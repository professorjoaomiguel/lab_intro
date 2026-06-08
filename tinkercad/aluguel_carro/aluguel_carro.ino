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

// TODO: Defina as variáveis globais de estado para reter a última leitura de tempo, distância e categoria.
// Elas iniciam em -1 para forçar a primeira escrita na tela logo ao inicializar o loop().
int ultimoTempo = -1;
int ultimaDistancia = -1;
int ultimaCategoria = -1;

// TODO: Defina o pino digital conectado à chave slide (Pino 9).
int pinoChave = 9;

void setup() {
  // Inicializa o LCD com 16 colunas e 2 linhas
  LCD.begin(16, 2);
  
  // TODO: Configure o pino da chave slide como entrada utilizando resistor de pull-up interno.
  // Dica de pesquisa: use 'pinMode(pino, INPUT_PULLUP)'.
  
  // TODO (Etapa 2): Desenhe o layout estático inicial na tela de uma única vez.
  // Escrever as etiquetas aqui economiza processamento e evita cintilações no LCD.
  // Dica: Use LCD.setCursor(coluna, linha) e LCD.print("texto")
  // LCD.setCursor(0, 0);
  // LCD.print("T:   d K:     ");
  // LCD.setCursor(0, 1);
  // LCD.print("Total: R$       ");
}

void loop() {
  // TODO: Leia o estado da chave slide (POP/SUV) conectada ao pino digital 9.
  // Dica de pesquisa: use 'digitalRead(pino)'.
  int categoria = 0; 

  // TODO: Leia e mapeie o potenciômetro 1 (conectado em A0) para a faixa de 1 a 30 dias (tempo).
  // Dica: map(analogRead(pino), 0, 1023, min, max)
  int tempo = 0; 
  
  // TODO: Leia e mapeie o potenciômetro 2 (conectado em A1) para a faixa de 1 a 1000 km (distancia).
  int distancia = 0; 

  // TODO (Etapa 2): Filtro de Estado Composto.
  // Crie um bloco 'if' que verifica se houve mudança nas entradas analógicas ou na chave slide:
  // if (tempo != ultimoTempo || distancia != ultimaDistancia || categoria != ultimaCategoria)
  
  // {
    // TODO: Determine os valores da diária e da taxa de km rodado baseando-se no estado da chave.
    // - Se categoria for LOW (Popular - POP):
    //   -> Diária = R$ 30.00, Km = R$ 0.01.
    // - Se categoria for HIGH (SUV):
    //   -> Diária = R$ 80.00, Km = R$ 0.05.
    float diaria = 0.0;
    float taxaKm = 0.0;
    
    // TODO: Calcule o valor total da locação com 10% de desconto.
    // Fórmula de negócio: (tempo * diaria + distancia * taxaKm) * 0.90
    float valorTotal = 0.0;
    
    // TODO: Posicione o cursor e exiba a quantidade de dias no LCD (Linha 0).
    // Dica: Posicione na coluna 2 da linha 0. Limpe com espaços ("  ") antes de escrever.
    
    // TODO: Posicione o cursor e exiba a distância percorrida no LCD (Linha 0).
    // Dica: Posicione na coluna 8 da linha 0. Limpe com espaços ("    ") antes de escrever.
    
    // TODO: Posicione o cursor e exiba o rótulo da categoria ("POP" ou "SUV") na linha 0.
    // Dica: Posicione na coluna 13 da linha 0.
    
    // TODO: Posicione o cursor e exiba o valor total formatado no LCD (Linha 1).
    // Dica: Posicione na coluna 10 da linha 1. Use LCD.print(valorTotal, 2) para duas casas decimais.
    
    // TODO (Etapa 2): Atualize as variáveis de estado para reter as leituras atuais.
    
  // }
  
  delay(100); // Pausa para estabilidade de hardware
}
