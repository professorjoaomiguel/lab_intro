---
theme: seriph
background: https://images.unsplash.com/photo-1518770660439-4636190af475?auto=format&fit=crop&w=1920&q=80
class: text-center
highlighter: shiki
lineNumbers: true
drawings:
  persist: false
transition: slide-left
title: Programação em C e Introdução ao Arduino
info: |
  Apresentação de apoio para a disciplina de Programação Básica.
  Faculdade de Tecnologia SENAI Porto Alegre.
---

# Programação em C e Introdução ao Arduino

Atividades Práticas com Simuladores Tinkercad & Wokwi

<div class="pt-12">
  <span @click="$slidev.nav.next" class="px-2 py-1 rounded cursor-pointer hover:bg-white/10" style="font-size: 15px;">
    Prof. Me. João Miguel Lac Roehe <kbd class="ml-2">pressione Barra de Espaço ou →</kbd>
  </span>
</div>

<div class="abs-bottom-right m-6 opacity-60">
  Faculdade de Tecnologia SENAI Porto Alegre
</div>

---
layout: intro
---

# Agenda da Aula

Estrutura de aprendizagem para hoje:

1. **Introdução ao Arduino** - Conceito de Percepção, Ação e Prototipagem Rápida.
2. **Sinais Elétricos** - A diferença prática entre Sinais Analógicos e Digitais.
3. **Linguagem Arduino (APL)** - Comparativo da estrutura de código em C e Arduino.
4. **Ambientes de Simulação** - Como criar e testar circuitos no Tinkercad e Wokwi.
5. **Atividade 1** - Conversão de Temperatura ($^{\circ}\text{C}$ para $^{\circ}\text{F}$) com display LCD.
6. **Atividade 2 & 3** - Cálculo de Aluguel de Carro (Locadora "Sai da Frente") em C e Arduino.
7. **Desafio Técnico** - Como eliminar a oscilação (*flicker*) do display LCD.

---
layout: two-cols
---

# O que é o Arduino?

O Arduino é uma plataforma de prototipagem eletrônica de código aberto (*open-source*), baseada em hardware e software fáceis de usar.

* **Hardware:** Placas com microcontroladores (como o ATmega328P no Arduino Uno) e pinos de Entrada/Saída (I/O).
* **Software (IDE):** Ambiente onde escrevemos, compilamos e enviamos o código para a placa.
* **Prototipagem Rápida:** Criada para facilitar o aprendizado e testes rápidos de ideias sem a complexidade de circuitos industriais dedicados.

::right::

<div class="pl-8 pt-10">
  <h3 class="font-bold text-lg mb-4 text-primary">Ciclo de Percepção e Ação</h3>
  
  <div class="flex flex-col gap-3">
    <div class="border border-white/20 p-2 rounded bg-white/5">
      <b class="text-green-400">1. Estímulo:</b> Fenômeno físico (ex: luz, temperatura).
    </div>
    <div class="border border-white/20 p-2 rounded bg-white/5">
      <b class="text-green-400">2. Percepção (Sensores):</b> Lê o estímulo e envia sinal à placa.
    </div>
    <div class="border border-white/20 p-2 rounded bg-white/5">
      <b class="text-green-400">3. Processamento (Código):</b> Decisão lógica tomada pelo programa.
    </div>
    <div class="border border-white/20 p-2 rounded bg-white/5">
      <b class="text-green-400">4. Ação (Atuadores):</b> Realiza o trabalho (ex: acende LED, move motor).
    </div>
  </div>
</div>

---
layout: two-cols
---

# Sinais Analógicos

Sinais **contínuos** no tempo que podem assumir infinitos valores em uma determinada faixa.

* **Conversor AD (Analógico-Digital):** O Arduino Uno possui entradas analógicas que convertem tensões de `0V a 5V` em valores digitais de `0 a 1023` (10 bits de resolução).
* **Exemplos de entrada:**
  - Potenciômetro (posição).
  - Sensor de Luz (LDR).
  - Sensor de Temperatura (LM35).
