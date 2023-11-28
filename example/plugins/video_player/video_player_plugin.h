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

#ifndef VIDEO_PLAYER_PLUGIN_H_
#define VIDEO_PLAYER_PLUGIN_H_

#include <functional>

#include <flutter/plugin_registrar.h>

#include "messages.g.h"

namespace video_player {
class VideoPlayerPlugin final : public flutter::Plugin,
                              public AVFoundationVideoPlayerApiCodecSerializer,
                              public AVFoundationVideoPlayerApi {
public:
  VideoPlayerPlugin() = default;
  ~VideoPlayerPlugin() override = default;

  std::optional<FlutterError> Initialize() override;
  ErrorOr<TextureMessage> Create(const CreateMessage& msg) override;
  std::optional<FlutterError> Dispose(const TextureMessage& msg) override;
  std::optional<FlutterError> SetLooping(const LoopingMessage& msg) override;
  std::optional<FlutterError> SetVolume(const VolumeMessage& msg) override;
  std::optional<FlutterError> SetPlaybackSpeed(const PlaybackSpeedMessage& msg) override;
  std::optional<FlutterError> Play(const TextureMessage& msg) override;
  ErrorOr<PositionMessage> Position(const TextureMessage& msg) override;
  void SeekTo(
    const PositionMessage& msg,
    std::function<void(std::optional<FlutterError> reply)> result) override;
  std::optional<FlutterError> Pause(const TextureMessage& msg) override;
  std::optional<FlutterError> SetMixWithOthers(const MixWithOthersMessage& msg) override;

  static void RegisterWithRegistrar(
      flutter::PluginRegistrar* registrar) {
    auto plugin = std::make_unique<VideoPlayerPlugin>();

    SetUp(registrar->messenger(), plugin.get());

    registrar->AddPlugin(std::move(plugin));
  }
};
}

#endif // VIDEO_PLAYER_PLUGIN_H_
