#include "LiquidCrystal.h"
LiquidCrystal lcd(13,12,11,10,9,8);
int GAS_VAL = 0;
long readUltrasonicDistance(int triggerPin, int echoPin) {
pinMode(triggerPin, OUTPUT);
digitalWrite(triggerPin, LOW); 
delayMicroseconds(2);
digitalWrite(triggerPin, HIGH);
delayMicroseconds(10); 
digitalWrite(triggerPin, LOW); 
pinMode(echoPin, INPUT);
return pulseIn(echoPin, HIGH);
}
void setup()
{
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(A0, INPUT);
Serial.begin(9600);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("   AIR QUALITY  ");
}
void loop()
{
GAS_VAL = analogRead(A0);
Serial.println(GAS_VAL);
lcd.setCursor(7,8);
lcd.print(GAS_VAL);
if(GAS_VAL>310)
 {
  if (0.01723 * readUltrasonicDistance(2, 3) < 10) {
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
} 
else {
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
}
 delay(10);
 }
  else
  {
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
 }
}

