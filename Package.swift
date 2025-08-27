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
        ),
    ],
     targets: [
        .binaryTarget(
            name: "DigiyoSwiftPackage",
            url: "https://github.com/digiyoid/identiasdk-ios/releases/download/v1.1.0/DigiyoSwiftPackage.zip",
            checksum: "76f155a2e91313dc5acbb2628e254bff8c104e476b9cb2f6531b53c427f5061d",
        )
    ]
)