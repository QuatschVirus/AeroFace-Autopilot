# How to make it yourself
Building the Autopilot yourselves is not necessarily a complicated, but rather just tedious task.
## Requirements
You more or less obviously need a 3D-printer and/or access to one. Ideally, you are also familiar with 3D printing and -modelling, should you need to adapt it to your needs. You should be able to solder, and have a minor understanding of electronics.
## Parts
If I provide links, those are the parts I used. You can substitute them for something with similar function, just beware that you may need to change the models to make them fit:
- Any microcontroller or comparable minicomputer. It needs to have I2C and ideally 8 GPIO pins with an Input pullup option (or just add $10k\Omega$ resistors to 5V yourself). I used an Arduino Uno for the first try, but will probably use a Raspberry Pi Zero for the final version because I do not understand the Arduino Code.
- An I2C-enabled 20x4 LCD display [like this one](https://www.sunfounder.com/products/i2c-lcd2004-module)
- Two 16bit I2C expander boards, [for example these](https://www.az-delivery.de/en/products/mcp23017-serielles-interface-modul)
- 9 simple pushbutton switches, [see these](https://www.electrokit.com/en/tryckknapp-1-pol-off-onmetall-bla-lodoron)
- 4 Incremental Rotary Encoders with integrated pushbutton switches, [like these](https://www.electrokit.com/en/rotationsenkoder-24-p/v-med-tryckknapp-fasta-lagen) plus accompaning [knobs](https://www.electrokit.com/en/ratt-gummi-svart-16x14.7mm-d-axel)
- 18 3mm diameter LEDs (color doesn't matter, I used green ones)
- 4 5mm diameter LEDs (again, color's irrelevant)
- 13 $200 \Omega$ resistors
- Enough wire
- M3 and M4 screws (I'll count them later)
## Instructions
*soon TM*