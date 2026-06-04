#define IRRIGATION_SECONDS 5

const uint8_t LED_STATUS = 13;
const uint8_t BTN_MANUAL = 2;
const uint8_t RELAY_VALVE = 8;

const unsigned long DEBOUNCE_MS = 50;

bool lastReading = HIGH;
bool stableState = HIGH;
unsigned long lastDebounceTime = 0;

bool irrigationActive = false;
unsigned long irrigationStartMs = 0;

void setValve(bool open) {
  digitalWrite(RELAY_VALVE, open ? HIGH : LOW);
  // If your relay is active-low, use:
  // digitalWrite(RELAY_VALVE, open ? LOW : HIGH);
}

bool buttonPressed() {
  bool reading = digitalRead(BTN_MANUAL);

  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_MS) {
    stableState = reading;
  }

  lastReading = reading;

  return (stableState == LOW);
}

void logIrrigationEvent() {
  Serial.print(F("[EVENT] Irrigation Started | Timestamp="));
  Serial.print(millis() / 1000);
  Serial.println(F(" sec since boot"));
}

void setup() {
  pinMode(LED_STATUS, OUTPUT);
  pinMode(BTN_MANUAL, INPUT_PULLUP);
  pinMode(RELAY_VALVE, OUTPUT);

  setValve(false);

  Serial.begin(9600);

  Serial.println(F("================================"));
  Serial.println(F("Task 3 - Manual Irrigation Toggle"));
  Serial.println(F("Release: v0.1-manual"));
  Serial.print(F("Duration: "));
  Serial.print(IRRIGATION_SECONDS);
  Serial.println(F(" sec"));
  Serial.println(F("================================"));
}

void loop() {

  // Start irrigation on button press
  if (buttonPressed() && !irrigationActive) {

    irrigationActive = true;
    irrigationStartMs = millis();

    setValve(true);
    digitalWrite(LED_STATUS, HIGH);

    logIrrigationEvent();
  }

  // Stop irrigation after configured duration
  if (irrigationActive &&
      (millis() - irrigationStartMs >= (IRRIGATION_SECONDS * 1000UL))) {

    irrigationActive = false;

    setValve(false);
    digitalWrite(LED_STATUS, LOW);

    Serial.print(F("[EVENT] Irrigation Ended | Timestamp="));
    Serial.print(millis() / 1000);
    Serial.println(F(" sec since boot"));
  }
}
