#pragma once
/*
Copyright (c) 2025 Patryk Dudziński

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
 * Authors: Patryk Dudziński
 */
#include "rclcpp/rclcpp.hpp"
#include <chrono>

namespace ari {

class FrequencyTimer {
private:
  std::chrono::nanoseconds interval_;
  std::chrono::steady_clock::time_point last_trigger_;

public:
  // Constructor with frequency in Hz
  FrequencyTimer(double frequency_hz) : interval_(static_cast<int64_t>(1000'000.0 / frequency_hz)) {
    last_trigger_ = std::chrono::steady_clock::now();
  }

  // Constructor with interval in milliseconds
  FrequencyTimer(std::chrono::milliseconds interval) : interval_(interval) {
    last_trigger_ = std::chrono::steady_clock::now();
  }

  // Check if it's time to trigger, auto-resets
  bool should_trigger() {
    auto now     = std::chrono::steady_clock::now();
    auto elapsed = now - last_trigger_;
    if(elapsed >= interval_) {
      return true;
    }
    return false;
  }

  // Manual reset if needed
  void reset() {
    last_trigger_ = std::chrono::steady_clock::now();
  }
  // Get elapsed time since last trigger
  double elapsed_s() const {
    return std::chrono::duration<double>(std::chrono::steady_clock::now() - last_trigger_).count();
  }
};

} // namespace ari