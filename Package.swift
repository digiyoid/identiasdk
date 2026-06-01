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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.4.4/DigiyoSwiftPackage.xcframework.zip",
            checksum: "cbd2983d50ef4178da62e9ee94548f4e53bd0d8088f60bb30875266304b39756"
        )
    ]
)
