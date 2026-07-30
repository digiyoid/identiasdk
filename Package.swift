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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.5.1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "7bb38389724c47f081da2f917b89ecf3aff6c362c2e95b7414eefa04401303c0"
        )
    ]
)
