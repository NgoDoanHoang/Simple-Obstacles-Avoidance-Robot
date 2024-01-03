const int trig1 = 28;
const int trig2 = 26;
const int trig3 = 24;
const int trig4 = 22;
const int trig0 = 30;
const int echo0 = 31;
const int echo1 = 29;
const int echo2 = 27;
const int echo3 = 25;
const int echo4 = 23;
const int Rwheela=5;
const int Rwheelb=4;
const int Lwheela=6;
const int Lwheelb=7;

void setup() 
{
    //Serial
    Serial.begin(9600);
    
  // put your setup code here, to run once:
    pinMode(trig0,OUTPUT);
    pinMode(trig1,OUTPUT);
    pinMode(trig2,OUTPUT);
    pinMode(trig3,OUTPUT);
    pinMode(trig4,OUTPUT); 
    pinMode(echo0,INPUT);
    pinMode(echo1,INPUT);
    pinMode(echo2,INPUT);
    pinMode(echo3,INPUT);
    pinMode(echo4,INPUT);
    pinMode(Rwheela,OUTPUT);
    pinMode(Rwheelb,OUTPUT);
    pinMode(Lwheela,OUTPUT);
    pinMode(Lwheelb,OUTPUT);    

    //Set initial rotation direction
    analogWrite(Rwheela, 50);
    analogWrite(Rwheelb, 0);
    analogWrite(Lwheela, 50);
    analogWrite(Lwheelb, 0);
}

void straight() 
{
    analogWrite(Rwheela, 50);
    analogWrite(Rwheelb, 0);
    analogWrite(Lwheela, 50);
    analogWrite(Lwheelb, 0);
}

int Distance(int trig, int echo)
{
    unsigned long duration; // biến đo thời gian
    int distance;           // biến lưu khoảng cách
    
    /* Phát xung từ chân trig */
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    return distance = int(duration/2/29.412);
}

void turnLeft() 
{
    analogWrite(Rwheela, 50);
    analogWrite(Rwheelb, 0);
    analogWrite(Lwheela, 0);
    analogWrite(Lwheelb, 50);
}

void loop() 
{
  int a = Distance(trig2, echo2);
  Serial.println(a);
  delay(500);

  if(a<20) 
  {
    turnLeft();
    delay(1000);
  } else straight();

//  if(Distance(trig1, echo0)<20) {
//    turnLeft();
//    delay(1000);
//  } else straight();
//  if(Distance(trig2, echo0)<20) {
//    turnLeft();
//    delay(1000);
//  } else straight();
//  if(Distance(trig3, echo0)<20) {
//    turnLeft();
//    delay(1000);
//  } else straight();
//  if(Distance(trig4, echo0)<20) {
//    turnLeft();
//    delay(1000);
//  } else straight();
}
