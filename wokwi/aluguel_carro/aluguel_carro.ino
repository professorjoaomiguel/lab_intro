// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 02: Computador de Tarifação Dinâmica - Car Sharing (VoltLog - LCD 20x4)
// 
// IMPORTANTE: Preencha seu nome e a data de realização abaixo:
// Aluno: <PREENCHA SEU NOME COMPLETO AQUI>  Data: DD/MM/AAAA
//
// -----------------------------------------------------------------------------
// APRESENTAÇÃO E CONTEXTO:
// A VoltLog aluga seus utilitários elétricos de carga para motoristas de entrega
// parceiros em turnos flexíveis (Car Sharing). O cálculo de tarifa é processado em tempo
// real pelo computador de bordo principal do veículo no encerramento do expediente.
//
// ETAPAS DE DESENVOLVIMENTO:
// - ETAPA 1 (Intermediária):
//   1. Leia o potenciômetro 1 (A0) e converta para Tempo (1 a 30 dias).
//   2. Leia o potenciômetro 2 (A1) e converta para Distância (1 a 1000 km).
//   3. Calcule o valor total da locação com a fórmula padrão de negócio:
//      -> Custo = (Dias * Diária + Km * TaxaKm) * 0.90 (desconto de 10% de fidelidade)
//   4. Imprima os valores de dias, km, a categoria ativa e o custo total no LCD 20x4.
//      *(Nesta etapa, a tela pode piscar devido ao redesenho contínuo no loop).*
//
// - ETAPA 2 (Final - Desafio):
//   1. Elimine o flicker escrevendo os rótulos de texto fixo uma única vez dentro do setup().
//      -> Linha 0: "LOCADORA SAI FRENTE"
//      -> Linha 1: "Tempo:    dias"
//      -> Linha 2: "Dist:     km  [   ]"
//      -> Linha 3: "Total: R$ "
//   2. No loop(), implemente um Filtro de Estado Composto: atualize as saídas numéricas
//      do LCD apenas se algum valor mudou (tempo, distância ou categoria).
//   3. Lógica de Tarifação Dinâmica: leia a chave slide (Pino 9) que define a categoria:
//      -> LOW (Popular - POP): Diária de R$ 30,00 e R$ 0,01 por km.
//      -> HIGH (Utilitário SUV - SUV): Diária de R$ 80,00 e R$ 0,05 por km.
//   4. Limpe as casas numéricas dinâmicas com espaços em branco antes de imprimir novos valores.
// -----------------------------------------------------------------------------
//
// 🧠 REFLEXÃO TÉCNICA (Obrigatório):
// As perguntas desta atividade devem ser respondidas no arquivo 'folha_respostas.md'.
// Preencha suas respostas lá e garanta que o arquivo esteja na entrega final.
// -----------------------------------------------------------------------------

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos do Arduino: RS, Enable, D4, D5, D6, D7
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

// Variáveis globais de estado (usadas na Etapa 2 para o Filtro de Estado)
int ultimoTempo = -1;
int ultimaDistancia = -1;
int ultimaCategoria = -1;

// Pino digital conectado à chave slide seletora de categoria
int pinoChave = 9;

void setup() {
  // Inicializa o LCD com 20 colunas e 4 linhas
  LCD.begin(20, 4);

  // Configure o pino da chave slide como entrada com resistor de pull-up interno.
  // O pull-up interno garante leitura estável (HIGH) quando a chave não está pressionada.
  pinMode(pinoChave, INPUT_PULLUP);

  // ---------------------------------------------------------------------------
  // [INSTRUÇÃO ETAPA 2: Layout Fixo No-Flicker]
  // Escrever os textos fixos aqui no setup() faz com que eles apareçam apenas uma vez.
  // TODO: Ao implementar a Etapa 2, descomente as 8 linhas abaixo:
  // ---------------------------------------------------------------------------
  // LCD.setCursor(0, 0);
  // LCD.print("LOCADORA SAI FRENTE");
  // LCD.setCursor(0, 1);
  // LCD.print("Tempo:    dias");
  // LCD.setCursor(0, 2);
  // LCD.print("Dist:     km  [   ]");
  // LCD.setCursor(0, 3);
  // LCD.print("Total: R$ ");
}

