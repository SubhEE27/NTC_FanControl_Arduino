int pot = A0;
int fan = 11;

void setup() {
  pinMode(fan, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(pot);
  float v = val * (5.0 / 1023.0);

  if (v < 0.001) v = 0.001;   // avoid divide-by-zero

  float r = (10000 * (5.0 - v)) / v;
  if (r < 1000) r = 1000;     // clamp values
  if (r > 50000) r = 50000;

  // Steinhart–Hart approximation (for 10k NTC, Beta = 3950)
  float temp;
  temp = r / 10000.0;                      
  temp = log(temp);
  temp /= 3950.0;                            
  temp += 1.0 / (25 + 273.15);             
  temp = 1.0 / temp;                         
  temp -= 273.15;                          

  Serial.print("  Temp: "); 
  Serial.println(temp);

  // Fan control with 3 states
  Serial.print("Fan State: ");
  if (temp < 25) {
    analogWrite(fan, 0);
    Serial.println("Off");
  } else if (temp >= 25 && temp < 30) {
    analogWrite(fan, 100);
    Serial.println("Half ON");
  } else {
    analogWrite(fan, 255);
    Serial.println("Full ON");
  }

  delay(500);
}
