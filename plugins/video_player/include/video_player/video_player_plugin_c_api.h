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

#ifndef FLUTTER_PLUGIN_VIDEO_PLAYER_PLUGIN_C_API_H_
#define FLUTTER_PLUGIN_VIDEO_PLAYER_PLUGIN_C_API_H_

#include "flutter/shell/platform/common/public/flutter_plugin_registrar.h"

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#endif

FLUTTER_PLUGIN_EXPORT void VideoPlayerPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrar* registrar);

#endif  // FLUTTER_PLUGIN_VIDEO_PLAYER_PLUGIN_C_API_H_
