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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.8.0/DigiyoSwiftPackage.xcframework.zip",
            checksum: "8d40c50522410d6c95ec638ce9bf9a8b2a1a53d12ae78da8a572b7cc9b84ac87"
        )
    ]
)
