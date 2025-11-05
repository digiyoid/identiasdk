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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.2.7/DigiyoSwiftPackage.xcframework.zip",
            checksum: "09a165cf1eefdacfab8894243a7857bcd2a2955ec6a05a829ec217c74e5b7b6d"
        )
    ]
)
