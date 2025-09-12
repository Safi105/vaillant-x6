```markdown
# Verwendung: send_command Service

Dieser Abschnitt zeigt, wie du den neuen Service "send_command" verwenden kannst, um generische Befehle an das Vaillant X6-Protokoll zu senden.

Beispiel-Aufruf (Home Assistant -> Entwicklerwerkzeuge -> Dienste):

service: esphome.send_command
data:
  command_byte: 16               # Dezimal oder 0x10 als Hex
  payload: [1, 2, 3]             # Liste von Bytes
  expected_response_payload_length: 2

Hinweis:
- Der exakte Service-Name hängt von der finalen Registrierung ab (z. B. `esphome.<node_id>_send_command` oder `esphome.send_command`). Im PR werde ich den exakten Namen setzen, sobald die Wrapper-Registrierung final ist.
- `command_byte` ist ein Byte (0..255).
- `payload` ist eine Liste von Bytes (je Element 0..255).
- `expected_response_payload_length` ist die erwartete Länge (in Bytes) des Antwort-Payloads.
```
