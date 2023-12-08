#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(7, 8);                  // CE, CSN
const byte address[6] = "00002";   // transmit  address
const byte address2[6] = "00001";  // receive trnasmit

int incoming_request;

void setup() {

  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.openWritingPipe(address2);
  radio.setPALevel(RF24_PA_MIN);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  // lcd.setBacklight(LOW);
}

void loop() {
  int gasRead = analogRead(A0);
  int alcohol = analogRead(A1);
  int room_reply_arr = 10000;
  Serial.println(gasRead);
  Serial.println(alcohol);

  if (gasRead >= 160) {
    room_reply_arr = room_reply_arr + 1000;
  }

  if (alcohol >= 20) {
    room_reply_arr = room_reply_arr + 100;
  }



  radio.startListening();
  radio.read(&incoming_request, sizeof(incoming_request));

  if (incoming_request == 1) {
    Serial.println(incoming_request);

    // room_reply_arr[0] = 1; // room_no
    // room_reply_arr[2] = 0; // gas
    // room_reply_arr[3] = 0; // alcohol
    // room_reply_arr[4] = 0; // temp
    // room_reply_arr[5] = 0; // humidity

    radio.stopListening();

    for (int i = 0; i <= 50; i++) {
      radio.write(&room_reply_arr, sizeof(room_reply_arr));
    }
  }
}
