#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

const int LCD_NB_ROWS = 2;
const int LCD_NB_COLUMNS = 16;

byte START_DIV_0_OF_1[8] = {
  B01111, 
  B11000,
  B10000,
  B10000,
  B10000,
  B10000,
  B11000,
  B01111
}; // Char début 0 / 1

byte START_DIV_1_OF_1[8] = {
  B01111, 
  B11000,
  B10011,
  B10111,
  B10111,
  B10011,
  B11000,
  B01111
}; // Char début 1 / 1

byte DIV_0_OF_2[8] = {
  B11111, 
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
}; // Char milieu 0 / 2

byte DIV_1_OF_2[8] = {
  B11111, 
  B00000,
  B11000,
  B11000,
  B11000,
  B11000,
  B00000,
  B11111
}; // Char milieu 1 / 2

byte DIV_2_OF_2[8] = {
  B11111, 
  B00000,
  B11011,
  B11011,
  B11011,
  B11011,
  B00000,
  B11111
}; // Char milieu 2 / 2

byte END_DIV_0_OF_1[8] = {
  B11110, 
  B00011,
  B00001,
  B00001,
  B00001,
  B00001,
  B00011,
  B11110
}; // Char fin 0 / 1

byte END_DIV_1_OF_1[8] = {
  B11110, 
  B00011,
  B11001,
  B11101,
  B11101,
  B11001,
  B00011,
  B11110
}; // Char fin 1 / 1

void setupProgressbar() {
  lcd.createChar(0, START_DIV_0_OF_1);
  lcd.createChar(1, START_DIV_1_OF_1);
  lcd.createChar(2, DIV_0_OF_2);
  lcd.createChar(3, DIV_1_OF_2);
  lcd.createChar(4, DIV_2_OF_2);
  lcd.createChar(5, END_DIV_0_OF_1);
  lcd.createChar(6, END_DIV_1_OF_1);
}

void drawProgressbar(byte percent) {
  lcd.setCursor(0, 0);
  lcd.print(percent);
  lcd.print(F(" %  ")); 
  lcd.setCursor(0, 1);
  
  byte nb_columns = map(percent, 0, 100, 0, LCD_NB_COLUMNS * 2 - 2);

  for (byte i = 0; i < LCD_NB_COLUMNS; ++i) {
    if (i == 0) { // Premiére case
      if (nb_columns > 0) {
        lcd.write(1); // Char début 1 / 1
        nb_columns -= 1;
      } else {
        lcd.write((byte) 0); // Char début 0 / 1
      }
    } else if (i == LCD_NB_COLUMNS -1) { // Derniére case
      if (nb_columns > 0) {
        lcd.write(6); // Char fin 1 / 1
      } else {
        lcd.write(5); // Char fin 0 / 1
      }
    } else { // Autres cases
      if (nb_columns >= 2) {
        lcd.write(4); // Char div 2 / 2
        nb_columns -= 2;
      } else if (nb_columns == 1) {
        lcd.write(3); // Char div 1 / 2
        nb_columns -= 1;
      } else {
        lcd.write(2); // Char div 0 / 2
      }
    }
  }
}

void setup() {
  lcd.begin(LCD_NB_COLUMNS, LCD_NB_ROWS);
  setupProgressbar();
}

void loop() {
  static byte percent = 0;

  drawProgressbar(percent);

  if (++percent == 101) {
    percent = 0;
    delay(1000);
  }
  delay(500);
}