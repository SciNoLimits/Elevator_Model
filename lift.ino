
//Lift code for three floors//
#include <EEPROM.h>
#include <Stepper.h>
bool debug = true;
const int stepsPerRevolution = 512;

int pos=0;
int address = 0;
int memSize = 10; 

void ISR1();
void ISR2();
void ISR3();
      
int e=A0,
    d=A1,
    c=A2,
    g=A3,
    f=A4,
    a=A5,
    b=A6;
    
void zero();
void one();
void two();
void nul();

Stepper myStepper(stepsPerRevolution, 8, 12, 10, 13);

int floor_button_0 = 18;
int floor_button_1 = 19;
int floor_button_2 = 20;

int magnetic_sensor_0 = 7;
int magnetic_sensor_1 = 6;
int magnetic_sensor_2 = 5;

int motor_1 = 9;
int motor_2 = 11;

int door_1 = 8;
int door_2 = 10;
int door_3 = 12;
int door_4 = 13;

void showSeq();
void setup() {

Serial.begin(9600);
myStepper.setSpeed(70);

 pinMode(a, OUTPUT);
 pinMode(b, OUTPUT);
 pinMode(c, OUTPUT);
 pinMode(d, OUTPUT);
 pinMode(e, OUTPUT);
 pinMode(f, OUTPUT);
 pinMode(g, OUTPUT);
 
pinMode(floor_button_0, INPUT_PULLUP);
pinMode(floor_button_1, INPUT_PULLUP);
pinMode(floor_button_2, INPUT_PULLUP);

pinMode(magnetic_sensor_0, INPUT_PULLUP);
pinMode(magnetic_sensor_1, INPUT_PULLUP);
pinMode(magnetic_sensor_2, INPUT_PULLUP);

pinMode(motor_1, OUTPUT);
pinMode(motor_2, OUTPUT);

pinMode(door_1, OUTPUT);
pinMode(door_2, OUTPUT);
pinMode(door_3, OUTPUT);
pinMode(door_4, OUTPUT);

attachInterrupt(digitalPinToInterrupt(floor_button_0), ISR1, LOW);
attachInterrupt(digitalPinToInterrupt(floor_button_1), ISR2, LOW);
attachInterrupt(digitalPinToInterrupt(floor_button_2), ISR3, LOW);

for (int i = 0 ; i < (memSize+10) ; i++) EEPROM.write(i, 0);

if(digitalRead(magnetic_sensor_0)== LOW) zero();
else if(digitalRead(magnetic_sensor_1)== LOW) one();
else if(digitalRead(magnetic_sensor_2)== LOW) two();
else nul();
}

