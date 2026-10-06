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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.5.0/DigiyoSwiftPackage.xcframework.zip",
            checksum: "fa421f3c37a12e9007be448134337f6e6e268ca1f2e569e829dec05a2d0b19d3"
        )
    ]
)
