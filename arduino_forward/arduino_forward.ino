
//set pin numbers for the outputs
const int leftRev = 28;
const int leftFor = 30;
const int rightRev = 26;
const int rightFor = 32;
const int motorControlPinR = 5;
const int motorControlPinL = 4;
const int trigPin = 2;
const int echoPin = 22;
long duration;
int distance;
//variable to keep track of current speed detting
int motorSpeed = 0;
/**
   function prototypes
*/
void slowStartMotors(int speed); //speed sets maximum pwm speed - speed <= 255
void slowStopMotors();
void setLeftForward(void);
void setRightForward(void);
void setLeftReverse(void);
void setRightReverse(void);

void setup() {
  pinMode(leftFor, OUTPUT);
  pinMode(leftRev, OUTPUT);
  pinMode(rightFor, OUTPUT);
  pinMode(rightRev, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

Serial.println("forward");
  //  move forward
  setLeftForward();
  setRightForward();
  slowStartMotors(100);
  delay(1500);
  slowStopMotors();

  delay(1000);
Serial.println("backward");
  //move backwards
  setLeftReverse();
  setRightReverse();
  slowStartMotors(100);
  delay(800);
  slowStopMotors();

  delay(1000);

Serial.println("spin");
  //spin in place
  setLeftForward();
  setRightReverse();
  slowStartMotors(75);
  delay(3000);
  slowStopMotors();
}

void loop() {
  //  //things that repeat go here
  //  digitalWrite(trigPin, LOW);
  //  delayMicroseconds(2);
  //  // Sets the trigPin on HIGH state for 10 micro seconds
  //  digitalWrite(trigPin, HIGH);
  //  delayMicroseconds(10);
  //  digitalWrite(trigPin, LOW);
  //  // Reads the echoPin, returns the sound wave travel time in microseconds
  //  duration = pulseIn(echoPin, HIGH);
  //  // Calculating the distance
  //  distance = duration * 0.034 / 2;
  //  // Prints the distance on the Serial Monitor
  //  Serial.print("Distance: ");
  //  Serial.println(distance);
  //  //move forward
  //  setLeftForward();
  //  setRightForward();
  //  slowStartMotors(100);
  //  delay(1500);
  //  slowStopMotors();
  //
  //  delay(1000);
  // Clears the trigPin
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  // Sets the trigPin on HIGH state for 10 micro seconds
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  // Reads the echoPin, returns the sound wave travel time in microseconds
//  duration = pulseIn(echoPin, HIGH);
//  // Calculating the distance
//  distance = duration * 0.034 / 2;
//  // Prints the distance on the Serial Monitor
//  if (distance < 20)
//  { Serial.println("you are to close");
//    Serial.print("Distance: ");
////    Serial.println(distance);
//  }
//  else {
//    Serial.println("you are good");
//    Serial.print("Distance: ");
//    Serial.println(distance);
//  }
//
//  delay(5000);
}

void slowStartMotors(int speed) {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= speed; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(motorControlPinL, fadeValue);
    analogWrite(motorControlPinR, fadeValue + 1);
    motorSpeed = fadeValue;
    // wait for 5 milliseconds to for each of the 51 steps
    delay(40);
  }
}

void slowStopMotors() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = motorSpeed ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    if (fadeValue < 0) {
      fadeValue = 0;
    }
    analogWrite(motorControlPinL, fadeValue);
    analogWrite(motorControlPinR, fadeValue);
    // wait for 5 milliseconds to for each of the 51 steps
    delay(50);
  }
}

void setLeftForward() {
  digitalWrite(leftFor, HIGH);
  digitalWrite(leftRev, LOW);
}

void setRightForward() {
  digitalWrite(rightFor, HIGH);
  digitalWrite(rightRev, LOW);
}

void setLeftReverse() {
  digitalWrite(leftFor, LOW);
  digitalWrite(leftRev, HIGH);
}

void setRightReverse() {
  digitalWrite(rightFor, LOW);
  digitalWrite(rightRev, HIGH);
}

