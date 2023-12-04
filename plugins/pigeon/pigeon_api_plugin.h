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

#ifndef PIGEON_API_PLUGIN_H_
#define PIGEON_API_PLUGIN_H_

#include <functional>

#include "flutter/shell/platform/common/client_wrapper/include/flutter/plugin_registrar.h"

#include "messages.g.h"

namespace pigeon_example {
class PigeonApiPlugin final : public flutter::Plugin, public ExampleHostApi {
 public:
  PigeonApiPlugin() = default;
  ~PigeonApiPlugin() override = default;

  ErrorOr<std::string> GetHostLanguage() override { return {"C++"}; }

  ErrorOr<int64_t> Add(const int64_t a, const int64_t b) override {
    if (a < 0 || b < 0) {
      return FlutterError("code", "message",
                          flutter::EncodableValue("details"));
    }
    return a + b;
  }

  void SendMessage(const MessageData& message,
                   std::function<void(ErrorOr<bool> reply)> result) override {
    if (Code::one == message.code()) {
      result(
          FlutterError("code", "message", flutter::EncodableValue("details")));
      return;
    }
    result(true);
  }

  static void RegisterWithRegistrar(flutter::PluginRegistrar* registrar) {
    auto plugin = std::make_unique<PigeonApiPlugin>();

    SetUp(registrar->messenger(), plugin.get());

    registrar->AddPlugin(std::move(plugin));
  }
};
}  // namespace pigeon_example

#endif  // PIGEON_API_PLUGIN_H_
