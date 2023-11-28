
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