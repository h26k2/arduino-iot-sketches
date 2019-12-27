
//keypad stuff
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

char masterPassword[] = "1234";
char inputtedPassword[5]; 
int inputCount = 0;

//Lock state
int binState = LOW;

//light and buzzer stuff (right || wrong indicator)

int lightPin = 0;
int buzzer = A1;


//second stuff
int interval = 1000;


//three button

int pin1 = A5;
int pin2  = A4;
int pin3 = A3;

void setup() {
  
  pinMode(lightPin,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);

  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
}

void loop() {

  if(inputCount < 4){

    char customKey = customKeypad.getKey();
    
    if(customKey){
      Serial.println(customKey);
      inputtedPassword[inputCount] = customKey;
      inputCount++;
    }   
    
  }
   
  if(inputCount == 4){
    
    int validityStatus = strcmp(inputtedPassword,masterPassword);

    if(validityStatus == LOW){
      Serial.println("locked open successfully");
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin3,HIGH);
    }
    else{
      Serial.println("password wrong \ntry again");
      for(int i=0 ; i<4 ; i++){
        if(i == 0 || i == 2){
          digitalWrite(lightPin,HIGH);
          digitalWrite(buzzer,HIGH);
        }
        else{
          digitalWrite(lightPin,LOW);
          digitalWrite(buzzer,LOW);
        }
        delay(1000);
      }
      
    }

    inputCount = 0;
  }

}
