//Maestro
#include <SoftwareSerial.h>
//sensor de Humedad y Temperatura
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 2 // asignamos el pin 2 para el sensor de Humedad y Temperatura
//pines de comunicación
SoftwareSerial miBt(10, 11); // RX, TX

//Sensor de Humedad de tierra 

int sensorTierra = A0;
int humedadTierra = 0;
int porctHumedadTierra = 0;
//Sensor de luz 
int sensorLuz = A1;
int lecturaLuz = 0; //0-1023
//Sensor de lluvia
int sensorLluvia = A2;
int lecturaLluvia = 0;//0-1023
//Lista de datos separados por A
//Temperatura,Humedad,HumedadTierra,                                                                                                                                                                                                                                                                                                                            
String datos = "A";

void setup(){

  pinMode(2,INPUT);//declaramos el pin 2 como entrada

  //iniciamos las comunicaciones
  Serial.begin(9600);
  miBt.begin(9600);
}

void loop(){
  
  //leemos temperatura y humedad
  datos = datos + DHT.temperature + "A";
  datos = datos + DHT.humidity + "A";

  //calculamos el porcentaje de humedad en la tierra
  humedadTierra = analogRead(sensorTierra);
  porctHumedadTierra = map(humedadTierra, 0, 1024, 100, 0);
  datos = datos + porctHumedadTierra + "A";


  //comprobamos el estado del tiempo 
  lecturaLuz = analogRead(sensorLuz);
  lecturaLluvia = analogRead(sensorLluvia);

  if(lecturaLuz>700){
    datos = datos + "SoleadoA";
    //a menor valor más lluvia
  }else if(lecturaLluvia<400){
        datos = datos + "LluviaIntensaA";
  }else if(lecturaLluvia<700){
        datos = datos + "LluviaModeradaA";
  }else if(lecturaLuz<100){
    datos = datos +"NocheA";
  }else{
    datos = datos + "NubladoA";
  }

  miBt.println(datos);

  datos = "A";

  delay(10000);
 
}