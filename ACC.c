#define echoPin 2        
#define trigPin 3 
#define MotorPin1 9
#define MotorPin1a 12
#define MotorPin2 8
#define MotorPin2a 11
#define Buzzer 5
#define Accelerator 7
#define Reverse 6
long duration;
float distance;
void setup(){
  pinMode (trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(MotorPin1,OUTPUT);
  pinMode(MotorPin1a,OUTPUT);
  pinMode(MotorPin2a,OUTPUT);
  pinMode(MotorPin2,OUTPUT);
  pinMode (Buzzer,OUTPUT);
  pinMode (Accelerator,INPUT);
  pinMode (Reverse,INPUT);
  Serial.begin(9600);
  Serial.println("distance");
  delay(500);
  
}
void dist_measure(void){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.0344/2;
  Serial.print("distance:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}
void motor_off(void){
     digitalWrite(MotorPin1,LOW);
     digitalWrite(MotorPin1a,LOW);
     digitalWrite(MotorPin2,LOW);
     digitalWrite(MotorPin2a,LOW);
     digitalWrite(Buzzer,LOW);}
void motor_ON(void){
     analogWrite(9,100);
     digitalWrite(MotorPin1a,LOW);
     digitalWrite(MotorPin2,LOW);
     analogWrite(11,100);
}
void motor_reverse(void){
     digitalWrite(MotorPin1,LOW);
     digitalWrite(MotorPin1a,HIGH);
     digitalWrite(MotorPin2,HIGH);
     digitalWrite(MotorPin2a,LOW);
}
  
  void loop(){
  dist_measure();
  if (digitalRead (Accelerator) == 0 && digitalRead (Reverse ==0)){
    motor_off();}
  if(digitalRead(Accelerator) == 1 && digitalRead(Reverse == 0)){
  while (distance >51){
    motor_ON();
    delayMicroseconds(2);
    digitalWrite(Buzzer,LOW);
    delayMicroseconds(2);
    dist_measure();
    if (digitalRead(Accelerator) == 0 && digitalRead(Reverse) == 0){
      break;}
   else 
        continue;    
   }
     while (distance <50 && distance >30){
    motor_ON();
    delayMicroseconds(2);
    digitalWrite(Buzzer,HIGH);
    delayMicroseconds(2);
    dist_measure();
    if (digitalRead(Accelerator) == 0 && digitalRead(Reverse) == 0){
      break;}
   else 
        continue;    
   }
     while (distance < 30){
    motor_off();
    delayMicroseconds(2);
    digitalWrite(Buzzer,HIGH);
    delayMicroseconds(2);
    dist_measure();
    if (digitalRead(Accelerator) == 0 && digitalRead(Reverse) == 0){
      break;}
   else 
        continue;    
   }
  }
  else if(digitalRead(Reverse) == 1 && digitalRead(Accelerator) == 0){
  while (distance >51){
    motor_reverse();
    delayMicroseconds(2);
    digitalWrite(Buzzer,LOW);
    delayMicroseconds(2);
    dist_measure();
   if (digitalRead(Accelerator) == 0 && digitalRead(Reverse) == 0){
      break;}
   else 
        continue;    
   }
     while (distance <50 && distance >30){
    motor_reverse();
    delayMicroseconds(2);
    digitalWrite(Buzzer,HIGH);
    delayMicroseconds(2);
    dist_measure();
    if (digitalRead(Accelerator) == 0 && digitalRead(Reverse) == 0){
      break;}
   else 
        continue;    
   }
     while (distance < 30){
    motor_off();
    delayMicroseconds(2);
    digitalWrite(Buzzer,HIGH);
    delayMicroseconds(2);
    dist_measure();
   if (digitalRead(Accelerator) == 0 && digitalRead(Reverse) == 0){
      break;}
   else 
        continue;    
   }
  }
 } 
