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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.3.1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "bd4b3d6c6391b35dd6b41d0948e585e3739d85f26dfe3b121d29fedb69660de3"
        )
    ]
)
