// Faculdade SENAI Porto Alegre
// Disciplina: Programação Básica
// Professor: João Miguel Lac Roehe
//
// Atividade 1: Conversão de Temperatura (Celsius para Fahrenheit) com display LCD
// Solução otimizada para evitar oscilação (flicker) no display LCD.

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos correspondentes:
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

int ultimoTempC = -1; // Armazena a última temperatura para atualizar apenas quando houver mudança

void setup() {
  // Configura o display LCD com 16 colunas e 2 linhas
  LCD.begin(16, 2);
  
  // Imprime os textos estáticos (labels) que não precisam ser limpos e reescritos no loop
  LCD.setCursor(0, 0);
  LCD.print("TempC:      oC");
  LCD.setCursor(0, 1);
  LCD.print("TempF:      oF");
}

void loop() {
  // Lê a entrada analógica A0 conectada ao potenciômetro (0 a 1023)
  int potenciometro = analogRead(A0);
  
  // Mapeia a leitura analógica para a faixa de temperatura desejada (0 a 60 graus Celsius)
  int tempC = map(potenciometro, 0, 1023, 0, 60);
  
  // Só atualiza o LCD se houver mudança de valor (evita o efeito de piscar / flicker)
  if (tempC != ultimoTempC) {
    // Calcula a conversão de Celsius para Fahrenheit: F = C * 1.8 + 32
    float tempF = (9.0 / 5.0) * tempC + 32.0;
    
    // Atualiza a temperatura em Celsius no LCD (coluna 7, linha 0)
    LCD.setCursor(7, 0);
    LCD.print("    "); // Limpa o espaço reservado para o valor antigo
    LCD.setCursor(7, 0);
    LCD.print(tempC);
    
    // Atualiza a temperatura em Fahrenheit no LCD (coluna 7, linha 1)
    LCD.setCursor(7, 1);
    LCD.print("      "); // Limpa o espaço reservado para o valor antigo
    LCD.setCursor(7, 1);
    LCD.print(tempF, 1); // Mostra o valor com 1 casa decimal
    
    // Atualiza a referência
    ultimoTempC = tempC;
  }
  
  delay(100); // Pequeno atraso para suavizar as leituras analógicas
}
