//Sender code
//Arduino DUE
#include <Wire.h>
#include <stdlib.h>

#define potPin A0  //analogRead port
int readVal;

///////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Communication I2C
  Wire.begin(2);
  Wire.onRequest(requestEvent); // register event
  Serial.begin(115200);
}

void loop() {
  readVal = analogRead(potPin);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void requestEvent() {
  // respond with message of 2 bytes
  Serial.println(readVal);
  Wire.write(highByte(readVal));
  Wire.write(lowByte(readVal));
  // Wire.send("hello"); //test with char
}

