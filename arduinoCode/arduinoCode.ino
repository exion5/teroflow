const int switch1 = 2;
const int switch2 = 3;
const int switch3 = 4;
const int switch4 = 5;
const int ledPin = 10;
const int speakerPin = 11;

const int speakerVolume = 128;

bool pythonOverride = false;
bool speakerActive = false;

void setup() {
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(switch4, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  analogWrite(speakerPin, 0);
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
  Serial.println("Arduino ready");
}

void loop() {
  // Read switches
  bool s1 = digitalRead(switch1) == LOW;
  bool s2 = digitalRead(switch2) == LOW;
  bool s3 = digitalRead(switch3) == LOW;
  bool s4 = digitalRead(switch4) == LOW;

  // Check switch password
  bool passwordCorrect = s1 && !s2 && s3 && s4;

  if (passwordCorrect) {
    // Switch password overrides Python
    digitalWrite(ledPin, HIGH);
    analogWrite(speakerPin, 0);
    pythonOverride = false;  // ignore Python while password active
  } else {
    // Only read Python commands if password NOT active
    if (Serial.available() > 0) {
      char cmd = Serial.read();
      if (cmd == '1') {
        speakerActive = true;
      } else if (cmd == '0') {
        speakerActive = false;
      }
      pythonOverride = true;
      Serial.print("Python command received: ");
      Serial.println(cmd);
    }

    // Apply Python control if override is active
    if (pythonOverride) {
      analogWrite(speakerPin, speakerActive ? speakerVolume : 0);
      digitalWrite(ledPin, speakerActive ? HIGH : LOW);
    } else {
      // default state when no Python and password inactive
      analogWrite(speakerPin, 0);
      digitalWrite(ledPin, LOW);
    }
  }

  delay(100);
}