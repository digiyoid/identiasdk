# Guía Completa: Digiyo SDK - Kotlin Multiplatform

![GitHub Release](https://img.shields.io/github/v/release/digiyoid/identiasdk)

## ¿Qué es Digiyo SDK?

Digiyo SDK es una solución para integrar funcionalidades de identificación digital en aplicaciones móviles. Se compone de dos módulos principales:

- **DigiyoCore**: Maneja la comunicación HTTP con los servicios de Digiyo.
- **DigiyoSDK**: Proporciona una capa de interfaz de usuario (UI) lista para usar y depende de DigiyoCore.

Este SDK emplea inteligencia artificial para la detección precisa y eficiente de documentos, rostros y manos. En Android, se basa en **MLKit**, mientras que en iOS utiliza **Vision** para la detección en imágenes y videos.

---

## Descargo de responsabilidad

**Nota:** Este proyecto está en constante desarrollo y actualización. Algunas partes de esta documentación podrían quedar desactualizadas. Te recomendamos verificar siempre las últimas versiones del SDK y consultar con el equipo de soporte si tienes alguna duda.

---

## Instalación del SDK

### Android

El SDK requiere un mínimo de **API 24**. Para instalar la librería en una aplicación Android, agrega la siguiente dependencia en el archivo `build.gradle` o `build.gradle.kts` de tu módulo App:

```groovy
implementation "com.roshka:digiyocore:{versión del sdk}"
implementation "com.roshka:digiyo{versión del sdk}"
```
En el `build.gradle` (`settings.gradle` o `settings.gradle.kts`) del proyecto, se configura el repositorio Maven apuntando a GithubPackages de la siguiente manera:

```groovy
    //Github Packages
    dependencyResolutionManagement {
        ...
        repositories {
            ...
             maven {
                name = "GitHubPackages"
                url = uri("https://maven.pkg.github.com/digiyoid/identiasdk")
                credentials {
                    username = System.getenv("GITHUB_USER") // tu usuario de Github
                    password = System.getenv("GITHUB_PAT") // tu Personal Access Token
                }
            }
            ...
        }
    }
```
**Nota**: Maven Registry en Github Packages necesita autenticación para acceder a la lista de paquetes incluso cuando son públicos, por ello, el Username y un Personal Access Token de Github son necesarios. 
Se recomienda definir ambos como variables de entorno.
___

Si encuentras errores relacionados con **CameraX**, también incluye la siguiente dependencia:

```groovy
implementation 'com.google.guava:guava:32.1.2-android'
```

### iOS

En iOS, puedes instalar Digiyo SDK utilizando **Swift Package Manager**. Para ello, agrega la siguiente URL a tu proyecto:

```
git@github.com:Digiyoid/identiasdk.git
```

---

## Configuración e inicialización

Una vez inicializado con `DigiyoConfig`, en inicializaciones posteriores puedes pasar `null` (en Android) porque la configuración se almacena localmente y se recupera automáticamente.

### Android

```kotlin
import DigiyoSDK

// Configuración del SDK
private val config = DigiyoConfig(
    baseUrl = BuildConfig.Digiyo_BASE_URL, // URL base definida en BuildConfig
    apiKey = BuildConfig.Digiyo_API_KEY,    // Clave API definida en BuildConfig
    requestTimeoutInMillis = null          // Timeout opcional (Cuando no es definida usa el valor por defecto de 60 segundos)
)

//El Context es requerido para poder acceder al directorio de las fotografías y videos una vez que el flujo haya terminado.

// Instancia de DigiyoSDK
private val Digiyo = DigiyoSDK(context, config)
```

### iOS

```swift
import Digiyo

// Configuración del SDK
let DigiyoSDK = DigiyoSDK(config: DigiyocoreDigiyoConfig(
    baseUrl: ProcessInfo.processInfo.environment["Digiyo_BASE_URL"],
    apiKey: ProcessInfo.processInfo.environment["Digiyo_API_KEY"],
    requestTimeoutInMillis: nil
))
```

---

## Métodos principales

### Índice

- [createDia](#createdia)
- [commitDia](#commitdia)
- [verifyTasksAndCommit](#verifytasksandcommit)
- [getDia](#getdia)
- [sendImage](#sendimage)
- [sendImageAsynchronously](#sendimageasynchronously)
- [sendVideo](#sendvideo)
- [sendVideoAsynchronously](#sendvideoasynchronously)
- [CaptureModeConfig](#capturemodeconfig)
- [DigiyoColorScheme](#Digiyocolorscheme)
- [DocumentCameraView](#documentcameraview)
- [SelfieCameraView](#selfiecameraview)
- [VideoCameraView](#videocameraview)
- [HelpScreenView](#helpscreenview)
- [MediaPreviewScreen](#mediapreviewscreen)
- [sendTextData](#sendtextdata)
- [sendJsonData](#sendjsondata)
- [getInData](#getindata)
- [Nuevos Parámetros Agregados](#nuevos-parámetros-agregados)
- [DigiYoIcons](#digiyoicons)

---

### `createDia`

Crea un nuevo DIA (Documento de Identificación y Autenticación).

#### Android

```kotlin
Digiyo.createDia(
    diaType = "standard-validation-sdk",
    onSuccess = { dia ->
        // Success
    },
    onError = { error ->
        // Error
    }
)
```

#### iOS

```swift
DigiyoSDK.createDia(diaType: "standard-validation-sdk") { dia in
    // Success
} onError: { error in
    // Error
}
```

**Parámetros**

- **`diaType`** (*String*): Tipo de DIA, por ejemplo: "standard-validation-sdk".
- **`onSuccess`** (*Callback*): Función invocada en caso de éxito.
- **`onError`** (*Callback*): Función invocada en caso de error.

---

### `commitDia`

Realiza el commit del DIA para iniciar el procesamiento en el backend.

#### Android

```kotlin
Digiyo.commitDia(
    diaId = diaId,
    onSuccess = { status ->
        // Success
    },
    onError = {
        // Error
    }
)
```

#### iOS

```swift
DigiyoSDK.commitDia(diaId: DigiyoSDK.getSavedDia()?.diaId ?? "") { status in
    // Success
} onError: { error in
    // Error
}
```

**Parámetros**

- **`diaId`** (*String*): ID del DIA que se desea procesar.

---

### `verifyTasksAndCommit`

Verifica las tareas de subida de imágenes o video asíncronas y espera a que todos terminan para realizar el commit del DIA e iniciar el procesamiento en el backend.

#### Android

```kotlin
Digiyo.verifyTasksAndCommit(
    diaId = diaId,
    onSuccess = { status ->
        // Success
    },
    onError = {
        // Error
    },
    onTasksNotCompleted = { tasks ->
        // Retorna la lista de inDataName que no pudieron ser enviados en forma asíncrona
    }
)
```

#### iOS

```swift
DigiyoSDK.verifyTasksAndCommit(diaId: DigiyoSDK.getSavedDia()?.diaId ?? "") { status in
    // Success
} onError: { error in
    // Error
} onTasksNotCompleted: { tasks in
    // Retorna la lista de inDataName que no pudieron ser enviados en forma asíncrona
}
```

**Parámetros**

- **`diaId`** (*String*): ID del DIA que se desea procesar.

---

### `getDia`

Obtiene el estado del DIA en el backend.

#### Android

```kotlin
Digiyo.getDia(
    diaId = Digiyo.getSavedDia()?.diaId ?: "",
    onSuccess = { res ->
        res?.let {
            if (it.status != "STARTED" && it.status != "PENDING") {
                // Proceso completado
            }
        } ?: run {
            // Error en la respuesta
        }
    },
    onError = { error ->
        // Error
    }
)
```

#### iOS

```swift
DigiyoSDK.getDia(diaId: DigiyoSDK.getSavedDia()?.diaId ?? "") { [weak self] res in
    // Verificar estado
    if res?.status != "STARTED" && res?.status != "PENDING" {
        // Proceso completado
    }
} onError: { [weak self] error in
    // Error
}
```

**Notas**

- Este método debe llamarse periódicamente (por ejemplo, cada segundo) hasta que el estado deje de ser "STARTED" o "PENDING".

- Los siguientes campos dentro del objeto 'ResultModel' estarán disponibles en Camel Case dentro de la respuesta:

    `ValidationFlags`

    Campo del Response | Campo del model (SDK) 
    --- | ---
    "ci_es_real" | `isDocumentReal`
    "ci_no_expeirado" | `documentNotExpired`
    "selfie_es_real" | `isSelfieReal`
    "ci_numero_validado" | `documentNumberVerified`
    "prueba_de_vida_aprobada" | `proofOfLifeApproved`
    "fecha_de_nacimiento_valida" | `birthDateVerified`


---

### `sendImage`

Sube imágenes capturadas.

#### Android

```kotlin
Digiyo.sendImage(
    diaId = Digiyo.getSavedDia()?.diaId ?: "",
    filePath = filePath,
    inDataName = "ID_CARD_FRONT", // Ejemplo
    liveValidationOptions = LiveValidationOptions(
        faceEyeCheck = false,
        faceSmileCheck = false,
        idOnFaceCheck = false,
        fingerCheck = false
    ), //Ejemplo
    onSuccess = {
        // Success
    },
    onError = {
        // Error
    }
)
```

#### iOS

```swift
DigiyoSDK.sendImage(
    diaId: DigiyoSDK.getSavedDia()?.diaId ?? "",
    filePath: filePath,
    inDataName: "ID_CARD_FRONT", // Ejemplo
    liveValidationOptions: LiveValidationOptions(
        faceEyeCheck: false,
        faceSmileCheck: false,
        idOnFaceCheck: false,
        fingerCheck: false
    ), //Ejemplo
) { status in
    // Success
} onError: { error in
    // Error
}
```

**Notas**

- **`inDataName`** especifica el nombre del inData al que se asociará la imagen. Por ejemplo: "ID_CARD_FRONT".
- Para ubicar los inData disponibles, puedes usar el método `getSavedDia`.
- **`liveValidationOptions`** es un campo de configuración de las validaciones a realizar a la imagen: ojos, sonrisa, documento y dedos (El campom es opcional y solamente debe ser enviado en caso de ser necesario).

---

### `sendImageAsynchronously`

Sube imágenes capturadas en forma asíncrona, sin esperar por el resultado. Los errores seran verificados durante la ejecución de **`verifyTasksAndCommit`**.

#### Android

```kotlin
Digiyo.sendImageAsynchronously(
    diaId = Digiyo.getSavedDia()?.diaId ?: "",
    filePath = filePath,
    inDataName = "ID_CARD_FRONT", // Ejemplo
    liveValidationOptions = LiveValidationOptions(
        faceEyeCheck = false,
        faceSmileCheck = false,
        idOnFaceCheck = false,
        fingerCheck = false
    ), //Ejemplo
)
```

#### iOS

```swift
DigiyoSDK.sendImageAsynchronously(
    diaId: DigiyoSDK.getSavedDia()?.diaId ?? "",
    filePath: filePath,
    inDataName: "ID_CARD_FRONT", // Ejemplo
    liveValidationOptions: LiveValidationOptions(
        faceEyeCheck: false,
        faceSmileCheck: false,
        idOnFaceCheck: false,
        fingerCheck: false
    ), //Ejemplo
)
```

**Notas**

- **`inDataName`** especifica el nombre del inData al que se asociará la imagen. Por ejemplo: "ID_CARD_FRONT".
- Para ubicar los inData disponibles, puedes usar el método `getSavedDia`.
- **`liveValidationOptions`** es un campo de configuración de las validaciones a realizar a la imagen: ojos, sonrisa, documento y dedos (El campom es opcional y solamente debe ser enviado en caso de ser necesario).

---

### `sendVideo`

Sube un video grabado.

#### Android

```kotlin
val finalData = InDataEntryModel(
    name = data.name,
    data = DataRequireModel(
        value = data.data?.value,
        contentType = data.data?.contentType,
        config = InDataConfigModel(versusArray = listOf(2))
    )
)

Digiyo.sendVideo(
    diaId = Digiyo.getSavedDia()?.diaId ?: "",
    filePath = filePath,
    inData = finalData,
    onSuccess = {
        // Success
    },
    onError = {
        // Error
    }
)
```

#### iOS

```swift
var finalData = DigiyocoreInDataEntryModel(
    name: data.name,
    data: DigiyocoreDataRequireModel(
        value: data.data?.value,
        contentType: data.data?.contentType,
        config: DigiyocoreInDataConfigModel(versusArray: [2])
    )
)

DigiyoSDK.sendVideo(
    diaId: DigiyoSDK.getSavedDia()?.diaId ?? "",
    filePath: filePath,
    inData: finalData
) { status in
    // Success
} onError: { error in
    // Error
}
```

**Parámetros**

- **`inData`** (*InDataEntryModel*): Configuración del video. El campo `versusArray` indica cuántos dedos se deben detectar.
- **`diaId`** (*String*): ID del DIA asociado.
- **`filePath`** (*String*): Ruta al archivo de video.

---

### `sendVideoAsynchronously`

Sube un video grabado en forma asíncrona, sin esperar por el resultado. Los errores seran verificados durante la ejecución de **`verifyTasksAndCommit`**.

#### Android

```kotlin
val finalData = InDataEntryModel(
    name = data.name,
    data = DataRequireModel(
        value = data.data?.value,
        contentType = data.data?.contentType,
        config = InDataConfigModel(versusArray = listOf(2))
    )
)

Digiyo.sendVideoAsynchronously(
    diaId = Digiyo.getSavedDia()?.diaId ?: "",
    filePath = filePath,
    inData = finalData
)
```

#### iOS

```swift
var finalData = DigiyocoreInDataEntryModel(
    name: data.name,
    data: DigiyocoreDataRequireModel(
        value: data.data?.value,
        contentType: data.data?.contentType,
        config: DigiyocoreInDataConfigModel(versusArray: [2])
    )
)

DigiyoSDK.sendVideoAsynchronously(
    diaId: DigiyoSDK.getSavedDia()?.diaId ?? "",
    filePath: filePath,
    inData: finalData
)
```

**Parámetros**

- **`inData`** (*InDataEntryModel*): Configuración del video. El campo `versusArray` indica cuántos dedos se deben detectar.
- **`diaId`** (*String*): ID del DIA asociado.
- **`filePath`** (*String*): Ruta al archivo de video.

---

### `CaptureModeConfig`

Configuración del modo de captura de: DocumentCameraView, SelfieCameraView y VideoCameraView

#### Android

```kotlin
Digiyo.DocumentCameraView(
    config = DocumentCameraConfig(
       ...
        captureModeConfig = CaptureModeConfig(
            automaticReadingEnabled = true,
            automaticModeTimeoutMillis = 8000,
            manualCaptureButtonTitle = "Capturar documento",
            manualCaptureButtonColor = null
        ),
    ),
    onClose = {
        navController.popBackStack()
    },
    onResult = { imageCropped, imageFull ->
        viewModel.patchPhoto(filePath = imageCropped, imageFullPath = imageFull)
    },
)
```

#### iOS

```swift
DigiyoSDK.getDocumentCameraViewController(
    config: DocumentCameraConfig(
        ...
        captureModeConfig: CaptureModeConfig(
            automaticReadingEnabled: true,
            automaticModeTimeoutMillis: 8000,
            manualCaptureButtonTitle: "Capturar documento",
            manualCaptureButtonColor: nil
        ),
    ),
    onResult = { imageCropped, imageFull in
        viewModel.sendImage(filePath: imageCropped, imageFullPath: imageFull)
    },
    onClose: {
        self.presentationMode.wrappedValue.dismiss()
    }
)
```

**Parámetros**

- **`automaticReadingEnabled`** (*Boolean*): Activa o desactiva el modo de captura automática.
- **`automaticModeTimeoutMillis`** (*Long?*): Si no es nulo, define el tiempo en milisegundos en que la captura automática estrá activada antes de pasar a modo manual.
- **`manualCaptureButtonTitle`** (*String?*): Título del botón de captura manual.
- **`manualCaptureButtonColor`** (*DigiyoRGB?*): Color del botón de captura manual. Si es nulo, se utiliza seondaryColor o primaryColor del colorScheme.

---

### `DigiyoColorScheme`

Configuración para facilitar la personalización de colores de algunos elementos en: DocumentCameraView, SelfieCameraView y VideoCameraView.

#### Android

```kotlin
Digiyo.DocumentCameraView(
    config = DocumentCameraConfig(
       ...
        colorScheme = DigiyoColorScheme.fromPrimaryColor(
            DigiyoRGB(red: 94, green: 240, blue: 160)
        ),
        ...
    ),
    onClose = {
        navController.popBackStack()
    },
    onResult = { imageCropped, imageFull ->
        viewModel.patchPhoto(filePath = imageCropped, imageFullPath = imageFull)
    },
)
```

#### iOS

```swift
DigiyoSDK.getDocumentCameraViewController(
    config: DocumentCameraConfig(
        ...
        colorScheme = DigiyoColorScheme.companion.fromPrimaryColor(
            DigiyoRGB(red: 94, green: 240, blue: 160)
        ),
        ...
    ),
    onResult = { imageCropped, imageFull in
        viewModel.sendImage(filePath: imageCropped, imageFullPath: imageFull)
    },
    onClose: {
        self.presentationMode.wrappedValue.dismiss()
    }
)
```

**Parámetros**

- **`primaryColor`** (*DigiyoRGB*): Color primario a ser utilizado.
- **`secondaryColor`** (*DigiyoRGB?*): Color complementario que será utilizado en botones y otros componentes. Si no se define, se utiliza el color primario.
- **`accentColor`** (*DigiyoRGB?*): Color a ser utilizado en los marcos y otros detalles.
- **`primaryTextColor`** (*DigiyoRGB?*): Color de texto primario.
- **`secondaryTextColor`** (*DigiyoRGB?*): Color de texto secundario.
- **`errorColor`** (*DigiyoRGB?*): Color en caso de error.
- **`successColor`** (*DigiyoRGB?*): Color en caso de éxito.

**Helpers**

##### Android

- **`DigiyoColorScheme.fromPrimaryColor(DigiyoRGB)`** (*DigiyoRGB*): Crea un colorScheme usando el color primario y valores por defecto.

##### iOS

- **`DigiyoColorScheme.companion.fromPrimaryColor(DigiyoRGB)`** (*DigiyoRGB*): Crea un colorScheme usando el color primario y valores por defecto.

---

### `DocumentCameraView`

Muestra una vista (Android) o un `UIViewController` (iOS) para capturar fotos de documentos.

#### Android

```kotlin
val context = LocalContext.current
val customImage = AppCompatResources.getDrawable(context, R.drawable.vc_document_front)?.toBase64Image()
...

Digiyo.DocumentCameraView(
    config = DocumentCameraConfig(
        cameraTitle = "ID Card - Front",
        successAlertConfig = SuccessAlertConfig(
            title = "Next Step",
            subTitle = "Scan the back side",
            buttonTitle = "Continue",
            primaryColor = DigiyoRGB(red = 94, green = 185, blue = 240),
            imageBase64 = customImage,
            displayDefaultActivityIndicator = false,
            displayDialogAsBottomSheet = false
        ),
        documentType = DocumentType.ID_FRONT,
        colorScheme = DigiyoColorScheme.fromPrimaryColor(
            DigiyoRGB(red: 94, green: 240, blue: 160)
        ),
        showCloseButton = false,
        captureModeConfig = CaptureModeConfig(
            automaticReadingEnabled = true,
            automaticModeTimeoutMillis = 8000,
            manualCaptureButtonTitle = "Capturar documento",
            manualCaptureButtonColor = null
        ),
        showDetectedObjectRect = true,
        smartCropEnabled = false
    ),
    onClose = {
        navController.popBackStack()
    },
    onResult = { imageCropped, imageFull ->
        viewModel.patchPhoto(filePath = imageCropped, imageFullPath = imageFull)
    },
)
```

#### iOS

```swift
var customImage: String?
if let image = UIImage(named: "vc_document_front") {
     customImage = ExtensionsKt.toBase64Image(image)
}
...

DigiyoSDK.getDocumentCameraViewController(
    config: DocumentCameraConfig(
        cameraTitle: "ID Card - Front",
        documentType: .idFront,
        colorScheme = DigiyoColorScheme.companion.fromPrimaryColor(
            DigiyoRGB(red: 94, green: 240, blue: 160)
        ),
        successAlertConfig: SuccessAlertConfig(
            title: "Next Step",
            subTitle: "Scan the back side",
            buttonTitle: "Continue",
            primaryColor: DigiyoRGB(red: 94, green: 185, blue: 240),
            iamgeBase64: customImage,
            displayDefaultActivityIndicator: false,
            displayDialogAsBottomSheet: false
        ),
        showCloseButton: false,
        captureModeConfig: CaptureModeConfig(
            automaticReadingEnabled: true,
            automaticModeTimeoutMillis: 8000,
            manualCaptureButtonTitle: "Capturar documento",
            manualCaptureButtonColor: nil
        ),
        showDetectedObjectRect: true,
        smartCropEnabled: false
    ),
    onResult = { imageCropped, imageFull in
        viewModel.sendImage(filePath: imageCropped, imageFullPath: imageFull)
    },
    onClose: {
        self.presentationMode.wrappedValue.dismiss()
    }
)
```

**Parámetros**

- **`config`** (*DocumentCameraConfig*): Configuración de la cámara.
- **`onResult`** (*Callback*): Retorna las rutas de las imágenes capturadas.
- **`onClose`** (*Callback*): Se invoca al cerrar la cámara.

---

### `SelfieCameraView`

Muestra una vista (Android) o un `UIViewController` (iOS) para capturar selfies con la cámara frontal.

#### Android

```kotlin
val context = LocalContext.current
val customImage = AppCompatResources.getDrawable(context, R.drawable.vc_document_front)?.toBase64Image()
...

Digiyo.SelfieCameraView(
    config = SelfieCameraConfig(
        cameraTitle = "Selfie",
        successAlertConfig = SuccessAlertConfig(
            title = "Next Step",
            subTitle = "Record a 5-second video",
            buttonTitle = "Continue",
            primaryColor = DigiyoRGB(94, 185, 240),
            imageBase64 = customImage,
            displayDefaultActivityIndicator = false,
            displayDialogAsBottomSheet = false
        ),
        colorScheme = DigiyoColorScheme.fromPrimaryColor(
            DigiyoRGB(red: 94, green: 240, blue: 160)
        ),
        showCloseButton = false,
        captureModeConfig = CaptureModeConfig(
            automaticReadingEnabled = true,
            automaticModeTimeoutMillis = 8000,
            manualCaptureButtonTitle = "Capturar selfie",
            manualCaptureButtonColor = null
        ),
    ),
    onResult = { path ->
        viewModel.patchPhoto(filePath = path)
    },
    onClose = {
        navController.popBackStack()
    }
)
```

#### iOS

```swift
var customImage: String?
if let image = UIImage(named: "vc_document_front") {
     customImage = ExtensionsKt.toBase64Image(image)
}
...

DigiyoSDK.getSelfieCameraViewViewController(
    config: SelfieCameraConfig(
        cameraTitle: "Selfie",
        colorScheme = DigiyoColorScheme.companion.fromPrimaryColor(
            DigiyoRGB(red: 94, green: 240, blue: 160)
        ),
        successAlertConfig: SuccessAlertConfig(
            title: "Next Step",
            subTitle: "Record a 5-second video",
            buttonTitle: "Continue",
            primaryColor = DigiyoRGB(red: 94, green: 185, blue: 240),
            imageBase64: customImage,
            displayDefaultActivityIndicator: false,
            displayDialogAsBottomSheet: false
        ),
        showCloseButton: true,
        captureModeConfig: CaptureModeConfig(
            automaticReadingEnabled: true,
            automaticModeTimeoutMillis: 8000,
            manualCaptureButtonTitle: "Capturar selfie",
            manualCaptureButtonColor: nil
        ),
    )
) { path in
    viewModel.patchPhoto(filePath: path)
} onClose: {
    self.presentationMode.wrappedValue.dismiss()
}
```

**Parámetros**

- **`config`** (*SelfieCameraConfig*): Configuración de la cámara.
- **`onResult`** (*Callback*): Retorna la ruta de la imagen capturada.
- **`onClose`** (*Callback*): Se invoca al cerrar la cámara.

---

### `VideoCameraView`

Muestra una vista (Android) o un `UIViewController` (iOS) para grabar videos.

#### Android

```kotlin
Digiyo.VideoCameraView(
    config = VideoCameraConfig(
        cameraTitle = "Show 2 fingers",
        colorScheme = DigiyoColorScheme.fromPrimaryColor(
            DigiyoRGB(red: 94, green: 240, blue: 160)
        ),
        successAlertConfig = SuccessAlertConfig(
            title = "Done",
            subTitle = "We will now analyze your video",
            buttonTitle = "OK",
            primaryColor = DigiyoRGB(94, 185, 240),
            customImage = null,
            displayDefaultActivityIndicator = false,
            displayDialogAsBottomSheet = false
        ),
        showCloseButton = false,
        errorAlertConfig = ErrorAlertConfig(
            title = "Oops!",
            subTitle = "No hand detected in the video",
            buttonTitle = "Try again",
            primaryColor = DigiyoRGB(94, 185, 240),
            displayDefaultActivityIndicator = false,
            displayDialogAsBottomSheet = false
        ),
        captureModeConfig = CaptureModeConfig(
            automaticReadingEnabled = true,
            automaticModeTimeoutMillis = 8000,
            manualCaptureButtonTitle = "Grabar video",
            manualCaptureButtonColor = null
        ),
    ),
    onResult = { path ->
        viewModel.patchVideo(filePath = path)
    },
    onClose = {
        navController.popBackStack()
    }
)
```

#### iOS

```swift
DigiyoSDK.getVideoCameraViewViewController(
    config: VideoCameraConfig(
        cameraTitle: "Video",
        colorScheme = DigiyoColorScheme.companion.fromPrimaryColor(
            DigiyoRGB(red: 94, green: 240, blue: 160)
        ),
        successAlertConfig: SuccessAlertConfig(
            title: "Next Step",
            subTitle: "We will now analyze your video",
            buttonTitle: "Continue",
            primaryColor = DigiyoRGB(red: 94, green: 185, blue: 240),
            customImage: nil,
            displayDefaultActivityIndicator: false,
            displayDialogAsBottomSheet: false
        ),
        errorAlertConfig: ErrorAlertConfig(
            title: "Oops!",
            subTitle: "No hand detected in the video",
            buttonTitle: "Try again",
            primaryColor: DigiyoRGB(red: 94, green: 185, blue: 240),
            displayDefaultActivityIndicator: false,
            displayDialogAsBottomSheet: false
        ),
        showCloseButton: true,
        captureModeConfig: CaptureModeConfig(
            automaticReadingEnabled: true,
            automaticModeTimeoutMillis: 8000,
            manualCaptureButtonTitle: "Grabar video",
            manualCaptureButtonColor: nil
        ),
    )
) { path in
    viewModel.patchVideo(filePath: path)
} onClose: {
    self.presentationMode.wrappedValue.dismiss()
}
```

**Parámetros**

- **`config`** (*VideoCameraConfig*): Configuración de la cámara.
- **`onResult`** (*Callback*): Retorna la ruta del video grabado.
- **`onClose`** (*Callback*): Se invoca al cerrar la cámara.

---

### `HelpScreenView`

Muestra una vista (Android) o un `UIViewController` (iOS) que puede ser tutilizado para desplegar recomendaciones a lo largo del flujo.

#### Android

```kotlin
val context = LocalContext.current
val icon = AppCompatResources.getDrawable(context, R.drawable.vc_document_front)?.toBase64Image()
...


digiyoSDK.getHelpScreenView(
    config = HelpConfig(
        helpScreenTitle = "Foto frontal de tu cédula",
        helpScreenImageBase64 = icon,
        colorScheme =  DigiYoColorScheme.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
        ),
        imageShouldFollowColorScheme = false,
        bulletAndAdvices = listOf(
            HelpBulletPoint.Check to "Foto legible, bien iluminada.",
            HelpBulletPoint.Check to "Coloca tu CI en una superficie plana y de un solo color.",
            HelpBulletPoint.Check to "Pon el teléfono cerca para que tu rostro y número de CI se vean con claridad.",
            HelpBulletPoint.Error to "No enviés CI editadas o caducadas.",
        ),
        continueButtonTitle = "Escanear documento",
        customTitleTextColor = null,
        customContinueButtonColor = DigiYoColorScheme.DEFAULT_COLOR_SCHEME.primaryColor,
        displayDefaultActivityIndicator = false
        ),
     onButtonPressed = {
        navController.navigate("step2")
    },
)
```

#### iOS

```swift
var base64Image: String?
if let image = UIImage(named: "vc_document_front") {
     base64Image = ExtensionsKt.toBase64Image(image)
}
...

viewModel.digiyoSDK.getHelpScreenViewViewController(
    config: HelpConfig(
        helpScreenTitle: "Foto frontal de tu cédula",
        helpScreenImageBase64: base64Image,
        colorScheme: DigiYoColorScheme.companion.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
        ),
        imageShouldFollowColorScheme: false,
        bulletAndAdvices: [
            KotlinPair(first: HelpBulletPoint.check, second: "Foto legible, bien iluminada."),
            KotlinPair(first: HelpBulletPoint.check, second: "Coloca tu CI en una superficie plana y de un solo color."),
            KotlinPair(first: HelpBulletPoint.check, second: "Pon el teléfono cerca para que tu rostro y número de CI se vean con claridad."),
            KotlinPair(first: HelpBulletPoint.error, second: "No enviés CI editadas o caducadas.")
        ],
        continueButtonTitle: "Escanear documento",
        customTitleTextColor: nil,
        customContinueButtonColor: DigiYoColorScheme.companion.DEFAULT_COLOR_SCHEME.primaryColor),
        displayDefaultActivityIndicator: false,
    onButtonPressed: {
        viewModel.navigateToNextScreen = true
    }
)
```

**Parámetros**

- **`config`** (*HelpConfig*): Configuración de la pantalla de recomendación/ayuda.
- **`onButtonPressed`** (*Callback*): Acción a realizar al presionar el botón.

---

### `MediaPreviewScreen`

Muestra una vista (Android) o un `UIViewController` (iOS) que puede ser tutilizado para previsualizar las imágenes o videos capturados antes de su envío.

#### Android
```

digiyoSDK.getMediaPreviewScreen(
    config = MediaPreviewConfig(
        previewScreenTitle = "Verifica tu fotografía",
        previewSubtitle = "Asegurate que la foto de tu cédula frontal\nsea visible y con buena iluminación.",
        previewMediaPath = mediaPath, // Path de la imagen o el video capturado
        isMediaAVideo = true,
        colorScheme = null,
        bulletAndAdvices = null,
        primaryButtonTitle = "Continuar",
        secondaryButtonTitle = "Volver a tomar la foto",
        customTitleTextColor = null,
        customPrimaryButtonColor = DigiYoColorScheme.DEFAULT_COLOR_SCHEME.primaryColor,
        customSecondaryButtonColor = DigiYoColorScheme.DEFAULT_COLOR_SCHEME.primaryColor,
        displayDefaultActivityIndicator = false,
    ),
    onPrimaryButtonPressed = {

    },
    onSecondaryButtonPressed = {

    }
) // Ejemplo
```

#### iOS

```swift

viewModel.digiyoSDK.getMediaPreviewScreenViewController(
    config: MediaPreviewConfig(
        previewScreenTitle: "Verifica tu fotografía",
        previewSubtitle: "Asegurate que la foto de tu cédula frontal\nsea visible y con buena iluminación.",
        previewMediaPath: mediaPath, //Path de la imagen o el video capturado
        isMediaAVideo: true,
        colorScheme: nil,
        bulletAndAdvices: nil,
        primaryButtonTitle: "Continuar",
        customPrimaryButtonColor: DigiYoColorScheme.companion.DEFAULT_COLOR_SCHEME.primaryColor,
        secondaryButtonTitle: "Volver a tomar la foto",
        customSecondaryButtonColor: DigiYoColorScheme.companion.DEFAULT_COLOR_SCHEME.primaryColor,
        customTitleTextColor: nil,
        displayDefaultActivityIndicator: false,
    ),
    onPrimaryButtonPressed: {

    },
    onSecondaryButtonPressed: {

    }
) // Ejemplo
```

**Parámetros**

- **`config`** (*MediaPreviewConfig*): Configuración de la pantalla de vista previa.
- **`onPrimaryButtonPressed`** (*Callback*): Acción a realizar al presionar el botón principal.
- **`onSecondaryButtonPressed`** (*Callback*): Acción a realizar al presionar el botón secundario.

---

### `sendTextData`

Permite enviar datos de texto a un DIA específico.

#### Android

```kotlin
Digiyo.sendTextData(
    diaId = "DIA_ID",
    value = "TEXT_VALUE",
    inDataName = "REQUIRED_INDATA_NAME",
    onSuccess = {
        // Success
    },
    onError = { error ->
        // Error
    }
)
```

#### iOS

```swift
DigiyoSDK.sendTextData(
    diaId: DigiyoSDK.getSavedDia()?.diaId ?? "",
    value: "TEXT_VALUE",
    inDataName: "REQUIRED_INDATA_NAME"
) { _ in
    // Success
} onError: { error in
    // Error
}
```

**Parámetros**

- **`diaId`** (*String*): ID del DIA donde se asociarán los datos.
- **`value`** (*String*): Valor de texto a enviar.
- **`inDataName`** (*String*): Nombre del inData para indicar el tipo de dato.
- **`onSuccess`** (*Callback*): Función llamada en caso de éxito.
- **`onError`** (*Callback*): Función llamada en caso de error.

---

### `sendJsonData`

Permite enviar datos en formato JSON a un DIA específico.

#### Android

```kotlin
Digiyo.sendJsonData(
    diaId = "DIA_ID",
    json = "{\"key\":\"value\"}",
    onSuccess = {
        // Success
    },
    onError = { error ->
        // Error
    }
)
```

#### iOS

```swift
DigiyoSDK.sendJsonData(
    diaId: DigiyoSDK.getSavedDia()?.diaId ?? "",
    json: "{\"key\":\"value\"}"
) { _ in
    // Success
} onError: { error in
    // Error
}
```

**Parámetros**

- **`diaId`** (*String*): ID del DIA donde se asociará el JSON.
- **`json`** (*String*): Cadena JSON a enviar.
- **`onSuccess`** (*Callback*): Función llamada en caso de éxito.
- **`onError`** (*Callback*): Función llamada en caso de error.

---

### `getInData`

Obtiene un `InDataEntryModel` a partir de su nombre.

#### Android

```kotlin
val inDataEntry = Digiyo.getInData("ID_CARD_FRONT")
if (inDataEntry != null) {
    // Do something with inDataEntry
}
```

#### iOS

```swift
let inDataEntry = DigiyoSDK.getInData("ID_CARD_FRONT")
if let entry = inDataEntry {
    // Do something with entry
}
```

**Parámetros**

- **`inDataName`** (*String*): Nombre de la entrada inData que se desea obtener.

**Retorna**

- *`InDataEntryModel?`*: El modelo correspondiente si se encuentra, o `null` en caso contrario.

---

### `Nuevos Parámetros Agregados`

- #### DocumentCameraConfig:
  - **`showDetectedObjectRect`** (*Boolean*): Permite activar o desactivar el dibujado de un rectángulo alrededor del objeto detectado.
  - **`smartCropEnabled`** (*Boolean*): Permite activar o desactivar el recorte de la imagen usando el rectángulo detectado. Si se encuentra desactivado, la referencia es el recuadro guía presente en la pantalla de cámara.
- #### HelpConfig:
  - **`imageShouldFollowColorScheme`** (*Boolean*): Permite manejar si la imagen agregada debe ser o no coloreada con respecto al colorScheme.
- #### SuccessAlertConfig
  - **`imageBase64`** (*String?*): Permite agregar una imagen personalizada al modal, codificada en Base64. Pueden utilizarse las imagenes presentes en el SDK en ```DigiYoIcons```:
    - Android: ```DigiYoIcons.DocBackImage```
    - iOS: ```DigiYoIcons.shared.DocBackImage```

- #### SuccessAlertConfig, ErrorAlertConfig
  - **`displayDialogAsBottomSheet`** (*Boolean*): Permite manejar si el modal correspondiente debe mostrarse como un BottomSheet o como un AlertDialog.
- #### HelpConfig, SuccessAlertConfig, ErrorAlertConfig
  - **`displayDefaultActivityIndicator`** (*Boolean*): Permite la opción de mostrar u ocultar el activity indicator presente dentro de esas vistas con una condición.

---

### `DigiYoIcons`

Agrupa las imágenes e iconos presentes en el SDK:

- CheckImage
- DocFrontImage
- DocBackImage
- SelfieImage
- VideoImage
- ErrorImage
- ErrorImageInverted
- ProfileImage
- NoGlassesImage

---
