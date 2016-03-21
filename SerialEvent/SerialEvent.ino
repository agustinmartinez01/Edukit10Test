//Test Placas Edukit 10 v7.1-001
//leds
#define digitalled2 2
#define digitalled3 3
#define digitalled4 4
#define digitalled7 7
#define digitalled8 8
#define digitalled9 9

//INterruptores
#define interr1 10
#define interr2 11
#define interr3 12
//bosina
#define bosina 13
//Motor
#define mot 5
#define mot1 6
//servo
#include <Servo.h>
Servo myservo;
Servo myservo1;
int pos = 0;

//Baterias
int valorPort = 0;
float voltajePort = 0;


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int estado = 0;
void setup() {
  // initialize serial:
  Serial.begin(9600);

  //leds
  pinMode(digitalled2, OUTPUT);
  pinMode(digitalled3, OUTPUT);
  pinMode(digitalled4, OUTPUT);
  pinMode(digitalled7, OUTPUT);
  pinMode(digitalled8, OUTPUT);
  pinMode(digitalled9, OUTPUT);
  //interruptores
  pinMode(interr1,INPUT);
  pinMode(interr2,INPUT);
  pinMode(interr3,INPUT);
  pinMode(bosina, OUTPUT);
  //servo
  myservo.attach(10);
  myservo1.attach(11);
//motor
  pinMode(mot,OUTPUT);
  pinMode(mot1,OUTPUT);


  
  Serial.println("Test Placa Edukit 10");
  Serial.println("Indique para probar ...");
  Serial.println("1----->Leds");
  Serial.println("2----->INterruptores");
  Serial.println("3----->Servos");
  Serial.println("4----->Motor");
  //Serial.println("5----->Ldr");
  Serial.println("6----->Baterias");
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  serialEvent(); //call the function
  // print the string when a newline arrives:
  if (stringComplete) {
    
    Serial.println(inputString);
    estado=inputString.toInt();
    switch (estado) {
    case 1: 
          leds();
          break;
    case 2: 
          interr();
          break;
    case 3:
          serv();
          closed();
          break;
    case 4:
          motor();
          break;
   /*case 5:
          sensorluz();
          //Serial.println("Valor obtenido"+(int)analogRead(ldr));
          //closed();
          break;*/
  case 6:
          bateria();
          break;
    case 0:
          closed();
          break;
                                   
          } 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void bateria(){
    valorPort=analogRead(6);
    voltajePort=((valorPort*12)/737)/2;
    Serial.println(valorPort);
    Serial.print("Voltaje obtenido  ");
    Serial.println(voltajePort);
    closed();
}

/*void sensorluz(){
  valor = (int)analogRead(ldr);
  Serial.println("Valor obtenido"+valor);
  closed();
}//end closed*/


//funcion closed
void closed(){
  int i = 0;
  for(i = 0; i <= 12; i += 1) 
  {                                  
    digitalWrite(i,LOW);                  
  }
}//endclosed

//funcion motor
void motor(){
  Serial.println("Girando MOtor");
  digitalWrite(3,HIGH);
  analogWrite(mot,250);
  analogWrite(mot1,0);
  delay(3000);
  Serial.println("Girando Motor sentido opuesto");
  analogWrite(mot1,250);
  analogWrite(mot,0);
  delay(3000);
  closed();
}

//funcion serv
void serv(){
  Serial.println("Gira 180 grados");
  for(pos = 0; pos <= 180; pos += 1) 
  {                                  
    myservo.write(pos);
    myservo1.write(pos);               
    delay(15);                       
  } 
  delay(500);
  Serial.println("Gira menos 180 grados");
  for(pos = 180; pos>=10; pos-=1)      
  {                                
    myservo.write(pos);  
    myservo1.write(pos);             
    delay(15);                        
  } 
  closed();
}


void interr(){
  bool estadobtn = 0;
  bool estadobtn1 = 0;
  bool estadobtn2 = 0;
  while ((estadobtn==0) && (estadobtn1==0) &&(estadobtn2==0)){
    Serial.println("Precione Boton10");
    delay(3000);
    estadobtn = digitalRead(interr1);
    if (estadobtn==1){
      digitalWrite(bosina,HIGH);
      delay(800);
      digitalWrite(bosina,LOW);
      //estadobtn=0;
    }
    Serial.println("Precione Boton11");
    delay(3000);
    estadobtn1 = digitalRead(interr2);
    if (estadobtn1==1){
      digitalWrite(bosina,HIGH);
      delay(800);
      digitalWrite(bosina,LOW);
      //estadobtn1=0;
    }
    Serial.println("Precione Boton12");
    delay(3000);
    estadobtn2 = digitalRead(interr3);
    if (estadobtn2==1){
      digitalWrite(bosina,HIGH);
      delay(800);
      digitalWrite(bosina,LOW);
      //estadobtn2=0;
    }
    closed();
    
    
  }
}

void leds (){
  delay(2000);
  Serial.println("Probando leds");
  delay(2000);
  Serial.println("Prendido");
  digitalWrite(digitalled2,HIGH);
  digitalWrite(digitalled3,HIGH);
  digitalWrite(digitalled4,HIGH);
  digitalWrite(digitalled7,HIGH);
  digitalWrite(digitalled8,HIGH);
  digitalWrite(digitalled9,HIGH);
  delay(1000);
  Serial.println("Apagando leds");
  delay(2000);
  digitalWrite(digitalled2,LOW);
  digitalWrite(digitalled3,LOW);
  digitalWrite(digitalled4,LOW);
  digitalWrite(digitalled7,LOW);
  digitalWrite(digitalled8,LOW);
  digitalWrite(digitalled9,LOW);
  Serial.println("Apagado");
  delay(1000);
  closed();
}


