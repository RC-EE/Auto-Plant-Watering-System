#include <Servo.h>

Servo servo;

const unsigned long eventInterval = 86400000; //24 hour timer
unsigned long previousTime = 0;
int pos = 0;    

void setup() {
  Serial.begin(9600);
  servo.attach(A5); 
}

void loop() {

  unsigned long currentTime = millis();
  if (currentTime - previousTime >= eventInterval) {
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
  }

  previousTime = currentTime;
  }
}
