// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 02: Cálculo de Aluguel de Carro com Display LCD (Original Tinkercad)
// 
// Aluno: _____________________________________ Data: ___/___/_____
//
// -----------------------------------------------------------------------------
// ETAPA 1 (Intermediária): Faça a leitura de A0 (dias, 1 a 30) e A1 (km, 1 a 1000).
//                          Calcule o custo total (diária 30.0 + 0.01 por km) com 10%
//                          de desconto e imprima no LCD 16x2.
//
// ETAPA 2 (Final - Desafio): Elimine a oscilação do display LCD utilizando a
//                             condição de atualização sob variação dupla.
// -----------------------------------------------------------------------------
//
// 🧠 REFLEXÃO TÉCNICA (Obrigatório):
// 1. Por que o cálculo de ponto flutuante (uso do tipo 'float') deve ser feito com
//    cuidado no Arduino Uno (microcontrolador de 8 bits AVR) em comparação com
//    operações matemáticas com inteiros?
// 2. Como a condição composta '||' (OR) ajuda a atualizar o LCD apenas quando
//    houver mudança real em um dos dois potenciômetros?
//
// Resposta: ___________________________________________________________________
// _____________________________________________________________________________
// _____________________________________________________________________________

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos do Arduino: RS, Enable, D4, D5, D6, D7
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

// TODO: Defina as variáveis globais de estado para reter a última leitura de tempo e distância
int ultimoTempo = -1;
int ultimaDistancia = -1;

void setup() {
  // Inicializa o LCD de 16 colunas e 2 linhas
  LCD.begin(16, 2);
  
  // TODO (Etapa 2): Desenhe o layout estático inicial uma única vez
  // Dica: LCD.print("T:   d  D:    km");
}

void loop() {
  // TODO: Leia e mapeie o potenciômetro 1 (A0) para a faixa de 1 a 30 dias (tempo)
  int tempo = 0; 
  
  // TODO: Leia e mapeie o potenciômetro 2 (A1) para a faixa de 1 a 1000 km (distancia)
  int distancia = 0; 

  // TODO (Etapa 2): Estruture a condição 'if' composta para comparar se
  // o 'tempo' é diferente de 'ultimoTempo' OU se a 'distancia' é diferente de 'ultimaDistancia'.
  
  // {
    // TODO: Calcule o valor total da diária com 10% de desconto
    // Fórmula: (tempo * 30.0 + distancia * 0.01) * 0.90
    float valorTotal = 0.0;
    
    // TODO: Posicione o cursor e exiba o tempo atual no LCD
    // TODO: Posicione o cursor e exiba a distância atual no LCD
    // TODO: Posicione o cursor e exiba o valor total a pagar no LCD
    
    // Dica (Etapa 2): Sempre limpe com espaços vazios ("    ") antes de imprimir
    // os novos números para não embolar os dígitos do display.
    
    // TODO (Etapa 2): Atualize as variáveis de estado para o próximo ciclo
  // }
  
  delay(100);
}
