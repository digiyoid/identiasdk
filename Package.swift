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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.0.0-ktor2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "c77630a5a546de4999e0633161b07fd6c2eaf72c2b187e8502092b0890d25b25"
        )
    ]
)