void loop(){
//  int floor_read_0 = digitalRead(floor_button_0);
//  int floor_read_1 = digitalRead(floor_button_1);
//  int floor_read_2 = digitalRead(floor_button_2);

if (EEPROM.read(0) != 255){
 for (int i=0; i<memSize; i++){
  if(EEPROM.read(i) == 3)
  {
    while(1)
    {
      if(debug) showSeq();
      if(debug)Serial.println("Motor rotate");
      digitalWrite(motor_1, HIGH);
      digitalWrite(motor_2, LOW);
      int sensor_read_2 = digitalRead(magnetic_sensor_2);    
      if (sensor_read_2 == LOW)
      {
        two();
        digitalWrite(motor_1, LOW);
        digitalWrite(motor_2, LOW);
        if(debug)Serial.println("clockwise");
//        myStepper.step(-stepsPerRevolution*9);
//        delay(4000);
//        if(debug)Serial.println("counterclockwise");
//        myStepper.step(stepsPerRevolution*9);
//        delay(4000);
        digitalWrite(door_1, LOW);
        digitalWrite(door_2, LOW);
        digitalWrite(door_3, LOW);
        digitalWrite(door_4, LOW);
        break;
      }
    }
  }
  if(EEPROM.read(i) == 2)
  {
    
    int sensor_read_0 = digitalRead(magnetic_sensor_0);
    int sensor_read_2 = digitalRead(magnetic_sensor_2);
    if(sensor_read_0 == LOW)
    {
      while(1)
      {
            if(debug) showSeq();

      digitalWrite(motor_1, HIGH);
      digitalWrite(motor_2, LOW);
      int sensor_read_1 = digitalRead(magnetic_sensor_1);    
      if (sensor_read_1 == LOW)
      {
        one();
        digitalWrite(motor_1, LOW);
        digitalWrite(motor_2, LOW);
       myStepper.step(-stepsPerRevolution*9);
       delay(4000);
       if(debug)Serial.println("counterclockwise");
       myStepper.step(stepsPerRevolution*9);
       delay(4000);
        digitalWrite(door_1, LOW);
        digitalWrite(door_2, LOW);
        digitalWrite(door_3, LOW);
        digitalWrite(door_4, LOW);
        break;
      }
      }
    }
    if(sensor_read_2 == LOW)
    {
      while(1)
      {    if(debug) showSeq();

      digitalWrite(motor_1, LOW);
      digitalWrite(motor_2, HIGH);
      int sensor_read_1 = digitalRead(magnetic_sensor_1);    
      if (sensor_read_1 == LOW)
      {
        digitalWrite(motor_1, LOW);
        digitalWrite(motor_2, LOW);
//        myStepper.step(-stepsPerRevolution*9);
//        delay(4000);
//        if(debug)Serial.println("counterclockwise");
//        myStepper.step(stepsPerRevolution*9);
//        delay(4000);
        digitalWrite(door_1, LOW);
        digitalWrite(door_2, LOW);
        digitalWrite(door_3, LOW);
        digitalWrite(door_4, LOW);
        break;
      }
      }
    }
  }
  if(EEPROM.read(i) == 1)
  {

    while(1)
    {     if(debug) showSeq();

      if(debug)Serial.println("Motor rotate");
      digitalWrite(motor_1, LOW);
      digitalWrite(motor_2, HIGH);
      int sensor_read_0 = digitalRead(magnetic_sensor_0);    
      if (sensor_read_0 == LOW)
      {
        zero();
        digitalWrite(motor_1, LOW);
        digitalWrite(motor_2, LOW);
       myStepper.step(-stepsPerRevolution*9);
       delay(4000);
       if(debug)Serial.println("counterclockwise");
       myStepper.step(stepsPerRevolution*9);
       delay(4000);
        digitalWrite(door_1, LOW);
        digitalWrite(door_2, LOW);
        digitalWrite(door_3, LOW);
        digitalWrite(door_4, LOW);

        break;
       }
    }
  }
  if (EEPROM.read(i)==0){
        if(debug) showSeq();
        digitalWrite(motor_1, LOW);
        digitalWrite(motor_2, LOW);
        digitalWrite(door_1, LOW);
        digitalWrite(door_2, LOW);
        digitalWrite(door_3, LOW);
        digitalWrite(door_4, LOW);
        EEPROM.write(0, 255);

    }
//  Serial.println("Break........");
}
}
}
void zero(){
     digitalWrite(a, 0);
     digitalWrite(b, 0);
     digitalWrite(c, 0);
     digitalWrite(d, 0);
     digitalWrite(e, 0);
     digitalWrite(f, 0);
     digitalWrite(g, 1);
  }

void one(){
     digitalWrite(a, 1);
     digitalWrite(b, 0);
     digitalWrite(c, 0);
     digitalWrite(d, 1);
     digitalWrite(e, 1);
     digitalWrite(f, 1);
     digitalWrite(g, 1);
  }

void two(){
     digitalWrite(a, 0);
     digitalWrite(b, 0);
     digitalWrite(c, 1);
     digitalWrite(d, 0);
     digitalWrite(e, 0);
     digitalWrite(f, 1);
     digitalWrite(g, 0);
  }

void nul(){
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  }
  
void ISR1(){
  detachInterrupt(floor_button_0);
  pos = 1;
  EEPROM.write(address, pos);
  address ++;
  if (address == memSize) address = 0;
  delay(100);
//  attachInterrupt(digitalPinToInterrupt(floor_button_0), ISR1, FALLING);
}

void ISR2(){
  detachInterrupt(floor_button_1);
  pos = 2;
  EEPROM.write(address, pos);
  address ++;
  if (address == memSize) address = 0;
  delay(100);
//  attachInterrupt(digitalPinToInterrupt(floor_button_1), ISR2, FALLING);  
  }

void ISR3(){
  detachInterrupt(floor_button_2);
  pos = 3;
  EEPROM.write(address, pos);
  address ++;
  if (address == memSize) address = 0;
  delay(100);
//  attachInterrupt(digitalPinToInterrupt(floor_button_2), ISR3, FALLING);  
  }

void showSeq(){
  for (int i = 0 ; i < memSize ; i++){
    Serial.print(EEPROM.read(i), DEC);
    Serial.print(',');
    }
  Serial.println();
}
