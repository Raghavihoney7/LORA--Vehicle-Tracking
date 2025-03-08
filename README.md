### README for LoRa GPS Communication

## 📌 Project Overview
This project implements a **LoRa-based GPS communication system** using **TinyGPS++**, **SoftwareSerial**, and **LoRa E32 modules**. The system consists of a **transmitter** that sends GPS coordinates over LoRa and a **receiver** that parses and displays the received data.

---

## 📜 Features
- **LoRa-based communication** between two modules.
- **GPS data retrieval** using TinyGPS++ library.
- **Parsing and extraction** of latitude and longitude.
- **AT Command Configuration** for setting LoRa addresses and network ID.

---

## 🛠️ Hardware Requirements
- **Arduino Uno/Nano**
- **LoRa E32 433/915MHz Module**
- **GPS Module (Neo-6M or similar)**
- **Jumper Wires**
- **OLED Display (Optional for visual output)**

---

## 📂 File Structure
```
│── transmitter.ino   # Sends GPS data over LoRa
│── receiver.ino      # Receives and parses GPS data
│── README.md         # Documentation
```

---

## 🚀 Getting Started

### 1️⃣ **Wiring**
| **LoRa Module** | **Arduino** |
|-------------|---------|
| M0, M1 | GND (for normal mode) |
| TX | Pin 8 |
| RX | Pin 9 |
| VCC | 3.3V |
| GND | GND |

| **GPS Module** | **Arduino** |
|-------------|---------|
| TX | Pin 10 |
| RX | Pin 11 |
| VCC | 5V |
| GND | GND |

---

### 2️⃣ **Installation**
1. **Clone the repository**  
   ```sh
   git clone https://github.com/yourusername/lora-gps.git
   cd lora-gps
   ```
2. **Install Arduino Libraries**  
   - [TinyGPS++](https://github.com/mikalhart/TinyGPSPlus)
   - SoftwareSerial (Built-in)

---

### 3️⃣ **Usage**
#### **Uploading the Code**
1. Upload **`transmitter.ino`** to the first Arduino (LoRa sender).
2. Upload **`receiver.ino`** to the second Arduino (LoRa receiver).
3. Open the **Serial Monitor** at 9600 baud rate.

#### **Expected Output**
- **Transmitter Output:**
  ```
  Location: 17.3850, 78.4867
  Sent: AT+SEND=2,15,17.3850/78.4867
  ```
- **Receiver Output:**
  ```
  Received data: RCV=17.3850/78.4867
  Latitude: 17.3850
  Longitude: 78.4867
  ```

---

## 🛠️ Troubleshooting
- **No GPS Data?**  
  - Check GPS module wiring.
  - Ensure GPS is outdoors for better signal.
- **LoRa Not Communicating?**  
  - Verify **M0, M1 pins** are set correctly.
  - Check **baud rate and addresses**.

---

