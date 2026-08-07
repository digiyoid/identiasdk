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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.0.0-beta.1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "19275929ed8f0e8d539d636d97edfcdddd32df8465091bb6fc1df65a4ff9b195"
        )
    ]
)
