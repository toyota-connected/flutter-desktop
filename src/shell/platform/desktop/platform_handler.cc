// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "shell/platform/desktop/platform_handler.h"

#include <iostream>

#include "flutter/shell/platform/common/json_method_codec.h"

static constexpr char kChannelName[] = "flutter/platform";

static constexpr char kGetClipboardDataMethod[] = "Clipboard.getData";
static constexpr char kSetClipboardDataMethod[] = "Clipboard.setData";
static constexpr char kSystemNavigatorPopMethod[] = "SystemNavigator.pop";

static constexpr char kTextPlainFormat[] = "text/plain";
static constexpr char kTextKey[] = "text";

static constexpr char kNoWindowError[] = "Missing window error";
static constexpr char kUnknownClipboardFormatError[] =
    "Unknown clipboard format error";

namespace flutter {

PlatformHandler::PlatformHandler(flutter::BinaryMessenger* messenger,
                                 GLFWwindow* window)
    : channel_(std::make_unique<flutter::MethodChannel<rapidjson::Document>>(
          messenger,
          kChannelName,
          &flutter::JsonMethodCodec::GetInstance())),
      window_(window) {
  channel_->SetMethodCallHandler(
      [this](
          const flutter::MethodCall<rapidjson::Document>& call,
          std::unique_ptr<flutter::MethodResult<rapidjson::Document>> result) {
        HandleMethodCall(call, result);
      });
}

void PlatformHandler::HandleMethodCall(
    const flutter::MethodCall<rapidjson::Document>& method_call,
    const std::unique_ptr<flutter::MethodResult<rapidjson::Document>>& result)
    const {
  const std::string& method = method_call.method_name();

  if (method == kGetClipboardDataMethod) {
    if (!window_) {
      result->Error(kNoWindowError,
                    "Clipboard is not available in GLFW headless mode.");
      return;
    }
    // Only one string argument is expected.
    const rapidjson::Value& format = method_call.arguments()[0];

    if (strcmp(format.GetString(), kTextPlainFormat) != 0) {
      result->Error(kUnknownClipboardFormatError,
                    "GLFW clipboard API only supports text.");
      return;
    }

    const char* clipboardData = glfwGetClipboardString(window_);
    if (clipboardData == nullptr) {
      result->Error(kUnknownClipboardFormatError,
                    "Failed to retrieve clipboard data from GLFW api.");
      return;
    }
    rapidjson::Document document;
    document.SetObject();
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
    document.AddMember(rapidjson::Value(kTextKey, allocator),
                       rapidjson::Value(clipboardData, allocator), allocator);
    result->Success(document);
  } else if (method == kSetClipboardDataMethod) {
    if (!window_) {
      result->Error(kNoWindowError,
                    "Clipboard is not available in GLFW headless mode.");
      return;
    }
    const rapidjson::Value& document = *method_call.arguments();
    const rapidjson::Value::ConstMemberIterator itr =
        document.FindMember(kTextKey);
    if (itr == document.MemberEnd()) {
      result->Error(kUnknownClipboardFormatError,
                    "Missing text to store on clipboard.");
      return;
    }
    glfwSetClipboardString(window_, itr->value.GetString());
    result->Success();
  } else if (method == kSystemNavigatorPopMethod) {
    exit(EXIT_SUCCESS);
  } else {
    result->NotImplemented();
  }
}
}  // namespace flutter
