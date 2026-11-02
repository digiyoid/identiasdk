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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.9.5-ktor2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "125807f8517abb2c3236abdb55e94eb534a2975f129a74f055f8fc4c9394b699"
        )
    ]
)
