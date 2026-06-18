# Wiring Diagram

## ESP32 Connections

### Soil Moisture Sensor
- VCC → 3.3V
- GND → GND
- AO → GPIO34

### Relay Module
- VCC → 5V
- GND → GND
- IN → GPIO26

### Push Button
- One side → GPIO27
- Other side → GND

(INPUT_PULLUP used)

### LED
- Anode → GPIO2 through 220Ω resistor
- Cathode → GND

### Pump
Pump connected via relay NO terminal.