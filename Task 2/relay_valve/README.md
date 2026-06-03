# Day 5 – Relay and Solenoid Valve

## Objective

Safely control a solenoid valve using a relay module.

## Relay Connection

Relay IN -> Arduino Pin 8
Relay VCC -> 5V
Relay GND -> GND

## Commands

v -> Activate valve briefly

e -> Emergency stop

## Safety

Valve is OFF during startup.
Relay only drives the valve.
Valve is never connected directly to Arduino.
