// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 00: Primeiro Contato com o Wokwi Web (O LED do Painel)
// 
// Aluno: _____________________________________ Data: ___/___/_____

// -----------------------------------------------------------------------------
// APRESENTAÇÃO E DIRETRIZES:
// O objetivo desta atividade de integração é aprender a navegar e operar a 
// interface do simulador online Wokwi Web. Você rodará seu primeiro código
// no microcontrolador Arduino e fará pequenas modificações para entender como
// o software controla fisicamente o hardware em tempo real.
// -----------------------------------------------------------------------------

void setup() {
  // Configura o pino digital 13 (onde conectamos o LED vermelho) como saída (OUTPUT).
  // Dica de hardware: o Arduino Uno possui um LED interno embutido na placa ligado a esse mesmo pino!
  pinMode(13, OUTPUT);
}

void loop() {
  // Ligar o LED enviando sinal lógico ALTO (HIGH = 5 Volts) para o pino 13
  digitalWrite(13, HIGH);
  
  // Aguardar 1000 milissegundos (1 segundo) com o LED ligado
  delay(1000);
  
  // Desligar o LED enviando sinal lógico BAIXO (LOW = 0 Volts) para o pino 13
  digitalWrite(13, LOW);
  
  // Aguardar 1000 milissegundos (1 segundo) com o LED desligado
  delay(1000);
}
