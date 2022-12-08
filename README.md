# Physical-Computing_1

# Week 6

In week 6, I want to make sure which sensor I want to use it, and test it. Finally I make a decision to use the sound sensor and a HC-SR501. But at the first time, I never think about the HC-SR501, I use the distance sensor. But the distance sensor cannot test the coming things is a people, only test the something coming, so I want to change the sensor. Than I use the PIR ，it was a good sensor but there has a red light always bright, it was not I want. Finally, I decided to use a HC-SR501, it was a good sensor to test coming things is people and without any light.


<img width="619" alt="截屏2022-12-08 下午3 55 29" src="https://user-images.githubusercontent.com/119190967/206495567-5ccd0b47-a44c-4400-8fd7-fee3eaef33ce.png">

<img width="547" alt="image" src="https://user-images.githubusercontent.com/119190967/206496518-9a3a8958-b77f-4331-a60c-5d3a010757e0.png">

```

#define trigPin 6 //输入
#define echoPin 5 //输出


long duration; 
int distance; 

void setup() {
  pinMode(5, OUTPUT); 
  pinMode(6, INPUT); 
  pinMode(12,OUTPUT);
  Serial.begin(9600); 
 // Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
 // Serial.println("with Arduino UNO R3");
}
void loop() {
  digitalWrite(12, LOW);
  //digitalWrite(5, LOW);
  delayMicroseconds(2);
  
  //digitalWrite(5, HIGH);
  //delayMicroseconds(10);
 // digitalWrite(5, LOW);

  duration = pulseIn(6, HIGH);

 // distance = duration * 0.034 / 2; 
  
  Serial.print("Distance: ");
  Serial.print(distance);
    Serial.println(duration);
  if(distance<=10)
  {
    digitalWrite(12, HIGH);
    }
}
```


<img width="489" alt="截屏2022-12-08 下午4 01 15" src="https://user-images.githubusercontent.com/119190967/206497095-d7c80778-c2cc-47e7-b67e-4dac64d661aa.png">

Then I design a workflow to help me to understand the work, to help me to thinking more logically. And I also draw a Tinkecad to help me understand the route map，but the Tinkecad without the sound sensor, so I only can draw the sound sensor and to link it.

<img width="493" alt="截屏2022-12-08 下午3 55 59" src="https://user-images.githubusercontent.com/119190967/206497530-e27cd08b-89e2-4022-b6f1-512a275ebb33.png">

<img width="620" alt="截屏2022-12-08 下午3 56 13" src="https://user-images.githubusercontent.com/119190967/206497776-b6f83741-6a48-4d54-bd4e-ff8e8c1c8ba1.png">

# Week 7

In this week I want to link sensors, and test the connect witrh the every sensor. At first, I try to link the LED strip and the sound sensor. But I meet a problem that I did not know how to control the color of the lights, they only show the colorful light and I cannot use the code to control it. So I found the other LED strip, and I found it the code only can use for the LED_TYPE WS2812, and the LED Strip type is different to use it, it can use it under the water. Than I borrow the other LED strip and add the other code about how to control turn off the LED strip.

Then, I want to link sensors, I link the LED strip and the Sound senser at first, an test it. Here is a LED test code:

```
// include library
#include<FastLED.h>

//define number of LED and pin
#define NUM_LEDS 8
#define DATA_PIN 5

// create the ld object array
CRGB leds[NUM_LEDS];

// define 3 byte for the random color
byte  r, g, b;

void setup() {
  // init the LED object
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // set random seed
  randomSeed(analogRead(0));
}


void loop() {
  // loop over the NUM_LEDS
  for (int cur = 0; cur < NUM_LEDS; cur++) {
    // chose random value for the r/g/b
    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);

    //set the value to the led
    leds[cur] = CRGB (r, g, b);

    // set the colors set into the phisical LED
    FastLED.show();

    // delay 50 millis
    FastLED.delay(200);
  }
}
```

Secondly, I use the fans and sound sensor,in order to link the sound sensor with the fans I found a question that fans is a direct current never have the motors to change it, I test for a long time and I found the ULN2003 driver is a good motor to help sound sensor and fans linking.

![stepper-motor-and-uln2003-driver-board](https://user-images.githubusercontent.com/119190967/206562173-6f1263da-b9e8-4ab2-a996-a2771279f862.jpeg)

```
int motorIn1=2;
//int motorIn2=3;


void setup() {
  //int value =analogRead(A1);
  // put your setup code here, to run once:
 pinMode(motorIn1,OUTPUT);
 //pinMode(motorIn,OUTPUT);
 Serial.begin(9600);
  
}

void loop() {
  int value =analogRead(A1);
  Serial.println(value);
  // put your main code here, to run repeatedly:
    if (value>=300) {
      //analogWrite(motorIn1,Speed);
    analogWrite(motorIn1,150);
    }
    else {  
     analogWrite(motorIn1,150);
    }
}
```

# Week 8

In this week, I think the most important things is to do the house to decorate it. And I need to soldering the wiring with a tool, because at the end we don't use the breadboard to control it. I spead two days to finish it, actually I only can use one day, but something wrong and some line broken. So I need to relink at next day.

![WechatIMG58](https://user-images.githubusercontent.com/119190967/206564820-729b3353-b20f-4eb2-8307-6276e86d410d.jpeg)

Add I want to use the Acrylic board to making a house. So I draw a picture which can be used in the laser cutter machine. And I use the cut board to cut it at first, and use for testing. I found a problem that I never combine it successfully. I asked other students how to solve the problem and eventually I found that I had to design interpolation to make the cut more stable.

![位图](https://user-images.githubusercontent.com/119190967/206565778-6ff42a61-be0e-4054-a8b7-796110f87a5b.jpg)




# Week 9
