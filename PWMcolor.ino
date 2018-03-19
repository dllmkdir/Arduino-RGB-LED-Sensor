//Tested in a dark room.
//code by dllmkdir.
//Software generated PWM example
//Output enable -> GND
int i;
int n;
int dled[3]={5,6,3};
int dsensorc[3][2]={{LOW,HIGH},{HIGH,HIGH},{LOW,LOW}};//BGR; Selection for photodiode array
int dcolor[3]={0,0,0};
int r=3;
int g=6;
int b=5;
int s0=8;
int s1=9;
int s2=10;
int s3=11;
int outpin=12;

int pin,freq;
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
  
  //aRead=analogRead(aPin);
  if (freq>20 && freq<130 && (dsensorc[pin][0] && dsensorc[pin][1])){//GREEN
    n=(int)(floor(freq*(-37.5)+3750));//equation for light intensity
    dcolor[0]=freq;//for debugging
    digitalWrite(dled[pin],HIGH);//write HIGH a certain time
    delayMicroseconds(n);
    digitalWrite(dled[pin],LOW);//CLear output pin
  }else if (freq>20 && freq<100 && (!dsensorc[pin][0] && dsensorc[pin][1])){//BLUE
    n=(int)(floor(freq*(-11.764705)+3000));//equation for light intensity
    dcolor[1]=freq;//for debugging
    digitalWrite(dled[pin],HIGH);
    delayMicroseconds(n);
    digitalWrite(dled[pin],LOW);
  }else if (freq>20 &&freq<200 && (!dsensorc[pin][0] && !dsensorc[pin][1])){//RED
    
    n=(int)(floor(freq*(-11.764705)+3000));//equation for light intensity
    dcolor[2]=freq;//for debugging
    digitalWrite(dled[pin],HIGH);
    delayMicroseconds(n);
    digitalWrite(dled[pin],LOW);

  }
  
  
}
  /*
  Serial.print("B:");
  Serial.print(dcolor[0]);
  Serial.print("  G:");
  Serial.print(dcolor[1]);
  Serial.print("  R:");
  Serial.print(dcolor[2]);
  Serial.println();
  delay(1000);*/
  

}