#include <LiquidCrystal.h>

// initialization, we define the ports for RS, E and D4 to D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

const int pinButton = 2;
unsigned long startTime = 0;
unsigned long currentTime = 0;
int buttonState = 0;
bool buttonPush = false;

byte voidCase[8] = 
{
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup() {
  pinMode(pinButton, INPUT);
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Chronometer !");
}

void loop() {
  buttonState = digitalRead(pinButton);
  
  if(buttonState == HIGH) {
    if(!buttonPush) {
      buttonPush = true;
      startTime = millis();
    }
    currentTime = millis() - startTime;
    lcd.setCursor(0, 1);
    lcd.print(currentTime / 1000);
  
  } else {
    buttonPush = false;
    startTime = 0;
    currentTime = 0;
    for(int i = 0; i < 16; i++) {
      lcd.createChar(0, voidCase);
      lcd.setCursor(i,1);   
      lcd.write(byte(0));
    }
  }

}

