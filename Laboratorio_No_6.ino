#include <Stepper.h>  // incluye libreria stepper

Stepper motor1(2048, 8, 10, 9, 11);  // pasos completos

String a, b, c;
int Grado, Direccion, Velocidad;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (!Serial.available());
  a = Serial.parseInt();
  Grado = a.toInt();

  while (!Serial.available());
  b = Serial.parseInt();
  Velocidad = b.toInt();

  while (!Serial.available());
  c = Serial.parseInt();
  Direccion = c.toInt();

  Serial.print("Grados: ");
  Serial.println(a);
  Serial.print("Velocidad: ");
  Serial.println(b);
  Serial.print("Direccion: ");
  Serial.println(c);

  Motor(Grado, Velocidad, Direccion);
}

void Motor(int a, int b, int c) {
  int Grados = a * 6;
  if ((b >= 1) && (b <= 10)) {
    if (c == 1) {
      motor1.setSpeed(b);
      motor1.step(Grados * -1);
      delay(3000);
    } else if (c == 2) {
      motor1.setSpeed(b);
      motor1.step(Grados);
      delay(3000);
    }
  }
}
