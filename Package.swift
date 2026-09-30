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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.4.0/DigiyoSwiftPackage.xcframework.zip",
            checksum: "a131849a275b79c7339df5843a2f0c8e7a921905d707e1fd821813465138977d"
        )
    ]
)
