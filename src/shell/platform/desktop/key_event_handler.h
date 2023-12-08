// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_PLATFORM_DESKTOP_KEY_EVENT_HANDLER_H
#define FLUTTER_SHELL_PLATFORM_DESKTOP_KEY_EVENT_HANDLER_H

#include <memory>

#include "flutter/shell/platform/common/client_wrapper/include/flutter/basic_message_channel.h"
#include "flutter/shell/platform/common/client_wrapper/include/flutter/binary_messenger.h"
#include "rapidjson/document.h"
#include "shell/platform/desktop/keyboard_hook_handler.h"

namespace flutter {

// Implements a KeyboardHookHandler
//
// Handles key events and forwards them to the Flutter engine.
class KeyEventHandler final : public KeyboardHookHandler {
 public:
  explicit KeyEventHandler(flutter::BinaryMessenger* messenger);

  ~KeyEventHandler() override;

  // |KeyboardHookHandler|
  void KeyboardHook(GLFWwindow* window,
                    int key,
                    int scancode,
                    int action,
                    int mods) override;

  // |KeyboardHookHandler|
  void CharHook(GLFWwindow* window, unsigned int code_point) override;

 private:
  // The Flutter system channel for key event messages.
  std::unique_ptr<flutter::BasicMessageChannel<rapidjson::Document>> channel_;
};

}  // namespace flutter

#endif  // FLUTTER_SHELL_PLATFORM_DESKTOP_KEY_EVENT_HANDLER_H
