#include <SoftwareSerial.h>

SoftwareSerial ArduinoMega(2,3); //RX TX

int data1, data2, data3;
float data4, data5, data6;
String data7, data8, data9;

void setup() {
  // put your setup code here, to run once:
  //Open serial communication in Arduino Mega 2560-PC
  Serial.begin(9600);

  //Open serial communication in Arduino Mega 2560-Arduino Uno
  ArduinoMega.begin(9600);
  data1 = 0; data2 = 10; data3 = 100;
}

void loop() {
  // put your main code here, to run repeatedly:
  data1 = data1++;
  data2 = data2++;
  data3 = data3++;
  data4 = 12.12345;
  data5 = 123.1234;
  data6 = 1234.123;
  data7 = "Muhammad Nur Faizi";
  data8 = "Operation Teknik";
  data9 = "PT Steel Pipe Industry of Indonesia, Tbk";

  ArduinoMega.print(data1); ArduinoMega.print("A"); 
  ArduinoMega.print(data2); ArduinoMega.print("B"); 
  ArduinoMega.print(data3); ArduinoMega.print("C"); 
  ArduinoMega.print(data4, 5); ArduinoMega.print("D"); 
  ArduinoMega.print(data5, 4); ArduinoMega.print("E"); 
  ArduinoMega.print(data6, 3); ArduinoMega.print("F"); 
  ArduinoMega.print(data7); ArduinoMega.print("G"); 
  ArduinoMega.print(data8); ArduinoMega.print("H"); 
  ArduinoMega.print(data9); ArduinoMega.print("I"); 
  ArduinoMega.print("\n");

  delay(2000);
}
