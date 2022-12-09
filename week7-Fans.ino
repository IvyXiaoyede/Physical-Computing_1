#include <Servo.h>
#include <DHT.h>
#include <DHT_U.h>



DHT dhtA3(A3,11);
Servo servo_11;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 //fans
 dhtA3.begin();
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 //Car Control
 pinMode(7,INPUT);
 servo_11.attach(11);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Temputer control fans
 // Fans();
  //CarControl();
 // CarControltofans();
}
void Fans()
{
   Serial.println(String("T:")+String(dhtA3.readTemperature( )));
  delay(500);

  if(dhtA3.readTemperature()>30)
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    }else
    {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    }
}
void CarControl()
{
  if(digitalRead(7)==0)
  {servo_11.write(90);
  delay(500);
    }else{
    servo_11.write(0);
    delay(1000);
    }
}
void CarControltofans()
{
  if(digitalRead(7)==0)
  {servo_11.write(90);
  delay(500);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
    }else{
    servo_11.write(0);
    delay(1000);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    }
}
