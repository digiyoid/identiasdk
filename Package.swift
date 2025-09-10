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
            url: "https://github.com/digiyoid/identiasdk-ios/releases/download/v1.1.3/DigiyoSwiftPackage.zip",
            checksum: "56f121266b7ea3306fdae89ae477189fa5bf8943650585c3a4cba024d063bf39",
        )
    ]
)