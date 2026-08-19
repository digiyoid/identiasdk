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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.0.2-ktor2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "3ff426154080082c0bfecfa01149fa7419f9f5fb7c52ca2832327c30b588515b"
        )
    ]
)
