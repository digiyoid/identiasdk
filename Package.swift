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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.3.1-patch2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "f736b81c271e5a766685bd5d575e26576154e84c64f967bad1c22f17a622d1a2"
        )
    ]
)
