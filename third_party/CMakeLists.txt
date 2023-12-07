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

add_library(platform_common STATIC
        flutter/shell/platform/common/client_wrapper/core_implementations.cc
        flutter/shell/platform/common/client_wrapper/plugin_registrar.cc
        flutter/shell/platform/common/client_wrapper/standard_codec.cc
        flutter/shell/platform/common/incoming_message_dispatcher.cc
        flutter/shell/platform/common/json_message_codec.cc
        flutter/shell/platform/common/json_method_codec.cc
        flutter/shell/platform/common/path_utils.cc
        flutter/shell/platform/common/text_editing_delta.cc
        flutter/shell/platform/common/text_input_model.cc

        flutter/fml/logging.cc
        flutter/fml/log_settings.cc
        flutter/fml/log_settings_state.cc
        flutter/fml/string_conversion.cc
)

target_include_directories(platform_common PUBLIC
        .
        ..

        flutter/shell/common
        flutter/shell/platform/common
        flutter/shell/platform/common/public
        flutter/shell/platform/common/client_wrapper/include
        flutter/shell/platform/common/client_wrapper/include/flutter

        rapidjson/include
)

target_compile_definitions(platform_common PUBLIC
        RAPIDJSON_HAS_STDSTRING
)

add_sanitizers(platform_common)

install(DIRECTORY flutter/shell/platform/common/public/
        DESTINATION
        ${CMAKE_INSTALL_DATAROOTDIR}/flutter_desktop/include
        FILES_MATCHING
        PATTERN "*.h"
)

install(DIRECTORY flutter/shell/platform/common/client_wrapper/include/
        DESTINATION
        ${CMAKE_INSTALL_DATAROOTDIR}/flutter_desktop/include
        FILES_MATCHING
        PATTERN "*.h"
)

install(DIRECTORY flutter/shell/platform/common/client_wrapper/include/flutter/
        DESTINATION share/flutter_desktop/include/flutter
        FILES_MATCHING
        PATTERN "*.h"
)
