#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);  // I2C address 0x27, 16 column and 2 rows
RF24 radio(7, 8);                    // CE, CSN
const byte address[6] = "00001";
const byte address2[6] = "00002";
int msg;

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
  msg = 1;
  radio.write(&msg, sizeof(msg));
  radio.startListening();
}
