#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include "Keyboard.h"

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(); // Conecta o sensor ADCL345 (Acelerometro)

float x = 0;  // Inicializa a variavel para o eixo X
float y = 0;  // Inicializa a variavel para o eixo Y
float z = 0;  // Inicializa a variavel para o eixo Z
int tempo = 50; // Tempo entre execuções
int sensibilidade = 3;  // Sensibilidade de inclinacao para emissao do comando

void setup(void){ 
  Keyboard.begin();   // Inicia a conexao do Arduino Leonardo como teclado
  Serial.begin(9600); // Inicia a comunicacao serial
  if (!accel.begin()) // Caso o sensor nao tenha um sensor conectado emite um erro
  {
    Serial.println("No ADXL345 sensor detected.");
    while (1);
  }
}
void loop(void)
{
  x = leituraX(); // Realiza a leitura do eixo X
  y = leituraY(); // Realiza a leitura do eixo Y
  z = leituraZ(); // Realiza a leitura do eixo Z

  // Verifica eixo X para a esquerda
  if(x >= sensibilidade){ // Compara o movimento a sensibilidade definida
    Keyboard.press(KEY_LEFT_ARROW); // Envia o comando de teclado
    Serial.println("<-");           // Envia para o monitor serial
  }  

  // Verifica eixo X para a direita
  if(x <= -sensibilidade){ // Compara o movimento a sensibilidade definida
    Keyboard.press(KEY_RIGHT_ARROW); // Envia o comando de teclado
    Serial.println("->");            // Envia para o monitor serial
  }

  // Verifica eixo Y para a cima
  if(y <= -sensibilidade){ // Compara o movimento a sensibilidade definida
    while(y <= -(sensibilidade-4)){ // Enquanto se manter inclinado continua enviando o sinal
      Keyboard.press(KEY_UP_ARROW); // Envia o comando de teclado
      Serial.println("^");          // Envia para o monitor serial
      y = leituraY();
    }
  }

 // Verifica eixo Y para a baixo
  if(y >= sensibilidade){ // Compara o movimento a sensibilidade definida
    Keyboard.press(KEY_DOWN_ARROW); // Envia o comando de teclado
    Serial.println("v");            // Envia para o monitor serial
  }         
                                       
  delay(tempo);           // Tempo antes da proxima execucao
  Keyboard.releaseAll();  // Libera as teclas pressionadas
}

// Funcao de leitura do eixo X
float leituraX() {
  sensors_event_t event;
  accel.getEvent(&event);
  return (event.acceleration.x);
}

// Funcao de leitura do eixo Y
float leituraY() {
  sensors_event_t event;
  accel.getEvent(&event);
  return (event.acceleration.y);
}

// Funcao de leitura do eixo Z
float leituraZ() {
  sensors_event_t event;
  accel.getEvent(&event);
  return (event.acceleration.z);
}