* **Função no código:** `analogRead(pino);`

::right::

<div class="pl-8">
  <h1 class="text-primary">Sinais Digitais</h1>
  
  Sinais **discretos** no tempo que assumem apenas dois estados lógicos bem definidos.

  * **Estados:**
    - `HIGH` (Alto / 1 / 5V)
    - `LOW` (Baixo / 0 / 0V)
  * **Exemplos de sensores e atuadores:**
    - Botão de pressão (Pressionado / Solto).
    - LED (Aceso / Apagado).
    - Buzzer (Ligado / Desligado).
  * **Funções no código:**
    - `digitalRead(pino);`
    - `digitalWrite(pino, valor);`
</div>

---

# A Linguagem do Arduino (APL)

A Linguagem de Programação do Arduino (APL) é baseada em C/C++ e utiliza o framework Wiring.

<div class="grid grid-cols-2 gap-8 pt-4">
<div>

### Estrutura Tradicional em C
```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Executa uma única vez
    printf("Olá Mundo!");
    
    // Não repete automaticamente
    return 0;
}
```
</div>
<div>

### Estrutura do Arduino
```cpp
void setup() {
  // Executado uma única vez ao iniciar a placa
  // Usado para configurar pinos e periféricos
  Serial.begin(9600);
}

void loop() {
  // Executado continuamente em loop infinito
  Serial.println("Olá Mundo!");
  delay(1000);
}
```
</div>
</div>

---
layout: center
---

# Por que o loop() se repete infinitamente?

Por baixo dos panos, o compilador do Arduino estrutura a execução clássica do C da seguinte forma:

```cpp
int main(void) {
    setup(); // Executa a configuração uma única vez
    
    while (1) {
        loop(); // Executa o loop indefinidamente enquanto houver energia
    }
    
    return 0;
}
```

---

# Atividade 1: Conversor de Temperatura

Mapear a posição de um potenciômetro em Celsius e exibir os valores de Celsius e Fahrenheit no LCD 16x2.

<div class="grid grid-cols-2 gap-4">
<div>

### Requisitos e Conexões
* **LCD 16x2:** Conectado nos pinos do Arduino:
  `LiquidCrystal LCD(12, 11, 5, 4, 3, 2);`
* **Potenciômetro:** Conectado no pino analógico `A0`.
* **Fórmula de Conversão:**
  $$F = \frac{9}{5} \times C + 32$$
* **Escala Celsius desejada:** $0$ a $60^{\circ}\text{C}$.
* Mapeamento feito com a função `map()` do Arduino.

</div>
<div>

### O Problema do Flicker (Tela Piscando)
Muitos programas de iniciantes limpam a tela (`lcd.clear()`) e reescrevem tudo em cada ciclo de execução. 
Isso faz com que o display fique piscando de forma desconfortável.

**Como resolver?**
1. Escreva os textos fixos (`TempC:` e `TempF:`) apenas uma vez no `setup()`.
2. No `loop()`, reposicione o cursor e atualize apenas os números quando o valor sofrer alteração.

</div>
</div>

---

# Funcionamento do LCD e a Causa do Flicker

Por que displays piscam e como otimizar a atualização via software?

<div class="grid grid-cols-2 gap-8">
<div>

### Hardware do Display (HD44780)
*   **Comunicação Lenta:** A CPU do Arduino Uno opera a 16 MHz, mas o controlador do LCD (HD44780) é muito mais lento para processar instruções físicas.
*   **Custo do `LCD.clear()`:** Limpar toda a tela exige que o chip interno do LCD desligue fisicamente todos os pixels. Esse ciclo de limpeza leva cerca de **1.64 ms**!
*   **Origem do Flicker (Piscadas):** Ao limpar e reescrever a tela repetidamente centenas de vezes por segundo no `loop()`, a tela cintila pois alterna constantemente entre ligar e desligar.

</div>
<div>

