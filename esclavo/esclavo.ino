//esclavo
#include <SoftwareSerial.h>
char dato ='a';
String datos="";
boolean newline = false;
SoftwareSerial miBt(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  miBt.begin(9600);  
}

void loop() {
 
     // Leemos los datos mandados por el maestro
    while (miBt.available())
    {  
      delay(100);
        dato = miBt.read();
        if(dato=='\r'){
          continue;
        }else if (dato =='\n'){
          newline = true;
          break;
        }
        else{
        datos = datos+dato;
        }
    }

    if(newline){
      Serial.println(datos);
      newline = false;  
      datos="";

    }
 
}
