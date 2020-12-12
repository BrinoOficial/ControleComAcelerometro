# Controle Com Arduino e Acelerometro
Nesse projeto utilizamos um Arduino e um acelerômetro para emitir comandos como um teclado para um computador.

#Requisitos
Para utilizar este código é necessário possuir:
* Arduino Leonardo
* Sensor Acelerometro ADXL345
* Biblioteca Adafruit_ADXL345_U disponível em: https://github.com/adafruit/Adafruit_ADXL345
* Biblioteca Adafruit Sensor Library disponível em: https://github.com/adafruit/Adafruit_Sensor

#Conexões do Acelerômetro:
* ADXL345 SCL -> Arduino SCL
* ADXL345 SDA -> Arduino SDA
* ADXL345 VCC -> Arduino 3V3
* ADXL345 GND -> Arduino GND

# Este código foi testado em:
* Windows 10 Single Language de 64 Bits Versão 2004 
* IDE Arduino 1.8.13 (Windows Store 1.8.42.0)

# Comandos emitidos:
* KEY_LEFT_ARROW (Seta para a esquerda)
* KEY_RIGHT_ARROW (Seta para a direita)
* KEY_UP_ARROW (Seta para cima)
* KEY_DOWN_ARROW (Seta para baixo)