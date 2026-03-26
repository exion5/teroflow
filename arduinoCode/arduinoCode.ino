const int switch1 = 2;
const int switch2 = 3;
const int switch3 = 4;
const int switch4 = 5;
const int ledPin = 10;
const int speakerPin = 11;

const int speakerVolume = 128; // medium volume for testing

bool pythonOverride = false;
bool speakerActive = false;

void setup() {
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(switch4, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  analogWrite(speakerPin, 0); // speaker OFF by default
  digitalWrite(ledPin, LOW);  // LED OFF by default

  Serial.begin(9600);
  Serial.println("Arduino ready");
}

void loop() {
  // --- Check for Python commands ---
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    pythonOverride = true;
    if (cmd == '1') speakerActive = true;
    if (cmd == '0') speakerActive = false;

    Serial.print("Python command received: ");
    Serial.println(cmd);
  }

  // --- Act according to override or switches ---
  if (pythonOverride) {
    analogWrite(speakerPin, speakerActive ? speakerVolume : 0);
    digitalWrite(ledPin, speakerActive ? HIGH : LOW);
  } else {
    bool s1 = digitalRead(switch1) == LOW;
    bool s2 = digitalRead(switch2) == LOW;
    bool s3 = digitalRead(switch3) == LOW;
    bool s4 = digitalRead(switch4) == LOW;

    // Password logic: s1 HIGH, s2 LOW, s3 HIGH, s4 HIGH
    if (s1 && !s2 && s3 && s4) {
      digitalWrite(ledPin, HIGH);
      analogWrite(speakerPin, 0); // Speaker OFF
      Serial.println("Switch password correct → LED ON, Speaker OFF");
    } else {
      digitalWrite(ledPin, LOW);
      analogWrite(speakerPin, speakerVolume); // Speaker ON
      Serial.println("Switch password incorrect → LED OFF, Speaker ON");
    }
  }

  delay(100); // small delay
}