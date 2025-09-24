
const int rLEDPin=3;
const int gLEDPin=4;
const int bLEDPin=5;


// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //red
  digitalWrite(rLEDPin, LOW);//only red
  digitalWrite(gLEDPin, HIGH);
  digitalWrite(bLEDPin, HIGH);
  delay(1000);                   // wait for a second

  //pink (red + blue)
  digitalWrite(rLEDPin, LOW);
  digitalWrite(gLEDPin, HIGH);   
  digitalWrite(bLEDPin, LOW);     
  delay(1000);

  //Blue
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(gLEDPin, HIGH);   
  digitalWrite(bLEDPin, LOW); 
  delay(1000);    


  //cyan (blue + green)
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(gLEDPin, LOW);   
  digitalWrite(bLEDPin, LOW);     
  delay(1000);

  //green
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(gLEDPin, LOW);   
  digitalWrite(bLEDPin, HIGH);      
  delay(1000);  

  //yellow (red + green)
  digitalWrite(rLEDPin, LOW);
  digitalWrite(gLEDPin, LOW);   
  digitalWrite(bLEDPin, HIGH);     
  delay(1000);   

  //turn everything off
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(gLEDPin, HIGH);   
  digitalWrite(bLEDPin, HIGH);      
  delay(1000);                      // wait for a second
}
