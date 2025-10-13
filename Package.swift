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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.2.5/DigiyoSwiftPackage.xcframework.zip",
            checksum: "b7a3d1b32b1ecfe190cd4a9e4570547c019c4714f9e839c66ba210177eb21cc8"
        )
    ]
)
