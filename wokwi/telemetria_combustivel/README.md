# Experimento 03: Telemetria de Combustível e Autonomia (LCD 20x4)

Este guia orienta o desenvolvimento do terceiro experimento prático de Arduino. Leia atentamente as seções abaixo para entender as etapas, a teoria por trás da atividade e como simular o circuito.

---

## 🧭 Guia do Aluno: Como Iniciar
1.  **Onde programar:** Abra o arquivo [telemetria_combustivel.ino](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/telemetria_combustivel.ino) localizado nesta pasta. Ele é o seu template de trabalho e contém comentários marcados com `# TODO` onde você deve inserir seu código.
2.  **Como simular no Wokwi Web (Navegador):**
    *   Acesse [wokwi.com/projects/new/arduino-uno](https://wokwi.com/projects/new/arduino-uno).
    *   Substitua o conteúdo da aba **`diagram.json`** no simulador pelo conteúdo do arquivo [diagram.json](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/diagram.json) desta pasta para carregar o circuito automaticamente.
    *   Copie o código de [telemetria_combustivel.ino](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/telemetria_combustivel.ino) e cole-o no arquivo de código principal do simulador (`sketch.ino`).
    *   *(Opcional)* Crie um arquivo `README.md` no Wokwi e cole o conteúdo deste roteiro para lê-lo diretamente na tela da simulação. Consulte o [Guia de Início Rápido do Wokwi Web](file:///C:/GitHub/lab_intro/docs/Guia_Wokwi_Inicio_Rapido.md) para mais detalhes.

---

## 1. Objetivos de Aprendizagem
*   **Nível Intermediário:** Ler e reescalar duas entradas analógicas usando cálculo em ponto flutuante: volume do combustível ($0.0$ a $50.0$ litros) e taxa de consumo de combustível ($0.0$ a $20.0$ L/h). Calcular a autonomia do veículo de forma segura contra falhas matemáticas (divisão por zero) e apresentar no LCD de 20 colunas e 4 linhas.
*   **Nível Final (Desafio):**
    1.  Otimizar o display contra oscilações utilizando o Filtro de Estado.
    2.  Desenhar de forma dinâmica uma barra de progresso horizontal gráfica na Linha 2 do display LCD utilizando caracteres sólidos (bloco preenchido com o código `char(255)`).
    3.  Implementar controle de nível em reserva: se o volume for menor que $5.0$ litros, deve acender o LED indicador físico (Pino 7), e o rótulo da Linha 3 do LCD deve mudar dinamicamente de `Autonomia:` para `!RESERVA!`. Caso contrário, apaga o LED de alarme e exibe a mensagem de autonomia normal.

---

## 2. Cenário e Teoria

### Proteção Contra Divisão por Zero
Em programação de sistemas embarcados, falhas matemáticas como tentar dividir um número por zero podem travar o processador ou produzir valores inválidos (como `NaN` ou `Infinity`). 
Ao calcular a autonomia de combustível ($Autonomia = Volume / Consumo$), se o potenciômetro de consumo estiver no mínimo ($0.0$ L/h), haverá uma tentativa de divisão por zero.
Para contornar este problema crítico, devemos usar uma estrutura condicional:

```cpp
if (consumo < 0.1) {
  // Define que a autonomia é "infinita" ou zero e avisa o sistema
  divisaoPorZero = true;
} else {
  autonomia = volume / consumo;
}
```

### Barra de Progresso Gráfica no LCD
Displays LCD de caracteres possuem 256 posições na tabela ASCII padrão. O caractere de código **255** representa um bloco totalmente preenchido (sólido).
Para desenhar uma barra de progresso de 10 segmentos:
1.  Descubra o percentual atual do volume do tanque (escala de 0% a 100%).
2.  Divida o percentual por 10 para saber quantos blocos sólidos (0 a 10) devem ser acesos.
3.  Utilize um laço de repetição `for` de 10 passos para imprimir `char(255)` para blocos preenchidos e espaço em branco `" "` para blocos vazios:

```cpp
int blocos = percentual / 10;
for (int i = 0; i < 10; i++) {
  if (i < blocos) {
    LCD.write(255); // Bloco preenchido
  } else {
    LCD.print(" "); // Espaço vazio
  }
}
```

---

## 3. Componentes e Conexões (Wokwi)
*   **Arduino Uno R3**
*   **Display LCD 20x4 (Ligação Paralela)**
    *   `RS` -> Pino 12 | `E` -> Pino 11
    *   `D4` -> Pino 5 | `D5` -> Pino 4 | `D6` -> Pino 3 | `D7` -> Pino 2
    *   `VCC` -> 5V | `GND` -> GND
*   **Potenciômetro 1 (Nível Combustível):** Cursor no pino analógico `A0`
*   **Potenciômetro 2 (Consumo):** Cursor no pino analógico `A1`
*   **LED de Alerta de Reserva:** Conectado no pino digital **7** (com resistor de 220 ohms)

---

## 4. O Desafio (Mão na Massa)
1.  **Ponto de Partida:** Abra o arquivo [telemetria_combustivel.ino](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/telemetria_combustivel.ino).
2.  **Tarefa Intermediária:** Complete os `# TODO` para realizar as leituras analógicas das entradas de volume e consumo, proteja a equação matemática contra divisão por zero e escreva no LCD de forma simples (mesmo com flicker).
3.  **Tarefa Final (Desafio):**
    *   Implemente o Filtro de Estado para remover oscilações.
    *   Desenhe a barra de progresso gráfica com os blocos no LCD de 20x4.
    *   Ligue a saída do LED Vermelho no pino 7 e implemente a alteração visual dinâmica do texto de alarme (`!RESERVA!`) quando o tanque cair abaixo de $5.0$ litros.

---

## 5. ✅ Checklist de Entrega
1.  **Etapa Intermediária:** Leitura em ponto flutuante calibrada e exibição correta dos valores de volume e consumo com proteção contra divisões inválidas.
2.  **Etapa Final:** Barra gráfica de 10 segmentos funcional, controle de nível de alarme acendendo o LED físico 7 e redefinindo dinamicamente as strings do LCD para `!RESERVA!` e `Autonomia:`, operando de forma otimizada (no-flicker).
3.  **Reflexão Técnica:** Preenchimento da reflexão obrigatória no cabeçalho do arquivo [telemetria_combustivel.ino](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/telemetria_combustivel.ino).
4.  **Explicação Oral:** Explicação da aritmética por trás da lógica da barra de progresso e o funcionamento da validação preventiva contra divisão por zero.

---

## 6. Conexão com a Indústria (APL/RS) 🏭
*Reflexão contextualizada para o Rio Grande do Sul:*
No APL de Máquinas e Implementos Agrícolas (região de Não-Me-Toque e Passo Fundo/RS), tratores e colheitadeiras possuem painéis locais eletrônicos robustos para monitorar o tanque de combustível e arla32 em campo. A prevenção de falhas de hardware/software nestes veículos e a rápida percepção ergonômica de combustível pelo operador rural via barras de progresso evitam paradas indesejadas de maquinário agrícola em colheitas críticas.

---

## 7. 🧠 Reflexão Técnica (No Código)
Responda à pergunta teórica obrigatória contida no cabeçalho do arquivo [telemetria_combustivel.ino](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/telemetria_combustivel.ino).

---

## 🤖 Dica de Prompt para IA (Uso Saudável)
> *"Estou no Experimento 3 de Arduino. Preciso calcular a autonomia dividindo o volume do tanque (0 a 50L) pelo consumo (0 a 20 L/h). Como posso estruturar uma rotina em C que impeça a divisão por zero caso o consumo seja nulo ou muito próximo a zero? Não me dê o código pronto."*

---

## 8. Referências e Documentação Oficial
Para aprofundar seu conhecimento sobre a sintaxe, hardware e funções utilizadas, consulte os seguintes links no Portal do Arduino:
-   [Documentação da Biblioteca LiquidCrystal](https://www.arduino.cc/reference/en/libraries/liquidcrystal/) — Instruções de uso e funções para displays de cristal líquido.
-   [Referência da Função pinMode()](https://www.arduino.cc/reference/pt/language/functions/digital-io/pinmode/) — Configuração de um pino digital como entrada ou saída.
-   [Referência da Função digitalWrite()](https://www.arduino.cc/reference/pt/language/functions/digital-io/digitalwrite/) — Escrita de estados lógicos HIGH ou LOW em pinos de saída digital.
-   [Referência da Função analogRead()](https://www.arduino.cc/reference/pt/language/functions/analog-io/analogread/) — Leitura dos canais conversores de sinal analógico para digital (ADC).
-   [Referência da Função map()](https://www.arduino.cc/reference/pt/language/functions/math/map/) — Sintaxe matemática do mapeamento proporcional de valores.
-   [Referência da Função delay()](https://www.arduino.cc/reference/pt/language/functions/time/delay/) — Pausa na execução do programa por um período de tempo em milissegundos.
-   [Página de Referência Geral da Linguagem (Português)](https://www.arduino.cc/reference/pt/) — Dicionário de comandos, estruturas de repetição e tipos de variáveis em C++.
