//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Victor Tchistiak - 2019
//
//This example demostrates master mode bluetooth connection and pin
//it creates a bridge between Serial and Classical Bluetooth (SPP)
//this is an extention of the SerialToSerialBT example by Evandro Copercini - 2018
//

#include "BluetoothSerial.h"
#include "display.h"
BluetoothSerial SerialBT;
DisplayInfo Disp;


String MACadd = "00:1C:05:01:A4:E4";
uint8_t address[6] = { 0x00, 0x1C, 0x05, 0x01, 0xA4, 0xE4 };
String name = "Nonin_Medical_Inc._527898";
char *pin = "527898";  //<- standard pin would be provided by default
bool connected;

void setup() {
  Serial.begin(115200);
  Disp.initLCD(true);
  SerialBT.begin("ESP32test", true);
  SerialBT.setPin(pin);
  Serial.println("The device started in master mode, make sure remote BT device is on!");

  connected = SerialBT.connect(name);

  if (connected) {
    Serial.println("Connected Succesfully!");
  } else {
    while (!SerialBT.connected(10000)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app.");
      SerialBT.connect(name);
    }
  }
}

void loop() {
  if (!SerialBT.connected()) {
    Disp.printLCD("0", "disconnected");
    if (SerialBT.connect(name)) {
      connected = true;
      Disp.printLCD("0", "reconnected");
    } else {
      Disp.printLCD("0", "disconected");
    }
  }
  if (SerialBT.available() && connected) {
    String pulseRate = String(SerialBT.read());
    // String spo2 = String(data[1]);
    // Realizar el procesamiento o visualización de los datos
    Disp.printLCD(pulseRate, "online");
  }
  delay(2000);
}
