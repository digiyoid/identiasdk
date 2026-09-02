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

## [2.2.0] — 2026-09-02

Dos frentes independientes. **Atestación de capturas**: el SDK ahora acompaña cada imagen y cada video
con evidencia de que el archivo lo produjo una app legítima en un dispositivo real. Y **marcas de agua
en el desafío de movimiento de cabeza**: una silueta sobre la cámara que le indica al usuario hacia
dónde girar.

Nada de lo agregado rompe compilación. La atestación **necesita una habilitación de tu app en el
backend de Digiyo**, una sola vez; el detalle está en "Notas para quien integra".

### Agregado

- **Atestación de capturas.** El SDK registra **una clave por dispositivo** al arrancar la app y firma
  con ella cada archivo que sube. La evidencia viaja junto a la subida, separada de la verificación de
  origen que ya existía desde la 2.0.2: son dos controles distintos y el backend los evalúa por
  separado.

  El registro de la clave ocurre una sola vez, al arrancar la app, y no agrega espera a ninguna
  subida.

  **Requiere una habilitación inicial de tu app**, una sola vez: el backend de Digiyo tiene que tener
  registrada su identidad. Ver "Notas para quien integra".

  **El flujo de tu app no depende de ella.** Podés integrar la 2.2.0 antes de completar la
  habilitación, y en un dispositivo que no pueda atestiguar —por antigüedad o por su configuración—
  capturar y subir también siguen su curso normal. No hace falta ninguna contención para esos casos.

- **Android: `DigiyoIntegrity.configure(context, cloudProjectNumber)`.** Adjunta el token de Play
  Integrity a cada captura. Va junto con la habilitación de tu app: el número tiene que ser el de **tu**
  proyecto de Google Cloud, el mismo del que sale la credencial que nos entregaste.

  ```kotlin
  utils.DigiyoIntegrity.configure(
      context = applicationContext,
      cloudProjectNumber = 123456789012L, // el NÚMERO del proyecto de Google Cloud, no el id
  )
  ```

  No es un campo de `DigiYoConfig` a propósito: necesita un `Context` y el número de proyecto, que son
  propiedades de tu aplicación y no del SDK, y agregarle un parámetro a esa clase rompería la
  compilación de los clientes iOS —que además no usan Play Integrity—.

- **`VideoCameraConfig.challengeImages`** (`VideoChallengeImages`): marca de agua con silueta de cabeza
  sobre la cámara durante el desafío de `look_left_right`. Una imagen por fase, con opacidad, tinte y
  tamaño configurables.

  **Convive con `challengeTexts`, no lo reemplaza.** Se pueden usar uno, el otro o los dos: la consigna
  escrita se dibuja encima del borde superior del marco y la silueta adentro, y las dos cambian juntas
  al avanzar la fase.

  `VideoChallengeImages()` sin argumentos usa las siluetas del propio SDK, así que activar la marca de
  agua no obliga a diseñar nada:

  ```kotlin
  challengeImages = VideoChallengeImages.DEFAULT
  ```

  Si definís **al menos una** imagen propia, el SDK deja de aportar las suyas y las fases sin imagen no
  dibujan nada. Es deliberado: mezclar una silueta del SDK con una ilustración tuya en la misma
  secuencia se lee como un error, no como un respaldo.

- **`VideoCameraConfig.lookSequenceConfig`** (`LookSequenceConfig`): comportamiento y marco del desafío
  de giros.

  - `startSide`: hacia qué lado se pide el **primer** giro. **No es cosmético** — cambia el orden que
    el SDK espera. Con `RIGHT` la secuencia es derecha → frente → izquierda → frente.
  - `frameShape`: óvalo (por defecto) o rectángulo redondeado durante la grabación.
  - `frameStrokeWidth` y `frameColor`: el trazo del marco.
  - `showStepNumber`, `stepNumberColor`, `stepNumberFontSize`: el "1." al "4." dentro del marco.

  **Los textos y las imágenes siguen indexados por LADO, no por orden**, así que invertir `startSide`
  no te obliga a reordenar nada: `lookRightInstructionText` es el texto del giro a la derecha, sea el
  primero o el segundo. Lo único a revisar es el contenido: un texto que numera el paso a mano
  —"Paso 1: girá a la izquierda"— deja de coincidir al invertir el orden. El número lo dibuja el SDK y
  es la posición real en la secuencia —1, 2, 3 y 4, con las dos vueltas al frente en 2 y 4—, así que no
  hace falta repetirlo.

