#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class DigiyoDigiyocoreDigiYoConfig, DigiyoDigiyocoreDigiYoError, DigiyoDigiyocoreDiaModel, DigiyoDigiyocoreInDataEntryModel, DigiyoDigiyocoreLiveValidationOptions, DigiyoDigiyocoreDigiYoCore, DigiyoDigiYoHelper, DigiyoDigiYoSDK, DigiyoDigiYo, UIViewController, DigiyoDocumentCameraConfig, DigiyoHelpConfig, DigiyoMediaPreviewConfig, DigiyoSelfieCameraConfig, DigiyoVideoCameraConfig, DigiyoRes, DigiyoKotlinByteArray, DigiyoResArray, DigiyoResDrawable, DigiyoResFont, DigiyoResPlurals, DigiyoResString, DigiyoDigiYoRGBCompanion, DigiyoDigiYoRGB, DigiyoErrorAlertConfig, DigiyoDigiYoColorScheme, DigiyoHelpBulletPoint, DigiyoKotlinPair<__covariant A, __covariant B>, DigiyoSuccessAlertConfig, DigiyoCaptureModeConfigCompanion, DigiyoCaptureModeConfig, DigiyoDigiYoColorSchemeCompanion, DigiyoDocumentType, DigiyoDigiYoIcons, DigiyoKotlinEnumCompanion, DigiyoKotlinEnum<E>, DigiyoKotlinArray<T>, DigiyoCameraMode, DigiyoCaptureArea, DigiyoDigiYoSDKUtils, DigiyoDocumentDetectorStatus, DigiyoLensFacingType, DigiyoSelfieDetectorStatus, DigiyoVideoDetectorStatus, DigiyoVideoValidationType, DigiyoUi_geometryRectCompanion, DigiyoUi_geometryRect, DigiyoKotlinCValue<T>, DigiyoLibraryDrawableResource, DigiyoLibraryFontResource, DigiyoLibraryPluralStringResource, DigiyoLibraryStringArrayResource, DigiyoLibraryStringResource, UIImage, DigiyoUiImageVector, VNRectangleObservation, DigiyoKotlinIntRange, NSData, VNFaceLandmarkRegion2D, DigiyoDigiyocoreDigiYoConfigEntity, DigiyoDigiyocoreDigiYoErrorCompanion, DigiyoDigiyocoreMetaModel, DigiyoDigiyocoreDataRequireModel, DigiyoDigiyocoreTaskModel, DigiyoDigiyocoreDiaModelCompanion, DigiyoDigiyocoreInDataEntryModelCompanion, DigiyoDigiyocoreLiveValidationOptionsCompanion, DigiyoKotlinThrowable, DigiyoKotlinException, DigiyoKotlinRuntimeException, DigiyoKotlinIllegalStateException, DigiyoKotlinByteIterator, DigiyoKotlinAutofreeScope, DigiyoKotlinCValuesRef<T>, DigiyoKotlinCValues<T>, DigiyoLibraryResource, DigiyoLibraryResourceItem, DigiyoUiImageVectorCompanion, DigiyoUiVectorGroup, DigiyoKotlinIntArray, DigiyoUi_graphicsColorSpace, DigiyoKotlinIntProgressionCompanion, DigiyoKotlinIntIterator, DigiyoKotlinIntProgression, DigiyoKotlinIntRangeCompanion, DigiyoDigiyocoreDigiYoConfigEntityCompanion, DigiyoDigiyocorePartnerModel, DigiyoDigiyocoreMetaModelCompanion, DigiyoDigiyocoreInDataConfigModel, DigiyoDigiyocoreDataRequireModelCompanion, DigiyoDigiyocoreResultModel, DigiyoDigiyocoreTaskModelCompanion, DigiyoKotlinDeferScope, DigiyoUiVectorNode, DigiyoUi_graphicsPathNode, DigiyoKotlinFloatArray, DigiyoDigiyocorePartnerModelCompanion, DigiyoDigiyocoreInDataConfigModelCompanion, DigiyoDigiyocoreScoresModel, DigiyoDigiyocoreIdInfoModel, DigiyoDigiyocorePolDetails, DigiyoDigiyocoreCisefDetails, DigiyoDigiyocoreValidationFlags, DigiyoDigiyocoreConductorDetails, DigiyoDigiyocoreResultModelCompanion, DigiyoKotlinFloatIterator, DigiyoKotlinx_serialization_coreSerializersModule, DigiyoKotlinx_serialization_coreSerialKind, DigiyoKotlinNothing, DigiyoDigiyocoreScoresModelCompanion, DigiyoDigiyocoreIdInfoModelCompanion, DigiyoDigiyocorePolDetailsCompanion, DigiyoDigiyocoreCisefDetailsCompanion, DigiyoDigiyocoreValidationFlagsCompanion, DigiyoDigiyocoreConductorDetailsCompanion;

