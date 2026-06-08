// Faculdade SENAI Porto Alegre
// Disciplina: Programação Básica
// Professor: João Miguel Lac Roehe
//
// Atividade 3: Cálculo de Aluguel de Carro (Locadora Sai da Frente)
// Simulação otimizada para o Wokwi.

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos correspondentes:
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

int ultimoTempo = -1;
int ultimaDistancia = -1;

void setup() {
  LCD.begin(16, 2);
  
  // Imprime os labels fixos no LCD
  LCD.setCursor(0, 0);
  LCD.print("T:   d  D:    km");
  LCD.setCursor(0, 1);
  LCD.print("Total: R$       ");
}

void loop() {
  // Lê e mapeia a quantidade de dias (pino A0, de 1 a 30)
  int potTempo = analogRead(A0);
  int tempo = map(potTempo, 0, 1023, 1, 30);
  
  // Lê e mapeia a distância rodada em quilômetros (pino A1, de 1 a 1000)
  int potDist = analogRead(A1);
  int distancia = map(potDist, 0, 1023, 1, 1000);
  
  // Só atualiza o display se houver alteração
  if (tempo != ultimoTempo || distancia != ultimaDistancia) {
    float valorTotal = (tempo * 30.0 + distancia * 0.01) * 0.9;
    
    // Atualiza o tempo
    LCD.setCursor(2, 0);
    LCD.print("  ");
    LCD.setCursor(2, 0);
    LCD.print(tempo);
    
    // Atualiza a distância
    LCD.setCursor(10, 0);
    LCD.print("    ");
    LCD.setCursor(10, 0);
    LCD.print(distancia);
    
    // Atualiza o valor total
    LCD.setCursor(10, 1);
    LCD.print("      ");
    LCD.setCursor(10, 1);
    LCD.print(valorTotal, 2);
    
    ultimoTempo = tempo;
    ultimaDistancia = distancia;
  }
  
  delay(100);
}
