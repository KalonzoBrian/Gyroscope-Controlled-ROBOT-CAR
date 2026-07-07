# Gyroscope-Controlled ROBOT CAR

A wireless gyroscope-based control system for a robot car that uses accelerometer and gyroscope sensors to detect movement and orientation, translating these into directional commands sent wirelessly to an Arduino-controlled vehicle via Bluetooth.

---

## 📋 Project Overview

This project implements an intuitive motion-based control interface for a robot car. By utilizing a gyroscope module (such as MPU6050 or GY-87), users can control the car's direction by tilting a controller device. The sensor readings are processed and transmitted wirelessly using a Bluetooth module to an onboard Arduino that manages the motor drivers and movement.

**Key Features:**
- Real-time gyroscope-based directional control
- Wireless Bluetooth communication
- Arduino-based motor control
- Simple and intuitive tilt-based interface
- Low-latency response to motion commands

---

## 🔧 Hardware Components

### Controller Side (Transmitter)
- **Gyroscope/Accelerometer Module**: MPU6050 or GY-87 IMU (Inertial Measurement Unit)
- **Microcontroller**: Arduino (Uno, Nano, or compatible)
- **Bluetooth Module**: HC-05 or HC-06 (transmitter configuration)
- **Power Supply**: Battery pack (5V for Arduino and sensors)

### Robot Car Side (Receiver)
- **Microcontroller**: Arduino (Uno, Nano, or compatible)
- **Motor Driver**: L298N DC motor driver module
- **DC Motors**: 2x motors for differential drive (tank-style movement)
- **Bluetooth Module**: HC-05 or HC-06 (receiver configuration)
- **Wheels & Chassis**: Robot car chassis with motors
- **Power Supply**: Battery pack (suitable voltage for motors and Arduino)

---

## 📡 System Architecture

```
Gyroscope Module → Arduino (Controller) → Bluetooth Module (TX)
                                           ↓
                                      Wireless Signal
                                           ↓
                                  Bluetooth Module (RX) → Arduino (Robot) → Motor Driver → DC Motors
```

### Signal Flow
1. **Sensor Reading**: Gyroscope and accelerometer detect tilt/rotation
2. **Data Processing**: Arduino processes sensor values and converts to direction commands
3. **Wireless Transmission**: Bluetooth module sends commands wirelessly
4. **Motor Control**: Receiver Arduino interprets commands and controls motor speeds/directions
5. **Movement**: Motor driver adjusts power to wheels for the desired motion

---

## 🎛️ Control Mapping

The gyroscope sensor's orientation translates to directional commands:
- **Tilt Forward**: Forward movement
- **Tilt Backward**: Backward movement
- **Tilt Left**: Left turn/rotation
- **Tilt Right**: Right turn/rotation
- **Level/Neutral**: Stop

The sensitivity and threshold values can be calibrated in the code to suit user preferences.

---

## 💻 Software Stack

- **Language**: C++ (Arduino sketches)
- **Communication Protocol**: Serial (Bluetooth UART)
- **Key Libraries**:
  - `MPU6050` or equivalent IMU driver library
  - `Wire.h` (I2C communication)
  - `SoftwareSerial.h` (or hardware Serial for Bluetooth)
  - Standard Arduino libraries

---

## 🚀 Getting Started

### Prerequisites
- Arduino IDE installed
- Required libraries installed (MPU6050, Wire, etc.)
- Bluetooth module paired and configured
- Hardware components assembled

### Installation Steps

1. **Clone the repository**
   ```bash
   git clone https://github.com/KalonzoBrian/Gyroscope-Controlled-ROBOT-CAR.git
   cd Gyroscope-Controlled-ROBOT-CAR
   ```

2. **Upload Controller Code**
   - Open the controller sketch in Arduino IDE
   - Select appropriate board and COM port
   - Upload to the controller Arduino

3. **Upload Robot Code**
   - Open the robot sketch in Arduino IDE
   - Select appropriate board and COM port
   - Upload to the robot's Arduino

