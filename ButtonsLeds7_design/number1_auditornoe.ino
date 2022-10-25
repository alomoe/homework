int buttonPin = 9;
int ledPin = 3;
bool light = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  bool val = digitalRead(buttonPin);
  Serial.println(val);
  Serial.println(digitalRead(buttonPin));
  if (val!=digitalRead(buttonPin) && val==1){
    light = !light; 
    digitalWrite(ledPin, light);   
    delay(100);   
  }
  else{
    digitalWrite(ledPin, light);
    delay(100);  
  }
}
