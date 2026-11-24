#include <Wire.h>

#define SDA_PIN 5  // D4 on XIAO ESP32-S3
#define SCL_PIN 6  // D5 on XIAO ESP32-S3

void setup() {

  Serial.begin(115200);
  // Enable "USB CDC On Boot" in Arduino Tools menu to see Serial output
  while (!Serial) delay(10);

  Wire.begin(SDA_PIN, SCL_PIN);
  Serial.println("\nXIAO ESP32-S3 I2C Scanner ready...");
}

void loop() {
  byte error, address;
  int nDevices = 0;

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Device found at 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    }
  }

  if (nDevices == 0) {
    Serial.println("No I2C devices found");
  }
  delay(2000);
}