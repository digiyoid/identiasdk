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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.3.0/DigiyoSwiftPackage.xcframework.zip",
            checksum: "bba342fe6a2b32dc28376403eaf194c4050f15724d3b1b08e5bf616e1708f957"
        )
    ]
)
