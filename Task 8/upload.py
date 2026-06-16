import requests
import random
import time
from secrets import API_KEY

# Replace this with your real telemetry URL
API_URL = "https://careers.zelbytes.com/api/iot-lab/v1/telemetry"

DEVICE_ID = "uno_bench_01"

headers = {
    "X-Iot-Lab-Key": API_KEY,
    "Content-Type": "application/json"
}

for i in range(10):
    payload = {
        "device_id": DEVICE_ID,
        "temperature_c": round(random.uniform(25, 35), 1),
        "humidity_pct": random.randint(60, 90),
        "soil_moisture_pct": random.randint(30, 80),
        "light_level": random.randint(500, 1000)
    }

    response = requests.post(API_URL, headers=headers, json=payload)

    print("Sent:", payload)
    print("Status:", response.status_code)
    print("Response:", response.text)

    time.sleep(2)