#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(7, 8);                    // CE, CSN
const byte address[6] = "00001"; // transmit  address
const byte address2[6] = "00002"; // receive trnasmit 



int room_status(int room_no)
{
  int room_reply_arr[6];

  radio.stopListening();
  radio.write(&room_no, sizeof(room_no));
  radio.startListening();
  radio.read(&room_reply_arr, sizeof(room_reply_arr));

  return room_reply_arr;

}

void setup() {

  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.openWritingPipe(address2);
  radio.setPALevel(RF24_PA_MIN);

  delay(2000);

  // lcd.setBacklight(LOW);
}

void loop() {

  int room_no = room_status[0];
  int pir = room_status[1];
  int gas = room_status[2];
  int alcohol = room_status[3];
  int temp = room_status[4];
  int humidity = room_status[5];

  Serial.println(room_status(1));



}
