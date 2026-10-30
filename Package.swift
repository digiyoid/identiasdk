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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.9.5/DigiyoSwiftPackage.xcframework.zip",
            checksum: "367c9cc3af744b25dcb65cccf317bc8d2da2a4c064b6e6d3aa005bc987db01fa"
        )
    ]
)
