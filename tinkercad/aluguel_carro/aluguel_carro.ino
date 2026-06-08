// Faculdade SENAI Porto Alegre
// Disciplina: Programação Básica
// Professor: João Miguel Lac Roehe
//
// Atividade 3: Cálculo de Aluguel de Carro (Locadora Sai da Frente)
// Utiliza dois potenciômetros para entrada:
// - Potenciômetro 1 (A0): tempo do aluguel (1 a 30 dias)
// - Potenciômetro 2 (A1): distância rodada (1 a 1000 km)
// Exibe os parâmetros e o valor total com 10% de desconto no LCD.

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos correspondentes:
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

int ultimoTempo = -1;
int ultimaDistancia = -1;

void setup() {
  // Inicializa o display LCD de 16x2
  LCD.begin(16, 2);
  
  // Imprime os labels fixos para economizar ciclos e evitar piscadas no display
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
  
  // Atualiza a tela apenas se houver variação nas leituras
  if (tempo != ultimoTempo || distancia != ultimaDistancia) {
    // Cálculo do valor: R$30.00 por dia + R$0.01 por km, com 10% de desconto (* 0.9)
    float valorTotal = (tempo * 30.0 + distancia * 0.01) * 0.9;
    
    // Atualiza o tempo no display (coluna 2, linha 0)
    LCD.setCursor(2, 0);
    LCD.print("  "); // Limpa dois caracteres
    LCD.setCursor(2, 0);
    LCD.print(tempo);
    
    // Atualiza a distância no display (coluna 10, linha 0)
    LCD.setCursor(10, 0);
    LCD.print("    "); // Limpa quatro caracteres
    LCD.setCursor(10, 0);
    LCD.print(distancia);
    
    // Atualiza o valor total a pagar no display (coluna 10, linha 1)
    LCD.setCursor(10, 1);
    LCD.print("      "); // Limpa o valor anterior
    LCD.setCursor(10, 1);
    LCD.print(valorTotal, 2); // Exibe com duas casas decimais
    
    // Salva as referências atuais
    ultimoTempo = tempo;
    ultimaDistancia = distancia;
  }
  
  delay(100); // Pequeno atraso para estabilização
}
