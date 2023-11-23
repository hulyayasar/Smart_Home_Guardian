#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();

   lcd.setBacklight(HIGH);


 lcd.setCursor ( 0, 0 );
 lcd.print("                    ");
 lcd.setCursor ( 0, 1 ); // go to the 2nd row
 lcd.print("SYSTEM LOADING.     "); // pad string with spaces for centering
 delay(300);

  lcd.setCursor ( 0, 1 ); // go to the 2nd row
 lcd.print("SYSTEM LOADING..    "); 
 lcd.setCursor ( 0, 2 ); // go to the 2nd row
 lcd.print("                    "); // pad string with spaces for centering// pad string with spaces for centering
 delay(300);

  lcd.setCursor ( 0, 1 ); // go to the 2nd row
 lcd.print("SYSTEM LOADING...   "); // pad string with spaces for centering
 delay(300);

 lcd.setCursor ( 0, 1 ); // go to the 2nd row
 lcd.print("SYSTEM LOADING....  "); // pad string with spaces for centering
 delay(300);

 
 lcd.setCursor ( 0, 2 ); // go  he third row
 lcd.print("                    "); // pith spaces for centering
 lcd.setCursor ( 0, 3 ); // go to the fourth row
 lcd.print("                    ");
 delay(400);

 lcd.setCursor ( 0, 0 );
 lcd.print("     WELCOME TO     ");
 lcd.setCursor ( 0, 1 );
 lcd.print("                    ");
 lcd.setCursor ( 0, 2 );
 lcd.print("SMART HOUSE GUARDIAN");
 lcd.setCursor ( 0, 3 );
 lcd.print("                    ");

// lcd.setBacklight(LOW); 


//  lcd.setCursor ( 0, 0 ); // go to the top left corner
//  lcd.print("                    "); // write this string on the top row
//  lcd.setCursor ( 0, 1 ); // go to the 2nd row
//  lcd.print("                    "); // pad string with spaces for centering
//  lcd.setCursor ( 0, 2 ); // go  he third row
//  lcd.print("                    "); // pith spaces for centering
//  lcd.setCursor ( 0, 3 ); // go to the fourth row
//  lcd.print("                    ");
}

void loop()
{ 
lcd.setCursor ( 0, 0 );
 lcd.print("  ROOM     |  STATUS");
 lcd.setCursor ( 0, 1 );
 lcd.print("ROOM 1     |  OK    ");
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |  OK    ");
 lcd.setCursor ( 0, 3 );
 lcd.print("ROOM 3     |  OK    ");

 delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |  TEMP  ");
delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |        ");

  delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |  TEMP  ");
delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |        ");

  delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |  TEMP  ");
delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |        ");

  delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |  TEMP  ");
delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |        ");

  delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |  TEMP  ");
delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |        ");

  delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |  TEMP  ");
delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |        ");

  delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |  TEMP  ");
delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |        ");

  delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |  TEMP  ");
delay(500);
 lcd.setCursor ( 0, 2 );
 lcd.print("ROOM 2     |        ");

 

}
