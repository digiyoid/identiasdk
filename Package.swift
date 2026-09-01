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
                "https://github.com/digiyoid/identiasdk/releases/download/v2.1.3-ktor2/DigiyoSwiftPackage.xcframework.zip",
            checksum: "d6b6ac7aa200c3b21d9e22a6781f79f319225eea2451943f37db21b2762f77bc"
        )
    ]
)
