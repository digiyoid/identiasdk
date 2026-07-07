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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.4.5/DigiyoSwiftPackage.xcframework.zip",
            checksum: "13f0ce0ab97e6f96716a12034436e4c21a0547110c33125d471f49e26314c6a5"
        )
    ]
)
