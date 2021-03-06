// SPDX-FileCopyrightText: 2020 Sveriges Television AB
// SPDX-FileCopyrightText: 2021 Sveriges Television AB
//
// SPDX-License-Identifier: GPL-2.0-or-later

#ifndef DISPLAYSTATE_HH_
#define DISPLAYSTATE_HH_

#include <string>
#include <cmath>
#include <iostream>

#include "time/Time.hh"

namespace vivictpp {
namespace ui {

class Zoom {
 private:
  int zoom_ = 0;
  float multiplier_ = 1.0;
 public:
  void set(int zoom) {
    zoom_ = zoom;
    setMultiplier();
  }
  int get() const { return zoom_; }
  int increment() {
    zoom_++;
    setMultiplier();
    return zoom_;
  }
  int decrement() {
    zoom_--;
    setMultiplier();
    return zoom_;
  }
  float multiplier() const { return multiplier_; }
 private:
  void setMultiplier() { multiplier_ = pow(1.2, zoom_); }
};

struct DisplayState {
  float splitPercent{50};
  //  int zoom{0};
  Zoom zoom;
  float panX{0};
  float panY{0};
  bool fullscreen{false};
  std::string timeStr;
  bool displayTime{true};
  bool displayMetadata{true};
  bool displayPlot{true};
  bool splitScreenDisabled{false};
  bool isPlaying{false};
  vivictpp::time::Time pts{0};
  bool seekBarVisible{false};
  int64_t hideSeekBar{0};
  int seekBarOpacity{255};
  float seekBarRelativePos{0};
  int leftFrameOffset{0};
};

}  // ui
}  // vivictpp

#endif // DISPLAYSTATE_HH_
