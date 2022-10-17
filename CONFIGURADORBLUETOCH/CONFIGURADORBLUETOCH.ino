#include <SoftwareSerial.h>

SoftwareSerial miBt(10, 11); // RX, TX

void setup(){
  Serial.begin(9600);
  Serial.print("Listo");
  miBt.begin(38400);
}

void loop(){
  if (miBt.available()){
    Serial.write(miBt.read()); // lee BT y envia a arduino

  }

  if(Serial.available()){
    miBt.write(Serial.read()); // lee arduino y envia a BT 
  }
}