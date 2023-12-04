// Copyright 2023, the Chromium project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.
// Copyright 2023, Toyota Connected North America

#include "include/firebase_core/firebase_core_plugin_c_api.h"

#include "shell/platform/desktop/client_wrapper/include/flutter/plugin_registrar_desktop.h"

#include <flutter/plugin_registrar.h>

#include "firebase_core_plugin.h"

void FirebaseCorePluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  firebase_core_linux::FirebaseCorePlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarDesktop>(registrar));
}