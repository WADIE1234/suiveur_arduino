
#include <QTRSensors.h>
const uint8_t sensorCount=16;
// uint16_t s[SensorCount];
int s[16];
QTRSensorsRC qtr((unsigned char[]){A0, A1, A2, A3, A4, A5, A6,A7,A8,A9,A10,A11,A12,A13,A14,A15}, 16);

int position;
int n=0;
int c=0;
//PID
int right_speed,left_speed; 

float kp=0.0,kd=0.0,ki=0,P,D,I;



float PIDvalue,lasterror,error;
int left_base,right_base;
//motors
int rightF=5;
int rightR=6;
int leftF=11;
int leftR=10;
unsigned int current_time,last_time,lunch_time;


int launchpin=7;
void setup() {
  


 
  //moteurs
  pinMode(rightF,OUTPUT);
  pinMode(leftF,OUTPUT);
  pinMode(rightR,OUTPUT);
  pinMode(leftR,OUTPUT);  

   // turn on Arduino's LED to indicate we are in calibration mode
   for (int i = 0 ; i < 100; i++)
  {
    qtr.calibrate();
    tst=1;
    delay(20);
  }


    digitalWrite(launchpin, HIGH);
    current_time=millis();
int x=1;

   while(1){
   x=digitalRead(launchpin);
    // Serial.println(x);
    if(x==0){
         lunch_time=millis();
      if(lunch_time-current_time>200) break;
    }
    //  
    }



left_base=200;right_base=200;


}


void loop() {

 
  position = qtr.readLine(s);
  current_time=millis();
 

}

void PID(){
  position = qtr.readLine(s);
  error=position-7500;
  P = error;
  D = error-lasterror;
  I=error+I;
  PIDvalue =(kp*P)+(kd*D)+(ki*I);
  lasterror = error;
  right_speed=right_base+PIDvalue;
  left_speed=left_base-PIDvalue;
  left_speed=min(250,max(left_speed,0));
  right_speed=min(250,max(right_speed,0));
  //delay(200);
  //Serial.println(error);
}
void PIDW(){
  position = qtr.readLineM(s);
  error=position-3500;
  P = error;
  D = error-lasterror;
  I=error+I;
  PIDvalue =(kp*P)+(kd*D)+(ki*I);
  lasterror = error;
  right_speed=right_base+PIDvalue;
  left_speed=left_base-PIDvalue;
  left_speed=min(250,max(left_speed,0));
  right_speed=min(250,max(right_speed,0));}


void pidforcee(){
  position = qtr.readLine(s);
  if(position<2000){left(1);}
  else if (position>13000){right(1);} 
 else{ error=position-7500;
  P = error;
  D = error-lasterror;
  I=error+I;
  PIDvalue =(kp*P)+(kd*D)+(ki*I);
  lasterror = error;
  right_speed=right_base+PIDvalue;
  left_speed=left_base-PIDvalue;
  left_speed=min(250,max(left_speed,0));
  right_speed=min(250,max(right_speed,0)); } 
}
void PID_noir(){
  position = qtr.readLine(s,QTR_EMITTERS_ON,1,true);
  error=position-7500;
  P = error;
  D = error-lasterror;
  I=error+I;
  PIDvalue =(kp*P)+(kd*D)+(ki*I);
  lasterror = error;
  left_speed=left_base-PIDvalue;
  right_speed=right_base+PIDvalue;
  left_speed=min(250,max(left_speed,0));
  right_speed=min(250,max(right_speed,0));
  //delay(200);
  //Serial.println(error);
}

void PID_noir_special(){
  position = qtr.readLine(s,QTR_EMITTERS_ON,1,false);
  error=position-7500;
  P = error;
  D = error-lasterror;
  I=error+I;
  PIDvalue =(kp*P)+(kd*D)+(ki*I);
  lasterror = error;
  left_speed=left_base-PIDvalue;
  right_speed=right_base+PIDvalue;
  left_speed=min(250,max(left_speed,0));
  right_speed=min(250,max(right_speed,0));
  //delay(200);
  //Serial.println(error);
}

