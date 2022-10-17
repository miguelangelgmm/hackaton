#include <DFRobot_DHT11.h>


//Objeto para leer la libreria, viene dado por la libreria DFRobot_DHT11
DFRobot_DHT11 DHT;
#define DHT11_PIN 2 // asignamos el pin 2 para el sensor de Humedad y Temperatura

void setup(){
  Serial.begin(9600);

  pinMode(2,INPUT);//declaramos el pin 2 como entrada
}

void loop(){
  //realizamos la lectura de Humedad y Temperatura
  DHT.read(DHT11_PIN);
  //mostramos los resultamos
  Serial.print("temperatura:");
  Serial.print(DHT.temperature);
  Serial.print("  humedad:");
  Serial.println(DHT.humidity);
  //bloqueamos 1 segundo
  delay(1000);
}
