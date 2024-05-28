#include <Firmata.h>

#include <RotaryEncoder.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_MCP23X17.h>

#define EncoderMode RotaryEncoder::LatchMode::FOUR0

LiquidCrystal_I2C display(0x27, 20, 4);
Adafruit_MCP23X17 leds;
Adafruit_MCP23X17 buttons;

RotaryEncoder encoder1(2, 3, EncoderMode);
RotaryEncoder encoder2(4, 5, EncoderMode);
RotaryEncoder encoder3(6, 7, EncoderMode);
RotaryEncoder encoder4(8, 9, EncoderMode);

const uint8_t PACKET_COMMAND = 0xAA;

void firmata_callback(char* input) {
  // Recieving
  int cmd = 0;

  char* ptr = strtok(input, "\n");
  byte i = 0;
  while (ptr) {
    if (i < 1) {
      cmd = atol(ptr);
    } else {
      display.setCursor(0, i - 1);
      display.print(ptr);
    }
    ptr = strtok(NULL, "\n");
    i++;
  }

  // for (int i = 0; i < 14; i++) {
  //   if (((1 << i) & cmd) != 0) {
  //     leds.digitalWrite(i, HIGH);
  //   } else {
  //     leds.digitalWrite(i, LOW);
  //   }
  // }

  // Sending
  int state = 0;
  // for (int i = 0; i < 14; i++) {
  //   state |= ((~buttons.digitalRead(i)) << i);
  // }

  char enc1 = min(-128, max(encoder1.getPosition(), 127)) & 0xFF;
  char enc2 = min(-128, max(encoder2.getPosition(), 127)) & 0xFF;
  char enc3 = min(-128, max(encoder3.getPosition(), 127)) & 0xFF;
  char enc4 = min(-128, max(encoder4.getPosition(), 127)) & 0xFF;

  encoder1.setPosition(0);
  encoder2.setPosition(0);
  encoder3.setPosition(0);
  encoder4.setPosition(0);

  char stateBig = (state >> 8) & 0xFF;
  char stateSmall = state & 0xFF;
  char response[7] = {stateBig, stateSmall, enc1, enc2, enc3, enc4, '\0'};
  Firmata.sendString(response);
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  buttons.begin_I2C(0x20);
  leds.begin_I2C(0x22);

  display.init();
  display.backlight();

  display.setCursor(0, 0);
  display.print("Welcome to AeroFace!");
  display.setCursor(0, 1);
  display.print("  Autopilot Module  ");
  display.setCursor(0, 2);
  display.print("  Awaiting input... ");
  display.setCursor(0, 3);
  display.print("                    ");

  Firmata.setFirmwareVersion(FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);
  Firmata.attach(STRING_DATA, firmata_callback);
  Firmata.begin(57600);

  // for (int i = 0; i < 13; i++) {
  //   leds.pinMode(i, OUTPUT);
  //   buttons.pinMode(i, INPUT_PULLUP);
  // }

  Serial.println("AeroFace_Autopilot");
}

void loop() {
  
}