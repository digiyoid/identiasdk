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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.9.2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "b84a33ba2ad7870412553b59fb6fe2cf9e0e14a5eda383a146de3562caea218c"
        )
    ]
)
