# Methodology

1. Initialize sensors and outputs.
2. Enter IDLE state at startup.
3. Transition to MONITORING state.
4. Continuously read:

   * Soil moisture
   * Humidity
5. If soil moisture remains below 25% for three consecutive readings:

   * Start irrigation.
6. Open valve through relay.
7. Continue irrigation until:

   * Moisture reaches 40%, or
   * Maximum runtime expires.
8. Enter COOLDOWN state.
9. Wait 5 seconds.
10. Return to MONITORING state.
11. If DHT22 fails three consecutive readings:

* Enter FAULT state.
* Close valve.
* Blink status LED.
