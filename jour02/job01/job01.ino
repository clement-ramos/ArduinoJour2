#include <LiquidCrystal.h>

// initialization, we define the ports for RS, E and D4 to D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  // indicates the number of characters (16) and lines (2)
  lcd.begin(16, 2);
  // display the message
  lcd.print("Hello");
  // displays the message at the beginning of the first line
  lcd.setCursor(0, 1);
  lcd.print("World !");
}

void loop() {
  // put your main code here, to run repeatedly:

}
