#
# Copyright 2023 Toyota Connected North America
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#
# Firebase C++ SDK
#
if (EXISTS ${FIREBASE_CPP_SDK_ROOT_DIR})
    message(STATUS "Firebase CPP SDK Root: ${FIREBASE_CPP_SDK_ROOT_DIR}")

    add_library(plugin_firebase_storage STATIC
            firebase_storage_plugin.cc
            firebase_storage_plugin_c_api.cc
            pigeon_messages.g.cc
    )
    target_include_directories(plugin_firebase_storage PRIVATE
            ${FIREBASE_CPP_SDK_ROOT_DIR}/app/src/include
            ${FIREBASE_CPP_SDK_ROOT_DIR}/storage/src/include
    )
    target_link_directories(plugin_firebase_storage PUBLIC
            ${FIREBASE_CPP_SDK_BINARY_DIR}/installations
            ${FIREBASE_CPP_SDK_BINARY_DIR}/messaging
            ${FIREBASE_CPP_SDK_BINARY_DIR}/analytics
            ${FIREBASE_CPP_SDK_BINARY_DIR}/app_check
            ${FIREBASE_CPP_SDK_BINARY_DIR}/database
            ${FIREBASE_CPP_SDK_BINARY_DIR}/dynamic_links
            ${FIREBASE_CPP_SDK_BINARY_DIR}/remote_config
            ${FIREBASE_CPP_SDK_BINARY_DIR}/auth
            ${FIREBASE_CPP_SDK_BINARY_DIR}/app/rest
            ${FIREBASE_CPP_SDK_BINARY_DIR}/app
            ${FIREBASE_CPP_SDK_BINARY_DIR}/storage
            ${FIREBASE_CPP_SDK_BINARY_DIR}/functions
            ${FIREBASE_CPP_SDK_BINARY_DIR}/gma
            ${FIREBASE_CPP_SDK_BINARY_DIR}/external/src/zlib-build
            ${FIREBASE_CPP_SDK_BINARY_DIR}/external/src/flatbuffers-build
            platform_desktop
    )
    target_link_libraries(plugin_firebase_storage PUBLIC
            platform_desktop
            firebase_storage
            firebase_app
            flatbuffers
            z
    )

    add_sanitizers(plugin_firebase_storage)

    if (IPO_SUPPORT_RESULT)
        set_property(TARGET plugin_firebase_storage PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    endif ()
endif ()
