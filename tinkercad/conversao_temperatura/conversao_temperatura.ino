// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 01: Conversão de Temperatura com Display LCD (Original Tinkercad)
// 
// Aluno: _____________________________________ Data: ___/___/_____
//
// -----------------------------------------------------------------------------
// ETAPA 1 (Intermediária): Mapeie a leitura analógica (A0) para 0 a 60 °C.
//                          Calcule e exiba as temperaturas (C e F) no LCD.
//                          (Nesta etapa, o display pode piscar/oscilar).
//
// ETAPA 2 (Final - Desafio): Evite o flicker (piscar de tela). 
//                             Atualize os números no LCD apenas sob variação.
// -----------------------------------------------------------------------------
//
// 🧠 REFLEXÃO TÉCNICA (Obrigatório):
// 1. Por que atualizar o display LCD continuamente a cada iteração do loop() causa 
//    o efeito visual de piscada (flicker)? 
// 2. Como a variável global de estado (como 'ultimoTempC') resolve esse problema?
//
// Resposta: ___________________________________________________________________
// _____________________________________________________________________________
// _____________________________________________________________________________

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos do Arduino: RS, Enable, D4, D5, D6, D7
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

// TODO: Defina aqui as variáveis globais de estado necessárias para a Etapa 2
int ultimoTempC = -1; 

void setup() {
  // Inicializa o LCD de 16 colunas e 2 linhas
  LCD.begin(16, 2);
  
  // TODO (Etapa 2): Escreva os rótulos estáticos no display de uma vez só
  // Dica: Use LCD.setCursor(coluna, linha) e LCD.print("texto")
  // LCD.setCursor(0, 0);
  // LCD.print("TempC:      oC");
}

void loop() {
  // TODO: Faça a leitura analógica do potenciômetro conectado ao pino A0
  int potenciometro = 0; 
  
  // TODO: Use a função map() para converter a leitura de 0-1023 para a escala de 0-60 °C
  int tempC = 0; 

  // TODO (Etapa 2): Estruture um bloco condicional 'if' para que a atualização
  // do LCD ocorra apenas se o valor de 'tempC' for diferente de 'ultimoTempC'.
  // Para a Etapa 1, você pode ignorar o 'if' e escrever diretamente.
  
  // {
    // TODO: Calcule a conversão de Celsius para Fahrenheit
    // Dica: Fahrenheit = C * (9.0 / 5.0) + 32.0
    float tempF = 0.0;
    
    // TODO (Etapa 1): Posicione o cursor e exiba o valor de Celsius no LCD
    // TODO (Etapa 1): Posicione o cursor e exiba o valor de Fahrenheit no LCD
    
    // TODO (Etapa 2): Lembre-se de limpar com espaços ("    ") a posição numérica
    // antes de reescrever o novo valor, para evitar resíduos de números anteriores.
    
    // TODO (Etapa 2): Atualize a variável de estado anterior
  // }
  
  delay(100);
}
