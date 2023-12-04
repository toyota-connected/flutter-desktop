/*
 * Copyright 2023 Toyota Connected North America
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <flutter/plugin_registrar.h>
#include <iostream>
#include <memory>

#include "flutter/shell/platform/embedder/embedder.h"
#include "src/shell/platform/desktop/public/flutter_desktop.h"

#include "plugins/firebase_core/include/firebase_core/firebase_core_plugin_c_api.h"
#include "plugins/pigeon/include/pigeon_api/pigeon_api_plugin_c_api.h"
#include "plugins/video_player/include/video_player/video_player_plugin_c_api.h"

static constexpr size_t kInitialWindowWidth = 800;
static constexpr size_t kInitialWindowHeight = 600;

static_assert(FLUTTER_ENGINE_VERSION == 1,
              "This Flutter Embedder was authored against the stable Flutter "
              "API at version 1. There has been a serious breakage in the "
              "API. Please read the ChangeLog and take appropriate action "
              "before updating this assertion");

void printUsage() {
  std::cout << "usage: example <path to bundle>" << std::endl;
}

void RegisterPlugins(FlutterDesktopEngineRef engine) {
  // Firebase Core
  FirebaseCorePluginCApiRegisterWithRegistrar(
      FlutterDesktopGetPluginRegistrar(engine, ""));
  // Pigeon Demo
  PigeonApiPluginCApiRegisterWithRegistrar(
      FlutterDesktopGetPluginRegistrar(engine, ""));
  // Video Player
  VideoPlayerPluginCApiRegisterWithRegistrar(
      FlutterDesktopGetPluginRegistrar(engine, ""));
}

int main(const int argc, const char* argv[]) {
  if (argc != 2) {
    printUsage();
    return 1;
  }

  const std::string project_path = argv[1];

  if (!FlutterDesktopInit()) {
    std::cout << "Could not initialize FlutterDesktop." << std::endl;
    return EXIT_FAILURE;
  }

  FlutterDesktopWindowProperties window_properties{};
  window_properties.title = "Flutter";
  window_properties.width = kInitialWindowWidth;
  window_properties.height = kInitialWindowHeight;
  window_properties.prevent_resize = false;

  const std::string assets_path = project_path + "/data/flutter_assets";
  const std::string icudtl_path = project_path + "/data/icudtl.dat";
  const std::string engine_path = project_path + "/lib/libflutter_engine.so";
  const std::string aot_path = project_path + "/lib/libapp.so";

  FlutterDesktopEngineProperties engine_properties{};
  engine_properties.engine_path = engine_path.c_str();
  engine_properties.assets_path = assets_path.c_str();
  engine_properties.icu_data_path = icudtl_path.c_str();
  engine_properties.aot_library_path = aot_path.c_str();

  std::vector dart_vm = {
      "--serve-observatory",
      "--verbose-logging"
  };
  engine_properties.switches = dart_vm.data();
  engine_properties.switches_count = dart_vm.size();

  const auto controller =
      FlutterDesktopCreateWindow(window_properties, engine_properties);
  if (controller == nullptr) {
    std::cout << "Could not create Flutter Desktop Window." << std::endl;
    return EXIT_FAILURE;
  }

  RegisterPlugins(FlutterDesktopGetEngine(controller));

  do {
  } while (FlutterDesktopRunWindowEventLoopWithTimeout(controller, 16));

  FlutterDesktopDestroyWindow(controller);
  FlutterDesktopTerminate();

  return EXIT_SUCCESS;
}
