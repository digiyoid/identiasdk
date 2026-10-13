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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.5.1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "8c12b2d389cd2c92304f2f37babe9ff7d84ac60435572651eca0470fafb28b59"
        )
    ]
)
