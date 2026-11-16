const int trigPin = 22;
const int echoPin = 23; 
const int buzzerPin = 21; 

const int v1 = 13;
const int v2 = 12;
const int v3 = 14;
const int a1 = 27;
const int a2 = 26;
const int a3 = 25;
const int r1 = 33;
const int r2 = 32;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT); 
  pinMode(buzzerPin, OUTPUT); 

  pinMode(v1, OUTPUT);
  pinMode(v2, OUTPUT);
  pinMode(v3, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);

  pinMode(echoPin, INPUT);  
}

void loop() {
  //  Disparar pulso ultrasónico por Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //  Medir cuánto tarda en volver por Echo
  unsigned long duracion = pulseIn(echoPin, HIGH, 30000UL);

  if (duracion == 0) {
    Serial.println("Sin lectura (revisa cables VCC 5V, GND, Trig G22 y Echo G23)");
    digitalWrite(v1, LOW);
    digitalWrite(v2, LOW);
    digitalWrite(v3, LOW);
    digitalWrite(a1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(buzzerPin, HIGH); // Pita si no detecta nada cerca
    delay(300);
  } else {
    long distancia = duracion / 58.2;

    if (distancia > 0 && distancia <= 10) {
      // Muy cerca solo verdes encendido
      digitalWrite(v1, HIGH);
      digitalWrite(v2, HIGH);
      digitalWrite(v3, HIGH);
      digitalWrite(a1, LOW);
      digitalWrite(a2, LOW);
      digitalWrite(a3, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);

      digitalWrite(buzzerPin, LOW);
      delay(300);
    } else if (distancia > 10 && distancia <= 17) {
      // Cerca dos verdes 
      digitalWrite(v1, HIGH);
      digitalWrite(v2, HIGH);
      digitalWrite(v3, LOW);
      digitalWrite(a1, LOW);
      digitalWrite(a2, LOW);
      digitalWrite(a3, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);

      digitalWrite(buzzerPin, LOW);
      delay(300);
    } else if (distancia > 17 && distancia <= 24) {
      // Cerca-medio un verde + pitido muy lento
      digitalWrite(v1, HIGH);
      digitalWrite(v2, LOW);
      digitalWrite(v3, LOW);
      digitalWrite(a1, LOW);
      digitalWrite(a2, LOW);
      digitalWrite(a3, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);

      digitalWrite(buzzerPin, HIGH);
      delay(80);
      digitalWrite(buzzerPin, LOW);
      delay(500);
    } else if (distancia > 24 && distancia <= 31) {
      // Medio tres amarillos + pitido lento
      digitalWrite(v1, LOW);
      digitalWrite(v2, LOW);
      digitalWrite(v3, LOW);
      digitalWrite(a1, HIGH);
      digitalWrite(a2, HIGH);
      digitalWrite(a3, HIGH);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);

      digitalWrite(buzzerPin, HIGH);
      delay(100);
      digitalWrite(buzzerPin, LOW);
      delay(350);
    } else if (distancia > 31 && distancia <= 38) {
      // Medio dos amarillos + pitido moderado
      digitalWrite(v1, LOW);
      digitalWrite(v2, LOW);
      digitalWrite(v3, LOW);
      digitalWrite(a1, HIGH);
      digitalWrite(a2, HIGH);
      digitalWrite(a3, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);

      digitalWrite(buzzerPin, HIGH);
      delay(100);
      digitalWrite(buzzerPin, LOW);
      delay(220);
    } else if (distancia > 38 && distancia <= 45) {
      // Medio-lejos un amarillo + pitido rápido
      digitalWrite(v1, LOW);
      digitalWrite(v2, LOW);
      digitalWrite(v3, LOW);
      digitalWrite(a1, HIGH);
      digitalWrite(a2, LOW);
      digitalWrite(a3, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);

      digitalWrite(buzzerPin, HIGH);
      delay(120);
      digitalWrite(buzzerPin, LOW);
      delay(120);
    } else if (distancia > 45 && distancia <= 52) {
      // Lejos dos rojos + pitido continuo
      digitalWrite(v1, LOW);
      digitalWrite(v2, LOW);
      digitalWrite(v3, LOW);
      digitalWrite(a1, LOW);
      digitalWrite(a2, LOW);
      digitalWrite(a3, LOW);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, HIGH);

      digitalWrite(buzzerPin, HIGH);
      delay(300);
    } else if (distancia > 52 && distancia <= 60) {
      // Muy lejos solo un rojo + pitido continuo
      digitalWrite(v1, LOW);
      digitalWrite(v2, LOW);
      digitalWrite(v3, LOW);
      digitalWrite(a1, LOW);
      digitalWrite(a2, LOW);
      digitalWrite(a3, LOW);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, LOW);

      digitalWrite(buzzerPin, HIGH);
      delay(300);
    } else {
      // Fuera de rango  60 cm pitido continuo
      digitalWrite(v1, LOW);
      digitalWrite(v2, LOW);
      digitalWrite(v3, LOW);
      digitalWrite(a1, LOW);
      digitalWrite(a2, LOW);
      digitalWrite(a3, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);

      digitalWrite(buzzerPin, HIGH);
      delay(300);
    }

    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
  }
}
