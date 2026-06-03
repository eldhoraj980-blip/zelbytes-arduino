# Serial Debugging Guide

## Objective
To understand and monitor Arduino program behavior using the Serial Monitor.

## Hardware
- Arduino Uno
- USB Cable
- Computer

## Baud Rate
9600

## Commands

| Command | Function |
|----------|----------|
| ? | Display help |
| l | Turn LED ON |
| o | Turn LED OFF |

## Procedure

1. Upload the serial_debug sketch.
2. Open Serial Monitor.
3. Select 9600 baud.
4. Enter commands in the text box.
5. Observe the responses.

## Expected Output

Commands: ? help, l on, o off

l
ON

o
OFF

## Debug Messages

The program prints the uptime every 2 seconds.

Example:

uptime_ms=2000
uptime_ms=4000
uptime_ms=6000

## Conclusion

Serial Monitor was successfully used for debugging and command testing.
