#include <SoftwareSerial.h>

//L298n Motor Driver pins.
#define in1 2 
#define in2 3
#define in3 4
#define in4 5

#define rxPin 0
#define txPin 1

// set up a new serial port
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

void setup() {
    // put your setup code here, to run once:
    // define pin modes for tx, rx:
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);

    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    
    // set the data rate for the SoftwareSerial port
    mySerial.begin(9600);
    Serial.begin(9600);
}

void loop() {
    char c = 0;
    // put your main code here, to run repeatedly:
    if (mySerial.available()>0){
        c = mySerial.read();
        switch (c) {
            case 'f':
              Serial.println("Start");
              digitalWrite(in1, HIGH);
              digitalWrite(in2, LOW);
              digitalWrite(in3, HIGH);
              digitalWrite(in4, LOW);
              break;
            case 'b':
              Serial.println("Back");
              digitalWrite(in1, LOW);
              digitalWrite(in2, HIGH);
              digitalWrite(in3, LOW);
              digitalWrite(in4, HIGH);
              break;
            case 'r':
              Serial.println("Right");
              digitalWrite(in1, HIGH);
              digitalWrite(in2, LOW);
              digitalWrite(in3, LOW);
              digitalWrite(in4, HIGH);
              break;
            case 'l':
              Serial.println("Left");
              digitalWrite(in1, LOW);
              digitalWrite(in2, HIGH);
              digitalWrite(in3, HIGH);
              digitalWrite(in4, LOW);
              break;
            case '5':
              Serial.println("Stop");
              digitalWrite(in1, LOW);
              digitalWrite(in2, LOW);
              digitalWrite(in3, LOW);
              digitalWrite(in4, LOW);
              break;
            default:
              Serial.println("Stop");
              digitalWrite(in1, LOW);
              digitalWrite(in2, LOW);
              digitalWrite(in3, LOW);
              digitalWrite(in4, LOW);
              break;
              }
    }
}
