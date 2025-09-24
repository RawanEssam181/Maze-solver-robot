//motors defination
int in1=3;
int in2=4;

int in3=7;
int in4=8;
//speed
int ena=5;
int enb=6;
//ultrasonicSensors
int echo1=2;
int echo2=9;
int echo3=10;

int trig1=11;
int trig2=12;
int trig3=13;

int distance1;      //for forwardsensor
int distance2;      //for leftSensor
int distance3;      //for rightSensor

int duration1;
int duration2;
int duration3;


void setup() {
 
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

pinMode(ena,OUTPUT);
pinMode(enb,OUTPUT);
pinMode(trig1, OUTPUT);
pinMode(echo1, INPUT);

pinMode(trig2, OUTPUT);
pinMode(echo2, INPUT);

pinMode(trig3, OUTPUT);
pinMode(echo3, INPUT);
  
Serial.begin(9600);

}

// the loop routine runs over and over again forever:
void loop() {
digitalWrite(trig1, LOW);
delayMicroseconds(2);
digitalWrite(trig1, HIGH);
delayMicroseconds(10);
digitalWrite(trig1, LOW);

duration1 = pulseIn(echo1, HIGH);
distance1 = duration1 * 0.034 / 2;


digitalWrite(trig2, LOW);
delayMicroseconds(2);
digitalWrite(trig2, HIGH);
delayMicroseconds(10);
digitalWrite(trig2, LOW);

duration2 = pulseIn(echo2, HIGH);
distance2 = duration2 * 0.034 / 2;

digitalWrite(trig3, LOW);
delayMicroseconds(2);
digitalWrite(trig3, HIGH);
delayMicroseconds(10);
digitalWrite(trig3, LOW);

duration3 = pulseIn(echo1, HIGH);
distance3 = duration3 * 0.034 / 2;

if(distance1>15)
{forward();}
else if(distance1<15 && distance2>15)
{left();}
else if(distance1<15 && distance2<15 && distance3 >15)
{right();}
else if(distance1<15 && distance2<15 && distance3 <15)
{Stop();}
}

void forward()
{
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
 analogWrite(ena,255);
 analogWrite(enb,255);
  }
 void backward()
 {
  digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 analogWrite(ena,255);
 analogWrite(enb,255);

  }
  void left ()
 { 
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(ena,255);
analogWrite(enb,255);
  }
  void right()
{
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
analogWrite(ena,255);
analogWrite(enb,255);
}
void Stop()
{
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
analogWrite(ena,0);
analogWrite(enb,0);
  }
