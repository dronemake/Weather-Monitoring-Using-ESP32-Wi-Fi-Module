#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const String API_KEY = "YOUR_API_KEY";
const String CITY = "Delhi";
const String COUNTRY = "IN";

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Connecting WiFi...");
  display.display();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    display.print(".");
    display.display();
  }
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("WiFi Connected!");
  display.display();
  delay(1000);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "http://api.openweathermap.org/data/2.5/weather?q=" + CITY + "," + COUNTRY + "&appid=" + API_KEY + "&units=metric";
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);
      float temperature = doc["main"]["temp"];
      float humidity = doc["main"]["humidity"];
      String weather = doc["weather"][0]["main"];
      Serial.println("Temp: " + String(temperature));
      Serial.println("Humidity: " + String(humidity));
      Serial.println("Weather: " + weather);
      display.clearDisplay();
      display.setCursor(0, 0);
      display.setTextSize(1);
      display.println("Weather in " + CITY);
      display.println("----------------------");
      display.println("Temp: " + String(temperature) + " C");
      display.println("Humidity: " + String(humidity) + "%");
      display.println("Status: " + weather);
      display.display();
    } else {
      Serial.println("HTTP Request failed");
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
  delay(10000);
}
