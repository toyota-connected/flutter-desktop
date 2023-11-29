# pigeon_api

### re-generate messages.g.cc + messages.g.h

    git clone https://github.com/flutter/packages
    cd packages/packages/pigeon/example/app
    flutter pub run pigeon --input pigeons/messages.dart --cpp_header_out messages.g.h --cpp_source_out messages.g.cc --cpp_namespace pigeon_example

It will output two files, copy these into this folder, and rebuild the example target

### Run demo

    example <bundle path from above step>

### Automatically create a bundle folder using workspace_automation

    cd ${FLUTTER_WORKSPACE}
    source ./setup_env.sh
    cd third_party/packages/packages/pigeon/example/app
    flutter run -d desktop-homescreen
    q
    cd .desktop-homescreen/
    export BUNDLE=`pwd`

Navigate to build folder

    example/example $BUNDLE

### References

https://github.com/meta-flutter/workspace-automation