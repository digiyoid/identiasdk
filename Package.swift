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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.2.4/DigiyoSwiftPackage.xcframework.zip",
            checksum: "34b1cf7abeaed48d7f68e01db4bf9b9481f17addc4027dc082d64a456ea62b67"
        )
    ]
)
