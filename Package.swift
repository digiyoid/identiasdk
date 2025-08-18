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
        ),
    ],
     targets: [
        .binaryTarget(
            name: "DigiyoSwiftPackage",
            url: "https://github.com/digiyoid/identiasdk-ios/releases/download/v1.0.18-patch1/DigiyoSwiftPackage.zip",
            checksum: "2b8f7c3650f61fcfbe767acca70f04c6c6f11c24450d6c8c89464e82d1a9ed27",
        )
    ]
)