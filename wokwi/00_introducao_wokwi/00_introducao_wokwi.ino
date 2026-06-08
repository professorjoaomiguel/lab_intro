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
// o software controla fisicamente o hardware em tempo real e como se comunicar
// com o computador através do Monitor Serial.
// -----------------------------------------------------------------------------

void setup() {
  // Configura o pino digital 13 (onde conectamos o LED vermelho) como saída (OUTPUT).
  pinMode(13, OUTPUT);
  
  // Inicializa a comunicação serial com velocidade de 9600 bits por segundo (baud rate).
  // Essa função "abre o canal de conversa" entre o Arduino e o Monitor Serial do seu computador.
  Serial.begin(9600);
}

void loop() {
  // Ligar o LED enviando sinal lógico ALTO (HIGH = 5 Volts) para o pino 13
  digitalWrite(13, HIGH);
  
  // Envia uma frase de texto pela porta serial para ser exibida no computador.
  // Essa mensagem viaja na forma de pulsos elétricos (bits) através do cabo virtual.
  Serial.println("LED LIGADO - Enviando sinal HIGH (5V)");
  
  // Aguardar 1000 milissegundos (1 segundo) com o LED ligado
  delay(1000);
  
  // Desligar o LED enviando sinal lógico BAIXO (LOW = 0 Volts) para o pino 13
  digitalWrite(13, LOW);
  
  // Envia outra mensagem indicando o desligamento do LED.
  Serial.println("LED DESLIGADO - Enviando sinal LOW (0V)");
  
  // Aguardar 1000 milissegundos (1 segundo) com o LED desligado
  delay(1000);
}
