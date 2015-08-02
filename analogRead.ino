#include "Arduino.h"

int lectura;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  lectura = analogRead(0);
  Serial.print("Lectura: ");
  Serial.println(lectura);
  delay(1000);
}
