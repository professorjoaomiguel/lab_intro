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
// -----------------------------------------------------------------------------

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos do Arduino: RS, Enable, D4, D5, D6, D7
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

// Pino do LED vermelho indicador de combustível em reserva
int pinoAlerta = 7;

// Variáveis globais de estado para o Filtro de Estado (Etapa 2)
int ultimoPercentual = -1;
int ultimoConsumoInt = -1;

void setup() {
  // Inicializa o LCD de 20 colunas por 4 linhas
  LCD.begin(20, 4);

  // Configura o LED de alerta como saída e garante que começa apagado
  pinMode(pinoAlerta, OUTPUT);
  digitalWrite(pinoAlerta, LOW);

  // ---------------------------------------------------------------------------
  // [INSTRUÇÃO ETAPA 2: Layout Fixo No-Flicker]
  // Escrever os textos fixos aqui evita que pisquem a cada ciclo do loop().
  // TODO: Ao implementar a Etapa 2, descomente as 6 linhas abaixo:
  // ---------------------------------------------------------------------------
  // LCD.setCursor(0, 0);
  // LCD.print("PAINEL DE TELEMETRIA");
  // LCD.setCursor(0, 1);
  // LCD.print("Tanque:     L");
  // LCD.setCursor(0, 3);
  // LCD.print("Autonomia:        h");
}

void loop() {
  // 1. Leitura analógica do sensor de nível (A0) -> Volume em Litros (0.0 a 50.0 L)
  float volume = (analogRead(A0) / 1023.0) * 50.0;

  // 2. Leitura analógica do sensor de fluxo (A1) -> Consumo em L/h (0.0 a 20.0 L/h)
  float consumo = (analogRead(A1) / 1023.0) * 20.0;

  // 3. Cálculo do percentual do tanque (0 a 100%) — usado no Filtro de Estado e na barra
  float percentual = (volume / 50.0) * 100.0;
  int percentualInt = (int)percentual;

  // Converte o consumo para inteiro com 1 casa decimal (ex: 7.3 -> 73) para o Filtro de Estado
  int consumoInt = (int)(consumo * 10.0);

  // 4. Proteção contra Divisão por Zero
  //    Se consumo < 0.1 L/h, o carro está em modo 100% elétrico — não há combustível sendo consumido.
  float autonomia = 0.0;
  bool divisaoPorZero = false;

  if (consumo < 0.1) {
    divisaoPorZero = true;  // Flag de segurança ativada: evita divisão por zero
    autonomia = 0.0;
  } else {
    autonomia = volume / consumo;  // Calcula: quanto tempo o tanque ainda dura (em horas)
  }

  // ===========================================================================
  // [CÓDIGO ATIVO] ETAPA 1: PAINEL SIMPLES (COM TREMULAÇÃO / FLICKER)
  // Este bloco funciona imediatamente ao iniciar o simulador.
  // ---------------------------------------------------------------------------
  // TODO: Quando for implementar a Etapa 2 (No-Flicker), comente as linhas desta
  // seção colocando '//' no início de cada linha.
  // ===========================================================================

  LCD.clear();

  LCD.setCursor(0, 0);
  LCD.print("PAINEL DE TELEMETRIA");

  LCD.setCursor(0, 1);
  LCD.print("Tanque: ");
  LCD.print(volume, 1);
  LCD.print(" L");

  LCD.setCursor(0, 2);
  LCD.print("Consumo: ");
  LCD.print(consumo, 1);
  LCD.print(" L/h");

  LCD.setCursor(0, 3);
  if (divisaoPorZero) {
    LCD.print("Autonomia: INF (elet)");
  } else {
    LCD.print("Autonomia: ");
    LCD.print(autonomia, 1);
    LCD.print(" h");
  }

  // Alarme de reserva ativo mesmo na Etapa 1
  if (volume < 5.0) {
    digitalWrite(pinoAlerta, HIGH);
  } else {
    digitalWrite(pinoAlerta, LOW);
  }

  // ===========================================================================
  // [CÓDIGO INATIVO] ETAPA 2: PAINEL PROFISSIONAL (NO-FLICKER + BARRA GRÁFICA)
  // ---------------------------------------------------------------------------
  // TODO: Para ativar o painel profissional:
  // 1. Remova as marcas de comentário de bloco (/* e */) das linhas abaixo.
  // 2. Complete o código onde há marcações "COMPLETE AQUI".
  // ===========================================================================

  /*
  if (percentualInt != ultimoPercentual || consumoInt != ultimoConsumoInt) {

    // Atualiza volume na coluna 8, linha 1 (limpa resíduos com espaços)
    LCD.setCursor(8, 1);
    LCD.print("      ");
    LCD.setCursor(8, 1);
    LCD.print(volume, 1);

    // Desenha a Barra de Progresso Gráfica na linha 2
    int blocos = percentualInt / 10;  // De 0 a 10 blocos preenchidos
    LCD.setCursor(0, 2);
    LCD.print("Barra: [");
    for (int i = 0; i < 10; i++) {
      if (i < blocos) {
        LCD.write(255);   // Bloco sólido preenchido (caractere ASCII 255)
      } else {
        LCD.print(" ");   // Espaço vazio
      }
    }
    LCD.print("] ");
    LCD.print(percentualInt);
    LCD.print("%  ");

    // Atualiza a autonomia na coluna 11, linha 3
    LCD.setCursor(11, 3);
    LCD.print("         ");
    LCD.setCursor(11, 3);
    if (divisaoPorZero) {
      LCD.print("INF  ");
    } else {
      LCD.print(autonomia, 1);
    }

    // Lógica do LED e etiqueta de reserva
    if (volume < 5.0) {
      // TODO: Acenda o LED de alerta (pinoAlerta = HIGH):
      // digitalWrite(pinoAlerta, ...);  // <-- COMPLETE AQUI

      // Substitui o rótulo da linha 3 pelo aviso de emergência
      LCD.setCursor(0, 3);
      LCD.print("!RESERVA! ");
    } else {
      // TODO: Apague o LED de alerta (pinoAlerta = LOW):
      // digitalWrite(pinoAlerta, ...);  // <-- COMPLETE AQUI

      // Restaura o rótulo padrão da linha 3
      LCD.setCursor(0, 3);
      LCD.print("Autonomia:");
    }

    // TODO: Atualize as duas variáveis de estado anterior abaixo:
    // ultimoPercentual = percentualInt;   // <-- COMPLETE AQUI
    // ultimoConsumoInt = consumoInt;      // <-- COMPLETE AQUI
  }
  */

  delay(100); // Pausa do loop principal
}
