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
            url: "https://github.com/digiyoid/identiasdk/releases/download/v1.2.1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "b27df6bb7791298d18c075a0cbbb1a1f327049fd2327feb252efe07b80e84320"
        )
    ]
)