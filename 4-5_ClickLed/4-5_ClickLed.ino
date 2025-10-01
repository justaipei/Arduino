const int buttonPin=2;
const int rLEDPin=3;
const int gLEDPin=4;
const int bLEDPin=5;


int buttonState=0; //variable for reading the pushbutton state
int ledcolor=0;

bool ButtonPressed=false;

String currentcolor="led";

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  pinMode(buttonPin,INPUT);

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  //read the state of the pushbutton value
  buttonState=digitalRead(buttonPin);

  Serial.print("current color: ");
  Serial.println(currentcolor);
  
  //check if the pushbutton is pressed (if yes it is LOW)
  if (buttonState==LOW && !ButtonPressed){
    //turn led on
    ledcolor=ledcolor+1;
    ButtonPressed=true;
    //delay(100);
  }
  if (buttonState==HIGH && ButtonPressed){
      ButtonPressed=false;
  }
  if (ledcolor==0){
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
    currentcolor="led off";
  }
  else if (ledcolor==1){
    //red
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
    currentcolor="red";
  }
  else if (ledcolor==2){
    //green
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, HIGH);
    currentcolor="green";
  }
  else if (ledcolor==3){
    //blue
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, LOW);
    currentcolor="blue";
  }
  else if (ledcolor==4){
    //yellow
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, HIGH);
    currentcolor="yellow";
  }
  else if (ledcolor==5){
    //purple
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, LOW);
    currentcolor="purple";
  }
  else if (ledcolor==6){
    //cyan
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, LOW);
    currentcolor="cyan";
  }
  else if (ledcolor==7){
    //white
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, LOW);
    currentcolor="white";
  }
  else if (ledcolor==8){
    ledcolor=0;
  }
}
