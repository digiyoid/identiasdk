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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.5.0/DigiyoSwiftPackage.xcframework.zip",
            checksum: "2b7eda6a147b917f3a76f80a9c913ca2173e50db3df37f60f39a01ae768a043b"
        )
    ]
)
