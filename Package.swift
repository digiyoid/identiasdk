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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.0.2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "c6927b8fe77e7f8355e5a60c9045b9e1d643974fa093f2de7c0bb7942c3b6a62"
        )
    ]
)