### Rotina de Atualização por Estado
1.  **Labels Estáticos (setup):** Texto fixo como `"TempC: "` é impresso apenas uma vez na inicialização.
2.  **Filtro de Estado (loop):** Use condicionais para atualizar a tela apenas quando houver alteração de valor: `if (valorAtual != ultimoValor)`.
3.  **Limpeza Local de Resíduos:** Antes de escrever o novo valor numérico, imprima alguns espaços vazios (`"    "`) no cursor para limpar dígitos antigos órfãos (ex: apagar o `0` do `10` ao mudar para `9`).

</div>
</div>

---

# Solução Otimizada da Atividade 1

```cpp {all|11-19|24-26|28-44}
#include <LiquidCrystal.h>
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);
int ultimoTempC = -1; // Guarda o valor anterior para evitar reescrita constante

void setup() {
  LCD.begin(16, 2);
  
  // Imprime os rótulos fixos uma única vez
  LCD.setCursor(0, 0);
  LCD.print("TempC:      oC");
  LCD.setCursor(0, 1);
  LCD.print("TempF:      oF");
}

void loop() {
  int potenciometro = analogRead(A0);
  int tempC = map(potenciometro, 0, 1023, 0, 60);
  
  if (tempC != ultimoTempC) { // Atualiza o display SOMENTE se a temperatura mudar
    float tempF = (9.0 / 5.0) * tempC + 32.0;
    
    LCD.setCursor(7, 0);
    LCD.print("    "); // Limpa o número anterior
    LCD.setCursor(7, 0);
    LCD.print(tempC);
    
    LCD.setCursor(7, 1);
    LCD.print("      "); // Limpa o número anterior
    LCD.setCursor(7, 1);
    LCD.print(tempF, 1); // Exibe com 1 casa decimal
    
    ultimoTempC = tempC;
  }
  delay(100);
}
```

---

# Atividade 2: Aluguel de Carro em C (TheHuxley #1086)

Implementar em C puro a regra de cálculo da locadora de carros **"Sai da Frente"**:

* **Regras de Negócio:**
  - Diária do veículo: **R$ 30,00**.
  - Custo por quilômetro rodado: **R$ 0,01**.
  - Desconto especial de São João: **10%** no valor total.
* **Formato de Entrada:**
  - Quantidade de dias (`tempo`): de $1$ a $30$.
  - Quilômetros rodados (`distancia`): de $1$ a $1000$.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tempo, distancia;
    float valor;
    
    scanf("%i %i", &tempo, &distancia);
    
    // Cálculo aplicando o desconto de 10% (* 0.9)
    valor = (tempo * 30.0 + distancia * 0.01) * 0.9;
    
    printf("%.2f\n", valor);
    return 0;
}
```

---

# Atividade 3: Aluguel de Carro no Arduino com LCD

Trazer a regra da locadora para a simulação física do Arduino Uno.

<div class="grid grid-cols-2 gap-4">
<div>

### Lógica da Simulação
* **Entrada de dados:** Dois potenciômetros:
  - Potenciômetro 1 (`A0`): Controla o tempo de locação (mapeado de 1 a 30 dias).
  - Potenciômetro 2 (`A1`): Controla a distância percorrida (mapeado de 1 a 1000 km).
* **Saída (LCD):**
  - **Linha 1:** Quantidade de dias e quilômetros rodados.
  - **Linha 2:** O total a pagar calculado com desconto.

</div>
<div>

### Código Arduino no LCD
O LCD mostrará as informações formatadas de forma compacta:
```text
T: 12d  D: 450km
Total: R$ 301.05
```
Assim como na atividade 1, as leituras são monitoradas e a tela só atualiza se os valores de dias ou quilômetros sofrerem modificações.

</div>
</div>

---

# Solução Completa da Atividade 3

```cpp {all|14-22|24-26|27-37}
#include <LiquidCrystal.h>
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);
int ultimoTempo = -1, ultimaDistancia = -1;

void setup() {
  LCD.begin(16, 2);
  LCD.setCursor(0, 0);
  LCD.print("T:   d  D:    km");
  LCD.setCursor(0, 1);
  LCD.print("Total: R$       ");
}

