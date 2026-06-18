# Automated Grow-Bench Prototype (Firmware v1.0)

## Objective
Develop an automated irrigation system using ESP32 that waters plants based on soil moisture threshold with manual override support.

## Features
- Auto irrigation based on soil moisture
- Manual override using push button
- Serial commands:
  - STATUS
  - FORCE_ON
  - FORCE_OFF
- WiFi telemetry upload to Zelbytes server
- Relay-controlled pump
- LED status indicator
- Web control:
  - /on
  - /off
  - /status

## Hardware Used
- ESP32
- Soil Moisture Sensor
- Relay Module
- Water Pump
- Push Button
- LED
- Jumper Wires
- Power Supply

## Pin Configuration
| Component | Pin |
|-----------|-----|
| Soil Sensor | GPIO34 |
| Relay | GPIO26 |
| Button | GPIO27 |
| LED | GPIO2 |

## Auto Mode Logic
1. Read soil moisture
2. Convert raw ADC to percentage
3. Compare with threshold
4. If soil is dry → Pump ON
5. Else → Pump OFF

Threshold:
```cpp
DRY_THRESHOLD = 2000
```

## Manual Override
Press button to toggle:
- AUTO → MANUAL
- Pump ON/OFF manually

## Serial Commands
### STATUS
Displays:
- Soil moisture
- Pump state
- Current mode

### FORCE_ON
Turns pump ON manually.

### FORCE_OFF
Turns pump OFF manually.

## Telemetry API
POST:
https://careers.zelbytes.com/api/iot-lab/v1/telemetry

Payload:
```json
{
  "soil_moisture_pct": 65
}
```

## Build Steps
1. Open Arduino IDE
2. Select ESP32 board
3. Install libraries:
   - WiFi
   - HTTPClient
   - WebServer
4. Upload sketch
5. Open Serial Monitor (115200)

## Git Tag
Tag used:
v1.0-capstone