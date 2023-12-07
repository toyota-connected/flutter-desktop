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

find_package(PkgConfig REQUIRED)
pkg_check_modules(UUID REQUIRED IMPORTED_TARGET uuid)

set(CMAKE_THREAD_PREFER_PTHREAD ON)
include(FindThreads)

add_library(plugin_firebase_storage STATIC
        firebase_storage_plugin.cc
        firebase_storage_plugin_c_api.cc
        messages.g.cc
)

target_compile_definitions(plugin_firebase_storage PRIVATE
        -DINTERNAL_EXPERIMENTAL=1
)

target_include_directories(plugin_firebase_storage PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include
        ${FIREBASE_CPP_SDK_DIR}/app/src/include
        ${FIREBASE_CPP_SDK_DIR}/storage/src/include
)

target_link_directories(plugin_firebase_storage PUBLIC
        ${FIREBASE_SDK_LIBDIR}/app
        ${FIREBASE_SDK_LIBDIR}/storage
        ${FIREBASE_SDK_LIBDIR}/external/src/curl-build
        ${FIREBASE_SDK_LIBDIR}/external/src/flatbuffers-build
        ${FIREBASE_SDK_LIBDIR}/external/src/zlib-build
        ${FIREBASE_SDK_LIBDIR}/external/src/boringssl
)

target_link_libraries(plugin_firebase_storage PUBLIC
        plugin_firebase_core
        firebase_sdk
        PkgConfig::UUID
        Threads::Threads
)

add_sanitizers(plugin_firebase_storage)

if (IPO_SUPPORT_RESULT)
    set_property(TARGET plugin_firebase_storage PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif ()
