// defines pins numbers
const int trigPin = 11;
const int echoPin = 10;
// defines variables
long duration;
int distance;

// Left Motor
const int motorPin1  = 6;  
const int motorPin2  = 9; 
// Right Motor
const int motorPin3  = 3; // Pin  7 of L293
const int motorPin4  = 5;  // Pin  2 of L293

const int maxValue = 255;

//This will run only one time.
void setup(){
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  
  //Set pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop(){
  bothForward();
  int dur = readSonar();
  if (dur < 2500) {
    Serial.print("go turn!");
    spinLeft();
    delay(250);
    //go forward a bit so we're not getting crazy readings from the sonar
    bothForward();
    delay(150);
  }
}

int readSonar() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("duration");
  Serial.println(duration);
  return duration;
}

void stupidPattern() {
  rightForward();
  delay(2000);
  rightBack();
  delay(2000);
}

void bothForward() {
  leftForward();
  rightForward();
}

void bothBack() {
  leftBack();
  rightBack();
}

void spinRight() {
  rightBack();
  leftForward();
}

void spinLeft() {
  rightForward();
  leftBack();
}

void allStop() {
  leftStop();
  rightStop();
}

void leftForward() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, maxValue);
}

void leftBack() {
  analogWrite(motorPin1, maxValue);
  analogWrite(motorPin2, 0);
}

void rightForward() {
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, maxValue);
}

void rightBack() {
  analogWrite(motorPin3, maxValue);
  analogWrite(motorPin4, 0);
}

void leftStop() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
}

void rightStop() {
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
}

