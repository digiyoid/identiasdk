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
            url: "https://github.com/digiyoid/identiasdk/releases/download/v1.2.1/DigiyoSwiftPackage.zip",
            checksum: "61eec065af9be7f4a1a428f75bf35ad93a1cdaf03bdc090f315611a76c7e4842",
        )
    ]
)