- **`DigiYoIcons.HeadLateralViewLeft`**: el perfil de `HeadLateralView` espejado, disponible como
  cualquier otro ícono del SDK.

### Cambiado

- **El marco del desafío de giros se agranda al arrancar la grabación**, para no quedar pegado al
  contorno de la silueta. **No toca el óvalo de encuadre**: el que se compara contra tu rostro para
  habilitar el botón y hacer desaparecer el "ALÉJESE" conserva su tamaño y su exigencia. Durante la
  grabación lo que se valida es la secuencia de giros y no la contención en el marco, así que
  agrandarlo no afloja ningún criterio.

  Las medidas del marco no son configurables: están atadas entre sí y a la silueta, y elegirlas desde
  afuera rompe esa relación en silencio. Lo que sí se configura es el trazo.

- **iOS: el identificador de dispositivo ahora persiste en el Keychain.** El `identifierForVendor` de
  Apple se reinicia al desinstalar la última app del mismo vendor, que con una sola app es simplemente
  reinstalar. Guardándolo la primera vez, el identificador sobrevive la reinstalación.

### Corregido

- **iOS: el video podía grabarse acostado.** La orientación se fijaba en la salida que alimenta al
  detector pero no en la que escribe el archivo, así que el detector veía vertical y el video salía
  horizontal si el usuario acostaba el equipo. Ahora se fija en las tres salidas, en las tres cámaras.

- **Android: después de un desafío rechazado, el botón de grabar no se volvía a habilitar.** Al tocar
  el botón del diálogo de rechazo, la etiqueta del óvalo no desaparecía y el disparador quedaba
  deshabilitado, sin más salida que cerrar la cámara.

  La causa era una fuga de detectores faciales: se construía uno nuevo en cada redibujado de la vista y
  ninguno se cerraba. Con este desafío es grave, porque la detección corre **dentro** de la grabación y
  cada muestra de rostro redibuja. En el camino feliz no se notaba —la pantalla se cierra enseguida—,
  pero después de un rechazo hay que seguir detectando y ahí aparecía.

  Además, el reintento ahora descarta el rostro detectado para reevaluar el encuadre con una muestra
  nueva, y la secuencia vuelve al primer giro.

### Notas para quien integra

- **Habilitación de tu app (una sola vez).** Para que la atestación reúna evidencia, necesitamos de tu
  lado el **application id**, el **digest del certificado de firma** con el que publicás la app, y la
  **credencial de Play Integrity** de tu proyecto de Google Cloud (solo Android). Coordinalo con el
  equipo de Digiyo por el canal que ya usás para tu integración; **la credencial no va por correo ni en
  un issue**.

- **Android, Play Integrity**: el `cloudProjectNumber` es el número —no el id— de **tu** proyecto de
  Google Cloud, el mismo del que sale la credencial que nos entregaste. Si no coinciden, el token no se
  puede validar.

  Llamá a `DigiyoIntegrity.configure(...)` **antes** de inicializar el SDK: la preparación del API es
  costosa y se hace una sola vez, así que cuanto antes arranque, más chance de que el token esté listo
  en la primera captura.

- **iOS, App Attest**: tu app necesita estos dos entitlements. Sin ellos funciona igual, pero no se
  adjunta la evidencia de iOS.

  ```xml
  <key>com.apple.developer.devicecheck.app-attest-opt-in</key>
  <array>
      <string>CDhash</string>
  </array>
  <key>com.apple.developer.devicecheck.appattest-environment</key>
  <string>production</string>
  ```

- **Android, dependencia transitiva nueva**: el SDK ahora usa `io.github.roshkamobile:signet`, que se
  publica en **Maven Central**. No hay que declarar ningún repositorio adicional: el `mavenCentral()`
  que tu proyecto ya tiene alcanza, y no pide credenciales. Vas a verla aparecer en el árbol de
  dependencias.

---

## [2.1.3] — 2026-08-28

Apaga el certificate pinning por defecto, corrige un rechazo de subida que afectaba capturas **hechas
con el SDK**, y arregla dos defectos visuales y de comportamiento que sólo aparecían con ciertos temas o
en iOS.

Un solo punto a mirar al actualizar, y está en la primera entrada.

