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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.3.1-ktor2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "18bb925a315b425112b9983d655ff93d941b3097c8e1d98e452ecf6fbcce7b82"
        )
    ]
)
