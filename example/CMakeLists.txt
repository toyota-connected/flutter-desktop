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
# Example
#
add_executable(example main.cc)

target_include_directories(example PRIVATE)

target_link_libraries(example PRIVATE
        platform_common
        platform_desktop
        plugin_pigeon_api
        plugin_video_player
)

if (BUILD_PLUGIN_FIREBASE_CORE)
    target_link_libraries(example PRIVATE plugin_firebase_core)
    target_compile_definitions(example PRIVATE ENABLE_PLUGIN_FIREBASE_CORE)
endif ()

if (BUILD_PLUGIN_CLOUD_FIRESTORE)
    target_link_libraries(example PRIVATE plugin_cloud_firestore)
    target_compile_definitions(example PRIVATE ENABLE_PLUGIN_CLOUD_FIRESTORE)
endif ()

if (BUILD_PLUGIN_FIREBASE_AUTH)
    target_link_libraries(example PRIVATE plugin_firebase_auth)
    target_compile_definitions(example PRIVATE ENABLE_PLUGIN_FIREBASE_AUTH)
endif ()

if (BUILD_PLUGIN_FIREBASE_STORAGE)
    target_link_libraries(example PRIVATE plugin_firebase_storage)
    target_compile_definitions(example PRIVATE ENABLE_PLUGIN_FIREBASE_STORAGE)
endif ()


add_sanitizers(example)

if (IPO_SUPPORT_RESULT)
    set_property(TARGET example PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif ()
