#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C display(0x27, 20, 4);

void setup() {
  display.init();
  display.backlight();

  
}

void loop() {
  demo_info();
  delay(10000);
  demo();
  delay(10000);
}

void demo_info() {
  display.setCursor(0, 0);
  display.print("Welcome to AeroFace!");
  display.setCursor(0, 1);
  display.print("  Autopilot Module  ");
  display.setCursor(0, 2);
  display.print(" This is a demo and ");
  display.setCursor(0, 3);
  display.print("not a final version!");
}

void demo() {
  display.setCursor(0, 0);
  display.print("HDG:  090|  AeroFace");
  display.setCursor(0, 1);
  display.print("ALT:30000| Autopilot");
  display.setCursor(0, 2);
  display.print("VS :-1000|NAV: WRB3S");
  display.setCursor(0, 3);
  display.print("SP :  300|NEXT:DV240");
}