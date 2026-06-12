// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 00: Gabarito — LEDs alternados (pinos 12 e 13)
//
// SOLUÇÃO DE REFERÊNCIA — uso exclusivo do professor.

// PINO 13 → LED Vermelho
// PINO 12 → LED Verde
// Quando um está LIGADO, o outro está DESLIGADO.

void setup() {
  pinMode(13, OUTPUT); // LED vermelho como saída
  pinMode(12, OUTPUT); // LED verde como saída

  // Abre canal serial a 9600 bps
  Serial.begin(9600);
}

void loop() {
  // FASE 1: vermelho LIGADO, verde DESLIGADO
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  Serial.println(
    "VERMELHO ligado | VERDE desligado"
  );
  delay(1000);

  // FASE 2: vermelho DESLIGADO, verde LIGADO
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  Serial.println(
    "VERMELHO desligado | VERDE ligado"
  );
  delay(1000);
}
