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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.9.3/DigiyoSwiftPackage.xcframework.zip",
            checksum: "3ad909e219544e49eecdf3492c9ef4584878a8f64df5d6e6652c51428046150a"
        )
    ]
)
