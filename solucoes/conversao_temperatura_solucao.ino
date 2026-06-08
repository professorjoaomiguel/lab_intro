// Faculdade SENAI Porto Alegre
// Disciplina: Programação Básica
// Professor: João Miguel Lac Roehe
//
// Solução Completa - Atividade 1: Conversão de Temperatura (Celsius para Fahrenheit) com display LCD
// Simulação otimizada para o Wokwi.

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos correspondentes:
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

const int pinoVermelho = 7;
const int pinoVerde = 8;

int ultimoTempC = -1;

void setup() {
  LCD.begin(16, 2);
  
  pinMode(pinoVermelho, OUTPUT);
  pinMode(pinoVerde, OUTPUT);
  
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
    
    // Controle de Alarme e Status (Limiar de 40 °C)
    if (tempC >= 40) {
      digitalWrite(pinoVermelho, HIGH);
      digitalWrite(pinoVerde, LOW);
      LCD.setCursor(13, 0);
      LCD.print("AL"); // Alerta
    } else {
      digitalWrite(pinoVermelho, LOW);
      digitalWrite(pinoVerde, HIGH);
      LCD.setCursor(13, 0);
      LCD.print("OK"); // Normal
    }
    
    ultimoTempC = tempC;
  }
  
  delay(100);
}
