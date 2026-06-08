// Faculdade de Tecnologia SENAI Porto Alegre
// Disciplina: Programação Básica
// Experimento 03: Telemetria de Combustível e Autonomia (LCD 20x4)
// Solução de Referência (Gabarito do Professor)

#include <LiquidCrystal.h>

// Inicializa o display LCD nos pinos correspondentes:
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

const int pinoAlerta = 7;

// Variáveis de estado para controle do filtro de exibição
int ultimoPercentual = -1;
int ultimoConsumoInt = -1;

void setup() {
  LCD.begin(20, 4);
  pinMode(pinoAlerta, OUTPUT);
  
  // Imprime layout estático inicial que nunca muda
  LCD.setCursor(0, 0);
  LCD.print("PAINEL DE TELEMETRIA");
  LCD.setCursor(0, 1);
  LCD.print("Tanque:     L");
  LCD.setCursor(0, 3);
  LCD.print("Autonomia:        h");
}

void loop() {
  // Leitura e mapeamento do volume do tanque (0 a 50 litros)
  int potNivel = analogRead(A0);
  float volume = (potNivel / 1023.0) * 50.0;
  
  // Leitura e mapeamento da taxa de consumo (0.0 a 20.0 L/h)
  int potConsumo = analogRead(A1);
  float consumo = (potConsumo / 1023.0) * 20.0;
  
  // Porcentagem atual de combustível
  float percentual = (volume / 50.0) * 100.0;
  int percentualInt = (int)percentual;
  
  // Multiplicamos por 10 para converter em inteiro de 1 casa decimal para o filtro de estado
  int consumoInt = (int)(consumo * 10.0);
  
  // Só atualiza o LCD se houver mudança de estado significativa
  if (percentualInt != ultimoPercentual || consumoInt != ultimoConsumoInt) {
    
    // 1. Proteção de software contra divisão por zero
    float autonomia = 0.0;
    bool divisaoPorZero = false;
    
    if (consumo < 0.1) {
      divisaoPorZero = true;
    } else {
      autonomia = volume / consumo;
    }
    
    // 2. Exibição de Volume
    LCD.setCursor(8, 1);
    LCD.print("     "); // limpa 5 posições
    LCD.setCursor(8, 1);
    LCD.print(volume, 1);
    
    // 3. Exibição do Consumo (Coluna 14)
    LCD.setCursor(13, 1);
    LCD.print("     "); // limpa
    LCD.setCursor(13, 1);
    LCD.print(consumo, 1);
    LCD.print("/h");
    
    // 4. Desenho da Barra de Progresso na Linha 2
    LCD.setCursor(0, 2);
    LCD.print("Barra: [");
    int blocos = percentualInt / 10; // 0 a 10 blocos
    for (int i = 0; i < 10; i++) {
      if (i < blocos) {
        LCD.write(255); // Escreve o bloco cheio (ASCII 255)
      } else {
        LCD.print(" "); // Escreve o espaço vazio
      }
    }
    LCD.print("] ");
    LCD.print(percentualInt);
    LCD.print("%");
    
    // Limpa possíveis dígitos residuais da porcentagem
    if (percentualInt < 100) LCD.print(" ");
    if (percentualInt < 10)  LCD.print(" ");
    
    // 5. Exibição da Autonomia (Linha 3)
    LCD.setCursor(11, 3);
    LCD.print("      "); // limpa
    LCD.setCursor(11, 3);
    if (divisaoPorZero) {
      LCD.print("INF"); // Infinito
    } else {
      LCD.print(autonomia, 2);
    }
    
    // 6. Lógica de Reserva (Menos de 5 litros)
    if (volume < 5.0) {
      digitalWrite(pinoAlerta, HIGH); // Liga o LED de alerta
      LCD.setCursor(0, 3);
      LCD.print("!RESERVA! "); // Exibe alerta
    } else {
      digitalWrite(pinoAlerta, LOW); // Desliga o LED
      LCD.setCursor(0, 3);
      LCD.print("Autonomia:"); // Restaura o label
    }
    
    // Atualiza os estados de controle
    ultimoPercentual = percentualInt;
    ultimoConsumoInt = consumoInt;
  }
  
  delay(100);
}
