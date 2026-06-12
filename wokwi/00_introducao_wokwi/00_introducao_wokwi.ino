// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 00: Primeiro Contato com o Wokwi Web (O LED do Painel)
// 
// IMPORTANTE: Preencha seu nome e a data de realização abaixo:
// Aluno: <PREENCHA SEU NOME COMPLETO AQUI>  Data: DD/MM/AAAA

// -----------------------------------------------------------------------------
// APRESENTAÇÃO E DIRETRIZES:
// O objetivo desta atividade de integração é aprender a navegar e
// operar a interface do simulador online Wokwi Web. Você rodará
// seu primeiro código no microcontrolador Arduino e fará pequenas
// modificações para entender como o software controla fisicamente
// o hardware em tempo real e como se comunicar com o computador
// através do Monitor Serial.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// PINO 13 → LED Vermelho (LED do painel do Arduino)
// PINO 12 → LED Verde (LED externo adicionado por você)
// Os dois LEDs piscam de forma alternada:
//   quando um está LIGADO, o outro está DESLIGADO.
// -----------------------------------------------------------------------------

void setup() {
  // Configura o pino 13 (LED vermelho) como saída (OUTPUT).
  pinMode(13, OUTPUT);

  // Configura o pino 12 (LED verde) como saída (OUTPUT).
  pinMode(12, OUTPUT);

  // Inicializa a comunicação serial a 9600 bits por segundo.
  // Essa função "abre o canal de conversa" entre o Arduino
  // e o Monitor Serial do seu computador.
  Serial.begin(9600);
}

void loop() {
  // --- FASE 1: LED vermelho LIGADO, LED verde DESLIGADO ---
  digitalWrite(13, HIGH); // Liga LED vermelho (5V no pino 13)
  digitalWrite(12, LOW);  // Desliga LED verde (0V no pino 12)

  Serial.println(">> LED VERMELHO ligado | LED VERDE desligado");

  // Aguarda 1000 ms (1 segundo) neste estado
  delay(1000);

  // --- FASE 2: LED vermelho DESLIGADO, LED verde LIGADO ---
  digitalWrite(13, LOW);  // Desliga LED vermelho (0V no pino 13)
  digitalWrite(12, HIGH); // Liga LED verde (5V no pino 12)

  Serial.println(">> LED VERMELHO desligado | LED VERDE ligado");

  // Aguarda 1000 ms (1 segundo) neste estado
  delay(1000);
}
