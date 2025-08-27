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
            url: "https://github.com/digiyoid/identiasdk-ios/releases/download/v1.1.1/DigiyoSwiftPackage.zip",
            checksum: "5f37a403a8497a3088f5e72631ff0c1e5c6ab09d4a1068e91076025924075112",
        )
    ]
)