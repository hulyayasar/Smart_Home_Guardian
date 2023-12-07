/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

// int led = 9;         // the PWM pin the LED is attached to
// int brightness = 0;  // how bright the LED is
// int fadeAmount = 5;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  Serial.begin(9600);

  pinMode(A1, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(6,LOW);


}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  // tone(6, 85); 
  // delay(1000);
  // noTone(6);
  // delay(1000);

  if (sensorValue >=150)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);


  }
  else 
  {
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
  }
 

  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
