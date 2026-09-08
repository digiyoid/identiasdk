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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.3.0-ktor2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "5d90c9da06cf6af5e54b83854c349709a56af8c3c95847b48b132684e66379dd"
        )
    ]
)
