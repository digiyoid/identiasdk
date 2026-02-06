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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.3.1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "b26d50ae7f15afc4e1241e4ac9d18b5bdb0f4682467a0f1279b1386582245625"
        )
    ]
)
