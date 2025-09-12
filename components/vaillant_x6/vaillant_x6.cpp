#include "vaillant_x6.h"
#include "esphome/core/log.h"

namespace esphome {
namespace vaillant_x6 {

static const char *TAG = "vaillant_x6";

void VaillantX6Component::send_command(uint8_t command, const std::vector<uint8_t> &payload, uint8_t expected_response_length) {
  std::vector<uint8_t> buf;
  buf.push_back(command);
  buf.insert(buf.end(), payload.begin(), payload.end());

  // Send bytes over UART
  this->write_array(buf.data(), buf.size());
  ESP_LOGD(TAG, "Sent command: %u payload_len: %d expected_response_len: %u", command, static_cast<int>(payload.size()), expected_response_length);

  // Response handling is intentionally left minimal in this stub.
}

}  // namespace vaillant_x6
}  // namespace esphome
