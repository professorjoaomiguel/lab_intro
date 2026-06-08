// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 03: Telemetria de Combustível e Autonomia Híbrida (VoltLog - LCD 20x4)
// 
// IMPORTANTE: Preencha seu nome e a data de realização abaixo:
// Aluno: <PREENCHA SEU NOME COMPLETO AQUI>  Data: DD/MM/AAAA
//
// -----------------------------------------------------------------------------
// APRESENTAÇÃO E CONTEXTO:
// Em viagens intermunicipais (como a rota Porto Alegre a Caxias do Sul), a VoltLog
// utiliza utilitários com motorização híbrida (motor elétrico + motor a combustão).
// Você desenvolverá o firmware do computador de bordo principal que gerencia o
// tanque de combustível líquido e calcula a autonomia em tempo real no LCD 20x4.
//
// ETAPAS DE DESENVOLVIMENTO:
// - ETAPA 1 (Intermediária):
//   1. Configure o pino do LED físico de alerta de reserva (Pino 7) como OUTPUT.
//   2. Leia o sensor de nível A0 e converta para Volume (faixa de 0.0 a 50.0 Litros).
//   3. Leia o sensor de fluxo A1 e converta para Consumo (faixa de 0.0 a 20.0 L/h).
//   4. Calcule a autonomia (Volume / Consumo). 
//      ATENÇÃO: proteja o código contra divisão por zero (caso consumo < 0.1 L/h,
//      situação em que o utilitário está rodando 100% no motor elétrico).
//   5. Exiba os valores numéricos de litros, consumo e autonomia no LCD 20x4.
//
// - ETAPA 2 (Final - Desafio):
//   1. Implemente o Filtro de Estado: a tela só deve ser atualizada se o percentual
//      de combustível mudar OU se a leitura inteira de consumo mudar.
//   2. Desenhe uma barra de progresso gráfica na linha 2 do LCD.
//      -> Calcule o percentual de preenchimento (0 a 100%).
//      -> O número de blocos (0 a 10) é dado por percentual / 10.
//      -> Use um loop 'for' de 10 iterações. Se o índice do loop for menor que o número
//         de blocos calculados, imprima o bloco sólido (char(255)). Senão, imprima um espaço (" ").
//   3. Lógica de Reserva do Tanque: se o volume for menor que 5.0 Litros:
//      -> Acenda o LED vermelho do pino 7.
//      -> Altere a etiqueta da linha 3 para exibir "!RESERVA!" em vez de "Autonomia:".
//      -> Caso contrário, mantenha o LED apagado e restaure o texto original.
// -----------------------------------------------------------------------------
//
// 🧠 REFLEXÃO TÉCNICA (Obrigatório):
// As perguntas desta atividade devem ser respondidas no arquivo 'folha_respostas.md'.
// Preencha suas respostas lá e garanta que o arquivo esteja na entrega final.

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos do Arduino: RS, Enable, D4, D5, D6, D7
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

// Pino do LED vermelho indicador de combustível em reserva
int pinoAlerta = 7;

// TODO: Defina as variáveis globais de estado para reter o último percentual do tanque e 
// o último consumo (em formato inteiro) exibidos. Elas impedem redesenhos constantes no loop().
int ultimoPercentual = -1;
int ultimoConsumoInt = -1;

void setup() {
  // Inicializa o LCD de 20 colunas por 4 linhas
  LCD.begin(20, 4);
  
  // TODO: Configure o pino do LED de alerta como saída (OUTPUT)
  
  // TODO (Etapa 2): Desenhe a moldura estática inicial no display de uma única vez no setup().
  // Linha 0 (Cursor 0,0) -> "PAINEL DE TELEMETRIA"
  // Linha 1 (Cursor 0,1) -> "Tanque:     L"
  // Linha 3 (Cursor 0,3) -> "Autonomia:        h"
}

void loop() {
  // TODO: Leia o sensor de nível (A0) e mapeie proporcionalmente para 0.0 a 50.0 litros (volume).
  // Dica: Use cálculo em ponto flutuante: volume = (analogRead(A0) / 1023.0) * 50.0
  float volume = 0.0; 

  // TODO: Leia o sensor de consumo (A1) e mapeie proporcionalmente para 0.0 a 20.0 L/h (consumo).
  float consumo = 0.0; 

  // Calcule o percentual inteiro atual do tanque (0 a 100%) para uso no Filtro de Estado
  float percentual = (volume / 50.0) * 100.0;
  int percentualInt = (int)percentual;
  
  // Calcule o consumo como inteiro com 1 casa decimal (multiplicado por 10) para o Filtro de Estado
  int consumoInt = (int)(consumo * 10.0);

  // TODO (Etapa 2): Filtro de Estado. Envolva toda a atualização do LCD dentro de um bloco 'if':
  // if (percentualInt != ultimoPercentual || consumoInt != ultimoConsumoInt)
  
  // {
    // TODO: Proteção contra Divisão por Zero.
    // Se o consumo for muito baixo (menor que 0.1 L/h, indicando uso exclusivo do motor elétrico),
    // defina a autonomia de forma segura ou avise o sistema. Caso contrário, calcule (volume / consumo).
    float autonomia = 0.0;
    bool divisaoPorZero = false;

    // TODO: Imprima o volume de combustível atualizado no LCD (Linha 1).
    // Dica: Posicione na coluna 8 da linha 1. Imprima "     " antes para limpar o número antigo.
    
    // TODO: Imprima o consumo atualizado no LCD (Linha 1).
    // Dica: Posicione na coluna 13 da linha 1. Use LCD.print(consumo, 1) e escreva "/h".
    
    // TODO (Etapa 2): Desenhe a Barra de Progresso textual horizontal de 10 segmentos (Linha 2).
    // O número de blocos preenchidos será de 0 a 10 (blocos = percentualInt / 10).
    // Utilize um loop 'for (int i = 0; i < 10; i++)' para imprimir o caractere sólido 'char(255)'
    // nas posições correspondentes e espaços em branco " " nas posições vazias da barra.
    // Formato final esperado: "Barra: [██████    ] 60%"
    
    // TODO: Imprima a autonomia calculada no LCD (Linha 3).
    // Dica: Se for divisão por zero, imprima "INF". Caso contrário, imprima o valor real com 2 casas decimais.
    
    // TODO (Etapa 2): Lógica e Alerta de Reserva.
    // - Se o volume atual for menor que 5.0 Litros:
    //   -> Ative o pino do LED de alerta (HIGH).
    //   -> Posicione no início da linha 3 e escreva "!RESERVA! ".
    // - Caso contrário (normal):
    //   -> Desative o pino do LED de alerta (LOW).
    //   -> Posicione no início da linha 3 e restaure o rótulo "Autonomia:".
    
    // TODO (Etapa 2): Atualize as variáveis globais de controle de estado anterior.
    
  // }
  
  delay(100); // Pausa do loop principal
}
