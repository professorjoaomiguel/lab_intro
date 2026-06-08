// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 03: Telemetria de Combustível e Autonomia (LCD 20x4)
// 
// Aluno: _____________________________________ Data: ___/___/_____
//
// -----------------------------------------------------------------------------
// ETAPA 1 (Intermediária): Leia o nível do tanque (A0, 0-50L) e consumo (A1, 0-20 L/h).
//                          Calcule a autonomia em horas (cuidado com consumo = 0!).
//                          Exiba os valores numéricos no LCD 20x4.
//
// ETAPA 2 (Final - Desafio): Evite o flicker (redesenho apenas sob alteração).
//                             Desenhe a barra de progresso do tanque de 10 segmentos.
//                             Acione o LED vermelho (Pino 7) se o nível cair abaixo de 5L.
// -----------------------------------------------------------------------------
//
// 🧠 REFLEXÃO TÉCNICA (Obrigatório):
// 1. O que acontece com o software se tentarmos dividir por zero no cálculo de 
//    autonomia? Como o condicional 'if' de proteção resolve essa falha crítica?
// 2. Qual a vantagem ergonômica de exibir uma barra de progresso visual em um 
//    painel de telemetria industrial, em comparação com apenas números?
//
// Resposta: ___________________________________________________________________
// _____________________________________________________________________________
// _____________________________________________________________________________

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos do Arduino: RS, Enable, D4, D5, D6, D7
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

int pinoAlerta = 7;

// TODO: Declare as variáveis globais de estado necessárias para reter os valores anteriores
int ultimoTempo = -1; // você pode usar variáveis para volume e consumo anterior

void setup() {
  LCD.begin(20, 4);
  pinMode(pinoAlerta, OUTPUT);
  
  // TODO (Etapa 2): Desenhe a moldura e textos fixos uma única vez
  // LCD.setCursor(0, 0);
  // LCD.print("  PAINEL TELEMETRIA ");
}

void loop() {
  // TODO: Leia o potenciômetro de nível (A0) e mapeie para 0 a 50 litros
  int potNivel = analogRead(A0);
  float volume = 0.0; // Faça a conversão do potenciômetro para float (0.0 a 50.0)

  // TODO: Leia o potenciômetro de consumo (A1) e mapeie para 0 a 20 L/h
  int potConsumo = analogRead(A1);
  float consumo = 0.0; // Faça a conversão do potenciômetro para float (0.0 a 20.0)

  // TODO (Etapa 2): Condição de atualização sob variação (Filtro de Estado)
  // {
    
    // TODO: Calcule a autonomia (Volume / Consumo)
    // ATENÇÃO: Faça a proteção de software para evitar a divisão por zero!
    float autonomia = 0.0;

    // TODO: Exiba o volume e consumo no LCD (Linha 1)
    
    // TODO: Desenhe a barra de progresso gráfica na Linha 2
    // Dica: Calcule a porcentagem de combustível: percentual = (volume / 50.0) * 100.0
    // O número de blocos (0 a 10) será: blocos = percentual / 10
    // Use um loop 'for' para escrever os caracteres de bloco (char(255)) e espaços.
    
    // TODO: Exiba a autonomia em horas na Linha 3
    
    // TODO: Lógica de Reserva (Volume < 5L)
    // Se estiver na reserva, ligue/pisque o pino de alerta (7) e exiba "RESERVA CRITICA" na Linha 3.
    // Senão, mantenha o pino de alerta desligado e apague o aviso.
    
  // }
  
  delay(100);
}
