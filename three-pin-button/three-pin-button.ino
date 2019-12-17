
/*
 * Three Pin Push Button
 * pin S is for sense
 * pin - is for ground
 * the remaing pin needs +5V to work
 */

int sensePin = 12;
int lightPin = 13;

void setup() {
  // put your setup code here, to run once:

  pinMode(sensePin,INPUT);
  pinMode(lightPin,OUTPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(sensePin) == HIGH){
    digitalWrite(lightPin,LOW);
  }
  else{
    digitalWrite(lightPin,HIGH);
  }
  
}
