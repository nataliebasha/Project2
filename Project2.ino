int buttonPin = A0; // the number of the button's pin
int redLED= 12; // the number of the red LED's pin
int greenLED= 27; // the number of the green LED's pin
boolean counter = 0; //checks to see if a new number needs to be generated
                     //boolean because it only holds two numbers: 0(true), 1(false)
int randomNum = 0; //holds the randomized number
int buttonState = 0;
int brightness = 0; 
unsigned long interval=1000; 
unsigned long prevMillis=0;

void setup() {
  Serial.begin(9600);
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) { //if the button is pressed 
     if(counter==0){
      counter=1;
      randomNum=random(2);
      if (randomNum == 0){   //if-else statement to correspond a pin number to a randomized number
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED,LOW);
        Serial.println("You did not pass, Bag Check Required!");
      }
      else if (randomNum == 1){
        digitalWrite(greenLED, HIGH); 
        digitalWrite(redLED, LOW);
        Serial.println("You Passed, Welcome!");
      }
     }
    }
  brightness= analogRead(A1); //checks to see if it is light out or not
  unsigned long currentMillis=millis();
  if((currentMillis-prevMillis)>=interval){
     if(brightness > 0){ //if the light is on then the station is open
    Serial.println("This station is open!");
    prevMillis=millis();
  }else{
    Serial.println("This station is closed!"); //if the light is not then it is closed
    prevMillis=millis();
  }
  counter=0; //resets
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  }
}
