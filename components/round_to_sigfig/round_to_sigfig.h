#pragma once

#include "esphome/components/sensor/filter.h"

namespace esphome {
namespace sensor {

class RoundSigfigFilter : public Filter {
 public:
  explicit RoundSigfigFilter(uint8_t digits);
  optional<float> new_value(float value) override;

 protected:
  uint8_t digits_;
};

}  // namespace sensor
}  // namespace esphome
