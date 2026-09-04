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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.2.0-ktor2.1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "615a2ce1b9d1905a8ab093f495b100520908162c8c33d3494e842a4263df182e"
        )
    ]
)
