#include <RotaryEncoder.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_MCP23X17.h>

LiquidCrystal_I2C display(0x27, 20, 4);
Adafruit_MCP23X17 knobs;
Adafruit_MCP23X17 buttons;

long command;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.write("AeroFace_Autopilot");

  buttons.begin_I2C();

  display.init();

  display.setCursor(0, 0);
  display.println("Welcome to AeroFace!");
  display.println("  Autopilot Module  ");
  display.println("  Awaiting input... ");
  display.println("                    ");

  // TODO: Pin setup
}

void loop() {
  if (Serial.available()) {
    int leds = Serial.read();
    display.println(Serial.readStringUntil('\n'));
    display.println(Serial.readStringUntil('\n'));
    display.println(Serial.readStringUntil('\n'));
    display.println(Serial.readStringUntil('\n'));

    for (int i = 0; i < 9; i++) {
      if ((leds & (1 << i)) != 0) {
        digitalWrite(i + 2, HIGH);
      } else {
        digitalWrite(i + 2, LOW);
      }
    }

    for (int i = 0; i < 4; i++) {
      if ((leds & (1 << (i + 9))) != 0) {
        knobs.digitalWrite((i * 4) + 3, HIGH);
      } else {
        knobs.digitalWrite((i * 4) + 3, LOW);
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    command |= buttons.digitalRead(i) << i;
  }
}