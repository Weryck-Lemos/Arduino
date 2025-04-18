#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTYPE DHT11
#define rs 12
#define e 11
#define d4 5
#define d5 4
#define d6 3
#define d7 2
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

#define DHTPIN A1      
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

bool hello = false;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello World");

  dht.begin();
  delay(2000); 
}

void loop() {
delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

 
    lcd.clear();
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Umid: ");
    lcd.print(h);
    lcd.print("%");
}
