#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);  // I2C address 0x27, 16 column and 2 rows
RF24 radio(7, 8);                    // CE, CSN
const byte address[6] = "00001";     // transmit  address
const byte address2[6] = "00002";    // receive trnasmit
int data;
String lcd_data;
String lcd_msg;

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
  lcd.setCursor(0, 0);
  lcd.print("                    ");
  lcd.setCursor(0, 1);
  lcd.print("                    ");
  lcd.setCursor(0, 2);
  lcd.print("                    ");
  lcd.setCursor(0, 3);
  lcd.print("                    ");
}

void status_display(int room, int data) {

  Serial.print(room);
  Serial.print(" - ");
  Serial.print(data);
  Serial.println("");

  char char_msg[6];
  itoa(data, char_msg, 10);

  lcd.setCursor(0, 0);
  lcd.print("ROOM   STATUS");

  if (room == 1) {
    lcd_msg = "";
    
    if (char_msg[1] == '0' && char_msg[2] == '0' && char_msg[3] == '0' && char_msg[4] == '0') {
      lcd_msg = "OK           ";
      lcd.setCursor(0, room);
      lcd_data = "";
      lcd_data = " R" + String(room) + "  | " + lcd_msg;
      lcd.print(lcd_data);
      //lcd_msg = "";
    }
    if (char_msg[1] == '1') {
      lcd.setCursor(0, room);
      lcd_data = "";
      lcd_msg = lcd_msg + "CO2 ";
      lcd_data = " R" + String(room) + "  | " + lcd_msg;
      lcd.print(lcd_data);
    }
    if (char_msg[2] == '1') {
      lcd.setCursor(0, room);
      lcd_data = "";
      lcd_msg = lcd_msg + "AL ";
      lcd_data = " R" + String(room) + "  | " + lcd_msg;
      lcd.print(lcd_data);
    }
  }

  if (room == 2) {
    lcd_msg = "";
    lcd.setCursor(0, room);
    if (char_msg[1] == '0' && char_msg[2] == '0' && char_msg[3] == '0' && char_msg[4] == '0') {
      lcd_msg = "OK           ";
      lcd.setCursor(0, room);
      lcd_data = " R" + String(room) + "  | " + lcd_msg;
      lcd.print(lcd_data);
      lcd_msg = "";
    }
    if (char_msg[1] == '1') {
      lcd_msg = lcd_msg + "CO2 ";
      lcd_data = " R" + String(room) + "  | " + lcd_msg;
      lcd.print(lcd_data);
    }
    if (char_msg[2] == '1') {
      lcd_msg = lcd_msg + "AL ";
      lcd_data = " R" + String(room) + "  | " + lcd_msg;
      lcd.print(lcd_data);
    }
  }


  delay(300);
}

int room_status(int room_no) {

  int room_reply_arr;
  radio.startListening();

  for (int i = 0; i <= 100; i++) {
    radio.read(&room_reply_arr, sizeof(room_reply_arr));
    if (room_reply_arr >= (room_no * 10000)) {
      return room_reply_arr;
      //Serial.println(room_reply_arr);
    }
  }

  radio.stopListening();
  radio.write(&room_no, sizeof(room_no));
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

  data = room_status(1);
  if (data == 0) {
    data = room_status(1);
  }
  status_display(1, data);
  delay(20);

  data = room_status(2);
  if (data == 0) {
    data = room_status(2);
  }
  status_display(2, 20000);
  delay(20);

  data = room_status(3);
  if (data == 0) {
    data = room_status(3);
  }
  status_display(3, data);
  delay(20);
  //Serial.println(data);
}
