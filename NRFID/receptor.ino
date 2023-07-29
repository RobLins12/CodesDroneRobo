//Incluindo as bibliotecas necessárias, essas três estão em um pacote unico de biblioteca

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address); //Aqui passa novamento o endereço para comunicação os RFID
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening(); //Define-se como apenas receptor
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text)); //Código para receber a mensagem
    Serial.println(text);
  }
}