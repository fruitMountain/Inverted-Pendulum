//Arduino
//Read basic accelerometer data

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Temporary Variables to store the voltage readouts
  float A = analogRead(A0);
  float B = analogRead(A1);
  float C = analogRead(A2);

  // Mapping those Voltages to Sin(theta)
  float X = (A - 330) / 62;
  float Y = (B - 330) / 60;
  float Z = (C - 330) / 71;

  /*
  Serial.print("X = ");
  Serial.print(A);
  Serial.print("\t");
  Serial.println(X);
  Serial.print("Y = ");
  Serial.print(B);
  Serial.print("\t");
  Serial.println(Y);
  Serial.print("Z = ");
  Serial.print(C);
  Serial.print("\t");
  Serial.println(Z);
  */

  Theta = atan2(Y,X);
  Serial.print(Theta);

  delay(500);
}

/*
  -1G = 260
  0 G = 330
  1 G = 390
*/
