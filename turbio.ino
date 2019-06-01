//experimento turbio
//booleans que controlan cosas
//boolean welcomeB;

#define b1 3//emergencia
#define b2 4//
#define b3 5//
#define b4 6//puerta1
#define b5 7//puerta2


int ledEmergencia = 22;
int ledAforoRed = 24;
int ledAforoGreen = 26;
int ledAforoBlue = 28;
int ledTempRed = 30;
int ledTempGreen = 32;
int ledTempBlue = 34;
int ledFuera1 = 36;
int ledFuera2 = 38;
int ledDentro1 = 40;
int ledAspersor = 42;

boolean dhtB;

boolean emergenciaB;
boolean lucesFueraB;
boolean lucesDentroB;
boolean aspersoresB;
boolean aforoCompletoB;
boolean lm35B;
boolean puerta1Open;
//boolean puerta1Close;
boolean puerta2Open;
//boolean puerta2Close;

float humedad;
float temperatura;

//aforo
long aforo;
int empleados = 5;

//millis()
long previousMillis = 0;
long ping = 0;
long pirTime = 0;
long previousPir;
//photocell
int photocell = 15;

//Servos
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
Servo myservo2;
int pos = 0;
int servoTime = 5;

//PIR
int pirPin = 11; // Input for HC-S501
int pirValue; // Place to store read PIR Value

//lm35
int lm35_id = 13;
long tempTime = 0;
long previousTemp = 0;

//humedad
int adc_id = 14;
long waterTime = 0;
long previousWater = 0;

//////////////////////////////////////////////////////////////////////////////SETUP

void setup() {
  Serial.begin(9600);
  // welcomeB=false;
  emergenciaB = false;
  dhtB = true;

  lucesFueraB = false;
  lucesDentroB = false;
  aspersoresB = false;
  aforoCompletoB = false;
  puerta1Open = false;
  puerta2Open = false;
  lm35B = false;

  humedad = 0;
  temperatura = 0;

  aforo = empleados;

  pinMode(ledEmergencia, OUTPUT);
  pinMode(ledAforoRed, OUTPUT);
  pinMode(ledAforoGreen, OUTPUT);
  pinMode(ledAforoBlue, OUTPUT);
  pinMode(ledTempRed, OUTPUT);
  pinMode(ledTempGreen, OUTPUT);
  pinMode(ledTempBlue, OUTPUT);
  pinMode(ledFuera1, OUTPUT);
  pinMode(ledFuera2, OUTPUT);
  pinMode(ledDentro1, OUTPUT);
  pinMode(ledAspersor, OUTPUT);


  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b4, INPUT_PULLUP);
  pinMode(b5, INPUT_PULLUP);
  //servos
  myservo.attach(9);
  myservo2.attach(10);
  //servos a posicion 0
  myservo.write(0);
  myservo2.write(180);
  //PIR
  pinMode(pirPin, INPUT);
  previousPir = 0;
}

void loop() {
  RunSystem();

}