@protocol DigiyoDigiyocoreDigiyoFileManager, DigiyoKotlinComparable, DigiyoUiModifier, DigiyoUi_graphicsImageBitmap, DigiyoDigiyocoreJavaSerializable, DigiyoKotlinIterator, DigiyoUiModifierElement, DigiyoKotlinIterable, DigiyoKotlinClosedRange, DigiyoKotlinOpenEndRange, DigiyoLibrary_baseDeleteable, DigiyoLibrary_baseBaseRealmObject, DigiyoLibrary_baseTypedRealmObject, DigiyoLibrary_baseRealmObject, DigiyoKotlinx_serialization_coreKSerializer, DigiyoKotlinNativePlacement, DigiyoLibraryQualifier, DigiyoKotlinx_serialization_coreEncoder, DigiyoKotlinx_serialization_coreSerialDescriptor, DigiyoKotlinx_serialization_coreSerializationStrategy, DigiyoKotlinx_serialization_coreDecoder, DigiyoKotlinx_serialization_coreDeserializationStrategy, DigiyoKotlinx_serialization_coreCompositeEncoder, DigiyoKotlinAnnotation, DigiyoKotlinx_serialization_coreCompositeDecoder, DigiyoKotlinx_serialization_coreSerializersModuleCollector, DigiyoKotlinKClass, DigiyoKotlinKDeclarationContainer, DigiyoKotlinKAnnotatedElement, DigiyoKotlinKClassifier;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface DigiyoBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface DigiyoBase (DigiyoBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface DigiyoMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface DigiyoMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorDigiyoKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface DigiyoNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface DigiyoByte : DigiyoNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface DigiyoUByte : DigiyoNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface DigiyoShort : DigiyoNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface DigiyoUShort : DigiyoNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface DigiyoInt : DigiyoNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface DigiyoUInt : DigiyoNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface DigiyoLong : DigiyoNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface DigiyoULong : DigiyoNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface DigiyoFloat : DigiyoNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface DigiyoDouble : DigiyoNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface DigiyoBoolean : DigiyoNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((swift_name("DigiyocoreDigiYoCore")))
@interface DigiyoDigiyocoreDigiYoCore : DigiyoBase
- (instancetype)initWithConfig:(DigiyoDigiyocoreDigiYoConfig * _Nullable)config fileManager:(id<DigiyoDigiyocoreDigiyoFileManager>)fileManager __attribute__((swift_name("init(config:fileManager:)"))) __attribute__((objc_designated_initializer));
- (void)cancelDiaDiaId:(NSString *)diaId onSuccess:(void (^)(void))onSuccess onError:(void (^)(DigiyoDigiyocoreDigiYoError *))onError __attribute__((swift_name("cancelDia(diaId:onSuccess:onError:)")));
- (void)commitDiaDiaId:(NSString *)diaId onSuccess:(void (^)(NSString * _Nullable))onSuccess onError:(void (^)(DigiyoDigiyocoreDigiYoError *))onError __attribute__((swift_name("commitDia(diaId:onSuccess:onError:)")));
- (void)createDiaDiaType:(NSString *)diaType onSuccess:(void (^)(DigiyoDigiyocoreDiaModel * _Nullable))onSuccess onError:(void (^)(DigiyoDigiyocoreDigiYoError *))onError __attribute__((swift_name("createDia(diaType:onSuccess:onError:)")));
- (void)createDiaDiaType:(NSString *)diaType latitude:(NSString * _Nullable)latitude longitude:(NSString * _Nullable)longitude onSuccess:(void (^)(DigiyoDigiyocoreDiaModel * _Nullable))onSuccess onError:(void (^)(DigiyoDigiyocoreDigiYoError *))onError __attribute__((swift_name("createDia(diaType:latitude:longitude:onSuccess:onError:)")));
- (void)getDiaDiaId:(NSString *)diaId onSuccess:(void (^)(DigiyoDigiyocoreDiaModel * _Nullable))onSuccess onError:(void (^)(DigiyoDigiyocoreDigiYoError *))onError __attribute__((swift_name("getDia(diaId:onSuccess:onError:)")));
- (DigiyoDigiyocoreInDataEntryModel * _Nullable)getInDataInDataName:(NSString *)inDataName __attribute__((swift_name("getInData(inDataName:)")));
- (DigiyoDigiyocoreDiaModel * _Nullable)getSavedDia __attribute__((swift_name("getSavedDia()")));
- (void)sendImageDiaId:(NSString *)diaId filePath:(NSString *)filePath inDataName:(NSString *)inDataName liveValidationOptions:(DigiyoDigiyocoreLiveValidationOptions * _Nullable)liveValidationOptions onSuccess:(void (^)(NSString * _Nullable))onSuccess onError:(void (^)(DigiyoDigiyocoreDigiYoError *))onError __attribute__((swift_name("sendImage(diaId:filePath:inDataName:liveValidationOptions:onSuccess:onError:)")));
- (void)sendImageAysnchronouslyDiaId:(NSString *)diaId filePath:(NSString *)filePath inDataName:(NSString *)inDataName liveValidationOptions:(DigiyoDigiyocoreLiveValidationOptions * _Nullable)liveValidationOptions __attribute__((swift_name("sendImageAysnchronously(diaId:filePath:inDataName:liveValidationOptions:)")));
- (void)sendJsonDataDiaId:(NSString *)diaId json:(NSString *)json onSuccess:(void (^)(NSString * _Nullable))onSuccess onError:(void (^)(DigiyoDigiyocoreDigiYoError *))onError __attribute__((swift_name("sendJsonData(diaId:json:onSuccess:onError:)")));
- (void)sendTextDataDiaId:(NSString *)diaId value:(NSString *)value inDataName:(NSString *)inDataName onSuccess:(void (^)(NSString * _Nullable))onSuccess onError:(void (^)(DigiyoDigiyocoreDigiYoError *))onError __attribute__((swift_name("sendTextData(diaId:value:inDataName:onSuccess:onError:)")));
- (void)sendVideoDiaId:(NSString *)diaId filePath:(NSString *)filePath inData:(DigiyoDigiyocoreInDataEntryModel *)inData onSuccess:(void (^)(NSString * _Nullable))onSuccess onError:(void (^)(DigiyoDigiyocoreDigiYoError *))onError __attribute__((swift_name("sendVideo(diaId:filePath:inData:onSuccess:onError:)")));
- (void)sendVideoAsynchronouslyDiaId:(NSString *)diaId filePath:(NSString *)filePath inData:(DigiyoDigiyocoreInDataEntryModel *)inData __attribute__((swift_name("sendVideoAsynchronously(diaId:filePath:inData:)")));
- (void)verifyTasksAndCommitDiaId:(NSString *)diaId onSuccess:(void (^)(NSString * _Nullable))onSuccess onError:(void (^)(DigiyoDigiyocoreDigiYoError *))onError onTaskNotCompleted:(void (^)(NSArray<NSString *> *))onTaskNotCompleted __attribute__((swift_name("verifyTasksAndCommit(diaId:onSuccess:onError:onTaskNotCompleted:)")));
@property (readonly) id<DigiyoDigiyocoreDigiyoFileManager> fileManager __attribute__((swift_name("fileManager")));
@end

__attribute__((swift_name("DigiYo")))
@interface DigiyoDigiYo : DigiyoDigiyocoreDigiYoCore
- (instancetype)initWithConfig:(DigiyoDigiyocoreDigiYoConfig * _Nullable)config fileManager:(id<DigiyoDigiyocoreDigiyoFileManager>)fileManager __attribute__((swift_name("init(config:fileManager:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiYoHelper")))
@interface DigiyoDigiYoHelper : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)digiYoHelper __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiYoHelper *shared __attribute__((swift_name("shared")));
- (void)initializeConfig:(DigiyoDigiyocoreDigiYoConfig * _Nullable)config __attribute__((swift_name("initialize(config:)")));
@property (readonly) DigiyoDigiYoSDK *sdk __attribute__((swift_name("sdk")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiYoSDK")))
@interface DigiyoDigiYoSDK : DigiyoDigiYo
- (instancetype)initWithConfig:(DigiyoDigiyocoreDigiYoConfig * _Nullable)config __attribute__((swift_name("init(config:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithConfig:(DigiyoDigiyocoreDigiYoConfig * _Nullable)config fileManager:(id<DigiyoDigiyocoreDigiyoFileManager>)fileManager __attribute__((swift_name("init(config:fileManager:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (UIViewController *)getDocumentCameraViewControllerConfig:(DigiyoDocumentCameraConfig *)config onResult:(void (^)(NSString *, NSString *))onResult onClose:(void (^)(void))onClose __attribute__((swift_name("getDocumentCameraViewController(config:onResult:onClose:)")));
- (UIViewController *)getHelpScreenViewViewControllerConfig:(DigiyoHelpConfig *)config onButtonPressed:(void (^)(void))onButtonPressed __attribute__((swift_name("getHelpScreenViewViewController(config:onButtonPressed:)")));
- (UIViewController *)getMediaPreviewScreenViewControllerConfig:(DigiyoMediaPreviewConfig *)config onPrimaryButtonPressed:(void (^)(void))onPrimaryButtonPressed onSecondaryButtonPressed:(void (^)(void))onSecondaryButtonPressed __attribute__((swift_name("getMediaPreviewScreenViewController(config:onPrimaryButtonPressed:onSecondaryButtonPressed:)")));
- (UIViewController *)getSelfieCameraViewViewControllerConfig:(DigiyoSelfieCameraConfig *)config onResult:(void (^)(NSString *))onResult onClose:(void (^)(void))onClose __attribute__((swift_name("getSelfieCameraViewViewController(config:onResult:onClose:)")));
- (UIViewController *)getVideoCameraViewViewControllerConfig:(DigiyoVideoCameraConfig *)config onResult:(void (^)(NSString *))onResult onClose:(void (^)(void))onClose __attribute__((swift_name("getVideoCameraViewViewController(config:onResult:onClose:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Res")))
@interface DigiyoRes : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)res __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoRes *shared __attribute__((swift_name("shared")));
- (NSString *)getUriPath:(NSString *)path __attribute__((swift_name("getUri(path:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readBytesPath:(NSString *)path completionHandler:(void (^)(DigiyoKotlinByteArray * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readBytes(path:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Res.array")))
@interface DigiyoResArray : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)array __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoResArray *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Res.drawable")))
@interface DigiyoResDrawable : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)drawable __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoResDrawable *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Res.font")))
@interface DigiyoResFont : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)font __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoResFont *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Res.plurals")))
@interface DigiyoResPlurals : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)plurals __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoResPlurals *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Res.string")))
@interface DigiyoResString : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)string __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoResString *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiYoRGB")))
@interface DigiyoDigiYoRGB : DigiyoBase
- (instancetype)initWithRed:(int32_t)red green:(int32_t)green blue:(int32_t)blue __attribute__((swift_name("init(red:green:blue:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiYoRGBCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiYoRGB *)doCopyRed:(int32_t)red green:(int32_t)green blue:(int32_t)blue __attribute__((swift_name("doCopy(red:green:blue:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t blue __attribute__((swift_name("blue")));
@property (readonly) int32_t green __attribute__((swift_name("green")));
@property (readonly) int32_t red __attribute__((swift_name("red")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiYoRGB.Companion")))
@interface DigiyoDigiYoRGBCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiYoRGBCompanion *shared __attribute__((swift_name("shared")));
- (DigiyoDigiYoRGB *)fromHexHexColor:(int32_t)hexColor __attribute__((swift_name("fromHex(hexColor:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ErrorAlertConfig")))
@interface DigiyoErrorAlertConfig : DigiyoBase
- (instancetype)initWithTitle:(NSString *)title subTitle:(NSString *)subTitle buttonTitle:(NSString *)buttonTitle primaryColor:(DigiyoDigiYoRGB * _Nullable)primaryColor displayDefaultActivityIndicator:(BOOL)displayDefaultActivityIndicator displayDialogAsBottomSheet:(BOOL)displayDialogAsBottomSheet __attribute__((swift_name("init(title:subTitle:buttonTitle:primaryColor:displayDefaultActivityIndicator:displayDialogAsBottomSheet:)"))) __attribute__((objc_designated_initializer));
- (DigiyoErrorAlertConfig *)doCopyTitle:(NSString *)title subTitle:(NSString *)subTitle buttonTitle:(NSString *)buttonTitle primaryColor:(DigiyoDigiYoRGB * _Nullable)primaryColor displayDefaultActivityIndicator:(BOOL)displayDefaultActivityIndicator displayDialogAsBottomSheet:(BOOL)displayDialogAsBottomSheet __attribute__((swift_name("doCopy(title:subTitle:buttonTitle:primaryColor:displayDefaultActivityIndicator:displayDialogAsBottomSheet:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *buttonTitle __attribute__((swift_name("buttonTitle")));
@property (readonly) BOOL displayDefaultActivityIndicator __attribute__((swift_name("displayDefaultActivityIndicator")));
@property (readonly) BOOL displayDialogAsBottomSheet __attribute__((swift_name("displayDialogAsBottomSheet")));
@property (readonly) DigiyoDigiYoRGB * _Nullable primaryColor __attribute__((swift_name("primaryColor")));
@property (readonly) NSString *subTitle __attribute__((swift_name("subTitle")));
@property (readonly) NSString *title __attribute__((swift_name("title")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HelpConfig")))
@interface DigiyoHelpConfig : DigiyoBase
- (instancetype)initWithHelpScreenTitle:(NSString *)helpScreenTitle helpScreenImageBase64:(NSString * _Nullable)helpScreenImageBase64 colorScheme:(DigiyoDigiYoColorScheme * _Nullable)colorScheme imageShouldFollowColorScheme:(BOOL)imageShouldFollowColorScheme bulletAndAdvices:(NSArray<DigiyoKotlinPair<DigiyoHelpBulletPoint *, NSString *> *> *)bulletAndAdvices continueButtonTitle:(NSString *)continueButtonTitle customTitleTextColor:(DigiyoDigiYoRGB * _Nullable)customTitleTextColor customContinueButtonColor:(DigiyoDigiYoRGB * _Nullable)customContinueButtonColor displayDefaultActivityIndicator:(BOOL)displayDefaultActivityIndicator __attribute__((swift_name("init(helpScreenTitle:helpScreenImageBase64:colorScheme:imageShouldFollowColorScheme:bulletAndAdvices:continueButtonTitle:customTitleTextColor:customContinueButtonColor:displayDefaultActivityIndicator:)"))) __attribute__((objc_designated_initializer));
- (DigiyoHelpConfig *)doCopyHelpScreenTitle:(NSString *)helpScreenTitle helpScreenImageBase64:(NSString * _Nullable)helpScreenImageBase64 colorScheme:(DigiyoDigiYoColorScheme * _Nullable)colorScheme imageShouldFollowColorScheme:(BOOL)imageShouldFollowColorScheme bulletAndAdvices:(NSArray<DigiyoKotlinPair<DigiyoHelpBulletPoint *, NSString *> *> *)bulletAndAdvices continueButtonTitle:(NSString *)continueButtonTitle customTitleTextColor:(DigiyoDigiYoRGB * _Nullable)customTitleTextColor customContinueButtonColor:(DigiyoDigiYoRGB * _Nullable)customContinueButtonColor displayDefaultActivityIndicator:(BOOL)displayDefaultActivityIndicator __attribute__((swift_name("doCopy(helpScreenTitle:helpScreenImageBase64:colorScheme:imageShouldFollowColorScheme:bulletAndAdvices:continueButtonTitle:customTitleTextColor:customContinueButtonColor:displayDefaultActivityIndicator:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<DigiyoKotlinPair<DigiyoHelpBulletPoint *, NSString *> *> *bulletAndAdvices __attribute__((swift_name("bulletAndAdvices")));
@property (readonly) DigiyoDigiYoColorScheme * _Nullable colorScheme __attribute__((swift_name("colorScheme")));
@property (readonly) NSString *continueButtonTitle __attribute__((swift_name("continueButtonTitle")));
@property (readonly) DigiyoDigiYoRGB * _Nullable customContinueButtonColor __attribute__((swift_name("customContinueButtonColor")));
@property (readonly) DigiyoDigiYoRGB * _Nullable customTitleTextColor __attribute__((swift_name("customTitleTextColor")));
@property (readonly) BOOL displayDefaultActivityIndicator __attribute__((swift_name("displayDefaultActivityIndicator")));
@property (readonly) NSString * _Nullable helpScreenImageBase64 __attribute__((swift_name("helpScreenImageBase64")));
@property (readonly) NSString *helpScreenTitle __attribute__((swift_name("helpScreenTitle")));
@property (readonly) BOOL imageShouldFollowColorScheme __attribute__((swift_name("imageShouldFollowColorScheme")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MediaPreviewConfig")))
@interface DigiyoMediaPreviewConfig : DigiyoBase
- (instancetype)initWithPreviewScreenTitle:(NSString *)previewScreenTitle previewSubtitle:(NSString * _Nullable)previewSubtitle previewMediaPath:(NSString * _Nullable)previewMediaPath isMediaAVideo:(BOOL)isMediaAVideo colorScheme:(DigiyoDigiYoColorScheme * _Nullable)colorScheme bulletAndAdvices:(NSArray<DigiyoKotlinPair<DigiyoHelpBulletPoint *, NSString *> *> * _Nullable)bulletAndAdvices primaryButtonTitle:(NSString *)primaryButtonTitle customPrimaryButtonColor:(DigiyoDigiYoRGB * _Nullable)customPrimaryButtonColor secondaryButtonTitle:(NSString *)secondaryButtonTitle customSecondaryButtonColor:(DigiyoDigiYoRGB * _Nullable)customSecondaryButtonColor customTitleTextColor:(DigiyoDigiYoRGB * _Nullable)customTitleTextColor displayDefaultActivityIndicator:(BOOL)displayDefaultActivityIndicator __attribute__((swift_name("init(previewScreenTitle:previewSubtitle:previewMediaPath:isMediaAVideo:colorScheme:bulletAndAdvices:primaryButtonTitle:customPrimaryButtonColor:secondaryButtonTitle:customSecondaryButtonColor:customTitleTextColor:displayDefaultActivityIndicator:)"))) __attribute__((objc_designated_initializer));
- (DigiyoMediaPreviewConfig *)doCopyPreviewScreenTitle:(NSString *)previewScreenTitle previewSubtitle:(NSString * _Nullable)previewSubtitle previewMediaPath:(NSString * _Nullable)previewMediaPath isMediaAVideo:(BOOL)isMediaAVideo colorScheme:(DigiyoDigiYoColorScheme * _Nullable)colorScheme bulletAndAdvices:(NSArray<DigiyoKotlinPair<DigiyoHelpBulletPoint *, NSString *> *> * _Nullable)bulletAndAdvices primaryButtonTitle:(NSString *)primaryButtonTitle customPrimaryButtonColor:(DigiyoDigiYoRGB * _Nullable)customPrimaryButtonColor secondaryButtonTitle:(NSString *)secondaryButtonTitle customSecondaryButtonColor:(DigiyoDigiYoRGB * _Nullable)customSecondaryButtonColor customTitleTextColor:(DigiyoDigiYoRGB * _Nullable)customTitleTextColor displayDefaultActivityIndicator:(BOOL)displayDefaultActivityIndicator __attribute__((swift_name("doCopy(previewScreenTitle:previewSubtitle:previewMediaPath:isMediaAVideo:colorScheme:bulletAndAdvices:primaryButtonTitle:customPrimaryButtonColor:secondaryButtonTitle:customSecondaryButtonColor:customTitleTextColor:displayDefaultActivityIndicator:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<DigiyoKotlinPair<DigiyoHelpBulletPoint *, NSString *> *> * _Nullable bulletAndAdvices __attribute__((swift_name("bulletAndAdvices")));
@property (readonly) DigiyoDigiYoColorScheme * _Nullable colorScheme __attribute__((swift_name("colorScheme")));
@property (readonly) DigiyoDigiYoRGB * _Nullable customPrimaryButtonColor __attribute__((swift_name("customPrimaryButtonColor")));
@property (readonly) DigiyoDigiYoRGB * _Nullable customSecondaryButtonColor __attribute__((swift_name("customSecondaryButtonColor")));
@property (readonly) DigiyoDigiYoRGB * _Nullable customTitleTextColor __attribute__((swift_name("customTitleTextColor")));
@property (readonly) BOOL displayDefaultActivityIndicator __attribute__((swift_name("displayDefaultActivityIndicator")));
@property (readonly) BOOL isMediaAVideo __attribute__((swift_name("isMediaAVideo")));
@property (readonly) NSString * _Nullable previewMediaPath __attribute__((swift_name("previewMediaPath")));
@property (readonly) NSString *previewScreenTitle __attribute__((swift_name("previewScreenTitle")));
@property (readonly) NSString * _Nullable previewSubtitle __attribute__((swift_name("previewSubtitle")));
@property (readonly) NSString *primaryButtonTitle __attribute__((swift_name("primaryButtonTitle")));
@property (readonly) NSString *secondaryButtonTitle __attribute__((swift_name("secondaryButtonTitle")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SuccessAlertConfig")))
@interface DigiyoSuccessAlertConfig : DigiyoBase
- (instancetype)initWithTitle:(NSString *)title subTitle:(NSString *)subTitle buttonTitle:(NSString *)buttonTitle primaryColor:(DigiyoDigiYoRGB * _Nullable)primaryColor imageBase64:(NSString * _Nullable)imageBase64 displayDefaultActivityIndicator:(BOOL)displayDefaultActivityIndicator displayDialogAsBottomSheet:(BOOL)displayDialogAsBottomSheet __attribute__((swift_name("init(title:subTitle:buttonTitle:primaryColor:imageBase64:displayDefaultActivityIndicator:displayDialogAsBottomSheet:)"))) __attribute__((objc_designated_initializer));
- (DigiyoSuccessAlertConfig *)doCopyTitle:(NSString *)title subTitle:(NSString *)subTitle buttonTitle:(NSString *)buttonTitle primaryColor:(DigiyoDigiYoRGB * _Nullable)primaryColor imageBase64:(NSString * _Nullable)imageBase64 displayDefaultActivityIndicator:(BOOL)displayDefaultActivityIndicator displayDialogAsBottomSheet:(BOOL)displayDialogAsBottomSheet __attribute__((swift_name("doCopy(title:subTitle:buttonTitle:primaryColor:imageBase64:displayDefaultActivityIndicator:displayDialogAsBottomSheet:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *buttonTitle __attribute__((swift_name("buttonTitle")));
@property (readonly) BOOL displayDefaultActivityIndicator __attribute__((swift_name("displayDefaultActivityIndicator")));
@property (readonly) BOOL displayDialogAsBottomSheet __attribute__((swift_name("displayDialogAsBottomSheet")));
@property (readonly) NSString * _Nullable imageBase64 __attribute__((swift_name("imageBase64")));
@property (readonly) DigiyoDigiYoRGB * _Nullable primaryColor __attribute__((swift_name("primaryColor")));
@property (readonly) NSString *subTitle __attribute__((swift_name("subTitle")));
@property (readonly) NSString *title __attribute__((swift_name("title")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CaptureModeConfig")))
@interface DigiyoCaptureModeConfig : DigiyoBase
- (instancetype)initWithAutomaticReadingEnabled:(BOOL)automaticReadingEnabled automaticModeTimeoutMillis:(DigiyoLong * _Nullable)automaticModeTimeoutMillis manualCaptureButtonTitle:(NSString * _Nullable)manualCaptureButtonTitle manualCaptureButtonColor:(DigiyoDigiYoRGB * _Nullable)manualCaptureButtonColor __attribute__((swift_name("init(automaticReadingEnabled:automaticModeTimeoutMillis:manualCaptureButtonTitle:manualCaptureButtonColor:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoCaptureModeConfigCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoCaptureModeConfig *)doCopyAutomaticReadingEnabled:(BOOL)automaticReadingEnabled automaticModeTimeoutMillis:(DigiyoLong * _Nullable)automaticModeTimeoutMillis manualCaptureButtonTitle:(NSString * _Nullable)manualCaptureButtonTitle manualCaptureButtonColor:(DigiyoDigiYoRGB * _Nullable)manualCaptureButtonColor __attribute__((swift_name("doCopy(automaticReadingEnabled:automaticModeTimeoutMillis:manualCaptureButtonTitle:manualCaptureButtonColor:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DigiyoLong * _Nullable automaticModeTimeoutMillis __attribute__((swift_name("automaticModeTimeoutMillis")));
@property (readonly) BOOL automaticReadingEnabled __attribute__((swift_name("automaticReadingEnabled")));
@property (readonly) DigiyoDigiYoRGB * _Nullable manualCaptureButtonColor __attribute__((swift_name("manualCaptureButtonColor")));
@property (readonly) NSString * _Nullable manualCaptureButtonTitle __attribute__((swift_name("manualCaptureButtonTitle")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CaptureModeConfig.Companion")))
@interface DigiyoCaptureModeConfigCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoCaptureModeConfigCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) int64_t DEFAULT_BUTTON_TIMEOUT_MILLIS __attribute__((swift_name("DEFAULT_BUTTON_TIMEOUT_MILLIS")));
@property (readonly) NSString *DEFAULT_BUTTON_TITLE __attribute__((swift_name("DEFAULT_BUTTON_TITLE")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiYoColorScheme")))
@interface DigiyoDigiYoColorScheme : DigiyoBase
- (instancetype)initWithPrimaryColor:(DigiyoDigiYoRGB *)primaryColor secondaryColor:(DigiyoDigiYoRGB * _Nullable)secondaryColor accentColor:(DigiyoDigiYoRGB * _Nullable)accentColor primaryTextColor:(DigiyoDigiYoRGB * _Nullable)primaryTextColor secondaryTextColor:(DigiyoDigiYoRGB * _Nullable)secondaryTextColor errorColor:(DigiyoDigiYoRGB * _Nullable)errorColor successColor:(DigiyoDigiYoRGB * _Nullable)successColor __attribute__((swift_name("init(primaryColor:secondaryColor:accentColor:primaryTextColor:secondaryTextColor:errorColor:successColor:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiYoColorSchemeCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiYoColorScheme *)doCopyPrimaryColor:(DigiyoDigiYoRGB *)primaryColor secondaryColor:(DigiyoDigiYoRGB * _Nullable)secondaryColor accentColor:(DigiyoDigiYoRGB * _Nullable)accentColor primaryTextColor:(DigiyoDigiYoRGB * _Nullable)primaryTextColor secondaryTextColor:(DigiyoDigiYoRGB * _Nullable)secondaryTextColor errorColor:(DigiyoDigiYoRGB * _Nullable)errorColor successColor:(DigiyoDigiYoRGB * _Nullable)successColor __attribute__((swift_name("doCopy(primaryColor:secondaryColor:accentColor:primaryTextColor:secondaryTextColor:errorColor:successColor:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DigiyoDigiYoRGB *accent __attribute__((swift_name("accent")));
@property (readonly) DigiyoDigiYoRGB * _Nullable accentColor __attribute__((swift_name("accentColor")));
@property (readonly) DigiyoDigiYoRGB * _Nullable errorColor __attribute__((swift_name("errorColor")));
@property (readonly) DigiyoDigiYoRGB *onErrorColor __attribute__((swift_name("onErrorColor")));
@property (readonly) DigiyoDigiYoRGB *onSuccessColor __attribute__((swift_name("onSuccessColor")));
@property (readonly) DigiyoDigiYoRGB *primaryColor __attribute__((swift_name("primaryColor")));
@property (readonly) DigiyoDigiYoRGB *primaryText __attribute__((swift_name("primaryText")));
@property (readonly) DigiyoDigiYoRGB * _Nullable primaryTextColor __attribute__((swift_name("primaryTextColor")));
@property (readonly) DigiyoDigiYoRGB *secondary __attribute__((swift_name("secondary")));
@property (readonly) DigiyoDigiYoRGB * _Nullable secondaryColor __attribute__((swift_name("secondaryColor")));
@property (readonly) DigiyoDigiYoRGB *secondaryText __attribute__((swift_name("secondaryText")));
@property (readonly) DigiyoDigiYoRGB * _Nullable secondaryTextColor __attribute__((swift_name("secondaryTextColor")));
@property (readonly) DigiyoDigiYoRGB * _Nullable successColor __attribute__((swift_name("successColor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiYoColorScheme.Companion")))
@interface DigiyoDigiYoColorSchemeCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiYoColorSchemeCompanion *shared __attribute__((swift_name("shared")));
- (DigiyoDigiYoColorScheme *)fromPrimaryColorPrimaryColor:(DigiyoDigiYoRGB *)primaryColor __attribute__((swift_name("fromPrimaryColor(primaryColor:)")));
@property (readonly) DigiyoDigiYoColorScheme *DEFAULT_COLOR_SCHEME __attribute__((swift_name("DEFAULT_COLOR_SCHEME")));
@property (readonly) uint64_t DISABLED_BACKGROUND __attribute__((swift_name("DISABLED_BACKGROUND")));
@property (readonly) uint64_t DISABLED_TEXT_COLOR __attribute__((swift_name("DISABLED_TEXT_COLOR")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DocumentCameraConfig")))
@interface DigiyoDocumentCameraConfig : DigiyoBase
- (instancetype)initWithCameraTitle:(NSString *)cameraTitle documentType:(DigiyoDocumentType *)documentType colorScheme:(DigiyoDigiYoColorScheme * _Nullable)colorScheme successAlertConfig:(DigiyoSuccessAlertConfig * _Nullable)successAlertConfig showCloseButton:(DigiyoBoolean * _Nullable)showCloseButton captureModeConfig:(DigiyoCaptureModeConfig *)captureModeConfig showDetectedObjectRect:(BOOL)showDetectedObjectRect smartCropEnabled:(BOOL)smartCropEnabled shutterSoundEnabled:(BOOL)shutterSoundEnabled __attribute__((swift_name("init(cameraTitle:documentType:colorScheme:successAlertConfig:showCloseButton:captureModeConfig:showDetectedObjectRect:smartCropEnabled:shutterSoundEnabled:)"))) __attribute__((objc_designated_initializer));
- (DigiyoDocumentCameraConfig *)doCopyCameraTitle:(NSString *)cameraTitle documentType:(DigiyoDocumentType *)documentType colorScheme:(DigiyoDigiYoColorScheme * _Nullable)colorScheme successAlertConfig:(DigiyoSuccessAlertConfig * _Nullable)successAlertConfig showCloseButton:(DigiyoBoolean * _Nullable)showCloseButton captureModeConfig:(DigiyoCaptureModeConfig *)captureModeConfig showDetectedObjectRect:(BOOL)showDetectedObjectRect smartCropEnabled:(BOOL)smartCropEnabled shutterSoundEnabled:(BOOL)shutterSoundEnabled __attribute__((swift_name("doCopy(cameraTitle:documentType:colorScheme:successAlertConfig:showCloseButton:captureModeConfig:showDetectedObjectRect:smartCropEnabled:shutterSoundEnabled:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *cameraTitle __attribute__((swift_name("cameraTitle")));
@property (readonly) DigiyoCaptureModeConfig *captureModeConfig __attribute__((swift_name("captureModeConfig")));
@property (readonly) DigiyoDigiYoColorScheme * _Nullable colorScheme __attribute__((swift_name("colorScheme")));
@property (readonly) DigiyoDocumentType *documentType __attribute__((swift_name("documentType")));
@property (readonly) DigiyoBoolean * _Nullable showCloseButton __attribute__((swift_name("showCloseButton")));
@property (readonly) BOOL showDetectedObjectRect __attribute__((swift_name("showDetectedObjectRect")));
@property (readonly) BOOL shutterSoundEnabled __attribute__((swift_name("shutterSoundEnabled")));
@property (readonly) BOOL smartCropEnabled __attribute__((swift_name("smartCropEnabled")));
@property (readonly) DigiyoSuccessAlertConfig * _Nullable successAlertConfig __attribute__((swift_name("successAlertConfig")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SelfieCameraConfig")))
@interface DigiyoSelfieCameraConfig : DigiyoBase
- (instancetype)initWithCameraTitle:(NSString *)cameraTitle colorScheme:(DigiyoDigiYoColorScheme * _Nullable)colorScheme successAlertConfig:(DigiyoSuccessAlertConfig * _Nullable)successAlertConfig showCloseButton:(DigiyoBoolean * _Nullable)showCloseButton captureModeConfig:(DigiyoCaptureModeConfig *)captureModeConfig shutterSoundEnabled:(BOOL)shutterSoundEnabled __attribute__((swift_name("init(cameraTitle:colorScheme:successAlertConfig:showCloseButton:captureModeConfig:shutterSoundEnabled:)"))) __attribute__((objc_designated_initializer));
- (DigiyoSelfieCameraConfig *)doCopyCameraTitle:(NSString *)cameraTitle colorScheme:(DigiyoDigiYoColorScheme * _Nullable)colorScheme successAlertConfig:(DigiyoSuccessAlertConfig * _Nullable)successAlertConfig showCloseButton:(DigiyoBoolean * _Nullable)showCloseButton captureModeConfig:(DigiyoCaptureModeConfig *)captureModeConfig shutterSoundEnabled:(BOOL)shutterSoundEnabled __attribute__((swift_name("doCopy(cameraTitle:colorScheme:successAlertConfig:showCloseButton:captureModeConfig:shutterSoundEnabled:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *cameraTitle __attribute__((swift_name("cameraTitle")));
@property (readonly) DigiyoCaptureModeConfig *captureModeConfig __attribute__((swift_name("captureModeConfig")));
@property (readonly) DigiyoDigiYoColorScheme * _Nullable colorScheme __attribute__((swift_name("colorScheme")));
@property (readonly) DigiyoBoolean * _Nullable showCloseButton __attribute__((swift_name("showCloseButton")));
@property (readonly) BOOL shutterSoundEnabled __attribute__((swift_name("shutterSoundEnabled")));
@property (readonly) DigiyoSuccessAlertConfig * _Nullable successAlertConfig __attribute__((swift_name("successAlertConfig")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VideoCameraConfig")))
@interface DigiyoVideoCameraConfig : DigiyoBase
- (instancetype)initWithCameraTitle:(NSString *)cameraTitle colorScheme:(DigiyoDigiYoColorScheme * _Nullable)colorScheme successAlertConfig:(DigiyoSuccessAlertConfig * _Nullable)successAlertConfig errorAlertConfig:(DigiyoErrorAlertConfig * _Nullable)errorAlertConfig showCloseButton:(DigiyoBoolean * _Nullable)showCloseButton captureModeConfig:(DigiyoCaptureModeConfig *)captureModeConfig __attribute__((swift_name("init(cameraTitle:colorScheme:successAlertConfig:errorAlertConfig:showCloseButton:captureModeConfig:)"))) __attribute__((objc_designated_initializer));
- (DigiyoVideoCameraConfig *)doCopyCameraTitle:(NSString *)cameraTitle colorScheme:(DigiyoDigiYoColorScheme * _Nullable)colorScheme successAlertConfig:(DigiyoSuccessAlertConfig * _Nullable)successAlertConfig errorAlertConfig:(DigiyoErrorAlertConfig * _Nullable)errorAlertConfig showCloseButton:(DigiyoBoolean * _Nullable)showCloseButton captureModeConfig:(DigiyoCaptureModeConfig *)captureModeConfig __attribute__((swift_name("doCopy(cameraTitle:colorScheme:successAlertConfig:errorAlertConfig:showCloseButton:captureModeConfig:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *cameraTitle __attribute__((swift_name("cameraTitle")));
@property (readonly) DigiyoCaptureModeConfig *captureModeConfig __attribute__((swift_name("captureModeConfig")));
@property (readonly) DigiyoDigiYoColorScheme * _Nullable colorScheme __attribute__((swift_name("colorScheme")));
@property (readonly) DigiyoErrorAlertConfig * _Nullable errorAlertConfig __attribute__((swift_name("errorAlertConfig")));
@property (readonly) DigiyoBoolean * _Nullable showCloseButton __attribute__((swift_name("showCloseButton")));
@property (readonly) DigiyoSuccessAlertConfig * _Nullable successAlertConfig __attribute__((swift_name("successAlertConfig")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiYoIcons")))
@interface DigiyoDigiYoIcons : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)digiYoIcons __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiYoIcons *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *CheckImage __attribute__((swift_name("CheckImage")));
@property (readonly) NSString *DocBackImage __attribute__((swift_name("DocBackImage")));
@property (readonly) NSString *DocFrontImage __attribute__((swift_name("DocFrontImage")));
@property (readonly) NSString *ErrorImage __attribute__((swift_name("ErrorImage")));
@property (readonly) NSString *ErrorImageInverted __attribute__((swift_name("ErrorImageInverted")));
@property (readonly) NSString *InfoGlyph __attribute__((swift_name("InfoGlyph")));
@property (readonly) NSString *NoGlassesImage __attribute__((swift_name("NoGlassesImage")));
@property (readonly) NSString *ProfileImage __attribute__((swift_name("ProfileImage")));
@property (readonly) NSString *SelfieImage __attribute__((swift_name("SelfieImage")));
@property (readonly) NSString *VideoImage __attribute__((swift_name("VideoImage")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol DigiyoKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface DigiyoKotlinEnum<E> : DigiyoBase <DigiyoKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HelpBulletPoint")))
@interface DigiyoHelpBulletPoint : DigiyoKotlinEnum<DigiyoHelpBulletPoint *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DigiyoHelpBulletPoint *check __attribute__((swift_name("check")));
@property (class, readonly) DigiyoHelpBulletPoint *profile __attribute__((swift_name("profile")));
@property (class, readonly) DigiyoHelpBulletPoint *error __attribute__((swift_name("error")));
@property (class, readonly) DigiyoHelpBulletPoint *noglasses __attribute__((swift_name("noglasses")));
+ (DigiyoKotlinArray<DigiyoHelpBulletPoint *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DigiyoHelpBulletPoint *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *icon __attribute__((swift_name("icon")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CameraMode")))
@interface DigiyoCameraMode : DigiyoKotlinEnum<DigiyoCameraMode *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DigiyoCameraMode *document __attribute__((swift_name("document")));
@property (class, readonly) DigiyoCameraMode *human __attribute__((swift_name("human")));
+ (DigiyoKotlinArray<DigiyoCameraMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DigiyoCameraMode *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CaptureArea")))
@interface DigiyoCaptureArea : DigiyoBase
- (instancetype)initWithLeft:(float)left top:(float)top right:(float)right bottom:(float)bottom __attribute__((swift_name("init(left:top:right:bottom:)"))) __attribute__((objc_designated_initializer));
- (DigiyoCaptureArea *)doCopyLeft:(float)left top:(float)top right:(float)right bottom:(float)bottom __attribute__((swift_name("doCopy(left:top:right:bottom:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) float bottom __attribute__((swift_name("bottom")));
@property (readonly) float left __attribute__((swift_name("left")));
@property (readonly) float right __attribute__((swift_name("right")));
@property (readonly) float top __attribute__((swift_name("top")));
@end

__attribute__((swift_name("CaptureAreaProvider")))
@protocol DigiyoCaptureAreaProvider
@required
- (DigiyoCaptureArea *)getCaptureArea __attribute__((swift_name("getCaptureArea()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiYoSDKUtils")))
@interface DigiyoDigiYoSDKUtils : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)digiYoSDKUtils __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiYoSDKUtils *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *SDK_LOG_TAG __attribute__((swift_name("SDK_LOG_TAG")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DocumentDetectorStatus")))
@interface DigiyoDocumentDetectorStatus : DigiyoKotlinEnum<DigiyoDocumentDetectorStatus *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DigiyoDocumentDetectorStatus *nothing __attribute__((swift_name("nothing")));
@property (class, readonly) DigiyoDocumentDetectorStatus *noCenter __attribute__((swift_name("noCenter")));
@property (class, readonly) DigiyoDocumentDetectorStatus *invalidDistance __attribute__((swift_name("invalidDistance")));
@property (class, readonly) DigiyoDocumentDetectorStatus *valid __attribute__((swift_name("valid")));
@property (class, readonly) DigiyoDocumentDetectorStatus *captured __attribute__((swift_name("captured")));
+ (DigiyoKotlinArray<DigiyoDocumentDetectorStatus *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DigiyoDocumentDetectorStatus *> *entries __attribute__((swift_name("entries")));
- (uint64_t)getColorPrimaryColor:(uint64_t)primaryColor __attribute__((swift_name("getColor(primaryColor:)")));
- (uint64_t)getColorPrimaryColor:(uint64_t)primaryColor neutralColor:(id _Nullable)neutralColor __attribute__((swift_name("getColor(primaryColor:neutralColor:)")));
- (NSString *)getMessageManualMode:(BOOL)manualMode __attribute__((swift_name("getMessage(manualMode:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DocumentType")))
@interface DigiyoDocumentType : DigiyoKotlinEnum<DigiyoDocumentType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DigiyoDocumentType *ciFront __attribute__((swift_name("ciFront")));
@property (class, readonly) DigiyoDocumentType *ciBack __attribute__((swift_name("ciBack")));
+ (DigiyoKotlinArray<DigiyoDocumentType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DigiyoDocumentType *> *entries __attribute__((swift_name("entries")));
- (NSString *)getFileFullName __attribute__((swift_name("getFileFullName()")));
- (NSString *)getFileName __attribute__((swift_name("getFileName()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LensFacingType")))
@interface DigiyoLensFacingType : DigiyoKotlinEnum<DigiyoLensFacingType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DigiyoLensFacingType *lensFacingFront __attribute__((swift_name("lensFacingFront")));
@property (class, readonly) DigiyoLensFacingType *lensFacingBack __attribute__((swift_name("lensFacingBack")));
+ (DigiyoKotlinArray<DigiyoLensFacingType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DigiyoLensFacingType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SelfieDetectorStatus")))
@interface DigiyoSelfieDetectorStatus : DigiyoKotlinEnum<DigiyoSelfieDetectorStatus *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DigiyoSelfieDetectorStatus *nothing __attribute__((swift_name("nothing")));
@property (class, readonly) DigiyoSelfieDetectorStatus *noCenter __attribute__((swift_name("noCenter")));
@property (class, readonly) DigiyoSelfieDetectorStatus *invalidDistance __attribute__((swift_name("invalidDistance")));
@property (class, readonly) DigiyoSelfieDetectorStatus *valid __attribute__((swift_name("valid")));
@property (class, readonly) DigiyoSelfieDetectorStatus *captured __attribute__((swift_name("captured")));
+ (DigiyoKotlinArray<DigiyoSelfieDetectorStatus *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DigiyoSelfieDetectorStatus *> *entries __attribute__((swift_name("entries")));
- (uint64_t)getColorPrimaryColor:(uint64_t)primaryColor __attribute__((swift_name("getColor(primaryColor:)")));
- (uint64_t)getColorPrimaryColor:(uint64_t)primaryColor neutralColor:(id _Nullable)neutralColor __attribute__((swift_name("getColor(primaryColor:neutralColor:)")));
- (uint64_t)getFrameColorPrimaryColor:(uint64_t)primaryColor neutralColor:(id _Nullable)neutralColor __attribute__((swift_name("getFrameColor(primaryColor:neutralColor:)")));
- (NSString *)getMessageManualMode:(BOOL)manualMode __attribute__((swift_name("getMessage(manualMode:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VideoDetectorStatus")))
@interface DigiyoVideoDetectorStatus : DigiyoKotlinEnum<DigiyoVideoDetectorStatus *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DigiyoVideoDetectorStatus *nothing __attribute__((swift_name("nothing")));
@property (class, readonly) DigiyoVideoDetectorStatus *noCenter __attribute__((swift_name("noCenter")));
@property (class, readonly) DigiyoVideoDetectorStatus *invalidDistance __attribute__((swift_name("invalidDistance")));
@property (class, readonly) DigiyoVideoDetectorStatus *valid __attribute__((swift_name("valid")));
@property (class, readonly) DigiyoVideoDetectorStatus *recording __attribute__((swift_name("recording")));
@property (class, readonly) DigiyoVideoDetectorStatus *captured __attribute__((swift_name("captured")));
@property (class, readonly) DigiyoVideoDetectorStatus *invalid __attribute__((swift_name("invalid")));
@property (class, readonly) DigiyoVideoDetectorStatus *success __attribute__((swift_name("success")));
+ (DigiyoKotlinArray<DigiyoVideoDetectorStatus *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DigiyoVideoDetectorStatus *> *entries __attribute__((swift_name("entries")));
- (uint64_t)getColorPrimaryColor:(uint64_t)primaryColor __attribute__((swift_name("getColor(primaryColor:)")));
- (uint64_t)getColorPrimaryColor:(uint64_t)primaryColor neutralColor:(id _Nullable)neutralColor __attribute__((swift_name("getColor(primaryColor:neutralColor:)")));
- (uint64_t)getFrameColorPrimaryColor:(uint64_t)primaryColor neutralColor:(id _Nullable)neutralColor __attribute__((swift_name("getFrameColor(primaryColor:neutralColor:)")));
- (NSString *)getMessageAmountOfFingers:(DigiyoInt * _Nullable)amountOfFingers __attribute__((swift_name("getMessage(amountOfFingers:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VideoValidationType")))
@interface DigiyoVideoValidationType : DigiyoKotlinEnum<DigiyoVideoValidationType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DigiyoVideoValidationType *face __attribute__((swift_name("face")));
@property (class, readonly) DigiyoVideoValidationType *hand __attribute__((swift_name("hand")));
@property (class, readonly) DigiyoVideoValidationType *both __attribute__((swift_name("both")));
+ (DigiyoKotlinArray<DigiyoVideoValidationType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DigiyoVideoValidationType *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Immutable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ui_geometryRect")))
@interface DigiyoUi_geometryRect : DigiyoBase
- (instancetype)initWithLeft:(float)left top:(float)top right:(float)right bottom:(float)bottom __attribute__((swift_name("init(left:top:right:bottom:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoUi_geometryRectCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsOffset:(int64_t)offset __attribute__((swift_name("contains(offset:)")));
- (DigiyoUi_geometryRect *)doCopyLeft:(float)left top:(float)top right:(float)right bottom:(float)bottom __attribute__((swift_name("doCopy(left:top:right:bottom:)")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
- (DigiyoUi_geometryRect *)deflateDelta:(float)delta __attribute__((swift_name("deflate(delta:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
- (DigiyoUi_geometryRect *)inflateDelta:(float)delta __attribute__((swift_name("inflate(delta:)")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
- (DigiyoUi_geometryRect *)intersectOther:(DigiyoUi_geometryRect *)other __attribute__((swift_name("intersect(other:)")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
- (DigiyoUi_geometryRect *)intersectOtherLeft:(float)otherLeft otherTop:(float)otherTop otherRight:(float)otherRight otherBottom:(float)otherBottom __attribute__((swift_name("intersect(otherLeft:otherTop:otherRight:otherBottom:)")));
- (BOOL)overlapsOther:(DigiyoUi_geometryRect *)other __attribute__((swift_name("overlaps(other:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
- (DigiyoUi_geometryRect *)translateOffset:(int64_t)offset __attribute__((swift_name("translate(offset:)")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
- (DigiyoUi_geometryRect *)translateTranslateX:(float)translateX translateY:(float)translateY __attribute__((swift_name("translate(translateX:translateY:)")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
@property (readonly) float bottom __attribute__((swift_name("bottom")));
@property (readonly) int64_t bottomCenter __attribute__((swift_name("bottomCenter")));
@property (readonly) int64_t bottomLeft __attribute__((swift_name("bottomLeft")));
@property (readonly) int64_t bottomRight __attribute__((swift_name("bottomRight")));
@property (readonly) int64_t center __attribute__((swift_name("center")));
@property (readonly) int64_t centerLeft __attribute__((swift_name("centerLeft")));
@property (readonly) int64_t centerRight __attribute__((swift_name("centerRight")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
@property (readonly) float height __attribute__((swift_name("height")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
@property (readonly) BOOL isFinite __attribute__((swift_name("isFinite")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
@property (readonly) BOOL isInfinite __attribute__((swift_name("isInfinite")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
@property (readonly) float left __attribute__((swift_name("left")));
@property (readonly) float maxDimension __attribute__((swift_name("maxDimension")));
@property (readonly) float minDimension __attribute__((swift_name("minDimension")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
@property (readonly) float right __attribute__((swift_name("right")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
@property (readonly) int64_t size __attribute__((swift_name("size")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
@property (readonly) float top __attribute__((swift_name("top")));
@property (readonly) int64_t topCenter __attribute__((swift_name("topCenter")));
@property (readonly) int64_t topLeft __attribute__((swift_name("topLeft")));
@property (readonly) int64_t topRight __attribute__((swift_name("topRight")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
@property (readonly) float width __attribute__((swift_name("width")));
@end

@interface DigiyoUi_geometryRect (Extensions)
- (BOOL)containsOther:(DigiyoUi_geometryRect *)other __attribute__((swift_name("contains(other:)")));
- (DigiyoKotlinCValue<id> *)toCGRect __attribute__((swift_name("toCGRect()")));
@end

@interface DigiyoRes (Extensions)
@property (readonly) NSDictionary<NSString *, DigiyoLibraryDrawableResource *> *allDrawableResources __attribute__((swift_name("allDrawableResources")));
@property (readonly) NSDictionary<NSString *, DigiyoLibraryFontResource *> *allFontResources __attribute__((swift_name("allFontResources")));
@property (readonly) NSDictionary<NSString *, DigiyoLibraryPluralStringResource *> *allPluralStringResources __attribute__((swift_name("allPluralStringResources")));
@property (readonly) NSDictionary<NSString *, DigiyoLibraryStringArrayResource *> *allStringArrayResources __attribute__((swift_name("allStringArrayResources")));
@property (readonly) NSDictionary<NSString *, DigiyoLibraryStringResource *> *allStringResources __attribute__((swift_name("allStringResources")));
@end

@interface DigiyoDigiYoRGB (Extensions)
- (uint64_t)toColor __attribute__((swift_name("toColor()")));
@end

@interface DigiyoDigiYoColorScheme (Extensions)
- (DigiyoDigiYoRGB *)colorFromBulletTypeBulletType:(DigiyoHelpBulletPoint *)bulletType __attribute__((swift_name("colorFromBulletType(bulletType:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceUtilsKt")))
@interface DigiyoDeviceUtilsKt : DigiyoBase
+ (UIImage * _Nullable)captureImageFromSampleBufferSampleBuffer:(void *)sampleBuffer __attribute__((swift_name("captureImageFromSampleBuffer(sampleBuffer:)")));
+ (BOOL)isIOS14OrLater __attribute__((swift_name("isIOS14OrLater()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Doc_backKt")))
@interface DigiyoDoc_backKt : DigiyoBase
@property (class, readonly) DigiyoUiImageVector *Doc_back __attribute__((swift_name("Doc_back")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DocumentCameraView_iosKt")))
@interface DigiyoDocumentCameraView_iosKt : DigiyoBase
+ (BOOL)calculateSizeValidCentralRect:(DigiyoUi_geometryRect *)centralRect boxDetected:(DigiyoUi_geometryRect *)boxDetected __attribute__((swift_name("calculateSizeValid(centralRect:boxDetected:)")));
+ (UIImage *)cropImageImageData:(void * _Nullable)imageData smartCropEnabled:(BOOL)smartCropEnabled observation:(VNRectangleObservation * _Nullable)observation __attribute__((swift_name("cropImage(imageData:smartCropEnabled:observation:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExtensionsKt")))
@interface DigiyoExtensionsKt : DigiyoBase
+ (id<DigiyoUiModifier>)applyModifierIf:(id<DigiyoUiModifier>)receiver contition:(BOOL)contition modifier:(id<DigiyoUiModifier> (^)(id<DigiyoUiModifier>))modifier __attribute__((swift_name("applyModifierIf(_:contition:modifier:)")));
+ (uint64_t)contrastingTextColor:(uint64_t)receiver __attribute__((swift_name("contrastingTextColor(_:)")));
+ (id<DigiyoUi_graphicsImageBitmap>)decodeBase64ToImage:(NSString *)receiver __attribute__((swift_name("decodeBase64ToImage(_:)")));
+ (BOOL)isOvalWithinBoundsOuterBounds:(DigiyoUi_geometryRect *)outerBounds innerBounds:(DigiyoUi_geometryRect *)innerBounds tolerance:(float)tolerance __attribute__((swift_name("isOvalWithinBounds(outerBounds:innerBounds:tolerance:)")));
+ (DigiyoUi_geometryRect *)normalizeRectRect:(DigiyoUi_geometryRect *)rect __attribute__((swift_name("normalizeRect(rect:)")));
+ (DigiyoKotlinIntRange *)retrieveDigitsRange:(NSString *)receiver __attribute__((swift_name("retrieveDigitsRange(_:)")));
+ (DigiyoKotlinCValue<id> *)scaled:(void *)receiver size:(void *)size __attribute__((swift_name("scaled(_:size:)")));
+ (NSString * _Nullable)toBase64Image:(UIImage *)receiver __attribute__((swift_name("toBase64Image(_:)")));
+ (DigiyoKotlinByteArray *)toByteArray:(NSData *)receiver __attribute__((swift_name("toByteArray(_:)")));
+ (uint64_t)toComposeColor:(NSString *)receiver __attribute__((swift_name("toComposeColor(_:)")));
+ (NSString *)toPluralizedFingerString:(int32_t)receiver __attribute__((swift_name("toPluralizedFingerString(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ic_cameraKt")))
@interface DigiyoIc_cameraKt : DigiyoBase
@property (class, readonly) DigiyoUiImageVector *Ic_camera __attribute__((swift_name("Ic_camera")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SelfieCameraView_iosKt")))
@interface DigiyoSelfieCameraView_iosKt : DigiyoBase
+ (double)calculateEAREyePoints:(NSMutableArray<DigiyoKotlinCValue<id> *> *)eyePoints __attribute__((swift_name("calculateEAR(eyePoints:)")));
+ (double)distanceBetweenP1:(DigiyoKotlinCValue<id> *)p1 p2:(DigiyoKotlinCValue<id> *)p2 __attribute__((swift_name("distanceBetween(p1:p2:)")));
+ (NSMutableArray<DigiyoKotlinCValue<id> *> *)getEyePointsEye:(VNFaceLandmarkRegion2D *)eye __attribute__((swift_name("getEyePoints(eye:)")));
+ (BOOL)isEyeClosedEye:(VNFaceLandmarkRegion2D *)eye __attribute__((swift_name("isEyeClosed(eye:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GetPlatform_iosKt")))
@interface DigiyoGetPlatform_iosKt : DigiyoBase
+ (NSString *)getPlatform __attribute__((swift_name("getPlatform()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreDigiYoConfig")))
@interface DigiyoDigiyocoreDigiYoConfig : DigiyoBase
- (instancetype)initWithBaseUrl:(NSString * _Nullable)baseUrl apiKey:(NSString * _Nullable)apiKey requestTimeoutInMillis:(DigiyoLong * _Nullable)requestTimeoutInMillis __attribute__((swift_name("init(baseUrl:apiKey:requestTimeoutInMillis:)"))) __attribute__((objc_designated_initializer));
- (DigiyoDigiyocoreDigiYoConfig *)doCopyBaseUrl:(NSString * _Nullable)baseUrl apiKey:(NSString * _Nullable)apiKey requestTimeoutInMillis:(DigiyoLong * _Nullable)requestTimeoutInMillis __attribute__((swift_name("doCopy(baseUrl:apiKey:requestTimeoutInMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (DigiyoDigiyocoreDigiYoConfigEntity *)toEntity __attribute__((swift_name("toEntity()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable apiKey __attribute__((swift_name("apiKey")));
@property NSString * _Nullable baseUrl __attribute__((swift_name("baseUrl")));
@property DigiyoLong * _Nullable requestTimeoutInMillis __attribute__((swift_name("requestTimeoutInMillis")));
@end

__attribute__((swift_name("DigiyocoreDigiyoFileManager")))
@protocol DigiyoDigiyocoreDigiyoFileManager
@required
- (void)removeFileFilePath:(NSString *)filePath __attribute__((swift_name("removeFile(filePath:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreDigiYoError")))
@interface DigiyoDigiyocoreDigiYoError : DigiyoBase
- (instancetype)initWithCode:(NSString * _Nullable)code detail:(NSString * _Nullable)detail userVisible:(BOOL)userVisible __attribute__((swift_name("init(code:detail:userVisible:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreDigiYoErrorCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreDigiYoError *)doCopyCode:(NSString * _Nullable)code detail:(NSString * _Nullable)detail userVisible:(BOOL)userVisible __attribute__((swift_name("doCopy(code:detail:userVisible:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable code __attribute__((swift_name("code")));
@property (readonly) NSString * _Nullable detail __attribute__((swift_name("detail")));
@property (readonly) BOOL userVisible __attribute__((swift_name("userVisible")));
@end

__attribute__((swift_name("DigiyocoreJavaSerializable")))
@protocol DigiyoDigiyocoreJavaSerializable
@required
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreDiaModel")))
@interface DigiyoDigiyocoreDiaModel : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithDiaId:(NSString * _Nullable)diaId type:(NSString * _Nullable)type status:(NSString * _Nullable)status meta:(DigiyoDigiyocoreMetaModel * _Nullable)meta inData:(NSDictionary<NSString *, DigiyoDigiyocoreDataRequireModel *> * _Nullable)inData task:(DigiyoDigiyocoreTaskModel * _Nullable)task __attribute__((swift_name("init(diaId:type:status:meta:inData:task:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreDiaModelCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreDiaModel *)doCopyDiaId:(NSString * _Nullable)diaId type:(NSString * _Nullable)type status:(NSString * _Nullable)status meta:(DigiyoDigiyocoreMetaModel * _Nullable)meta inData:(NSDictionary<NSString *, DigiyoDigiyocoreDataRequireModel *> * _Nullable)inData task:(DigiyoDigiyocoreTaskModel * _Nullable)task __attribute__((swift_name("doCopy(diaId:type:status:meta:inData:task:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="dia_id")
*/
@property (readonly) NSString * _Nullable diaId __attribute__((swift_name("diaId")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="in_data")
*/
@property (readonly) NSDictionary<NSString *, DigiyoDigiyocoreDataRequireModel *> * _Nullable inData __attribute__((swift_name("inData")));
@property (readonly) NSArray<DigiyoDigiyocoreInDataEntryModel *> *inDataList __attribute__((swift_name("inDataList")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="meta")
*/
@property (readonly) DigiyoDigiyocoreMetaModel * _Nullable meta __attribute__((swift_name("meta")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="status")
*/
@property (readonly) NSString * _Nullable status __attribute__((swift_name("status")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="task")
*/
@property (readonly) DigiyoDigiyocoreTaskModel * _Nullable task __attribute__((swift_name("task")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="type")
*/
@property (readonly) NSString * _Nullable type __attribute__((swift_name("type")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreInDataEntryModel")))
@interface DigiyoDigiyocoreInDataEntryModel : DigiyoBase
- (instancetype)initWithName:(NSString * _Nullable)name data:(DigiyoDigiyocoreDataRequireModel * _Nullable)data __attribute__((swift_name("init(name:data:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreInDataEntryModelCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreInDataEntryModel *)doCopyName:(NSString * _Nullable)name data:(DigiyoDigiyocoreDataRequireModel * _Nullable)data __attribute__((swift_name("doCopy(name:data:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DigiyoDigiyocoreDataRequireModel * _Nullable data __attribute__((swift_name("data")));
@property (readonly) NSString * _Nullable name __attribute__((swift_name("name")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreLiveValidationOptions")))
@interface DigiyoDigiyocoreLiveValidationOptions : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithFaceEyeCheck:(BOOL)faceEyeCheck faceSmileCheck:(BOOL)faceSmileCheck idOnFaceCheck:(BOOL)idOnFaceCheck fingerCheck:(BOOL)fingerCheck __attribute__((swift_name("init(faceEyeCheck:faceSmileCheck:idOnFaceCheck:fingerCheck:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreLiveValidationOptionsCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreLiveValidationOptions *)doCopyFaceEyeCheck:(BOOL)faceEyeCheck faceSmileCheck:(BOOL)faceSmileCheck idOnFaceCheck:(BOOL)idOnFaceCheck fingerCheck:(BOOL)fingerCheck __attribute__((swift_name("doCopy(faceEyeCheck:faceSmileCheck:idOnFaceCheck:fingerCheck:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSDictionary<NSString *, DigiyoBoolean *> *)toMap __attribute__((swift_name("toMap()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="face_eye_check")
*/
@property (readonly) BOOL faceEyeCheck __attribute__((swift_name("faceEyeCheck")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="face_smile_check")
*/
@property (readonly) BOOL faceSmileCheck __attribute__((swift_name("faceSmileCheck")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="finger_check")
*/
@property (readonly) BOOL fingerCheck __attribute__((swift_name("fingerCheck")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="id_on_face_check")
*/
@property (readonly) BOOL idOnFaceCheck __attribute__((swift_name("idOnFaceCheck")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface DigiyoKotlinThrowable : DigiyoBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DigiyoKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DigiyoKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (DigiyoKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DigiyoKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface DigiyoKotlinException : DigiyoKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DigiyoKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DigiyoKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface DigiyoKotlinRuntimeException : DigiyoKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DigiyoKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DigiyoKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface DigiyoKotlinIllegalStateException : DigiyoKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DigiyoKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DigiyoKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface DigiyoKotlinCancellationException : DigiyoKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DigiyoKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DigiyoKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface DigiyoKotlinByteArray : DigiyoBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(DigiyoByte *(^)(DigiyoInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (DigiyoKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinPair")))
@interface DigiyoKotlinPair<__covariant A, __covariant B> : DigiyoBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("init(first:second:)"))) __attribute__((objc_designated_initializer));
- (DigiyoKotlinPair<A, B> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("doCopy(first:second:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface DigiyoKotlinEnumCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface DigiyoKotlinArray<T> : DigiyoBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(DigiyoInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<DigiyoKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ui_geometryRect.Companion")))
@interface DigiyoUi_geometryRectCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoUi_geometryRectCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
@property (readonly) DigiyoUi_geometryRect *Zero __attribute__((swift_name("Zero")));
@end

__attribute__((swift_name("KotlinCValuesRef")))
@interface DigiyoKotlinCValuesRef<T> : DigiyoBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void *)getPointerScope:(DigiyoKotlinAutofreeScope *)scope __attribute__((swift_name("getPointer(scope:)")));
@end

__attribute__((swift_name("KotlinCValues")))
@interface DigiyoKotlinCValues<T> : DigiyoKotlinCValuesRef<T>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (void *)getPointerScope:(DigiyoKotlinAutofreeScope *)scope __attribute__((swift_name("getPointer(scope:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (void *)placePlacement:(void *)placement __attribute__((swift_name("place(placement:)")));
@property (readonly) int32_t align __attribute__((swift_name("align")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("KotlinCValue")))
@interface DigiyoKotlinCValue<T> : DigiyoKotlinCValues<T>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Immutable
*/
__attribute__((swift_name("LibraryResource")))
@interface DigiyoLibraryResource : DigiyoBase
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Immutable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LibraryDrawableResource")))
@interface DigiyoLibraryDrawableResource : DigiyoLibraryResource
- (instancetype)initWithId:(NSString *)id items:(NSSet<DigiyoLibraryResourceItem *> *)items __attribute__((swift_name("init(id:items:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Immutable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LibraryFontResource")))
@interface DigiyoLibraryFontResource : DigiyoLibraryResource
- (instancetype)initWithId:(NSString *)id items:(NSSet<DigiyoLibraryResourceItem *> *)items __attribute__((swift_name("init(id:items:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Immutable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LibraryPluralStringResource")))
@interface DigiyoLibraryPluralStringResource : DigiyoLibraryResource
- (instancetype)initWithId:(NSString *)id key:(NSString *)key items:(NSSet<DigiyoLibraryResourceItem *> *)items __attribute__((swift_name("init(id:key:items:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Immutable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LibraryStringArrayResource")))
@interface DigiyoLibraryStringArrayResource : DigiyoLibraryResource
- (instancetype)initWithId:(NSString *)id key:(NSString *)key items:(NSSet<DigiyoLibraryResourceItem *> *)items __attribute__((swift_name("init(id:key:items:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Immutable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LibraryStringResource")))
@interface DigiyoLibraryStringResource : DigiyoLibraryResource
- (instancetype)initWithId:(NSString *)id key:(NSString *)key items:(NSSet<DigiyoLibraryResourceItem *> *)items __attribute__((swift_name("init(id:key:items:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Immutable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UiImageVector")))
@interface DigiyoUiImageVector : DigiyoBase
@property (class, readonly, getter=companion) DigiyoUiImageVectorCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
@property (readonly) BOOL autoMirror __attribute__((swift_name("autoMirror")));
@property (readonly) float defaultHeight __attribute__((swift_name("defaultHeight")));
@property (readonly) float defaultWidth __attribute__((swift_name("defaultWidth")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) DigiyoUiVectorGroup *root __attribute__((swift_name("root")));
@property (readonly) int32_t tintBlendMode __attribute__((swift_name("tintBlendMode")));
@property (readonly) uint64_t tintColor __attribute__((swift_name("tintColor")));
@property (readonly) float viewportHeight __attribute__((swift_name("viewportHeight")));
@property (readonly) float viewportWidth __attribute__((swift_name("viewportWidth")));
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
__attribute__((swift_name("UiModifier")))
@protocol DigiyoUiModifier
@required
- (BOOL)allPredicate:(DigiyoBoolean *(^)(id<DigiyoUiModifierElement>))predicate __attribute__((swift_name("all(predicate:)")));
- (BOOL)anyPredicate:(DigiyoBoolean *(^)(id<DigiyoUiModifierElement>))predicate __attribute__((swift_name("any(predicate:)")));
- (id _Nullable)foldInInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<DigiyoUiModifierElement>))operation __attribute__((swift_name("foldIn(initial:operation:)")));
- (id _Nullable)foldOutInitial:(id _Nullable)initial operation:(id _Nullable (^)(id<DigiyoUiModifierElement>, id _Nullable))operation __attribute__((swift_name("foldOut(initial:operation:)")));
- (id<DigiyoUiModifier>)thenOther:(id<DigiyoUiModifier>)other __attribute__((swift_name("then(other:)")));
@end

__attribute__((swift_name("Ui_graphicsImageBitmap")))
@protocol DigiyoUi_graphicsImageBitmap
@required
- (void)prepareToDraw __attribute__((swift_name("prepareToDraw()")));
- (void)readPixelsBuffer:(DigiyoKotlinIntArray *)buffer startX:(int32_t)startX startY:(int32_t)startY width:(int32_t)width height:(int32_t)height bufferOffset:(int32_t)bufferOffset stride:(int32_t)stride __attribute__((swift_name("readPixels(buffer:startX:startY:width:height:bufferOffset:stride:)")));
@property (readonly) DigiyoUi_graphicsColorSpace *colorSpace __attribute__((swift_name("colorSpace")));
@property (readonly) int32_t config __attribute__((swift_name("config")));
@property (readonly) BOOL hasAlpha __attribute__((swift_name("hasAlpha")));
@property (readonly) int32_t height __attribute__((swift_name("height")));
@property (readonly) int32_t width __attribute__((swift_name("width")));
@end

__attribute__((swift_name("KotlinIterable")))
@protocol DigiyoKotlinIterable
@required
- (id<DigiyoKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end

__attribute__((swift_name("KotlinIntProgression")))
@interface DigiyoKotlinIntProgression : DigiyoBase <DigiyoKotlinIterable>
@property (class, readonly, getter=companion) DigiyoKotlinIntProgressionCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (DigiyoKotlinIntIterator *)iterator __attribute__((swift_name("iterator()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t first __attribute__((swift_name("first")));
@property (readonly) int32_t last __attribute__((swift_name("last")));
@property (readonly) int32_t step __attribute__((swift_name("step")));
@end

__attribute__((swift_name("KotlinClosedRange")))
@protocol DigiyoKotlinClosedRange
@required
- (BOOL)containsValue:(id)value __attribute__((swift_name("contains(value:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
@property (readonly) id endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly) id start __attribute__((swift_name("start")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
__attribute__((swift_name("KotlinOpenEndRange")))
@protocol DigiyoKotlinOpenEndRange
@required
- (BOOL)containsValue_:(id)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
@property (readonly) id endExclusive __attribute__((swift_name("endExclusive")));
@property (readonly) id start __attribute__((swift_name("start")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntRange")))
@interface DigiyoKotlinIntRange : DigiyoKotlinIntProgression <DigiyoKotlinClosedRange, DigiyoKotlinOpenEndRange>
- (instancetype)initWithStart:(int32_t)start endInclusive:(int32_t)endInclusive __attribute__((swift_name("init(start:endInclusive:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoKotlinIntRangeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsValue:(DigiyoInt *)value __attribute__((swift_name("contains(value:)")));
- (BOOL)containsValue_:(DigiyoInt *)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
@property (readonly) DigiyoInt *endExclusive __attribute__((swift_name("endExclusive"))) __attribute__((deprecated("Can throw an exception when it's impossible to represent the value with Int type, for example, when the range includes MAX_VALUE. It's recommended to use 'endInclusive' property that doesn't throw.")));
@property (readonly) DigiyoInt *endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly) DigiyoInt *start __attribute__((swift_name("start")));
@end

__attribute__((swift_name("Library_baseDeleteable")))
@protocol DigiyoLibrary_baseDeleteable
@required
@end

__attribute__((swift_name("Library_baseBaseRealmObject")))
@protocol DigiyoLibrary_baseBaseRealmObject <DigiyoLibrary_baseDeleteable>
@required
@end

__attribute__((swift_name("Library_baseTypedRealmObject")))
@protocol DigiyoLibrary_baseTypedRealmObject <DigiyoLibrary_baseBaseRealmObject>
@required
@end

__attribute__((swift_name("Library_baseRealmObject")))
@protocol DigiyoLibrary_baseRealmObject <DigiyoLibrary_baseTypedRealmObject>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreDigiYoConfigEntity")))
@interface DigiyoDigiyocoreDigiYoConfigEntity : DigiyoBase <DigiyoLibrary_baseRealmObject>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithBaseUrl:(NSString * _Nullable)baseUrl apiKey:(NSString * _Nullable)apiKey requestTimeoutMillis:(DigiyoLong * _Nullable)requestTimeoutMillis __attribute__((swift_name("init(baseUrl:apiKey:requestTimeoutMillis:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreDigiYoConfigEntityCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (DigiyoDigiyocoreDigiYoConfig *)toModel __attribute__((swift_name("toModel()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable apiKey __attribute__((swift_name("apiKey")));
@property NSString * _Nullable baseUrl __attribute__((swift_name("baseUrl")));
@property DigiyoLong * _Nullable requestTimeoutInMillis __attribute__((swift_name("requestTimeoutInMillis")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreDigiYoError.Companion")))
@interface DigiyoDigiyocoreDigiYoErrorCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreDigiYoErrorCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreMetaModel")))
@interface DigiyoDigiyocoreMetaModel : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithCreated:(NSString * _Nullable)created updated:(NSString * _Nullable)updated partner:(DigiyoDigiyocorePartnerModel * _Nullable)partner __attribute__((swift_name("init(created:updated:partner:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreMetaModelCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreMetaModel *)doCopyCreated:(NSString * _Nullable)created updated:(NSString * _Nullable)updated partner:(DigiyoDigiyocorePartnerModel * _Nullable)partner __attribute__((swift_name("doCopy(created:updated:partner:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="created")
*/
@property (readonly) NSString * _Nullable created __attribute__((swift_name("created")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="partner")
*/
@property (readonly) DigiyoDigiyocorePartnerModel * _Nullable partner __attribute__((swift_name("partner")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="updated")
*/
@property (readonly) NSString * _Nullable updated __attribute__((swift_name("updated")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreDataRequireModel")))
@interface DigiyoDigiyocoreDataRequireModel : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithValue:(NSString * _Nullable)value contentType:(NSString * _Nullable)contentType config:(DigiyoDigiyocoreInDataConfigModel * _Nullable)config __attribute__((swift_name("init(value:contentType:config:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreDataRequireModelCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreDataRequireModel *)doCopyValue:(NSString * _Nullable)value contentType:(NSString * _Nullable)contentType config:(DigiyoDigiyocoreInDataConfigModel * _Nullable)config __attribute__((swift_name("doCopy(value:contentType:config:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="config")
*/
@property (readonly) DigiyoDigiyocoreInDataConfigModel * _Nullable config __attribute__((swift_name("config")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="content_type")
*/
@property (readonly) NSString * _Nullable contentType __attribute__((swift_name("contentType")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="value")
*/
@property (readonly) NSString * _Nullable value __attribute__((swift_name("value")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreTaskModel")))
@interface DigiyoDigiyocoreTaskModel : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithResult:(DigiyoDigiyocoreResultModel * _Nullable)result __attribute__((swift_name("init(result:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreTaskModelCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreTaskModel *)doCopyResult:(DigiyoDigiyocoreResultModel * _Nullable)result __attribute__((swift_name("doCopy(result:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="result")
*/
@property (readonly) DigiyoDigiyocoreResultModel * _Nullable result __attribute__((swift_name("result")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreDiaModel.Companion")))
@interface DigiyoDigiyocoreDiaModelCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreDiaModelCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreInDataEntryModel.Companion")))
@interface DigiyoDigiyocoreInDataEntryModelCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreInDataEntryModelCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreLiveValidationOptions.Companion")))
@interface DigiyoDigiyocoreLiveValidationOptionsCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreLiveValidationOptionsCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol DigiyoKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface DigiyoKotlinByteIterator : DigiyoBase <DigiyoKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (DigiyoByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

__attribute__((swift_name("KotlinDeferScope")))
@interface DigiyoKotlinDeferScope : DigiyoBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)deferBlock:(void (^)(void))block __attribute__((swift_name("defer(block:)")));
@end

__attribute__((swift_name("KotlinNativePlacement")))
@protocol DigiyoKotlinNativePlacement
@required
- (void *)doAllocSize:(int32_t)size align:(int32_t)align __attribute__((swift_name("doAlloc(size:align:)")));
- (void *)doAllocSize:(int64_t)size align_:(int32_t)align __attribute__((swift_name("doAlloc(size:align_:)")));
@end

__attribute__((swift_name("KotlinAutofreeScope")))
@interface DigiyoKotlinAutofreeScope : DigiyoKotlinDeferScope <DigiyoKotlinNativePlacement>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void *)doAllocSize:(int64_t)size align_:(int32_t)align __attribute__((swift_name("doAlloc(size:align_:)")));
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Immutable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LibraryResourceItem")))
@interface DigiyoLibraryResourceItem : DigiyoBase
- (instancetype)initWithQualifiers:(NSSet<id<DigiyoLibraryQualifier>> *)qualifiers path:(NSString *)path offset:(int64_t)offset size:(int64_t)size __attribute__((swift_name("init(qualifiers:path:offset:size:)"))) __attribute__((objc_designated_initializer));
- (DigiyoLibraryResourceItem *)doCopyQualifiers:(NSSet<id<DigiyoLibraryQualifier>> *)qualifiers path:(NSString *)path offset:(int64_t)offset size:(int64_t)size __attribute__((swift_name("doCopy(qualifiers:path:offset:size:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UiImageVector.Companion")))
@interface DigiyoUiImageVectorCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoUiImageVectorCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("UiVectorNode")))
@interface DigiyoUiVectorNode : DigiyoBase
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Immutable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UiVectorGroup")))
@interface DigiyoUiVectorGroup : DigiyoUiVectorNode <DigiyoKotlinIterable>
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (DigiyoUiVectorNode *)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (id<DigiyoKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@property (readonly) NSArray<DigiyoUi_graphicsPathNode *> *clipPathData __attribute__((swift_name("clipPathData")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) float pivotX __attribute__((swift_name("pivotX")));
@property (readonly) float pivotY __attribute__((swift_name("pivotY")));
@property (readonly) float rotation __attribute__((swift_name("rotation")));
@property (readonly) float scaleX __attribute__((swift_name("scaleX")));
@property (readonly) float scaleY __attribute__((swift_name("scaleY")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@property (readonly) float translationX __attribute__((swift_name("translationX")));
@property (readonly) float translationY __attribute__((swift_name("translationY")));
@end

__attribute__((swift_name("UiModifierElement")))
@protocol DigiyoUiModifierElement <DigiyoUiModifier>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntArray")))
@interface DigiyoKotlinIntArray : DigiyoBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(DigiyoInt *(^)(DigiyoInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int32_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (DigiyoKotlinIntIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int32_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("Ui_graphicsColorSpace")))
@interface DigiyoUi_graphicsColorSpace : DigiyoBase
- (instancetype)initWithName:(NSString *)name model:(int64_t)model __attribute__((swift_name("init(name:model:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @note annotations
 *   androidx.annotation.Size(min=3.toLong())
 * @param v annotations androidx.annotation.Size(min=3.toLong())
*/
- (DigiyoKotlinFloatArray *)fromXyzV:(DigiyoKotlinFloatArray *)v __attribute__((swift_name("fromXyz(v:)")));

/**
 * @note annotations
 *   androidx.annotation.Size(min=3.toLong())
*/
- (DigiyoKotlinFloatArray *)fromXyzX:(float)x y:(float)y z:(float)z __attribute__((swift_name("fromXyz(x:y:z:)")));

/**
 * @param component annotations androidx.annotation.IntRange(from=0.toLong(), to=3.toLong())
*/
- (float)getMaxValueComponent:(int32_t)component __attribute__((swift_name("getMaxValue(component:)")));

/**
 * @param component annotations androidx.annotation.IntRange(from=0.toLong(), to=3.toLong())
*/
- (float)getMinValueComponent:(int32_t)component __attribute__((swift_name("getMinValue(component:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   androidx.annotation.Size(min=3.toLong())
 * @param v annotations androidx.annotation.Size(min=3.toLong())
*/
- (DigiyoKotlinFloatArray *)toXyzV:(DigiyoKotlinFloatArray *)v __attribute__((swift_name("toXyz(v:)")));

/**
 * @note annotations
 *   androidx.annotation.Size(value=3.toLong())
*/
- (DigiyoKotlinFloatArray *)toXyzR:(float)r g:(float)g b:(float)b __attribute__((swift_name("toXyz(r:g:b:)")));
@property (readonly) int32_t componentCount __attribute__((swift_name("componentCount")));
@property (readonly) BOOL isSrgb __attribute__((swift_name("isSrgb")));
@property (readonly) BOOL isWideGamut __attribute__((swift_name("isWideGamut")));
@property (readonly) int64_t model __attribute__((swift_name("model")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntProgression.Companion")))
@interface DigiyoKotlinIntProgressionCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoKotlinIntProgressionCompanion *shared __attribute__((swift_name("shared")));
- (DigiyoKotlinIntProgression *)fromClosedRangeRangeStart:(int32_t)rangeStart rangeEnd:(int32_t)rangeEnd step:(int32_t)step __attribute__((swift_name("fromClosedRange(rangeStart:rangeEnd:step:)")));
@end

__attribute__((swift_name("KotlinIntIterator")))
@interface DigiyoKotlinIntIterator : DigiyoBase <DigiyoKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (DigiyoInt *)next __attribute__((swift_name("next()")));
- (int32_t)nextInt __attribute__((swift_name("nextInt()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntRange.Companion")))
@interface DigiyoKotlinIntRangeCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoKotlinIntRangeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DigiyoKotlinIntRange *EMPTY __attribute__((swift_name("EMPTY")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreDigiYoConfigEntity.Companion")))
@interface DigiyoDigiyocoreDigiYoConfigEntityCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreDigiYoConfigEntityCompanion *shared __attribute__((swift_name("shared")));
- (id)io_realm_kotlin_newInstance __attribute__((swift_name("io_realm_kotlin_newInstance()")));
- (id)io_realm_kotlin_schema __attribute__((swift_name("io_realm_kotlin_schema()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol DigiyoKotlinx_serialization_coreSerializationStrategy
@required
- (void)serializeEncoder:(id<DigiyoKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DigiyoKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol DigiyoKotlinx_serialization_coreDeserializationStrategy
@required
- (id _Nullable)deserializeDecoder:(id<DigiyoKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
@property (readonly) id<DigiyoKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol DigiyoKotlinx_serialization_coreKSerializer <DigiyoKotlinx_serialization_coreSerializationStrategy, DigiyoKotlinx_serialization_coreDeserializationStrategy>
@required
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocorePartnerModel")))
@interface DigiyoDigiyocorePartnerModel : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithPartnerId:(DigiyoInt * _Nullable)partnerId name:(NSString * _Nullable)name __attribute__((swift_name("init(partnerId:name:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocorePartnerModelCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocorePartnerModel *)doCopyPartnerId:(DigiyoInt * _Nullable)partnerId name:(NSString * _Nullable)name __attribute__((swift_name("doCopy(partnerId:name:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="name")
*/
@property (readonly) NSString * _Nullable name __attribute__((swift_name("name")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="partner_id")
*/
@property (readonly) DigiyoInt * _Nullable partnerId __attribute__((swift_name("partnerId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreMetaModel.Companion")))
@interface DigiyoDigiyocoreMetaModelCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreMetaModelCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreInDataConfigModel")))
@interface DigiyoDigiyocoreInDataConfigModel : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithVersusArray:(NSArray<DigiyoInt *> *)versusArray liveValidations:(NSDictionary<NSString *, DigiyoBoolean *> * _Nullable)liveValidations __attribute__((swift_name("init(versusArray:liveValidations:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreInDataConfigModelCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreInDataConfigModel *)doCopyVersusArray:(NSArray<DigiyoInt *> *)versusArray liveValidations:(NSDictionary<NSString *, DigiyoBoolean *> * _Nullable)liveValidations __attribute__((swift_name("doCopy(versusArray:liveValidations:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="live_validations")
*/
@property (readonly) NSDictionary<NSString *, DigiyoBoolean *> * _Nullable liveValidations __attribute__((swift_name("liveValidations")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="versus_array")
*/
@property (readonly) NSArray<DigiyoInt *> *versusArray __attribute__((swift_name("versusArray")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreDataRequireModel.Companion")))
@interface DigiyoDigiyocoreDataRequireModelCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreDataRequireModelCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreResultModel")))
@interface DigiyoDigiyocoreResultModel : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithFlowId:(NSString * _Nullable)flowId scores:(DigiyoDigiyocoreScoresModel * _Nullable)scores idInfo:(DigiyoDigiyocoreIdInfoModel * _Nullable)idInfo thresholds:(DigiyoDigiyocoreScoresModel * _Nullable)thresholds videoArray:(NSMutableArray<DigiyoInt *> *)videoArray polDetails:(DigiyoDigiyocorePolDetails * _Nullable)polDetails cisefDetails:(DigiyoDigiyocoreCisefDetails * _Nullable)cisefDetails idNumberInput:(NSString * _Nullable)idNumberInput enrolledUserId:(DigiyoLong * _Nullable)enrolledUserId validationFlags:(DigiyoDigiyocoreValidationFlags * _Nullable)validationFlags conductorDetails:(DigiyoDigiyocoreConductorDetails * _Nullable)conductorDetails __attribute__((swift_name("init(flowId:scores:idInfo:thresholds:videoArray:polDetails:cisefDetails:idNumberInput:enrolledUserId:validationFlags:conductorDetails:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreResultModelCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreResultModel *)doCopyFlowId:(NSString * _Nullable)flowId scores:(DigiyoDigiyocoreScoresModel * _Nullable)scores idInfo:(DigiyoDigiyocoreIdInfoModel * _Nullable)idInfo thresholds:(DigiyoDigiyocoreScoresModel * _Nullable)thresholds videoArray:(NSMutableArray<DigiyoInt *> *)videoArray polDetails:(DigiyoDigiyocorePolDetails * _Nullable)polDetails cisefDetails:(DigiyoDigiyocoreCisefDetails * _Nullable)cisefDetails idNumberInput:(NSString * _Nullable)idNumberInput enrolledUserId:(DigiyoLong * _Nullable)enrolledUserId validationFlags:(DigiyoDigiyocoreValidationFlags * _Nullable)validationFlags conductorDetails:(DigiyoDigiyocoreConductorDetails * _Nullable)conductorDetails __attribute__((swift_name("doCopy(flowId:scores:idInfo:thresholds:videoArray:polDetails:cisefDetails:idNumberInput:enrolledUserId:validationFlags:conductorDetails:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="cisef_details")
*/
@property (readonly) DigiyoDigiyocoreCisefDetails * _Nullable cisefDetails __attribute__((swift_name("cisefDetails")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="conductor_details")
*/
@property (readonly) DigiyoDigiyocoreConductorDetails * _Nullable conductorDetails __attribute__((swift_name("conductorDetails")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="enrolled_user_id")
*/
@property (readonly) DigiyoLong * _Nullable enrolledUserId __attribute__((swift_name("enrolledUserId")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="flow_id")
*/
@property (readonly) NSString * _Nullable flowId __attribute__((swift_name("flowId")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="id_info")
*/
@property (readonly) DigiyoDigiyocoreIdInfoModel * _Nullable idInfo __attribute__((swift_name("idInfo")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="id_number_input")
*/
@property (readonly) NSString * _Nullable idNumberInput __attribute__((swift_name("idNumberInput")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="pol_details")
*/
@property (readonly) DigiyoDigiyocorePolDetails * _Nullable polDetails __attribute__((swift_name("polDetails")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="scores")
*/
@property (readonly) DigiyoDigiyocoreScoresModel * _Nullable scores __attribute__((swift_name("scores")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="thresholds")
*/
@property (readonly) DigiyoDigiyocoreScoresModel * _Nullable thresholds __attribute__((swift_name("thresholds")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="validation_flags")
*/
@property (readonly) DigiyoDigiyocoreValidationFlags * _Nullable validationFlags __attribute__((swift_name("validationFlags")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="video_array")
*/
@property (readonly) NSMutableArray<DigiyoInt *> *videoArray __attribute__((swift_name("videoArray")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreTaskModel.Companion")))
@interface DigiyoDigiyocoreTaskModelCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreTaskModelCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((swift_name("LibraryQualifier")))
@protocol DigiyoLibraryQualifier
@required
@end


/**
 * @note annotations
 *   androidx.compose.runtime.Immutable
*/
__attribute__((swift_name("Ui_graphicsPathNode")))
@interface DigiyoUi_graphicsPathNode : DigiyoBase
@property (readonly) BOOL isCurve __attribute__((swift_name("isCurve")));
@property (readonly) BOOL isQuad __attribute__((swift_name("isQuad")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinFloatArray")))
@interface DigiyoKotlinFloatArray : DigiyoBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(DigiyoFloat *(^)(DigiyoInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (float)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (DigiyoKotlinFloatIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(float)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol DigiyoKotlinx_serialization_coreEncoder
@required
- (id<DigiyoKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));
- (id<DigiyoKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));
- (void)encodeEnumEnumDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));
- (id<DigiyoKotlinx_serialization_coreEncoder>)encodeInlineDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("encodeInline(descriptor:)")));
- (void)encodeIntValue:(int32_t)value __attribute__((swift_name("encodeInt(value:)")));
- (void)encodeLongValue:(int64_t)value __attribute__((swift_name("encodeLong(value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNotNullMark __attribute__((swift_name("encodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNull __attribute__((swift_name("encodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableValueSerializer:(id<DigiyoKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));
- (void)encodeSerializableValueSerializer:(id<DigiyoKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));
@property (readonly) DigiyoKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol DigiyoKotlinx_serialization_coreSerialDescriptor
@required

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSArray<id<DigiyoKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<DigiyoKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSArray<id<DigiyoKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) DigiyoKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol DigiyoKotlinx_serialization_coreDecoder
@required
- (id<DigiyoKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));
- (int32_t)decodeEnumEnumDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));
- (id<DigiyoKotlinx_serialization_coreDecoder>)decodeInlineDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeInline(descriptor:)")));
- (int32_t)decodeInt __attribute__((swift_name("decodeInt()")));
- (int64_t)decodeLong __attribute__((swift_name("decodeLong()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeNotNullMark __attribute__((swift_name("decodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (DigiyoKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<DigiyoKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));
- (id _Nullable)decodeSerializableValueDeserializer:(id<DigiyoKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));
@property (readonly) DigiyoKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocorePartnerModel.Companion")))
@interface DigiyoDigiyocorePartnerModelCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocorePartnerModelCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreInDataConfigModel.Companion")))
@interface DigiyoDigiyocoreInDataConfigModelCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreInDataConfigModelCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreScoresModel")))
@interface DigiyoDigiyocoreScoresModel : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithVideo:(NSString * _Nullable)video globalScore:(NSString * _Nullable)globalScore selfieVsId:(NSString * _Nullable)selfieVsId idExtraction:(NSString * _Nullable)idExtraction cisefOcrScore:(NSString * _Nullable)cisefOcrScore cisefFaceScore:(NSString * _Nullable)cisefFaceScore videoFrameVsId:(NSString * _Nullable)videoFrameVsId selfieVsVideoFrame:(NSString * _Nullable)selfieVsVideoFrame __attribute__((swift_name("init(video:globalScore:selfieVsId:idExtraction:cisefOcrScore:cisefFaceScore:videoFrameVsId:selfieVsVideoFrame:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreScoresModelCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreScoresModel *)doCopyVideo:(NSString * _Nullable)video globalScore:(NSString * _Nullable)globalScore selfieVsId:(NSString * _Nullable)selfieVsId idExtraction:(NSString * _Nullable)idExtraction cisefOcrScore:(NSString * _Nullable)cisefOcrScore cisefFaceScore:(NSString * _Nullable)cisefFaceScore videoFrameVsId:(NSString * _Nullable)videoFrameVsId selfieVsVideoFrame:(NSString * _Nullable)selfieVsVideoFrame __attribute__((swift_name("doCopy(video:globalScore:selfieVsId:idExtraction:cisefOcrScore:cisefFaceScore:videoFrameVsId:selfieVsVideoFrame:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="cisef_face_score")
*/
@property (readonly) NSString * _Nullable cisefFaceScore __attribute__((swift_name("cisefFaceScore")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="cisef_ocr_score")
*/
@property (readonly) NSString * _Nullable cisefOcrScore __attribute__((swift_name("cisefOcrScore")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="global_score")
*/
@property (readonly) NSString * _Nullable globalScore __attribute__((swift_name("globalScore")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="id_extraction")
*/
@property (readonly) NSString * _Nullable idExtraction __attribute__((swift_name("idExtraction")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="selfie_vs_id")
*/
@property (readonly) NSString * _Nullable selfieVsId __attribute__((swift_name("selfieVsId")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="selfie_vs_video_frame")
*/
@property (readonly) NSString * _Nullable selfieVsVideoFrame __attribute__((swift_name("selfieVsVideoFrame")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="video")
*/
@property (readonly) NSString * _Nullable video __attribute__((swift_name("video")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="video_frame_vs_id")
*/
@property (readonly) NSString * _Nullable videoFrameVsId __attribute__((swift_name("videoFrameVsId")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreIdInfoModel")))
@interface DigiyoDigiyocoreIdInfoModel : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithIc:(NSString * _Nullable)ic sex:(NSString * _Nullable)sex location:(NSString * _Nullable)location fullName:(NSString * _Nullable)fullName idNumber:(NSString * _Nullable)idNumber issueDate:(NSString * _Nullable)issueDate lastNames:(NSString * _Nullable)lastNames firstNames:(NSString * _Nullable)firstNames nationality:(NSString * _Nullable)nationality generalInfo:(NSString * _Nullable)generalInfo dateOfBirth:(NSString * _Nullable)dateOfBirth maritalStatus:(NSString * _Nullable)maritalStatus placeOfBirth:(NSString * _Nullable)placeOfBirth expirationDate:(NSString * _Nullable)expirationDate __attribute__((swift_name("init(ic:sex:location:fullName:idNumber:issueDate:lastNames:firstNames:nationality:generalInfo:dateOfBirth:maritalStatus:placeOfBirth:expirationDate:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreIdInfoModelCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreIdInfoModel *)doCopyIc:(NSString * _Nullable)ic sex:(NSString * _Nullable)sex location:(NSString * _Nullable)location fullName:(NSString * _Nullable)fullName idNumber:(NSString * _Nullable)idNumber issueDate:(NSString * _Nullable)issueDate lastNames:(NSString * _Nullable)lastNames firstNames:(NSString * _Nullable)firstNames nationality:(NSString * _Nullable)nationality generalInfo:(NSString * _Nullable)generalInfo dateOfBirth:(NSString * _Nullable)dateOfBirth maritalStatus:(NSString * _Nullable)maritalStatus placeOfBirth:(NSString * _Nullable)placeOfBirth expirationDate:(NSString * _Nullable)expirationDate __attribute__((swift_name("doCopy(ic:sex:location:fullName:idNumber:issueDate:lastNames:firstNames:nationality:generalInfo:dateOfBirth:maritalStatus:placeOfBirth:expirationDate:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="date_of_birth")
*/
@property (readonly) NSString * _Nullable dateOfBirth __attribute__((swift_name("dateOfBirth")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="expiration_date")
*/
@property (readonly) NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="first_names")
*/
@property (readonly) NSString * _Nullable firstNames __attribute__((swift_name("firstNames")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="full_name")
*/
@property (readonly) NSString * _Nullable fullName __attribute__((swift_name("fullName")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="general_info")
*/
@property (readonly) NSString * _Nullable generalInfo __attribute__((swift_name("generalInfo")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="ic")
*/
@property (readonly) NSString * _Nullable ic __attribute__((swift_name("ic")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="id_number")
*/
@property (readonly) NSString * _Nullable idNumber __attribute__((swift_name("idNumber")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="issue_date")
*/
@property (readonly) NSString * _Nullable issueDate __attribute__((swift_name("issueDate")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="last_names")
*/
@property (readonly) NSString * _Nullable lastNames __attribute__((swift_name("lastNames")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="location")
*/
@property (readonly) NSString * _Nullable location __attribute__((swift_name("location")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="marital_status")
*/
@property (readonly) NSString * _Nullable maritalStatus __attribute__((swift_name("maritalStatus")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="nationality")
*/
@property (readonly) NSString * _Nullable nationality __attribute__((swift_name("nationality")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="place_of_birth")
*/
@property (readonly) NSString * _Nullable placeOfBirth __attribute__((swift_name("placeOfBirth")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="sex")
*/
@property (readonly) NSString * _Nullable sex __attribute__((swift_name("sex")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocorePolDetails")))
@interface DigiyoDigiyocorePolDetails : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithEyeStatus:(NSString * _Nullable)eyeStatus smileFound:(DigiyoBoolean * _Nullable)smileFound fingersRead:(NSArray<DigiyoLong *> *)fingersRead videoIsReal:(DigiyoBoolean * _Nullable)videoIsReal faceDirection:(NSString * _Nullable)faceDirection documentFoundOnSelfie:(DigiyoBoolean * _Nullable)documentFoundOnSelfie fingersRequirement:(NSArray<DigiyoLong *> *)fingersRequirement documentPhotoMatchesSelfie:(DigiyoBoolean * _Nullable)documentPhotoMatchesSelfie __attribute__((swift_name("init(eyeStatus:smileFound:fingersRead:videoIsReal:faceDirection:documentFoundOnSelfie:fingersRequirement:documentPhotoMatchesSelfie:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocorePolDetailsCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocorePolDetails *)doCopyEyeStatus:(NSString * _Nullable)eyeStatus smileFound:(DigiyoBoolean * _Nullable)smileFound fingersRead:(NSArray<DigiyoLong *> *)fingersRead videoIsReal:(DigiyoBoolean * _Nullable)videoIsReal faceDirection:(NSString * _Nullable)faceDirection documentFoundOnSelfie:(DigiyoBoolean * _Nullable)documentFoundOnSelfie fingersRequirement:(NSArray<DigiyoLong *> *)fingersRequirement documentPhotoMatchesSelfie:(DigiyoBoolean * _Nullable)documentPhotoMatchesSelfie __attribute__((swift_name("doCopy(eyeStatus:smileFound:fingersRead:videoIsReal:faceDirection:documentFoundOnSelfie:fingersRequirement:documentPhotoMatchesSelfie:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="ci_found_on_selfie")
*/
@property (readonly) DigiyoBoolean * _Nullable documentFoundOnSelfie __attribute__((swift_name("documentFoundOnSelfie")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="ci_photo_matches_selfie")
*/
@property (readonly) DigiyoBoolean * _Nullable documentPhotoMatchesSelfie __attribute__((swift_name("documentPhotoMatchesSelfie")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="eye_status")
*/
@property (readonly) NSString * _Nullable eyeStatus __attribute__((swift_name("eyeStatus")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="face_direction")
*/
@property (readonly) NSString * _Nullable faceDirection __attribute__((swift_name("faceDirection")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="fingers_read")
*/
@property (readonly) NSArray<DigiyoLong *> *fingersRead __attribute__((swift_name("fingersRead")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="fingers_requirement")
*/
@property (readonly) NSArray<DigiyoLong *> *fingersRequirement __attribute__((swift_name("fingersRequirement")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="smile_found")
*/
@property (readonly) DigiyoBoolean * _Nullable smileFound __attribute__((swift_name("smileFound")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="video_is_real")
*/
@property (readonly) DigiyoBoolean * _Nullable videoIsReal __attribute__((swift_name("videoIsReal")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreCisefDetails")))
@interface DigiyoDigiyocoreCisefDetails : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithLogin:(NSString * _Nullable)login status:(NSString * _Nullable)status validateOcr:(NSString * _Nullable)validateOcr validateSelfie:(NSString * _Nullable)validateSelfie openTransaction:(NSString * _Nullable)openTransaction closeTransaction:(NSString * _Nullable)closeTransaction __attribute__((swift_name("init(login:status:validateOcr:validateSelfie:openTransaction:closeTransaction:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreCisefDetailsCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreCisefDetails *)doCopyLogin:(NSString * _Nullable)login status:(NSString * _Nullable)status validateOcr:(NSString * _Nullable)validateOcr validateSelfie:(NSString * _Nullable)validateSelfie openTransaction:(NSString * _Nullable)openTransaction closeTransaction:(NSString * _Nullable)closeTransaction __attribute__((swift_name("doCopy(login:status:validateOcr:validateSelfie:openTransaction:closeTransaction:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="close_transaction")
*/
@property (readonly) NSString * _Nullable closeTransaction __attribute__((swift_name("closeTransaction")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="login")
*/
@property (readonly) NSString * _Nullable login __attribute__((swift_name("login")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="open_transaction")
*/
@property (readonly) NSString * _Nullable openTransaction __attribute__((swift_name("openTransaction")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="status")
*/
@property (readonly) NSString * _Nullable status __attribute__((swift_name("status")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="validate_ocr")
*/
@property (readonly) NSString * _Nullable validateOcr __attribute__((swift_name("validateOcr")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="validate_selfie")
*/
@property (readonly) NSString * _Nullable validateSelfie __attribute__((swift_name("validateSelfie")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreValidationFlags")))
@interface DigiyoDigiyocoreValidationFlags : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithIsDocumentReal:(DigiyoBoolean * _Nullable)isDocumentReal documentNotExpired:(DigiyoBoolean * _Nullable)documentNotExpired isSelfieReal:(DigiyoBoolean * _Nullable)isSelfieReal documentNumberVerified:(DigiyoBoolean * _Nullable)documentNumberVerified proofOfLifeApproved:(DigiyoBoolean * _Nullable)proofOfLifeApproved birthDateVerified:(DigiyoBoolean * _Nullable)birthDateVerified isDocumentTemporary:(DigiyoBoolean * _Nullable)isDocumentTemporary __attribute__((swift_name("init(isDocumentReal:documentNotExpired:isSelfieReal:documentNumberVerified:proofOfLifeApproved:birthDateVerified:isDocumentTemporary:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreValidationFlagsCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreValidationFlags *)doCopyIsDocumentReal:(DigiyoBoolean * _Nullable)isDocumentReal documentNotExpired:(DigiyoBoolean * _Nullable)documentNotExpired isSelfieReal:(DigiyoBoolean * _Nullable)isSelfieReal documentNumberVerified:(DigiyoBoolean * _Nullable)documentNumberVerified proofOfLifeApproved:(DigiyoBoolean * _Nullable)proofOfLifeApproved birthDateVerified:(DigiyoBoolean * _Nullable)birthDateVerified isDocumentTemporary:(DigiyoBoolean * _Nullable)isDocumentTemporary __attribute__((swift_name("doCopy(isDocumentReal:documentNotExpired:isSelfieReal:documentNumberVerified:proofOfLifeApproved:birthDateVerified:isDocumentTemporary:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DigiyoBoolean * _Nullable birthDateVerified __attribute__((swift_name("birthDateVerified")));
@property (readonly) DigiyoBoolean * _Nullable documentNotExpired __attribute__((swift_name("documentNotExpired")));
@property (readonly) DigiyoBoolean * _Nullable documentNumberVerified __attribute__((swift_name("documentNumberVerified")));
@property (readonly) DigiyoBoolean * _Nullable isDocumentReal __attribute__((swift_name("isDocumentReal")));
@property (readonly) DigiyoBoolean * _Nullable isDocumentTemporary __attribute__((swift_name("isDocumentTemporary")));
@property (readonly) DigiyoBoolean * _Nullable isSelfieReal __attribute__((swift_name("isSelfieReal")));
@property (readonly) DigiyoBoolean * _Nullable proofOfLifeApproved __attribute__((swift_name("proofOfLifeApproved")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreConductorDetails")))
@interface DigiyoDigiyocoreConductorDetails : DigiyoBase <DigiyoDigiyocoreJavaSerializable>
- (instancetype)initWithDiaID:(NSString *)diaID flowID:(NSString *)flowID clientFlow:(NSString *)clientFlow __attribute__((swift_name("init(diaID:flowID:clientFlow:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DigiyoDigiyocoreConductorDetailsCompanion *companion __attribute__((swift_name("companion")));
- (DigiyoDigiyocoreConductorDetails *)doCopyDiaID:(NSString *)diaID flowID:(NSString *)flowID clientFlow:(NSString *)clientFlow __attribute__((swift_name("doCopy(diaID:flowID:clientFlow:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="client_flow")
*/
@property (readonly) NSString *clientFlow __attribute__((swift_name("clientFlow")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="dia_id")
*/
@property (readonly) NSString *diaID __attribute__((swift_name("diaID")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="flow_id")
*/
@property (readonly) NSString *flowID __attribute__((swift_name("flowID")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreResultModel.Companion")))
@interface DigiyoDigiyocoreResultModelCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreResultModelCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((swift_name("KotlinFloatIterator")))
@interface DigiyoKotlinFloatIterator : DigiyoBase <DigiyoKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (DigiyoFloat *)next __attribute__((swift_name("next()")));
- (float)nextFloat __attribute__((swift_name("nextFloat()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol DigiyoKotlinx_serialization_coreCompositeEncoder
@required
- (void)encodeBooleanElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));
- (void)encodeByteElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));
- (void)encodeCharElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));
- (void)encodeDoubleElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));
- (void)encodeFloatElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));
- (id<DigiyoKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));
- (void)encodeIntElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));
- (void)encodeLongElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<DigiyoKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeSerializableElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<DigiyoKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeShortElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));
- (void)encodeStringElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));
- (void)endStructureDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));
@property (readonly) DigiyoKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface DigiyoKotlinx_serialization_coreSerializersModule : DigiyoBase

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)dumpToCollector:(id<DigiyoKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<DigiyoKotlinx_serialization_coreKSerializer> _Nullable)getContextualKClass:(id<DigiyoKotlinKClass>)kClass typeArgumentsSerializers:(NSArray<id<DigiyoKotlinx_serialization_coreKSerializer>> *)typeArgumentsSerializers __attribute__((swift_name("getContextual(kClass:typeArgumentsSerializers:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<DigiyoKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<DigiyoKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<DigiyoKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<DigiyoKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end

__attribute__((swift_name("KotlinAnnotation")))
@protocol DigiyoKotlinAnnotation
@required
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface DigiyoKotlinx_serialization_coreSerialKind : DigiyoBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol DigiyoKotlinx_serialization_coreCompositeDecoder
@required
- (BOOL)decodeBooleanElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));
- (int8_t)decodeByteElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));
- (unichar)decodeCharElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));
- (int32_t)decodeCollectionSizeDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));
- (double)decodeDoubleElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));
- (int32_t)decodeElementIndexDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));
- (float)decodeFloatElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));
- (id<DigiyoKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));
- (int32_t)decodeIntElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));
- (int64_t)decodeLongElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<DigiyoKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));
- (id _Nullable)decodeSerializableElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<DigiyoKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (int16_t)decodeShortElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));
- (NSString *)decodeStringElementDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));
- (void)endStructureDescriptor:(id<DigiyoKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
@property (readonly) DigiyoKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface DigiyoKotlinNothing : DigiyoBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreScoresModel.Companion")))
@interface DigiyoDigiyocoreScoresModelCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreScoresModelCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreIdInfoModel.Companion")))
@interface DigiyoDigiyocoreIdInfoModelCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreIdInfoModelCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocorePolDetails.Companion")))
@interface DigiyoDigiyocorePolDetailsCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocorePolDetailsCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreCisefDetails.Companion")))
@interface DigiyoDigiyocoreCisefDetailsCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreCisefDetailsCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreValidationFlags.Companion")))
@interface DigiyoDigiyocoreValidationFlagsCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreValidationFlagsCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DigiyocoreConductorDetails.Companion")))
@interface DigiyoDigiyocoreConductorDetailsCompanion : DigiyoBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DigiyoDigiyocoreConductorDetailsCompanion *shared __attribute__((swift_name("shared")));
- (id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol DigiyoKotlinx_serialization_coreSerializersModuleCollector
@required
- (void)contextualKClass:(id<DigiyoKotlinKClass>)kClass provider:(id<DigiyoKotlinx_serialization_coreKSerializer> (^)(NSArray<id<DigiyoKotlinx_serialization_coreKSerializer>> *))provider __attribute__((swift_name("contextual(kClass:provider:)")));
- (void)contextualKClass:(id<DigiyoKotlinKClass>)kClass serializer:(id<DigiyoKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));
- (void)polymorphicBaseClass:(id<DigiyoKotlinKClass>)baseClass actualClass:(id<DigiyoKotlinKClass>)actualClass actualSerializer:(id<DigiyoKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));
- (void)polymorphicDefaultBaseClass:(id<DigiyoKotlinKClass>)baseClass defaultDeserializerProvider:(id<DigiyoKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultDeserializerProvider:)"))) __attribute__((deprecated("Deprecated in favor of function with more precise name: polymorphicDefaultDeserializer")));
- (void)polymorphicDefaultDeserializerBaseClass:(id<DigiyoKotlinKClass>)baseClass defaultDeserializerProvider:(id<DigiyoKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefaultDeserializer(baseClass:defaultDeserializerProvider:)")));
- (void)polymorphicDefaultSerializerBaseClass:(id<DigiyoKotlinKClass>)baseClass defaultSerializerProvider:(id<DigiyoKotlinx_serialization_coreSerializationStrategy> _Nullable (^)(id))defaultSerializerProvider __attribute__((swift_name("polymorphicDefaultSerializer(baseClass:defaultSerializerProvider:)")));
@end

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol DigiyoKotlinKDeclarationContainer
@required
@end

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol DigiyoKotlinKAnnotatedElement
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinKClassifier")))
@protocol DigiyoKotlinKClassifier
@required
@end

__attribute__((swift_name("KotlinKClass")))
@protocol DigiyoKotlinKClass <DigiyoKotlinKDeclarationContainer, DigiyoKotlinKAnnotatedElement, DigiyoKotlinKClassifier>
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