void PID_special(){
  bool v=false;
  position = qtr.readLine(s,QTR_EMITTERS_ON,0,v);
  error=position-7500;
  P = error;
  D = error-lasterror;
  I=error+I;
  PIDvalue =(kp*P)+(kd*D)+(ki*I);
  lasterror = error;
  right_speed=right_base+PIDvalue;
  left_speed=left_base-PIDvalue;
  left_speed=min(250,max(left_speed,0));
  right_speed=min(250,max(right_speed,0));
  //delay(200);
  //Serial.println(error);
}
void forwardPID(){
  
  analogWrite(rightF,right_speed);
   analogWrite(leftF,left_speed);
  analogWrite(rightR,0);
  analogWrite(leftR,0);

}
void forward(int x){
  
analogWrite(rightF,165);
   analogWrite(leftF,170);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}
void forwardM(int x){
  
analogWrite(rightF,150);
   analogWrite(leftF,150);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}
void forwardG(int l, int r, int x){
  
analogWrite(rightF,r);
   analogWrite(leftF,l);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}


void forwardf(int x){
  
analogWrite(rightF,255);
   analogWrite(leftF,255);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}
void right(int x){
  
  analogWrite(rightF,180);
   analogWrite(leftF,0);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}
void right_sep(int x){
  
  analogWrite(rightF,150);
   analogWrite(leftF,60);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}

void right_dd(int x){
  
  analogWrite(rightF,120);
   analogWrite(leftF,0);
  analogWrite(rightR,0);
  analogWrite(leftR,120);
  delay(x);
}
void right_dd1(int x){
  
  analogWrite(rightF,110);
   analogWrite(leftF,70);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}
void left_dd(int x){
  
  analogWrite(rightF,0);
   analogWrite(leftF,120);
  analogWrite(rightR,120);
  analogWrite(leftR,0);
  delay(x);
}
void left_dd1(int x){
  
  analogWrite(rightF,70);
   analogWrite(leftF,110);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}
void left(int x){
  
  analogWrite(rightF,0);
   analogWrite(leftF,180);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}
void stp(long int x){
  
  analogWrite(rightF,0);
   analogWrite(leftF,0);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}
void back(int x){
   analogWrite(rightF,0);
   analogWrite(leftF,0);
  analogWrite(rightR,100);
  analogWrite(leftR,100);
  delay(x);
}
void stp1(){
  
  analogWrite(rightF,0);
   analogWrite(leftF,0);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
}
void leftmaze(int x){
  analogWrite(rightF,30);
   analogWrite(leftF,60);//80
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}
void rightmaze(int x){
  analogWrite(rightF,100);
   analogWrite(leftF,40);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}
void rightmaze_1(int x){
  analogWrite(rightF,90);
   analogWrite(leftF,32);
  analogWrite(rightR,0);
  analogWrite(leftR,0);
  delay(x);
}
void speed(){
  int i=158; int j=120;
  while(i<255){
    left_speed=i;
    right_speed=j;
    i+=0.1;j+=0.1;
  }
}
void dhaw(int x) {
  digitalWrite(53, HIGH);
  digitalWrite(red, HIGH);
  delay(50);
  digitalWrite(53, LOW);
  digitalWrite(red, LOW);
}
void dhawfinale(int x) {
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  delay(50);
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  delay(70);
}

void mouleharebbi_valide_N(){
  if (s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]+s[0]>=14000){
  forwardM(1);
  }


else if(s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+2000<s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]+s[0]) {
  right_dd1(1);
} 
else if(s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]>2000+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]+s[0]) {
  left_dd1(1);
}
else {
  forwardM(1);
}
}
void mouleharebbi_valide(){
  if (s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]+s[0]>=14000){
  forwardM(1);
  }


else if(s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+2000<s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]+s[0]) {
  left_dd1(1);
} 
else if(s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]>2000+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]+s[0]) {
  right_dd1(1);
}
else {
  forwardM(1);
}
}

void mouleharebbi_valide_favors_turn_right(){
if(s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]+s[0]<=1000&&s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]>=3500) {
  right_dd1(1);

} 
else if(s[5]+s[4]+s[3]+s[2]+s[1]+s[0]>=3500&&s[15]+s[14]+s[13]+s[12]+s[11]+s[10]>=3500) {
  left_dd1(1);

} 

else if(s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+2000<s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]+s[0]) {
  left_dd1(1);
} 
 
else if(s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]+s[0]<=2000) {
  left_dd(1);

} 
else {
  forwardM(1);
}
}





