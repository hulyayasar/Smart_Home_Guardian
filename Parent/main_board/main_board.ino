#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);  // I2C address 0x27, 16 column and 2 rows
RF24 radio(7, 8);                    // CE, CSN
const byte address[6] = "00001";     // transmit  address
const byte address2[6] = "00002";    // receive trnasmit

void welcome_msg() {
  lcd.setCursor(0, 0);
  lcd.print("                    ");
  lcd.setCursor(0, 1);                // go to the 2nd row
  lcd.print("SYSTEM LOADING.     ");  // pad string with spaces for centering
  delay(300);

  lcd.setCursor(0, 1);  // go to the 2nd row
  lcd.print("SYSTEM LOADING..    ");
  lcd.setCursor(0, 2);                // go to the 2nd row
  lcd.print("                    ");  // pad string with spaces for centering// pad string with spaces for centering
  delay(300);

  lcd.setCursor(0, 1);                // go to the 2nd row
  lcd.print("SYSTEM LOADING...   ");  // pad string with spaces for centering
  delay(300);

  lcd.setCursor(0, 1);                // go to the 2nd row
  lcd.print("SYSTEM LOADING....  ");  // pad string with spaces for centering
  delay(300);

  lcd.setCursor(0, 2);                // go  he third row
  lcd.print("                    ");  // pith spaces for centering
  lcd.setCursor(0, 3);                // go to the fourth row
  lcd.print("                    ");
  delay(400);

  lcd.setCursor(0, 0);
  lcd.print("     WELCOME TO     ");
  lcd.setCursor(0, 1);
  lcd.print("                    ");
  lcd.setCursor(0, 2);
  lcd.print("SMART HOUSE GUARDIAN");
  lcd.setCursor(0, 3);
  lcd.print("                    ");
  delay(2000);
}

void status_display() {

  lcd.setCursor(0, 0);
  lcd.print("ROOM          STATUS");
  lcd.setCursor(0, 1);
  lcd.print(" R1  |       OK     ");
  lcd.setCursor(0, 2);
  lcd.print(" R2  |       OK     ");
  lcd.setCursor(0, 3);
  lcd.print(" R3  |       OK     ");
  delay(300);

}

int room_status(int room_no) {

  int room_reply_arr;
  radio.startListening();

  for (int i = 0; i <= 100; i++) {
    radio.read(&room_reply_arr, sizeof(room_reply_arr));
    if (room_reply_arr > 0) {
      Serial.println(room_reply_arr);
    }
  }

  radio.stopListening();
  radio.write(&room_no, sizeof(room_no));

  return room_reply_arr;
}

void setup() {
  lcd.init();  // initialize the lcd
  lcd.backlight();
  lcd.setBacklight(HIGH);

  welcome_msg();

  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.openWritingPipe(address2);
  radio.setPALevel(RF24_PA_MIN);

  delay(2000);

  // lcd.setBacklight(LOW);
}

void loop() {

  // int room_no = room_status[0];
  // int pir = room_status[1];
  // int gas = room_status[2];
  // int alcohol = room_status[3];
  // int temp = room_status[4];
  // int humidity = room_status[5];

  room_status(2);
  status_display();
}
