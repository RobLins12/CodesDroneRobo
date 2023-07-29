//Incluindo as bibliotecas necessárias, essas três estão em um pacote unico de biblioteca

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address); //Aqui é passado o endereço para comunicação os RFID
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening(); //Nessa linha define que o sensor só irá transmitir
}

void loop() {
  const char text[] = "Olá Mundo"; //Texto a ser passado
  radio.write(&text, sizeof(text)); //Código para transmitir mensagem 
  delay(1000);
}