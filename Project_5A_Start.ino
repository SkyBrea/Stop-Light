// By: Skyler 
// Project #5: Controlling Traffic

#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10

#define yellowBlinkTime 500

boolean trafficWest = true; // west = true, east = false
int flowTime = 10000;
int changeDelay = 2000;

void setup() {
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);

  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}

void loop() {
  if (digitalRead(westButton) == HIGH && trafficWest == false) {
    switchToWest();
  }
  
  if (digitalRead(eastButton) == HIGH && trafficWest == true) {
    switchToEast();
  }
}

// Function to switch traffic flow to WEST
void switchToWest() {
  trafficWest = true;
  delay(flowTime);
  
  digitalWrite(eastGreen, LOW);
  digitalWrite(eastYellow, HIGH);
  delay(changeDelay);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastRed, HIGH);
  delay(changeDelay);
  
  blinkYellow(westYellow);
  
  digitalWrite(westYellow, LOW);
  digitalWrite(westRed, LOW);
  digitalWrite(westGreen, HIGH);
}

// Function to switch traffic flow to EAST
void switchToEast() {
  trafficWest = false;
  delay(flowTime);
  
  digitalWrite(westGreen, LOW);
  digitalWrite(westYellow, HIGH);
  delay(changeDelay);
  digitalWrite(westYellow, LOW);
  digitalWrite(westRed, HIGH);
  delay(changeDelay);
  
  blinkYellow(eastYellow);
  
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastRed, LOW);
  digitalWrite(eastGreen, HIGH);
}

// Function to blink yellow light 5 times
void blinkYellow(int pin) {
  for (int i = 0; i < 5; i++) {
    digitalWrite(pin, LOW);
    delay(yellowBlinkTime);
    digitalWrite(pin, HIGH);
    delay(yellowBlinkTime);
  }
}
