#include <ESP8266WiFi.h>                                              
#include <FirebaseArduino.h> 
#define FIREBASE_HOST "fire-detection-a0910.firebaseio.com"                     
#define FIREBASE_AUTH "juaWHeYrUmtSKqbkJk647ZSXVDVZVTOZrh2lBiDn"           
#define WIFI_SSID "HURU Technologies"                                          
#define WIFI_PASSWORD "passme48"                                            

  int fire_sensor=13;
  int Buzz=D1;
  int Gas=A0;
  int Gthrs=875;                                              
  int Sthrs=950;
 void setup() {
  
  pinMode(fire_sensor,INPUT);
  pinMode(Buzz,OUTPUT);
  pinMode(Gas,INPUT);

  Serial.begin(9600);
  delay(1000);                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                   
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                     
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                       
                                                             
}
void loop() { 
                                            
  int Sensor_Value=digitalRead(fire_sensor);
  int Gas_Value=analogRead(Gas);
  Serial.println(Sensor_Value);
  Serial.println(Gas_Value);
  delay(1000);

  if(Sensor_Value==LOW &&Gas_Value>Gthrs){
 
    Serial.println("FIRE in the HOUSE");
    digitalWrite(Buzz,HIGH);
    String F="FIRE in the HOUSE";
    Firebase.setString("message/Value", F);
    //delay(1000);
  }
  
  else if(Sensor_Value==HIGH &&(Gas_Value>Gthrs)){//&&Gas_Value<Sthrs)){ 
    Serial.println("GAS Leaked");
    digitalWrite(Buzz,HIGH);
    String G="GAS Leaked";
    Firebase.setString("message/Value", G);
    //delay(1000);
  }
  else if(Sensor_Value==LOW&&Gas_Value<Gthrs){ 
    Serial.println("Only fire");
    digitalWrite(Buzz,HIGH);
    String of="Only fire";
    Firebase.setString("message/Value",of);
    //delay(1000);
  }
  else {
    Serial.println("No Fire No Gas");
    digitalWrite(Buzz,LOW);
    String na="no gas no fire";
    Firebase.setString("message/Value",na);
    //delay(1000);
  }

  
}
