#include <FastLED.h>
#define NUM_LEDS 30
#define DATA_PIN 3
#define LED_TYPE WS2812         // LED灯带型号
#define COLOR_ORDER GRB
#define BRIGHTNESS 64

uint8_t max_bright = 128; 
CRGB leds[NUM_LEDS];        
//const int SoundInput=A0;



int irSensor=8;

//Fan
int motorIn1=11;


void setup() {
  // put your setup code here, to run once:

 Serial.begin(9600);
 LEDS.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);  // 初始化灯带
 FastLED.setBrightness(60);                            // 设置灯带亮度 Max_bright
 FastLED.clear();
 FastLED.show();
 
 
 pinMode(irSensor,INPUT);       //红外人体感应
 pinMode(13,OUTPUT); //检测小灯

 pinMode(motorIn1,OUTPUT); //风扇
}

void loop() {

   
  bool sensorReading = digitalRead(irSensor); 
  if(sensorReading==1)
  {
    LED_LIGHT_TURNON();
   //LED_LIGHT_TURN();
     
   }else{
    LED_LIGHT_TURN();
   // LED_LIGHT_TURNOFF();
    }
   Serial.println(sensorReading); 
   LEDD();
}

void LEDD(){
   int value =analogRead(A1);
  Serial.println(value);
   if (value>=100) {
    analogWrite(motorIn1,450);
    }
    else {
    analogWrite(motorIn1,50);
    }
}

void LED_LIGHT_TURNON()
{
  for (int i=0; i<NUM_LEDS; i++ )
   {
   leds[i] = CRGB(50, 255-2*i, 2*i );
   FastLED.setBrightness(6*i);
   FastLED.show();
   delay (5);
   
   }
}

void LED_LIGHT_TURNOFF()
{
  
    for (int i=0; i<NUM_LEDS; i++ )
    {
    leds[i]=CRGB::Black;
    FastLED.show(); 
    }
}

void LED_LIGHT_TURN()
{
    for (int i=0; i<NUM_LEDS; i++ )
    {
    leds[i]=CRGB::White;
    FastLED.show(); 
    
    }
}
