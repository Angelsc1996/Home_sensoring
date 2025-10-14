#include <ESP8266WiFi.h>
#include <espnow.h>
#include "DHT.h"

#define DHTPIN D4     // Pin donde está conectado el DHT11
#define DHTTYPE DHT11 // Definimos el tipo de sensor

DHT dht(DHTPIN, DHTTYPE);

// Estructura para enviar datos
typedef struct struct_message {
    char id[32];
    uint8_t humidity;
    float temperature;
} struct_message;

struct_message myData;

uint8_t receiverAddress[] = { 0x8C, 0x4F, 0x00, 0x2F, 0x88, 0x0C}; // Reemplaza con la MAC address de tu ESP32

void setup() {
    Serial.begin(115200);
    dht.begin();
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != 0) {
        Serial.println("Error inicializando ESP-NOW");
        return;
    }
    esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
    esp_now_add_peer(receiverAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);

    // Inicializa los datos de la estructura
    strcpy(myData.id, "Sensor_1");
        myData.humidity = dht.readHumidity();
    myData.temperature = dht.readTemperature();

    if (isnan(myData.humidity) || isnan(myData.temperature)) {
        Serial.println("Error al leer del sensor DHT11");
        return;
    }

    esp_now_send(receiverAddress, (uint8_t *) &myData, sizeof(myData));
    Serial.println("Datos enviados:");
    Serial.print("Humedad: ");
    Serial.println(myData.humidity);
    Serial.print("Temperatura: ");
    Serial.println(myData.temperature);
    Serial.println(millis());

    ESP.deepSleep(1000000);
}

void loop() {

}