# Physical-Computing_1

# Week 6
This week, I want to make sure which sensor I want to use, and test it. Finally, I decide to use the sound sensor and an HC-SR501. But the first time, I never think about the HC-SR501, I use the distance sensor. But the distance sensor cannot test the coming things a people, only test the something coming, so I want to change the sensor. Then I use the PIR，it was a good sensor but there has a red light always bright, it was not what I want. Finally, I decided to use an HC-SR501, it was a good sensor to test coming things in people and without any light.


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

Then I design a workflow to help me to understand the work, to help me to think more logically. And I also draw a Tinkecad to help me understand the route map， but the Tinkecad is without a sound sensor, so I only can draw the sound sensor and link it.

<img width="493" alt="截屏2022-12-08 下午3 55 59" src="https://user-images.githubusercontent.com/119190967/206497530-e27cd08b-89e2-4022-b6f1-512a275ebb33.png">

<img width="620" alt="截屏2022-12-08 下午3 56 13" src="https://user-images.githubusercontent.com/119190967/206497776-b6f83741-6a48-4d54-bd4e-ff8e8c1c8ba1.png">

# Week 7

This week I want to link sensors and test the connection with every sensor. At first, I try to link the LED strip and the sound sensor. But I meet a problem in that I did not know how to control the colour of the lights, they only show colourful light and I cannot use the code to control it. So I found the other LED strip, and I found the code only can use for the LED_TYPE WS2812, and the LED Strip type is different to use it, it can use under the water. Then I borrow the other LED strip and add the other code about how to control and turn off the LED strip.

Then, I want to link sensors, I link the LED strip and the Sound sensor first, and test it. Here is a LED test code:

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

Secondly, I use the fans and sound sensor, in order to link the sound sensor with the fans I found a question the fans a direct current never have the motors to change it, I test for a long time and I found the ULN2003 driver is a good motor to help sound sensor and fans linking.

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
This week, I think the most important thing is to do the house to decorate it. And I need to solder the wiring with a tool because, in the end, we don't use the breadboard to control it. I spent two days to finish it, actually, I only can use it for one day, but something was wrong and some lines were broken. So I need to relink at next day.

Finish to linking the circuits， I must test it to make sure it can be successfully used it. And I found many questions about the link, so I must do it again, it was a piece of sad news. After doing this work twice later, I successfully linked it, and it can be used.

![WechatIMG58](https://user-images.githubusercontent.com/119190967/206564820-729b3353-b20f-4eb2-8307-6276e86d410d.jpeg)

Add I want to use the Acrylic board to make a house. So I draw a picture which can be used in the laser cutter machine. And I use the cut board to cut it at first and use it for testing. I found a problem that I never combine successfully. I asked other students how to solve the problem and eventually, I found that I had to design interpolation to make the cut more stable.

![位图](https://user-images.githubusercontent.com/119190967/206565778-6ff42a61-be0e-4054-a8b7-796110f87a5b.jpg)


# Week 9
This was the last week，I decide to make a slides and take a video. I had finished laser cutting last week so I had an easier task this week and just had to go and assemble it, but I had a hard time controlling my set up when assembling it and when replacing materials found that the materials were not as I wanted them to be, so I changed the way I expressed it to a different method. I used laser paper as a cover for the film fabric, with small balls inside that bounced in response to the fan, thus achieving the concept of a restless sound.

![IMG_0794 2](https://user-images.githubusercontent.com/119190967/206574152-f756872e-ff19-44c1-8112-9ddf8523c61f.PNG)

After doing the assembly of the installation, I then needed to start making my slides page, and then found that because of my personal habits I just didn't leave a lot of marks, such as photos etc., so it was a pain to make the slides and make sure to leave some marks afterwards so that I could correct myself etc.

Here is a video link:

https://youtu.be/drEBErppDFc