void loop() {
  int tempo = map(analogRead(A0), 0, 1023, 1, 30);
  int distancia = map(analogRead(A1), 0, 1023, 1, 1000);
  
  if (tempo != ultimoTempo || distancia != ultimaDistancia) {
    float valorTotal = (tempo * 30.0 + distancia * 0.01) * 0.9;
    
    LCD.setCursor(2, 0);
    LCD.print("  "); // Limpa o tempo anterior
    LCD.setCursor(2, 0);
    LCD.print(tempo);
    
    LCD.setCursor(10, 0);
    LCD.print("    "); // Limpa a distância anterior
    LCD.setCursor(10, 0);
    LCD.print(distancia);
    
    LCD.setCursor(10, 1);
    LCD.print("      "); // Limpa o valor anterior
    LCD.setCursor(10, 1);
    LCD.print(valorTotal, 2); // Imprime com duas casas decimais
    
    ultimoTempo = tempo;
    ultimaDistancia = distancia;
  }
  delay(100);
}
```

---

# Novo Projeto: Telemetria e Autonomia de Combustível

Ampliando a IHM local com display LCD 20x4 e múltiplas variáveis

<div class="grid grid-cols-2 gap-8">
<div>

### Requisitos Técnicos
*   **LCD 20x4 (HD44780):** Inicializado com `LCD.begin(20, 4)`. Oferece 4 linhas de 20 colunas.
*   **Entradas Analógicas:**
    *   Volume Restante (A0): $0$ a $50$ Litros.
    *   Consumo Instantâneo (A1): $0$ a $20$ L/h.
*   **Tratamento de Exceção (Divisão por Zero):**
    *   $\text{Autonomia} = \text{Volume} / \text{Consumo}$
    *   Se o consumo for menor que $0.1$ L/h, a divisão direta causaria travamento lógico ou erro. O software exibe `INF` (infinito).

</div>
<div>

### Elementos Avançados de Interface
*   **LED de Reserva:** Um LED vermelho no pino 7 acende e pisca o aviso `!RESERVA!` no LCD se o volume for menor que $5$ Litros.
*   **Barra de Progresso Dinâmica:** Uma representação em bloco preenchido (`char(255)`) com base na porcentagem de preenchimento do tanque:
    `Barra: [██████    ] 60%`
*   **Filtro de Estado:** Atualização sob variação do percentual ou do consumo para evitar flicker no LCD 20x4.

</div>
</div>

---

# Estrutura do Código: Telemetria de Combustível

```cpp {all|1-4|6-10|11-20|22-26}
// ... Dentro do loop() após ler entradas mapeadas como float ...
float percentual = (volume / 50.0) * 100.0;
int percentualInt = (int)percentual;
int consumoInt = (int)(consumo * 10.0);

if (percentualInt != ultimoPercentual || consumoInt != ultimoConsumoInt) {
  // 1. Evita divisão por zero
  float autonomia = (consumo < 0.1) ? 0.0 : (volume / consumo);
  
  // 2. Loop de desenho da Barra de Progresso (Linha 2)
  LCD.setCursor(0, 2);
  LCD.print("Barra: [");
  int blocos = percentualInt / 10;
  for (int i = 0; i < 10; i++) {
    if (i < blocos) LCD.write(255); // Bloco cheio (ASCII 255)
    else LCD.print(" ");           // Espaço vazio
  }
  LCD.print("] "); LCD.print(percentualInt); LCD.print("%");
  
  // 3. Exibe Autonomia (ou Alerta de Reserva)
  // ...
  ultimoPercentual = percentualInt;
  ultimoConsumoInt = consumoInt;
}
```

---
layout: center
class: text-center
---

# Mãos à Obra!

Experimente agora mesmo nos simuladores. 

Os códigos estão disponíveis na estrutura deste projeto:
* **Tinkercad**: Copie os arquivos `.ino` da pasta `tinkercad/`
* **Wokwi**: Execute as simulações nas pastas do diretório `wokwi/`

Dúvidas? Entre em contato com o **Prof. Me. João Miguel Lac Roehe**!
