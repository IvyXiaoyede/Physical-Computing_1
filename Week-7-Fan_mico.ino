
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
