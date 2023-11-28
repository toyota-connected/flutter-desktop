
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

include(GNUInstallDirs)
install(TARGETS platform_desktop
        EXPORT platform_desktop
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES
        public/platform_desktop.h
        client_wrapper/include/flutter/flutter_engine.h
        client_wrapper/include/flutter/flutter_window.h
        client_wrapper/include/flutter/flutter_window_controller.h
        client_wrapper/include/flutter/plugin_registrar_desktop.h
        DESTINATION
        share/platform_desktop/
)
