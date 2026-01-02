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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.4.0/DigiyoSwiftPackage.xcframework.zip",
            checksum: "9d3ff222bdd3368007c8a6b8cfbd8453c79801d7581b75cf56f676a98ce38b8c"
        )
    ]
)
