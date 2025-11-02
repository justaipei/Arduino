//Button pin 
const int buttonPin =2;
//LED pin analog
const int ledPin=3;

//current led state
int ledState=LOW;
//current button state
int buttonState=0;
//Variable if the user have pressed the button or not
bool buttonPressed= false;

//Lightstick mode
int currentMode=0;

//Blinking time
int blinkTime=0;
const int slowBlink=2000;
const int mediumBlink=1000;
const int fastBlink=500;

unsigned long previousMillis=0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  checkButton();
}


void changeMode(){
  currentMode = currentMode +1;
  if (currentMode>3){
    currentMode=0;
    blinkTime=0;
    Serial.println("Mode 0 steady");
  }

  else if (currentMode==1){
    blinkTime=slowBlink;
    Serial.println("Mode 1 slow blinking");
  }

  else if (currentMode==2){
    blinkTime = mediumBlink;
    Serial.println("Mode 2 medium blinking");
  }

  else if (currentMode==3){
    blinkTime=fastBlink;
    Serial.println("Mode 2 medium blinking");
  }
}

void checkButton(){
  buttonState = digitalRead(buttonPin);

  // Button pressed
  if (buttonState == LOW && !buttonPressed){
    buttonPressed = true;
    // Serial.println("Button pressed down");
  }
  
  // Button released 
  if (buttonState == HIGH && buttonPressed){
    changeMode();
    buttonPressed = false;
  }

  int interval=blinkTime;

  unsigned long currentMillis = millis();
  if (currentMillis -previousMillis >= interval){
    previousMillis = currentMillis;
    if (ledState==HIGH){
      ledState=LOW;
    }
    else{
      ledState=HIGH;
    }
  }
  digitalWrite(ledPin, ledState);
}

 