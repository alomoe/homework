int buttonPin = 9;
int ledPin = 3;
bool light = 0;
int count = 10;
int step = 10;

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
  }

  if(val==digitalRead(buttonPin) && val==1 && light==1){     
    analogWrite(ledPin, count);
    delay(30);   
    count = count + step;
    Serial.println(count);
    if (count == 10 || count == 350) {
      step = -step ;
    }
  }
  if(val==digitalRead(buttonPin) && val==0){     
    light = !light; 
    digitalWrite(ledPin, light);   
    delay(100);  
  }
}