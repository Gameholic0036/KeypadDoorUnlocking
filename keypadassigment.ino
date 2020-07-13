#include <Keypad.h>//including the keypad library
#include <LiquidCrystal.h>//including the liquidCrystal library
#include <EEPROM.h>//including the EEPROM library
#include <Servo.h>//including the Servo library
//INCLUDING ALL THE LIBRARIES
LiquidCrystal lcd(12,11,7,6,5,4);

char keys[4][4]=
{{'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}};
 byte rowpins[4]={A0,A1,A2,A3};
 byte colpins[4]={A4,A5,2,3};
 Keypad keypad=Keypad(makeKeymap(keys),rowpins,colpins,4,4);
 Servo myservo;
char pwd[4],tpwd[4];
int wrg=0;int b=8; 
//                        CHANGE FUNCTION
void change()
  {lcd.clear();
    delay(500);
    lcd.print("Enter the password");
    lcd.setCursor(0,1);
   for(int i=0;i<4;i++)
     {  
      char s=keypad.waitForKey();
      if(s){
      EEPROM.write(i,s);}
      lcd.print("+");
     }
     delay(1000);
     lcd.clear();
     getpwd();
    }//end of change function
/*CHANGE FUNCTION is used to alter the password that has been stored in the eeprom*/    
//                        GRTPWD FUNCTION
void getpwd()
         { lcd.print("LOADING...."); 
           for(int i=0;i<4;i++)
           {charexg(i);}
            delay(2000);
           lcd.clear();
         } //end of getpwd
/*getpwd FUNCTION has been defined to get the value of password that haas been stored in EEPROM*/
//                        CHAREXG FUNCTION
void charexg(int a)
      {int e=EEPROM.read(a);
      pwd[a]=(char)(e);
      }// end of charexg
void servomo(){
  for (int pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
  }//servomo is defined to turn the servo motor by 90
//                       SETUP FUNCTION
void setup()
    {Serial.begin(9600);
     lcd.begin(16,2);
     if(EEPROM.read(100)==0)
     /*this if has been used to check if EEPROM already has a stored password or not
      * if value at 100 is 0 that means there is no password stored 
      * but if value at 100 is not 0 that means there is a passsword stored,so it skip to else
      */
      {lcd.print("    WELCOME   ");
      delay(500);
      change();
      EEPROM.write(100,1);
      }// end of if 
     else
     {getpwd();
     }// end of else
    pinMode(b,OUTPUT);
    
    myservo.attach(9);}//end of setup
//                        LOOP FUNCTION
void loop()
{  lcd.clear();
   delay(500); 
  if(wrg<3)
    {int i;
      lcd.print("The password");
      lcd.setCursor(0,1);
      for( i=0;i<4;i++)
        { char s=keypad.waitForKey();
        tone(b,4500);
        delay(100);
        noTone(b);
         if(s=='*')
         {change();
         break;}
         tpwd[i]=s;
         if(pwd[i]!=tpwd[i])//
            { lcd.print("+");
            delay(1000);
            lcd.clear();
            lcd.print("ACCESS DENIED");
             tone(b,427);
             delay(500);
             noTone(b);
             delay(500);  
             wrg++; 
             break;}
         else
         {lcd.print("+");
         }  
           if(i==3)
         {lcd.clear();lcd.print("ACCESS GRANTED"); servomo();delay(5000);}
        }//end of for loop
     }//end of if
  else
            {lcd.clear();
            lcd.print("Try again in");
        for(int i=30;i>0;i--)
          {lcd.setCursor(0,1);
            lcd.print(i);
           delay(1000);
           }//end of for loop
      wrg=0;
      }// end of else
}
// end of loop function
