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
            url: "https://github.com/digiyoid/identiasdk/releases/download/v1.2.0/DigiyoSwiftPackage.zip",
            checksum: "92abf302f2617ca87a89bd8f7a1c54b1c24ad91ba443ebd218f0770864f1010b",
        )
    ]
)