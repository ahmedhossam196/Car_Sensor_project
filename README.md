# Car Parking Sensor 🚗
Smart Home Automation Using ATmega32, LCD, Temperature Sensor, LDR Sensor, Flame Sensor and Motor Contro

**Lighting Control:**
- LDR Sensor: Measures ambient light levels.
**LED Responses:**
- 0 - 15%: All LEDs ON (Red, Green, Blue).
- 16–50%: Red and Green LEDs ON.
- 51–69%: Red LED ON.
- 70 - 100%: All LEDs OFF.

**Fan Speed Control:**
- LM35 Sensor: Monitors temperature.
**Fan Speed Adjustments:**
- ≥ 40°C: 100% speed.
- 35–39°C: 75% speed.
- 30–34°C: 50% speed.
- 25–29°C: 25% speed.
- ≤ 24°C: OFF.
  
**Fire Detection:**
- Flame Sensor: Detects flames.
- Alerts:
Sounds a buzzer.
Displays "Critical Alert!" on a 16x2 LCD.

**Real-Time Feedback:**
- LCD Display: Shows current temperature and light levels continuously.
