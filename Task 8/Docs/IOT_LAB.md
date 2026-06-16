# IoT Lab Documentation

## Task

Task 8: Zelbytes IoT Lab — First Cloud Post

## Objective

Post telemetry data to Zelbytes IoT Learning Lab using Python.

## Device ID

uno_bench_01

## API Endpoint

/api/iot-lab/v1/telemetry

## Method Used

Host-side Python script with simulated telemetry data.

## Authentication

API key stored in gitignored secrets.py file.

## JSON Field Mapping

* temperature_c → Temperature in Celsius
* humidity_pct → Humidity Percentage
* soil_moisture_pct → Soil Moisture Percentage
* light_level → Light Sensor Reading

## Sample Payload

{
"device_id": "uno_bench_01",
"temperature_c": 29.5,
"humidity_pct": 72,
"soil_moisture_pct": 48,
"light_level": 850
}

## Result

Successfully sent 10 telemetry samples using HTTPS POST.

Server Response:
HTTP 202 Accepted
