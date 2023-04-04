#include <LiquidCrystal.h>

// initialization, we define the ports for RS, E and D4 to D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

byte smiley[8] = 
{
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};

void setup() {
  // put your setup code here, to run once:
  lcd.createChar(0, smiley);  
  lcd.begin(16,2);
  lcd.setCursor(0,0); 
  lcd.print("*** LCD I2C ****");  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(i, 1);   
    lcd.write(byte(0));
  }
}

