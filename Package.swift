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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.2.5-patch01/DigiyoSwiftPackage.xcframework.zip",
            checksum: "9893f792eb07cb5ad74d9094e2c37040958c213636bbea785457b8303823cf43"
        )
    ]
)
