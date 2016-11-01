//Reader code
//Arduino UNO
// Déclaration des variables et librairies I2C
#include <Wire.h>


///////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output
}

void loop() {
  Wire.requestFrom(2, 2);    // request 2 bytes from slave device #2
  Serial.println("potentiometer value");
  byte loByte;
  byte hiByte;
  while (Wire.available()) {  // slave may send less than requested
    // char c = Wire.receive(); // test with char
    // Serial.print(c);
    hiByte = Wire.read();
    loByte = Wire.read();
  }
  Serial.println(hiByte, BIN);
  Serial.println(loByte, BIN);
  int val = (hiByte << 8) + loByte;
  Serial.print(val);
  Serial.println("");
  delay(500);
}
