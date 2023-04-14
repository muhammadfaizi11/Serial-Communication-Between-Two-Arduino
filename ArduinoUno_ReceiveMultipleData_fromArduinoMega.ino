#include <SoftwareSerial.h>

SoftwareSerial ArduinoUno(2,3); //RX TX

//Below is global variable
char c;
String dataIn;
int8_t indexofA, indexofB, indexofC, indexofD, indexofE,
       indexofF, indexofG, indexofH, indexofI;

String data1, data2, data3, data4, data5, data6, data7, data8, data9;

void parse_the_data(){
  indexofA = dataIn.indexOf("A");
  indexofB = dataIn.indexOf("B");
  indexofC = dataIn.indexOf("C");
  indexofD = dataIn.indexOf("D");
  indexofE = dataIn.indexOf("E");
  indexofF = dataIn.indexOf("F");
  indexofG = dataIn.indexOf("G");
  indexofH = dataIn.indexOf("H");
  indexofI = dataIn.indexOf("I");

  data1 = dataIn.substring(0, indexofA);
  data2 = dataIn.substring(indexofA+1, indexofB);
  data3 = dataIn.substring(indexofB+1, indexofC);
  data4 = dataIn.substring(indexofC+1, indexofD);
  data5 = dataIn.substring(indexofD+1, indexofE);
  data6 = dataIn.substring(indexofE+1, indexofF);
  data7 = dataIn.substring(indexofF+1, indexofG);
  data8 = dataIn.substring(indexofG+1, indexofH);
  data9 = dataIn.substring(indexofH+1, indexofI);
}

void setup() {
  // put your setup code here, to run once:

  //Open serial communication Arduino Uno-PC
  Serial.begin(9600);
  
  //Open serial communication Arduino Uno-Arduino Mega
  ArduinoUno.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(ArduinoUno.available()>0){
    c = ArduinoUno.read();
    
    if(c=='\n'){
      break;
    }
    else {
      dataIn += c;
    }
  }

  if(c=='\n'){
    parse_the_data();

    //Show all data to serial monitor
    Serial.println("Data 1 = " + data1);
    Serial.println("Data 2 = " + data2);
    Serial.println("Data 3 = " + data3);
    Serial.println("Data 4 = " + data4);
    Serial.println("Data 5 = " + data5);
    Serial.println("Data 6 = " + data6);
    Serial.println("Data 7 = " + data7);
    Serial.println("Data 8 = " + data8);
    Serial.println("Data 9 = " + data9);
    Serial.println("====================================");

    //Reset the variable
    c=0;
    dataIn="";
  }
}
