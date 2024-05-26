//hetha houa
#include <QTRSensors.h>
const uint8_t sensorCount=16;
// uint16_t s[SensorCount];
int s[16];
QTRSensorsRC qtr((unsigned char[]){A0, A1, A2, A3, A4, A5, A6,A7,A8,A9,A10,A11,A12,A13,A14,A15}, 16);
int i=10000000000;
int j=10000000000;
int position;
int n=0;
int c=0;
//PID
int right_speed,left_speed; 
float last_time2;
// float kp=0.1,kd=0.2,ki=0,P,D,I; left=158,right=120
// float kp=0.05,kd=0.07,ki=0,P,D,I;


float kp=0.026,kd=0.05,ki=0,P,D,I;



float PIDvalue,lasterror,error,error1,lasterror1;
int left_base,right_base;
//motors
int rightF=5;
int rightR=6;
int leftF=11;
int leftR=10;
unsigned int current_time,last_time,lunch_time;

 


int led=5;
int red=49;
int green=51;

int launchpin=7;
void setup() {
  


  int tst=0;
  //moteurs
  pinMode(rightF,OUTPUT);
  pinMode(leftF,OUTPUT);
  pinMode(rightR,OUTPUT);
  pinMode(leftR,OUTPUT);  
  pinMode(39,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(launchpin,INPUT);
  pinMode(launchpin,LOW);

  pinMode(led,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
 // qtr.setEmitterPin(2);
// forward(234567);

  // pinMode(LED_BUILTIN, OUTPUT);
  pinMode(13, OUTPUT);
  // digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(red, HIGH);
   // turn on Arduino's LED to indicate we are in calibration mode
   for (int i = 0 ; i < 100; i++)
  {
    qtr.calibrate();
    tst=1;
    delay(20);
  }



   digitalWrite(LED_BUILTIN, LOW); 
   digitalWrite(13, LOW); 
   digitalWrite(red, LOW);


   

    // Serial.begin(9600);

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
delay(200);
forward(150);





}


void loop() {

  // while(1){
  position = qtr.readLine(s);
  current_time=millis();
  if(n==0 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]>=6000 && current_time>200){
stp(100); 
back(100);
right_dd(200);
stp(150);
last_time=current_time;
n=1  ; 
  }
  if(n==1 && current_time- last_time>900){
stp(100) ;   
    n=2;
    last_time=current_time;
  }
    if(n==2 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=2000 && current_time-last_time>800){
stp(50);
back(140); 
left_dd(230);
stp(200);
last_time=current_time;
n=3 ; 
  }
    if(n==3 && s[15]+s[14]+s[13]+s[12]+s[11]+s[5]+s[4]+s[3]+s[2]+s[1]>=8000 && current_time-last_time>1100){

stp(200);
last_time=current_time;
n=4 ; 
  }
  if(n==4 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=2000 && current_time-last_time>300 ){
    stp(5000);
    last_time=current_time;
n=5 ; 
    
  }
  if (n==5 && s[15]+s[14]+s[13]+s[12]+s[11]+s[5]+s[4]+s[3]+s[2]+s[1]<=2000 && current_time-last_time>800 ){
    stp(100);
    left(10);
    n=6;

    last_time=current_time;
  }
  
  if (n==6 && s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]>=6000 && current_time-last_time>850 ){

back(300);
stp(50); 
left_dd(210);
stp(200);
    n=7;
left_base=140;right_base=140;
    last_time=current_time;
  }
  if(n==7 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=2000  && current_time-last_time>250 ){

    back(180);
    
    left(250);
    stp(100);

    n=8;

    last_time=current_time;
  }
  if(n==8 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=2000 && current_time-last_time>500 ){
    stp(50); 
    back(150);
    right_dd(280);
    stp(100);

    n=9;

    last_time=current_time;
  }
  if(n==9 && s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]>=8000 && current_time-last_time>900 ){
    stp(50); 
    back(80);
    left_dd(310);
    stp(100);

    n=10;

    last_time=current_time;
  }
  if(n==10 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]>=4200 && current_time-last_time>800 ){
    stp(50); 
    back(80);
    right_dd(310);
    stp(100);

    n=11;

    last_time=current_time;
  }
  if(n==11 && s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]>=8000 && current_time-last_time>600 ){
    stp(100); 
    back(80);
    left_dd(310);
    forward(160);
    stp(80);

    n=12;

    

    
    last_time=current_time;
  }
  if (n==12 && s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]>=6000 && current_time-last_time>1300 ){

    

back(200);
stp(50); 
left_dd(200);
stp(20);
    n=13;

    left_base=140;right_base=140;

    last_time=current_time;
  }
  if(n==13 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]>=4200 && current_time-last_time>400 ){
    stp(100); 
    right(550);
    stp(100); 
    n=90;
    
    last_time=current_time;
  }
  if(n==90 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=2000 && current_time-last_time>800 ){
    stp(100);
    left(560);
    n=91;
    last_time=current_time;
      }
      if(n==91 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=2000 && current_time-last_time>1200 ){
    stp(100);
    right(310);
    stp(200);
    n=14;
    last_time=current_time;
      }
  if(n==14 && current_time-last_time>800 && s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]>=6000){
    stp(100);
    forward(50);    
    left_dd(230);
    
    n=15; 

    left_base=160;right_base=160;
    
    last_time=current_time;
  }
  if(n==15 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=2000 && current_time-last_time>500 ){
    stp(50); 
    back(120);
    
   
    
    

    n=16;

    last_time=current_time;
  }
  if(n==16 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]>=6500 && current_time-last_time>350 ){
    stp(50); 
   
    forward(50);
    left_dd(260);
    
    stp(100);
    

    n=17;

    last_time=current_time;
  }
  if(n==17 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]>=4200 && current_time-last_time>700 ){
    stp(50); 
   
    
    right_dd(290);
    
    
    stp(100);

    n=18;

    last_time=current_time;
  }
  if(n==18&& s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]>=12000 && current_time-last_time>400 ){
    stp(50); 
   
    
    left_dd(320);
    
    stp(100);
    

    n=19;

    last_time=current_time;
  }
  if(n==19 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=1500 && current_time-last_time>1000 ){
    stp(50); 
    back(150);
    stp(10);
    

    n=20;

    last_time=current_time;
  }
  if(n==20 &&  s[6]+s[5]+s[4]+s[3]+s[2]+s[1]>=4500 ){
    stp(50); 
   
    forward(50);
    left_dd(280);
    
    stp(50);
    

    n=21;

    last_time=current_time;
  }
  if(n==21 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=2200 && current_time-last_time>250 ){
    
    right(80);

  
  }
