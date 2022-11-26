// This example sends data to multiple variables to
// Ubidots through HTTP protocol.

/****************************************
 * Include Libraries
 ****************************************/

#include "Ubidots.h"

/****************************************
 * Define Instances and Constants
 ****************************************/
int Len_A = D1;
int Len_B = D2;
int Len_C = D3;
int Len_D = D4;
int Led_A = D5;
int Led_B = D6;
int Led_C = D7;
int Led_D = D8;
const char* UBIDOTS_TOKEN = "BBFF-UAXxUtHas9X4kOVBuoOWNsJQUTeUHF";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "TRAFFIC";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "1234567890";      // Put here your Wi-Fi password

Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

/****************************************
 * Auxiliar Functions
 ****************************************/

// Put here your auxiliar functions

/****************************************
 * Main Functions
 ****************************************/

void setup() 
{
  Serial.begin(115200);

  //----CONNECTING TO WIFI----//
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages

  //----SETTING PIN CONFIGURATIONS----//
  pinMode(Len_A, OUTPUT);
  pinMode(Len_B, OUTPUT);
  pinMode(Len_C, OUTPUT);
  pinMode(Len_D, OUTPUT);
  pinMode(Led_A,OUTPUT);
  pinMode(Led_B,OUTPUT);
  pinMode(Led_C,OUTPUT);
  pinMode(Led_D,OUTPUT);
  //----SERIAL INITIALIZATION----//
  Serial.println("Setup Completed");
  delay(500);
}

void loop() 
{

  //----GETTING VARIABLE VALUE FROM UBIDOTS----//
  int A = ubidots.get("bcddc2b39b74","lane-a");  // Change for your variable name
  int B = ubidots.get("bcddc2b39b74","lane-b");  // Change for your variable name
  int C = ubidots.get("bcddc2b39b74","lane-c");  // Change for your variable name
  int D = ubidots.get("bcddc2b39b74","lane-d");  // Change for your variable name
  if (A != ERROR_VALUE) {
    Serial.print("Value A : ");
    Serial.println(A);
  }
  if (B != ERROR_VALUE) {
    Serial.print("Value B : ");
    Serial.println(B);
  }
  if (C != ERROR_VALUE) {
    Serial.print("Value C : ");
    Serial.println(C);
  }
  if (D != ERROR_VALUE) {
    Serial.print("Value D : ");
    Serial.println(D);
  }
  if(A==1)
  {
    digitalWrite(Led_A,HIGH);
    digitalWrite(Len_A,HIGH);
  }
  else
  {
    digitalWrite(Led_A,LOW);
    digitalWrite(Len_A,LOW);
  }
  if(B==1)
  {
    digitalWrite(Led_B,HIGH);
    digitalWrite(Len_B,HIGH);
  }
  else
  {
    digitalWrite(Led_B,LOW);
    digitalWrite(Len_B,LOW);
  }
  if(C==1)
  {
    digitalWrite(Led_C,HIGH);
    digitalWrite(Len_C,HIGH);
  }
  else
  {
    digitalWrite(Led_C,LOW);
    digitalWrite(Len_C,LOW);
  }
  if(D==1)
  {
    digitalWrite(Led_D,HIGH);
    digitalWrite(Len_D,HIGH);
  }
  else
  {
    digitalWrite(Led_D,LOW);
    digitalWrite(Len_D,LOW);
  }
  
  Serial.println("DONE!!!");
  delay(1000);
}