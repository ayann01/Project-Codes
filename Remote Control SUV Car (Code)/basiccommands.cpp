// button ONOFF

const int LED = 13;

const int BUTTON = 7; // the input pin where the
// pushbutton is connected
int val = 0; // val will be used to store the state
// of the input pin
void setup() {
pinMode(LED, OUTPUT); // tell Arduino LED is an output
pinMode(BUTTON, INPUT); // and BUTTON is an input
}
void loop(){
val = digitalRead(BUTTON); // read input value and store it
// check whether the input is HIGH (button pressed)
if (val == HIGH) {
digitalWrite(LED, HIGH); // turn LED ON
} else {
digitalWrite(LED, LOW);
}
}


//KEEP LIGHT

const int LED = 13;

const int BUTTON = 7; // the input pin where the
// pushbutton is connected
int val = 0; // val will be used to store the state
// of the input pin
int state = 0; // 0 = LED off while 1 = LED on
void setup() {
pinMode(LED, OUTPUT); // tell Arduino LED is an output
pinMode(BUTTON, INPUT); // and BUTTON is an input
}
void loop() {
val = digitalRead(BUTTON); // read input value and store it
// check if the input is HIGH (button pressed)
// and change the state
if (val == HIGH) {
state = 1 - state;
}
if (state == 1) {
digitalWrite(LED, HIGH); // turn LED ON
} else {
digitalWrite(LED, LOW);
}
}




//BETTER LIGHT
const int LED = 13; // the pin for the LED
const int BUTTON = 7; // the input pin where the
// pushbutton is connected
int val = 0; // val will be used to store the state
// of the input pin
int old_val = 0; // this variable stores the previous
// value of "val"
int state = 0; // 0 = LED off and 1 = LED on
void setup() {
pinMode(LED, OUTPUT); // tell Arduino LED is an output
pinMode(BUTTON, INPUT); // and BUTTON is an input
}
void loop(){
val = digitalRead(BUTTON); // read input value and store it
// yum, fresh
// check if there was a transition
if ((val == HIGH) && (old_val == LOW)){
state = 1 - state;
}
old_val = val; // val is now old, let's store it
if (state == 1) {
digitalWrite(LED, HIGH); // turn LED ON
} else {
digitalWrite(LED, LOW);
}
}







//light fading
const int LED = 9; // the pin for the LED
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < 255; i++) { // loop from 0 to 254 (fade in)
  analogWrite(LED, i); // set the LED brightness
  delay(10); // Wait 10ms because analogWrite
  // is instantaneous and we would
  // not see any change with no delay
  }
  for (i = 255; i > 0; i--) { // loop from 255 to 1 (fade out)
  analogWrite(LED, i); // set the LED brightness
  delay(10); // Wait 10ms
  }
}









