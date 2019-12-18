
/***************************************************
 * Using 3-pin push button to function like toggle
 * on or off
 ***************************************************/

int lightPin = 13;
int sensePin = 12;

int lightState = HIGH;
int btnCurrentState;
int btnPreviousState = LOW;

void setup() {

  pinMode(lightPin , OUTPUT);
  pinMode(sensePin, INPUT);
  Serial.begin(9600);
  
}

void loop() {

  btnCurrentState = digitalRead(sensePin);
  Serial.println(btnCurrentState);
  
}
