// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_PLATFORM_GLFW_GLFW_EVENT_LOOP_H_
#define FLUTTER_SHELL_PLATFORM_GLFW_GLFW_EVENT_LOOP_H_

#include "shell/platform/desktop/event_loop.h"

namespace flutter {
// An event loop implementation that supports Flutter Engine tasks scheduling in
// the GLFW event loop.
class DesktopEventLoop final : public EventLoop {
public:
  DesktopEventLoop(std::thread::id main_thread_id,
                const TaskExpiredCallback& on_task_expired);

  ~DesktopEventLoop() override;

  // Prevent copying.
  DesktopEventLoop(const DesktopEventLoop&) = delete;
  DesktopEventLoop& operator=(const DesktopEventLoop&) = delete;

private:
  // |EventLoop|
  void WaitUntil(const TaskTimePoint& time) override;

  // |EventLoop|
  void Wake() override;
};
} // namespace flutter

#endif  // FLUTTER_SHELL_PLATFORM_GLFW_GLFW_EVENT_LOOP_H_
