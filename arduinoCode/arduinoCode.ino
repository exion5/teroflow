const int switch1 = 2;
const int switch2 = 3;
const int switch3 = 4;
const int switch4 = 5;
const int ledPin = 10;
const int speakerPin = 11;  // PWM pin for speaker

const int speakerVolume = 32; // 0-255, lower = quieter

void setup() {
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(switch4, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  // Start speaker automatically
  analogWrite(speakerPin, speakerVolume);
}

void loop() {
  bool s1 = digitalRead(switch1) == LOW;
  bool s2 = digitalRead(switch2) == LOW;
  bool s3 = digitalRead(switch3) == LOW;
  bool s4 = digitalRead(switch4) == LOW;

  // If switches match password, LED on and speaker off
  if (s1 && !s2 && s3 && s4) {
    digitalWrite(ledPin, HIGH);
    analogWrite(speakerPin, 0);  // speaker off
  } else {
    digitalWrite(ledPin, LOW);
    analogWrite(speakerPin, speakerVolume); // speaker on at quieter volume
  }

  delay(100); // small delay
}