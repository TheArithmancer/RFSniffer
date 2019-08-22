#include <RCSwitch.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
RCSwitch mySwitch = RCSwitch();    // Set up to receive RF Transmissions

void setup()
{
  
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #D2 on Arduino

  lcd.init();                      // initialize the lcd 

  // Print a start message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Yaz's RF Sniffer");
}


void loop()
{
  
  if (mySwitch.available()) {   // If we have received a signal
    lcd.setCursor(0,1);
    lcd.print("Signal: ");
    lcd.print(mySwitch.getReceivedValue());
    lcd.print(" (");
    lcd.print(mySwitch.getReceivedBitlength());
    lcd.print(")");
    
    lcd.setCursor(0,2);
    lcd.print("Pulse Length: ");
    lcd.print(mySwitch.getReceivedDelay());

    lcd.setCursor(0,3);
    lcd.print("Protocol: ");
    lcd.print(mySwitch.getReceivedProtocol());

  
    mySwitch.resetAvailable();
    
  }
}
