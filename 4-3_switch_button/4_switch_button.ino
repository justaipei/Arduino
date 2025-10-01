const int buttonPin=2;
const int rLEDPin=3;
const int gLEDPin=4;
const int bLEDPin=5;


int buttonState=0; //variable for reading the pushbutton state
int ledcolor=0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  pinMode(buttonPin,INPUT);
}

// the loop function runs over and over again forever
void loop() {
  //read the state of the pushbutton value
  buttonState=digitalRead(buttonPin);

  //check if the pushbutton is pressed (if yes it is LOW)
  if (buttonState==LOW){
    //turn led on
    ledcolor=ledcolor+1;
    delay(100);
  }
  if (ledcolor==0){
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
  }
  else if (ledcolor==1){
    //red
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
  }
  else if (ledcolor==2){
    //green
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, HIGH);
  }
  else if (ledcolor==3){
    //blue
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, LOW);
  }
  else if (ledcolor==4){
    //pink
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, HIGH);
  }
  else if (ledcolor==5){
    //purple
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, LOW);
  }
  else if (ledcolor==6){
    //green
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, LOW);
  }
  else if (ledcolor==7){
    //green
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, LOW);
  }
  else if (ledcolor==8){
    ledcolor=0;
  }
}
