
int sensePin = 13;
int lightPinSeq = 0;

int btnPreviousState = LOW;
int btnCurrentState;

void setup() {
  
  for(int i=0 ; i<5 ; i++){
    pinMode(i,OUTPUT);
  }

  pinMode(sensePin,INPUT);
  Serial.begin(9600);
}

void loop() {

  btnCurrentState = digitalRead(sensePin);
  
  if(btnPreviousState == LOW && btnCurrentState == HIGH){

    for(int i=0 ; i<5 ; i++){

      if(i == lightPinSeq){
        digitalWrite(i,HIGH);  
      }
      else{
        digitalWrite(i,LOW);
      }
      
    }

    if(lightPinSeq == 4){
      lightPinSeq = 0;
    }
    else{
      lightPinSeq++;
    }

    
  }

  btnPreviousState = btnCurrentState;

  delay(100);
}