if(n==21 && current_time-last_time>2500 && s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=2000 )  {
  stp(200000);
}
  

  
  
  

if(n==1){
left_base=100;right_base=100;  
 PID();
forwardPID();
}


if (n==2 ){
  left_base=150;right_base=150;  
  kp=0.02;kd=0.05;
  PID();
forwardPID();
if (s[15]+s[14]>=1100){
  
  forward(20);
  
}
if (s[0]+s[1]>=1100){
  forward(20);
}
if(right_base>140){
    if(j%2==0){right_base--;
    left_base--;}
    j--; 
  }
  }
else if(n==3){
left_base=150;right_base=140;
 kp=0.02;kd=0.05;
  PIDW();
forwardPID();
if (s[15]+s[14]>=1100){
  
  forward(20);
  
}
if (s[0]+s[1]>=1100){
  forward(20);
}  

}
else if(n==4){
  left_base=200;right_base=200;
PID_noir(); 
forwardPID(); 
}
else if(n==5){
  left_base=240;right_base=230;
  if(s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=1000 ){
left(1);    
  }
  mouleharebbi_valide_N(); 
}

else if(n==6){
  if (s[15]+s[14]+s[13]+s[12]+s[11]+s[10]+s[9]+s[8]+s[7]+s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=2000) {
    forward(1);
  } 
  else{
     PID();
forwardPID();
  }
}
else if(n==8 || n==9 || n==10 || n==11){
left_base=180;right_base=180;  
 PID();
    forwardPID(); 
  }
else if(n==12){
    left_base=160;right_base=160;
    PID();
forwardPID();
}
else if(n==14 || n==90 || n==91 || n==19){
  left_base=100;right_base=100;
    PID();
forwardPID();

}

else if(n==20 || n==16){
  if(s[6]+s[5]+s[4]+s[3]+s[2]+s[1]<=3500){
    right_sep(1); 
  }
}

  

else{
  PID();
forwardPID();
}

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




