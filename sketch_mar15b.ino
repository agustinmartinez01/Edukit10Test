//Test Placas Edukit 10 v7.1-001
//leds
#define digitalled2 2
#define digitalled3 3
#define  digitalled4 4
#define  digitalled7 7
#define digitalled8 8
#define  digitalled9 9

//INterruptores
#define interr1 10
#define interr2 11
#define interr3 12
//
#define bosina 13

//servo
#include <Servo.h>
Servo myservo;
int pos = 0;
enum estado {led=1, interruptores=2, ser=3, hhh=4};
void setup() {
  
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
  //myservo.attach(11);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(9600);
  Serial.println("Test Placa Edukit 10");
  Serial.println("Indique para probar ...");
  Serial.println("1----->Leds");
  Serial.println("2----->INterruptores");
  Serial.println("3----->Servos");
  delay(1000);
  int estadoc=Serial.parseInt();
  switch (estadoc) {
    case 1: 
          leds();
          break;
    case 2: 
          interr();
          break;
    case 3:
          serv();
          break;
    
                                   
          } 
  //leds();
  //interr();
  //serv();
  delay(2000);
}

//funcion serv
void serv(){
  Serial.println("Gira 180 grados");
  for(pos = 0; pos <= 180; pos += 1) 
  {                                  
    myservo.write(pos);               
    delay(50);                       
  } 
  delay(1000);
  Serial.println("Gira menos 180 grados");
  for(pos = 180; pos>=0; pos-=1)      
  {                                
    myservo.write(pos);               
    delay(50);                        
  } 
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
  
}

