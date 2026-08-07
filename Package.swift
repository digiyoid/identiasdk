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
                "https://github.com/digiyoid/identiasdk/releases/download/v1.5.6/DigiyoSwiftPackage.xcframework.zip",
            checksum: "81cb74deae4bd0e975d9f91dfcab5eda20116a1a60c02ab83471733edf02414c"
        )
    ]
)
