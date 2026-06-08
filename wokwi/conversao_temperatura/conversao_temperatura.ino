// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 01: Monitor Térmico das Baterias (VoltLog - LCD 20x4)
// 
// IMPORTANTE: Preencha seu nome e a data de realização abaixo:
// Aluno: <PREENCHA SEU NOME COMPLETO AQUI>  Data: DD/MM/AAAA
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
// 🧠 REFLEXÃO TÉCNICA (Obrigatório):
// As perguntas desta atividade devem ser respondidas no arquivo 'folha_respostas.md'.
// Preencha suas respostas lá e garanta que o arquivo esteja na entrega final.
// -----------------------------------------------------------------------------

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos do Arduino: RS, Enable, D4, D5, D6, D7
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

// Variáveis globais de estado (usadas na Etapa 2)
int ultimoTempC = -1; 
int pinoVermelho = 7;
int pinoVerde = 8;

void setup() {
  // Inicializa o LCD configurando a resolução para 20 colunas e 4 linhas
  LCD.begin(20, 4);
  
  // Configure os pinos digitais dos LEDs de alarme como saídas.
  pinMode(pinoVermelho, OUTPUT);
  pinMode(pinoVerde, OUTPUT);
  
  // Liga o LED Verde e apaga o LED Vermelho por padrão ao ligar o painel
  digitalWrite(pinoVerde, HIGH);
  digitalWrite(pinoVermelho, LOW);
  
  // ---------------------------------------------------------------------------
  // [INSTRUÇÃO ETAPA 2: Display Sem Tremulação (No-Flicker)]
  // Escrever textos estáticos no setup() evita que a tela pisque a cada ciclo.
  // TODO: Ao implementar a Etapa 2, descomente as 8 linhas abaixo:
  // ---------------------------------------------------------------------------
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
  // 1. Leitura analógica do potenciômetro (sensor de temperatura no pino A0)
  int potenciometro = analogRead(A0); 
  
  // 2. Mapeamento de escala: converte a leitura analógica (0-1023) para Celsius (0-60)
  int tempC = map(potenciometro, 0, 1023, 0, 60); 

  // 3. Conversão física: calcula a temperatura correspondente em Fahrenheit
  float tempF = tempC * 1.8 + 32.0;

  // ===========================================================================
  // [CÓDIGO ATIVO] ETAPA 1: PAINEL SIMPLES (COM TREMULAÇÃO / FLICKER)
  // Este bloco funciona imediatamente ao iniciar o simulador. Ele limpa e
  // reescreve todo o LCD a cada 100ms, fazendo a tela piscar.
  // ---------------------------------------------------------------------------
  // TODO: Quando for fazer a Etapa 2 (Módulo Sem Tremulação e com Alertas):
  // Comente as linhas da Etapa 1 abaixo (coloque '//' no início de cada linha).
  // ===========================================================================
  
  LCD.clear();
  
  LCD.setCursor(0, 0);
  LCD.print("PAINEL DE TEMPERATURA");
  
  LCD.setCursor(0, 1);
  LCD.print("Celsius: ");
  LCD.print(tempC);
  LCD.print(" oC");
  
  LCD.setCursor(0, 2);
  LCD.print("Fahrenheit: ");
  LCD.print(tempF, 1);
  LCD.print(" oF");
  
  LCD.setCursor(0, 3);
  LCD.print("Status: OK");

  // ===========================================================================
  // [CÓDIGO INATIVO] ETAPA 2: PAINEL PROFISSIONAL (NO-FLICKER E ALARME DE LED)
  // ---------------------------------------------------------------------------
  // TODO: Para ativar o painel profissional sem flicker e com os LEDs ativos:
  // 1. Remova as marcas de comentário de bloco (/* e */) das linhas abaixo.
  // 2. Complete o código onde há marcações "COMPLETE AQUI".
  // ===========================================================================
  
  /*
  if (tempC != ultimoTempC) {
    
    // Atualiza Celsius na coluna 13, linha 1 (limpando resíduos antigos)
    LCD.setCursor(13, 1);
    LCD.print("   "); 
    LCD.setCursor(13, 1);
    LCD.print(tempC);
    
    // Atualiza Fahrenheit na coluna 13, linha 2 (limpando resíduos antigos)
    LCD.setCursor(13, 2);
    LCD.print("     "); 
    LCD.setCursor(13, 2);
    LCD.print(tempF, 1);
    
    // Lógica do Alarme de Temperatura (Limite: 40 °C)
    if (tempC >= 40) {
      // Bateria quente! Acende o vermelho e apaga o verde.
      digitalWrite(pinoVermelho, HIGH);
      // TODO: Apague o LED verde enviando sinal LOW nele:
      // digitalWrite(pinoVerde, ...); // <-- COMPLETE AQUI
      
      // Imprime "ALERTA" na coluna 8, linha 3
      LCD.setCursor(8, 3);
      LCD.print("ALERTA");
    } 
    else {
      // Temperatura segura! Apaga o vermelho e acende o verde.
      // TODO: Apague o LED vermelho enviando sinal LOW nele:
      // digitalWrite(pinoVermelho, ...); // <-- COMPLETE AQUI
      digitalWrite(pinoVerde, HIGH);
      
      // Imprime "OK    " na coluna 8, linha 3 (espaços em branco apagam a palavra ALERTA anterior)
      LCD.setCursor(8, 3);
      LCD.print("OK    ");
    }
    
    // Atualiza o estado anterior para a próxima comparação
    ultimoTempC = tempC;
  }
  */

  delay(100); // Pausa de estabilidade
}
