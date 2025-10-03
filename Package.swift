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
            url: "https://github.com/digiyoid/identiasdk/releases/download/v1.2.3/DigiyoSwiftPackage.xcframework.zip",
            checksum: "cdddd41dc0ea459d07553a44d5c911a694bf469135e408bb53dae1c8d3b5013f"
        )
    ]
)