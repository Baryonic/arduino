//ariel
//||||||||||||LIBRERIAS

//sensor humedad

#include <SimpleDHT.h>


// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 8
int pinDHT11= 8;
SimpleDHT11 dht11;


//control remoto
#include "IRremote.h"
int receiver = 4;
/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'


//led controler
int lightPin = 0;
int clockPin = 10;
int latchPin = 11;
int dataPin = 12;

int leds = 0;






boolean emergencia;
boolean sensorB;



  byte temperature;
  byte humidity;
  byte data[40];







void setup() {

  
   Serial.begin(9600);
   emergencia=true;
   sensorB=false;
  pinMode(lr1,OUTPUT);

  
temperature = 0;
humidity = 0;
data[40] = {0};

//control IR
irrecv.enableIRIn();

//led controler
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);


}











void loop() {
  

  Emergencia();

  ControlIR();

  if(sensorB==true){SensorHT();}
  else{return;}

  
  
}

void Emergencia(){
if(emergencia==true){
  digitalWrite(lr1,LOW);
  delay(50);
  digitalWrite(lr1,HIGH);
  delay(50);
}else{digitalWrite(lr1,HIGH);}
  
}

void SensorHT(){
    // read with raw sample data.

  Serial.print((int)temperature);Serial.print("*C");
Serial.print(((int)humidity));Serial.println("%H2O");

 if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    return;
  }
  }


void ControlIR(){

  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  

  
}
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{

  switch(results.value)

  {
  case 0xFFA25D: if(emergencia==true){emergencia=false;}else{emergencia=true;} 
  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  case 0xFF629D: Serial.println("VOL+");break;

  case 0xFF22DD: Serial.println("FAST BACK");    break;
  case 0xFF02FD: Serial.println("PAUSE");    break;
  case 0xFFC23D: Serial.println("FAST FORWARD");   break;
  case 0xFFE01F: Serial.println("DOWN");    break;
  case 0xFFA857: Serial.println("VOL-");;break;

  case 0xFF906F: Serial.println("UP");    break;
  case 0xFF9867: Serial.println("EQ");    break;
  case 0xFFB04F: if(sensorB==true){sensorB=false;}else{sensorB=true;} 
  case 0xFF6897: Serial.println("0");    break;
  case 0xFF30CF: Serial.println("1");    break;
  case 0xFF18E7: Serial.println("2");    break;
  case 0xFF7A85: Serial.println("3");    break;
  case 0xFF10EF: Serial.println("4");    break;
  case 0xFF38C7: Serial.println("5");    break;
  case 0xFF5AA5: Serial.println("6");    break;
  case 0xFF42BD: Serial.println("7");    break;
  case 0xFF4AB5: Serial.println("8");    break;
  case 0xFF52AD: Serial.println("9");    break;
  case 0xFFFFFFFF: Serial.println("repeat");    break;

  default: 
    Serial.println(" other button   ");

  }// End Case

  delay(50); // Do not get immediate repeat


}
