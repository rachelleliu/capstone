// Basic demo for Adafruit DRV2605L
// Adapted for XIAO ESP32-S3

#include <Wire.h>
#include <Adafruit_DRV2605.h>

Adafruit_DRV2605 drv;

uint8_t effect = 1;

const char* effectNames[] = {
  "Stop",
  "Strong Click - 100%",
  "Strong Click - 60%",
  "Strong Click - 30%",
  "Sharp Click - 100%",
  "Sharp Click - 60%",
  "Sharp Click - 30%",
  "Soft Bump - 100%",
  "Soft Bump - 60%",
  "Soft Bump - 30%",
  "Double Click - 100%",
  "Double Click - 60%",
  "Triple Click - 100%",
  "Soft Fuzz - 60%",
  "Strong Buzz - 100%",
  "750 ms Alert - 100%",
  "1000 ms Alert - 100%",
  "Strong Click 1 - 100%",
  "Strong Click 2 - 80%",
  "Strong Click 3 - 60%",
  "Strong Click 4 - 30%",
  "Medium Click 1 - 100%",
  "Medium Click 2 - 80%",
  "Medium Click 3 - 60%",
  "Sharp Tick 1 - 100%",
  "Sharp Tick 2 - 80%",
  "Sharp Tick 3 - 60%",
  "Short Double Click Strong 1 - 100%",
  "Short Double Click Strong 2 - 80%",
  "Short Double Click Strong 3 - 60%",
  "Short Double Click Strong 4 - 30%",
  "Short Double Click Medium 1 - 100%",
  "Short Double Click Medium 2 - 80%",
  "Short Double Click Medium 3 - 60%",
  "Short Double Sharp Tick 1 - 100%",
  "Short Double Sharp Tick 2 - 80%",
  "Short Double Sharp Tick 3 - 60%",
  "Long Double Sharp Click Strong 1 - 100%",
  "Long Double Sharp Click Strong 2 - 80%",
  "Long Double Sharp Click Strong 3 - 60%",
  "Long Double Sharp Click Strong 4 - 30%",
  "Long Double Sharp Click Medium 1 - 100%",
  "Long Double Sharp Click Medium 2 - 80%",
  "Long Double Sharp Click Medium 3 - 60%",
  "Long Double Sharp Tick 1 - 100%",
  "Long Double Sharp Tick 2 - 80%",
  "Long Double Sharp Tick 3 - 60%",
  "Buzz 1 - 100%",
  "Buzz 2 - 80%",
  "Buzz 3 - 60%",
  "Buzz 4 - 40%",
  "Buzz 5 - 20%",
  "Pulsing Strong 1 - 100%",
  "Pulsing Strong 2 - 60%",
  "Pulsing Medium 1 - 100%",
  "Pulsing Medium 2 - 60%",
  "Pulsing Sharp 1 - 100%",
  "Pulsing Sharp 2 - 60%",
  "Transition Click 1 - 100%",
  "Transition Click 2 - 80%",
  "Transition Click 3 - 60%",
  "Transition Click 4 - 40%",
  "Transition Click 5 - 20%",
  "Transition Click 6 - 10%",
  "Transition Hum 1 - 100%",
  "Transition Hum 2 - 80%",
  "Transition Hum 3 - 60%",
  "Transition Hum 4 - 40%",
  "Transition Hum 5 - 20%",
  "Transition Hum 6 - 10%",
  "Transition Ramp Down Long Smooth 1 - 100 to 0%",
  "Transition Ramp Down Long Smooth 2 - 100 to 0%",
  "Transition Ramp Down Medium Smooth 1 - 100 to 0%",
  "Transition Ramp Down Medium Smooth 2 - 100 to 0%",
  "Transition Ramp Down Short Smooth 1 - 100 to 0%",
  "Transition Ramp Down Short Smooth 2 - 100 to 0%",
  "Transition Ramp Down Long Sharp 1 - 100 to 0%",
  "Transition Ramp Down Long Sharp 2 - 100 to 0%",
  "Transition Ramp Down Medium Sharp 1 - 100 to 0%",
  "Transition Ramp Down Medium Sharp 2 - 100 to 0%",
  "Transition Ramp Down Short Sharp 1 - 100 to 0%",
  "Transition Ramp Down Short Sharp 2 - 100 to 0%",
  "Transition Ramp Up Long Smooth 1 - 0 to 100%",
  "Transition Ramp Up Long Smooth 2 - 0 to 100%",
  "Transition Ramp Up Medium Smooth 1 - 0 to 100%",
  "Transition Ramp Up Medium Smooth 2 - 0 to 100%",
  "Transition Ramp Up Short Smooth 1 - 0 to 100%",
  "Transition Ramp Up Short Smooth 2 - 0 to 100%",
  "Transition Ramp Up Long Sharp 1 - 0 to 100%",
  "Transition Ramp Up Long Sharp 2 - 0 to 100%",
  "Transition Ramp Up Medium Sharp 1 - 0 to 100%",
  "Transition Ramp Up Medium Sharp 2 - 0 to 100%",
  "Transition Ramp Up Short Sharp 1 - 0 to 100%",
  "Transition Ramp Up Short Sharp 2 - 0 to 100%",
  "Transition Ramp Down Long Smooth 1 - 50 to 0%",
  "Transition Ramp Down Long Smooth 2 - 50 to 0%",
  "Transition Ramp Down Medium Smooth 1 - 50 to 0%",
  "Transition Ramp Down Medium Smooth 2 - 50 to 0%",
  "Transition Ramp Down Short Smooth 1 - 50 to 0%",
  "Transition Ramp Down Short Smooth 2 - 50 to 0%",
  "Transition Ramp Down Long Sharp 1 - 50 to 0%",
  "Transition Ramp Down Long Sharp 2 - 50 to 0%",
  "Transition Ramp Down Medium Sharp 1 - 50 to 0%",
  "Transition Ramp Down Medium Sharp 2 - 50 to 0%",
  "Transition Ramp Down Short Sharp 1 - 50 to 0%",
  "Transition Ramp Down Short Sharp 2 - 50 to 0%",
  "Transition Ramp Up Long Smooth 1 - 0 to 50%",
  "Transition Ramp Up Long Smooth 2 - 0 to 50%",
  "Transition Ramp Up Medium Smooth 1 - 0 to 50%",
  "Transition Ramp Up Medium Smooth 2 - 0 to 50%",
  "Transition Ramp Up Short Smooth 1 - 0 to 50%",
  "Transition Ramp Up Short Smooth 2 - 0 to 50%",
  "Transition Ramp Up Long Sharp 1 - 0 to 50%",
  "Transition Ramp Up Long Sharp 2 - 0 to 50%",
  "Transition Ramp Up Medium Sharp 1 - 0 to 50%",
  "Transition Ramp Up Medium Sharp 2 - 0 to 50%",
  "Transition Ramp Up Short Sharp 1 - 0 to 50%",
  "Transition Ramp Up Short Sharp 2 - 0 to 50%",
  "Long Buzz for Programmatic Stopping - 100%",
  "Smooth Hum 1 (No kick or brake pulse) - 50%",
  "Smooth Hum 2 (No kick or brake pulse) - 40%",
  "Smooth Hum 3 (No kick or brake pulse) - 30%",
  "Smooth Hum 4 (No kick or brake pulse) - 20%",
  "Smooth Hum 5 (No kick or brake pulse) - 10%"
};

void setup() {
  Serial.begin(115200);
  while (!Serial)
    delay(10);

  Serial.println("Adafruit DRV2605L test!");

  Wire.begin(5, 6);

  if (!drv.begin(&Wire)) {
    Serial.println("Failed to find DRV2605L chip");
    while (1) {
      delay(10);
    }
  }

  Serial.println("DRV2605L Found!");

  // Configure for ERM vibration motor
  drv.useERM();

  // Select waveform library
  drv.selectLibrary(1);

  // Internal trigger mode
  drv.setMode(DRV2605_MODE_INTTRIG);
}

void loop() {

  if (effect == 1) {
    Serial.println();
    Serial.println("Waveform Library Effects List");
    Serial.println("-----------------------------");
  }

  // Print effect number and name
  Serial.print(effect);
  Serial.print(" - ");
  Serial.println(effectNames[effect]);

  // Set the effect to play
  drv.setWaveform(0, effect);
  drv.setWaveform(1, 0);

  // Play the effect
  drv.go();

  // Wait before playing the next effect
  delay(1500);

  // Stop any effect that is still playing
  drv.stop();

  effect++;

  if (effect > 123) {
    effect = 1;
  }
}