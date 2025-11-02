//Button pin 
const int buttonPin =2;
//LED pin analog
const int rLEDPin=9;
const int gLEDPin=10;
const int bLEDPin=11;

//current button state
int buttonState=0;
//Variable if the user have pressed the button or not
bool buttonPressed= false;
//timer for pressing time
unsigned long pressingTime=0;
//threshold long press interval
const int longPressInterval=2000;

//Lightstick mode
int currentMode=0;
unsigned long blinkTimer=0;
const int blinkInterval=500;
bool blinkOn=true;

//Current light stick number (0:white, 1:red, 2:blue, 3:green, 4:yellow...)
int lightNum=0;
//current light stick xolor
int rLightColor=0;
int gLightColor=0;
int bLightColor=0;
int rCurrentColor=0;
int gCurrentColor=0;
int bCurrentColor=0;

//variables for fading mode
const int fadeAmount = 2;//fading amount per time step
int fadeDirection=1;



void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  checkButton();
  updateLEDColor();
  setRGBColor( rCurrentColor,  gCurrentColor, bCurrentColor); 
}


void changeMode(){
  currentMode = currentMode +1;
  if (currentMode>=3){
    currentMode=0;
    Serial.println("Mode 0");
  }
  //reset variables for blinking effects
  if (currentMode==1){
    blinkTimer=0;
    blinkOn=true;
    Serial.println("Mode 1 blinking");
  }

  //reset variable for fading effects
  if (currentMode==2){
    fadeDirection=1;
    Serial.println("Mode 2 fading");
  }
}

void checkButton(){
  int buttonState = digitalRead(buttonPin);

  // Button pressed
  if (buttonState == LOW && !buttonPressed){
    pressingTime = millis();
    buttonPressed = true;
    Serial.println("Button pressed down");
  }
  
  // Button released 
  if (buttonState == HIGH && buttonPressed){
    unsigned long currentTime = millis();
    unsigned long pressDuration = currentTime - pressingTime;
    Serial.print("Button released after: ");
    Serial.println(pressDuration);
    
    if (pressDuration >= longPressInterval){
      // Long press - change mode
      changeMode();
      Serial.println("LONG PRESS - Mode changed");
    }
    else{
      // Short press - change color
      changeLEDColor();
      Serial.println("SHORT PRESS - Color changed");
    }
    buttonPressed = false;
  }
}

void updateLEDColor(){
  if(currentMode==0){
    //constant light mode
    rCurrentColor=rLightColor;
    gCurrentColor=gLightColor;
    bCurrentColor=bLightColor;
  }
  else if (currentMode==1){
    //blink mode
    unsigned long currentTime=millis();
    if (currentTime-blinkTimer > blinkInterval){
      blinkOn= !blinkOn;
      blinkTimer=currentTime;
    }
    if(blinkOn){
      rCurrentColor=rLightColor;
      gCurrentColor=gLightColor;
      bCurrentColor=bLightColor;
    }
    else{
      rCurrentColor=255;
      gCurrentColor=255;
      bCurrentColor=255;
    }
  }
  else if(currentMode==2){
    bool negativeDir=false;
    //breathing light
    //if the light value is 0, we need to modify it progress; otherwise, just make it 255
    if (rLightColor==0){
      rCurrentColor+=fadeDirection*fadeAmount;
      if (rCurrentColor > (255-rLightColor)||(rCurrentColor<0)){
        negativeDir = true;
      }

      //make sure the color is within range (0-255)
      if (rCurrentColor<0) rCurrentColor=0;
      if (rCurrentColor>255) rCurrentColor=255;
    }

    if (gLightColor==0){
      gCurrentColor+=fadeDirection*fadeAmount;
      if (gCurrentColor > (255-gLightColor)||(gCurrentColor<0)){
        negativeDir = true;
      }

      //make sure the color is within range (0-255)
      if (gCurrentColor<0) gCurrentColor=0;
      if (gCurrentColor>255) gCurrentColor=255;
    }

    if (bLightColor==0){
      bCurrentColor+=fadeDirection*fadeAmount;
      if (bCurrentColor > (255-bLightColor)||(bCurrentColor<0)){
        negativeDir = true;
      }

      //make sure the color is within range (0-255)
      if (bCurrentColor<0) bCurrentColor=0;
      if (bCurrentColor>255) bCurrentColor=255;
    }

    if (negativeDir){
      fadeDirection=-fadeDirection;
    }
    delay(10);
  }
  
}

void changeLEDColor(){
  //increase light number
  lightNum = lightNum +1;
  if(lightNum>=5){
    lightNum=0;
  }

  //set RGB light color
  if (lightNum==0){
    //white
    rLightColor=0;
    gLightColor=0;
    bLightColor=0;
    //Serial.println("white : ");
  }
  if(lightNum==1){
    //red
    rLightColor=0;
    gLightColor=255;
    bLightColor=255;
    //Serial.print("red : ");
  }
  if(lightNum==2){
    //green
    rLightColor=255;
    gLightColor=0;
    bLightColor=255;
    //Serial.print("green : ");
  }
  if(lightNum==3){
    //blue
    rLightColor=255;
    gLightColor=255;
    bLightColor=0;
    //Serial.print("blue : ");
  }
  if(lightNum==4){
    //yellow
    rLightColor=0;
    gLightColor=0;
    bLightColor=255;
    //Serial.print("yellow : ");
  }
  rCurrentColor=rLightColor;
  gCurrentColor=gLightColor;
  bCurrentColor=bLightColor;
}

void setRGBColor(int rColor, int gColor, int bColor) {
  analogWrite(rLEDPin, rColor);
  analogWrite(gLEDPin, gColor);
  analogWrite(bLEDPin, bColor);
  // Serial.print("Color: ");
  // Serial.print(rCurrentColor);
  // Serial.print(gCurrentColor);
  // Serial.println(bCurrentColor);
}
