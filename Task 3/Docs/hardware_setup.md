# Hardware Connections

| Component | Arduino Pin |
|------------|------------|
| Button | D2 |
| Relay IN | D8 |
| Status LED | D13 |
| Relay VCC | 5V |
| Relay GND | GND |

## Solenoid Valve

Power Supply (+) → Relay COM

Relay NO → Solenoid (+)

Solenoid (-) → Power Supply (-)

## Operation

Button Pressed:
- Relay ON
- Valve OPEN
- LED ON

Button Released:
- Relay OFF
- Valve CLOSED
- LED OFF
