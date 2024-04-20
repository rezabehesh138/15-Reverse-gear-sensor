/*    
   * Ultrasonic Sensor HC-SR05/4 and Arduino
    * by Hanie Kiani
*  https://electropeak.com/learn
    */
long duration;
int distance;

const int trig = 9;
const int echo = 10;
int LED = 6;

void setup() {
  pinMode(trig, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echo, INPUT);   // Sets the echoPin as an Input
  Serial.begin(9600);     // Starts the serial communication
}
void loop() {
  distance = calculateDistance();
  Serial.print("distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance > 30) {
    digitalWrite(LED, LOW);}
  else if (distance < 10) {
    digitalWrite(LED, HIGH);
  } else {
    int Range = map(distance, 10, 30, 255, 0);
      analogWrite(LED, Range);
  }
  //delay(500);
}
int calculateDistance() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;
  return distance;
}