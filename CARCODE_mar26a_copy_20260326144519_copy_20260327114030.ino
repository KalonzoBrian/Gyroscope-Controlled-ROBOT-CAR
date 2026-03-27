// Motor A (Left)
int enA = 9; int in1 = 8; int in2 = 7;
// Motor B (Right)
int enB = 3; int in3 = 5; int in4 = 4;

void setup() {
  Serial.begin(9600); // Bluetooth logic
  
  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);

  stopMotors(); 
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    if (command == 'F') moveForward();
    else if (command == 'B') moveBackward();
    else if (command == 'L') turnLeft();
    else if (command == 'R') turnRight();
    else if (command == 'S') stopMotors();
  }
}

void moveForward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, 200);   analogWrite(enB, 200); 
}

void moveBackward() {
  digitalWrite(in1, LOW);  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);  digitalWrite(in4, HIGH);
  analogWrite(enA, 200);   analogWrite(enB, 200);
}

void turnLeft() {
  // Tank steer: Left back, Right forward
  digitalWrite(in1, LOW);  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, 150);   analogWrite(enB, 150);
}

void turnRight() {
  // Tank steer: Left forward, Right back
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);  digitalWrite(in4, HIGH);
  analogWrite(enA, 150);   analogWrite(enB, 150);
}

void stopMotors() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
  analogWrite(enA, 0);   analogWrite(enB, 0);
}