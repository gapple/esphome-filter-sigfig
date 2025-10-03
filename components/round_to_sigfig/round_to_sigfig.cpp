#include "round_to_sigfig.h"

namespace esphome {
namespace sensor {

RoundSigfigFilter::RoundSigfigFilter(uint8_t digits) : digits_(digits) {}
optional<float> RoundSigfigFilter::new_value(float value) {
  if (std::isfinite(value)) {
    // Based on https://stackoverflow.com/a/13094362/120080
    if (value == 0.0) return 0.0;

    double factor = pow(10.0, digits - ceil(log10(fabs(value))));
    return round(value * factor) / factor;
  }
  return value;
}

}  // namespace sensor
}  // namespace esphome
