byte seven_seg_digits[10][7]={
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,0,1,0,0},
  };
byte pin_numbers[7]={2,3,4,5,6,7,8};

const int buttonPin=12;
int buttonState=0;
int n=0;

void setup() {
  // put your setup code here, to run once:
  for(byte pin=0;pin<7;pin++){
    pinMode(pin_numbers[pin],OUTPUT);
    };
   pinMode(9,OUTPUT);
   digitalWrite(9,0);
   digitalWrite(buttonPin,HIGH);
   pinMode(buttonPin,INPUT_PULLUP);
}

void sevenSegWrite(byte digit){
  for(byte seg=0;seg<7;seg++){
   digitalWrite(pin_numbers[seg],seven_seg_digits[digit][seg]);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
//  buttonState=digitalRead(buttonPin);
//  if(buttonState==0){
    n++;
    if(n>9){
      n=0;
      }
//    }
  sevenSegWrite(n);
  delay(1000);
}
