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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.7.1/DigiyoSwiftPackage.xcframework.zip",
            checksum: "9964e4bd919144485601e1bbf77ea3b500705d36e7cdd4e5bc7fcd300e9fdcaf"
        )
    ]
)
