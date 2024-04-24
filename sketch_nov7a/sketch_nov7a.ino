#include <SPI.h>
#include <LoRa.h>
#include <Wire.h> // Include for I2C communication (might be needed for specific boards)

// Replace these with your TTN details
const char *appId = "0000000000000000";
const char *devId = "*****";
const char *devEUI = "***"; // 8-byte hexadecimal string
const char *appKey = "***"; // 32-byte hexadecimal string

#define ss 5
#define rst 14
#define dio0 2

int counter = 0; // Declare counter globally

void setup()
{
    // Initialize Serial Monitor
    Serial.begin(115200);
    while (!Serial)
        ;
    Serial.println("LoRa Sender to TTN");

    // Setup LoRa transceiver module
    LoRa.setPins(ss, rst, dio0);

    // Replace the LoRa.begin(---E-) argument with your region's frequency
    // 433E6 for Asia
    // 866E6 for Europe
    // 915E6 for North America
    while (!LoRa.begin(866E6))
    {
        Serial.println(".");
        delay(500);
    }

    // Change sync word (0xF3) to match the receiver (optional)
    // The sync word assures you don't get LoRa messages from other LoRa transceivers
    // ranges from 0-0xFF
    LoRa.setSyncWord(0xF3);

    Serial.println("LoRa Initializing OK!");
}

void loop()
{
    Serial.print("Sending data to TTN: ");
    Serial.println(counter);

    // Join TTN network (check library documentation for exact function names)
    if (!LoRa.beginPacket())
    {
        Serial.println("Failed to begin packet!");
        return;
    }

    // Depending on the library, the function might be `setMode` or similar
    LoRa.setMode(/* argument for LoRa mode */); // Check library documentation

    // Join TTN network (function names might differ)
    LoRa.join(/* Function for joining TTN */, devEUI, appEUI, appId, devId);

    // Wait for joining
    int joinRetries = 0;
    while (/* Function to check joining status */)
    {
        if (joinRetries++ > 20)
        {
            Serial.println("Failed to join TTN after 20 retries!");
            break;
        }
        Serial.println("Joining TTN...");
        delay(5000);
    }

    // Check joining status (function names might differ)
    if (/* Function to check joining status */)
    {
        Serial.println("Joined TTN!");

        // Prepare data packet
        LoRa.beginPacket();
        LoRa.print("Hello from ESP32: ");
        LoRa.print(counter);
        LoRa.endPacket();

        counter++;
        delay(10000); // Adjust sending interval as needed
    }
}
break;
}
Serial.println("Joining TTN...");
delay(5000);
}

// Check joining status (function names might differ)
if (/* Function to check joining status */)
{
    Serial.println("Joined TTN!");

    // Prepare data packet
    LoRa.beginPacket();
    LoRa.print("Hello from ESP32: ");
    LoRa.print(counter);
    LoRa.endPacket();

    counter++;
    delay(10000); // Adjust sending interval as needed
}
}