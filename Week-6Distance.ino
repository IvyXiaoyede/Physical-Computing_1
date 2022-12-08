
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
