# Smart Grow Bench Irrigation System

## Project Description

This project is an IoT-based smart irrigation system designed to automate watering in a grow bench environment. Using an ESP32 microcontroller and a soil moisture sensor, the system continuously monitors soil conditions and automatically activates a solenoid valve when the soil becomes dry. The project also supports manual override, web-based control, and telemetry upload for remote monitoring.

---

## Intern Details

**Name:** Eldho Raj
**Branch:** Electronics and Communication Engineering
**Platform:** Arduino IDE
**Project:** Smart Grow Bench Irrigation System

---

## Objectives

* Monitor soil moisture in real time
* Automate irrigation based on soil conditions
* Provide manual override using a button
* Enable remote monitoring via cloud telemetry
* Support serial and web-based control

---

## Hardware Components

* ESP32 DevKit
* Soil Moisture Sensor
* Relay Module
* Solenoid Valve
* LED
* Push Button
* 220Ω Resistor
* External Power Supply
* Jumper Wires

---

## Circuit Connections

### Soil Sensor

* VCC → 3.3V
* GND → GND
* AO → GPIO34

### Relay Module

* VCC → 5V
* GND → GND
* IN → GPIO26

### Button

* One side → GPIO27
* Other side → GND

### LED

* Anode → GPIO2 via 220Ω resistor
* Cathode → GND

### Solenoid Valve

* Valve + → External Supply +
* Valve − → Relay NO
* Relay COM → Supply −

---

## Firmware Features

### Automatic Irrigation

The ESP32 reads soil moisture and activates irrigation automatically when the moisture level crosses the dry threshold.

### Manual Override

A push button allows switching between automatic and manual control.

### Serial Commands

Supported commands:

* `STATUS`
* `FORCE_ON`
* `FORCE_OFF`

### Web Server Endpoints

* `/on`
* `/off`
* `/status`

### Cloud Telemetry

Soil moisture data is uploaded periodically to the Zelbytes IoT Lab server for remote monitoring.

---

## Calibration Data

* Dry Soil Reading: 1500
* Wet Soil Reading: 2069
* Threshold: 2000

---

## Repository Structure

```text
zelbytes-arduino/
│
├── README.md
├── grow_bench_final.ino
│   
├── docs/
│   └── FINAL_REPORT.md
└── images/
```

---

## Setup Instructions

1. Install Arduino IDE
2. Install ESP32 board package
3. Install required libraries:

   * WiFi
   * HTTPClient
   * WebServer
4. Connect ESP32 via USB
5. Select **ESP32 Dev Module**
6. Upload firmware
7. Open Serial Monitor at **115200 baud**

---

## Final Report

Detailed technical documentation is available in:

`docs/FINAL_REPORT.md`
