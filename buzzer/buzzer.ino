int speakerPin = 38;
void setup () {
  pinMode (speakerPin, OUTPUT);
}
void loop () {
  analogWrite (speakerPin, 20);
  delay (50);
  analogWrite (speakerPin, -1);
  delay (1000);
  Serial.println("bad");
}