void loop() {
  // 1. Leitura da chave slide (LOW = Popular, HIGH = SUV)
  int categoria = digitalRead(pinoChave);

  // 2. Leitura e mapeamento dos potenciômetros
  //    A0 -> Tempo de locação: de 1 a 30 dias
  int tempo = map(analogRead(A0), 0, 1023, 1, 30);
  //    A1 -> Distância percorrida: de 1 a 1000 km
  int distancia = map(analogRead(A1), 0, 1023, 1, 1000);

  // 3. Lógica de Tarifação: define diária e taxa por km conforme categoria
  float diaria = 30.0;   // Padrão: categoria Popular (POP)
  float taxaKm = 0.01;
  String categoriaLabel = "POP";

  if (categoria == HIGH) {
    // Categoria SUV: diária maior e taxa por km maior
    diaria = 80.0;
    taxaKm = 0.05;
    categoriaLabel = "SUV";
  }

  // 4. Cálculo do custo total com desconto de 10% de fidelidade
  float valorTotal = (tempo * diaria + distancia * taxaKm) * 0.90;

  // ===========================================================================
  // [CÓDIGO ATIVO] ETAPA 1: PAINEL SIMPLES (COM TREMULAÇÃO / FLICKER)
  // Este bloco funciona imediatamente ao iniciar o simulador.
  // ---------------------------------------------------------------------------
  // TODO: Quando for fazer a Etapa 2 (No-Flicker), comente as linhas abaixo
  // colocando '//' no início de cada linha desta seção.
  // ===========================================================================

  LCD.clear();

  LCD.setCursor(0, 0);
  LCD.print("LOCADORA SAI FRENTE");

  LCD.setCursor(0, 1);
  LCD.print("Tempo: ");
  LCD.print(tempo);
  LCD.print(" dias");

  LCD.setCursor(0, 2);
  LCD.print("Dist: ");
  LCD.print(distancia);
  LCD.print(" km [");
  LCD.print(categoriaLabel);
  LCD.print("]");

  LCD.setCursor(0, 3);
  LCD.print("Total: R$ ");
  LCD.print(valorTotal, 2);

  // ===========================================================================
  // [CÓDIGO INATIVO] ETAPA 2: PAINEL PROFISSIONAL (NO-FLICKER + CATEGORIA)
  // ---------------------------------------------------------------------------
  // TODO: Para ativar o painel profissional sem flicker e com tarifação dinâmica:
  // 1. Remova as marcas de comentário de bloco (/* e */) das linhas abaixo.
  // 2. Complete o código onde há marcações "COMPLETE AQUI".
  // ===========================================================================

  /*
  if (tempo != ultimoTempo || distancia != ultimaDistancia || categoria != ultimaCategoria) {

    // Atualiza o tempo na coluna 6, linha 1 (limpa resíduos com espaços antes)
    LCD.setCursor(6, 1);
    LCD.print("   ");
    LCD.setCursor(6, 1);
    LCD.print(tempo);

    // Atualiza a distância na coluna 6, linha 2 (limpa resíduos com espaços antes)
    LCD.setCursor(6, 2);
    LCD.print("     ");
    LCD.setCursor(6, 2);
    LCD.print(distancia);

    // Atualiza a categoria na coluna 15, linha 2
    LCD.setCursor(15, 2);
    LCD.print(categoriaLabel);

    // Atualiza o valor total na coluna 10, linha 3 (limpa resíduos com espaços antes)
    LCD.setCursor(10, 3);
    LCD.print("          ");
    LCD.setCursor(10, 3);
    LCD.print(valorTotal, 2);

    // TODO: Atualize as três variáveis de estado anterior abaixo:
    // ultimoTempo = tempo;               // <-- COMPLETE AQUI
    // ultimaDistancia = distancia;       // <-- COMPLETE AQUI
    // ultimaCategoria = categoria;       // <-- COMPLETE AQUI
  }
  */

  delay(100); // Pausa de estabilidade
}
