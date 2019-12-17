
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
  
}

void loop() {

  btnCurrentState = digitalRead(sensePin);
  
  //This condition ensure that the button is pressed up 
  if(btnPreviousState == LOW && btnCurrentState == HIGH){

    //Now toggling the led state (on || off)

    if(lightState == LOW){
      lightState = HIGH;
    }
    else{
      lightState = LOW;
    }
    
  }

  digitalWrite(lightPin,lightState);
  btnPreviousState = btnCurrentState;
  
}
