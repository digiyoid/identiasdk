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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.3.1-patch3/DigiyoSwiftPackage.xcframework.zip",
            checksum: "d757392b1ae5c6786709d7660e05652359d705b35b5e5c5cf95c7e13a3253490"
        )
    ]
)
