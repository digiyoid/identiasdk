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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.5.6-ktor2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "d868532abe80be40905afb3c78b9e1f1eaa8bff67a622d79da9ab3cce8a38fb3"
        )
    ]
)
