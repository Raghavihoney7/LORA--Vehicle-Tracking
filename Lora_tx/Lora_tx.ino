#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

// Define the pins for SoftwareSerial communication
SoftwareSerial loraSerial(8, 9); // RX, TX

TinyGPSPlus gps;

float Lt;
float Lg;

void setup()
{
  Serial.begin(9600);
  loraSerial.begin(9600);

  // Configure LoRa module (optional)
  // Set the address of this module (TX)
  loraSerial.println("AT+ADDRESS=1");
  delay(1000);
  
  // Set the address of the receiver module (RX)
  loraSerial.println("AT+DESTINATION=2");
  delay(1000);
  
  // Set the LoRa network ID
  loraSerial.println("AT+NETWORKID=6");
  delay(1000);
}

void loop()
{
  while (Serial.available() > 0)
    if (gps.encode(Serial.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    loraSerial.println("AT+SEND=2,15,No GPS detected"); delay(1000);
    while (true);
  }
  
}

void displayInfo()
{
  Serial.print(F("Location: "));
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);

    String gps_data = String(gps.location.lat(), 6)+"/"+String(gps.location.lng(), 6);
    String command = "AT+SEND=2,"+String(gps_data.length())+","+gps_data;
    loraSerial.println(command); // Send to address 2, length of "Hello" is 5
    delay(2000);
  }
  else
  {
    Serial.print(F("INVALID"));
    loraSerial.println("AT+SEND=2,7,Invalid");delay(500);
  }
  Serial.println();
}