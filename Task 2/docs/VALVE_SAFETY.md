# Solenoid Valve Safety Procedure

## Objective

To safely control a solenoid valve using a relay module.

## Important Rule

The solenoid valve must never be connected directly to an Arduino GPIO pin.

The valve must be powered through a relay module and an external power supply.

## Relay Connections

Arduino Pin 8  -> Relay IN

Arduino 5V     -> Relay VCC

Arduino GND    -> Relay GND

## Valve Connections

Power Supply Positive -> Relay COM

Relay NO -> Valve Positive

Valve Negative -> Power Supply Negative

## Startup Safety

The valve remains OFF during startup.

Code:

setValve(false);

## Emergency Stop

Command:

e

Action:

Immediately de-energizes the relay and closes the valve.

## Testing Procedure

1. Verify relay wiring.
2. Upload sketch.
3. Listen for relay click.
4. Test emergency stop command.
5. Connect valve only after relay operation is verified.

## Conclusion

The valve was controlled safely through the relay and the emergency stop function operated correctly.
