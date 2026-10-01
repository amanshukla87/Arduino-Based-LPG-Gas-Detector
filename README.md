# Arduino-Based LPG Gas Detector

A simple Arduino-based project for detecting LPG/combustible gas using an MQ-series gas sensor. The system gives a visual and audible alert when the sensor reading crosses a preset threshold.

## About the Project

This project was built to understand the basic working of an MQ gas sensor with Arduino and to implement a simple gas-alert system.

The sensor provides an analog output, which is read by the Arduino through **A0**. The reading is compared with a threshold value. Depending on the reading, the system stays in a safe state or activates the alarm.

### System response

- **Safe condition:** Green LED ON, Red LED OFF, Buzzer OFF
- **Alert condition:** Red LED ON, Green LED OFF, Buzzer ON
- **Serial Monitor:** Sensor reading displayed at **9600 baud**

> **Note:** This project uses a threshold-based detection method. The sensor reading is not converted into an actual LPG concentration in ppm. The threshold should be calibrated for the particular sensor, hardware setup, and environment.

## Components Used

- Arduino board
- MQ-6 / MQ-series gas sensor module
- Red LED
- Green LED
- Piezo buzzer
- Breadboard
- Jumper wires

## Pin Connections

| Component | Arduino Pin |
|---|---|
| Gas sensor analog output | A0 |
| Buzzer | D8 |
| Green LED | D9 |
| Red LED | D10 |

## How It Works

1. The MQ gas sensor produces an analog signal based on the detected gas level.
2. Arduino reads this signal from **A0** using `analogRead()`.
3. The sensor value is compared with the threshold set in the Arduino code.
4. If the value is above the threshold, the alarm condition is activated.
5. The red LED turns ON and the buzzer sounds.
6. If the value remains below the threshold, the green LED stays ON.
7. The sensor value is continuously sent to the Serial Monitor at **9600 baud**.

The current code uses a threshold value of **300**. This value is a project-level setting and can be changed after testing and calibration.

## Hardware Setup

### Project Setup

<p align="center">
  <img src="images/mq6-lpg-gas-detector-hardware-setup.jpeg" width="45%" alt="MQ-6 LPG gas detector hardware setup">
  <img src="images/mq6-lpg-gas-detector-hardware-setup-angle-02.jpeg" width="45%" alt="MQ-6 LPG gas detector hardware setup angle 02">
</p>

More hardware photos are available in the **images/** folder.

## Testing

The project was tested using the assembled hardware setup and Serial Monitor.

Project media is organized as follows:

- **Hardware photos:** `images/`
- **Testing videos:** `video/`

## Code

The Arduino sketch is available here:

`code/LPG_Gas_Detector.ino`

## Project Documentation

The complete project report is available in:

`documentation/Arduino-Based-LPG-Gas-Detector-Report.pdf`

## Limitations

- The system uses a simple analog threshold and is not a certified gas-safety device.
- MQ-series sensors need proper warm-up and calibration for consistent readings.
- The current implementation displays raw analog sensor values rather than calibrated LPG concentration.
- Sensor readings can vary with the environment and the particular sensor module.

## Possible Improvements

Some improvements that could be added in a future version:

- Add an automatic sensor warm-up and calibration routine.
- Add an LCD or OLED to display the sensor value and alarm status.
- Store sensor readings for later analysis.
- Add a more suitable concentration-estimation method after proper calibration.
- Add a relay or exhaust-control interface with appropriate electrical isolation and safety precautions.

## Author

**Aman Shukla**

Electronics Engineering | Embedded Systems & Sensors

---

This project is part of my hands-on work with **Arduino, sensors, embedded C/C++, and basic hardware interfacing**.
