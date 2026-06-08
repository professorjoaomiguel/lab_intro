// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 01: Monitor Térmico das Baterias (VoltLog - LCD 20x4)
// 
// Aluno: _____________________________________ Data: ___/___/_____
//
// -----------------------------------------------------------------------------
// APRESENTAÇÃO E CONTEXTO:
// Na VoltLog, startup de logística urbana inteligente, os utilitários de entrega 
// elétricos utilizam bancos de baterias de íons de lítio que geram muito calor sob carga.
// Para evitar degradação e riscos de incêndio (thermal runaway), o painel eletrônico
// da cabine do motorista (IHM) monitora constantemente a temperatura das células.
//
// ETAPAS DE DESENVOLVIMENTO:
// - ETAPA 1 (Intermediária): 
//   1. Configure os pinos digitais dos LEDs de alarme físico como saídas.
//   2. Leia o sensor de temperatura analógico em A0 (representado pelo potenciômetro).
//   3. Converta a leitura (0-1023) para Celsius (0-60 °C) usando a função map().
//   4. Calcule o equivalente em Fahrenheit usando a fórmula física (F = C * 1.8 + 32).
//   5. Imprima Celsius e Fahrenheit no LCD 20x4 do painel do motorista.
//   *(Nesta etapa, o uso de lcd.clear() causará oscilação/flicker na tela).*
//
// - ETAPA 2 (Final - Desafio):
//   1. Elimine o flicker escrevendo os rótulos estáticos no setup() de uma única vez.
//      -> Linha 0: "PAINEL DE TEMPERATURA"
//      -> Linha 1: "Celsius:       oC"
//      -> Linha 2: "Fahrenheit:    oF"
//      -> Linha 3: "Status: "
//   2. No loop(), envolva toda a escrita do display e controle dos LEDs dentro de
//      uma condição 'if' que verifica se o valor atual de 'tempC' mudou em relação
//      a 'ultimoTempC' (Filtro de Estado).
//   3. Lógica de Alarme da Bateria: se a temperatura atingir 40 °C ou mais:
//      -> Acenda o LED Vermelho, apague o LED Verde e exiba "ALERTA" no LCD. 
//      -> Caso contrário (temperatura segura), mantenha o LED Verde aceso, LED Vermelho
//         apagado e exiba "OK" no LCD.
//   4. Limpe o espaço numérico com espaços em branco ("    ") antes de imprimir
//      novos números para evitar resíduos numéricos antigos na tela.
// -----------------------------------------------------------------------------
//
// 🧠 REFLEXÃO TÉCNICA (Obrigatório):
// 1. Por que atualizar o display LCD continuamente a cada iteração do loop() causa 
//    o efeito visual de piscada (flicker)? 
// 2. Como a variável global de estado (como 'ultimoTempC') resolve esse problema?
// 3. Após realizar o desafio opcional (mudar o limite de alerta de 40 °C para 43 °C), 
//    explique qual linha de código você precisou alterar e o que mudou no circuito físico.
//
// Resposta: ___________________________________________________________________
// _____________________________________________________________________________
// _____________________________________________________________________________

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos do Arduino: RS, Enable, D4, D5, D6, D7
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

// TODO: Defina as variáveis globais de estado necessárias para a Etapa 2.
// Elas armazenam o último valor impresso para podermos fazer comparações.
int ultimoTempC = -1; 

// TODO: Defina os pinos correspondentes para os LEDs vermelho (alarme) e verde (seguro).
// Conectamos o LED Vermelho no pino digital 7 e o LED Verde no pino digital 8.
int pinoVermelho = 7;
int pinoVerde = 8;

void setup() {
  // Inicializa o LCD configurando a resolução para 20 colunas e 4 linhas
  LCD.begin(20, 4);
  
  // TODO: Configure os pinos digitais dos LEDs de alarme como saídas.
  // Dica de pesquisa: use a função 'pinMode(pino, modo)' com o modo 'OUTPUT'.
  
  // TODO (Etapa 2): Escreva os rótulos fixos (labels) que nunca mudam no display.
  // Escrevê-los aqui garante que eles não sejam apagados e reescritos no loop().
  // Dica: Use LCD.setCursor(coluna, linha) e LCD.print("texto")
  // Exemplo:
  // LCD.setCursor(0, 0);
  // LCD.print("PAINEL DE TEMPERATURA");
  // LCD.setCursor(0, 1);
  // LCD.print("Celsius:       oC");
  // LCD.setCursor(0, 2);
  // LCD.print("Fahrenheit:    oF");
  // LCD.setCursor(0, 3);
  // LCD.print("Status: ");
}

void loop() {
  // TODO: Realize a leitura analógica do sensor de temperatura (A0).
  // Dica de pesquisa: use a função 'analogRead(pino)'. Ela retorna um inteiro de 0 a 1023.
  int potenciometro = 0; 
  
  // TODO: Converta o valor bruto lido para graus Celsius (escala de 0 a 60).
  // Dica de pesquisa: use a função 'map(valor, deMin, deMax, paraMin, paraMax)'.
  int tempC = 0; 

  // TODO (Etapa 2): Implemente o Filtro de Estado.
  // Crie uma estrutura condicional 'if (tempC != ultimoTempC)' para envelopar os cálculos,
  // escrita no display e acionamento de LEDs. Isso otimiza o uso da CPU e previne o flicker.
  // (Para validar a Etapa 1, você pode fazer sem este 'if').
  
  // {
    // TODO: Calcule a conversão matemática de Celsius para Fahrenheit.
    // Fórmula física: Fahrenheit = Celsius * (9.0 / 5.0) + 32.0.
    // ATENÇÃO: use '9.0' e '5.0' para indicar números de ponto flutuante, evitando divisão inteira.
    float tempF = 0.0;
    
    // TODO (Etapa 1): Posicione o cursor e exiba o valor de Celsius na Linha 1 (coluna 13).
    // Dica: Use LCD.setCursor(coluna, linha) para ir até o local correto.
    // Lembre-se (Etapa 2) de imprimir espaços em branco ("   ") para limpar resíduos antigos.
    
    // TODO (Etapa 1): Posicione o cursor e exiba o valor de Fahrenheit na Linha 2 (coluna 13).
    // Dica: LCD.print(tempF, 1) exibe o valor float com apenas 1 casa decimal.
    
    // TODO (Etapa 2): Controle dos LEDs de Alarme e Status no LCD baseado no limiar de 40 °C.
    // Dica de pesquisa: use 'digitalWrite(pino, estado)' com 'HIGH' e 'LOW'.
    // - Se a temperatura atual for igual ou maior que 40 °C:
    //   -> Acenda o LED Vermelho e apague o LED Verde.
    //   -> Vá até a coluna 8 da linha 3 e imprima "ALERTA".
    // - Caso contrário (menor que 40 °C):
    //   -> Apague o LED Vermelho e acenda o LED Verde.
    //   -> Vá até a coluna 8 da linha 3 e imprima "OK" seguido de espaços para limpar.
    
    // TODO (Etapa 2): Atualize a variável de controle de estado anterior.
    // Isso garante que no próximo ciclo a comparação condicional funcione.
    
  // }
  
  delay(100); // Pequena pausa (100ms) para estabilização de leitura do sensor
}
