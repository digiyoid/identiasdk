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

## Tabla de Contenido

### [Instalación del SDK](#instalación-del-sdk)
### [Configuración e inicialización](#configuración-e-inicialización)
### [Métodos principales](#métodos-principales)
- [createDia](#createdia)
- [getDia](#getdia)
- [cancelDia](#canceldia)
- [sendImage](#sendimage)
- [sendImageAsynchronously](#sendimageasynchronously)
- [sendVideo](#sendvideo)
- [sendVideoAsynchronously](#sendvideoasynchronously)
- [sendTextData](#sendtextdata)
- [sendJsonData](#sendjsondata)
- [getInData](#getindata)
- [commitDia](#commitdia)
- [verifyTasksAndCommit](#verifytasksandcommit)
- [checkEnrollment](#checkenrollment)
### [Personlización y estilos](#personalización-y-estilos)
- [CaptureModeConfig](#capturemodeconfig)
- [DigiyoColorScheme](#digiyocolorscheme)
- [ButtonConfig](#buttonconfig)
- [DigiYoShape](#digiyoshape)
- [DigiYoButtonStyle](#digiyobuttonstyle)
- [CaptureButtonType](#capturebuttontype)
- [InfoBoxConfig](#infoboxconfig)
- [DigiYoIcons](#digiyoicons)
### [Componentes de UI](#componentes-de-ui-1)
- [DocumentCameraView](#documentcameraview)
- [SelfieCameraView](#selfiecameraview)
- [VideoCameraView](#videocameraview)
- [HelpScreenView](#helpscreenview)
- [MediaPreviewScreen](#mediapreviewscreen)
### Otros
- [Nuevos Parámetros Agregados](#nuevos-parámetros-agregados)
- [Proguard](#proguard-android)

---

## `Instalación del SDK`

### Android

El SDK requiere un mínimo de **API 24**. Para instalar la librería en una aplicación Android, agrega la siguiente dependencia en el archivo `build.gradle` o `build.gradle.kts` de tu módulo App:

```groovy
implementation "com.roshka:digiyocore:1.2.0"
implementation "com.roshka:digiyo:1.2.0"
```

En el `build.gradle` (`settings.gradle` o `settings.gradle.kts`) del proyecto, se configura el repositorio Maven apuntando a GithubPackages de la siguiente manera:

```groovy
    //Github Packages con Variables de Entorno
    dependencyResolutionManagement {
        ...
        repositories {
            ...
             maven {
                name = "GitHubPackages"
                url = uri("https://maven.pkg.github.com/digiyoid/identiasdk")
                credentials {`~
                    username = System.getenv("GITHUB_USER") // Variable de entorno que contiene el usuario de Github
                    password = System.getenv("GITHUB_PAT") // Variable de Entorno que contiene el Personal Access Token
                }
            }
            ...
        }
    }
```

En el archivo `.bashrc` (o equivalente en Macos, Linux u otros de tipo Unix), definir las variables de entorno de las siguiente manera:

```bash
#.bashrc de tu S.O.

export GITHUB_USER="tu usuario de Github"
export GITHUB_PAT="tu Personal Access Token"

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

## `Configuración e inicialización`

Una vez inicializado con `DigiyoConfig`, en inicializaciones posteriores puedes pasar `null` (en Android) porque la configuración se almacena localmente y se recupera automáticamente.

### Android

#### `Configuración`

```kotlin
import DigiyoSDK

// Configuración del SDK
private val config = DigiyoConfig(
    baseUrl = BuildConfig.Digiyo_BASE_URL,  // URL base definida en BuildConfig.
    apiKey = BuildConfig.Digiyo_API_KEY,    // Clave API definida en BuildConfig.
    enforceSslPinning: null,                // Cuando el valor no es asignado explícitamente, el SSL Pinning es activado por defecto.
    requestTimeoutInMillis = null           // Timeout opcional (Cuando no es definida usa el valor por defecto de 60 segundos)
)
```

#### `Inicialización directa de la instancia`

```kotlin
//El Context es requerido para poder acceder al directorio de las fotografías y videos una vez que el flujo haya terminado.

// Instancia de DigiyoSDK
private val digiyoSdk = DigiYoSDK(context, config)
```

#### `Inicialización mediante DigiYoHelper (Recomendada)`

```kotlin
//El Context es requerido para poder acceder al directorio de las fotografías y videos una vez que el flujo haya terminado.

DigiYoHelper.initialize(
    applicationContext,
    config
)

// Obtener instancia de DigiyoSDK
private val digiyoSdk = DigiYoHelper.sdk
```

### iOS

#### `Configuración`

```swift
import Digiyo

// Configuración del SDK
let digiyoConfig = DigiyocoreDigiyoConfig(
    baseUrl: ProcessInfo.processInfo.environment["Digiyo_BASE_URL"],
    apiKey: ProcessInfo.processInfo.environment["Digiyo_API_KEY"],
    enforceSslPinning: nil,
    requestTimeoutInMillis: nil
)
```

#### `Inicialización directa de la instancia`

```swift
// Instancia del SDK
let digiyoSdk = DigiYoSDK(config: digiyoConfig)
```

#### `Inicialización mediante DigiYoHelper (Recomendada)`

```swift
DigiYoHelper.shared.initialize(config: digiyoConfig)

//Obtener la instancia del SDK
let digiyoSdk = DigiYoHelper.shared.sdk
```

---

## `Métodos principales`

### `createDia`

Crea un nuevo DIA (Documento de Identificación y Autenticación).

#### Android

```kotlin
digiyoSdk.createDia(
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
digiyoSdk.createDia(diaType: "standard-validation-sdk") { dia in
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

### `getDia`

Obtiene el estado del DIA en el backend.

#### Android

```kotlin
digiyoSdk.getDia(
    diaId = digiyoSdk.getSavedDia()?.diaId ?: "",
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
digiyoSdk.getDia(diaId: digiyoSdk.getSavedDia()?.diaId ?? "") { [weak self] res in
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
    "is_cedula_temporal" | `isDocumentTemporary`


---

---

### `cancelDia`

Cancela el DIA especificado mediante su diaId.

#### Android

```kotlin
digiyoSdk.cancelDia(
    diaId = digiyoSdk.getSavedDia()?.diaId ?: "",
    onSuccess = { res ->
        res?.let {
            // Cancelacion exitosa
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
digiyoSdk.cancelDia(diaId: digiyoSdk.getSavedDia()?.diaId ?? "") { [weak self] res in
    // Cancelacion exitosa
} onError: { [weak self] error in
    // Error
}
```

**Parámetros**

- **`diaId`** (*String*): ID del DIA que se desea procesar.

---

### `sendImage`

Sube imágenes capturadas.

#### Android

```kotlin
digiyoSdk.sendImage(
    diaId = digiyoSdk.getSavedDia()?.diaId ?: "",
    filePath = filePath,
    inDataName = "ID_CARD_FRONT", // Ejemplo
    liveValidationOptions = LiveValidationOptions(
        lookLeftRight = false,
        lookUpDown = false,
        openCloseMouth = false,
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
digiyoSdk.sendImage(
    diaId: digiyoSdk.getSavedDia()?.diaId ?? "",
    filePath: filePath,
    inDataName: "ID_CARD_FRONT", // Ejemplo
    liveValidationOptions: LiveValidationOptions(
        lookLeftRight: false,
        lookUpDown: false,
        openCloseMouth: false,
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
digiyoSdk.sendImageAsynchronously(
    diaId = digiyoSdk.getSavedDia()?.diaId ?: "",
    filePath = filePath,
    inDataName = "ID_CARD_FRONT", // Ejemplo
    liveValidationOptions = LiveValidationOptions(
        lookLeftRight = false,
        lookUpDown = false,
        openCloseMouth = false,
        faceEyeCheck = false,
        faceSmileCheck = false,
        idOnFaceCheck = false,
        fingerCheck = false
    ), //Ejemplo
)
```

#### iOS

```swift
digiyoSdk.sendImageAsynchronously(
    diaId: digiyoSdk.getSavedDia()?.diaId ?? "",
    filePath: filePath,
    inDataName: "ID_CARD_FRONT", // Ejemplo
    liveValidationOptions: LiveValidationOptions(
        lookLeftRight: false,
        lookUpDown: false,
        openCloseMouth: false,
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
- **`liveValidationOptions`** es un campo de configuración de las validaciones a realizar a la imagen: ojos, sonrisa, documento y dedos (El campo es opcional y solamente debe ser enviado en caso de ser necesario).

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
        config = InDataConfigModel(
          versusArray = listOf(2),
          liveValidations = LiveValidationOptions(
              lookLeftRight = false,
              lookUpDown = false,
              openCloseMouth = false,
              faceEyeCheck = false,
              faceSmileCheck = false,
              idOnFaceCheck = false,
              fingerCheck = false
          ).toMap()
        )
    )
)

digiyoSdk.sendVideo(
    diaId = digiyoSdk.getSavedDia()?.diaId ?: "",
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
        config: DigiyocoreInDataConfigModel(
            versusArray: [2],
            liveValidations: LiveValidationOptions(
                lookLeftRight: false,
                lookUpDown: false,
                openCloseMouth: false,
                faceEyeCheck: false,
                faceSmileCheck: false,
                idOnFaceCheck: false,
                fingerCheck: false
            ).toMap()
        )
    )
)

digiyoSdk.sendVideo(
    diaId: digiyoSdk.getSavedDia()?.diaId ?? "",
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

**Observación:** Tanto el campo de la cantidad de dedos `versusArray`, como campo de configuración de las validaciones `liveValidations` están incluidos dentro de la estructura del `InDataEntryModel -> InDataConfigModel` (Es opcional y solamente debe ser enviado en caso de ser necesario, caso contrario deberá setearse como `null | nil`).

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
        config = InDataConfigModel(
            versusArray = listOf(2),
            liveValidations = LiveValidationOptions(
                lookLeftRight = false,
                lookUpDown = false,
                openCloseMouth = false,
                faceEyeCheck = false,
                faceSmileCheck = false,
                idOnFaceCheck = false,
                fingerCheck = false
            ).toMap()
        )
    )
)

digiyoSdk.sendVideoAsynchronously(
    diaId = digiyoSdk.getSavedDia()?.diaId ?: "",
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
        config: DigiyocoreInDataConfigModel(
            versusArray: [2],
            liveValidations: LiveValidationOptions(
                lookLeftRight: false,
                lookUpDown: false,
                openCloseMouth: false,
                faceEyeCheck: false,
                faceSmileCheck: false,
                idOnFaceCheck: false,
                fingerCheck: false
            ).toMap()
        )
    )
)

digiyoSdk.sendVideoAsynchronously(
    diaId: digiyoSdk.getSavedDia()?.diaId ?? "",
    filePath: filePath,
    inData: finalData
)
```

**Parámetros**

- **`inData`** (*InDataEntryModel*): Configuración del video. El campo `versusArray` indica cuántos dedos se deben detectar.
- **`diaId`** (*String*): ID del DIA asociado.
- **`filePath`** (*String*): Ruta al archivo de video.

**Observación:** Tanto el campo de la cantidad de dedos `versusArray`, como campo de configuración de las validaciones `liveValidations` están incluidos dentro de la estructura del `InDataEntryModel -> InDataConfigModel` (Es opcional y solamente debe ser enviado en caso de ser necesario, caso contrario deberá setearse como `null | nil`).

---


### `sendTextData`

Permite enviar datos de texto a un DIA específico.

#### Android

```kotlin
digiyoSdk.sendTextData(
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
digiyoSdk.sendTextData(
    diaId: digiyoSdk.getSavedDia()?.diaId ?? "",
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
digiyoSdk.sendJsonData(
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
digiyoSdk.sendJsonData(
    diaId: digiyoSdk.getSavedDia()?.diaId ?? "",
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
let inDataEntry = digiyoSdk.getInData("ID_CARD_FRONT")
if let entry = inDataEntry {
    // Do something with entry
}
```

**Parámetros**

- **`inDataName`** (*String*): Nombre de la entrada inData que se desea obtener.

**Retorna**

- *`InDataEntryModel?`*: El modelo correspondiente si se encuentra, o `null` en caso contrario.

---

### `commitDia`

Realiza el commit del DIA para iniciar el procesamiento en el backend.

#### Android

```kotlin
digiyoSdk.commitDia(
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
digiyoSdk.commitDia(diaId: digiyoSdk.getSavedDia()?.diaId ?? "") { status in
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
digiyoSdk.verifyTasksAndCommit(
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
digiyoSdk.verifyTasksAndCommit(diaId: digiyoSdk.getSavedDia()?.diaId ?? "") { status in
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

### `checkEnrollment`

Verifica el estado del enrolamiento.

#### Android

```kotlin
digiyoSdk.checkEnrollment(
    diaId = digiyoSdk.getSavedDia()?.diaId ?: "",
    idNumber = "1234567",
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
digiyoSdk.checkEnrollment(
    diaId: digiyoSdk.getSavedDia()?.diaId ?? "",
    idNumber: "1234567",
    onSuccess: { status in
        // Success
    },
    onError: { error in
        // Error
    },
    onTasksNotCompleted: { tasks in
        // Retorna la lista de inDataName que no pudieron ser enviados en forma asíncrona
    }
)
```

**Parámetros**

- **`diaId`** (*String*): ID del DIA que se desea procesar.
- **`idNumber`** (*String*): El número de documento que se desea verificar.

---

## `Personalización y Estilos`

### `DigiyoColorScheme`

Configuración para facilitar la personalización de colores de algunos elementos en: DocumentCameraView, SelfieCameraView y VideoCameraView.

#### Android

```kotlin
digiyoSdk.DocumentCameraView(
    config = DocumentCameraConfig(
       ...
        colorScheme = DigiyoColorScheme.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
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
digiyoSdk.getDocumentCameraViewController(
    config: DocumentCameraConfig(
        ...
        colorScheme = DigiyoColorScheme.companion.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
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

- **`primaryColor`** (*DigiYoRGB*): Color primario a ser utilizado.
- **`secondaryColor`** (*DigiYoRGB?*): Color complementario que será utilizado en botones y otros componentes. Si no se define, se utiliza el color primario.
- **`accentColor`** (*DigiYoRGB?*): Color a ser utilizado en los marcos y otros detalles.
- **`primaryTextColor`** (*DigiYoRGB?*): Color de texto primario.
- **`secondaryTextColor`** (*DigiYoRGB?*): Color de texto secundario.
- **`errorColor`** (*DigiYoRGB?*): Color en caso de error.
- **`successColor`** (*DigiYoRGB?*): Color en caso de éxito.

**Helpers**

##### Android

- **`DigiyoColorScheme.fromPrimaryColor(DigiYoRGB)`** (*DigiYoRGB*): Crea un colorScheme usando el color primario y valores por defecto.

##### iOS

- **`DigiyoColorScheme.companion.fromPrimaryColor(DigiYoRGB)`** (*DigiYoRGB*): Crea un colorScheme usando el color primario y valores por defecto.

---

### `DigiYoImageAsset`

Es un interface que contiene los métodos para interactuar con las imágenes provenientes de ambas plataformas.
Su implementación concreta sería:

#### Android

```kotlin

val context = LocalContext.current

ImageAsset(context, R.drawable.vc_document_front)

```
#### iOS

```swift

ImageAsset("vc_document_front")

```

### `CaptureModeConfig`

Configuración del modo de captura de: DocumentCameraView, SelfieCameraView y VideoCameraView

#### Android

```kotlin
digiyoSdk.DocumentCameraView(
    config = DocumentCameraConfig(
       ...
        captureModeConfig = CaptureModeConfig(
            automaticReadingEnabled = true,
            automaticModeTimeoutMillis = 8000,
            buttonConfig = ButtonConfig(
                label = "Capturar documento",
                shape = DigiYoShape.Rounded(24.0f),
                buttonStyle = DigiYoButtonStyle.Default,
                isLoading = false,
                contentPadding = 32,
                debounceIntervalMs = null,
                backgroundColor = DigiYoColorScheme.DEFAULT_COLOR_SCHEME.onSuccessColor,
                contentColor = null,
                disabledBackgroundColor = null,
                disabledContentColor = null
            ),
            buttonType = CaptureButtonType.Default,
            buttonBehavior = null,
            infoBoxConfig = null,
            overwriteDefaultTextWith = null
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
digiyoSdk.getDocumentCameraViewController(
    config: DocumentCameraConfig(
        ...
        captureModeConfig: CaptureModeConfig(
            automaticReadingEnabled: true,
            automaticModeTimeoutMillis: 8000,
            buttonConfig: ButtonConfig(
                label: "Capturar documento",
                shape: DigiYoShape.Rounded(cornerRadius: 24.0),
                buttonStyle: DigiYoButtonStyle.Default(),
                isLoading: false,
                contentPadding: 32,
                debounceIntervalMs: nil,
                backgroundColor: DigiYoColorScheme.Companion().DEFAULT_COLOR_SCHEME.onSuccessColor,
                contentColor: nil,
                disabledBackgroundColor: nil,
                disabledContentColor: nil
            ),
            buttonType: CaptureButtonType.defaultbutton,
            buttonBehavior: nil,
            infoBoxConfig: nil,
            overwriteDefaultTextWith: nil
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
- **`buttonConfig`** (*ButtonConfig?*): Corresponde a la configuración de personalización del botón, incluyendo el título.
- **`buttonType`** (*CaptureButtenType?*): Corresponde al tipo de botón.
- **`buttonBehavior`** (*CaptureButtonBehavior?*): Corresponde al comportamiento del botón al capturar la foto o el video. Por defecto, el botón queda desactivado.
- **`infoBoxConfig`** (*InfoBoxConfig?*): Corresponde a la configuración de personalización de la información que se despliega en la captura.
- **`overwriteDefaultTextWith`** (String?): Permite reemplazar el texto por defecto del infoBox. (Si existen validaciones activas, el texto de las validaciones tienen prioridad, por lo que deben de personalizarse desde `customLiveValidationsText` en la configuración correspondiente)

---

### `ButtonConfig`

Configuración de personalización de botones.

**Parámetros**

- **`label`** (*String*): Título del botón.
- **`shape`** (*DigiYoShape*): Forma del botón.
- **`buttonStyle`** (*DigiYoButtonStyle*): Corresponde al estilo del botón.
- **`isLoading`** (*Boolean*): Utilizado para activar y desactivar el activity indicator del botón.
- **`debounceIntervalMs`** (*Long?*): Corresponde al tiempo de espera del botón antes de volver a aceptar otra interacción. Si es nulo su valor es de 2 segundos.
- **`backgroundColor`** (*DigiYoRGB*): Color del botón activo.
- **`contentColor`** (*DigiYoRGB?*): Color del título, opcional. Se utiliza un color que contrasta con el color del botón cuando no se asigna explícitamente.
- **`disabledBackgroundColor`** (*DigiYoRGB?*): Color del botón inactivo. Cuando es nulo, usa un valor predeterminado.
- **`disabledContentColor`** (*DigiYoRGB?*):Color del texto inactivo. Cuando es nulo, usa un valor predeterminado.

---

### `DigiYoShape`

Forma del botón a personalizar.

**Tipos**

- **`Circle`** : Círculo.
- **`Rounded(cornerRadius: Float | Dp)`** : Rectángulo con esquinas redondeadas. Recibe el radio de la esquina como parámetro.
- **`Square`** : Rectángulo.

---

### `DigiYoButtonStyle`

Estilo del botón a personalizar.

**Tipos**

- **`Default`** : Text centrado.
- **`TextOnlyStart`** : Texto alineado a la izquierda.
- **`TextOnlyEnd`** : Texto alineado a la derecha.
- **`TextWithIconSpaceBetween`** : Texto alineado a la izquierda con icono. Recibe un DigiYoImageAsset como parámetro.
- **`TextWithIconCentered`** : Texto con icono, centrados. Recibe un DigiYoImageAsset como parámetro.

---

### `CaptureButtonType`

Tipo de botón. Tiene prioridad sobre el estilo del botón.

**Tipos**

- **`DefaultButton`** : Botón normal.
- **`ShutterButtonType1`** : Botón tipo shutter.
- **`ShutterButtonType2`** : Botón tipo shutter (estilo alternativo).

---

### `CaptureButtonBehavior`

Comportamiento del botón al tomar la foto o el video.

**Tipos**

- **`DisplayLoadingOnShoot`** : Muestra el activity indicator del botón al capturar.
- **`DisableButtonOnShoot`** : Desactiva el botón al capturar.

---

### `InfoBoxConfig`

Configuración de personalización de la información desplegada durante la captura de fotos/videos.

**Parámetros**

- **`icon`** (*DigiYoImageAsset?*): Icono del cuadro de texto. Si es nulo, usa un valor predeterminado.
- **`iconColor`** (*DigiYoRGB*): Color del icono. Si es nulo, usa un valor predeterminado.
- **`borderColor`** (*DigiYoRGB*): Color del borde. Si es nulo, no se aplica.
- **`borderRadius`** (*Int?*): Radio de la esquina del cuadro. Si es nulo, no se aplica.
- **`backgroundColor`** (*DigiYoRGB?*): Color del cuadro de texto. Si es nulo, usa un valor predeterminado.
- **`contentColor`** (*DigiYoRGB?*): Color del texto. Si es nulo, usa un valor predeterminado.
- **`infoBoxStyle`** (*InfoBoxStyle*): Corresponde al layout del contenido del cuadro. Puede ser `InfoBoxStyle.Vertical` o `InfoBoxStyle.Horizontal`

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


## `Componentes de UI`

### `DocumentCameraView`

Muestra una vista (Android) o un `UIViewController` (iOS) para capturar fotos de documentos.

#### Android

```kotlin
val context = LocalContext.current
val customImage = AppCompatResources.getDrawable(context, R.drawable.vc_document_front)?.toBase64Image()
...

digiyoSdk.DocumentCameraView(
    config = DocumentCameraConfig(
        cameraTitle = "ID Card - Front",
        successAlertConfig = SuccessAlertConfig(
            title = "Next Step",
            subTitle = "Scan the back side",
            buttonTitle = "Continue",
            primaryColor = DigiYoRGB(red = 94, green = 185, blue = 240),
            imageBase64 = customImage,
            displayDefaultActivityIndicator = false,
            displayDialogAsBottomSheet = false
        ),
        documentType = DocumentType.ID_FRONT,
        colorScheme = DigiyoColorScheme.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
        ),
        showCloseButton = false,
        captureModeConfig = CaptureModeConfig(
            automaticReadingEnabled = true,
            automaticModeTimeoutMillis = 8000,
            buttonConfig = ButtonConfig(
                label = "Capturar documento",
                shape = DigiYoShape.Rounded(Dimen24dp),
                buttonStyle = DigiYoButtonStyle.Default,
                isLoading = false,
                contentPadding = 32,
                debounceIntervalMs = null,
                backgroundColor = DigiYoColorScheme.DEFAULT_COLOR_SCHEME.onSuccessColor,
                contentColor = null,
                disabledBackgroundColor = null,
                disabledContentColor = null
            ),
            buttonType = CaptureButtonType.Default,
            infoBoxConfig = null
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

digiyoSdk.getDocumentCameraViewController(
    config: DocumentCameraConfig(
        cameraTitle: "ID Card - Front",
        documentType: .idFront,
        colorScheme = DigiyoColorScheme.companion.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
        ),
        successAlertConfig: SuccessAlertConfig(
            title: "Next Step",
            subTitle: "Scan the back side",
            buttonTitle: "Continue",
            primaryColor: DigiYoRGB(red: 94, green: 185, blue: 240),
            iamgeBase64: customImage,
            displayDefaultActivityIndicator: false,
            displayDialogAsBottomSheet: false
        ),
        showCloseButton: false,
        captureModeConfig: CaptureModeConfig(
            automaticReadingEnabled: true,
            automaticModeTimeoutMillis: 8000,
            buttonConfig: ButtonConfig(
                label: "Capturar documento",
                shape: DigiYoShape.Rounded(cornerRadius: 24.0),
                buttonStyle: DigiYoButtonStyle.Default(),
                isLoading: false,
                contentPadding: 32,
                debounceIntervalMs: nil,
                backgroundColor: DigiYoColorScheme.Companion().DEFAULT_COLOR_SCHEME.onSuccessColor,
                contentColor: nil,
                disabledBackgroundColor: nil,
                disabledContentColor: nil
            ),
            buttonType: CaptureButtonType.defaultbutton,
            infoBoxConfig: nil
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

digiyoSdk.SelfieCameraView(
    config = SelfieCameraConfig(
        cameraTitle = "Selfie",
        successAlertConfig = SuccessAlertConfig(
            title = "Next Step",
            subTitle = "Record a 5-second video",
            buttonTitle = "Continue",
            primaryColor = DigiYoRGB(94, 185, 240),
            imageBase64 = customImage,
            displayDefaultActivityIndicator = false,
            displayDialogAsBottomSheet = false
        ),
        colorScheme = DigiyoColorScheme.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
        ),
        showCloseButton = false,
        captureModeConfig = CaptureModeConfig(
            automaticReadingEnabled = true,
            automaticModeTimeoutMillis = 8000,
            buttonConfig = ButtonConfig(
                label = "Capturar selfie",
                shape = DigiYoShape.Rounded(Dimen24dp),
                buttonStyle = DigiYoButtonStyle.Default,
                isLoading = false,
                contentPadding = 32,
                debounceIntervalMs = null,
                backgroundColor = DigiYoColorScheme.DEFAULT_COLOR_SCHEME.onSuccessColor,
                contentColor = null,
                disabledBackgroundColor = null,
                disabledContentColor = null
            ),
            buttonType = CaptureButtonType.Default,
            infoBoxConfig = null
        ),
        customLiveValidationsText = null
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

digiyoSdk.getSelfieCameraViewViewController(
    config: SelfieCameraConfig(
        cameraTitle: "Selfie",
        colorScheme = DigiyoColorScheme.companion.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
        ),
        successAlertConfig: SuccessAlertConfig(
            title: "Next Step",
            subTitle: "Record a 5-second video",
            buttonTitle: "Continue",
            primaryColor = DigiYoRGB(red: 94, green: 185, blue: 240),
            imageBase64: customImage,
            displayDefaultActivityIndicator: false,
            displayDialogAsBottomSheet: false
        ),
        showCloseButton: true,
        captureModeConfig: CaptureModeConfig(
            automaticReadingEnabled: true,
            automaticModeTimeoutMillis: 8000,
            buttonConfig: ButtonConfig(
                label: "Capturar selfie",
                shape: DigiYoShape.Rounded(cornerRadius: 24.0),
                buttonStyle: DigiYoButtonStyle.Default(),
                isLoading: false,
                contentPadding: 32,
                debounceIntervalMs: nil,
                backgroundColor: DigiYoColorScheme.Companion().DEFAULT_COLOR_SCHEME.onSuccessColor,
                contentColor: nil,
                disabledBackgroundColor: nil,
                disabledContentColor: nil
            ),
            buttonType: CaptureButtonType.defaultbutton,
            infoBoxConfig: nil
        ),
        customLiveValidationsText: nil
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
digiyoSdk.VideoCameraView(
    config = VideoCameraConfig(
        cameraTitle = "Show 2 fingers",
        colorScheme = DigiyoColorScheme.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
        ),
        successAlertConfig = SuccessAlertConfig(
            title = "Done",
            subTitle = "We will now analyze your video",
            buttonTitle = "OK",
            primaryColor = DigiYoRGB(94, 185, 240),
            customImage = null,
            displayDefaultActivityIndicator = false,
            displayDialogAsBottomSheet = false
        ),
        showCloseButton = false,
        errorAlertConfig = ErrorAlertConfig(
            title = "Oops!",
            subTitle = "No hand detected in the video",
            buttonTitle = "Try again",
            primaryColor = DigiYoRGB(94, 185, 240),
            displayDefaultActivityIndicator = false,
            displayDialogAsBottomSheet = false
        ),
        captureModeConfig = CaptureModeConfig(
            automaticReadingEnabled = true,
            automaticModeTimeoutMillis = 8000,
            buttonConfig = ButtonConfig(
                label = "Grabar video",
                shape = DigiYoShape.Rounded(Dimen24dp),
                buttonStyle = DigiYoButtonStyle.Default,
                isLoading = false,
                contentPadding = 32,
                debounceIntervalMs = null,
                backgroundColor = DigiYoColorScheme.DEFAULT_COLOR_SCHEME.onSuccessColor,
                contentColor = null,
                disabledBackgroundColor = null,
                disabledContentColor = null
            ),
            buttonType = CaptureButtonType.Default,
            infoBoxConfig = null
        ),
        customLiveValidationsText = null,
        cameraSoundEnabled = false
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
digiyoSdk.getVideoCameraViewViewController(
    config: VideoCameraConfig(
        cameraTitle: "Video",
        colorScheme = DigiyoColorScheme.companion.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
        ),
        successAlertConfig: SuccessAlertConfig(
            title: "Next Step",
            subTitle: "We will now analyze your video",
            buttonTitle: "Continue",
            primaryColor = DigiYoRGB(red: 94, green: 185, blue: 240),
            customImage: nil,
            displayDefaultActivityIndicator: false,
            displayDialogAsBottomSheet: false
        ),
        errorAlertConfig: ErrorAlertConfig(
            title: "Oops!",
            subTitle: "No hand detected in the video",
            buttonTitle: "Try again",
            primaryColor: DigiYoRGB(red: 94, green: 185, blue: 240),
            displayDefaultActivityIndicator: false,
            displayDialogAsBottomSheet: false
        ),
        showCloseButton: true,
        captureModeConfig: CaptureModeConfig(
            automaticReadingEnabled: true,
            automaticModeTimeoutMillis: 8000,
            buttonConfig: ButtonConfig(
                label: "Grabar video",
                shape: DigiYoShape.Rounded(cornerRadius: 24.0),
                buttonStyle: DigiYoButtonStyle.Default(),
                isLoading: false,
                contentPadding: 32,
                debounceIntervalMs: nil,
                backgroundColor: DigiYoColorScheme.Companion().DEFAULT_COLOR_SCHEME.onSuccessColor,
                contentColor: nil,
                disabledBackgroundColor: nil,
                disabledContentColor: nil
            ),
            buttonType: CaptureButtonType.defaultbutton,
            infoBoxConfig: nil
        ),
        customLiveValidationsText: nil,
        cameraSoundEnabled: false
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
...

digiyoSdk.getHelpScreenView(
    config = HelpConfig(
        helpScreenTitle = "Foto frontal de tu cédula",
        helpScreenImage = ImageAsset(context, R.drawable.vc_document_front),
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
        buttonConfig ButtonConfig.DEFAULT.copy(
            label = "Tomar selfie"
        ),
        helpScreenImageContentDescription = "Imagen de un teléfono tomando una selfie"
        ),
     onButtonPressed = {
        navController.navigate("step2")
    },
)
```

#### iOS

```swift

digiyoSdk.getHelpScreenViewViewController(
    config: HelpConfig(
        helpScreenTitle: "Foto frontal de tu cédula",
        helpScreenImage: ImageAsset("vc_document_front"),
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
        customTitleTextColor: nil,
        buttonConfig: ButtonConfig.Companion().defaultWithLabel(label: "Tomar selfie"),
        helpScreenImageContentDescription: "Imagen de un teléfono tomando una selfie"
    ),
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

digiyoSdk.getMediaPreviewScreen(
    config = MediaPreviewConfig(
        previewScreenTitle = "Verifica tu fotografía",
        previewSubtitle = "Asegurate que la foto de tu cédula frontal\nsea visible y con buena iluminación.",
        previewMediaPath = mediaPath, // Path de la imagen o el video capturado
        isMediaAVideo = true,
        colorScheme = null,
        bulletAndAdvices = null,
        primaryButtonConfig = ButtonConfig.DEFAULT.copy(
          label = "Subir foto"
        ),
        secondaryButtonConfig = ButtonConfig.SECONDARY.copy(
          label = "Volver a tomar la foto"
        ),
        customTitleTextColor = null
    ),
    onPrimaryButtonPressed = {

    },
    onSecondaryButtonPressed = {

    }
) // Ejemplo
```

#### iOS

```swift

viewModel.digiyoSdk.getMediaPreviewScreenViewController(
    config: MediaPreviewConfig(
        previewScreenTitle: "Verifica tu fotografía",
        previewSubtitle: "Asegurate que la foto de tu cédula frontal\nsea visible y con buena iluminación.",
        previewMediaPath: mediaPath, //Path de la imagen o el video capturado
        isMediaAVideo: true,
        colorScheme: nil,
        bulletAndAdvices: nil,
        primaryButtonConfig: ButtonConfig.Companion().defaultWithLabel(label: "Subir foto"),
        secondaryButtonConfig: ButtonConfig.Companion().secondaryWithLabel(label: "Volver a tomar la foto"),
        customTitleTextColor: nil
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

### `Lista de Cambios`

- #### CaptureModeConfig:
    - **`buttonConfig`** (*ButtonConfig?*): Corresponde a la configuración de personalización del botón, incluyendo el título.
    - **`buttonType`** (*CaptureButtenType?*): Corresponde al tipo de botón.
    - **`infoBoxConfig`** (*InfoBoxConfig?*): Corresponde a la configuración de personalización de la información que se despliega en la captura.
- #### DocumentCameraConfig:
  - **`showDetectedObjectRect`** (*Boolean*): Permite activar o desactivar el dibujado de un rectángulo alrededor del objeto detectado.
  - **`smartCropEnabled`** (*Boolean*): Permite activar o desactivar el recorte de la imagen usando el rectángulo detectado. Si se encuentra desactivado, la referencia es el recuadro guía presente en la pantalla de cámara.
  - **`shutterSoundEnabled`** (*Boolean*): Permite activar o desactivar el sonido del obsturador de la cámara.
- #### SelfieCameraConfig:
  - **`shutterSoundEnabled`** (*Boolean*): Permite activar o desactivar el sonido del obsturador de la cámara.
  - **`customLiveValidationsText`** (*LiveValidationsText?*): Permite personalizar el texto de los diferentes desafíos presentados para la validación de prueba de vida.
- #### VideoCameraConfig:
  - **`customLiveValidationsText`** (*LiveValidationsText?*): Permite personalizar el texto de los diferentes desafíos presentados para la validación de prueba de vida.
  - **`cameraSoundEnabled`** (*Boolean*): Permite activar o desactivar el sonido de la cámara que alerta del inicio y final de la grabación.
- #### HelpConfig:
  - **`imageShouldFollowColorScheme`** (*Boolean*): Permite manejar si la imagen agregada debe ser o no coloreada con respecto al colorScheme.
- #### SuccessAlertConfig
  - **`image`** (*DigiYoAsset?*): Permite agregar una imagen personalizada al modal. Pueden utilizarse las imagenes presentes en el SDK en ```DigiYoIcons```:
    - Android: ```DigiYoIcons.DocBackImage.getImageAsset()```
    - iOS: ```DigiYoIcons.shared.DocBackImage.getImageAsset()```

- #### SuccessAlertConfig, ErrorAlertConfig
  - **`displayDialogAsBottomSheet`** (*Boolean*): Permite manejar si el modal correspondiente debe mostrarse como un BottomSheet o como un AlertDialog.
- #### HelpConfig, SuccessAlertConfig, ErrorAlertConfig
  - **`displayDefaultActivityIndicator`** (*Boolean*): Permite la opción de mostrar u ocultar el activity indicator presente dentro de esas vistas con una condición.

---

### Proguard (Android)

A continuación se detallan las excepciones para la ofuscación de código en Proguard, en caso de que sean necesarias:

```
# Author: Guillermo Sevilla.

# :white_check_mark: Digiyo | Identia SDK
-keep class com.roshka.** { *; }

# :white_check_mark: Flutter + Plugins (No aplica para Android Nativo)
-keep class io.flutter.** { *; }
-keep class io.flutter.plugins.** { *; }

# :white_check_mark: Jetpack Compose + @Composable
-keep class androidx.compose.** { *; }
-keepclassmembers class ** {
    @androidx.compose.runtime.Composable <methods>;
}

# :white_check_mark: Kotlin coroutines y lifecycle
-keep class kotlinx.coroutines.** { *; }
-dontwarn kotlinx.coroutines.**
-keep class androidx.lifecycle.DefaultLifecycleObserver

# :white_check_mark: Google Play Core (deferred components)
-keep class com.google.android.play.** { *; }
-dontwarn com.google.android.play.**

# :white_check_mark: ML Kit y Mediapipe
-keep class com.google.mediapipe.** { *; }
-keep class com.google.mlkit.** { *; }
-keep class com.google.android.gms.tasks.** { *; }
-dontwarn com.google.**

# :white_check_mark: Conservar todos los campos (previene errores por reflexión)
-keepclassmembers class * { <fields>; }

# :white_check_mark: Silenciar warnings innecesarios
-dontwarn java.awt.**
-dontwarn javax.lang.model.**
-dontwarn javax.swing.**
-dontwarn org.slf4j.impl.**
```
