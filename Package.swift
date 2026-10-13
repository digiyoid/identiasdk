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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.6.0/DigiyoSwiftPackage.xcframework.zip",
            checksum: "24d63afbebcf1d23e6bbc5ded4f2ee33e82809bf359758a96204af1a3340ef1f"
        )
    ]
)
