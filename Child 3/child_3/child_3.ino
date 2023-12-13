#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(7, 8);                  // CE, CSN
const byte address[6] = "00002";   // transmit  address
const byte address2[6] = "00001";  // receive trnasmit

int incoming_request;
int led_state = 0;
void setup() {

  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.openWritingPipe(address2);
  radio.setPALevel(RF24_PA_MIN);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, OUTPUT);  //green
  pinMode(A4, OUTPUT);  //red


  // lcd.setBacklight(LOW);
}

int ledLight(int state) {
  if (state == 1) {
    analogWrite(A3, 0);
    analogWrite(A4, 250);

  } else {
    analogWrite(A3, 200);
    analogWrite(A4, 0);
  }
  return 0;
}
void loop() {
  led_state = 0;
  int gasRead = analogRead(A0);
  int alcohol = analogRead(A1);
  Serial.println(gasRead);
  Serial.println(alcohol);
  int room_reply_arr = 30000;

  // Serial.println(gasRead);
  // Serial.println(alcohol);

  if (gasRead >= 170) {
    room_reply_arr = room_reply_arr + 1000;
    led_state = 1;
  }

  if (alcohol >= 60) {
    room_reply_arr = room_reply_arr + 100;
    led_state = 1;
  }

  //ledLight(led_state);
  //Serial.println(room_reply_arr);
  radio.startListening();
  radio.read(&incoming_request, sizeof(incoming_request));

  if (incoming_request == 3) {
    //Serial.println(incoming_request);


    radio.stopListening();

    for (int i = 0; i <= 50; i++) {
      radio.write(&room_reply_arr, sizeof(room_reply_arr));
      ledLight(led_state);
    }
  }


  led_state = 0;
}
