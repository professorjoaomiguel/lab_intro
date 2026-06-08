// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 02: Cálculo de Aluguel de Carro com Display LCD
// 
// Aluno: _____________________________________ Data: ___/___/_____
//
// -----------------------------------------------------------------------------
// APRESENTAÇÃO E DIRETRIZES:
// O objetivo desta atividade é simular as duas entradas de um sistema de aluguel de carros
// (Locadora "Sai da Frente") utilizando dois potenciômetros. O programa calcula o custo total
// aplicando um desconto de 10% e exibe tudo formatado no LCD 16x2 de maneira otimizada.
//
// ETAPAS DE DESENVOLVIMENTO:
// - ETAPA 1 (Intermediária):
//   1. Leia o potenciômetro 1 (A0) e converta para Tempo (1 a 30 dias).
//   2. Leia o potenciômetro 2 (A1) e converta para Distância (1 a 1000 km).
//   3. Calcule o valor total da locação com a fórmula:
//      -> Custo = (Dias * 30.0 + Km * 0.01) * 0.90 (desconto de 10%)
//   4. Imprima os valores numéricos de dias, km e o custo total no LCD no layout:
//      T: XXd  D: XXXkm
//      Total: R$ XXX.XX
//
// - ETAPA 2 (Final - Desafio):
//   1. Elimine o flicker escrevendo os rótulos de texto fixo ("T:   d  D:    km"
//      e "Total: R$       ") uma única vez dentro do setup().
//   2. No loop(), implemente um Filtro de Estado duplo: atualize as saídas numéricas 
//      do LCD apenas se o valor atual de tempo for diferente de 'ultimoTempo' 
//      OU se a distância atual for diferente de 'ultimaDistancia' (operador lógico OR '||').
//   3. Limpe as casas numéricas dinâmicas com espaços em branco ("  " ou "    ") antes
//      de imprimir para apagar dígitos órfãos residuais.
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

// TODO: Defina as variáveis globais de estado para reter a última leitura de tempo e distância.
// Elas iniciam em -1 para forçar a primeira escrita na tela logo ao inicializar o loop().
int ultimoTempo = -1;
int ultimaDistancia = -1;

void setup() {
  // Inicializa o LCD com 16 colunas e 2 linhas
  LCD.begin(16, 2);
  
  // TODO (Etapa 2): Desenhe o layout estático inicial na tela de uma única vez.
  // Escrever as etiquetas aqui economiza processamento e evita cintilações no LCD.
  // Dica: Use LCD.setCursor(coluna, linha) e LCD.print("texto")
  // LCD.setCursor(0, 0);
  // LCD.print("T:   d  D:    km");
  // LCD.setCursor(0, 1);
  // LCD.print("Total: R$       ");
}

void loop() {
  // TODO: Leia e mapeie o potenciômetro 1 (conectado em A0) para a faixa de 1 a 30 dias (tempo).
  // Dica: map(analogRead(pino), 0, 1023, min, max)
  int tempo = 0; 
  
  // TODO: Leia e mapeie o potenciômetro 2 (conectado em A1) para a faixa de 1 a 1000 km (distancia).
  int distancia = 0; 

  // TODO (Etapa 2): Filtro de Estado Composto.
  // Crie um bloco 'if' que verifica se houve mudança nas entradas:
  // if (tempo != ultimoTempo || distancia != ultimaDistancia)
  
  // {
    // TODO: Calcule o valor total da locação com 10% de desconto.
    // Fórmula de negócio: (tempo * 30.0 + distancia * 0.01) * 0.90
    // ATENÇÃO: Use números em float (como 30.0 e 0.01) para que as operações ocorram com precisão decimal.
    float valorTotal = 0.0;
    
    // TODO: Posicione o cursor e exiba a quantidade de dias no LCD (Linha 0).
    // Dica: Posicione na coluna 2 da linha 0. Limpe com espaços ("  ") antes de escrever.
    
    // TODO: Posicione o cursor e exiba a distância percorrida no LCD (Linha 0).
    // Dica: Posicione na coluna 10 da linha 0. Limpe com espaços ("    ") antes de escrever.
    
    // TODO: Posicione o cursor e exiba o valor total formatado no LCD (Linha 1).
    // Dica: Posicione na coluna 10 da linha 1. Use LCD.print(valorTotal, 2) para duas casas decimais.
    
    // TODO (Etapa 2): Atualize as variáveis de estado para reter as leituras atuais.
    
  // }
  
  delay(100); // Pausa para estabilidade de hardware
}
