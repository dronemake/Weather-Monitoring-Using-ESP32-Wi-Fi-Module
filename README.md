# ESP32 Wi-Fi Weather Monitor 🌤️

A beginner-friendly weather monitor project using ESP32, OpenWeatherMap API, and OLED display.

## 🔧 Requirements
- ESP32 Dev Board
- OLED Display (0.96" I2C SSD1306)
- Wi-Fi connection
- Jumper Wires & Breadboard

## 📦 Libraries
- `Adafruit_SSD1306`
- `Adafruit_GFX`
- `ArduinoJson`
- `WiFi`
- `HTTPClient`

## 🔌 Circuit Diagram
**VCC** → 3.3V on ESP32  
**GND** → GND  
**SCL** → GPIO22  
**SDA** → GPIO21

## 📡 Setup
1. Replace WiFi credentials and API key in the code.
2. Upload using Arduino IDE.
3. Monitor serial output or view on OLED screen.

## 🌐 API Used
[OpenWeatherMap API](https://openweathermap.org/api)

---

Made with ❤️ by Gajendra Verma
