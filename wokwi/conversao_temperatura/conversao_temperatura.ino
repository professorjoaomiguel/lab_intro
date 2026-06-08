// Faculdade SENAI Porto Alegre
// Disciplina: Programação Básica
// Professor: João Miguel Lac Roehe
//
// Atividade 1: Conversão de Temperatura (Celsius para Fahrenheit) com display LCD
// Simulação otimizada para o Wokwi.

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos correspondentes:
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

int ultimoTempC = -1;

void setup() {
  LCD.begin(16, 2);
  
  // Imprime os textos estáticos
  LCD.setCursor(0, 0);
  LCD.print("TempC:      oC");
  LCD.setCursor(0, 1);
  LCD.print("TempF:      oF");
}

void loop() {
  // Lê o potenciômetro em A0 (0 a 1023)
  int potenciometro = analogRead(A0);
  
  // Mapeia a leitura para 0 a 60 graus Celsius
  int tempC = map(potenciometro, 0, 1023, 0, 60);
  
  // Só atualiza o LCD se houver mudança
  if (tempC != ultimoTempC) {
    float tempF = (9.0 / 5.0) * tempC + 32.0;
    
    // Celsius
    LCD.setCursor(7, 0);
    LCD.print("    ");
    LCD.setCursor(7, 0);
    LCD.print(tempC);
    
    // Fahrenheit
    LCD.setCursor(7, 1);
    LCD.print("      ");
    LCD.setCursor(7, 1);
    LCD.print(tempF, 1);
    
    ultimoTempC = tempC;
  }
  
  delay(100);
}
