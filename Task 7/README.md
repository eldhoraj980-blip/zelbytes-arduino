# Task 7: CSV Data Logging

## Objective
Log a 30-minute sensor dataset containing environmental variables (timestamp, temperature, humidity, soil moisture, light intensity) via host-side Serial logging to produce a standardized CSV dataset.

## Repository Structure
├── task7_logger.ino     # Arduino sketch for reading sensors and outputting CSV format
└── data/
    └── sample_log.csv   # Captured 30-minute dataset (min 50 rows)

## How to Reproduce the Capture

### 1. Hardware Setup
Connect your sensors to the Arduino using the following pin layout:
* **DHT11/DHT22 (Temp/Humidity):** Data Pin -> Digital Pin 2
* **Soil Moisture Sensor:** Analog Out -> Analog Pin A0
* **LDR Light Sensor:** Voltage Divider Out -> Analog Pin A1

### 2. Software Compilation
1. Open `task7_logger.ino` inside the Arduino IDE.
2. Install the **DHT Sensor Library by Adafruit** via the Library Manager (`Ctrl+Shift+I` / `Cmd+Shift+I`).
3. Select your correct Board and COM Port under **Tools**, then click **Upload**.

### 3. Capturing Data to CSV
Because this project utilizes host-side serial capture, follow these steps to save the data:
1. Keep the Arduino connected to your PC for at least 30 minutes.
2. Open the **Arduino IDE Serial Monitor** (Set Baud Rate to `9600`).
3. Uncheck "Show timestamp" in the built-in IDE monitor window settings so it doesn't conflict with our custom formatted timestamp column.
4. Leave it running until at least 50 rows have printed (approx. 25–30 minutes at a 30-second intervals).
5. Copy the entire text output from the Serial Monitor window.
6. Open a plain text editor (like Notepad or VS Code), paste the text, and save the file as `sample_log.csv` inside a folder named `data`.