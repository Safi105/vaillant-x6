import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import CONF_ID

DEPENDENCIES = ['uart']
CODEOWNERS = ['@Safi105']
AUTO_LOAD = ['sensor', 'binary_sensor']

vaillant_x6_ns = cg.esphome_ns.namespace('vaillant_x6')
VaillantX6Component = vaillant_x6_ns.class_('VaillantX6Component', cg.PollingComponent, uart.UARTDevice)

CONF_SEND_COMMAND = 'send_command'

SEND_COMMAND_SCHEMA = cv.Schema({
    cv.Required('command_byte'): cv.uint8_t,
    cv.Optional('payload', default=[]): cv.All(cv.ensure_list(cv.uint8_t), [cv.uint8_t]),
    cv.Required('expected_response_payload_length'): cv.uint8_t,
})

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(VaillantX6Component),
}).extend(cv.polling_component_schema('10s')).extend(uart.UART_DEVICE_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)

    cg.add(var)  # placeholder to avoid unused variable

    # Note: Service registration wrapper will be implemented in a follow-up patch.