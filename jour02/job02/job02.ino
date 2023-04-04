#include <LiquidCrystal.h>

// initialization, we define the ports for RS, E and D4 to D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

const int pinAnalogA0 = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinAnalogA0, INPUT);
  // indicates the number of characters (16) and lines (2)
  lcd.begin(16, 2);
  // display the message
  lcd.print("Voltage values:");
}

void loop() {
  // put your main code here, to run repeatedly:
  float valPotar00 = analogRead(pinAnalogA0);
  // divide by 205 to convert 5V encoded to 10 bits (1024 values: 1024 / 205)
  float valPotar01 = valPotar00 / 205;

  // display the voltage values
  lcd.setCursor(0, 1);
  lcd.print(valPotar01);
  lcd.setCursor(5, 1);
  lcd.print("V");
  delay(500);
}
