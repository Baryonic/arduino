


int b2=2;
int b3=3;
int b4=4;
int b5=5;
int b6=6;
int b7=7;
int b8=8;
int b9=9;
int b10=10;
int b11=11;
int b12=12;
int b13=13;
int t=70;


/*#define b1 52
#define b2 49
#define b3 47
#define b4 45
#define b5 43*/
void setup() {


  pinMode(b2,OUTPUT);
  pinMode(b3,OUTPUT);
    pinMode(b4,OUTPUT);
  pinMode(b5,OUTPUT);
    pinMode(b6,OUTPUT);
  pinMode(b7,OUTPUT);
  pinMode(b8,OUTPUT);
    pinMode(b9,OUTPUT);
  pinMode(b10,OUTPUT);
    pinMode(b11,OUTPUT);
  pinMode(b12,OUTPUT);
  pinMode(b13,OUTPUT);
 /* pinMode(INPUT_PULLUP,b1);
 pinMode(INPUT_PULLUP,b2);
  pinMode(INPUT_PULLUP,b3);
   pinMode(INPUT_PULLUP,b4);
    pinMode(INPUT_PULLUP,b5);*/
}
void loop() {
Raimbow();
}
void RedOn(){}
void RedOff(){}
void Raimbow(){

  delay(t);
  digitalWrite(b2,LOW);
    delay(t);
  digitalWrite(b3,LOW);
    delay(t);
    digitalWrite(b4,LOW);
    delay(t);
  digitalWrite(b5,LOW);
  delay(t);
    digitalWrite(b6,LOW);
   delay(t);
    digitalWrite(b7,LOW);
  delay(t);
  digitalWrite(b8,LOW);
   delay(t);
  digitalWrite(b9,LOW);
  delay(t);
    digitalWrite(b10,LOW);
  delay(t);
  digitalWrite(b11,LOW);
  delay(t);
    digitalWrite(b12,LOW);

  delay(t);
  digitalWrite(b2,HIGH);
  delay(t);
  
  digitalWrite(b3,HIGH);
  delay(t);
  
  digitalWrite(b4,HIGH);
  delay(t);
  
  digitalWrite(b5,HIGH);
  delay(t);
    digitalWrite(b6,HIGH);
      delay(t);
      digitalWrite(b7,HIGH);
  delay(t);
  digitalWrite(b8,HIGH);
  delay(t);
  
  digitalWrite(b9,HIGH);
  delay(t);
  
  digitalWrite(b10,HIGH);
  delay(t);
  
  digitalWrite(b11,HIGH);
  delay(t);
    digitalWrite(b12,HIGH);
    delay(t);
}
