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
            url: "https://github.com/digiyoid/identiasdk/releases/download/v1.2.2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "b4586f93bd8b7ef06d6136d410e630fb08b8d3fe423d1c48fb77876a80aeb796"
        )
    ]
)