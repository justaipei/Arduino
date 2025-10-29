const int buttonPin=2;
const int rLedPin=3;
const int gLedPin=4;
const int bLedPin=5;


int buttonState=0; //variable for reading the pushbutton state
bool ButtonPressed = false; //has the button been pressed or not

unsigned long touchedTimer=0; //record of last touch time
unsigned long reducedTimer=0; //record of last reduced point time
const long unTouchedInterval = 5000; //interval for decreaseof mood
const long reducedInterval=1000;

int mood=0; //toy's mood state
const int neutralMood = 10; //neutral mood start

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);//Baund rate setting
  mood = neutralMood;
}

void loop() {

  Serial.println(mood);
  //Serial.print(buttonState);

  showLEDState(mood);

  //check if the button is pressed or not
  buttonState = digitalRead(buttonPin);
  Serial.println(mood);
  //if the button is clicked
  if (buttonState == HIGH && !ButtonPressed){
    mood=mood+1;
    if(mood>20) mood=20;
    touchedTimer=millis();
    ButtonPressed=true;
  }
  
  if (buttonState == LOW && ButtonPressed){
    ButtonPressed=false;
  }


  unsigned long currentTimer = millis();
  if (currentTimer - touchedTimer > unTouchedInterval){

    if (currentTimer - reducedTimer > reducedInterval){
      mood = mood -1;
      if (mood<0) mood=0;
      reducedTimer=currentTimer;
    }
  }

}

void showLEDState(int state){

  float brightnessInterval = 255/10.0;

  if (state>= neutralMood){
    analogWrite(rLedPin, 255-brightnessInterval * (state-neutralMood));
    analogWrite(gLedPin, brightnessInterval * (state-neutralMood));
    analogWrite(bLedPin, 255);
  }
  
  else{
    analogWrite(rLedPin,255);
    analogWrite(gLedPin,brightnessInterval * (neutralMood-state) );
    analogWrite(bLedPin,255- brightnessInterval * (neutralMood-state));
  }
}
