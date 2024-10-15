# Car Parking Sensor 🚗
Smart Home Automation Using ATmega32, LCD, Temperature Sensor, LDR Sensor, Flame Sensor and Motor Contro

**Features:**
- Ultrasonic Distance Measurement: Detects and displays distance on an LCD.
- LED Indicators: Red, Green, and Blue LEDs light up based on proximity.
- Buzzer Alert: Sounds when an obstacle is closer than 5 cm.
  
**LED & Buzzer Behavior**
- ≤ 5 cm: All LEDs flash + buzzer + "Stop" on LCD.
- 6-10 cm: All LEDs ON (no buzzer).
- 11-15 cm: Red and Green LEDs ON.
- 16-20 cm: Red LED ON.
- > 20 cm: All LEDs OFF + buzzer OFF
