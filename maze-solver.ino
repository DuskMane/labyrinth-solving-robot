 
  //left motor setup
  #define INL1 12
  #define INL2 13
  #define PWML 3
  
  //right motor setup
  #define INR1 7
  #define INR2 8
  #define PWMR 9

  //HCSR1 setup
  #define TRIG1 6
  #define ECHO1 4
  #define TRIG2 2 
  #define ECHO2 10
void setup() {
  // put your setup code here, to run once:
  
  pinMode(PWML,OUTPUT);
  pinMode(PWMR,OUTPUT);
  pinMode(INL1,OUTPUT);
  pinMode(INL2,OUTPUT);
  pinMode(INR1,OUTPUT);
  pinMode(INR2,OUTPUT);

  Serial.begin (9600);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
}

long sure, uzklk, onMesafe, sagMesafe;
long threedata[3];
unsigned long interval = 0;
void loop() {
  onMesafe = distanceFront();
  sagMesafe = distanceRight();
  if(sagMesafe < 7){
    turnLeftFor(55);
  }
  if(onMesafe < 10){
      backward();
  }
  if(onMesafe >= 20 && sagMesafe <= 20){
    if(sagMesafe < 7){
      turnLeftFor(55);
    }
    forward();
  }
  if(onMesafe >= 20 && sagMesafe > 25){
    delay(250);//250
    fullStop();
    turnRight();
    delay(330);//310
    fullStop();
    delay(320);//300
    forwardFor(275);//275
  }
  if(onMesafe < 20 && sagMesafe <= 20){
    backFor(400);
    turnLeft();
    delay(400);
  }
  if(onMesafe < 20 && sagMesafe > 20){
    if(onMesafe < 7){
      backward();
    }
    else{
      backFor(200);
      turnLeft90();
    }
  }
}
long distanceFront(){
  long uzklk1,uzklk2,uzklk3;
  digitalWrite(TRIG1, LOW);
  delay(5);
  digitalWrite(TRIG1, HIGH);
  delay(10);
  digitalWrite(TRIG1, LOW);
  sure = pulseIn(ECHO1, HIGH);
  uzklk1 = (sure/2)/ 29.1;
  uzklk2 = (sure/2)/ 29.1;
  uzklk3 = (sure/2)/ 29.1;
  uzklk = (uzklk1+uzklk2+uzklk3)/3;
  delay(50);
  return uzklk;
}
long distanceRight(){
  long uzklk1,uzklk2,uzklk3;
  digitalWrite(TRIG2, LOW);
  delay(5);
  digitalWrite(TRIG2, HIGH);
  delay(10);
  digitalWrite(TRIG2, LOW);
  sure = pulseIn(ECHO2, HIGH);
  uzklk1 = (sure/2)/ 29.1;
  uzklk2 = (sure/2)/ 29.1;
  uzklk3 = (sure/2)/ 29.1;
  uzklk = (uzklk1+uzklk2+uzklk3)/3;
  delay(50);
  return uzklk;
}
void backward() {
  digitalWrite(INL1, HIGH);
  digitalWrite(INR1, HIGH);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, LOW);
  analogWrite(PWML,120);
  analogWrite(PWMR,120);
  
}
void fullForward() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,120);
  analogWrite(PWMR,120); 
}
void forward() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,120);//105
  analogWrite(PWMR,145);  
}

void fullStop() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, LOW);
  
  analogWrite(PWML,0);
  analogWrite(PWMR,0);
  
}

void turnRight() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,110);
  analogWrite(PWMR,0);
}
void turnRight90() {
  turnRight();
  delay(900);
  fullStop();
}
void turnLeft() {
  digitalWrite(INL1, HIGH);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, HIGH);
  
  analogWrite(PWML,0);
  analogWrite(PWMR,130);
}
void turnLeft90() {
  turnLeft();
  delay(800);
  fullStop();
}
//smart commands
void turnLeft180() {
  turnLeft();
  delay(950);
  fullStop();
}
int turnLeftFor(int leftTime) {
  turnLeft();
  delay(leftTime);
  fullStop();
}
void forwardFor(int forwardTime) {
  fullForward();
  delay(forwardTime);
  fullStop();
}
void backFor(int backTime) {
  backward();
  delay(backTime);
  fullStop();
}
void rotateLeft() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,125);
  analogWrite(PWMR,147);  
}
void rotateRight() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,140);
  analogWrite(PWMR,140);  
}
