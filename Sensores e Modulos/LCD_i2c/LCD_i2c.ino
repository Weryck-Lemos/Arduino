#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Endereço do display I2C (geralmente 0x27 ou 0x3F)
// Ajuste o endereço se necessário
LiquidCrystal_I2C lcd(0x27, 16, 2); // Display 16x2

void setup() {
  // Inicializa o display
  lcd.init();
  lcd.backlight(); // Liga a luz de fundo
  lcd.setCursor(0, 0); // Define o cursor na posição inicial (linha 0, coluna 0)
  lcd.print("Hello World!"); // Imprime "Hello World!" no display
}

void loop() {
  lcd.clear();
  lcd.print("Oi Weryck :)");
  delay(2000);
  lcd.clear();
  lcd.print("I love samba");
  delay(2000);
}
