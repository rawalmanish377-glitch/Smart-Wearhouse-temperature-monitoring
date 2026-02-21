#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2        // DHT11 data pin
#define DHTTYPE DHT11   // Sensor type

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);   // I2C address 0x27 (kabhi 0x3F bhi hota hai)

void setup() {
  lcd.init();
  lcd.backlight();
  
  dht.begin();
  
  lcd.setCursor(0,0);
  lcd.print("Temp & Humidity");
  delay(2000);
  lcd.clear();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0,0);
    lcd.print("Sensor Error");
    return;
  }

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C ");

  lcd.setCursor(0,1);
  lcd.print("Hum : ");
  lcd.print(humidity);
  lcd.print(" % ");

  delay(2000);
}