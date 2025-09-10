# NTC_FanControl_Arduino

Tinkercad Link :-- https://www.tinkercad.com/things/44L40epDIZu-ntcfancontrolarduino?sharecode=Yrfni9jwOrZ4T_YGP4j2DP-hGXzoJxSwWI9CNFdNUvw

This project simulates a **temperature-controlled fan system** using an Arduino Uno.  
Since Tinkercad does not have a thermistor component, we use a **potentiometer** to simulate a **10k NTC thermistor**.  
The fan is represented by an **LED** connected to a PWM pin.

---

## 📌 Features
- Reads "temperature" from a **potentiometer acting as an NTC thermistor**.
- Converts analog input into a **temperature range (0 °C to 50 °C)** with inverted mapping:
  - Potentiometer low → High temperature  
  - Potentiometer high → Low temperature  
- Controls a **fan (LED)** with three states:
  - **OFF** below 25 °C                 (analogWrite value is 0)
  - **Half ON** between 25 °C and 30 °C (analogWrite value is 100 to notice the brightness difference)
  - **Full ON** above 30 °C             (analogWrite value is 255 complete value)
- Displays **temperature and fan state** on the Arduino Serial Monitor.

---

## 🛠️ Components
- Arduino Uno  
- 10kΩ Potentiometer (simulating NTC thermistor)  
- 10kΩ Fixed resistor (voltage divider)  
- LED (Fan indicator)  
- 220Ω Resistor (current limiting for LED)  
- Breadboard + jumper wires  

---

## 🔌 Circuit Connections

### Voltage Divider (NTC Simulation)
- Potentiometer:
  - One leg → **5V**
  - Middle leg (wiper) → **A0**
  - Other leg → (optional, can be left unconnected or tied to 5V)
- Fixed 10kΩ resistor:
  - One end → **A0**
  - Other end → **GND**

### Fan (LED)
- Arduino pin **11 (PWM)** → 220Ω resistor → LED → GND

---
