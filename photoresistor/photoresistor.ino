
int sensePin = A0;
int relayPin = 13;
int state = LOW;

void setup() {

  pinMode(sensePin , INPUT);
  pinMode(relayPin , OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int level = analogRead(sensePin);
  Serial.println(level);
  if(level >= 500 && state == LOW){
    Serial.println("TURNING LIGHTS ON");
    state = HIGH;
    digitalWrite(relayPin , state);
  }
  else if(level < 500 && state == HIGH){
    Serial.println("TURNING LIGHTS OFF");
    state = LOW;
    digitalWrite(relayPin , state);
  }

}
