# 🌱 IoT Smart Monitoring & Control System

This project is an **IoT-based smart monitoring system** built using an **Arduino Uno**, **LCD display**, **ultrasonic sensor**, **soil moisture sensor**, and **two servo motors**.  
The system monitors environmental parameters and performs automated actions using the connected hardware components.

---

## 📌 Features

- **Soil Moisture Monitoring**  
  Reads real-time soil moisture values using a capacitive moisture sensor.

- **Distance / Object Detection**  
  Utilizes the HC-SR04 ultrasonic sensor for distance measurement.

- **LCD Display (16x2)**  
  Continuously displays sensor readings and system status.

- **Servo Motor Control**  
  Two servo motors respond to sensor readings (for example: gate control, water dispenser, or mechanical response).

- **Modular & Expandable**  
  Easy to modify for smart farming, automation, or IoT-based decision systems.

---

## 🛠️ Components Used

| Component | Quantity |
|----------|----------|
| Arduino Uno | 1 |
| 16x2 LCD (I2C or Parallel) | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Soil Moisture Sensor | 1 |
| Servo Motor (SG90 or similar) | 2 |
| Breadboard & Jumper Wires | – |

---

## 🔌 Circuit Diagram

The full wiring diagram is provided in the repository (Tinkercad export):

**File: `Iot Project.png`**

It includes connections for:
- LCD display  
- Ultrasonic sensor  
- Soil moisture sensor  
- Servo motors  
- Arduino power rails

---

## 📂 Project Files

- `iot_project1.ino` – Arduino source code  
- `Iot Project.png` – Circuit schematic  
- `Iot Project.pdf` – PDF version of the wiring/preliminary documentation  
- `bom.csv` – Bill of materials

---

## ▶️ How It Works

1. **Arduino reads the soil moisture level** from the analog pin.  
2. **HC-SR04 measures distance** and detects objects or water level.  
3. Readings are printed on the **LCD display** in real time.  
4. Depending on threshold values:  
   - Servo motors activate (open/close mechanism).  
   - Optional automation logic can be added (e.g., pump control).  

---

## 🚀 Getting Started

### 1. Upload Code
Open the `.ino` file in the Arduino IDE and upload it to the Arduino Uno.

### 2. Connect Hardware
Follow the wiring shown in the diagram (`Iot Project.png`).

### 3. Power the System
You can power the Arduino through:
- USB cable  
- External 5V supply (regulated)

---

## 📜 License
This project is open-source. You can modify and use it for personal or educational purposes.

---

## 🙌 Author
Created by **[Your Name]**  
For questions or improvements, feel free to open an issue or contribute!
