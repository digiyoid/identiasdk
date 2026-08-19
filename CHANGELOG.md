# Changelog

Todos los cambios relevantes de **Digiyo / Identia SDK** se documentan en este archivo.

El formato sigue [Keep a Changelog](https://keepachangelog.com/es-ES/1.1.0/) y el versionado
sigue [Semantic Versioning](https://semver.org/lang/es/).

Cada versión corresponde a un release de este repositorio: en **iOS** al tag y al binario que
resuelve Swift Package Manager, y en **Android** a los artefactos `com.roshka:digiyo` y
`com.roshka:digiyocore` publicados con el mismo número.

> Las versiones **1.4.1 a 1.4.5** se documentan de forma resumida: se publicaron sin changelog y
> lo que figura acá se reconstruyó a partir del historial del repositorio y de la interfaz
> pública del binario de cada tag. A partir de la **1.5.0** el registro es completo.

---

## [2.0.2] — 2026-08-19

Refuerza la firma de capturas, agrega la limpieza automática de capturas abandonadas y permite consultar
las cámaras del dispositivo antes de abrir una vista.

> ⚠️ **Cambio de comportamiento que puede requerir cambios de código.** El SDK ahora solo sube archivos
> capturados con **sus propias vistas de cámara**. Si tu app captura por otro medio y usa `sendImage` o
> `sendVideo` para subir ese archivo, deja de funcionar. Ver
> [Origen de las capturas](#origen-de-las-capturas).

### Agregado

#### Origen de las capturas

`sendImage` y `sendVideo` ahora **verifican que el archivo provenga de las vistas de cámara del SDK** y
que no se haya modificado desde que se capturó. Si la verificación falla, la subida se rechaza por
`onError` y no se envía nada.

Es la contraparte necesaria de la firma de capturas que introdujo la 2.0.0: la firma garantiza que la
subida salió del SDK y que el archivo llegó íntegro, pero no podía garantizar que el archivo viniera de
la cámara. Ahora sí.

**Qué hacer según tu integración:**

| Tu app… | Acción |
|---|---|
| Usa `DocumentCameraView`, `SelfieCameraView` y `VideoCameraView` del SDK | Nada. Sigue funcionando igual. |
| Captura con su propia cámara o toma archivos de la galería | **Hay que migrar a las vistas del SDK.** Contactanos si tu flujo lo impide. |

Los mensajes de `onError` distinguen los dos motivos: que el archivo no lo capturó el SDK, o que cambió
después de capturarse.

#### Limpieza automática — `cancelDia` pasa a ser opcional

Hasta ahora, si el usuario abandonaba el flujo, las capturas quedaban en el dispositivo y el DIA abierto
en el backend hasta que la app llamara a `cancelDia`. La mayoría de las apps no lo hacen, porque no hay
ningún evento del sistema que avise que el usuario se fue.

El SDK ahora se encarga solo:

- Al crear un DIA nuevo, cierra el anterior si quedó sin comitear y borra sus capturas del dispositivo.
- Y descarta las capturas de más de **2 horas** que nunca se subieron.

Seguís pudiendo llamar a `cancelDia` cuando tenga sentido en tu flujo —al tocar "cancelar", por
ejemplo—; simplemente ya no es obligatorio para que el dispositivo quede limpio.

#### `getCameraAvailability()`

Informa qué cámaras tiene el dispositivo, para poder decidir **antes** de abrir una vista:

```kotlin
val camaras = digiyo.getCameraAvailability()
if (!camaras.canCaptureSelfie) { /* saltear el paso, o avisar al usuario */ }
```

Un equipo sin cámara delantera no puede hacer selfie ni prueba de vida; hasta ahora eso se descubría
cuando la cámara fallaba al abrir, con un error genérico. Ver
[CameraAvailability](README.md#cameraavailability).

### Corregido

- **iOS: las capturas legítimas se rechazaban al subir desde el puente de React Native.** El SDK
  comparaba la ruta del archivo tal como la recibía, y en iOS la ruta que entrega la cámara y la que
  necesita el core para leer el archivo se escriben distinto. Ahora la comparación es indiferente al
  formato de la ruta, así que un integrador puede transformarla sin que la subida se rechace.
- **El arranque del onboarding podía demorar más de un minuto** cuando la limpieza del DIA anterior no
  obtenía respuesta del servidor. Esa limpieza ya no bloquea el `createDia`.

---

## [2.0.0] — 2026-08-17

Segunda beta de la 2.0.0. Lo central es la **firma de capturas**: cada subida de imagen o video
viaja acompañada de headers que le permiten al backend verificar que la captura salió del SDK y que
el archivo no cambió en el camino. Trae además el control del logging y la personalización del botón
de cerrar.

> **No requiere cambios de código.** La firma es automática: no hay ningún método nuevo que llamar
> ni ningún parámetro que configurar. Los dos parámetros que se agregan son opcionales y en `null`
> dejan el comportamiento anterior. En Swift se agregaron los inicializadores de compatibilidad
> correspondientes, así que las apps ya integradas compilan sin tocar nada. Basta con actualizar la
> dependencia (Android) o el paquete (iOS).

### Agregado

- **Firma de capturas.** El `createDia` ahora devuelve un objeto `challenge` por cada requisito que
  recibe un archivo (`in_data`), y el SDK lo usa para firmar la subida. Los headers que agrega:

  | Header | Contenido |
  |---|---|
  | `X-Challenge-Id` | identificador del desafío |
  | `X-challenge-type` | le indica al backend con qué esquema verificar |
  | `X-signature` | la firma |
  | `X-timestamp` | momento de la firma, ISO-8601 en UTC con milisegundos |
  | `X-device-id` | identificador del dispositivo |
  | `X-sdk-version` | versión del SDK |
  | `X-platform` | `android` / `ios` |

  - **Nada que hacer del lado de la app.** El SDK lee el desafío del DIA y firma solo, en cada
    `sendImage` y `sendVideo`.
  - La firma incorpora una huella de **los bytes exactos que se suben**, así que un archivo sustituido
    entre la captura y el envío deja de verificar.
  - **El esquema de firma no se documenta**: es contrato interno entre el SDK y el backend de Digiyo, y
    una app que integra el SDK no necesita reproducirlo ni conocerlo. Lo único relevante del lado del
    cliente son los headers de la tabla, por si hay un gateway o un WAF en el camino que pueda
    descartarlos.
  - **La firma nunca bloquea una captura.** Si no se puede firmar, la subida sale igual y es el
    backend el que decide si la acepta.
  - **Los desafíos vencen.** Se emiten todos al crear el DIA, así que el tiempo se consume a lo largo
    del flujo y el último paso —normalmente el video— es el que menos margen tiene. Si vence, hay que
    **crear un DIA nuevo**: no existe un endpoint para renovarlo. Conviene tenerlo en cuenta en flujos
    donde el usuario pueda demorarse entre pasos.
  - Se agrega el modelo `ChallengeModel`, accesible en `DataRequireModel.challenge`. Es informativo:
    la app no necesita usarlo.

- **`DigiYoConfig.loggingEnabled`** — controla si el SDK escribe en la consola de la plataforma
  (Logcat en Android, consola de Xcode en iOS). `null` por defecto: autodetecta según si la app que
  integra el SDK es un build de desarrollo. Ver
  [Logging del SDK](README.md#logging-del-sdk-loggingenabled).
  - Poner `true` es lo que hay que hacer para depurar en **TestFlight** o en el **simulador de iOS**,
    donde la autodetección da `false`.
  - **Cambio de comportamiento respecto de versiones anteriores:** hasta la 2.0.0-beta.1 el SDK
    escribía en el log **también en builds de distribución**. Ahora, por defecto, solo lo hace en
    builds de desarrollo. Si una app dependía de ver esos mensajes en producción, tiene que pasar
    `loggingEnabled = true` explícitamente.

- **`closeButtonConfig`** en `DocumentCameraConfig`, `SelfieCameraConfig` y `VideoCameraConfig` —
  texto, ícono y ubicación del botón de cerrar, todo en un solo parámetro. Ver
  [Botón de cerrar](README.md#botón-de-cerrar-closebuttonconfig).
  - Texto personalizable. `"CERRAR"` es un **respaldo** para que el botón no quede vacío y aparece
    solo si no se configuró ni texto ni ícono; pasar únicamente un ícono **no** agrega "CERRAR" al
    lado.
  - Ícono opcional, a la izquierda o a la derecha del texto.
  - Sin texto queda **solo el ícono** y el botón se dibuja cuadrado. La altura no cambia nunca; el
    ancho se ajusta al contenido.
  - `position` elige de qué lado de la pantalla va el botón: `END` (derecha, el valor por defecto y
    la ubicación de siempre) o `START` (izquierda).
  - En `null` el botón se ve exactamente como antes.

### Corregido

- **`X-timestamp` y las marcas de tiempo del SDK ahora son UTC.** La utilidad de fecha ISO-8601 del
  SDK devolvía la **hora local** con el sufijo `Z` de UTC en Android, y un formato distinto —con
  offset local y sin milisegundos— en iOS. Con la firma esa cadena pasó a ser parte del protocolo, así
  que ahora las dos plataformas producen el mismo formato en UTC.
- **Los mensajes del SDK ya no se duplican en el log.** Crear más de una instancia del SDK en el
  mismo proceso hacía que cada línea se imprimiera una vez por instancia. Si la app anfitriona usaba
  la misma librería de logging, también se le duplicaban sus propias líneas.

### Seguridad

- **Qué aporta la firma.** Impide tres cosas: subir un archivo por la API sin pasar por el SDK,
  reusar una captura de otro DIA o de un intento anterior, y sustituir el archivo después de
  capturarlo.
- **Qué no cubre.** No prueba que el archivo provenga de la cámara del dispositivo. Esa capa
  —atestación de plataforma— está prevista para una versión posterior mediante el header
  `X-integrity-token`, que hoy se reserva y no se envía.

---

## [2.0.0-beta.1] — 2026-08-07

Primera **beta de la 2.0.0**. Sube a mayor por las dos capacidades nuevas que agrega al producto:
el **desafío de profundidad** (`pol_depth`) para la prueba de vida y el **NFC** de la cédula (OCR
del MRZ en el SDK, lectura del chip con una librería por plataforma). Trae además el **loader de
subida** del SDK.

> **Incluye todo lo publicado hasta la 1.5.6**: los parámetros `requireFaceFraming` y
> `lowLightBoostEnabled`, la normalización del encuadre por campo visual (iPhone XR), el watchdog
> del obturador en Android y el diagnóstico remoto. Las entradas de la 1.5.x siguen abajo, sin
> cambios.

> **No requiere cambios de código, aunque sea una mayor.** El salto a 2.0.0 es por alcance
> funcional, **no** por ruptura: ninguna firma pública se quitó y los constructores de
> compatibilidad de las tres configuraciones —y el alias `sendImageAysnchronously`— **siguen
> vigentes**. Cuando se retiren se avisará en una mayor posterior. Basta con actualizar la
> dependencia (Android) o el paquete (iOS): todo lo nuevo es opcional. Sí conviene leer los
> [cambios de comportamiento](#cambiado) y, en iOS, el punto sobre
> [remontar la cámara al volver del preview](#guía-de-migración-a-200-beta1).

### Agregado

- **Desafío de profundidad (`in_data.POL_VIDEO.config.pol_depth`).** Cuando `createDia`
  devuelve esa configuración, la pantalla de grabación cambia por completo: fondo opaco con un
  recorte ovalado, un óvalo grande (fase NEAR) que se pone del color de éxito al capturar el
  rostro y luego se reduce (fase FAR), las etiquetas **ACÉRQUESE** y **ALÉJESE** sobre el borde
  del óvalo y los mensajes de ayuda, captura y reintento debajo. La grabación se corta en
  cuanto se capturan las dos fases, sin esperar el límite de duración, y se fuerza una duración
  mínima de 12 s porque hay que reubicar el teléfono entre fases.
  - **Sin parámetros nuevos.** Las dos variantes del flujo se derivan de
    `captureModeConfig.automaticReadingEnabled`, que la app ya configuraba: en `true` no hay
    botón y la captura del rostro en el óvalo grande dispara la grabación; en `false` el botón
    funciona como un "Estoy listo", habilitado cuando el rostro entra en el óvalo grande.
  - En modo automático, un ciclo que vence sin capturar **no muestra popup de error**: vuelve
    al óvalo grande con el mensaje de reintento debajo.
  - Los desafíos de `versus_array` y `live_validations` mantienen el diseño de la 1.5.0 (óvalo
    guía fijo con su etiqueta), sin cambios.
- **Loader de subida del SDK** (`UploadLoaderScreen`), para no tener que armar uno en cada app:
  - Android: `digiyo.getUploadLoaderView(state, uploadingText, completedText, colorScheme, onCompletedTimeout)`.
  - iOS: `sdk.getUploadLoaderViewController(...)`, pensado para envolverlo en un
    `UIViewControllerRepresentable` (el sample incluye `Components/UploadLoaderView.swift`).
  - Dos estados: `UPLOADING` (círculo que late) y `COMPLETED` (círculo con check blanco, que a
    los 5 s invoca `onCompletedTimeout`).
  - Los textos son **opcionales**: en `null` / `nil` se ve solo la animación o solo el check. El
    color del círculo de éxito sale de `colorScheme.successColor`, el mismo con el que se pinta
    el óvalo; el check es siempre blanco.
- **OCR del MRZ del dorso, en el SDK** (`nfc.MrzReader`), que es el insumo para leer el chip NFC
  de la cédula: `extractMrz(imagePath) { info -> … }` devuelve número de documento, fecha de
  nacimiento y de vencimiento —los tres datos de la clave de acceso BAC—, más el número de
  cédula visible. Corre **on-device y sin conexión** (ML Kit en Android, Vision en iOS) y valida
  los dígitos verificadores del MRZ, así que una lectura dudosa devuelve `null` en lugar de
  llegar al chip. Incluye `nfc.MrzInfo`, `nfc.MrzKey`, `nfc.MrzParser` y `models.ParsedMrzData`.
  - **El SDK no lee el chip**: eso lo hace una librería externa por plataforma (AAR
    `NfcDocReader` en Android, paquete Swift `NFCIdentiaReader` en iOS). El README documenta
    cómo agregarlas y el sample tiene la implementación completa.
- **`models.OnboardingDiaType` y `models.ValidationDiaType`**: catálogos de `dia_type` de prueba
  con su sigla (`POL1`, `POL2`, `POL3`), para elegir el onboarding o la validación a probar sin
  escribir el nombre completo.
- **`live_validations.look_to_the_side`**: nueva validación reconocida en
  `LiveValidationOptions` y con su texto en `LiveValidationsText`.

### Cambiado

- **`requireFaceFraming` y la etiqueta `ALÉJESE` no aplican al desafío de profundidad.** Son parte
  del diseño del **óvalo guía fijo**, o sea de los DIA donde `createDia` responde
  `in_data.POL_VIDEO.config` con `versus_array` o con `live_validations`. Ahí el gate condiciona el
  disparo y la etiqueta indica qué hacer para lograr el encuadre.
  - En `pol_depth` el condicionamiento es **propio de las fases**: el botón "Estoy listo" se
    habilita cuando el rostro entra en el óvalo grande, y las etiquetas las manda la fase
    (**ACÉRQUESE** en NEAR, **ALÉJESE** en FAR), no la app. Pasar `requireFaceFraming = false` no
    tiene efecto en ese desafío, y `challengeTexts.ovalLabelText` tampoco se usa.
  - Es la primera versión en que las dos cosas conviven: el gate salió en la 1.5.3 y el desafío de
    profundidad, acá.
- **`VideoCameraConfig.cameraTitle` ahora aparece recién cuando el rostro queda encuadrado**, y
  se mantiene durante la grabación. Antes se dibujaba desde que abría la cámara. El título es la
  consigna del desafío ("Levantá 2 dedos", "Sonría"), así que ahora se intercambia con la
  etiqueta del óvalo en lugar de competir con ella: mientras se busca el encuadre se ve el óvalo
  con **ALÉJESE**, y al validarse aparece el título. En el desafío de profundidad **no se dibuja
  nunca**, porque ACÉRQUESE / ALÉJESE ya cumplen esa función.
  - No cambia ninguna firma. Si tu app usaba el título como encabezado de la pantalla (por
    ejemplo "Video"), conviene un encabezado propio por encima de la vista del SDK.
  - **Nada quedó obsoleto.** `challengeTexts.fingerRecordingText` y familia siguen funcionando
    igual: se dibujan **abajo** del óvalo y solo **durante** la grabación, mientras el título va
    arriba y desde el encuadre. Lo único a evitar es poner el mismo texto en los dos, porque
    durante la grabación se vería duplicado. El README compara los dos casos.
- El desafío de profundidad ignora `overlayDimAlpha`: su fondo es opaco a propósito, para que
  solo se vea la cámara dentro del óvalo.

### Corregido

- **El desafío de profundidad no se activaba nunca.** El backend envía `"pol_depth": {}` —un
  mapa vacío— en los `dia_type` de profundidad, y el SDK exigía que tuviera contenido. El
  resultado era que esos DIA caían en el diseño del óvalo guía fijo. Ahora alcanza con que la
  clave esté **presente**.
- **iOS: crash intermitente al leer el DIA guardado**
  (`RLM_ERR_FILE_OPERATION_FAILED`, *"thread constructor failed: Resource temporarily
  unavailable"*). Cada llamada del SDK abría una instancia nueva de Realm sin cerrarla, y cada
  instancia crea sus propios hilos internos: el proceso terminaba agotando los hilos
  disponibles. Ahora la instancia se abre una vez y se comparte.
- **Compatibilidad de `LiveValidationOptions` y `LiveValidationsText` con Swift.** Al agregar
  `look_to_the_side` se sumaron constructores con las firmas previas, porque la interfaz
  Objective-C no admite valores por defecto y un campo nuevo cambia el selector. Las apps ya
  integradas compilan sin tocar código.
- **iOS: al volver a la pantalla de grabación no se podía grabar de nuevo.** No es un defecto
  del SDK sino del ciclo de vida de SwiftUI: empujar el preview encima no destruye la pantalla
  de abajo, así que el estado interno de la cámara sobrevivía —el video ya guardado y, en
  profundidad, la fase completada— y al regresar se veía el óvalo chico con ALÉJESE y el botón
  no se habilitaba. La app tiene que **remontar** la vista al regresar; el README explica cómo y
  el sample lo implementa. Android no está afectado.

## Guía de migración a 2.0.0-beta.1

**No hay que tocar código.** Solo actualizar la versión de la dependencia (Android) o del
paquete (iOS).

### Puntos a revisar, aunque no rompan la compilación

- **iOS — remontar la cámara al volver del preview.** Si tu app vuelve a la pantalla de
  grabación (el típico "Volver a grabar video"), tiene que **recrear** la vista del SDK. En iOS
  `makeUIViewController` se llama una sola vez por identidad, así que el estado interno de la
  cámara sobrevive y no se puede grabar de nuevo. La solución es cambiar la identidad al
  regresar:

  ```swift
  @Published var cameraSessionId = UUID()   // en el ViewModel

  Step5ViewControllerRepresentable(viewModel: viewModel)
      .id(viewModel.cameraSessionId)
  .onChange(of: viewModel.navigateToNextScreen) { isActive in
      if !isActive { viewModel.cameraSessionId = UUID() }
  }
  ```

  En Android no hace falta: Navigation Compose descarta la composición del destino que no está
  visible.

- **Visibilidad de `cameraTitle`.** Ahora aparece con el rostro encuadrado y no antes. Conviene
  una pasada visual, y mover a un encabezado propio cualquier texto que sirviera de título de
  pantalla.

- **Desafío de profundidad.** Si tus `dia_type` incluyen `pol_depth`, la pantalla de grabación
  se ve distinta a partir de esta versión. Vale la pena probar los dos modos:
  `automaticReadingEnabled = true` (sin botón, arranca al capturar el rostro) y `false` (botón
  tipo "Estoy listo"); conviene también cambiar la etiqueta del botón en ese caso.

- **`in_data` sin `POL_VIDEO`.** Si tu app asume que siempre hay video, revisá el paso posterior
  a la selfie: cuando el DIA no pide `POL_VIDEO`, el commit va ahí.

---

## [1.5.6] — 2026-08-07

> **No requiere cambios de código.** Correcciones de comportamiento en la captura de documento de
> **Android**, ninguna con firmas nuevas y ninguna que endurezca un criterio de validación. Las tres
> salieron de los datos que dejó el diagnóstico de la 1.5.5, no de poder reproducir el problema: el
> caso del obturador trabado nunca se reprodujo a pedido.

### Corregido

- **Android: si el HAL de la cámara no respondía al obturador, la pantalla de captura quedaba
  trabada para siempre.** Hay equipos donde `takePicture` **no invoca ninguno de sus dos
  callbacks**: ni `onCaptureSuccess` ni `onError`. Confirmado en un **Samsung S24** con el log de
  diagnóstico —la solicitud salió y la línea del callback nunca llegó— y es el mismo síntoma que se
  reportó en un Vivo X200 Pro. Como el respaldo del screenshot vivía dentro de `onError`, tampoco se
  activaba: no había ninguna salida y el usuario tenía que cerrar la pantalla.
  - Ahora hay un **watchdog de 4 s** por intento: si no llega respuesta, se reintenta una vez y,
    agotados los intentos, se cae al screenshot del preview. Es de menor calidad —por eso se dejó de
    usar como camino principal en la 1.5.0— pero es preferible a una pantalla trabada, y cada paso
    de la escalada queda en el log.
  - Los 4 s son holgados a propósito: en el S24 una captura sana responde en **340 ms** con
    `lowLightBoostEnabled = false` y en **457-463 ms** con `true`, así que el watchdog no se dispara
    en el camino feliz ni en equipos lentos.
  - **`reinicios=0` en el caso que falló**, o sea que la detección se mantuvo válida sin una sola
    interrupción y el problema no estaba ni en el criterio de validación ni en el autofoco
    (`foco=OK`). El diagnóstico remoto es lo que permitió descartarlos.

  El formato de las líneas de captura queda así:

  ```
  doc captura: dia=<diaId> solicitada intento=N/2 framesValidosSeguidos=… reinicios=… foco=… modoCaptura=…
  doc captura: dia=<diaId> SIN RESPUESTA del HAL en 4000ms intento=N/2
  doc captura: dia=<diaId> callback=+NNNNms via=takePicture|respaldo|respaldo-timeout intento=N foco=…
  ```
- **Android: se podían disparar dos capturas para el mismo documento.** El disparo vive en un
  `LaunchedEffect` keyed por el estado de la detección, así que la secuencia
  válido → no válido → válido lo relanzaba y volvía a llamar `takePicture` con una captura todavía
  en vuelo: dos fotos escribían los mismos dos archivos y `onResult` se invocaba dos veces. Ahora la
  primera foto que se procesa gana y las demás se descartan con una línea en el log.
- **El SDK imprimía cada línea de log duplicada.** `Napier.base(DebugAntilog())` se llamaba en el
  `init` de `DigiYoCore` **y** en el de `DigiYo`, que hereda del primero: quedaban dos `Antilog`
  registrados. Afectaba a todas las apps integradas.

### Diagnóstico

- **`doc resumen` agrega `intentosCaptura`, `timeoutCaptura` y `modoCaptura`**, para poder separar
  en el campo una captura sana de una recuperada por el watchdog sin tener que reproducir nada.
- **El resultado del autofoco periódico también se registra.** Antes solo se instrumentaba el foco
  por detección, que no se dispara cuando el encuadre ya es válido: en las sesiones donde la cédula
  entra en válido de inmediato el diagnóstico reportaba `foco=SIN_DATO`, que se confunde con "no
  enfocó".

---

## [1.5.5] — 2026-08-07

> **No requiere cambios de código.** No hay firmas nuevas: son tres correcciones de equipos
> puntuales más diagnóstico. En iOS, el arreglo del encuadre **solo puede aflojar el criterio,
> nunca endurecerlo**, así que ningún equipo que hoy valida bien cambia de comportamiento; en
> Android, el arreglo del autofoco no toca la validación, solo deja de reiniciar el enfoque en cada
> frame.
>
> Los parámetros `requireFaceFraming` y `lowLightBoostEnabled` siguen siendo los de la 1.5.3: esta
> versión no toca la interfaz pública.

### Corregido

- **Android: la captura automática del documento demoraba o no llegaba a ocurrir en algunos
  equipos** (reportado en un Vivo X200 Pro). El autofoco sobre el objeto detectado se disparaba
  **dentro del callback del analizador**, sin throttle: 15 a 30 acciones de foco por segundo. Y en
  CameraX cada `startFocusAndMetering` cancela la anterior y reinicia el barrido de AF desde cero,
  así que el foco quedaba "cazando" de forma permanente. Los tres efectos se realimentaban: preview
  borroso → el detector parpadea más → se reinicia la ventana de estabilidad del disparo; y
  `takePicture` en `CAPTURE_MODE_MAXIMIZE_QUALITY`, que espera la convergencia de 3A antes de
  obturar, agotaba su timeout interno.
  - Ahora el enfoque por detección respeta un intervalo mínimo de 2 s y **las mismas dos guardas
    que el ciclo de autofoco periódico ya usaba**: no se re-enfoca cuando el encuadre ya es válido
    —re-disparar el AF justo antes de obturar era lo que trababa la convergencia— ni cuando el
    usuario acaba de enfocar con un toque.
  - Es el mismo criterio que documenta `CENTER_FOCUS_CANCEL_MS` desde la 1.5.0 para el A04
    ("re-disparar el foco sin pausa lo mantiene cazando foco"), aplicado también al analizador.
  - **En iOS no aplica**: el ciclo de foco es distinto.
- **iOS: en equipos con cámara frontal de campo visual angosto el encuadre era inalcanzable.** El
  criterio de tamaño compara el ancho del rostro contra el del óvalo, que es una fracción fija de
  la pantalla. Pero el ancho de escena que abarca una cámara a una distancia `d` es
  `2·d·tan(fov/2)`, así que un equipo con FOV más angosto muestra el mismo rostro **más grande** a
  la misma distancia física, y el usuario tenía que alejarse más de lo que llega el brazo.
  - Medido: un **iPhone XR reporta 61.16°** contra los **73.7° de un iPhone 14**. El factor
    geométrico da 1.27 y el cociente entre los anchos de rostro medidos en los dos equipos fue
    1.23 — la predicción se cumple con un 3 % de diferencia.
  - Ahora el umbral se **normaliza por el campo visual** del formato activo:
    `umbral = 0.90 × tan(73.7°/2) / tan(fov/2)`. En el XR queda en 1.14 y el encuadre se logra a
    la misma distancia física que en un equipo de referencia.
  - **Solo puede aflojar, nunca endurecer** (el factor tiene mínimo 1.0), así que ningún equipo
    que hoy valida bien cambia de comportamiento. Tiene tope en 1.35 (≈57° de FOV) y se ignora si
    el FOV informado está fuera de 40–100°.
  - En **Android no aplica**: el campo visual no está disponible por la misma API y el criterio ya
    está calibrado con ML Kit. `utils.evaluateFaceOvalFraming` recibe el factor como parámetro
    opcional (`maxWidthFactor`, por defecto `1f`), así que el comportamiento en Android es
    idéntico al de la 1.5.x.
- **iOS: el rect del rostro se construía invertido.** `getFaceBounds` mapeaba las coordenadas
  normalizadas de Vision con una función que invierte los dos ejes (para espejar la cámara
  frontal), así que la esquina que se tomaba como superior izquierda era en realidad la inferior
  derecha: el rect salía con `left > right` y `top > bottom`, y su ancho y alto eran **negativos**.
  La validación del encuadre no se veía afectada porque normaliza el rect antes de usarlo, pero
  cualquier otro consumidor de `getFaceBounds` —y el log de diagnóstico— recibía valores
  inservibles.

### Diagnóstico

- **Android, captura de documento:** tres líneas nuevas con tag `digiyo`, pensadas para
  diagnosticar a distancia los equipos que no tenemos —igual que se hizo con el `camara iOS` del
  campo visual—. No cambian ningún comportamiento.

  ```
  doc camara [dia=<diaId>]: equipo=<fabricante> <modelo> (Android NN) camara=<id> minFoco=<cm|FOCO_FIJO>
              focal=<mm> sensor=<mm> modosAF=[…] zoom=… | modoCaptura=QUALITY|LATENCY
              resAnalisis=1280x720 resCaptura=2048x1536 marco=[l,t,r,b] anchoMarco=…
              tolerancia=… umbralArea=0.5 vista=WxH

  doc encuadre: dia=<diaId> estado=… dentro=… areaRel=… umbralArea=0.5 marco=[…] anchoMarco=…
                box=[…] anchoBox=… framesValidosSeguidos=… reinicios=… foco=OK|FALLO|CANCELADO

  doc captura: dia=<diaId> solicitada framesValidosSeguidos=… reinicios=… foco=… modoCaptura=…
  doc captura: dia=<diaId> callback=+NNNNms via=takePicture|respaldo foco=…
  ```

  - **`minFoco`** es la distancia mínima de foco de la cámara que eligió CameraX, convertida a cm
    desde las dioptrías que informa Camera2 (`FOCO_FIJO` = lente sin autofoco). Los equipos con
    sensor grande no enfocan de cerca, y el criterio de área obliga a acercar la cédula: si la
    distancia necesaria queda por debajo de `minFoco`, ese equipo **no puede** enfocar el
    documento por más intentos que haga.
  - **`reinicios`** cuenta cuántas veces se cortó una racha de frames válidos. El marco se pinta
    del color de validado con **un** frame válido, mientras que la captura exige que el estado se
    mantenga válido durante toda la ventana de espera —cualquier frame que salga lo reinicia desde
    cero—. Si un cliente reporta que el marco cambia de color y no captura, y este contador sube
    mientras `framesValidosSeguidos` se queda bajo, la causa es el parpadeo de la detección.
  - **`foco`** registra el resultado real del autofoco (`OK` / `FALLO` / `CANCELADO`). Hoy **no
    condiciona la captura**: es el dato previo necesario para poder condicionarla. Mientras el
    foco se re-disparaba en cada frame el resultado era siempre `CANCELADO` y el foco era
    inobservable.
  - **`callback=+NNNNms`** mide cuánto tarda el HAL en responder al obturador, que es lo que
    separa una demora de convergencia de 3A de un problema del criterio de validación.
  - Todas las líneas locales llevan `dia=<diaId>` (o `dia=sin-dia` si la pantalla se abrió antes de
    que existiera un DIA), para poder cruzar un logcat con lo que quedó registrado del lado del
    servidor. El `LogData` remoto ya traía el `diaId` como campo propio. Se resuelve **una vez por
    pantalla**: leerlo cuesta un acceso a Realm y el log de encuadre corre por frame.
  - El log de encuadre se emite en los cambios de estado y cada 15 frames, para no inundar el
    logcat.
- **Los dos eventos clave se envían también al backend**, por el endpoint de logs que el SDK ya
  tenía (`DigiYoCore.log` → `POST /idb-logging/log`), así que un caso soportado se puede
  reconstruir **sin pedirle un logcat al usuario final**. Llegan con el `diaId`, el `partnerId`, el
  `deviceId` y los timestamps que resuelve el core.
  - `type=doc-camara`, `location=DocumentCameraView`, `subLocation=<tipo de documento>`: al abrir
    la pantalla, con las características de la cámara.
  - `type=doc-resumen`: **al cerrar la pantalla, haya capturado o no**. Es el que importa: el caso
    que no se podía diagnosticar de ninguna otra forma es el del usuario que abandona sin lograr la
    captura, porque ahí no llegaba ningún evento al servidor.

    ```
    doc resumen: dia=<diaId> capturo=false estadoFinal=VALID duracionMs=24310 framesAnalizados=486 fps=20.0
                 framesValidosSeguidos=3 reinicios=17 foco=OK callbackCapturaMs=-1
                 modoAutomatico=true | ultimoEncuadre: estado=VALID dentro=true areaRel=0.55 …
    ```

    `fps` está para poder leer el resto: la ventana de estabilidad del disparo se mide en
    milisegundos pero se consume en frames, así que sin los fps no se sabe cuántos frames seguidos
    hacían falta. `callbackCapturaMs=-1` significa que el HAL nunca respondió al obturador.
  - Son **dos requests por pantalla de documento**, no uno por frame: el log de encuadre por frame
    queda solo en el logcat. El envío es fire-and-forget en el scope del core, así que sobrevive al
    cierre de la pantalla.

- El log del SDK (tag `digiyo`) ahora incluye el **cociente** entre el ancho del rostro y el del
  óvalo, junto con el umbral, en las dos plataformas:

  ```
  encuadre: dentro=false tamañoOK=false ratio=1.12 umbral=1.14 (base=0.9 factorFov=1.27) | ovalo=[…] ancho=579 | rostro=[…] ancho=650
  ```

- En **iOS** se agregó además una línea por pantalla con los datos de la cámara, que son los que
  explican por qué en algunos modelos el rostro nunca "entra" en el óvalo: campo visual del
  formato activo, resolución del buffer que analiza Vision, y tamaños del preview y de la vista.

  ```
  camara iOS: fov=…° formato=WxH (aspecto=…) | preview=WxH | vista=WxH | umbralBase=0.9 factorFov=… umbralEfectivo=… fovReferencia=73.7 infladoRostro=1.3
  ```

---

---

## [1.5.3] — 2026-08-04

> **No requiere cambios de código.** Los dos cambios son **aditivos y no rompen
> compatibilidad**: las configuraciones conservan sus constructores anteriores, así que las apps
> ya integradas actualizan sin tocar código y **sin cambios de comportamiento**.

### Agregado

- **`VideoCameraConfig.requireFaceFraming`** (`Boolean`): permite desactivar el gate de encuadre
  de la grabación de video. **`true` por defecto**, es decir el comportamiento de la 1.5.x: en
  modo manual el botón se habilita recién con el rostro encuadrado en el óvalo, y en automático
  la grabación arranca ahí. Con `false` el encuadre deja de condicionar el disparo —en manual el
  botón está habilitado desde el arranque, y en automático se graba en cuanto se detecta un
  rostro a cualquier distancia—.
  - **La etiqueta del óvalo depende de este parámetro.** Con `true` se dibuja siempre: el texto
    que pase la app en `challengeTexts.ovalLabelText` o, si no lo definió, el `"ALÉJESE"` del SDK.
    Con `false` **no se dibuja**, porque si el encuadre no condiciona el disparo pedirle al
    usuario que se aleje no sirve de nada. El óvalo sí se sigue mostrando como guía.
  - **Ojo si tu app pasaba `ovalLabelText = null` para ocultar la etiqueta**: ahora eso muestra
    el texto por defecto. La forma de ocultarla es `requireFaceFraming = false`.
  - Resuelve el caso de los equipos con cámara frontal de campo visual angosto (un iPhone XR es
    el de referencia), donde el rostro ocupa más del encuadre a la misma distancia física y el
    usuario no llega a alejarse lo suficiente: el gate lo dejaba trabado sin poder grabar.
- **`lowLightBoostEnabled`** (`Boolean`) en `DocumentCameraConfig`, `SelfieCameraConfig` y
  `VideoCameraConfig`: permite apagar la mejora de captura para poca luz de **Android**, que
  desde la 1.5.0 era fija. **`true` por defecto**, es decir el mismo comportamiento con el que se
  publicó la 1.5.x: exposición aclarada (AE bias) y, en las fotos, captura de máxima calidad. Con
  `false` la captura se hace con latencia mínima y sin corrección de exposición, algo útil para
  comparar capturas en un dispositivo puntual.
  - En **iOS se ignora**: la implementación es específica de CameraX.

> **Nota de compatibilidad iOS:** las tres configuraciones mantienen sus constructores **sin**
> los parámetros nuevos, porque la interfaz Objective-C que consume Swift no admite valores por
> defecto y un campo nuevo cambiaría el selector. Las apps iOS no tienen que tocar nada, y los
> constructores de compatibilidad conservan los valores que replican el comportamiento actual.
> Al retirarlos (2.0.0) se avisará acá.
>
> `VideoCameraConfig` expone un `init` por cada **prefijo** de la firma: hasta `challengeTexts`,
> hasta `lowLightBoostEnabled`, o completa. Es decir que en Swift se puede omitir un **sufijo** de
> parámetros, pero **no** uno del medio: para pasar `requireFaceFraming` hay que enumerar también
> `lowLightBoostEnabled`, aunque en iOS ese parámetro se ignore. No hay forma de evitarlo: un
> constructor que termine en `requireFaceFraming: Boolean` choca en Kotlin con el que termina en
> `lowLightBoostEnabled: Boolean`, porque tienen la misma cantidad de parámetros y los mismos
> tipos. Ver "iOS: cómo omitir los parámetros nuevos" en el README.

---

## [1.5.1] — 2026-07-30

Versión de **compatibilidad**: recupera las firmas públicas que la 1.5.0 había cambiado sin
avisar y corrige tres defectos de esa misma versión.

> **Si venís de la 1.5.0 y tu app dejó de compilar, esta versión lo resuelve sin que toques
> código.**

### Agregado

- **`sendImageAysnchronously` vuelve a existir**, como alias `@Deprecated` de
  `sendImageAsynchronously`. La 1.5.0 corrigió el error de tipeo del nombre, pero en Swift el
  nombre viejo forma parte del selector exportado, así que renombrarlo rompía la compilación de
  las apps ya integradas. Usá `sendImageAsynchronously` en código nuevo; el alias se retirará en
  la 2.0.0.
- **`InDataConfigModel` recupera su constructor sin `polDepth`**, además del que lo incluye.
- **`VideoCameraConfig` expone cuatro constructores**, uno por cada firma publicada: la previa a
  la 1.4.5, la que agrega `showDetectedFaceOval`, la que agrega `overlayDimAlpha` y la que
  agrega `challengeTexts`. Así ninguna app tiene que enumerar parámetros nuevos para actualizar.

  > **Por qué hay varios constructores en lugar de valores por defecto:** Swift consume el
  > framework a través de su interfaz Objective-C, que **no admite valores por defecto**. Cada
  > parámetro agregado a una data class cambia el selector y rompe la compilación del cliente.
  > Cuando estos constructores se retiren (2.0.0) se avisará en este archivo.

### Corregido

- **La mejora de iluminación de Android no siempre se aplicaba.** `bindToLifecycle` es
  asíncrono: si la cámara todavía no estaba abierta, la corrección de exposición se descartaba
  en silencio y la captura salía sin ella. El resultado dependía del *timing* y no del equipo, y
  el síntoma era que **dos apps con el mismo dispositivo y la misma versión del SDK capturaban
  con iluminación distinta**. Ahora se espera a que la cámara esté lista.
- **El botón de grabar no respondía con `CaptureButtonBehavior.DisplayLoadingOnShoot`.** Al
  quedar el rostro encuadrado el botón se convertía en spinner: se veía habilitado, pero en modo
  *loading* no tiene acción y el toque no hacía nada.
- **El SDK reportaba al backend una versión incorrecta** en `ADDITIONAL_INFO.digiyo_version`. La
  tarea que genera la constante de versión no declaraba la versión como entrada, así que al
  subirla se reportaba UP-TO-DATE y quedaba la anterior.

---

## [1.5.0] — 2026-07-29

Release centrada en la estabilidad y el rendimiento de las cámaras en iOS, la personalización de
la pantalla de grabación de video y el soporte de flujos que dependen del `dia_type`.

> **Atención:** esta versión **sí cambió firmas públicas** (ver [Cambios
> incompatibles](#cambios-incompatibles)). La **1.5.1** repone todas esas firmas, así que si vas
> a actualizar conviene ir directo a la 1.5.1.

### Agregado

- **`VideoCameraConfig.challengeTexts`** (`VideoChallengeTexts`): personaliza los dos textos que
  el SDK dibuja sobre la cámara durante la grabación.
  - `ovalLabelText`: etiqueta encima del óvalo, **`"ALÉJESE"` por defecto**. Se muestra mientras
    el rostro no está encuadrado y desaparece junto con el óvalo.
  - Texto de grabación, elegido automáticamente según el desafío que devolvió `createDia` en
    `in_data.POL_VIDEO.config`: `fingerRecordingText` para `versus_array` (el `%d` se reemplaza
    por la cantidad de dedos del array), `depthRecordingText` para `pol_depth`, y un campo por
    cada `live_validations`. **Todos vacíos por defecto**: si la app no define un texto, el SDK
    no dibuja ningún mensaje durante la grabación.
- **`VideoCameraConfig.showDetectedFaceOval`** (`Boolean?`): dibuja u oculta el óvalo del rostro
  detectado, además del óvalo guía.
- **`VideoCameraConfig.overlayDimAlpha`** (`Float?`): opacidad del fondo translúcido que rodea
  al óvalo guía.
- **`SuccessAlertConfig.imageBase64`** (`String?`): imagen personalizada para el modal de éxito,
  codificada en Base64.
- **Desafío de prueba de vida 3D / profundidad**, activado por `pol_depth` en
  `in_data.POL_VIDEO.config`. `InDataConfigModel` incorpora el campo `polDepth` y
  `LiveValidationsText` el texto `depthCheck`.
- **Enfoque por toque (tap-to-focus)** en la captura de documentos en Android. No requiere
  configuración.
- **Utilidades públicas**, por si hace falta replicar el criterio del SDK en una interfaz
  propia: `utils.guideOvalRect` (geometría del óvalo guía), `utils.evaluateFaceOvalFraming`
  (criterio de encuadre del rostro, con el modelo `FaceOvalFraming`) y
  `utils.resolveVideoHelpText` (resolución del texto de ayuda).

### Cambiado

- **Android: mejora de captura con poca luz, siempre activa.** El SDK sube la compensación de
  exposición de la cámara (+1.5 EV en la trasera, +3.0 EV en la delantera) y usa el modo de
  máxima calidad al tomar fotos. Apunta a ambientes con poca luz y a equipos de gama baja, donde
  la cédula salía oscura o borrosa. **No es configurable y no requiere ninguna acción.** Solo
  afecta el brillo: no cambia la geometría del rostro, así que la detección y el liveness del
  óvalo se comportan igual. En iOS no aplica.

  > En esta versión la mejora no siempre llegaba a aplicarse; se corrigió en la 1.5.1.
- **`CaptureModeConfig.overwriteDefaultTextWith` en `null` ahora equivale a `""`.** Si no se
  define un texto (y tampoco `customLiveValidationsText`), la caja de ayuda debajo del óvalo
  **no se muestra**. Antes el SDK imponía el texto
  `"Mantén tu cara dentro del óvalo y levante %d dedo(s)"`. Si dependías de ese texto, pasalo
  explícitamente.
- **Se vaciaron dos mensajes por defecto del overlay de video.** En
  `VideoStatusMapper.DEFAULT_MESSAGE_MAP`, `NO_CENTER` (era `"Centre su rostro"`) y `RECORDING`
  (era `"Grabando..."`) pasaron a `""`, así que ya no se dibujan. Va en línea con el rediseño:
  cuando el rostro no está centrado la guía es el propio óvalo, y durante la grabación el
  indicador es el REC con el contador. Si tu app los necesita, se pasan explícitamente por
  `customLiveValidationsText` / `overwriteDefaultTextWith`. Los mapas de documento y selfie no
  cambiaron.
- **Rediseño del overlay de grabación de video.** Se eliminó el recuadro que rodeaba al óvalo:
  queda solo el óvalo sobre el fondo translúcido, con el mismo tratamiento visual que la cámara
  de selfie. La guía (óvalo, fondo y texto de ayuda) desaparece cuando el rostro queda encuadrado
  y reaparece si se sale.
- **Botón de grabación según el modo de captura.** Con
  `captureModeConfig.automaticReadingEnabled = false` el botón se muestra siempre, deshabilitado
  hasta que el rostro queda encuadrado. Con `true` no se muestra nunca y la grabación arranca
  sola. Durante la grabación ya no se ejecuta ninguna validación de encuadre.
- **Colores de la pantalla de grabación.** El marco del óvalo usa `colorScheme.accentColor`
  mientras se busca el rostro y `colorScheme.successColor` al quedar encuadrado. El fondo de la
  etiqueta sobre el óvalo usa `colorScheme.successColor`, con letras blancas.
- Se quitó el marco interno que intentaba detectar la cédula dentro del marco fijo, en ambas
  plataformas: parpadeaba y no aportaba información al usuario.
- **Las fotos en Android se guardan como JPEG (calidad 90) en lugar de PNG.** Los archivos ya se
  llamaban `.jpg`, pero se escribía PNG: una foto de sensor completo pesaba decenas de MB, su
  compresión tardaba segundos en equipos de gama baja e inflaba la subida al backend. Si tu app
  post-procesa esos archivos asumiendo PNG, hay que ajustarlo.
- El marco del preview de la imagen capturada ya no depende de la resolución en píxeles de la
  foto: para imágenes horizontales ocupa todo el ancho disponible y la imagen se escala hasta
  llenarlo. iOS y Android muestran el mismo resultado.
- El envío no cambió: la imagen de la cédula se sube completa tal como se capturó, y la versión
  recortada se envía únicamente como `CROPPED_CI_PY_FRONT` / `CROPPED_CI_PY_BACK` cuando el DIA
  la requiere en su `in_data`.

### Cambios incompatibles

Ninguno de estos se anunció en su momento; todos se revirtieron o repusieron en la **1.5.1**,
salvo donde se indica.

- **`sendImageAysnchronously` se renombró a `sendImageAsynchronously`.** En Swift el nombre viejo
  forma parte del selector, así que la compilación de las apps integradas fallaba. Repuesto como
  alias en la 1.5.1.
- **`InDataConfigModel` cambió de constructor** al agregar `polDepth`. Repuesto en la 1.5.1.
- **`VideoCameraConfig` cambió de constructor** al agregar `showDetectedFaceOval`,
  `overlayDimAlpha` y `challengeTexts`. Repuesto en la 1.5.1.
- **Se quitaron `LiveValidationOptions.lookToTheSide` y `LiveValidationsText.lookToTheSideText`**,
  agregados en la 1.4.5. El desafío "mirar hacia un lado" se dio de baja y `LiveValidationsText`
  pasó a exponer `depthCheck` en su lugar. **Esto no se repuso**: si tu app los usaba, hay que
  quitar esas referencias.
- **`VideoCameraConfig.addValidationsTextIfNeeded` agregó el parámetro `customChallenge`.**
- **`cropImage` (iOS) agregó los parámetros `viewCropRect` y `viewSize`.**

### Corregido

- **iOS: el rostro nunca se detectaba dentro del óvalo en la grabación de video** cuando la
  lectura era manual y el desafío no era de profundidad (por ejemplo `versus_array`). La salida
  de análisis de la cámara no se agregaba a la sesión en ese caso, así que el detector no
  recibía un solo frame y el botón de grabar no se habilitaba a ninguna distancia.
- **iOS: el marco detector de la cédula parpadeaba** y la línea superior saltaba, a diferencia de
  Android. Se estabilizó con reuso del handler de secuencia, tolerancia a frames perdidos,
  filtros de confianza y suavizado de esquinas.
- **iOS: el preview de la cédula no aplicaba el recorte** y quedaban espacios alrededor. Se
  corrigió el mapeo de coordenadas de la vista a la imagen y el recorte de la foto.
- **Android: el preview de la cédula podía verse rotado 90°** en algunos equipos. La orientación
  se resuelve por EXIF, con respaldo en la rotación reportada por la cámara y forzado a retrato.
- **Android: la captura de cédulas era poco efectiva y salía borrosa en equipos de gama baja.**
  Se ajustaron la resolución y el enfoque para equilibrar las distintas gamas (verificado en
  Pixel 9, Samsung S24 y Samsung A04).
- **Error `"InData no encontrado"` al iniciar el flujo** con `dia_type` que no incluyen todos los
  pasos. Se agregaron logs de diagnóstico en `getInData` con la clave solicitada y las
  disponibles.
- **Time-out en la subida de imágenes y videos.** Ahora hay un time-out por request —60 s para
  imágenes, 120 s para videos— en lugar del valor global del cliente HTTP, que cortaba subidas de
  video legítimas en conexiones lentas. También se mejoró el mensaje de time-out de `getDia`.
- **`OutOfMemoryError` al enviar fotos.** El plugin de logging de red buffereaba el cuerpo
  completo de cada request en memoria.

### Rendimiento

- **iOS: la cámara tardaba en abrir** en las pantallas de grabación de video y de selfie,
  mientras que al volver desde el preview aparecía al instante. La sesión de captura se
  configuraba en el hilo principal y en dos etapas, y al empezar a grabar se reconstruía en vivo.
  Ahora se configura una sola vez, completa, en un hilo de fondo. La apertura pasó a ser
  inmediata.
- **iOS: freeze en el instante de la captura de la selfie.** La detección de parpadeo, la
  codificación de la imagen y el guardado a disco corrían en el hilo principal; ahora corren en
  una cola de fondo dedicada.
- **iOS: la captura de selfie reconstruía la cámara en cada recomposición** (dispositivo, entrada,
  salida y sesión), lo que encarecía la apertura de la pantalla.
- iOS: se redujo el tiempo de cierre de la cámara al terminar de grabar, detectando el fin por
  duración máxima en lugar de esperar el time-out.
- iOS: se descartan los frames que llegan mientras el anterior aún se procesa, evitando
  acumulación y lag en la detección.
- El formato y el campo visual del sensor se mantienen constantes en iOS antes, durante y después
  de grabar. Antes cambiaban al iniciar la grabación, lo que desplazaba la calibración de la
  detección del rostro entre el primer intento y los reintentos.

### Seguridad

- **La API key ya no se escribe en el log del dispositivo.** El encabezado se sanitiza y el nivel
  de log de red pasó de `ALL` a `HEADERS`, con lo que tampoco se vuelcan las imágenes enviadas.

---

## [1.4.5] — 2026-07-07

### Agregado

- Desafío de prueba de vida **"mirar hacia un lado"**: `LiveValidationOptions.lookToTheSide`
  (`look_to_the_side` en el JSON) y `LiveValidationsText.lookToTheSideText`.

### Cambios incompatibles

- Los constructores de `LiveValidationOptions` y de `LiveValidationsText` pasaron de 7 a 8
  parámetros. En Swift eso cambia el selector, así que **las apps que instanciaban esas clases
  dejaban de compilar**.
- El desafío se dio de baja en la **1.5.0**, que volvió a quitar los dos campos.

---

## [1.4.4] — 2026-06-02

### Cambiado

- Se agregó el **identificador de dispositivo** a la información que el SDK recolecta y envía al
  backend. Sin cambios en la API pública.

---

## [1.4.3] — 2026-05-18

### Corregido

- **El texto por defecto de las cámaras no se tomaba** en algunos casos.

### Cambiado

- Se limpió el artefacto de iOS: se quitaron del paquete los símbolos de depuración (dSYM) que
  se habían incluido por error en la 1.4.2. Sin cambios en la API pública.

---

## [1.4.2] — 2026-04-22

Release de **documentación**. Sin cambios en la API pública ni en el comportamiento.

### Documentación

- Se documentaron en el README los modelos y configuraciones que faltaban:
  `DocumentCameraConfig`, `SelfieCameraConfig`, `VideoCameraConfig`, `ChallengeOverlayConfig`,
  `HelpConfig`, `HelpBulletpoint`, `MediaPreviewConfig`, `SuccessAlertConfig`,
  `ErrorAlertConfig`, `LiveValidationsText` y `DigiYoRGB`, cada uno con todos sus campos.
- Se completó la tabla de contenido y se corrigieron anclas y erratas.

---

## [1.4.1] — 2026-04-13

### Agregado

- **`getSubWorkflow`**: consulta los sub-flujos disponibles para el DIA.
- **`sendImage` con SubWorkflow automático**: nuevo parámetro `shouldRequestWorkflow`; cuando es
  `true`, el `onSuccess` devuelve además la lista de `SubWorkflow`.
- Documentación de los **modelos de datos** en el README: `DigiYoConfig`, `DiaModel`,
  `InDataEntryModel`, `DataRequireModel`, `InDataConfigModel`, `EnrollmentData`, `TaskModel`,
  `ResultModel`, `PolDetails` y `DigiYoError`.

---

## Versiones anteriores

Las versiones **1.4.0 y anteriores** se publicaron sin registro de cambios. El historial de
releases está disponible en la
[página de releases del repositorio](https://github.com/digiyoid/identiasdk/releases).
