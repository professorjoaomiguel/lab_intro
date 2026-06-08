# Experimento 01: Conversão de Temperatura com Display LCD (Tinkercad Clássico)

Este guia orienta o desenvolvimento do primeiro experimento prático de Arduino no simulador Tinkercad. Leia atentamente as seções abaixo para entender as etapas, a teoria por trás da atividade e como simular o circuito.

---

## 🧭 Guia do Aluno: Como Iniciar
1.  **Onde programar:** Abra o arquivo [conversao_temperatura.ino](file:///C:/GitHub/lab_intro/tinkercad/conversao_temperatura/conversao_temperatura.ino) localizado nesta pasta. Ele é o seu template de trabalho e contém comentários marcados com `# TODO` onde você deve inserir seu código.
2.  **Onde simular:** 
    *   **Tinkercad:** Acesse sua conta no [Tinkercad](https://www.tinkercad.com/). Crie um novo circuito contendo um Arduino Uno e um display LCD 16x2 de acordo com a pinagem. Copie o código do arquivo `.ino` e cole-o na aba de Código (modo Texto) para testar e simular.

---

## 1. Objetivos de Aprendizagem
*   **Nível Intermediário:** Realizar a leitura analógica de um potenciômetro em A0, mapeá-la para uma faixa de $0$ a $60^{\circ}\text{C}$, converter para Fahrenheit e exibir ambas as informações no LCD 16x2.
*   **Nível Final (Desafio):** Otimizar o código para eliminar completamente a oscilação (*flicker*) do display LCD, redesenhando os dados apenas quando o valor sofrer alteração.

---

## 2. Cenário e Teoria

### A Função `map()`
No Arduino Uno, o Conversor Analógico-Digital (ADC) possui resolução de 10 bits. Isso significa que a leitura de um sensor de tensão analógico de 0V a 5V (como o potenciômetro) é mapeada para uma escala numérica inteira de **0 a 1023**.

Para converter esse valor proporcionalmente em uma escala física diferente (como graus Celsius de $0$ a $60^{\circ}\text{C}$), utilizamos a função `map()`. 

#### Sintaxe:
```cpp
long map(long valor, long deMin, long deMax, long paraMin, long paraMax);
```

#### Como funciona matematicamente?
A função realiza uma interpolação linear utilizando a seguinte fórmula:

$$y = (valor - deMin) \times \frac{paraMax - paraMin}{deMax - deMin} + paraMin$$

No caso da nossa atividade, para transformar o valor analógico do potenciômetro (`0` a `1023`) para a escala de temperatura (`0` a `60`), usamos:
```cpp
int tempC = map(potenciometro, 0, 1023, 0, 60);
```

### Conversão Celsius para Fahrenheit
A conversão matemática clássica é dada pela fórmula:

$$F = C \times 1.8 + 32$$

No código C/C++ do Arduino, lembre-se de usar números reais (`9.0` e `5.0` ou `1.8`) na divisão/multiplicação para evitar o truncamento da divisão inteira.

---

### O Display LCD (HD44780) e a Origem do Flicker (Cintilação)
Displays LCD de caracteres (como o modelo de 16 colunas e 2 linhas) possuem um controlador interno que gerencia o acendimento físico dos cristais líquidos. A comunicação com este circuito integrado auxiliar é relativamente lenta se comparada ao clock do Arduino:
*   **O comando `LCD.clear()`:** Ao chamar a função `LCD.clear()`, o controlador interno do LCD desliga fisicamente todos os pixels e envia o cursor para a posição inicial. Essa operação exige cerca de **1,64 milissegundos** para ser finalizada no hardware.
*   **Como o flicker acontece:** Se o programa do microcontrolador executar comandos de limpeza total ou reescrever textos fixos repetidamente dentro do `loop()`, o display passará mais tempo no processo de apagar/redesenhar pixels do que exibindo informações estáticas. Visualmente, isso é percebido como uma **tela piscando constantemente (flicker)**.

### Estratégia de Software: Atualização por Filtro de Estado
A rotina correta de controle de telas em sistemas embarcados segue os seguintes princípios:
1.  **Escrita Estática Única (setup):** Rótulos fixos como `"TempC:      oC"` e `"TempF:      oF"` são definidos apenas uma vez durante a inicialização no `setup()`.
2.  **Comparação de Estado (loop):** Mantemos variáveis globais para registrar a última informação desenhada (ex: `ultimoTempC`).
3.  **Escrita Dinâmica sob Demanda:** Comparamos o valor lido atualmente com a variável de estado. O envio de dados para o display só é feito caso haja mudança real (`if (tempC != ultimoTempC)`).
4.  **Sobrescrita de Resíduos:** Para evitar que o display exiba caracteres "fantasmas" (por exemplo, o número `10` caindo para `9` e exibindo `90` por não limpar a segunda casa decimal), posicionamos o cursor, escrevemos espaços em branco (`"    "`) para apagar o resíduo anterior e só então escrevemos o novo valor.

---

## 3. Componentes e Conexões
*   **Arduino Uno R3**
*   **Display LCD 16x2 (Ligação Paralela)**
    *   `RS` -> Pino 12 | `E` -> Pino 11
    *   `D4` -> Pino 5 | `D5` -> Pino 4 | `D6` -> Pino 3 | `D7` -> Pino 2
    *   `VCC` -> 5V | `GND` -> GND
*   **Potenciômetro:** Cursor no pino analógico `A0`

---

## 4. O Desafio (Mão na Massa)
1.  **Ponto de Partida:** Abra o arquivo [conversao_temperatura.ino](file:///C:/GitHub/lab_intro/tinkercad/conversao_temperatura/conversao_temperatura.ino).
2.  **Tarefa Intermediária:** Complete o código nas seções `# TODO` para realizar as leituras analógicas e imprimir no LCD. A tela pode piscar nesta etapa.
3.  **Tarefa Final (Desafio):** Implemente a lógica de no-flicker (redesenho dinâmico somente sob variação).

---

## 5. ✅ Checklist de Entrega
1.  **Etapa Intermediária:** Temperatura calculada e exibida no display.
2.  **Etapa Final:** Circuito operando no Tinkercad sem piscar a tela.
3.  **Reflexão Técnica:** Preenchimento da reflexão obrigatória no cabeçalho do arquivo [conversao_temperatura.ino](file:///C:/GitHub/lab_intro/tinkercad/conversao_temperatura/conversao_temperatura.ino).
4.  **Explicação Oral:** Capacidade de explicar a lógica matemática do mapeamento e a eliminação de flicker.

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
