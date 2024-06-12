#include "DHT.h"
#define dht_type DHT11
int dht_pin = A1;
DHT dht_1 = DHT(dht_pin, dht_type);

void setup()
{
    Serial.begin(9600);
    dht_1.begin();
}

void loop()
{
    float temperatura = dht_1.readTemperature();
    float umidade = dht_1.readHumidity();

    if (isnan(temperatura) or isnan(umidade))
    {
      Serial.println("Erro ao ler o DHT");
    }
    else 
    {
      Serial.print(temperatura);
      Serial.print(';');
      Serial.println(umidade);
    }
  delay(2000);
}