### Cambiado

- **⚠️ Si no pasás `enforceSslPinning`, ahora el pinning queda APAGADO.** Hasta la 2.1.2 el valor por
  defecto era `true`: una app que no conocía el parámetro heredaba validación estricta de certificados
  sin haberla pedido, y en cualquier entorno que no presente exactamente el certificado esperado —un
  proxy corporativo, un backend intermedio, un entorno de prueba— los envíos fallaban con lo que
  parecía un error de red genérico.

  **Si tu app depende de que el SDK valide certificados, tenés que pedirlo explícitamente:**

  ```kotlin
  DigiYoConfig(baseUrl = url, apiKey = key, enforceSslPinning = true)
  ```

  Es lo recomendado en producción contra el backend de Digiyo. El valor se guarda con el resto de la
  configuración, así que cuando el SDK arranca desde su caché se respeta lo que pediste antes —eso
  también se corrigió en esta versión—.

### Agregado

- **iOS: tres `init` de `DigiYoConfig` que te permiten no pasar `enforceSslPinning`.** En Kotlin el
  parámetro siempre se pudo omitir, pero en Swift no: la interfaz Objective-C no admite valores por
  defecto, así que cada `init` obliga a pasar todos sus parámetros. Sin estas variantes, "no pasar
  `enforceSslPinning`" era imposible y había que escribir `enforceSslPinning: false` a mano.

  ```swift
  DigiyocoreDigiYoConfig(baseUrl:apiKey:requestTimeoutInMillis:loggingEnabled:)
  DigiyocoreDigiYoConfig(baseUrl:apiKey:requestTimeoutInMillis:)
  DigiyocoreDigiYoConfig(baseUrl:apiKey:)
  ```

  Los `init` anteriores siguen existiendo: nada de lo que tengas hoy deja de compilar.

  Para cualquier otra combinación, sin depender de que exista el selector exacto, los cinco campos son
  propiedades asignables:

  ```swift
  let config = DigiyocoreDigiYoConfig(baseUrl: url, apiKey: key)
  config.requestTimeoutInMillis = 20000
  config.loggingEnabled = false
  ```

### Corregido

- **Un envío rápido podía ser rechazado como si el archivo no lo hubiera capturado el SDK.** Si tu app
  dispara `sendImage` o `sendVideo` inmediatamente después de recibir la ruta —lo natural si el envío
  sale del callback de la cámara—, el SDK podía abortar la subida diciendo que el archivo no lo produjo
  una de sus cámaras. **Era un falso positivo**, y el archivo sí era del SDK.

  La verificación de origen compara el archivo contra un registro que la cámara crea al escribirlo, y
  ese registro se calcula en segundo plano para no congelar la pantalla al terminar de grabar. Cuando la
  subida llegaba primero, no encontraba el registro y concluía lo peor. Ahora espera a que termine antes
  de decidir.

  No hay nada que cambiar en tu código. Si querés confirmarlo en los logs, cuando la espera hace falta
  queda registrada: *"el registro estaba EN CURSO; se esperó Nms y apareció"*.

- **iOS: la cámara de video podía avisar el resultado más de una vez, y con la ruta vacía.** Cuando tu
  app no configura `successAlertConfig`, el aviso se emitía desde el cuerpo del render, así que se
  repetía en cada redibujado y podía llegar antes de que el archivo tuviera ruta. Es la otra mitad del
  rechazo descrito arriba. Ahora llega **una sola vez y con la captura ya en disco**. Android no estaba
  afectado.

- **El texto del botón de los diálogos podía quedar invisible.** Si tu tema define `primaryTextColor` y
  no define `secondaryTextColor`, el SDK pintaba la etiqueta del botón con tu color de texto sobre un
  botón de tu color primario. Con dos colores parecidos —que es lo habitual— el texto desaparecía: se
  veían el título y el mensaje, y el botón sin label. Ahora el color de la etiqueta se calcula para
  contrastar con el fondo real del botón. Si definís `secondaryTextColor`, se sigue respetando.

### Compatibilidad

**Nada deja de compilar**: los `init` nuevos son aditivos y los existentes no cambiaron.

Lo único a revisar es de comportamiento, y es el pinning: si tu app no lo pasaba explícitamente y
confiaba en el default, **dejá `enforceSslPinning = true` antes de subir a producción**.

---

