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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.4.2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "153aa333a648d5700d8b61666e65a668b22d06d7372b8b2c3d60f968890067a4"
        )
    ]
)
