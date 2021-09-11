const int potPin = A0;
const int ledPin = 11;
int potValue = 0;
int ledValue;

void setup() {
    pinMode(potPin, INPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (analogRead(potPin) != potValue) {

        Serial.println("Value changed");
        delay(500);

        potValue = analogRead(potPin);
        ledValue = map(potValue, 0, 1023, 0, 255);
        Serial.println(potValue);
        Serial.println(ledValue);
        Serial.println("");
        analogWrite(ledPin, ledValue);
        Serial.print("LED Value = ");
        Serial.println(ledValue);
        Serial.println("");
    }
}