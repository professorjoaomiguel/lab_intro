// Faculdade SENAI Porto Alegre
// Disciplina: Programação Básica
// Professor: João Miguel Lac Roehe
//
// Módulo de Monitoramento Térmico das Baterias (VoltLog - LCD 20x4)
// Solução de Referência (Gabarito do Professor)

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos correspondentes:
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

const int pinoVermelho = 7;
const int pinoVerde = 8;

int ultimoTempC = -1;

void setup() {
  LCD.begin(20, 4);
  
  pinMode(pinoVermelho, OUTPUT);
  pinMode(pinoVerde, OUTPUT);
  
  // Imprime os textos estáticos
  LCD.setCursor(0, 0);
  LCD.print("PAINEL DE TEMPERATURA");
  LCD.setCursor(0, 1);
  LCD.print("Celsius:       oC");
  LCD.setCursor(0, 2);
  LCD.print("Fahrenheit:    oF");
  LCD.setCursor(0, 3);
  LCD.print("Status: ");
}

void loop() {
  // Lê o sensor analógico de temperatura em A0 (0 a 1023)
  int potenciometro = analogRead(A0);
  
  // Mapeia a leitura para 0 a 60 graus Celsius
  int tempC = map(potenciometro, 0, 1023, 0, 60);
  
  // Só atualiza o LCD se houver mudança
  if (tempC != ultimoTempC) {
    float tempF = (9.0 / 5.0) * tempC + 32.0;
    
    // Celsius (coluna 13, linha 1)
    LCD.setCursor(13, 1);
    LCD.print("    ");
    LCD.setCursor(13, 1);
    LCD.print(tempC);
    
    // Fahrenheit (coluna 13, linha 2)
    LCD.setCursor(13, 2);
    LCD.print("      ");
    LCD.setCursor(13, 2);
    LCD.print(tempF, 1);
    
    // Controle de Alarme e Status (Limiar de 40 °C)
    if (tempC >= 40) {
      digitalWrite(pinoVermelho, HIGH);
      digitalWrite(pinoVerde, LOW);
      LCD.setCursor(8, 3);
      LCD.print("ALERTA");
    } else {
      digitalWrite(pinoVermelho, LOW);
      digitalWrite(pinoVerde, HIGH);
      LCD.setCursor(8, 3);
      LCD.print("OK    "); // Espaços para limpar a palavra ALERTA
    }
    
    ultimoTempC = tempC;
  }
  
  delay(100);
}
