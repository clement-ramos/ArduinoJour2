#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 4, 5, 6, 7); // Initialisez votre écran LCD avec les broches appropriées

int joystick_x_pin = A0; // La broche analogique utilisée pour lire la direction horizontale du joystick
int joystick_y_pin = A1; // La broche analogique utilisée pour lire la direction verticale du joystick

void setup() {
  lcd.begin(16, 2); // Initialisez votre écran LCD avec les dimensions appropriées (ici 16x2)
}

void loop() {
  int joystick_x_value = analogRead(joystick_x_pin); // Lire la valeur analogique de la broche horizontale du joystick
  int joystick_y_value = analogRead(joystick_y_pin); // Lire la valeur analogique de la broche verticale du joystick
  
  if (joystick_x_value < 400) {
    afficher_direction("Gauche"); // Si la valeur horizontale est inférieure à 400, afficher "Gauche"
  } else if (joystick_x_value > 600) {
    afficher_direction("Droite"); // Si la valeur horizontale est supérieure à 600, afficher "Droite"
  } else if (joystick_y_value < 400) {
    afficher_direction("Haut"); // Si la valeur verticale est inférieure à 400, afficher "Haut"
  } else if (joystick_y_value > 600) {
    afficher_direction("Bas"); // Si la valeur verticale est supérieure à 600, afficher "Bas"
  } else {
    afficher_direction(""); // Si aucune direction n'est détectée, effacer l'écran LCD
  }
  
  delay(100); // Attendre un court instant avant de lire à nouveau la direction du joystick
}

void afficher_direction(String direction) {
  lcd.clear(); // Effacer l'écran LCD
  lcd.setCursor(0, 0); // Déplacer le curseur en haut à gauche de
  lcd.print(direction);
}