// 2025 4
// Daejin University 
// arduino program
// ultrasound distance measure for disabled 

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

//SoftwareSerial mySoftwareSerial(9, 10); // 소프트웨어 시리얼용 핀 지정
SoftwareSerial mySoftwareSerial(10, 11);  // PCB 2024
DFRobotDFPlayerMini myDFPlayer;           // 객체 생성

const unsigned long interval = 5000;      // 5초 간격

int trigPin = A1;  // ultrasound trig
int echoPin = A0;  // ultrasound echo

//--------------------------------------------------------------
void setup()
{
  mySoftwareSerial.begin(9600);   // MP3 player
  Serial.begin(9600);             // PC serial 

  pinMode(2, INPUT);              // key-in / tone=0
  pinMode(3, INPUT);              // mode setting / mp3=1 / tone=0
  pinMode(4, OUTPUT);             // led ON
  pinMode(5, OUTPUT);             // buzzer pwm

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);



  if (!myDFPlayer.begin(mySoftwareSerial), false) {  //객체 초기화
    Serial.println(F("Unable to begin:"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online.")); 
  myDFPlayer.setTimeOut(500); //시리얼 통신용 타임아웃 시간 지정
  myDFPlayer.volume(30);      //소리 크기 0-30 사이의 값을 인수로 입력.
  
  tone(5,400,50);           // buzzer PWM
  delay(100);


}


//---------------------------------------------
void loop()
{
  int freq;
  
  for (int m=1;m<30;m++) {
    freq = 50*m+100;  // tone frequency
    tone(5,freq,200);   // tone
    //noTone(5);
    delay(200);
  }  
  delay(1000);  

  digitalWrite(4,HIGH); 
  delay(100);
  digitalWrite(4,LOW); 

}
