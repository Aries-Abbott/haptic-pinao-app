#include <SoftwareSerial.h>

SoftwareSerial BT(8, 9);
#define vibrationMotorPin_1 A0  
#define vibrationMotorPin_2 A1
#define vibrationMotorPin_3 A2
#define vibrationMotorPin_4 A3
#define vibrationMotorPin_5 A4
int sec = 5;

void setup() {
  pinMode(vibrationMotorPin_1, OUTPUT);
  pinMode(vibrationMotorPin_2, OUTPUT);
  pinMode(vibrationMotorPin_3, OUTPUT);
  pinMode(vibrationMotorPin_4, OUTPUT);
  pinMode(vibrationMotorPin_5, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
  // BT.setTimeout(1000);
}

void loop() {


  if(BT.available()){
    
    char cmd = BT.read();
    delay(100);
    Serial.println(cmd);

    sec = 0;
    
    if (cmd == '0') 
    {
      digitalWrite(vibrationMotorPin_1, HIGH);
    } 
    else if (cmd == '1') 
    {
      digitalWrite(vibrationMotorPin_2, HIGH);
    } 
    else if (cmd == '2') 
    {
      digitalWrite(vibrationMotorPin_3, HIGH);
    } 
    else if (cmd == '3') {
      digitalWrite(vibrationMotorPin_4, HIGH);
    } 
    else if (cmd == '4') 
    {
      digitalWrite(vibrationMotorPin_5, HIGH);
    }

    // // Serial.flush();
    // BT.flush();
    
  }else{
    // Serial.println(BT.available());
    if(sec == 5){
      digitalWrite(vibrationMotorPin_1, LOW);
      digitalWrite(vibrationMotorPin_2, LOW);
      digitalWrite(vibrationMotorPin_3, LOW);
      digitalWrite(vibrationMotorPin_4, LOW);
      digitalWrite(vibrationMotorPin_5, LOW);
    }
    else{
      sec = sec + 1;
    }
    delay(100); 
  }   

}


