#include <SoftwareSerial.h>

// TX-O pin of bluetooth mate, Arduino A0
#define bluetoothTxPin A0  
// RX-I pin of bluetooth mate, Arduino A1
#define bluetoothRxPin A1  

SoftwareSerial bluetooth(bluetoothTxPin, bluetoothRxPin);

void setup() {
  Serial.begin(9600); //init serial port and set baudrate
  while(!Serial); //wait for serial port to connect (needed for Leonardo only)
  Serial.println("\nStart...");
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  delay(2000);
  Serial.println("Waking up ble module...");
  sendBluetoothInitCommand("WAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUPWAKEUP");

  Serial.println("Sending AT+NAMEBLEGate...");
  sendBluetoothInitCommand("AT+NAMEBLEGate");
  
  Serial.println("Bluetooth setup done.");
}

void loop() {
  
}

void sendBluetoothInitCommand(String command) {
  bluetooth.print(command);
  delay(3000);
  if(bluetooth.available()) {
    Serial.print("Bluetooth response: ");
    while(bluetooth.available()) {
      char char2 = (char) bluetooth.read();
      Serial.print(char2);
    }
    Serial.print("\n");
  }
}

