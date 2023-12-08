# Flutter Desktop

This is a fork of the Flutter Engine platform/glfw platform. This has a plugin registrar and is suitable for running
cross-platform development scenarios.

Checkout this repo and run

    git submodule update --init --recursive
    cd third_party/flutter
    git apply ../../patches/0001-Support-Linux.patch
    git apply ../../patches/0001-Linux-compat-for-event_channel.h.patch

Build

    mkdir build && cd build
    cmake .. -GNinja
    ninja -j`nproc`

Create bundle folder following folder layout

Run from build folder

    example/example <bundle folder>

### Observatory

You may need to jump through some hoops to access the Observatory.

After starting the example, find the URL pattern

    flutter: The Dart VM service is listening on http://127.0.0.1:36893/wSOQS4qdu3M=/

If when Clicking the link you get

    This VM does not have a registered Dart Development Service (DDS) instance and is not currently serving Dart DevTools.

Then enter

    http://127.0.0.1:36893/wSOQS4qdu3M=/_serveObservatory

After the jsonrpc reports success, re-run this to access the observatory

    http://127.0.0.1:36893/wSOQS4qdu3M=/

### Bundle Folder Layout

    <bundle folder>/
    data/
    icudtl.dat
    flutter_assets/
    lib/
    libapp.so
    libflutter_engine.so