4. **Pair Bluetooth Modules**
   - Configure HC-05 modules in AT mode if needed
   - Pair the controller Bluetooth module with the robot's module
   - Verify serial communication is working

5. **Calibration**
   - Calibrate gyroscope sensors for zero offset
   - Test sensitivity and adjust threshold values as needed

---

## 📚 Circuit Connections

### Gyroscope Module (MPU6050/GY-87) to Controller Arduino
```
MPU6050 → Arduino
VCC     → 5V
GND     → GND
SCL     → A5 (Arduino Uno)
SDA     → A4 (Arduino Uno)
```

### Bluetooth Module (HC-05) Connections

**Controller Arduino:**
```
HC-05 TX → Arduino RX (Pin 0) or Software Serial RX
HC-05 RX → Arduino TX (Pin 1) or Software Serial TX
VCC      → 5V
GND      → GND
```

**Robot Arduino:**
```
HC-05 TX → Arduino RX (Pin 0) or Software Serial RX
HC-05 RX → Arduino TX (Pin 1) or Software Serial TX
VCC      → 5V
GND      → GND
```

### Motor Driver (L298N) to Robot Arduino
```
L298N → Arduino/Motors
IN1   → Arduino Pin 8
IN2   → Arduino Pin 9
IN3   → Arduino Pin 10
IN4   → Arduino Pin 11
OUT1  → Motor 1 +
OUT2  → Motor 1 -
OUT3  → Motor 2 +
OUT4  → Motor 2 -
+12V  → Power Supply +
GND   → Power Supply - & Arduino GND
```

---

## 🔍 How It Works

1. **Sensor Data Acquisition**: The MPU6050 continuously reads gyroscope and accelerometer values
2. **Calibration & Filtering**: Raw sensor data is processed with calibration offsets and filtering algorithms
3. **Direction Computation**: Tilt angles are calculated and compared against threshold values
4. **Command Generation**: Direction commands are generated based on the current orientation
5. **Wireless Transmission**: Commands are sent via Bluetooth in a simple protocol format
6. **Reception & Interpretation**: The robot receives commands and maps them to motor control signals
7. **Motor Actuation**: The L298N driver adjusts motor speeds and directions accordingly

---

## 🧪 Testing & Troubleshooting

### Common Issues
- **No Bluetooth Connection**: Verify pairing, check serial configuration, test with Serial Monitor
- **Gyroscope Not Responding**: Check I2C connections (SDA/SCL), verify correct I2C address
- **Motors Not Moving**: Check motor connections, verify motor driver power supply, test with direct commands
- **Erratic Movement**: Calibrate gyroscope, adjust sensitivity thresholds, check for interference

### Debugging
- Use Serial Monitor to view sensor readings and transmitted commands
- Test individual components separately before full integration
- Verify Bluetooth communication with AT commands

---

## 📖 References

- [L298N DC Motor Driver Tutorial](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/)
- [GY-87 & MPU6050 Interfacing Guide](https://electropeak.com/learn/interfacing-gy-87-10dof-imu-mpu6050-hmc5883l-bmp085-module-with-arduino/)
- >[HC 05 Bluetooth module guide](https://projecthub.arduino.cc/RucksikaaR/interfacing-the-hc-06-bluetooth-module-with-arduino-94aabd)

---

## 🎯 Future Enhancements

- [ ] Add calibration utility for easier setup
- [ ] Implement PID control for smoother movement
- [ ] Add speed control via pressure sensitivity
- [ ] Implement obstacle avoidance with sensors
- [ ] Add LED feedback for connection status
- [ ] Support multiple control modes (gyroscope, accelerometer, hybrid)
- [ ] Create mobile app interface for alternative control

---

## 📄 License

This project is provided as-is for educational and personal use.

---

## 👤 Author

**KalonzoBrian**

For questions or suggestions, feel free to open an issue or reach out!
