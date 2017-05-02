
//set pin numbers for the outputs for motor
const int leftRev = 28;
const int leftFor = 30;
const int rightRev = 26;
const int rightFor = 32;
const int motorControlPinR = 5;
const int motorControlPinL = 4;
// pins for ultrasonic sensor
const int trigPinF = 24;
const int echoPinF = 2;
const int trigPinR = 34;
const int echoPinR = 6;
const int trigPinL = 36;
const int echoPinL = 7;

long duration;
int distance;

//variable to keep track of current speed detting
int motorSpeed = 0;

//buzzer
int const speakerPin = 38;
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
  pinMode(trigPinF, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinF, INPUT); // Sets the echoPin as an Input
  pinMode(trigPinR, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinR, INPUT); // Sets the echoPin as an Input
  pinMode(trigPinL, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinL, INPUT); // Sets the echoPin as an Input
  pinMode (speakerPin, OUTPUT);//Sets up the buzzer
  Serial.begin(9600); // Starts the serial communication


  //  Serial.println("forward");
  //  //  move forward
  //  setLeftForward();
  //  setRightForward();
  //  slowStartMotors(100);
  //  delay(1500);
  //  slowStopMotors();
  //
  //
  //
  //  delay(1000);
  //
  //  Serial.println("spin");
  //  //spin in place
  //  setLeftForward();
  //  setRightReverse();
  //  slowStartMotors(75);
  //  delay(3000);
  //  slowStopMotors();
}

void loop() {

  //  Clears the trigPin
  digitalWrite(trigPinF, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinF, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinF, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPinF, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 30)
  {
//    Serial.println("backward");
//    analogWrite (speakerPin, 10);
//    delay (50);
//    analogWrite (speakerPin, -1);

    //move backwards
    setLeftReverse();
    setRightReverse();
    slowStartMotors(100);
    slowStopMotors();


  }
  else {
    Serial.println("you are good");
    Serial.println("forward");
    //  move forward
    setLeftForward();
    setRightForward();
    slowStartMotors(100);
    slowStopMotors();

  }

  delay(1000);
}

void slowStartMotors(int speed) {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= speed; fadeValue += 3) {
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

