//experimento turbio
//booleans que controlan cosas
//boolean welcomeB;

#define b1 3//emergencia
#define b2 4//entra persona
#define b3 5//sale persona

boolean dhtB;

boolean emergenciaB;
boolean lucesFueraB;
boolean lucesDentroB;
boolean aspersoresB;
boolean aforoCompletoB;

boolean puerta1Open;
boolean puerta1Close;
boolean puerta2Open;
boolean puerta2Close;

float humedad;
float temperatura;

long aforo;
int empleados=5;
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
  puerta1Close = false;
  puerta2Open = false;
  puerta2Close = false;

  humedad = 0;
  temperatura=0;

  aforo=empleados;
  
  pinMode(b1, INPUT_PULLUP);
    pinMode(b2, INPUT_PULLUP); 
    pinMode(b3, INPUT_PULLUP);

}

void loop() {
  RunSystem();

}



void RunSystem() {
  Serial.println("running system");


  CheckInputs();
  RunOutputs();

 delay(500);


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

  if (/*apretar boton abrir puerta1*/1 == 2) {
    if (puerta1Open == false) {
      puerta1Open = true;
    }
  }

  if (/*apretar boton abrir puerta2*/1 == 2) {
    if (puerta2Open == false) {
      puerta2Open = true;
    }
  }
  if (/*apretar boton cerrar puerta1*/1 == 2) {
    if (puerta1Close == false) {
      puerta1Close = true;
    }
  }

  if (/*apretar boton cerrar puerta2*/1 == 2) {
    if (puerta2Close == false) {
      puerta2Close = true;
    }
  }
    if (/*apretar boton cerrar puerta1*/1 == 2) {
    if (puerta1Close == false) {
      puerta1Close = true;
    }
  }

  if (/*apretar boton cerrar puerta2*/1 == 2) {
    if (puerta2Close == false) {
      puerta2Close = true;
    }
  }




  if (/*Presencia detectada(PIR)*/1 == 2) {
    lucesDentroB = true;
  }
  if (/*es de día*/1 == 2) {
    lucesFueraB = false;
  }
  if (/*es de noche*/1 == 1) {
    lucesFueraB = true;
  }

//Check dht for humedad and temp
 
}
//Outputs
void RunOutputs() {
  Serial.println("running outputs");
  if (puerta1Open == true) {
    Serial.println("opening puerta 1");
    //open puerta 1
    puerta1Open = false;
  }
  if (puerta1Close == true) {
    Serial.println("closing puerta 1");
    //close puerta 1
    puerta1Close = false;
  }
  if (puerta2Open == true) {
    Serial.println("opening puerta 2");
    //open puerta 2
    puerta2Open = false;
  }
  if (puerta2Close == true) {
    Serial.println("closing puerta 2");
    //close puerta 2
    puerta2Close = false;
  }
  if (lucesDentroB == true) {
    Serial.println("comienza secuencia de iluminacion");
    //enncender luz
    delay(30000);
    //apagar luz
    lucesDentroB = false;
  }
  if (lucesFueraB == true) {
    //enncender luz fuera
    Serial.println("luces de fuera encendidas");
  } else if (lucesFueraB == false) {
    //appagar luz fuera
    Serial.println("luces de fuera apagadas");
  }
  if (emergenciaB == true) {
    Serial.println("protocolo de emergencia iniciado");
    //encender led roja
    delay(500);
    //apagar led roja
  }
  if(humedad<=50){
    //apagar aspersores(led azul)
    } else if(humedad>=50){
    //encender aspersores (led azul)
    }


       if(temperatura<=4){
    //mucho frio(led rgb azul)
    }
     else if(temperatura<=14 &&temperatura>=5){
    //frio(led rgb cian)
    } else if(temperatura<=24 &&temperatura>=15){
    //normal (led rgb verde)
    }else if(temperatura<=34 &&temperatura>=25){
    //calor (led rgb amrillo)
    }else if(temperatura>=35){
    //calor (led rgb rojo)
    }

  Serial.print(aforo);
  if(aforo<=14){

         
          Serial.println(" hay pocas personas");
    // (led rgb verde)
    }else if(aforo<=39 &&aforo>=15){
      Serial.println(" hay gente");
    // (led rgb amrillo)
    }else if(aforo>=40){
      Serial.println(" aforo máximo alcanzado ");
    //(led rgb rojo)
    }
        } 
