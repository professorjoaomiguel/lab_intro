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
//      do LCD apenas se o valor atual de tempo for diferente de 'ultimoTempo' 
//      OU se a distância atual for diferente de 'ultimaDistancia' OU a chave seletora mudar.
//   3. Lógica de Tarifação Dinâmica: leia a chave slide (Pino 9) que define a categoria:
//      -> LOW (Popular - POP): Diária de R$ 30,00 e R$ 0,01 por km.
//      -> HIGH (Utilitário SUV - SUV): Diária de R$ 80,00 e R$ 0,05 por km.
//   4. Limpe as casas numéricas dinâmicas com espaços em branco ("  " ou "    ") antes
//      de imprimir para apagar dígitos órfãos residuais.
// -----------------------------------------------------------------------------
//
// 🧠 REFLEXÃO TÉCNICA (Obrigatório):
// As perguntas desta atividade devem ser respondidas no arquivo 'folha_respostas.md'.
// Preencha suas respostas lá e garanta que o arquivo esteja na entrega final.
//

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
  // Inicializa o LCD com 20 colunas e 4 linhas
  LCD.begin(20, 4);
  
  // TODO: Configure o pino da chave slide como entrada utilizando resistor de pull-up interno.
  // Dica de pesquisa: use 'pinMode(pino, INPUT_PULLUP)'.
  
  // TODO (Etapa 2): Desenhe o layout estático inicial na tela de uma única vez.
  // Escrever as etiquetas aqui economiza processamento e evita cintilações no LCD.
  // Dica: Use LCD.setCursor(coluna, linha) e LCD.print("texto")
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
    
    // TODO: Posicione o cursor e exiba a quantidade de dias no LCD (Linha 1).
    // Dica: Posicione na coluna 7 da linha 1. Limpe com espaços ("   ") antes de escrever.
    
    // TODO: Posicione o cursor e exiba a distância percorrida no LCD (Linha 2).
    // Dica: Posicione na coluna 6 da linha 2. Limpe com espaços ("    ") antes de escrever.
    
    // TODO: Posicione o cursor e exiba o rótulo da categoria ("POP" ou "SUV") na linha 2.
    // Dica: Posicione na coluna 15 da linha 2 (dentro do colchete "[POP]" ou "[SUV]").
    
    // TODO: Posicione o cursor e exiba o valor total formatado no LCD (Linha 3).
    // Dica: Posicione na coluna 10 da linha 3. Use LCD.print(valorTotal, 2) para duas casas decimais.
    
    // TODO (Etapa 2): Atualize as variáveis de estado para reter as leituras atuais.
    
  // }
  
  delay(100); // Pausa para estabilidade de hardware
}
