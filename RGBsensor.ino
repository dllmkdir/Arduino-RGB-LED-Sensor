//Tested in a dark room.
//code by dllmkdir.
//AnalogWrite example
//Output enable -> GND
int i;
int n;
int dled[3]={5,6,3};
int dsensorc[3][2]={{LOW,HIGH},{HIGH,HIGH},{LOW,LOW}};//BGR
int dcolor[3]={0,0,0};
const int aPin=A1;
int pin,freq;
int r=3;
int g=6;
int b=5;
int s0=8;
int s1=9;
int s2=10;
int s3=11;
int outpin=12;
void setup() {   
  pinMode(b, OUTPUT);//set RGB LED pins
  pinMode(g, OUTPUT);
  pinMode(r, OUTPUT);   
  pinMode(s0, OUTPUT);//Set RGB Sensor pins
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outpin, INPUT);
  digitalWrite(s0,HIGH);
  digitalWrite(s1,LOW);//setting Output Frequency Scaling to 20%

  //Serial.begin(9600); //For debugging...
}
 
void loop() {
for(pin=0;pin<3;pin++){
  //selecting photodiode
  digitalWrite(s2,dsensorc[pin][0]);
  digitalWrite(s3,dsensorc[pin][1]);
  dcolor[pin]=freq;
  freq=pulseIn(12,LOW);//PulseIn function for color detection
  if(freq>255){//offset for better performance, Setting limits, freq goes from 0 to 700
    freq=255;
    }else if(freq<20){
    freq=20;
   }
  if ( freq<255 && (dsensorc[pin][0] && dsensorc[pin][1])){//GREEN
    if(freq>80){
      freq=80;
      }
    analogWrite(dled[pin],(int)(freq*(-4.25)+340));//PWM output with linear equation to map 0 to 255. Adjusted after some debugging...
  }else if (freq<255 && (!dsensorc[pin][0] && dsensorc[pin][1])){//BLUE
    if(freq>80){
      freq=80;
      }
    analogWrite(dled[pin],(int)(freq*(-4.25)+340));
  }else if (freq<255 && (!dsensorc[pin][0] && !dsensorc[pin][1])){//RED
    if(freq>80){
      freq=80;
      }
    analogWrite(dled[pin],(int)(freq*(-4.25)+340));
  }
  
}

}