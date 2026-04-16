#include <DHT.h>
#include <DIYables_LCD_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// indirizzo I2C (di solito 0x27)
DIYables_LCD_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.print("hello world");
}

void loop() {
  delay(2000);
  lcd.clear();

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Errore sensore");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  

  Serial.print("Hum: ");
  Serial.print(h);
  Serial.println("%");

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.println(" C");
}
