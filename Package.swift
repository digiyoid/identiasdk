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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.4.1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "409d1a1240f24fa9c16394835ba3bbf69bd9cff6e38109714fb58d90f440d920"
        )
    ]
)
