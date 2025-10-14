#include <Arduino.h>

// put function declarations here:
// int myFunction(int, int);

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(115200);
  Serial.println("Error inicializando ESP-NOW");
}

void loop() {
  Serial.println("Funcionando");
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}

