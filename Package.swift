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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.7.0-ktor2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "187fdbd4e2664ec3d271cc96ec0216307cccc22c03d7aae5bc8ec2a5001505de"
        )
    ]
)
