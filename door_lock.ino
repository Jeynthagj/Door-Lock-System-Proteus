

// #include <Servo.h>
// Servo myservo;

// void setup() 
// {
//   myservo.attach(3);
//   delay(2000);
//   Serial.begin(9600);
// }

// void loop() 
// {
//   int i;
//   for(i=0;i<=90;i++);
//   {
//     myservo.write(i);
//     Serial.println("Forward");
//     delay(1000);
//   }
//   for(i=90;i>=0;i--);
//   {
//     myservo.write(i);
//     Serial.println("Backward");
//     delay(1000);
//   }
// }


// #include <Keypad.h>
// const byte ROWS = 4;
// const byte COLS = 3;
// char keys[ROWS][COLS]={
//   {'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}
// };
// byte rowPins[ROWS]={2,3,4,5};
// byte colPins[COLS]={6,7,8};
// Keypad pad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

// void setup()
// {
//   Serial.begin(9600);
// }
// void loop()
// {
//   char key=pad.getKey();
//   if(key)
//   {
//     Serial.print(key);
//   }
// }



#include <Keypad.h>        
#include <Servo.h>         
#include <LiquidCrystal.h> 


Servo myServo;

int servoPin = 9;  
int ledPin = 10;   

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3}; 
byte colPins[COLS] = {A4, A5, 6};     

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1902";
String enteredPassword = ""; 

void setup()
{
  lcd.begin(16, 2);       
  pinMode(ledPin, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(0);    

  lcd.print("ENTER PASSWORD");
  delay(1500);
  lcd.clear();
}

void loop()
{
  char key = keypad.getKey();
  if (key) 
  {
    if (key == '#') {
      lcd.clear();
      if (enteredPassword == password) 
      {
        lcd.print("PASS CORRECT");
        for (int i = 0; i < 16; i++) 
        {
          lcd.scrollDisplayRight();
          delay(250);
        } 
        myServo.write(90);
        delay(3000);
        myServo.write(0); 
      }
      else
      {
        lcd.clear();
        lcd.print("PASS WRONG");
        for (int i = 0; i < 16; i++) 
        {
          lcd.scrollDisplayRight();
          delay(250);
        }
        for (int i = 0; i < 3; i++) 
        {
          digitalWrite(ledPin, HIGH);
          delay(300);
          digitalWrite(ledPin, LOW);
          delay(300);
        }
      }
      enteredPassword = "";
      lcd.clear();
      lcd.print("ENTER PASSWORD");
    }


    else
      {
        if (enteredPassword.length() < 4) 
        {
          enteredPassword += key;
          lcd.clear();
          lcd.print("Entered: ");
          lcd.print(enteredPassword);
        }
      }
  }
}
