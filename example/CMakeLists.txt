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
# Plugins
#
add_subdirectory(plugins/pigeon)
add_subdirectory(plugins/video_player)

#
# Example
#
add_executable(example main.cc)

target_link_libraries(example PRIVATE
        plugin_pigeon_api
        plugin_video_player
        platform_common
        platform_desktop
)

add_sanitizers(example)
