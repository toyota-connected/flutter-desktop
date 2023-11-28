
#include "video_player_plugin.h"

#include <optional>

namespace video_player {
std::optional<FlutterError> VideoPlayerPlugin::Initialize() {
  return std::nullopt;
}

ErrorOr<TextureMessage> VideoPlayerPlugin::Create(
    const CreateMessage& /* msg */) {
  return TextureMessage(0);
}

std::optional<FlutterError> VideoPlayerPlugin::Dispose(
    const TextureMessage& /* msg */) {
  return std::nullopt;
}

std::optional<FlutterError> VideoPlayerPlugin::SetLooping(
    const LoopingMessage& /* msg */) {
  return std::nullopt;
}

std::optional<FlutterError> VideoPlayerPlugin::SetVolume(
    const VolumeMessage& /* msg */) {
  return std::nullopt;
}

std::optional<FlutterError> VideoPlayerPlugin::SetPlaybackSpeed(
    const PlaybackSpeedMessage& /* msg */) {
  return std::nullopt;
}

std::optional<FlutterError> VideoPlayerPlugin::Play(
    const TextureMessage& /* msg */) {
  return std::nullopt;
}

ErrorOr<PositionMessage>
VideoPlayerPlugin::Position(const TextureMessage& /* msg */) {
  return PositionMessage(0, 0.0);
}

void VideoPlayerPlugin::SeekTo(
    const PositionMessage& /* msg */,
    std::function<void(std::optional<FlutterError> reply)> /* result */) {
}

std::optional<FlutterError>
VideoPlayerPlugin::Pause(const TextureMessage& /* msg */) {
  return std::nullopt;
}

std::optional<FlutterError> VideoPlayerPlugin::SetMixWithOthers(
    const MixWithOthersMessage& /* msg */) {
  return std::nullopt;
}
}
