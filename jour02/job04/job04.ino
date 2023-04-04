#include <LiquidCrystal.h>

// initialization, we define the ports for RS, E and D4 to D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

int counter = 0;
int buttonState = 0;
const int pinButton = 2;  // the number of the pushbutton pin

void setup() {
  pinMode(pinButton, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(pinButton);

  if(buttonState != HIGH) {
    counter++;
    lcd.setCursor(0, 0);
    lcd.print("Ramaud");
    lcd.setCursor(0, 1);
    lcd.print(counter);
    delay(1000);
  } else {
    counter = 0;
    lcd.clear();
  }
}

