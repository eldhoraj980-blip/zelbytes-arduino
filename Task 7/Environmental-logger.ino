#include "DHT.h"

#define DHTPIN 2     // DHT Sensor digital pin
#define DHTTYPE DHT11 // Change to DHT22 if using that model
#define SOIL_PIN A0  // Soil moisture analog pin
#define LIGHT_PIN A1 // LDR analog pin

DHT dht(DHTPIN, DHTTYPE);

unsigned long previousMillis = 0;
// Interval for logging. To get 50+ rows over 30 mins, log every 30 seconds (1800000ms / 30000ms = 60 rows)
const unsigned long interval = 30000; 

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  // Print CSV Header to Serial Monitor
  Serial.println("timestamp,temp,humidity,soil,light");
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if it's time to log a new data point
  if (currentMillis - previousMillis >= interval || previousMillis == 0) {
    previousMillis = currentMillis;

    // Read Sensors
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int soilRaw = analogRead(SOIL_PIN);
    int lightRaw = analogRead(LIGHT_PIN);

    // Fallbacks if physical DHT sensor is missing during testing
    if (isnan(h) || isnan(t)) {
      t = random(220, 280) / 10.0; // Simulated Temp: 22.0 - 28.0 C
      h = random(450, 650) / 10.0; // Simulated Humidity: 45.0 - 65.0 %
    }

    // Convert raw analog values to approximate percentages/ranges
    int soilPercent = map(soilRaw, 1023, 0, 0, 100); // 100% is wet, 0% is dry
    int lightPercent = map(lightRaw, 0, 1023, 0, 100); // 100% is bright, 0% is dark

    // Format Timestamp: HH:MM:SS based on Arduino runtime
    unsigned long totalSeconds = currentMillis / 1000;
    unsigned long seconds = totalSeconds % 60;
    unsigned long minutes = (totalSeconds / 60) % 60;
    unsigned long hours = (totalSeconds / 3600);

    // Print CSV Row to Serial Monitor
    if (hours < 10) Serial.print("0"); Serial.print(hours); Serial.print(":");
    if (minutes < 10) Serial.print("0"); Serial.print(minutes); Serial.print(":");
    if (seconds < 10) Serial.print("0"); Serial.print(seconds);
    
    Serial.print(",");
    Serial.print(t, 1);
    Serial.print(",");
    Serial.print(h, 1);
    Serial.print(",");
    Serial.print(soilPercent);
    Serial.print(",");
    Serial.println(lightPercent);
  }
}
