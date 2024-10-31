#include <Servo.h>

Servo myServo;  // Crea un objeto servo

const int trigPin = 10;  // Pin Trigger del sensor ultrasónico
const int echoPin = 11;  // Pin Echo del sensor ultrasónico

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serie
  myServo.attach(12);  // Conecta el servo al pin 12
  pinMode(trigPin, OUTPUT);  // Configura el pin de Trigger como salida
  pinMode(echoPin, INPUT);   // Configura el pin de Echo como entrada
}

void loop() {
  // Mueve el servo de 0 a 180 grados
  for (int pos = 0; pos <= 90; pos += 1) {
    myServo.write(pos);  // Mueve el servo a la posición 'pos'
    delay(15);  // Espera 15 ms para permitir que el servo se mueva
  }
 long duration, distance;

  // Limpia el pin de Trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Envía un pulso de 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee el tiempo de duración del pulso
  duration = pulseIn(echoPin, HIGH);
  // Calcula la distancia en cm
  distance = duration * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  //delay(1000);  // Espera medio segundo antes de la siguiente lectura

  // Mueve el servo de 180 a 0 grados
  for (int pos = 0; pos >= 40; pos -= 1) {
    myServo.write(pos);  // Mueve el servo a la posición 'pos'
    delay(5);  // Espera 15 ms para permitir que el servo se mueva
  }
}
