// 2025 4
// Daejin University 
// arduino program
// ultrasound distance measure for disabled 
// tone  : D5 
// motor : D6
// MP3

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
  pinMode(6, OUTPUT);             // motor

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(4,HIGH); 
  digitalWrite(5,HIGH); 
  digitalWrite(6,HIGH); 
  delay(10);
  digitalWrite(4,LOW); 
  digitalWrite(5,LOW); 
  digitalWrite(6,LOW); 

  if (!myDFPlayer.begin(mySoftwareSerial), false) {  //객체 초기화
    Serial.println(F("Unable to begin:"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online.")); 
  myDFPlayer.setTimeOut(500); //시리얼 통신용 타임아웃 시간 지정
  myDFPlayer.volume(30);      //소리 크기 0-30 사이의 값을 인수로 입력.

  myDFPlayer.play(23);        // start sound 23번 파일 
  delay(3000);
  
  digitalWrite(4,HIGH);      // LED
  delay(50);
  digitalWrite(4,LOW); 
  
  tone(5,400,50);           // buzzer PWM
  delay(100);

  Serial.println(F("play start")); 

}

//---------------------------------------------
boolean key_in, method;
int freq, silence;
//---------------------------------------------
void loop()
{
  long duration, distance;
  int dist_int, dist_numb;
  
  key_in = digitalRead(2);
  method = digitalRead(3);
  Serial.print(key_in);
  Serial.print("  ");
  Serial.println(method);

  digitalWrite(4,HIGH);   // start LED
  delay(50);
  digitalWrite(4,LOW); 
  delay(1);

  // ultrasound trig pulse transmit 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 1+(duration * 17 / 1000);    // 거리 0 제거
  if (distance > 200)  distance = 210;    // max distance limit

  dist_int = distance/10;        // integer number of distznce 
  dist_numb = dist_int;          // mp3 file number

  if (dist_int == 0)       dist_numb = 21;      // distance ~~ 0cm   가깝다
  else if (dist_int >20)   dist_numb = 22;      // 멀다

  if (dist_int < 2) {         // motor
     digitalWrite(6,HIGH);      // motor
     delay(20);
     digitalWrite(6,LOW); 
  }

  Serial.print(distance);
  Serial.print("  ");
  Serial.print(dist_int);
  Serial.print("  ");
  Serial.println(dist_numb);  // integer
  
  if (method == 0 || key_in ==0 ) {  // tone mode
    freq    = 4000-100*dist_int;  // tone frequency
    silence = 20*dist_int+10;    // silence time 
    tone(5,freq,50);   // tone 
    delay(silence);
  }

  else if (method == 1 && key_in ==1 ) {  // mp3 sound mode
    switch(dist_numb) {    // sound
      case 1:
        myDFPlayer.play(1);  // 10cm
        break;
      case 2:
        myDFPlayer.play(2);
        break;
      case 3:
        myDFPlayer.play(3);
        break;
      case 4:
        myDFPlayer.play(4);
        break;
      case 5:
        myDFPlayer.play(5);
        break;
      case 6:
        myDFPlayer.play(6);
        break;
      case 7:
        myDFPlayer.play(7);
        break;
      case 8:
        myDFPlayer.play(8);
        break;  
      case 9:
        myDFPlayer.play(9);  // 90cm
        break;
      case 10:
        myDFPlayer.play(10);  // 100cm
        break;   
      case 11:
        myDFPlayer.play(11);  // 110cm
        break;  
      case 12:
        myDFPlayer.play(12);
        break;
      case 13:
        myDFPlayer.play(13);
        break;
      case 14:
        myDFPlayer.play(14);
        break;
      case 15:
        myDFPlayer.play(15);
        break;
      case 16:
        myDFPlayer.play(16);
        break;
      case 17:
        myDFPlayer.play(17);
        break;
      case 18:
        myDFPlayer.play(18);
        break;  
      case 19:
        myDFPlayer.play(19);  // 190cm
        break;
      case 20:
        myDFPlayer.play(20);  // 2m
        break;   
      case 21:
        myDFPlayer.play(21);  // 가깝다.
        delay(300);
        break;    
      case 22:
        myDFPlayer.play(22);  // 멀다.
        delay(300);
        break;                 
    } 
    delay(1000);  // mp3 play time 
  }   // else if
  

}
