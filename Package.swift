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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.4.1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "86977998545d9395eded1c2b03b1f3c6205672675bd6ca701290999bc51ac2a2"
        )
    ]
)
