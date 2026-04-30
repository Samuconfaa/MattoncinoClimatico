const int ledPin = 13;
const int ldrPin = A0;

int threshold = 300;
void setup() {
    pinMode(ledPin, OUTPUT);

}

void loop() 
{
    int lightValue = analogRead(ldrPin);
  
  // If light level is low turn LED on
  if (lightValue < threshold) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }


}
