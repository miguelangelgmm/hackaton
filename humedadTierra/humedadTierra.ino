int sensorTierra = A0;

int humedadTierra = 0;
int porctHumedadTierra = 0;
void setup() {
  Serial.begin(9600);
  pinMode(sensorTierra,INPUT);


}

void loop() {
  //el sensor de humedad de la tierra a menor mayor valor más seco esta
  humedadTierra = analogRead(sensorTierra);
  Serial.println(humedadTierra);

  porctHumedadTierra = map(humedadTierra, 0, 1024, 100, 0);
  Serial.println(porctHumedadTierra);
  delay(1000);
}
