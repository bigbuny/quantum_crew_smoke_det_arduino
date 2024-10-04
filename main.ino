#define sensor A0
#define buzz 4
#define red 6
#define green 5

int gas, CO2level;

void setup() {
  pinMode(buzz, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);

  Serial.println("  CO2 Meter   ");
  delay(1000);
  Serial.println("heating up coil");
}

void loop() {
  gas = analogRead(sensor);
  CO2level = gas - 200;
  CO2level = map(CO2level, 0, 1024, 400, 5000);

  Serial.println(gas);
  Serial.println("CO2 level is:");
  Serial.println(CO2level);
  Serial.println(" ppm");

  if ((CO2level >= 350) && (CO2level <= 1400)) {
    Serial.println(" Safe air ");
    digitalWrite(buzz, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  }
  else if ((CO2level >= 1400) && (CO2level <= 2000)) {
    digitalWrite(buzz, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    Serial.println("Not safe for environment ");
  }
  else {
    Serial.println(" Danger! Highly health threatening");
    digitalWrite(buzz, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  }

  delay(3000);
}
