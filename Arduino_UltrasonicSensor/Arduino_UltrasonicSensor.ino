#define trigPin 9      // The pin on which the ultrasonic sensor trig pin is connected
#define echoPin 10     // The pin on which the ultrasonic sensor echo pin is connected

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);   // Set the trigger pin low
  delayMicroseconds(2);          // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH);  // Set the trigger pin high
  delayMicroseconds(10);         // Wait for 10 microseconds
  digitalWrite(trigPin, LOW);   // Set the trigger pin low
  
  long duration = pulseIn(echoPin, HIGH);  // Measure the duration of the echo pulse
  int distance = duration / 58;            // Convert the duration to distance in centimeters
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm\n");       // Newline character for formatting
  
  delay(500);  // Wait for 500 milliseconds before taking the next measurement
}
