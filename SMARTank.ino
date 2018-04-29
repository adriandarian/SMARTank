#include <IRremote.h>
IRsend irsend;

int xPinRight = A7;
int yPinRight = A6;
int buttonPinRight = 2;
int xPinLeft = A5;
int yPinLeft = A4;
int buttonPinLeft = 3;

int xPositionRight = 0;
int yPositionRight = 0;
int buttonStateRight = 0;
int xPositionLeft = 0;
int yPositionLeft = 0;
int buttonStateLeft = 0;



void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  
  pinMode(xPinRight, INPUT);
  pinMode(yPinRight, INPUT);
  pinMode(xPinLeft, INPUT);
  pinMode(yPinLeft, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPinRight, INPUT_PULLUP); 
  pinMode(buttonPinLeft, INPUT_PULLUP);
}

void loop() {
  xPositionRight = analogRead(xPinRight);
  yPositionRight = analogRead(yPinRight);
  buttonStateRight = digitalRead(buttonPinRight);
  xPositionLeft = analogRead(xPinLeft);
  yPositionLeft = analogRead(yPinLeft);
  buttonStateLeft = digitalRead(buttonPinLeft);
  
  Serial.print("X: ");
  Serial.print(xPositionRight);
  Serial.print(" | Y: ");
  Serial.print(yPositionRight);
  Serial.print(" | Button: ");
  Serial.println(buttonStateRight);
  Serial.print("X: ");
  Serial.print(xPositionLeft);
  Serial.print(" | Y: ");
  Serial.print(yPositionLeft);
  Serial.print(" | Button: ");
  Serial.println(buttonStateLeft);

  delay(100); // add some delay between reads
  for (int i = 0; i <50; i ++) {
  irsend.sendSony (0xa90, 5); // Sony TV power code
  delay (40);
}
}
