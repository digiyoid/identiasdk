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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.9.4/DigiyoSwiftPackage.xcframework.zip",
            checksum: "5439bb559d2ba16b7829a55d4c4a8809bf0d1258ff749a347fc0449cbb3549ad"
        )
    ]
)
