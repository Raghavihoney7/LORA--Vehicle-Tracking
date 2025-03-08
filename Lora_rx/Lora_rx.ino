#include <SoftwareSerial.h>

// Define the pins for SoftwareSerial communication
SoftwareSerial loraSerial(8, 9); // RX, TX

void setup() {
  // Start the Serial Monitor
  Serial.begin(9600);
  // Start LoRa communication at 9600 baud rate
  loraSerial.begin(9600);

  // Configure LoRa module (optional)
  // Set the address of this module (RX)
  loraSerial.println("AT+ADDRESS=2");
  delay(1000);

  // Set the LoRa network ID
  loraSerial.println("AT+NETWORKID=6");
  delay(1000);
}

void loop()
{
  if (loraSerial.available())
  {
    String receivedData = loraSerial.readString();
    Serial.print("Received data: ");
    Serial.println(receivedData);
    parseLatLong(receivedData);
  }
  else
  {
    Serial.println("Waiting for data.....");delay(500);
  }
}

// Function to parse latitude and longitude
void parseLatLong(String data)
{
  // Find the start of the latitude and longitude string
  int startIndex = data.indexOf("RCV=") + 8; // Adjust to the start of lat/long part
  int separatorIndex = data.indexOf('/', startIndex);

  if (startIndex > 0 && separatorIndex > startIndex) {
    // Extract the latitude and longitude as strings
    String latitude = data.substring(startIndex + 1, separatorIndex);
    String longitude = data.substring(separatorIndex + 1, data.indexOf(',', separatorIndex));

    // Print the parsed latitude and longitude
    Serial.print("Latitude: ");
    Serial.println(latitude);
    Serial.print("Longitude: ");
    Serial.println(longitude);
  }
}
