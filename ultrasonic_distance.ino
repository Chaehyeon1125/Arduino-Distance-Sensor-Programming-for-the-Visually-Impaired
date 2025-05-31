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
  myDFPlayer.setTimeOut(500); //시리얼 통신용 타임아웃 시간 지정
  myDFPlayer.volume(30);      //0-30사이의 값을 인수로 입력.
 
  digitalWrite(4,HIGH);      // LED
  delay(50);
  digitalWrite(4,LOW); 
  tone(5,400,50);           // buzzer PWM
  delay(100);

}

//---------------------------------------------
boolean key_in, method;
int freq, silence;
//---------------------------------------------
void loop()
{
  long duration, distance;
  int dist_int, dist_mp3;
  
  key_in = digitalRead(2);
  method = digitalRead(3);
  Serial.print(key_in);
  Serial.print("  ");
  Serial.println(method);

  digitalWrite(4,HIGH);   // start LED
  delay(50);
  digitalWrite(4,LOW); 
  delay(1);

  // ultrasound transmit 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 17 / 1000)+1;    // +1 = 거리 0 제거
  if (distance > 200)  distance = 210;    // max distance limit

  dist_int  = distance/10;        // integer number of distance 
  dist_mp3 = dist_int;            // mp3 file number

  if (dist_int == 0)       dist_mp3 = 21;      // distance ~~ 0cm   가깝다
  else if (dist_int >20)   dist_mp3 = 22;      // 멀다

  Serial.print(distance);
  Serial.print("  ");
  Serial.print(dist_int);
  Serial.print("  ");
  Serial.println(dist_mp3);       // integer mp3 file
  
  if (method == 0 || key_in ==0 ) {    // tone mode
    freq    = 4000-100*dist_int;       // tone frequency
    silence = 20*dist_int+100;         // silence time 
    tone(5,freq,50);                   // tone 
    delay(silence);                    // 측정 시간 간격 조정   
  }

  else if (method == 1 && key_in ==1 ) {  // mp3 sound mode
    Serial.println("MP3 sound mode");     //
    delay(1200);  // mp3 play time 
  }   // else if
  

}
