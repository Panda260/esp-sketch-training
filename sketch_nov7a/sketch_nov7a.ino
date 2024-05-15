#include <SPI.h>
#include <LoRa.h>

// Definition der Pins für das SX1276 LoRa-Modul
#define LORA_SCK 5
#define LORA_MISO 19
#define LORA_MOSI 27
#define LORA_SS 18
#define LORA_RST 14
#define LORA_DI0 26

void setup() {
  // Initialisiere die serielle Verbindung für Debugging
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  // Initialisiere SPI
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_SS);
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DI0);

  // Versuch, LoRa zu starten
  if (!LoRa.begin(868E6)) { // Europäische Frequenz 868 MHz
    Serial.println("Starting LoRa failed!");
    while (1); // Bleibe in einer Endlosschleife, wenn LoRa nicht gestartet werden kann
  }

  Serial.println("LoRa Initialisiert");
}

void loop() {
  Serial.print("Sending packet: ");

  // Erzeuge eine Nachricht
  String message = "Hello LoRa";

  // Starte das Paket
  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  Serial.println(message);

  // Warte eine Sekunde
  delay(1000);
}
