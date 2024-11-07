const int red=5;
const int yellow=6;
const int green=7;
const int trigPin = 11;  
const int echoPin = 10; 
float duration, distance;
void setup() {
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
  pinMode(red, OUTPUT);  
  pinMode(yellow, OUTPUT); 
  pinMode(green, OUTPUT); 
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  int sensorValue = analogRead(A3);
  if(sensorValue<333){
    sensorValue=0;
  }else if(sensorValue>333&&sensorValue<666){
    sensorValue=5;
  }else if(sensorValue>=666){
    sensorValue=10;
  }
  if(distance>500)
    distance=0;
  Serial.print("pot: ");
  Serial.println(sensorValue);
  Serial.print("Distance: ");
  distance=distance-sensorValue;
  Serial.println(distance);
  if(distance<=10){
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
  }else if(distance<=20&&distance>10){
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);    
  }else{
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);   
  }
  delay(500);
    



}
