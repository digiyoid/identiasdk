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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.2.0/DigiyoSwiftPackage.xcframework.zip",
            checksum: "a7f317802c3bfa050c9fd40354fd750f965716d8bf950cc9a9f180fdc2143780"
        )
    ]
)
