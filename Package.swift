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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.3.1-patch1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "102f96a70542d25dd95ae2c7fd6b50c41db1050bf296842a21f50d7c52baf97e"
        )
    ]
)
