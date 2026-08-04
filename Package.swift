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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.5.3/DigiyoSwiftPackage.xcframework.zip",
            checksum: "7bbb6fd96e91a261d41f2bca16a8a4e8f790086768430e3027f2ddc549dfeb9d"
        )
    ]
)
