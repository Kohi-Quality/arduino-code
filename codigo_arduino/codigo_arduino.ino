#include "DHT.h"        // inclui a biblioteca
#define dht_type DHT11  // define o modelo (tipo) do sensor

int dht_pin = A1;                    // nomeia o pino A5 conectado ao sensor
DHT dht_1 = DHT(dht_pin, dht_type);  // cria o sensor dht_1 e envia para a biblioteca suas informações de modelo e pino

void setup() {         // só acontece uma vez no código
  Serial.begin(9600);  // inicia o Serial.Monitor com uma taxa de 9600 baud rates
  dht_1.begin();       // inicia o sensor dht_11
}

void loop() {

  float umidade = dht_1.readHumidity();

  float temperatura = dht_1.readTemperature(); 

  ///////////////////////////////////////////////////////////////

  if (isnan(temperatura) or isnan(umidade)) {  // Se não houver leitura, ele exibi uma mensagem de erro   "is nan" = "é nulo"
    Serial.println("Erro ao ler");             // escreve a frase de erro no monitor e pula linha com "ln"
  }

  else {
    
    Serial.print(temperatura);
    Serial.print("; ");
    Serial.println(umidade);
    
  }
  delay(1000);  // faz uma leitura a cada 1 segundo
}