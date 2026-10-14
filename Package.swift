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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.7.0/DigiyoSwiftPackage.xcframework.zip",
            checksum: "ece0e46f644832a262eec6e6af500c36b4d81234a0011d36e37d7d6cbf578027"
        )
    ]
)
