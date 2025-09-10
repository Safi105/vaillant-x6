#pragma once

#include "esphome.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace vaillant_x6 {

class VaillantX6Component : public PollingComponent, public uart::UARTDevice {
 public:
  void setup() override {}
  void loop() override {}
  void update() override {}
  void send_command(uint8_t command, const std::vector<uint8_t> &payload, uint8_t expected_response_length);
};

}  // namespace vaillant_x6
}  // namespace esphome
