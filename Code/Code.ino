//Prateek
//https://justdoelectronics.com
//https://www.youtube.com/c/JustDoElectronics/videos

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

float cf = 19.5;
int ffs1 = A0;
int ffsdata = 0;
float vout;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("WWW.PRATEEKS.IN");
  delay(1000);
  pinMode(ffs1, INPUT);
}

void loop() {

  ffsdata = analogRead(ffs1);
  vout = (ffsdata * 5.0) / 1023.0;
  vout = vout * cf;
  Serial.print("Flexi Force sensor: ");
  lcd.setCursor(0, 0);
  lcd.print("Force Range: ");
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print(vout, 3);
  lcd.print("");
  lcd.print(" Gram");
  Serial.print(vout, 3);
  Serial.println("");
  delay(100);
}