## [2.1.2] — 2026-08-27

Cierra los cuatro lugares donde una pantalla del SDK podía **crashear o quedarse sin salida**: el montaje
de las vistas de cámara en Android, la confirmación de la captura de documento en iOS, un video rechazado
y el permiso de cámara denegado. Y devuelve a Swift el `init` de `DigiYoError` que la 2.1.1 había cambiado.

El criterio detrás de todo esto: **un estado esperable del dispositivo o del flujo no puede terminar en un
crash ni en una pantalla muda.** Un permiso denegado, un desafío que no valida o un equipo sin cámara
trasera tienen que llegar a tu app como un mensaje y un `onClose`, no como una app cerrada o un usuario
atrapado.

Sin cambios rompientes: **una app integrada en la 2.1.1 compila y funciona sin tocar código** — y con la
2.1.2 vuelve a compilar el `init` de `DigiYoError` que la 2.1.1 le había roto a Swift.

### Agregado

- **`getCameraAccess(facing)`: preguntá si la cámara se puede abrir, antes de mostrar la pantalla.**
  Ya existía `getCameraAvailability()`, que mira el **hardware**; esta agrega el **permiso**, y hace falta
  porque el hardware solo te engaña —en direcciones opuestas según la plataforma—: en Android el sistema
  te informa las cámaras igual aunque el permiso esté denegado, y en iOS te las esconde cuando lo está,
  así que "no hay cámara" y "me lo negaron" se ven idénticos.

  ```kotlin
  when (val acceso = digiyo.getCameraAccess(CameraFacing.BACK)) {
      CameraAccess.DENIED -> mandarAAjustes()      // sólo el usuario lo resuelve
      CameraAccess.NO_CAMERA -> saltearElPaso()
      else -> abrirCamaraDeDocumento()
  }
  ```

  Si sólo querés decidir si abrir la pantalla, `acceso.canOpenCamera` alcanza.

  **El SDK sigue sin pedir el permiso**, y es a propósito: el momento en que se pide, el texto que lo
  acompaña y la declaración en tu manifiesto o tu `Info.plist` son decisiones de tu app, no del SDK.

### Corregido

- **Las vistas de cámara podían crashear al abrirse, en Android.** Si tu app monta una vista del SDK en
  una pantalla que el sistema mide **antes** de adjuntarla a una ventana, la app se caía con:

  ```
  IllegalStateException: Cannot locate windowRecomposer;
  View androidx.compose.ui.platform.ComposeView{...} is not attached to a window
  ```

  No era un caso raro: pasa con React Native cuando la app usa `react-native-screens` (que es lo que usan
  react-navigation y casi cualquier app con navegación), y también con Fragments en transición,
  `ViewPager2` o `BottomSheetDialog` en apps nativas. Es una **condición de carrera**: el mismo código
  funciona o falla según el frame en que caiga el montaje, y aparece con más frecuencia justo después de
  que el usuario responde el diálogo de permisos, porque ahí la pantalla se reactiva.

  Las cinco vistas —documento, selfie, video, ayuda y previsualización— ahora se entregan dentro de un
  contenedor que inserta la UI en el árbol recién cuando hay ventana. **No cambia nada de cómo se usan
  desde tu código**: el tipo devuelto sigue siendo el mismo y no hay props ni parámetros nuevos.

- **Sin permiso de cámara, la pantalla de captura no avisaba nada.** Un caso frecuente —el usuario negó el
  permiso, o tu app todavía no lo pidió— y el resultado era distinto en cada plataforma pero igual de
  terminal para el usuario final:

  - En **iOS** la app se **caía** al abrir la pantalla, con un `NullPointerException` desde dentro del SDK.
  - En **Android** no se caía, y era peor: la pantalla de captura se abría completa, con su overlay y sus
    instrucciones, pero el preview quedaba **negro**. Ningún mensaje, ninguna salida más que cerrar.

  Ahora las seis pantallas de cámara —documento, selfie y video, en las dos plataformas— avisan con un
  diálogo y su botón cierra la cámara, devolviéndote el control por `onClose`. Si tu configuración de
  cámara trae `errorAlertConfig` se usan tus textos; si no, los del SDK, distinguiendo "habilitá el
  permiso en los ajustes" de "este dispositivo no tiene esa cámara". No hay nada que cambiar en tu código
  para obtenerlo.

  Dos cosas que conviene saber, porque afectan lo que vas a ver al probarlo:

  - En **Android**, si el usuario concede el permiso con la pantalla abierta —respondiendo el pedido del
    sistema, o volviendo de los ajustes— la cámara **abre sola**, sin que tengas que remontar la vista. Y
    el diálogo espera medio segundo antes de aparecer: si tu app monta la vista y pide el permiso al mismo
    tiempo —patrón habitual en React Native—, no vas a ver el aviso del SDK parpadear detrás del pedido
    del sistema.
  - En **iOS**, si el usuario **nunca respondió** el permiso, no cambia nada: el diálogo del sistema lo
    sigue disparando la propia pantalla del SDK y ese primer uso funciona como siempre.

  Lo que sigue siendo tuyo es pedir el permiso en el momento adecuado —y con `getCameraAccess` podés
  evitar la pantalla del todo—. Lo que cambia es que el SDK ya no se queda callado cuando no puede.

