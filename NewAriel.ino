

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 22;
SimpleDHT11 dht11;


//remote ir
#include "IRremote.h"
int receiver = 3; // Signal Pin of IR receiver to Arduino Digital Pin 11
/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

boolean welcomeB;
boolean emergenciaB;
boolean dhtB;
boolean lucesFueraB;
boolean lucesDentroB;
boolean aspersoresB;
boolean aforoCompletoB;
boolean puertaB;



void setup() {
    Serial.begin(9600);
    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

irrecv.enableIRIn(); Serial.print("iniciada funsion de mierda");// Start the receiver
  
welcomeB=false;
emergenciaB=false;
dhtB=true;
lucesFueraB=false;
lucesDentroB=false;
aspersoresB=false;
aforoCompletoB=false;
puertaB=false;

}








//||||||||||||||||||||||||||||||WELCOME
void Welcome(){
     lcd.setCursor(0, 0);
  lcd.print("welcome");
  lcd.setCursor(0, 1);
  lcd.print("arile");
  delay(1000);
}


//||||||||||||||||||||||||||||||DHT
void DHT(){
    // start working...
  // read with raw sample data.
  byte temperature = 1;
  byte humidity = 0;
  byte data[40] = {0};
 if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
     lcd.setCursor(0, 0);
  lcd.print(((int)temperature));lcd.print("*C ");
  lcd.setCursor(0, 1);
  lcd.print(((int)humidity));lcd.print("%H2O ");
 Serial.println("funsiona");
    return;
  }
  
  // DHT11 sampling rate is 1HZ.


}
//||||||||||||||||||||||||||||||IR RECEIVER
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{

  switch(results.value)

  {
  case 0xFFA25D: lcd.setCursor(0, 0);lcd.print("POWER"); break;//power
  case 0xFFE21D: lcd.setCursor(0, 0);lcd.print("FUNC/STOP"); break;//func stop
  case 0xFF629D: lcd.setCursor(0, 0);lcd.print("VOL+"); break;//vol+
  case 0xFF22DD: lcd.setCursor(0, 0);lcd.print("FAST BACK");    break;//fast back
  case 0xFF02FD: lcd.setCursor(0, 0);lcd.print("PAUSE");    break;//pause
  case 0xFFC23D: lcd.setCursor(0, 0);lcd.print("FAST FORWARD");   break;//fast forward
  case 0xFFE01F: lcd.setCursor(0, 0);lcd.print("DOWN");    break;//down
  case 0xFFA857: lcd.setCursor(0, 0);lcd.print("VOL-");    break;// vol-
  case 0xFF906F: lcd.setCursor(0, 0);lcd.print("UP");    break;//up
  case 0xFF9867: lcd.setCursor(0, 0);lcd.print("EQ");    break;// eq
  case 0xFFB04F: if(dhtB==false){lcd.setCursor(0, 0);lcd.print("dht enabled");dhtB=true;break;}else{lcd.setCursor(0, 0);lcd.print("dht disabled");delay(500);dhtB=false;break;}    //st rept
  case 0xFF6897: lcd.setCursor(0, 0);lcd.print("0");    break;//0
  case 0xFF30CF: lcd.setCursor(0, 0);lcd.print("1");    break;//1
  case 0xFF18E7: lcd.setCursor(0, 0);lcd.print("2");    break;//2
  case 0xFF7A85: lcd.setCursor(0, 0);lcd.print("3");    break;//3
  case 0xFF10EF: lcd.setCursor(0, 0);lcd.print("4");    break;//4
  case 0xFF38C7: lcd.setCursor(0, 0);lcd.print("5");    break;//5
  case 0xFF5AA5: lcd.setCursor(0, 0);lcd.print("6");    break;//6
  case 0xFF42BD: lcd.setCursor(0, 0);lcd.print("7");    break;//7
  case 0xFF4AB5: lcd.setCursor(0, 0);lcd.print("8");    break;//8
  case 0xFF52AD: lcd.setCursor(0, 0);lcd.print("9");    break;//9
  case 0xFFFFFFFF: lcd.setCursor(0, 0);lcd.print(" REPEAT");break;//repeat  

  default: 
    Serial.println(" other button   ");

  }// End Case

delay(500); // Do not get immediate repeat


} //END translateIR
void ReceiveIR(){
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  delay(100);
  }
//||||||||||||||||||||||||||||||EMERGENCIA
//||||||||||||||||||||||||||||||LUZ INTELIGENTE



void RunPC(){
   
  if(welcomeB==true){
    Welcome();
    }
  else if(dhtB==true){
  DHT();

    }
    
 //ReceiveIR();
}
void loop() {
RunPC();

}
