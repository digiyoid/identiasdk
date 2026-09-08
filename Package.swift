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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.3.0/DigiyoSwiftPackage.xcframework.zip",
            checksum: "21925228a67fe9a96f0b3b1f17e284188f4093d665745c9c72b2a7e7224d57e5"
        )
    ]
)
