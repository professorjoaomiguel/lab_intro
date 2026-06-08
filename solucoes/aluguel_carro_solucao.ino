// Faculdade SENAI Porto Alegre
// Disciplina: Programação Básica
// Professor: João Miguel Lac Roehe
//
// Computador de Tarifação Dinâmica - Car Sharing (VoltLog - LCD 20x4)
// Solução de Referência (Gabarito do Professor)

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos correspondentes:
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

const int pinoChave = 9;

int ultimoTempo = -1;
int ultimaDistancia = -1;
int ultimaCategoria = -1;

void setup() {
  LCD.begin(20, 4);
  pinMode(pinoChave, INPUT_PULLUP);
  
  // Imprime os labels fixos no LCD
  LCD.setCursor(0, 0);
  LCD.print("LOCADORA SAI FRENTE");
  LCD.setCursor(0, 1);
  LCD.print("Tempo:    dias");
  LCD.setCursor(0, 2);
  LCD.print("Dist:     km  [   ]");
  LCD.setCursor(0, 3);
  LCD.print("Total: R$ ");
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
    
    // Altera tarifas baseando-se no estado físico da chave slide (HIGH = SUV, LOW = Popular)
    if (categoria == HIGH) {
      diaria = 80.0;
      taxaKm = 0.05;
      catLabel = "SUV";
    }
    
    // Calculation do valor com 10% de desconto
    float valorTotal = (tempo * diaria + distancia * taxaKm) * 0.9;
    
    // Atualiza o tempo no LCD (coluna 7, linha 1)
    LCD.setCursor(7, 1);
    LCD.print("   ");
    LCD.setCursor(7, 1);
    LCD.print(tempo);
    
    // Atualiza a distância no LCD (coluna 6, linha 2)
    LCD.setCursor(6, 2);
    LCD.print("    ");
    LCD.setCursor(6, 2);
    LCD.print(distancia);
    
    // Atualiza a sigla da categoria (coluna 15, linha 2)
    LCD.setCursor(15, 2);
    LCD.print(catLabel);
    
    // Atualiza o valor total no LCD (coluna 10, linha 3)
    LCD.setCursor(10, 3);
    LCD.print("      ");
    LCD.setCursor(10, 3);
    LCD.print(valorTotal, 2);
    
    ultimoTempo = tempo;
    ultimaDistancia = distancia;
    ultimaCategoria = categoria;
  }
  
  delay(100);
}
