#include "SPI.h"

volatile byte comando = 0;
int a,b,c;
float v1 = 4.98;
float r1 = 1000000;
float r2 = 100000;

void setup(void) {
  Serial.begin (115200);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);
}

ISR(SPI_STC_vect) {
  byte comando = SPDR;
  switch(comando){
  case 'i':
    SPDR = a;
    break;
  case 'x':
    SPDR = b;
    break;
  case 'y':
    SPDR = c;
    break;
  } 
}

int inteiro(float valor) {
  int numero = (int)valor;
  return numero;
}

int primeiraDecimal(float valor) {
  float numero = valor - (int)valor;
  numero = round(numero*100)/10;
  return (int)numero;
}

float segundaDecimal(float valor) {
  valor = valor*10;
  float numero = valor - (int)valor;
  numero = round(numero*100)/10;
  return (int)numero;
}

void loop(void) {
  float v = (analogRead(0)*v1)/1024.0;
  float v2 = v/(r2/(r1+r2));
  a = inteiro(v2);
  b = primeiraDecimal(v2);
  c = segundaDecimal(v2);
  Serial.println(c);
  delay(100);
}
