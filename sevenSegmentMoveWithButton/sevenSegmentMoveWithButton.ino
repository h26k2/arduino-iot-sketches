
int sensePin = 13;
int numToDisplay = 0;

int btnPreviousState = LOW;
int btnCurrentState;

int segA = 0;
int segB = 1;
int segC = 2;
int segD = 3;
int segE = 4;
int segF = 5;
int segG = 6;
int segCommon = 7;

void setup() {

  for(int i= segA ; i<= segCommon; i++){
    pinMode(i,OUTPUT);
  }

  pinMode(sensePin , INPUT);
  
}

void loop() {

  btnCurrentState = digitalRead(sensePin);
  digitalWrite(segCommon, HIGH);

  if(btnPreviousState == LOW && btnCurrentState == HIGH){

    if(numToDisplay == 0){
      
      for(int i=segA ; i<=segG ; i++){
        if(i != segG){
          digitalWrite(i,LOW);
        }
        else{
          digitalWrite(i,HIGH);
        }
      }
      
    }
    else if(numToDisplay == 1){

      for(int i=segA ; i<=segG ; i++){
        if(i != segB || i != segC){
          digitalWrite(i,HIGH);
        }
        else{
          digitalWrite(i,LOW);
        }
      }
      
      
    }
    else if(numToDisplay == 2){

      for(int i=segA ; i<=segG ; i++){
        if(i != segD || i != segF){
          digitalWrite(i,LOW);
        }
        else{
          digitalWrite(i,HIGH);
        }
      }
      
      
    }
    else if(numToDisplay == 3){

      for(int i=segA ; i<=segG ; i++){
        if(i != segE || i != segF){
          digitalWrite(i,LOW);
        }
        else{
          digitalWrite(i,HIGH);
        }
      }
      
      
    }
    else if(numToDisplay == 4){

      for(int i=segA ; i<=segG ; i++){
        if(i != segA || i != segD || i != segE){
          digitalWrite(i,LOW);
        }
        else{
          digitalWrite(i,HIGH);
        }
      }
      
      
    }
    else if(numToDisplay == 5){
      
      for(int i=segA ; i<=segG ; i++){
        if(i != segB || i != segE){
          digitalWrite(i,LOW);
        }
        else{
          digitalWrite(i,HIGH);
        }
      }
      
    }
    else if(numToDisplay == 6){

      for(int i=segA ; i<=segG ; i++){
        if(i != segB){
          digitalWrite(i,LOW);
        }
        else{
          digitalWrite(i,HIGH);
        }
      }
      
      
    }
    else if(numToDisplay == 7){

      for(int i=segA ; i<=segG ; i++){
        if(i != segD || i != segE || i != segF ){
          digitalWrite(i,LOW);
        }
        else{
          digitalWrite(i,HIGH);
        }
      }
      
      
    }
    else if(numToDisplay == 8){

      for(int i=segA ; i<=segG ; i++){
        digitalWrite(i,LOW);
      }
      
      
    }
    else if(numToDisplay == 9){

      for(int i=segA ; i<=segG ; i++){
        if( i != segE ){
          digitalWrite(i,LOW);
        }
        else{
          digitalWrite(i,HIGH);
        }
      }
        
         
    }

    if(numToDisplay != 9){
      numToDisplay++;
    }
    else{
      numToDisplay = 0;
    }
    
  }

  btnPreviousState = btnCurrentState;
  
}
