# Linux Pigeon Sandbox

This is a sandbox to experiement with Pigeon based plugins on Linux.

Checkout this repo and run

    git submodule update --init --recursive
    cd third_party/flutter
    git apply ../../patches/0001-Support-Linux.patch

Build
    mkdir build && cd build
    cmake .. -GNinja
    ninja -j`nproc`

Create bundle folder following folder layout

Run from build folder

    example/example <bundle folder>

### Bundle Folder Layout

    <bundle folder>/
    data/
    icudtl.dat
    flutter_assets/
    lib/
    libapp.so
    libflutter_engine.so
