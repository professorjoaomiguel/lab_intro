# Experimento 01: Conversão de Temperatura com Display LCD

## 1. Objetivos de Aprendizagem
*   **Nível Intermediário:** Realizar a leitura analógica de um potenciômetro, mapeá-la para uma faixa de $0$ a $60^{\circ}\text{C}$, converter para Fahrenheit e exibir ambas as informações no LCD 16x2.
*   **Nível Final (Desafio):** 
    1.  Otimizar o código para eliminar completamente a oscilação (*flicker*) do display LCD, redesenhando os dados apenas quando o valor sofrer alteração.
    2.  Implementar controle de estado visual (Alerta de Temperatura): se a temperatura for maior ou igual a $40^{\circ}\text{C}$, liga o LED Vermelho (Pino 7), desliga o LED Verde (Pino 8) e escreve `ALERTA` no LCD. Caso contrário (temperatura normal), mantém o LED Verde (Pino 8) ligado, o LED Vermelho desligado e escreve `OK` no LCD.

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

$$F = C \times \frac{9}{5} + 32$$

No código C/C++ do Arduino, lembre-se de usar números reais (`9.0` e `5.0`) na divisão para evitar o truncamento da divisão inteira.

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

## 3. Componentes e Conexões (Wokwi)
*   **Arduino Uno R3**
*   **Display LCD 16x2 (Ligação Paralela)**
    *   `RS` -> Pino 12 | `E` -> Pino 11
    *   `D4` -> Pino 5 | `D5` -> Pino 4 | `D6` -> Pino 3 | `D7` -> Pino 2
    *   `VCC` -> 5V | `GND` -> GND
*   **Potenciômetro:** Cursor no pino analógico `A0`
*   **LED Vermelho (Alerta Temp Alta):** Conectado no pino digital 7 (com resistor de 220 ohms)
*   **LED Verde (Status Normal):** Conectado no pino digital 8 (com resistor de 220 ohms)

---

## 4. O Desafio (Mão na Massa)
1.  **Ponto de Partida:** Abra o arquivo [conversao_temperatura_template.ino](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/conversao_temperatura_template.ino).
2.  **Tarefa Intermediária:** Complete o código nas seções `# TODO` para realizar as leituras analógicas e imprimir no LCD. A tela pode piscar nesta etapa.
3.  **Tarefa Final (Desafio):** 
    *   Implemente a lógica de no-flicker (redesenho dinâmico somente sob variação).
    *   Implemente a lógica de controle de estado: se a temperatura atingir $40^{\circ}\text{C}$ ou mais, acione o LED vermelho, desligue o verde e mostre `ALERTA` no LCD. Caso contrário, mantenha o LED verde aceso, o vermelho apagado e exiba `OK` no LCD.

---

## 5. ✅ Checklist de Entrega
1.  **Etapa Intermediária:** Temperatura calculada e exibida no display.
2.  **Etapa Final:** Circuito operando sem piscar a tela, com controle de status visual de LEDs e exibição de `OK`/`ALERTA` no LCD a partir de 40 °C.
3.  **Reflexão Técnica:** Preenchimento da reflexão obrigatória no código-fonte.
4.  **Explicação Oral:** Capacidade de explicar as conexões físicas, a lógica matemática do mapeamento e a lógica de condicionais para alarmes.

---

## 6. Conexão com a Indústria (APL/RS) 🏭
*Reflexão contextualizada para o Rio Grande do Sul:*
Na serra gaúcha (APL Vitivinícola) e na região metropolitana (APL Metalmecânico), a medição e sinalização local de temperatura e umidade em silos, adegas de maturação de vinhos ou caldeiras é crucial para a segurança do operador e a qualidade do produto. Exibições IHMs locais robustas e otimizadas evitam erros humanos de leitura causados por oscilações visuais de tela.

---

## 7. 🧠 Reflexão Técnica (No Código)
Responda à pergunta teórica obrigatória contida no cabeçalho do arquivo [conversao_temperatura_template.ino](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/conversao_temperatura_template.ino).

---

## 🤖 Dica de Prompt para IA (Uso Saudável)
> *"Estou no Experimento 1 de Arduino. Preciso ler um potenciômetro em A0 e mostrar Celsius e Fahrenheit em um LCD 16x2. **Não me dê o código completo**. Explique como usar a função map do Arduino para reescalar 0-1023 para 0-60 e como fazer a conversão matemática sem perder as casas decimais no cálculo em C++."*

---

## 8. Referências e Documentação Oficial
Para aprofundar seu conhecimento sobre a sintaxe, hardware e funções utilizadas, consulte os seguintes links no Portal do Arduino:
-   [Documentação da Biblioteca LiquidCrystal](https://www.arduino.cc/reference/en/libraries/liquidcrystal/) — Descrição geral das chamadas de métodos para displays de cristal líquido.
-   [Referência da Função map()](https://www.arduino.cc/reference/pt/language/functions/math/map/) — Sintaxe matemática do mapeamento proporcional de valores.
-   [Referência da Função analogRead()](https://www.arduino.cc/reference/pt/language/functions/analog-io/analogread/) — Leitura dos canais conversores de sinal analógico para digital (ADC).
-   [Página de Referência Geral da Linguagem (Português)](https://www.arduino.cc/reference/pt/) — Dicionário de comandos, estruturas de repetição e tipos de variáveis em C++.
