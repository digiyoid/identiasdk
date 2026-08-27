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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.1.2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "9483eb4e9209fdf163444493dff4c9cee67d60644990e5fdc1b4587d2d4dc597"
        )
    ]
)
