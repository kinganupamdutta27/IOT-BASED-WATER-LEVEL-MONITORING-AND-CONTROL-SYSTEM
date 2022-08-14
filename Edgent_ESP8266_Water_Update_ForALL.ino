#define BLYNK_TEMPLATE_ID "BLYNK_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME "BLYNK_DEVICE_NAME"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG

#define trig D5
#define echo D6
#define RelayPin1 13  //D7
#include "BlynkEdgent.h"
BlynkTimer timer;
long tankDepth=24;
int i=0;
int j=0;
int manual_Motor=1;
int auto_Motor=1;

BLYNK_WRITE(V1)
{
  if(manual_Motor==0)
  {
  Serial.println("Manual State: ON");
  }
  else
  {
  Serial.println("Manual State: OFF");
  }
  manual_Motor = param.asInt();
  if(manual_Motor==0)
  {
  Serial.println("Manual State: ON");
  }
  else
  {
  Serial.println("Manual State: OFF");
  }
}
BLYNK_WRITE(V3)
{
  if(auto_Motor==0)
  {
  Serial.println("Auto State: ON");
  }
  else
  {
  Serial.println("Auto State: OFF");
  }
  auto_Motor = param.asInt();
  if(auto_Motor==0)
  {
  Serial.println("Auto State: ON");
  }
  else
  {
  Serial.println("Auto State: OFF");
  }
  
}
void waterLevel(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.print("Centimeter: ");
  Serial.println(cm);
  double level= tankDepth-cm;
  if(level>0){
    long percentage=((level/tankDepth))*100;
    Blynk.virtualWrite(V0,percentage);
    Serial.print("Percentage: ");
    Serial.println(percentage);
    if(percentage>80)
    {
      digitalWrite(LED_BUILTIN,HIGH); //Motor Off
      Serial.println("Water Full >80% Motor OFF");
      digitalWrite(RelayPin1,HIGH);//Motor Off
    }
    else if(percentage<80 && auto_Motor == 0 && manual_Motor == 0)
    {
      digitalWrite(LED_BUILTIN,LOW); //Motor On
      Serial.println("Auto ON Manual ON Level <80 Motor On");
      digitalWrite(RelayPin1,LOW);//Motor On
    }
     else if(percentage<80 && auto_Motor == 0 && manual_Motor == 1)
    {
      digitalWrite(LED_BUILTIN,LOW); //Motor On
      Serial.println("Auto ON Manual OFF Level <80 Motor On");
       digitalWrite(RelayPin1,LOW);//Motor On
    }
     else if(percentage<80 && auto_Motor == 1 && manual_Motor == 0)
    {
      digitalWrite(LED_BUILTIN,LOW); //Motor On
      Serial.println("Auto OFF Manual ON Level <80 Motor On");
      digitalWrite(RelayPin1,LOW);//Motor On
    }
    else if(percentage<80 && auto_Motor == 1 && manual_Motor == 1)
    {
      digitalWrite(LED_BUILTIN,HIGH); //Motor OFF
      Serial.println("Auto OFF Manual OFF Level <80 Motor OFF");
      digitalWrite(RelayPin1,HIGH);//Motor Off
    }
    
  }
  else{
    digitalWrite(RelayPin1,HIGH);
    digitalWrite(LED_BUILTIN,HIGH);
    Blynk.virtualWrite(V0,0);
  }

}

void setup()
{
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(RelayPin1, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();
  timer.setInterval(10L, waterLevel);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
