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

## [1.5.5] — 2026-08-06

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
