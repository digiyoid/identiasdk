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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.2.0-ktor2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "24417ace00d102bb881ba6eb50211c114411c98bb0accc0a5a7aef680c2b1203"
        )
    ]
)
