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

const int pinoChave = 9;

int ultimoTempo = -1;
int ultimaDistancia = -1;
int ultimaCategoria = -1;

void setup() {
  LCD.begin(16, 2);
  pinMode(pinoChave, INPUT_PULLUP);
  
  // Imprime os labels fixos no LCD (K: no lugar de D: para liberar colunas para a categoria)
  LCD.setCursor(0, 0);
  LCD.print("T:   d K:     ");
  LCD.setCursor(0, 1);
  LCD.print("Total: R$       ");
}

void loop() {
  // Lê a chave slide (LOW = Popular, HIGH = SUV)
  int categoria = digitalRead(pinoChave);

  // Lê e mapeia a quantidade de dias (pino A0, de 1 a 30)
  int potTempo = analogRead(A0);
  int tempo = map(potTempo, 0, 1023, 1, 30);
  
  // Lê e mapeia a distância rodada em quilômetros (pino A1, de 1 a 1000)
  int potDist = analogRead(A1);
  int distancia = map(potDist, 0, 1023, 1, 1000);
  
  // Só atualiza o display se houver alteração em alguma das entradas analógicas ou na chave
  if (tempo != ultimoTempo || distancia != ultimaDistancia || categoria != ultimaCategoria) {
    float diaria = 30.0;
    float taxaKm = 0.01;
    char* catLabel = "POP";
    
    // Altera tarifas baseando-se no estado físico da chave slide
    if (categoria == HIGH) {
      diaria = 80.0;
      taxaKm = 0.05;
      catLabel = "SUV";
    }
    
    // Cálculo do valor com 10% de desconto
    float valorTotal = (tempo * diaria + distancia * taxaKm) * 0.9;
    
    // Atualiza o tempo no LCD (coluna 2, linha 0)
    LCD.setCursor(2, 0);
    LCD.print("  ");
    LCD.setCursor(2, 0);
    LCD.print(tempo);
    
    // Atualiza a distância no LCD (coluna 8, linha 0)
    LCD.setCursor(8, 0);
    LCD.print("    ");
    LCD.setCursor(8, 0);
    LCD.print(distancia);
    
    // Atualiza a sigla da categoria (coluna 13, linha 0)
    LCD.setCursor(13, 0);
    LCD.print(catLabel);
    
    // Atualiza o valor total no LCD (coluna 10, linha 1)
    LCD.setCursor(10, 1);
    LCD.print("      ");
    LCD.setCursor(10, 1);
    LCD.print(valorTotal, 2);
    
    ultimoTempo = tempo;
    ultimaDistancia = distancia;
    ultimaCategoria = categoria;
  }
  
  delay(100);
}
