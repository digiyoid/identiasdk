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
- [getSubWorkflow](#getsubworkflow)
- [sendImage (SubWorkflow automático)](#sendimage-con-subworkflow-automático)
### [Modelo de datos](#modelo-de-datos)
- [DigiYoConfig](#digiyoconfig)
- [DiaModel](#diamodel)
- [InDataEntryModel](#indataentrymodel)
- [DataRequireModel](#datarequiremodel)
- [InDataConfigModel](#indataconfigmodel)
- [EnrollmentData](#enrollmentdata)
- [TaskModel](#taskmodel)
- [ResultModel](#resultmodel)
- [PolDetails](#poldetails)
- [DigiYoError](#digiyoerror)
- [DocumentCameraConfig](#documentcameraconfig)
- [SelfieCameraConfig](#selfiecameraconfig)
- [VideoCameraConfig](#videocameraconfig)
- [ChallengeOverlayConfig](#challengeoverlayconfig)
- [HelpConfig](#helpconfig)
- [HelpBulletpoint](#helpbulletpoint)
- [MediaPreviewConfig](#mediapreviewconfig)
- [SuccessAlertConfig](#successalertconfig)
- [ErrorAlertConfig](#erroralertconfig)
- [LiveValidationsText](#livevalidationstext)
- [VideoChallengeTexts](#videochallengetexts)
- [DigiYoRGB](#digiyorgb)
### [Personalización y estilos](#personalización-y-estilos)
- [DigiyoColorScheme](#digiyocolorscheme)
- [DigiYoImageAsset](#digiyoimageasset)
- [CaptureModeConfig](#capturemodeconfig)
- [ButtonConfig](#buttonconfig)
- [DigiYoShape](#digiyoshape)
- [DigiYoButtonStyle](#digiyobuttonstyle)
- [CaptureButtonType](#capturebuttontype)
- [CaptureButtonBehavior](#capturebuttonbehavior)
- [InfoBoxConfig](#infoboxconfig)
- [DigiYoIcons](#digiyoicons)
### [Componentes de UI](#componentes-de-ui)
- [DocumentCameraView](#documentcameraview)
- [SelfieCameraView](#selfiecameraview)
- [VideoCameraView](#videocameraview)
  - [iOS: cómo omitir los parámetros nuevos](#ios-cómo-omitir-los-parámetros-nuevos)
  - [Gate de encuadre (`requireFaceFraming`)](#gate-de-encuadre-requirefaceframing)
  - [Textos sobre la cámara (`challengeTexts`)](#textos-sobre-la-cámara-challengetexts)
  - [Texto de ayuda debajo del óvalo](#texto-de-ayuda-debajo-del-óvalo)
  - [Colores del óvalo y de la etiqueta](#colores-del-óvalo-y-de-la-etiqueta)
- [HelpScreenView](#helpscreenview)
- [MediaPreviewScreen](#mediapreviewscreen)
### Otros
- [Captura con poca luz (Android)](#captura-con-poca-luz-android)
- [Utilidades públicas del SDK](#utilidades-públicas-del-sdk)
- [Lista de Cambios](#lista-de-cambios)
- [Proguard](#proguard-android)

---

## Instalación del SDK

### Android

El SDK requiere un mínimo de **API 24**. Para instalar la librería en una aplicación Android, agrega la siguiente dependencia en el archivo `build.gradle` o `build.gradle.kts` de tu módulo App:

```groovy
implementation "com.roshka:digiyocore:1.5.1"
implementation "com.roshka:digiyo:1.5.1"
```

> Ver el historial de versiones y los cambios de cada una en [CHANGELOG.md](CHANGELOG.md).

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
                credentials {
                    username = System.getenv("GITHUB_USER") // Variable de entorno que contiene el usuario de Github
                    password = System.getenv("GITHUB_PAT") // Variable de Entorno que contiene el Personal Access Token
                }
            }
            ...
        }
    }
```

En el archivo `.bashrc` (o equivalente en MacOS, Linux u otros de tipo Unix), definir las variables de entorno de las siguiente manera:

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

### Usar una versión pre-release

De vez en cuando se publica una versión **pre-release** —por ejemplo `2.0.0-beta.1`— para poder
probar lo que viene antes de que sea estable. Se reconocen por el sufijo después del guion y en
GitHub aparecen con la etiqueta **Pre-release**, así que **no** figuran como la versión "Latest" del
repositorio.

> **No usar en producción.** Una pre-release puede cambiar de comportamiento o de firmas antes de
> la versión final, y puede volver a publicarse con el mismo número. Es para probar e informar.

Hay que **pedirla explícitamente**: ni Swift Package Manager ni un rango de Gradle la van a tomar
solas.

#### iOS (Swift Package Manager)

SPM trata todo lo que tiene sufijo como *prerelease* de versionado semántico y lo **excluye de los
rangos**: con "Up to Next Major Version" o `from:` nunca se resuelve. Hay que fijar la versión
exacta.

Desde Xcode: **File → Add Package Dependencies…**, o el paquete ya agregado en
*Package Dependencies* → click derecho → **Update Package** → y en **Dependency Rule** elegir
**Exact Version**, escribiendo la versión **sin la `v` del tag**:

```
2.0.0-beta.1
```

Desde un `Package.swift`:

```swift
dependencies: [
    .package(
        url: "https://github.com/Digiyoid/identiasdk.git",
        exact: "2.0.0-beta.1"
    )
]
```

Para volver a una estable, se cambia la regla a **Up to Next Major Version** con el número estable
(por ejemplo `1.5.6`) y se hace *Update Package*.

#### Android (Gradle / GitHub Packages)

En Gradle no existe el concepto de prerelease: alcanza con escribir la versión completa, con el
sufijo incluido.

```groovy
implementation "com.roshka:digiyocore:2.0.0-beta.1"
implementation "com.roshka:digiyo:2.0.0-beta.1"
```

> **Ojo con las versiones dinámicas.** Justamente porque Gradle no distingue prereleases, un
> `2.+` o un `latest.release` **sí** puede traerse una beta sin que te enteres. Fijá siempre la
> versión exacta.

Para volver a una estable, se cambia el número y se sincroniza el proyecto.

---

## Configuración e inicialización

Una vez inicializado con `DigiyoConfig`, en inicializaciones posteriores puedes pasar `null` (en Android) porque la configuración se almacena localmente y se recupera automáticamente.

### Android

#### Configuración

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

#### Inicialización directa de la instancia

```kotlin
//El Context es requerido para poder acceder al directorio de las fotografías y videos una vez que el flujo haya terminado.

// Instancia de DigiyoSDK
private val digiyoSdk = DigiYoSDK(context, config)
```

#### Inicialización mediante DigiYoHelper (Recomendada)

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

#### Configuración

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

#### Inicialización directa de la instancia

```swift
// Instancia del SDK
let digiyoSdk = DigiYoSDK(config: digiyoConfig)
```

#### Inicialización mediante DigiYoHelper (Recomendada)

```swift
DigiYoHelper.shared.initialize(config: digiyoConfig)

//Obtener la instancia del SDK
let digiyoSdk = DigiYoHelper.shared.sdk
```

---

## Métodos principales

### createDia

Crea un nuevo DIA (Documento de Identificación y Autenticación).

#### Android

```kotlin
digiyoSdk.createDia(
    diaType = "standard-validation-sdk",
    latitude = "-25.2865", // Opcional
    longitude = "-57.6470", // Opcional
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
digiyoSdk.createDia(
    diaType: "standard-validation-sdk",
    latitude: "-25.2865", // Opcional
    longitude: "-57.6470", // Opcional
) { dia in
    // Success
} onError: { error in
    // Error
}
```

**Parámetros**

- **`diaType`** (*String*): Tipo de DIA, por ejemplo: "standard-validation-sdk".
- **`latitude`** (*String?*): Latitud opcional para geolocalización.
- **`longitude`** (*String?*): Longitud opcional para geolocalización.
- **`onSuccess`** (*Callback*): Función invocada en caso de éxito.
- **`onError`** (*Callback*): Función invocada en caso de error.

---

### getDia

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

### cancelDia

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

### sendImage

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

### sendImageAsynchronously

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

### sendVideo

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

### sendVideoAsynchronously

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


### sendTextData

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

### sendJsonData

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

### getInData

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

### commitDia

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

### verifyTasksAndCommit

Verifica las tareas de subida de imágenes o video asíncronas y espera a que todas terminen para realizar el commit del DIA e iniciar el procesamiento en el backend.

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

### checkEnrollment

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
    }
)
```

**Parámetros**

- **`diaId`** (*String*): ID del DIA que se desea procesar.
- **`idNumber`** (*String*): El número de documento que se desea verificar.

### getSubWorkflow

Obtiene la lista de sub-flujos (workflows) asociados a un DIA. Este método realiza reintentos automáticos si el procesamiento aún no ha finalizado.

#### Android (Kotlin)

```kotlin
Digiyo.getSubWorkflow(
    diaId = digiyoSdk.getSavedDia()?.diaId ?: "",
    attemptAfterMillis = 10000, // Opcional, por defecto 10s
    attempts = 9,               // Opcional, por defecto 9 reintentos
    onSuccess = { subWorkflows ->
        // Éxito: retorna List<SubWorkflow>?
    },
    onError = { error ->
        // Error: retorna DigiYoError
    }
)
```

#### iOS (Swift)

```swift
DigiyoSDK.getSubWorkflow(
    diaId: digiyoSdk.getSavedDia()?.diaId ?? "",
    attemptAfterMillis: 10000,
    attempts: 9
) { subWorkflows in
    // Éxito: retorna [DigiyocoreSubWorkflow]?
} onError: { error in
    // Error: retorna DigiyocoreDigiYoError
}
```

**Parámetros**

- **`diaId`** (*String*): Identificador único del DIA.
- **`attemptAfterMillis`** (*Long*): Tiempo de espera entre cada intento de consulta en milisegundos.
- **`attempts`** (*Int*): Cantidad máxima de reintentos permitidos.
- **`onSuccess`** (*Callback*): Función invocada cuando se recupera exitosamente la lista de sub-flujos.
- **`onError`** (*Callback*): Función invocada en caso de error o si se agotan los intentos.

---

### sendImage (con SubWorkflow automático)

Sube una imagen y permite solicitar automáticamente el estado del flujo de trabajo (`SubWorkflow`) una vez que la carga sea exitosa.

#### Android (Kotlin)

```kotlin
Digiyo.sendImage(
    diaId = digiyoSdk.getSavedDia()?.diaId ?: "",
    filePath = "ruta/al/archivo.jpg",
    inDataName = "CI_PY_BACK",
    liveValidationOptions = null,    // Opcional
    shouldRequestWorkflow = true,    // Si es true, solicita sub-workflows tras el éxito
    onSuccess = { imageResponse, subWorkflows ->
        // Éxito: retorna respuesta de imagen y lista de sub-flujos
    },
    onError = { error ->
        // Error
    }
)
```

#### iOS (Swift)

```swift
DigiyoSDK.sendImage(
    diaId: digiyoSdk.getSavedDia()?.diaId ?? "",
    filePath: "ruta/al/archivo.jpg",
    inDataName: "CI_PY_BACK",
    liveValidationOptions: nil,
    shouldRequestWorkflow: true
) { imageResponse, subWorkflows in
    // Éxito: retorna (String?, [DigiyocoreSubWorkflow]?)
} onError: { error in
    // Error
}
```

**Parámetros**

- **`diaId`** (*String*): ID del DIA asociado.
- **`filePath`** (*String*): Ruta local de la imagen capturada.
- **`inDataName`** (*String*): Nombre del inData (ej: "CI_PY_BACK").
- **`shouldRequestWorkflow`** (*Boolean*): Determina si el SDK debe llamar internamente a `getSubWorkflow` después de subir la imagen.
- **`onSuccess`** (*Callback*): Recibe la respuesta del servidor y la lista de sub-flujos (si se solicitó).
- **`onError`** (*Callback*): Invocado en caso de error en la carga o en la consulta del flujo.

---

## Modelo de datos

A continuación se detallan los modelos de datos (objetos) utilizados por el SDK para la gestión de identidades y comunicación con el backend.

---

### DigiYoConfig
Define los parámetros de conexión y seguridad del SDK.
- **`baseUrl`** (*String*): Dirección URL de los servicios de Digiyo.
- **`apiKey`** (*String*): Token para autenticación de peticiones.
- **`enforceSslPinning`** (*Boolean*): Habilita la validación estricta de certificados SSL.
- **`requestTimeoutInMillis`** (*Long*): Tiempo máximo (ms) de espera para respuestas del servidor.

---

### DiaModel
Representa el estado completo de un proceso de Documento de Identificación y Autenticación.
- **`diaId`** (*String*): Identificador único del proceso.
- **`type`** (*String*): Nombre del flujo o workflow configurado.
- **`status`** (*String*): Estado del proceso (ej. "STARTED", "PENDING", "COMPLETED").
- **`meta`** (*MetaModel*): Información de auditoría y del socio.
- **`inDataList`** (*List<InDataEntryModel>*): Lista de todos los requisitos de datos para este flujo.

---

### InDataEntryModel
Estructura que asocia un nombre de dato con su configuración técnica.
- **`name`** (*String*): Identificador del requisito (ej. "SELFIE", "ID_CARD_FRONT").
- **`data`** (*DataRequireModel*): Detalles técnicos del requisito.

---

### DataRequireModel
Contiene los metadatos de un requisito de entrada.
- **`value`** (*String*): Valor o identificador del dato.
- **`contentType`** (*String*): Formato esperado (ej. "image/jpeg", "video/mp4").
- **`config`** (*InDataConfigModel*): Configuraciones específicas de validación.

---

### InDataConfigModel
Configuraciones avanzadas para la validación de un dato.
- **`versusArray`** (*List<Int>*): Lista de IDs de dedos requeridos para validación biométrica.
- **`liveValidations`** (*Map<String, Boolean>*): Mapa de validaciones en vivo activas (ej. sonrisa, ojos).

---

### EnrollmentData
Información sobre el registro previo de un usuario.
- **`isEnrolled`** (*Boolean*): Indica si el usuario ya está enrolado en el sistema.
- **`isAllowedToRetry`** (*Boolean*): Determina si se permite intentar el flujo nuevamente.
- **`dia`** (*DiaModel*): Datos del último proceso asociado al usuario.

---

### TaskModel
Contiene los resultados del procesamiento del backend una vez finalizado el flujo.
- **`result`** (*ResultModel*): Detalles de las puntuaciones y datos extraídos.

---

### ResultModel
Detalle técnico de los resultados obtenidos tras el análisis.
- **`scores`** (*ScoresModel*): Puntuaciones de coincidencia facial y biometría.
- **`idInfo`** (*IdInfoModel*): Información extraída del documento (OCR).
- **`polDetails`** (*PolDetails*): Detalles de pruebas de vida (ojos, sonrisa, video real).
- **`validationFlags`** (*ValidationFlags*): Indicadores de éxito de diversas validaciones internas.

---

### PolDetails
Resultados específicos de las pruebas de vida y biometría.
- **`eyeStatus`** (*String*): Estado detectado de los ojos (abiertos/cerrados).
- **`smileFound`** (*Boolean*): Si se detectó una sonrisa válida.
- **`videoIsReal`** (*Boolean*): Resultado del análisis de anti-spoofing de video.
- **`fingersRead`** (*List<Long>*): Lista de dedos detectados exitosamente.
- **`documentPhotoMatchesSelfie`** (*Boolean*): Indica si la foto del documento coincide con la selfie.

---

### DigiYoError
Objeto estandarizado para la gestión de excepciones.
- **`code`** (*String*): Código identificador del error.
- **`detail`** (*String*): Mensaje detallado sobre la falla.
- **`userVisible`** (*Boolean*): Define si el mensaje es apto para mostrarse en la UI.

---

### DocumentCameraConfig
Configuración para la captura de documentos.
- **`cameraTitle`** (*String*): Título de la pantalla de la cámara.
- **`cameraSubtitle`** (*String?*): Subtítulo opcional de la pantalla de la cámara.
- **`documentType`** (*DocumentType*): Tipo de documento a capturar.
- **`colorScheme`** (*DigiyoColorScheme?*): Configuración de colores personalizada.
- **`successAlertConfig`** (*SuccessAlertConfig?*): Configuración de la alerta de éxito.
- **`showCloseButton`** (*Boolean?*): Indica si se debe mostrar el botón de cerrar.
- **`captureModeConfig`** (*CaptureModeConfig*): Configuración del modo de captura.
- **`showDetectedObjectRect`** (*Boolean*): Activa el dibujado de un rectángulo sobre el objeto detectado.
- **`smartCropEnabled`** (*Boolean*): Habilita el recorte inteligente basado en la detección.
- **`shutterSoundEnabled`** (*Boolean*): Indica si el sonido del obturador está activado.
- **`lowLightBoostEnabled`** (*Boolean*): Mejora de captura para poca luz en **Android**: aclara la exposición y toma la foto en modo de máxima calidad. **`true` por defecto.** En iOS se ignora. Ver [Captura con poca luz (Android)](#captura-con-poca-luz-android).

---

### SelfieCameraConfig
Configuración para la captura de selfies.
- **`cameraTitle`** (*String*): Título de la pantalla de selfie.
- **`colorScheme`** (*DigiyoColorScheme?*): Configuración de colores personalizada.
- **`successAlertConfig`** (*SuccessAlertConfig?*): Configuración de la alerta de éxito.
- **`showCloseButton`** (*Boolean?*): Indica si se debe mostrar el botón de cerrar.
- **`captureModeConfig`** (*CaptureModeConfig*): Configuración del modo de captura.
- **`shutterSoundEnabled`** (*Boolean*): Indica si el sonido del obturador está activado.
- **`customLiveValidationsText`** (*LiveValidationsText?*): Textos personalizados para las validaciones en vivo.
- **`lowLightBoostEnabled`** (*Boolean*): Mejora de captura para poca luz en **Android**. **`true` por defecto.** En iOS se ignora. Ver [Captura con poca luz (Android)](#captura-con-poca-luz-android).

---

### VideoCameraConfig
Configuración para la grabación de video.
- **`cameraTitle`** (*String*): Título de la pantalla de video.
- **`colorScheme`** (*DigiyoColorScheme?*): Configuración de colores personalizada.
- **`successAlertConfig`** (*SuccessAlertConfig?*): Configuración de la alerta de éxito.
- **`errorAlertConfig`** (*ErrorAlertConfig?*): Configuración de la alerta de error.
- **`showCloseButton`** (*Boolean?*): Indica si se debe mostrar el botón de cerrar.
- **`captureModeConfig`** (*CaptureModeConfig*): Configuración del modo de captura.
- **`customLiveValidationsText`** (*LiveValidationsText?*): Textos personalizados para validaciones en vivo.
- **`cameraSoundEnabled`** (*Boolean?*): Indica si los sonidos de inicio/fin de grabación están activados.
- **`challengeOverlayConfig`** (*ChallengeOverlayConfig?*): Configuración del overlay de desafíos.
- **`videoRecordDurationMs`** (*Long?*): Duración máxima de la grabación en milisegundos.
- **`showDetectedFaceOval`** (*Boolean?*): Dibuja o no el óvalo del rostro detectado, además del óvalo guía. `null` = no se dibuja.
- **`overlayDimAlpha`** (*Float?*): Opacidad del fondo translúcido que rodea al óvalo guía, de 0 a 1. `null` = el valor por defecto del SDK.
- **`challengeTexts`** (*VideoChallengeTexts?*): Textos que el SDK dibuja sobre la cámara durante la grabación. `null` = se usan los del SDK (`VideoChallengeTexts.DEFAULT`). Ver [Textos sobre la cámara](#textos-sobre-la-cámara-challengetexts).
- **`lowLightBoostEnabled`** (*Boolean*): Mejora de captura para poca luz en **Android**. **`true` por defecto.** En iOS se ignora. Ver [Captura con poca luz (Android)](#captura-con-poca-luz-android).
- **`requireFaceFraming`** (*Boolean*): Si el encuadre del rostro en el óvalo condiciona el inicio de la grabación. **`true` por defecto.** Ver [Gate de encuadre](#gate-de-encuadre-requirefaceframing).

---

### ChallengeOverlayConfig
Configuración del overlay de desafíos en la cámara de video.
- **`delayBetweenEachFrameMs`** (*Long*): Tiempo de espera entre cuadros de desafíos.
- **`displayCountdown`** (*Boolean*): Muestra o no una cuenta regresiva.
- **`displayStepNumber`** (*Boolean*): Muestra o no el número de paso.

---

### HelpConfig
Configuración de la pantalla de ayuda o recomendaciones.
- **`helpScreenTitle`** (*String*): Título de la pantalla de ayuda.
- **`helpScreenImage`** (*DigiYoImageAsset?*): Imagen principal de la pantalla de ayuda.
- **`helpScreenComplementaryImage`** (*DigiYoImageAsset?*): Imagen complementaria opcional.
- **`helpScreenComplementaryImageHeight`** (*Double?*): Altura de la imagen complementaria.
- **`colorScheme`** (*DigiyoColorScheme?*): Configuración de colores personalizada.
- **`imageShouldFollowColorScheme`** (*Boolean*): Indica si la imagen debe teñirse con el colorScheme.
- **`bulletAndAdvices`** (*List<HelpBulletpoint>*): Lista de puntos o consejos a mostrar.
- **`customTitleTextColor`** (*DigiYoRGB?*): Color personalizado para el título.
- **`buttonConfig`** (*ButtonConfig?*): Configuración del botón de acción.
- **`helpScreenImageContentDescription`** (*String?*): Descripción de accesibilidad para la imagen principal.
- **`helpScreenComplementaryImageContentDescription`** (*String?*): Descripción de accesibilidad para la imagen complementaria.

---

### HelpBulletpoint
Representa un punto informativo o consejo en la pantalla de ayuda.
- **`icon`** (*DigiYoImageAsset*): Icono descriptivo.
- **`iconSize`** (*Double*): Tamaño del icono.
- **`iconColor`** (*DigiYoRGB?*): Color opcional para el icono.
- **`text`** (*String*): Texto descriptivo del punto.

---

### MediaPreviewConfig
Configuración de la pantalla de previsualización de medios.
- **`previewScreenTitle`** (*String*): Título de la pantalla de previsualización.
- **`previewSubtitle`** (*String?*): Subtítulo de la pantalla de previsualización.
- **`previewMediaPath`** (*String?*): Ruta del archivo multimedia a previsualizar.
- **`isMediaAVideo`** (*Boolean*): Indica si el archivo es un video.
- **`colorScheme`** (*DigiyoColorScheme?*): Configuración de colores personalizada.
- **`bulletAndAdvices`** (*List<HelpBulletpoint>?*): Lista opcional de consejos.
- **`primaryButtonConfig`** (*ButtonConfig?*): Configuración del botón principal.
- **`secondaryButtonConfig`** (*ButtonConfig?*): Configuración del botón secundario.
- **`customTitleTextColor`** (*DigiYoRGB?*): Color personalizado para el título.

---

### SuccessAlertConfig
Configuración para la alerta de éxito que aparece tras una captura correcta.
- **`title`** (*String*): Título de la alerta.
- **`subTitle`** (*String*): Subtítulo explicativo.
- **`buttonTitle`** (*String*): Texto del botón de acción.
- **`primaryColor`** (*DigiYoRGB?*): Color principal de la alerta.
- **`image`** (*DigiYoImageAsset?*): Imagen o icono a mostrar.
- **`displayDefaultActivityIndicator`** (*Boolean*): Muestra un indicador de carga por defecto.
- **`displayDialogAsBottomSheet`** (*Boolean*): Si es true, la alerta se muestra como una hoja inferior (bottom sheet).

---

### ErrorAlertConfig
Configuración para la alerta de error que aparece ante una falla en la captura o validación.
- **`title`** (*String*): Título del error.
- **`subTitle`** (*String*): Descripción detallada del error.
- **`buttonTitle`** (*String*): Texto del botón para reintentar o cerrar.
- **`primaryColor`** (*DigiYoRGB?*): Color principal de la alerta.
- **`displayDefaultActivityIndicator`** (*Boolean*): Muestra un indicador de carga por defecto.
- **`displayDialogAsBottomSheet`** (*Boolean*): Si es true, la alerta se muestra como una hoja inferior (bottom sheet).

---

### LiveValidationsText
Textos personalizados para los desafíos de biometría y pruebas de vida.
- **`lookLeftRightText`** (*String?*): Instrucción para girar la cabeza a los lados.
- **`lookUpDownText`** (*String?*): Instrucción para mover la cabeza arriba y abajo.
- **`openCloseMouthText`** (*String?*): Instrucción para abrir y cerrar la boca.
- **`faceEyeCheckText`** (*String?*): Instrucción para parpadear.
- **`faceSmileCheckText`** (*String?*): Instrucción para sonreír.
- **`idOnFaceCheckText`** (*String?*): Instrucción para mostrar el documento junto al rostro.
- **`fingerCheckText`** (*String?*): Instrucción para mostrar una cantidad específica de dedos.

---

### VideoChallengeTexts
Textos que el SDK dibuja **sobre la cámara** durante la grabación de video. Se pasa en
`VideoCameraConfig.challengeTexts`; en `null` se usan los valores por defecto del SDK
(`VideoChallengeTexts.DEFAULT`). Ver [Textos sobre la cámara](#textos-sobre-la-cámara-challengetexts).

- **`ovalLabelText`** (*String?*): Etiqueta encima del óvalo, p. ej. `"ALÉJESE"`. Solo se dibuja con `VideoCameraConfig.requireFaceFraming = true`, y en `null` se usa `"ALÉJESE"`. Para ocultarla, `requireFaceFraming = false`.
- **`fingerRecordingText`** (*String?*): Texto durante la grabación en el desafío de dedos (`versus_array`). El `%d` se reemplaza por la cantidad de dedos del array.
- **`depthRecordingText`** (*String?*): Texto durante la grabación en el desafío 3D / profundidad (`pol_depth`).
- **`lookLeftRightRecordingText`** (*String?*): `live_validations.look_left_right`.
- **`lookUpDownRecordingText`** (*String?*): `live_validations.look_up_down`.
- **`openCloseMouthRecordingText`** (*String?*): `live_validations.open_close_mouth`.
- **`faceEyeCheckRecordingText`** (*String?*): `live_validations.face_eye_check`.
- **`faceSmileCheckRecordingText`** (*String?*): `live_validations.face_smile_check`.
- **`idOnFaceCheckRecordingText`** (*String?*): `live_validations.id_on_face_check`.

Todos los textos de grabación están **vacíos por defecto**: si la app no define uno, el SDK
no dibuja ningún mensaje mientras se graba.

---

### DigiYoRGB
Representación de colores en formato RGB.
- **`red`** (*Int*): Componente rojo (0-255).
- **`green`** (*Int*): Componente verde (0-255).
- **`blue`** (*Int*): Componente azul (0-255).

---

## Personalización y estilos

### DigiyoColorScheme

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

### DigiYoImageAsset

Es una interfaz que contiene los métodos para interactuar con las imágenes provenientes de ambas plataformas.
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

### CaptureModeConfig

Configuración del modo de captura de: DocumentCameraView, SelfieCameraView y VideoCameraView

| Campo | Tipo | Para qué sirve | Por defecto |
|---|---|---|---|
| `automaticReadingEnabled` | `Boolean` | `true`: la grabación arranca sola en cuanto el rostro queda encuadrado en el óvalo y **el botón nunca se muestra**. `false`: el botón se muestra siempre, deshabilitado hasta que el rostro queda encuadrado. | obligatorio |
| `automaticModeTimeoutMillis` | `Long?` | Solo en modo automático: pasado ese tiempo sin lograr el encuadre, se desactiva el modo automático y aparece el botón manual. `null` = sin timeout. | `null` |
| `cameraButtonConfig` | `ButtonConfig?` | Apariencia del botón (ver tabla siguiente). | `null` → etiqueta `"Capturar"` con `colorScheme.secondary` de fondo |
| `buttonType` | `CaptureButtonType` | `DefaultButton` (botón ancho con texto), `ShutterButtonType1` o `ShutterButtonType2` (botones tipo disparador, circulares, ignoran `label`). | `DefaultButton` |
| `buttonBehavior` | `CaptureButtonBehavior?` | `DisableButtonOnShoot`: al disparar, el botón se deshabilita. `DisplayLoadingOnShoot`: muestra un spinner en su lugar. | `DisableButtonOnShoot` |
| `infoBoxConfig` | `InfoBoxConfig?` | Caja de ayuda debajo del óvalo (icono, colores, borde, estilo). `null` = la del SDK, que colorea el texto según el estado de la detección. | `null` |
| `overwriteDefaultTextWith` | `String?` | Texto de ayuda de la caja debajo del óvalo. Admite `%d`, que se sustituye por la cantidad de dedos de `versus_array`. **`null` equivale a `""`: no se muestra ningún texto** (no se cae a un texto por defecto del SDK). | `null` → sin texto |

#### Android

```kotlin
digiyoSdk.getDocumentCameraView(
    config = DocumentCameraConfig(
       ...
        captureModeConfig = CaptureModeConfig(
            automaticReadingEnabled = true,
            automaticModeTimeoutMillis = 8000,
            cameraButtonConfig = ButtonConfig(
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
            buttonType = CaptureButtonType.DefaultButton,
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
            cameraButtonConfig: ButtonConfig(
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
- **`automaticModeTimeoutMillis`** (*Long?*): Si no es nulo, define el tiempo en milisegundos en que la captura automática estará activada antes de pasar a modo manual.
- **`cameraButtonConfig`** (*ButtonConfig?*): Corresponde a la configuración de personalización del botón, incluyendo el título.
- **`buttonType`** (*CaptureButtonType?*): Corresponde al tipo de botón.
- **`buttonBehavior`** (*CaptureButtonBehavior?*): Corresponde al comportamiento del botón al capturar la foto o el video. Por defecto, el botón queda desactivado.
- **`infoBoxConfig`** (*InfoBoxConfig?*): Corresponde a la configuración de personalización de la información que se despliega en la captura.
- **`overwriteDefaultTextWith`** (String?): Permite reemplazar el texto por defecto del infoBox. (Si existen validaciones activas, el texto de las validaciones tienen prioridad, por lo que deben de personalizarse desde `customLiveValidationsText` en la configuración correspondiente)

---

### ButtonConfig

Configuración de personalización de botones.

| Campo | Tipo | Para qué sirve | Por defecto |
|---|---|---|---|
| `label` | `String` | Texto del botón, p. ej. `"Grabar video"`. Se ignora con los `buttonType` de tipo disparador. | obligatorio |
| `shape` | `DigiYoShape` | `Rounded(cornerRadius)`, `Outlined(cornerRadius)` (dibuja además un borde), `Circle` o `Square`. El radio va en dp. | `Rounded(24.0)` |
| `buttonStyle` | `DigiYoButtonStyle` | `Default` (texto centrado), `TextOnlyStart`, `TextOnlyEnd`, `TextWithIconSpaceBetween(icon)`, `TextWithIconCentered(icon)`. | `Default` |
| `isLoading` | `Boolean` | Fuerza el estado de carga (spinner en lugar del texto). Normalmente se deja en `false` y lo maneja `buttonBehavior`. | `false` |
| `contentPadding` | `Int` | Padding horizontal interno, en dp. | `0` (los presets del SDK usan `32`) |
| `debounceIntervalMs` | `Long?` | Tiempo mínimo entre pulsaciones, para evitar dobles disparos. | `2000` |
| `backgroundColor` | `DigiYoRGB` | Color de fondo del botón habilitado. | obligatorio |
| `contentColor` | `DigiYoRGB?` | Color del texto. `null` = se calcula automáticamente por contraste con el fondo. | `null` |
| `disabledBackgroundColor` | `DigiYoRGB?` | Fondo con el botón deshabilitado, o sea mientras el rostro no está encuadrado. `null` = gris. | `null` |
| `disabledContentColor` | `DigiYoRGB?` | Texto con el botón deshabilitado. `null` = gris translúcido. | `null` |

Atajos útiles: `ButtonConfig.DEFAULT`, `ButtonConfig.SECONDARY`, `ButtonConfig.SHUTTER`, y `ButtonConfig.defaultWithLabel("...")` / `secondaryWithLabel("...")`.

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

### DigiYoShape

Forma del botón a personalizar.

**Tipos**

- **`Circle`** : Círculo.
- **`Rounded(cornerRadius: Float | Dp)`** : Rectángulo con esquinas redondeadas. Recibe el radio de la esquina como parámetro.
- **`Square`** : Rectángulo.

---

### DigiYoButtonStyle

Estilo del botón a personalizar.

**Tipos**

- **`Default`** : Text centrado.
- **`TextOnlyStart`** : Texto alineado a la izquierda.
- **`TextOnlyEnd`** : Texto alineado a la derecha.
- **`TextWithIconSpaceBetween`** : Texto alineado a la izquierda con icono. Recibe un DigiYoImageAsset como parámetro.
- **`TextWithIconCentered`** : Texto con icono, centrados. Recibe un DigiYoImageAsset como parámetro.

---

### CaptureButtonType

Tipo de botón. Tiene prioridad sobre el estilo del botón.

**Tipos**

- **`DefaultButton`** : Botón normal.
- **`ShutterButtonType1`** : Botón tipo shutter.
- **`ShutterButtonType2`** : Botón tipo shutter (estilo alternativo).

---

### CaptureButtonBehavior

Comportamiento del botón al tomar la foto o el video.

**Tipos**

- **`DisplayLoadingOnShoot`** : Muestra el activity indicator del botón al capturar.
- **`DisableButtonOnShoot`** : Desactiva el botón al capturar.

---

### InfoBoxConfig

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

### DigiYoIcons

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


## Componentes de UI

### DocumentCameraView

Muestra una vista (Android) o un `UIViewController` (iOS) para capturar fotos de documentos.

#### Android

```kotlin
val context = LocalContext.current
...

digiyoSdk.getDocumentCameraView(
    config = DocumentCameraConfig(
        cameraTitle = "ID Card - Front",
        cameraSubtitle = "Scan the front side of your ID Card",
        successAlertConfig = SuccessAlertConfig(
            title = "Next Step",
            subTitle = "Scan the back side",
            buttonTitle = "Continue",
            primaryColor = DigiYoRGB(red = 94, green = 185, blue = 240),
            image = ImageAsset(context, R.drawable.vc_document_front),
            displayDefaultActivityIndicator = false,
            displayDialogAsBottomSheet = false
        ),
        documentType = DocumentType.ID_FRONT,
        colorScheme = DigiyoColorScheme.fromPrimaryColor(
            DigiYoRGB(red = 94, green = 240, blue = 160)
        ),
        showCloseButton = false,
        captureModeConfig = CaptureModeConfig(
            automaticReadingEnabled = true,
            automaticModeTimeoutMillis = 8000,
            cameraButtonConfig = ButtonConfig(
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
            buttonType = CaptureButtonType.DefaultButton,
            infoBoxConfig = null
        ),
        showDetectedObjectRect = true,
        smartCropEnabled = false,
        shutterSoundEnabled = true
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
...

digiyoSdk.getDocumentCameraViewController(
    config: DocumentCameraConfig(
        cameraTitle: "ID Card - Front",
        cameraSubtitle: "Scan the front side of your ID Card",
        documentType: .idFront,
        colorScheme = DigiyoColorScheme.companion.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
        ),
        successAlertConfig: SuccessAlertConfig(
            title: "Next Step",
            subTitle: "Scan the back side",
            buttonTitle: "Continue",
            primaryColor: DigiYoRGB(red: 94, green: 185, blue: 240),
            image: ImageAsset("vc_document_front"),
            displayDefaultActivityIndicator: false,
            displayDialogAsBottomSheet: false
        ),
        showCloseButton: false,
        captureModeConfig: CaptureModeConfig(
            automaticReadingEnabled: true,
            automaticModeTimeoutMillis: 8000,
            cameraButtonConfig: ButtonConfig(
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
        smartCropEnabled: false,
        shutterSoundEnabled: true
    ),
    onResult = { imageCropped, imageFull in
        viewModel.sendImage(filePath: imageCropped, imageFullPath: imageFull)
    },
    onClose: {
        self.presentationMode.wrappedValue.dismiss()
    }
)
```
```

**Parámetros**

- **`config`** (*DocumentCameraConfig*): Configuración de la cámara.
- **`onResult`** (*Callback*): Retorna las rutas de las imágenes capturadas. **Se invoca una sola
  vez por pantalla**: desde la 1.5.6 la primera captura que se procesa gana y las demás se
  descartan. Antes, en Android, una secuencia rápida de encuadre válido → inválido → válido podía
  disparar dos capturas e invocarlo dos veces.
- **`onClose`** (*Callback*): Se invoca al cerrar la cámara.

**Qué pasa si la cámara del equipo no responde (Android).** Hay dispositivos donde la petición de
foto queda sin respuesta: el HAL no devuelve ni la imagen ni un error. Desde la **1.5.6** el SDK no
se queda esperando indefinidamente —antes la pantalla quedaba con el marco en el color de validado y
el usuario tenía que cerrarla—: espera 4 segundos, reintenta una vez y, si tampoco hay respuesta,
entrega una captura de menor calidad tomada del preview antes que dejar el flujo trabado. Toda la
escalada queda registrada en el log del SDK (tag `digiyo`), así que si aparece se puede identificar
el equipo. **La app no tiene que hacer nada**: `onResult` llega igual.

---

### SelfieCameraView

Muestra una vista (Android) o un `UIViewController` (iOS) para capturar selfies con la cámara frontal.

#### Android

```kotlin
val context = LocalContext.current
...

digiyoSdk.getSelfieCameraView(
    config = SelfieCameraConfig(
        cameraTitle = "Selfie",
        successAlertConfig = SuccessAlertConfig(
            title = "Next Step",
            subTitle = "Record a 5-second video",
            buttonTitle = "Continue",
            primaryColor = DigiYoRGB(94, 185, 240),
            image = ImageAsset(context, R.drawable.vc_document_front),
            displayDefaultActivityIndicator = false,
            displayDialogAsBottomSheet = false
        ),
        colorScheme = DigiyoColorScheme.fromPrimaryColor(
            DigiYoRGB(red = 94, green = 240, blue = 160)
        ),
        showCloseButton = false,
        captureModeConfig = CaptureModeConfig(
            automaticReadingEnabled = true,
            automaticModeTimeoutMillis = 8000,
            cameraButtonConfig = ButtonConfig(
                label = "Capturar selfie",
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
            buttonType = CaptureButtonType.DefaultButton,
            infoBoxConfig = null
        ),
        shutterSoundEnabled = true,
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
            primaryColor: DigiYoRGB(red: 94, green: 185, blue: 240),
            image: ImageAsset("vc_document_front"),
            displayDefaultActivityIndicator: false,
            displayDialogAsBottomSheet: false
        ),
        showCloseButton: true,
        captureModeConfig: CaptureModeConfig(
            automaticReadingEnabled: true,
            automaticModeTimeoutMillis: 8000,
            cameraButtonConfig: ButtonConfig(
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
        shutterSoundEnabled: true,
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

### VideoCameraView

Muestra una vista (Android) o un `UIViewController` (iOS) para grabar videos.

#### Android

```kotlin
digiyoSdk.getVideoCameraView(
    config = VideoCameraConfig(
        cameraTitle = "Show 2 fingers",
        colorScheme = DigiyoColorScheme.fromPrimaryColor(
            DigiYoRGB(red = 94, green = 240, blue = 160)
        ),
        successAlertConfig = SuccessAlertConfig(
            title = "Done",
            subTitle = "We will now analyze your video",
            buttonTitle = "OK",
            primaryColor = DigiYoRGB(94, 185, 240),
            image = null,
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
            cameraButtonConfig = ButtonConfig(
                label = "Grabar video",
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
            buttonType = CaptureButtonType.DefaultButton,
            infoBoxConfig = null
        ),
        customLiveValidationsText = null,
        cameraSoundEnabled = false,
        challengeOverlayConfig = ChallengeOverlayConfig.DEFAULT,
        videoRecordDurationMs = 5000L
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
        colorScheme: DigiyoColorScheme.companion.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
        ),
        successAlertConfig: SuccessAlertConfig(
            title: "Next Step",
            subTitle: "We will now analyze your video",
            buttonTitle: "Continue",
            primaryColor: DigiYoRGB(red: 94, green: 185, blue: 240),
            image: nil,
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
            cameraButtonConfig: ButtonConfig(
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
        cameraSoundEnabled: false,
        challengeOverlayConfig: ChallengeOverlayConfig.Companion().DEFAULT,
        videoRecordDurationMs: 5000
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

#### iOS: cómo omitir los parámetros nuevos

Kotlin exporta sus valores por defecto **solo a Kotlin**. En la interfaz Objective-C que consume
Swift no existen, así que el `init` primario de `VideoCameraConfig` exige **todos** sus
parámetros: cualquier llamada que no los enumere falla con *"Missing argument for parameter"*.

Para que las apps iOS puedan omitirlos, el SDK expone un `init` por cada **prefijo** de la firma.
Hoy son estos:

| Último parámetro de la llamada | Qué valores se asumen |
|---|---|
| `videoRecordDurationMs` | `showDetectedFaceOval` y `overlayDimAlpha` en `nil`, `challengeTexts` en `nil`, `lowLightBoostEnabled = true`, `requireFaceFraming = true` |
| `showDetectedFaceOval` | idem, desde `overlayDimAlpha` |
| `overlayDimAlpha` | idem, desde `challengeTexts` |
| `challengeTexts` | `lowLightBoostEnabled = true` y `requireFaceFraming = true` |
| `lowLightBoostEnabled` | `requireFaceFraming = true` |
| `requireFaceFraming` | ninguno: es la firma completa |

**Solo se puede omitir un sufijo, no parámetros sueltos.** Es decir, se puede pasar hasta
`lowLightBoostEnabled` y dejar afuera `requireFaceFraming`, pero **no** al revés: para llegar a
`requireFaceFraming` hay que enumerar también `lowLightBoostEnabled` —aunque en iOS ese parámetro
se ignore— porque no existe un `init` que salte uno del medio.

> **Por qué no se puede agregar ese `init` intermedio:** un constructor que termine en
> `requireFaceFraming: Boolean` tendría, del lado de Kotlin, la misma firma que el que termina en
> `lowLightBoostEnabled: Boolean` —misma cantidad de parámetros y mismos tipos— y el compilador lo
> rechaza por *conflicting overloads*. En Objective-C serían selectores distintos, porque incluyen
> los nombres, pero el choque ocurre antes.

Lo mismo aplica a `DocumentCameraConfig` y `SelfieCameraConfig`, que exponen su firma de la 1.5.x
y la que agrega `lowLightBoostEnabled`.

#### Gate de encuadre (`requireFaceFraming`)

Por defecto el SDK **exige que el rostro esté bien encuadrado en el óvalo antes de dejar grabar**:
en modo manual el botón está deshabilitado hasta ese momento, y en modo automático la grabación
arranca recién ahí. Ese es el instante en que el óvalo y su etiqueta desaparecen.

`VideoCameraConfig.requireFaceFraming = false` desactiva ese condicionamiento:

| | `true` (por defecto) | `false` |
|---|---|---|
| `automaticReadingEnabled = false` | El botón se habilita al quedar el rostro encuadrado | El botón está habilitado desde el arranque; el usuario decide cuándo |
| `automaticReadingEnabled = true` | La grabación arranca al quedar el rostro encuadrado | La grabación arranca en cuanto se detecta un rostro, **a cualquier distancia** |
| Óvalo | Se muestra y desaparece según el encuadre | Se sigue mostrando como guía visual, pero no condiciona nada |
| Etiqueta del óvalo ("ALÉJESE") | Se muestra siempre: el texto de la app o, si no lo definió, el del SDK | **No se dibuja**: si el encuadre no condiciona nada, pedir que se aleje no sirve |

Con `false` el óvalo sigue apareciendo porque orienta al usuario, pero la etiqueta **no**: el SDK
la omite. Y al revés, con `true` la etiqueta se muestra siempre, incluso si la app no pasa
`challengeTexts` o lo pasa con `ovalLabelText = null`; en ese caso se usa el texto del SDK
("ALÉJESE"). **La forma de ocultar la etiqueta es `requireFaceFraming = false`.**

**No aplica al desafío de profundidad (`pol_depth`).** El gate y la etiqueta son parte del diseño
del **óvalo guía fijo**, es decir de los DIA cuyo `in_data.POL_VIDEO.config` trae `versus_array` o
`live_validations`. En profundidad el condicionamiento lo manda la fase: el botón se habilita cuando
el rostro entra en el óvalo grande, y las etiquetas **ACÉRQUESE** / **ALÉJESE** las decide el
desafío, no la app. Ahí `requireFaceFraming` y `challengeTexts.ovalLabelText` se ignoran.

**Para qué sirve.** Hay equipos cuya cámara frontal tiene un campo visual angosto —el rostro ocupa
más del encuadre a la misma distancia física— y el usuario no llega a alejarse lo suficiente: el
gate lo deja trabado sin poder grabar. Un iPhone XR es el caso de referencia. Poniendo el
parámetro en `false` el flujo no se bloquea.

```kotlin
// Android
VideoCameraConfig(
    // ...
    requireFaceFraming = false,   // por defecto true
)
```

```swift
// iOS: como el init de Kotlin no exporta valores por defecto, o se pasa el parámetro
// en la firma completa, o se usa uno de los init de compatibilidad (que dejan true).
```

#### Textos sobre la cámara (`challengeTexts`)

Durante la grabación el SDK dibuja dos textos sobre la cámara, y ambos son parametrizables desde la app (igual que `CaptureModeConfig.overwriteDefaultTextWith`) a través de `VideoCameraConfig.challengeTexts`:

| Texto | Cuándo se muestra | Estilo |
|---|---|---|
| `ovalLabelText` | Encima del óvalo, mientras el rostro todavía **no** está bien encuadrado. Desaparece junto con el óvalo, es decir cuando el rostro queda validado (y, en modo manual, cuando se habilita el botón de grabar). **Solo con `requireFaceFraming = true`**; en `null` se usa `"ALÉJESE"`. | Letras blancas ExtraBold sobre un fondo de color con esquinas redondeadas. El fondo se configura con `colorScheme.successColor` (`VideoCameraConfig.colorScheme`), el mismo color al que cambia el marco del óvalo cuando el rostro queda encuadrado. |
| Texto de grabación | Mientras se está grabando. Cuál se usa depende del desafío que devolvió `createDia` en `in_data.POL_VIDEO.config`. | Blanco, negritas |

Los textos de grabación se eligen así, a partir de `in_data.POL_VIDEO.config`:

| Campo de `challengeTexts` | Se usa cuando `in_data.POL_VIDEO.config` trae |
|---|---|
| `fingerRecordingText` | `versus_array` (desafío de dedos). El `%d` se reemplaza por la cantidad de dedos del array: con `"Levantá %d dedos"` y `versus_array = [2]` se muestra "Levantá 2 dedos". |
| `depthRecordingText` | `pol_depth` (desafío 3D / profundidad) |
| `lookLeftRightRecordingText` | `live_validations.look_left_right` |
| `lookUpDownRecordingText` | `live_validations.look_up_down` |
| `openCloseMouthRecordingText` | `live_validations.open_close_mouth` |
| `faceEyeCheckRecordingText` | `live_validations.face_eye_check` |
| `faceSmileCheckRecordingText` | `live_validations.face_smile_check` |
| `idOnFaceCheckRecordingText` | `live_validations.id_on_face_check` |

#### Valores por defecto

Si no se pasa `challengeTexts`, el SDK usa `VideoChallengeTexts.DEFAULT`, que es:

| Texto | Valor por defecto |
|---|---|
| `ovalLabelText` | `"ALÉJESE"` |
| Todos los textos de grabación | **vacíos** |

Es decir, **el SDK no impone ningún mensaje durante la grabación**: si la app no define un
texto, no se dibuja nada. Es el mismo criterio que `CaptureModeConfig.overwriteDefaultTextWith`
en `null`. La app que quiera mostrar una instrucción la define explícitamente:

```kotlin
challengeTexts = VideoChallengeTexts(
    fingerRecordingText = "Levantá %d dedos",   // ovalLabelText mantiene "ALÉJESE"
)
```

Cualquier **texto de grabación** en `null` o vacío hace que no se muestre. `ovalLabelText` es la
excepción: con `requireFaceFraming = true`, en `null` se cae al `"ALÉJESE"` del SDK, y para
ocultar la etiqueta hay que usar `requireFaceFraming = false`.

##### Android

```kotlin
VideoCameraConfig(
    // ...
    challengeTexts = VideoChallengeTexts(
        ovalLabelText = "ALÉJESE",
        fingerRecordingText = "Levantá %d dedos",
    ),
)
```

##### iOS

En Swift los parámetros de Kotlin no tienen valores por defecto, así que hay que pasarlos todos (o pasar `challengeTexts: nil` para usar los del SDK):

```swift
VideoCameraConfig(
    // ...
    challengeTexts: VideoChallengeTexts(
        ovalLabelText: "ALÉJESE",
        fingerRecordingText: "Levantá %d dedos",
        depthRecordingText: nil,
        lookLeftRightRecordingText: nil,
        lookUpDownRecordingText: nil,
        openCloseMouthRecordingText: nil,
        faceEyeCheckRecordingText: nil,
        faceSmileCheckRecordingText: nil,
        idOnFaceCheckRecordingText: nil
    )
)
```

#### Texto de ayuda debajo del óvalo

El texto de la caja de ayuda se resuelve en el core con `utils.resolveVideoHelpText`, con esta precedencia:

1. `VideoCameraConfig.customLiveValidationsText` (el texto de la validación activa), si viene.
2. `captureModeConfig.overwriteDefaultTextWith`.
3. Nada.

Es decir, **si los dos vienen en `null` no se dibuja ninguna caja de ayuda**: dejar `overwriteDefaultTextWith` en `null` / `nil` es equivalente a pasar `""`. El SDK no impone un texto propio. El `%d` del texto elegido se reemplaza por la cantidad de dedos de `in_data.POL_VIDEO.config.versus_array` (2 si no viene), y ese número se resalta en negrita.

La caja acompaña al óvalo: se muestra mientras el rostro no está encuadrado y desaparece junto con el óvalo cuando lo está.

#### Colores del óvalo y de la etiqueta

Los colores de la pantalla de grabación no se configuran con parámetros propios: salen del `DigiYoColorScheme` que se pasa en `VideoCameraConfig.colorScheme`. Si se deja en `null` se usa `DigiYoColorScheme.DEFAULT_COLOR_SCHEME`.

| Elemento | Campo del `colorScheme` | Valor por defecto |
|---|---|---|
| Marco del óvalo mientras se busca el rostro (`NOTHING` / `NO_CENTER`) | `accentColor` | `0xE2EBF7` |
| Marco del óvalo con el rostro encuadrado (`VALID`) | `successColor` | `DigiYoRGB(94, 240, 160)` |
| Fondo de la etiqueta sobre el óvalo (`ovalLabelText`, p. ej. "ALÉJESE") | `successColor` | `DigiYoRGB(94, 240, 160)` |
| Texto del `InfoBox` de ayuda | `successColor` / `accentColor` según el estado | — |

En la práctica el marco del óvalo se ve con `accentColor`: al quedar el rostro encuadrado el óvalo desaparece junto con el fondo translúcido. El fondo de la etiqueta usa `successColor` de forma **fija** (en el desafío de profundidad cambiaba al detectar el rostro; acá no), y sus letras son siempre blancas y ExtraBold.

##### Android

```kotlin
VideoCameraConfig(
    // ...
    colorScheme = DigiYoColorScheme.DEFAULT_COLOR_SCHEME.copy(
        accentColor = DigiYoRGB(226, 235, 247),  // marco del óvalo
        successColor = DigiYoRGB(94, 240, 160)   // fondo de "ALÉJESE" y marco al encuadrar
    ),
)
```

##### iOS

En Swift el init de `DigiYoColorScheme` exige **los 7 campos**, en el orden en que están declarados: pasar solo el que interesa no compila. Los que no se quieran cambiar se copian de `DEFAULT_COLOR_SCHEME` (`0x2C365B`, `0x3DA9E0`, `0xE2EBF7`) o se dejan en `nil`, que hace que el SDK use su fallback. `copy` tampoco ayuda: Kotlin lo exporta como `doCopy(...)` y también pide los 7 argumentos.

```swift
VideoCameraConfig(
    // ...
    colorScheme: DigiYoColorScheme(
        primaryColor: DigiYoRGB(red: 44, green: 54, blue: 91),
        secondaryColor: DigiYoRGB(red: 61, green: 169, blue: 224),
        accentColor: DigiYoRGB(red: 226, green: 235, blue: 247),  // marco del óvalo
        primaryTextColor: nil,
        secondaryTextColor: nil,
        errorColor: nil,
        successColor: DigiYoRGB(red: 94, green: 240, blue: 160)   // fondo de "ALÉJESE"
    ),
)
```

Ojo: ese mismo `colorScheme` alimenta el resto del overlay. `secondaryColor` es el fondo del botón de grabar **solo si** no se pasa `captureModeConfig.cameraButtonConfig`; si se pasa, el botón usa su propio `backgroundColor` y es independiente de la etiqueta.

---

### HelpScreenView

Muestra una vista (Android) o un `UIViewController` (iOS) que puede ser utilizado para desplegar recomendaciones a lo largo del flujo.

#### Android

```kotlin
val context = LocalContext.current
...

digiyoSdk.getHelpScreenView(
    config = HelpConfig(
        helpScreenTitle = "Foto frontal de tu cédula",
        helpScreenImage = ImageAsset(context, R.drawable.vc_document_front),
        helpScreenComplementaryImage = null,
        helpScreenComplementaryImageHeight = null,
        colorScheme =  DigiYoColorScheme.fromPrimaryColor(
            DigiYoRGB(red = 94, green = 240, blue = 160)
        ),
        imageShouldFollowColorScheme = false,
        bulletAndAdvices = listOf(
            HelpBulletpoint(
                icon = ImageAsset(context, R.drawable.ic_check),
                text = "Foto legible, bien iluminada."
            ),
            HelpBulletpoint(
                icon = ImageAsset(context, R.drawable.ic_check),
                text = "Coloca tu CI en una superficie plana y de un solo color."
            ),
            HelpBulletpoint(
                icon = ImageAsset(context, R.drawable.ic_check),
                text = "Pon el teléfono cerca para que tu rostro y número de CI se vean con claridad."
            ),
            HelpBulletpoint(
                icon = ImageAsset(context, R.drawable.ic_error),
                iconColor = DigiYoRGB(255, 0, 0),
                text = "No envíes CI editadas o caducadas."
            ),
        ),
        customTitleTextColor = null,
        buttonConfig = ButtonConfig.DEFAULT.copy(
            label = "Escanear documento"
        ),
        helpScreenImageContentDescription = "Imagen de un teléfono tomando una selfie",
        helpScreenComplementaryImageContentDescription = null
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
        helpScreenComplementaryImage: nil,
        helpScreenComplementaryImageHeight: nil,
        colorScheme: DigiYoColorScheme.companion.fromPrimaryColor(
            DigiYoRGB(red: 94, green: 240, blue: 160)
        ),
        imageShouldFollowColorScheme: false,
        bulletAndAdvices: [
            HelpBulletpoint(icon: ImageAsset("ic_check"), text: "Foto legible, bien iluminada."),
            HelpBulletpoint(icon: ImageAsset("ic_check"), text: "Coloca tu CI en una superficie plana y de un solo color."),
            HelpBulletpoint(icon: ImageAsset("ic_check"), text: "Pon el teléfono cerca para que tu rostro y número de CI se vean con claridad."),
            HelpBulletpoint(icon: ImageAsset("ic_error"), iconColor: DigiYoRGB(red: 255, green: 0, blue: 0), text: "No envíes CI editadas o caducadas.")
        ],
        customTitleTextColor: nil,
        buttonConfig: ButtonConfig.Companion().defaultWithLabel(label: "Escanear documento"),
        helpScreenImageContentDescription: "Imagen de un teléfono tomando una selfie",
        helpScreenComplementaryImageContentDescription: nil
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

### MediaPreviewScreen

Muestra una vista (Android) o un `UIViewController` (iOS) que puede ser utilizado para previsualizar las imágenes o videos capturados antes de su envío.

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

### Captura con poca luz (Android)

En **Android** el SDK aplica una mejora de captura pensada para ambientes con poca
luz y para equipos de gama baja, donde la cédula salía oscura o borrosa (el caso de
referencia fue un Samsung A04):

- Sube la compensación de exposición de la cámara (AE bias): **+1.5 EV** en la trasera
  (documentos) y **+3.0 EV** en la delantera (selfie y video). En la delantera es más fuerte
  porque la exposición es la única palanca disponible: el video no usa `ImageCapture`, así
  que no hay modo "calidad" que ayude. El valor se acota siempre al rango que soporta el
  equipo, y si el dispositivo no soporta compensación de exposición se ignora sin error.
- En la captura de fotos usa el modo de **máxima calidad** en lugar del de mínima latencia
  (más procesamiento y reducción de ruido del fabricante).

**Activada por defecto y configurable en las tres cámaras.** Se controla con
`lowLightBoostEnabled`, presente en `DocumentCameraConfig`, `SelfieCameraConfig` y
`VideoCameraConfig`, y vale `true` si no se pasa nada: así, actualizar el SDK no cambia el
comportamiento de ninguna app. Pasar `false` la desactiva —la captura se hace con latencia mínima
y sin corrección de exposición—, algo útil para comparar capturas en un dispositivo puntual.

```kotlin
DocumentCameraConfig(
    // ...
    shutterSoundEnabled = false,
    lowLightBoostEnabled = false,   // por defecto true
)
```

Solo afecta el brillo de la imagen; no toca la geometría del rostro, así que la detección y el
liveness del óvalo se comportan igual.

En **iOS el parámetro se ignora**, porque la implementación es específica de CameraX. Las apps
iOS **no necesitan tocar nada**: las tres configuraciones conservan sus constructores anteriores,
así que siguen compilando y comportándose igual (ver la nota de compatibilidad).

---

### Utilidades públicas del SDK

Además de las vistas, el SDK expone las funciones con las que resuelve internamente el encuadre
del rostro y el texto de ayuda. Sirven si la app necesita replicar exactamente el mismo criterio
en una interfaz propia:

| Función | Para qué sirve |
|---|---|
| `utils.guideOvalRect(viewWidthPx, viewHeightPx, verticalOffsetPx)` | Geometría del óvalo guía de la grabación de video. Es la única fórmula del óvalo: la usan tanto la vista de cada plataforma —que valida el rostro contra él— como el overlay que lo dibuja. |
| `utils.evaluateFaceOvalFraming(ovalBounds, faceBounds, maxWidthFactor)` | Criterio de encuadre del rostro. Devuelve un `FaceOvalFraming` con `insideOval`, `fitsOval` y la propiedad derivada `isFramed`. `maxWidthFactor` afloja el umbral de tamaño para compensar el campo visual de la cámara; en `1f` (por defecto) el criterio es el mismo en Android y en iOS. |
| `utils.faceWidthFactorForFieldOfView(fieldOfViewDegrees)` | Calcula ese factor a partir del campo visual horizontal de la cámara, contra `REFERENCE_FIELD_OF_VIEW_DEGREES` (73.7°). Solo puede aflojar el umbral, nunca endurecerlo. |
| `utils.resolveVideoHelpText(customValidationText, overwriteDefaultTextWith, amountOfFingers)` | Resolución del texto de ayuda debajo del óvalo, con la precedencia descrita más arriba y el reemplazo del `%d`. |

---

### Lista de Cambios

- #### VideoCameraConfig (1.5.0):
  - **`challengeTexts`** (*VideoChallengeTexts?*): Personaliza los textos que el SDK dibuja
    sobre la cámara durante la grabación. `null` = se usan los textos por defecto del SDK.
    Ver [Textos sobre la cámara](#textos-sobre-la-cámara-challengetexts).
  - **`showDetectedFaceOval`** (*Boolean?*): Permite dibujar u ocultar el óvalo del rostro detectado.
  - **`overlayDimAlpha`** (*Float?*): Opacidad del fondo translúcido alrededor del óvalo guía.
- #### VideoCameraConfig:
  - **`requireFaceFraming`** (*Boolean*): Permite desactivar el gate de encuadre de la grabación
    de video. **`true` por defecto**, así que actualizar no cambia el comportamiento actual.
- #### DocumentCameraConfig, SelfieCameraConfig, VideoCameraConfig:
  - **`lowLightBoostEnabled`** (*Boolean*): Permite desactivar la mejora de captura para poca luz
    en Android. **`true` por defecto**, así que actualizar no cambia el comportamiento actual. En
    iOS se ignora, y las tres configuraciones conservan sus constructores anteriores.
- #### SuccessAlertConfig (1.5.0):
  - **`imageBase64`** (*String?*): Permite agregar una imagen personalizada al modal, codificada en Base64. Pueden utilizarse las imagenes presentes en el SDK en ```DigiYoIcons```:
    - Android: ```DigiYoIcons.DocBackImage```
    - iOS: ```DigiYoIcons.shared.DocBackImage```
- #### CaptureModeConfig:
    - **`cameraButtonConfig`** (*ButtonConfig?*): Corresponde a la configuración de personalización del botón, incluyendo el título.
    - **`buttonType`** (*CaptureButtonType?*): Corresponde al tipo de botón.
    - **`infoBoxConfig`** (*InfoBoxConfig?*): Corresponde a la configuración de personalización de la información que se despliega en la captura.
- #### DocumentCameraConfig:
  - **`cameraSubtitle`** (*String?*): Permite agregar un subtítulo a la pantalla de la cámara.
  - **`showDetectedObjectRect`** (*Boolean*): Permite activar o desactivar el dibujado de un rectángulo alrededor del objeto detectado.
  - **`smartCropEnabled`** (*Boolean*): Permite activar o desactivar el recorte de la imagen usando el rectángulo detectado. Si se encuentra desactivado, la referencia es el recuadro guía presente en la pantalla de cámara.
  - **`shutterSoundEnabled`** (*Boolean*): Permite activar o desactivar el sonido del obturador de la cámara.
- #### SelfieCameraConfig:
  - **`shutterSoundEnabled`** (*Boolean*): Permite activar o desactivar el sonido del obturador de la cámara.
  - **`customLiveValidationsText`** (*LiveValidationsText?*): Permite personalizar el texto de los diferentes desafíos presentados para la validación de prueba de vida.
- #### VideoCameraConfig:
  - **`customLiveValidationsText`** (*LiveValidationsText?*): Permite personalizar el texto de los diferentes desafíos presentados para la validación de prueba de vida.
  - **`cameraSoundEnabled`** (*Boolean?*): Permite activar o desactivar el sonido de la cámara que alerta del inicio y final de la grabación.
  - **`challengeOverlayConfig`** (*ChallengeOverlayConfig?*): Permite configurar el overlay de los desafíos de video.
  - **`videoRecordDurationMs`** (*Long?*): Permite configurar la duración máxima de la grabación de video en milisegundos.
- #### HelpConfig:
  - **`helpScreenComplementaryImage`** (*DigiYoImageAsset?*): Permite agregar una imagen complementaria a la pantalla de ayuda.
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
