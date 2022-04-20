// C++ code
//
int LED_1 = 6;
int LED_2 = 5;
int LED_3 = 8;
int LED_4 = 9;
int PIN_TRIGER = 4;
int PIN_ECHO = 3;

void setup()
{
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(PIN_TRIGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  
  int distance = 0;
  
  digitalWrite(PIN_TRIGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGER, LOW);
  
  distance = pulseIn(PIN_ECHO, HIGH);
  int cm = distance/57;
  
  Serial.println(cm);
  
  if(cm < 40){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  	delay(500);
  } else if(cm >=40 && cm < 70){
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  	delay(500);
  } else if(cm >=70 && cm < 100){
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, LOW);
    delay(500);
  } else if(cm >=100 && cm < 130){
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, HIGH);
    delay(500);
  } else if(cm>=130){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    delay(500);
  }
}