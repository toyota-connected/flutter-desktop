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

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED COMPONENTS EGL)

add_library(platform_desktop SHARED
        public/flutter_desktop.h
        event_loop.cc
        event_loop.h
        flutter_desktop.cc
        libflutter_engine.cc
        desktop_event_loop.cc
        desktop_event_loop.h
        headless_event_loop.cc
        headless_event_loop.h
        key_event_handler.cc
        key_event_handler.h
        keyboard_hook_handler.h
        platform_handler.cc
        platform_handler.h
        system_utils.cc
        text_input_plugin.cc
        text_input_plugin.h

        client_wrapper/flutter_engine.cc
        client_wrapper/flutter_window_controller.cc
)

target_include_directories(platform_desktop PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../../..
        public
        client_wrapper/include
        client_wrapper/include/flutter
)

target_link_libraries(platform_desktop platform_common glfw OpenGL::EGL)

set_target_properties(platform_desktop PROPERTIES OUTPUT_NAME "flutter_desktop")

add_sanitizers(platform_desktop)

install(TARGETS platform_desktop
        EXPORT platform_desktop
        INCLUDES DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/include
        RUNTIME DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/bin
        ARCHIVE DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/lib
        LIBRARY DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/lib
)

install(FILES public/flutter_desktop.h
        DESTINATION
        ${CMAKE_INSTALL_DATAROOTDIR}/flutter_desktop/include
)

install(DIRECTORY client_wrapper/include
        DESTINATION
        ${CMAKE_INSTALL_DATAROOTDIR}/flutter_desktop
        FILES_MATCHING
        PATTERN "*.h"
)
