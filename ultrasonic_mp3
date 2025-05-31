#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11);  // PCB 2024
DFRobotDFPlayerMini myDFPlayer;           // 객체 생성

const unsigned long interval = 5000;      // 5초 간격

int trigPin = A1;
int echoPin = A0;


void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  pinMode(4, OUTPUT);              // buzzer
  pinMode(5, OUTPUT);              // buzzer

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(4,HIGH); 
  digitalWrite(5,HIGH); 
  delay(200);
  digitalWrite(4,LOW); 
  digitalWrite(5,LOW); 
  delay(1);

  if (!myDFPlayer.begin(mySoftwareSerial), false) {  //객체 초기화
    Serial.println(F("Unable to begin:"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online.")); 
  myDFPlayer.setTimeOut(500); //시리얼 통신용 타임아웃 시간 지정
  myDFPlayer.volume(30);      //0-30사이의 값을 인수로 입력.

  myDFPlayer.play(23);        // start sound
  delay(3000);
  
  digitalWrite(4,HIGH); 
  digitalWrite(5,HIGH); 
  delay(200);
  digitalWrite(4,LOW); 
  digitalWrite(5,LOW); 
  delay(10);

  Serial.println(F("play start")); 

}

//---------------------------------------------------
void loop()
{
  long duration, distance;
  int dist_int, dist_numb;

  digitalWrite(4,HIGH); 
  digitalWrite(5,HIGH); 
  delay(100);
  digitalWrite(4,LOW); 
  digitalWrite(5,LOW); 
  delay(1);

  for(int m=1;m<=22;m++) {
    Serial.println(m); 
    myDFPlayer.play(m);  // 
    delay(1200); 
  }

}
//----------------------------------------------------
