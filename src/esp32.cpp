#include <Arduino.h>

// put function declarations here:
// int myFunction(int, int);

void _setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(115200);
  Serial.println("Error inicializando ESP-NOW");
}

void _loop() {
  Serial.println("Funcionando");
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}

// put function definitions here:
/*  int myFunction(int x, int y) {
  return x + y;
 }*/ 