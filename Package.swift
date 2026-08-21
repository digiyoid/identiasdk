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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.1.0/DigiyoSwiftPackage.xcframework.zip",
            checksum: "931a6ad52f9c314a3849e5e30877d6faeb648ef5b9375c2b89268ab103210347"
        )
    ]
)
