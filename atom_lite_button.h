#pragma once
#include "esphome/core/application.h"

// The tesla_ble_vehicle component creates its entities internally, so their IDs are
// not visible to YAML; find the charge-port flap cover by name instead.
inline bool flap_is_open() {
  for (auto *cv : esphome::App.get_covers()) {
    if (cv->get_name() == "Charge Port Door") {
      return cv->position > 0.5f;
    }
  }
  return false;
}