//////////////////////////////////////////////////////////////////////////////RUN SYSTEM
void RunSystem() {


  Serial.println("running system");


  CheckInputs();
  RunOutputs();

  delay(200);
  ping = millis() - previousMillis;
  Serial.print(ping); Serial.println("ms delay");
  previousMillis = millis();
  Serial.print(analogRead(photocell)); Serial.println(" light");
}
//Inputs
void CheckInputs() {
  Serial.println("checking inputs");
  if (digitalRead(b1) == LOW) {
    if (emergenciaB == false) {
      //abrir puertas
      emergenciaB = true;
    }
    else if (emergenciaB == true) {
      //apagar luz roja emergencia
      emergenciaB = false;
    }
  }
  if (digitalRead(b2) == LOW)aforo++;
  if (digitalRead(b3) == LOW)aforo--;


  if (digitalRead(b4) == LOW) {
    if (puerta1Open == false) {
      OpenPuerta1();
      puerta1Open = true;
    } else if (puerta1Open == true) {
      ClosePuerta1();
      puerta1Open = false;
    }
  }
  if (digitalRead(b5) == LOW) {
    if (puerta2Open == false) {
      OpenPuerta2();
      puerta2Open = true;
    } else if (puerta2Open == true) {
      ClosePuerta2();
      puerta2Open = false;
    }
  }



  //PIR
  if (lucesDentroB == true) {
    pirTime = pirTime + (millis() - previousPir);
    Serial.print(pirTime); Serial.println("ms pirtime");
    previousPir = millis();

  }
  if (digitalRead(pirPin) == HIGH) {

    lucesDentroB = true;
    // pirValue = digitalRead(pirPin);
    // digitalWrite(ledDentro1, pirValue);
    digitalWrite(ledDentro1, HIGH);

  }
  if (pirTime > 5000) {
    digitalWrite(ledDentro1, LOW);
    pirTime = 0;
    lucesDentroB = false;
  }
  //PHOTOCELL
  if (analogRead(photocell) > 400) {
    lucesFueraB = false;
  }
  if (analogRead(photocell) <= 400) {
    lucesFueraB = true;
  }

  //Check dht for humedad and temp

}
//Outputs
void RunOutputs() {
  Serial.println("running outputs");

  if (lucesFueraB == true) {
    //enncender luz fuera
    digitalWrite(ledFuera1, HIGH);
    digitalWrite(ledFuera2, HIGH);
    Serial.println("luces de fuera encendidas");
  } else if (lucesFueraB == false) {
    //appagar luz fuera
    digitalWrite(ledFuera1, LOW);
    digitalWrite(ledFuera2, LOW);
    Serial.println("luces de fuera apagadas");
  }
  if (emergenciaB == true) {
    Serial.println("protocolo de emergencia iniciado");
    if (puerta1Open == false) {
      OpenPuerta1();
      puerta1Open = true;
    }
    if (puerta2Open == false) {
      OpenPuerta2();
      puerta2Open = true;
    }
    digitalWrite(ledEmergencia, HIGH);
    delay(500);
    digitalWrite(ledEmergencia, LOW);
  }
  if (humedad <= 50) {
    //apagar aspersores(led azul)
  } else if (humedad >= 50) {
    //encender aspersores (led azul)
  }




  Serial.print(aforo);
  if (aforo <= 14) {


    Serial.println(" hay pocas personas");
    // (led rgb verde)
    digitalWrite(ledAforoGreen, HIGH);
    digitalWrite(ledAforoRed, LOW);
    digitalWrite(ledAforoBlue, LOW);
  } else if (aforo <= 39 && aforo >= 15) {
    Serial.println(" hay gente");
    // (led rgb amrillo)
    digitalWrite(ledAforoGreen, HIGH);
    digitalWrite(ledAforoRed, HIGH);
    digitalWrite(ledAforoBlue, LOW);
  } else if (aforo >= 40) {
    Serial.println(" aforo máximo alcanzado ");
    //(led rgb rojo)
    digitalWrite(ledAforoGreen, LOW);
    digitalWrite(ledAforoRed, HIGH);
    digitalWrite(ledAforoBlue, LOW);
  }
  Water();
  Temp();
}
void ClosePuerta1() {
  for (pos = 0; pos <= 180; pos += 1) {
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(servoTime);
  }
}
void OpenPuerta2() {
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(servoTime);
  }
}
void OpenPuerta1() {
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(servoTime);
  }
}
void ClosePuerta2() {
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(servoTime);
  }
}
void Water() {
  waterTime = waterTime + (millis() - previousWater);
  previousWater = millis();
  if (aspersoresB == false) {
    if (waterTime > 1000) {
      waterTime = 0;
      aspersoresB = true;
    }

  }
  if (aspersoresB == true) {
    int value = analogRead(adc_id); // get adc value
    Serial.println(value);
    if (value < 50) {
      digitalWrite(ledAspersor, HIGH);
    } else digitalWrite(ledAspersor, LOW);
    aspersoresB = false;
  }
}
void Temp() {
  tempTime = tempTime + (millis() - previousTemp);
  previousTemp = millis();
  if (lm35B == false) {
    if (tempTime > 1000) {
      tempTime = 0;
      lm35B = true;
    }

  }
  if (lm35B == true) {
    int tempValue = analogRead(lm35_id); // get adc value
    temperatura = ((tempValue - 32) / 1.8);
    Serial.print("temp="); Serial.println(temperatura);
    lm35B = false;
  }
  if (temperatura <= 4) {
    //mucho frio(led rgb azul)
    digitalWrite(ledTempGreen, LOW);
    digitalWrite(ledTempRed, LOW);
    digitalWrite(ledTempBlue, HIGH);
  }
  else if (temperatura <= 24 && temperatura >= 5) {
    //frio(led rgb cian)
    digitalWrite(ledTempGreen, HIGH);
    digitalWrite(ledTempRed, LOW);
    digitalWrite(ledTempBlue, HIGH);
  } else if (temperatura <= 34 && temperatura >= 25) {
    //normal (led rgb verde)
    digitalWrite(ledTempGreen, HIGH);
    digitalWrite(ledTempRed, LOW);
    digitalWrite(ledTempBlue, LOW);
  } else if (temperatura <= 44 && temperatura >= 35) {
    //calor (led rgb amrillo)
    digitalWrite(ledTempGreen, HIGH);
    digitalWrite(ledTempRed, HIGH);
    digitalWrite(ledTempBlue, LOW);
  } else if (temperatura >= 45) {
    //calor (led rgb rojo)
    digitalWrite(ledTempGreen, LOW);
    digitalWrite(ledTempRed, HIGH);
    digitalWrite(ledTempBlue, LOW);
  }
}