- **Un video rechazado ya no deja la pantalla sin salida.** Si el desafío de liveness no validaba, la
  pantalla de video se quedaba como estaba: el video grabado, ningún mensaje, ningún callback hacia tu
  app, y para el usuario sólo el botón de cerrar —perdiendo la captura y teniendo que reiniciar el flujo—.
  El diálogo que explica el motivo existía, pero sólo si tu app pasaba `errorAlertConfig`.

  Ahora **el SDK siempre avisa**: si configuraste `errorAlertConfig` se usan tus textos, y si no, los del
  SDK. En los dos casos el motivo concreto lo escribe el validador del desafío ("No se detectó el giro
  hacia la izquierda…", "No se logró capturar su rostro en el óvalo reducido…") y el botón permite
  reintentar sin salir de la pantalla. No hay nada que cambiar en tu código para obtenerlo.

- **iOS: la captura de documento podía romper la app al confirmarla.** La cámara de documentos avisaba el
  resultado antes de terminar de escribir los archivos, así que tu app recibía un primer aviso con las
  rutas vacías y —si navegás en ese callback, que es lo natural— desmontaba la cámara a mitad de la
  captura. En React Native con la nueva arquitectura eso terminaba en un crash de render; en una
  integración nativa, en un view controller a medio destruir. Ahora el aviso llega una sola vez y con la
  captura ya en disco. La cámara de selfie no estaba afectada.

- **El SDK podía informar en tus DIA una versión que no era la instalada.** El número que el SDK reporta
  en `ADDITIONAL_INFO.digiyo_version` se congelaba al subir de versión: podías ver un caso soportado
  diciendo `1.4.4-patch` cuando la app tenía otra versión. Era un problema de nuestro build, no de tu
  integración, pero afectaba directamente el diagnóstico —el dato que usamos para saber qué versión
  reprodujo un problema—. Ya está corregido: a partir de esta versión el número que viaja es el publicado.

### Compatibilidad

- **iOS / Swift: se restituye `DigiYoError(code:detail:userVisible:)`.** Al agregar `retryable`, la 2.1.1
  cambió el `init` a `DigiYoError(code:detail:userVisible:retryable:)` y una app Swift que **construyera**
  el error dejaba de compilar. La 2.1.2 mantiene el `init` de tres parámetros además del nuevo, igual que
  la 2.1.0 hizo con `CaptureModeConfig`, `VideoChallengeTexts` y `DigiYoRGB`. Si venías de la 2.1.1 y
  tuviste que agregar el parámetro, tu código sigue compilando: los dos `init` conviven.
- **Android / Kotlin.** Nada que hacer: alcanza con recompilar contra la versión nueva.

---

## [2.1.1] — 2026-08-25

Hace que los envíos al backend sobrevivan los cortes de red, y que un fallo de conexión llegue a tu app
como un error identificable y reintentable en lugar de uno genérico. Acorta además el plazo de la
secuencia de giros de cabeza.

Un solo punto a mirar: si tu app **construye** un `DigiYoError` en Swift, la firma cambió. Leerlo en los
`onError` sigue igual que antes.

### Corregido

- **En iOS los envíos no se reintentaban nunca.** El SDK ya traía reintentos automáticos para cortes de
  red, pero la detección no reconocía las excepciones del motor HTTP de iOS: en la práctica, cualquier
  fallo de transporte terminaba el envío en el primer intento. Ahora iOS reintenta ante conexión perdida,
  timeout, host inalcanzable y falta de red, y **no** reintenta lo que el usuario canceló ni los fallos de
  TLS o de certificate pinning, donde repetir sólo repite el rechazo. En Android la detección tampoco
  cubría toda la familia de errores de E/S —quedaban afuera los fallos de TLS, los resets de HTTP/2 y los
  de resolución de nombres—; ahora sí.

  El caso concreto: grabar el video, tocar enviar y pasar la app a segundo plano. iOS corta la conexión
  del envío ("The network connection was lost") y hasta esta versión eso terminaba el intento. Ahora el
  reintento queda programado y, si el sistema no terminó el proceso, el envío se completa al volver a la
  app sin que el usuario tenga que hacer nada.

- **Un corte de red llegaba a tu app como "Error inesperado".** Sólo los rechazos HTTP traían código; los
  problemas de red y las respuestas ilegibles caían todos en el mismo error genérico, sin código y con
  `userVisible = false`. No había forma de saber que el fallo era transitorio ni qué mostrarle al usuario.
  Ahora:

  | Qué pasó | `code` | `userVisible` | `retryable` |
  |---|---|---|---|
  | el servidor rechazó (4xx/5xx) | el código de estado | `false` | `false` |
  | se cortó la red, timeout, sin conexión | `NETWORK_ERROR` | `true` | `true` |
  | la respuesta no se pudo interpretar | `SERIALIZATION_ERROR` | `false` | `false` |

  `DigiYoError` gana el campo **`retryable`**. Cuando viene en `true`, la captura sigue en disco
  —`sendImage` y `sendVideo` reciben una ruta, no bytes—, así que reintentar es volver a llamar la misma
  función con los mismos argumentos: es el momento de ofrecer un botón "reintentar" en lugar de cortar el
  flujo.

  **Si tu app muestra el error tal como viene** (el objeto serializado, `{"detail":"…"}`), ahora conviene
  leer `detail` y decidir con `userVisible` y `retryable`: el `toString()` incluye más campos que antes.

- **Un fallo interno de `sendVideo` se reportaba como si el envío hubiera salido.** Cuando el cliente HTTP
  no estaba disponible, el PATCH no se emitía pero el error viajaba con el mismo mensaje genérico que un
  rechazo del servidor. Ahora entrega `code = "SDK_SERVICE_UNAVAILABLE"` y se registra como previo al
  envío.

### Cambiado

- **Los reintentos bajan de 5 a 3, con espera creciente entre intentos.** Con los reintentos recién
  funcionando en iOS, cinco intentos ponían en juego seis subidas completas del video —decenas de MB cada
  una, sin reanudación— sobre los datos móviles del usuario. Y un corte de conexión no se resuelve en los
  250 ms de la espera anterior.

- **La secuencia de giros baja su piso de 20 s a 7 s.** Como la grabación se corta sola al completarse la
  secuencia, ese número nunca fue el largo del video: es el **plazo** que tiene el usuario para completar
  los cuatro giros. `videoRecordDurationMs` sigue funcionando como piso: si tu app pide más de 7000 se
  respeta; si pide menos, se aplican 7000 (antes, cualquier valor por debajo de 20000 quedaba en 20 s).

  **Medí antes de actualizar si tus usuarios recorren el flujo por primera vez.** De los 7 s, el
  sostenimiento de las cuatro poses y el acuse de recibo ya consumen ~2,4 s: quedan ~4,6 s para leer las
  consignas y mover la cabeza. Si tu tasa de reintentos sube, pasá un `videoRecordDurationMs` mayor.

### Diagnóstico

- **Los logs que el SDK envía al backend ahora dicen de dónde vino el fallo.** El mensaje lleva un prefijo
  estable, `origin=<backend|transport|sdk> op=<operación>`. Al reportar un problema de envío, ese prefijo
  separa tres cosas que antes eran indistinguibles en el log: el servidor rechazó, la red se cortó, o el
  SDK no llegó a emitir el request. `transport` es un origen propio a propósito: en un corte de conexión
  el request pudo haber llegado igual, así que un envío marcado `origin=transport` que **sí** aparece en
  el log del servidor indica que la subida llegó y la respuesta se perdió.

### Compatibilidad

`DigiYoError` ganó el campo `retryable`, y el efecto depende de la plataforma:

- **Android / Kotlin.** El campo tiene valor por defecto: tu código compila sin cambios, alcanza con
  actualizar la dependencia.
- **iOS / Swift.** La interfaz Objective-C no admite valores por defecto, así que el `init` pasa a ser
  `DigiYoError(code:detail:userVisible:retryable:)`. Si tu app **construye** un `DigiYoError` —poco
  habitual: normalmente sólo se lee el que llega en los `onError`—, hay que agregar el parámetro. A
  diferencia de la 2.1.0, esta versión no conserva un `init` con la firma anterior para esta clase.

Si integrás a través de un bridge propio, revisá que reenvíe el campo nuevo: por ejemplo el bridge de
React Native expone hoy `code`, `detail` y `userVisible`, y necesita una línea más por plataforma.

### Lo que esta versión no resuelve

El envío sigue siendo una petición en primer plano. Los reintentos cubren el corte y la reconexión, pero
si el sistema **suspende** la app —segundo plano el tiempo suficiente— el envío muere y el video se sube
de nuevo desde cero al reintentar. Resolverlo requiere subida en segundo plano gestionada por el sistema
(`URLSession` background con el archivo en disco en iOS), lo que además obliga a que la app host declare
el handler correspondiente. Queda para una versión propia.

---

## [2.1.0] — 2026-08-21

Convierte el desafío `look_left_right` en una verificación real del movimiento de cabeza, y abre a
personalización el estilo de los textos sobre el óvalo y la forma del botón obturador.

Sin cambios rompientes: **una app integrada en la 2.0.2 compila y funciona sin tocar código.**

### Agregado

#### Secuencia de giros de cabeza (`look_left_right`)

Cuando `createDia` devuelve `in_data.POL_VIDEO.config.live_validations.look_left_right = true`, la
pantalla de video ahora pide cuatro poses **en orden** y las verifica contra el ángulo del rostro:

`girar a la izquierda` → `volver al frente` → `girar a la derecha` → `volver al frente` → completada

Antes, ese desafío mostraba una animación de una cabeza girando y **no comprobaba nada**: se cumplía
dejando el teléfono apoyado. El video que llegaba al backend podía no tener un solo giro.

- Al completarse, la grabación **se corta sola** —sin esperar el límite de duración—, el marco del óvalo
  pasa al `successColor` del `colorScheme` y el mensaje de completado se dibuja en ese mismo color.
- En este desafío el marco **no** se pone del color de éxito al encuadrar el rostro, como sí hace en los
  demás: se mantiene neutro hasta completar los cuatro giros, así ese color señala una sola cosa.
- **El óvalo no desaparece al encuadrar el rostro**, a diferencia del resto de los desafíos: se mantiene
  desde ese momento y durante toda la grabación, porque es la referencia contra la que el usuario acomoda
  la cabeza mientras gira. Lo que sí se oculta al quedar encuadrado es `ovalLabelText`, junto con la caja
  de ayuda de debajo del óvalo. El botón de disparo no cambia.
- Un giro brusco no alcanza: cada pose hay que sostenerla un instante. Es lo que hace que el video sirva
  para la verificación del backend.
- Si el usuario no completa la secuencia, aparece un mensaje que indica **en qué giro se quedó**.

> ⚠️ **La duración de la grabación tiene un piso de 20 segundos con este desafío.** Si tu app pasa un
> `VideoCameraConfig.videoRecordDurationMs` menor, se ignora y se usan 20 s. Son cuatro poses que el
> usuario tiene que leer, ejecutar y sostener: con los 5 s por defecto no se llegaba ni a la mitad y el
> intento terminaba siempre en el mensaje de fallo. **No alarga el caso exitoso**, porque al completarse
> la secuencia la grabación se corta antes del límite. Un valor **mayor** que el piso sí se respeta. Es
> el mismo criterio que ya tenía `pol_depth`, con un piso de 12 s.

#### `VideoChallengeTexts`: estilo de los textos sobre el óvalo

| Campo nuevo | Para qué | Sin definir |
|---|---|---|
| `ovalLabelBackgroundColor` | Fondo de los textos sobre el óvalo | el `successColor` del `colorScheme`, como estaba fijo antes |
| `ovalLabelFontSize` | Tamaño en sp | `34.0`, el valor de siempre |

Sirve para el caso en que el color de éxito del esquema no da suficiente contraste con letras blancas, o
simplemente no es el que la marca quiere ahí. Con `DigiYoRGB.TRANSPARENT` se ve solo el texto.

#### `VideoChallengeTexts`: instrucciones de la secuencia

Cuatro campos nuevos —`lookLeftInstructionText`, `lookFrontInstructionText`,
`lookRightInstructionText`, `lookSequenceCompletedText`— para la consigna de cada fase.

- **No tienen texto por defecto.** Sin definir, esa fase no muestra nada. Se pueden definir de a una.
- **Que no haya texto no afecta la validación.** Los cuatro giros se verifican igual: sin textos el
  desafío se cumple exactamente igual, el usuario solo no ve la consigna.
- Se truncan a 40 caracteres. Sin `look_left_right` activo no tienen ningún efecto.

`ovalLabelText` no cambia: sigue cayendo en `"ALÉJESE"` cuando no se define.

#### `DigiYoRGB.alpha` y `DigiYoRGB.TRANSPARENT`

`DigiYoRGB` gana un cuarto canal opcional, `alpha`, de `0` a `255` y por defecto `255`. Hasta ahora no
había forma de pedir un color transparente o semitransparente.

```kotlin
DigiYoRGB(61, 169, 224)            // opaco, como siempre
DigiYoRGB(0, 0, 0, alpha = 120)    // semitransparente
DigiYoRGB.TRANSPARENT              // invisible
```

El constructor de tres componentes sigue existiendo, así que el código ya escrito no cambia.

#### `ShutterButtonConfig`: apariencia de los obturadores circulares

Nuevo campo `CaptureModeConfig.shutterButtonConfig`, para configurar **diámetro, relleno y aro** de los
botones `ShutterButtonType1` y `ShutterButtonType2`. Con `DefaultButton` no tiene efecto.

| Campo | Qué controla | Sin definir |
|---|---|---|
| `diameter` | Lado total en dp (piso de 40 dp) | `64.0` |
| `backgroundColor` | Relleno interior: la superficie más visible | celeste claro / blanco según el tipo |
| `borderColor` | Color del aro | blanco |
| `borderWidth` | Grosor del aro en dp | proporcional al diámetro |
| `outerColor` | Círculo exterior, apenas perceptible | el del preset del SDK |

Cada campo es opcional por separado. El aro y el disco se escalan con el `diameter`, así que el botón
crece proporcionado sin tocar los otros campos.

Va aparte de `cameraButtonConfig` porque describen cosas distintas: `ButtonConfig` es un botón
rectangular con texto —`label`, `shape`, `buttonStyle`— y ninguno de esos campos significa algo en un
círculo.

### Corregido

- **`CaptureModeConfig.buttonType` se ignoraba en la cámara de documentos.** `DocumentCameraView`
  dibujaba siempre el botón rectangular: aceptaba `ShutterButtonType1` y `ShutterButtonType2` sin hacer
  nada con ellos y sin ningún aviso. En `SelfieCameraView` y `VideoCameraView` venía funcionando. Si tu
  app ya pasaba un `buttonType` de obturador para capturar cédulas, **el botón va a cambiar de aspecto**
  al actualizar: ahora se respeta lo que pediste.

- **El contador y el indicador REC se apoyaban sobre el borde inferior del óvalo** durante la grabación.
  Ahora quedan por debajo, con separación.

- **Al disparar, el obturador circular mostraba un círculo gris por detrás del disco**, pisando el
  `outerColor` configurado incluso si se había pedido transparente. Ahora, cuando la app pasa
  `shutterButtonConfig`, el círculo exterior conserva su color y la señal de deshabilitado la da el aro,
  que se apaga hacia el gris. **Sin `shutterButtonConfig` el botón queda exactamente igual que antes.**

### Compatibilidad

Tres clases ganaron campos, y las tres conservan un `init` con la firma de la 2.0.2 para que las apps
**Swift** no tengan que tocar código —la interfaz Objective-C no admite valores por defecto, así que cada
campo nuevo cambiaría el selector—:

| Clase | Firma preservada |
|---|---|
| `CaptureModeConfig` | los 7 parámetros anteriores a `shutterButtonConfig` |
| `VideoChallengeTexts` | los 9 parámetros anteriores a los de estilo y secuencia |
| `DigiYoRGB` | `DigiYoRGB(red, green, blue)` |

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
