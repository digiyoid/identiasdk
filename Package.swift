// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "DigiyoSwiftPackage",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "DigiyoSwiftPackage",
            targets: ["DigiyoSwiftPackage"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "DigiyoSwiftPackage",
            url:
                "https://github.com/digiyoid/identiasdk/releases/download/v2.1.1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "e915d8217860cfe5e582c073dfe82bb0f748d6eaa9dbbc5b18d2611973334e79"
        )
    ]
)
