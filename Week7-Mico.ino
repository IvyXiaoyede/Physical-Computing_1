//const int SoundInput=A0;
void setup() {
  // put your setup code here, to run once:
 
 pinMode(12,OUTPUT);
 Serial.begin(9600);
 
}

void loop() {
  int value =analogRead(A1);
  Serial.println(value);
  // put your main code here, to run repeatedly:
 if (value<=200) {
    digitalWrite(12, LOW);
    
  }
  else {
    digitalWrite(12, HIGH);
    delay(200);

  }
}
