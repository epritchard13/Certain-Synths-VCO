#include <SPI.h>

#define CONTROL_WORD 0x11
int dataByte = 0;  // Variable to hold the data byte
int decoder;

const int decoder_0 = 4;
const int decoder_1 = 5;
const int decoder_2 = 6;
const int decoder_3 = 7;

int divider = 0;;

void setup() {
  // Initialize SPI
  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  
  // Set SS pin as output and deselect the slave device
  pinMode(SS, OUTPUT);
  digitalWrite(SS, HIGH);


  decoder = 0;
  divider = 0;
}


void loop() {


// Happy Birthday melody notes (in Hz)
const int melody[] = {
  0, 51, 57, 51, 86, 80, 51, 51, 57, 51, 97, 86,
  51, 51, 154, 122, 110, 97, 136, 110, 102, 86, 147, 147,
  51, 51, 57, 51, 86, 80, 51, 51, 57, 51, 113, 97,
  161, 161, 154, 122, 110, 97, 136, 110, 102, 86, 147, 147,
  172, 172, 161, 161, 144, 122, 195, 195, 172, 172, 161, 161,
  144, 122, 205, 205, 194, 194, 172, 172, 154, 154, 172, 172,
  161, 161, 144, 122, 195, 195, 172, 172, 161, 161, 144, 122,
  161, 161, 144, 144, 129, 129, 136, 136, 122, 122, 110, 110,
  97, 97, 86, 86, 161, 161, 144, 144, 129, 129, 136, 136
};
  

  
  
  // Increment the data byte for the next iteration
  divider++;
  if(divider == 100){
    divider = 0;
    dataByte++;
  }
  

  
  digitalWrite(decoder_0, bitRead(decoder, 0));
  digitalWrite(decoder_1, bitRead(decoder, 1));
  digitalWrite(decoder_2, bitRead(decoder, 2));
  digitalWrite(decoder_3, bitRead(decoder, 3));



  

  
  if(decoder == 5){
      digitalWrite(SS, LOW);
  
  // Transmit the control word
      SPI.transfer(CONTROL_WORD);
  
  // Transmit the data byte (ramp wave)
      SPI.transfer(melody[dataByte]);
  
  // Deselect the slave device
      digitalWrite(SS, HIGH);
  }
  if(decoder == 7){
      digitalWrite(SS, LOW);
  
  // Transmit the control word
      SPI.transfer(CONTROL_WORD);
  
  // Transmit the data byte (ramp wave)
      SPI.transfer(melody[dataByte]);
  
  // Deselect the slave device
      digitalWrite(SS, HIGH);
  }
  decoder = decoder + 1;
  if(decoder == 16){
      decoder = 0;
  }
  if(dataByte == 72){
    dataByte == 0;
  }
  
  
  // Delay between transmissions
  //delay(10);  // Adjust the delay as needed
}
