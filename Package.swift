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
            url: "https://github.com/digiyoid/identiasdk-ios/releases/download/v1.0.19/DigiyoSwiftPackage.zip",
            checksum: "a448a9f5c7612bd716d409ee1d3e8c4a00812e61cee6a9a849adc29c4f2dc43c",
        )
    ]
)