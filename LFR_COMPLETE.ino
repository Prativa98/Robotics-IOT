int EnA=2,a=3,b=4,EnB=7,c=5,d=6;
int R1=A0,R2=A1,R3=A2,L3=A3,L2=A4,L1=A5;
int x=200;
void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(EnA,OUTPUT);
  pinMode(EnB,OUTPUT);

  analogWrite(EnA,128);
  analogWrite(EnB,128);
  Serial.begin(9600);
}

void loop() {
  int LL1=analogRead(L1);
  int LL2=analogRead(L2);
  int LL3=analogRead(L3);
  int RR1=analogRead(R1);
  int RR2=analogRead(R2);
  int RR3=analogRead(R3);
  Serial.println(String(LL1)+" "+String(LL2)+" "+String(LL3)+" "+String(RR3)+" "+String(RR2)+" "+String(RR1));
  if((LL3>x&&RR3>x)&&(LL1<x&&LL2<x)&&(RR2<x&&RR1<x)){
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(d,HIGH);
   digitalWrite(c,LOW); 
 
    Serial.println("Move Forward");
    }
else if((((LL1>x&&LL2>x)&&(LL3<x&&RR3<x)&&(RR2<x&&RR1<x))||(((LL1<x&&LL2>x)&&(LL3<x&&RR3<x)&&(RR2<x&&RR1<x))))||((LL2>x&&LL3>x)&&(LL1<x&&RR3<x)&&(RR2<x&&RR1<x)))
{
   Serial.println("Move Left");
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(d,LOW);
   digitalWrite(c,LOW);
   delay(100); 
  }
  //for 45dgr angle
else if((LL1>x&&(LL3>x&&RR3>x))&&((LL2<x&&RR2<x)&&RR1<x)){
  
  Serial.println("Move Left");
  
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(d,LOW);
   digitalWrite(c,LOW);
    delay(700); 
  
  }
  //T shaped Problem
  else if((LL1>x&&LL2>x)&&((LL3>x&&RR3>x)&&(RR2>x&&RR1>x))){
   Serial.println("Move Right");
   digitalWrite(a,LOW);
   digitalWrite(b,LOW);
   digitalWrite(d,HIGH);
   digitalWrite(c,LOW); 
   delay(100);
    
    }
  
  else if((RR1>x&&(RR3>x&&LL3>x))&&((RR2<x&&LL2<x)&&LL1<x)){
  
  Serial.println("Move Right");
  
   digitalWrite(a,LOW);
   digitalWrite(b,LOW);
   digitalWrite(d,HIGH );
   digitalWrite(c,LOW);
    delay(500); 
  
  }

    else if((((RR1>x&&RR2>x)&&(RR3<x&&LL3<x)&&(LL2<x&&LL1<x))||(((RR1>x&&RR2>x)&&(RR3<x&&LL3<x)&&(LL2<x&&LL1<x))))||((RR2>x&&RR3>x)&&(RR1<x&&LL3<x))){
    Serial.println("Move Right");
    digitalWrite(a,LOW);
   digitalWrite(b,LOW);
   digitalWrite(d,HIGH);
   digitalWrite(c,LOW); 
    delay(100);
    }
   /*else if(((RR1>x&&RR2>x)&&(RR3>x))&&((LL3>x)&&(LL2<x&&LL1<x))){
   Serial.println("Move Right");
   digitalWrite(a,LOW);
   digitalWrite(b,LOW);
   digitalWrite(d,HIGH);
   digitalWrite(c,LOW); 
    
    }
    */ 


  
}
