#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2          // Define the pin connected to the DHT sensor
#define DHTTYPE DHT11     // Define the type of DHT sensor

DHT dht(DHTPIN, DHTTYPE); // Initialize the DHT sensor

LiquidCrystal_I2C lcd(0x27,16,2); // Initialize the LCD display with I2C address 0x27

void setup() {
  dht.begin(); // Start the DHT sensor
  lcd.init();  // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  lcd.clear(); // Clear the display

  // Set the cursor to the beginning of the first line
  lcd.setCursor(0,0);
  lcd.print("Temp:"); // Print "Temp:" on the first line
  // Set the cursor to the beginning of the second line
  lcd.setCursor(0,1);
  lcd.print("Humid:"); // Print "Humid:" on the second line
}

void loop() {
  delay(1500); // Wait for 1.5 seconds between readings

  // Read humidity and temperature values
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    return;
  }

  // Set the cursor to the position after "Temp:" on the first line
  lcd.setCursor(7, 0);
  lcd.print(t); // Print the temperature value
  // Set the cursor to the position after "Humid:" on the second line
  lcd.setCursor(7, 1);
  lcd.print(h); // Print the humidity value
}
