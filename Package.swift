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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.5.5/DigiyoSwiftPackage.xcframework.zip",
            checksum: "b7c04e83038e9ed3e448ded82a13e9a4de9c8e92128749786a5adcbe11ca309f"
        )
    ]
)
