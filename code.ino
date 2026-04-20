// Arduino C++ code
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2); // Address I2C : 0x20 or 0x27 ( i used 0x27)
int brochePot = A0; // analogic enter
int brocheMoteur = 9; // exit of the PWM (noted with ~ on the Arduino)
int valeurCAN = 0; //  0 to 1023
int valeurPWM = 0; //  0 to 255
float tension = 0.0;
int pourcentage = 0;
void setup() {
Serial.begin(9600);
pinMode(brocheMoteur, OUTPUT);
lcd.init();
lcd.backlight();
lcd.print("PWM System OK");
delay(1000);
lcd.clear();
}

void loop() {
valeurCAN = analogRead(brochePot); //Potentiometer voltage reading
valeurPWM = map(valeurCAN, 0, 1023, 0, 255); // Conversion for analogWrite
tension = valeurCAN * 5.0 / 1023.0; // Calculation of the actual voltage
pourcentage = map(valeurCAN, 0, 1023, 0, 100); // Percentage of speed
analogWrite(brocheMoteur, valeurPWM); // GPWM signal generation
// Affichage LCD
lcd.setCursor(0, 0); lcd.print("CAN: "); lcd.print(valeurCAN);
lcd.setCursor(0, 1); lcd.print("Vitesse: "); lcd.print(pourcentage); lcd.print("%");
delay(200);
}
