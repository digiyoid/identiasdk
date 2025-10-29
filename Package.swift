// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "DigiyoSDK",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "Digiyo",
            targets: ["Digiyo"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "Digiyo",
            url:
                "https://github.com/digiyoid/identiasdk/releases/download/v1.2.6/Digiyo.xcframework.zip",
            checksum: "8464a15e4ce934d50cb9fda7e640b88bc5bf5a58d0cd7b0a6d43b0f81b5b02ad"
        )
    ]
)
