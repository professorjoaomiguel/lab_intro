# Experimento 01: Monitor Térmico das Baterias (VoltLog)

Este guia orienta o desenvolvimento do primeiro experimento prático de Arduino no simulador Wokwi Web, inserido no contexto de mobilidade elétrica da startup **VoltLog**.

---

## 🧭 Guia do Aluno: Como Iniciar
1.  **Onde programar:** Abra o arquivo [conversao_temperatura.ino](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/conversao_temperatura.ino) localizado nesta pasta. Ele é o seu template de trabalho e contém comentários marcados com `# TODO` onde você deve inserir seu código.
2.  **Como simular no Wokwi Web (Navegador):**
    *   Acesse [wokwi.com/projects/new/arduino-uno](https://wokwi.com/projects/new/arduino-uno).
    *   Substitua o conteúdo da aba **`diagram.json`** no simulador pelo conteúdo do arquivo [diagram.json](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/diagram.json) desta pasta para carregar o circuito automaticamente.
    *   Copie o código de [conversao_temperatura.ino](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/conversao_temperatura.ino) e cole-o no arquivo de código principal do simulador (`sketch.ino`).
    *   *(Opcional)* Crie um arquivo `README.md` no Wokwi e cole o conteúdo deste roteiro para lê-lo diretamente na tela da simulação. Consulte o [Guia de Início Rápido do Wokwi Web](file:///C:/GitHub/lab_intro/docs/Guia_Wokwi_Inicio_Rapido.md) para mais detalhes.

---

## 1. O Cenário da Atividade: A Bateria da **VoltLog**
Os veículos de entrega rápidos da **VoltLog** são 100% elétricos e equipados com bancos de baterias de íons de lítio. Sob alta carga (como subidas na serra gaúcha), essas células aquecem e precisam ser monitoradas constantemente por segurança.
Seu trabalho como programador da VoltLog é desenvolver o firmware do **Painel de Monitoramento Térmico** (IHM) do painel do motorista utilizando o display **LCD 20x4**.

*   **Nível Intermediário:** Realizar a leitura analógica do sensor de temperatura (potenciômetro em A0), mapeá-la para a faixa de $0$ a $60^{\circ}\text{C}$, converter para Fahrenheit e exibir Celsius e Fahrenheit no LCD 20x4.
*   **Nível Final (Desafio):** 
    1.  Otimizar o display contra oscilações (*flicker*), atualizando os números na tela apenas quando a temperatura mudar.
    2.  Implementar o sistema de alarme visual: se a temperatura atingir $40^{\circ}\text{C}$ ou mais, aciona o LED Vermelho de Alerta (Pino 7), desliga o LED Verde (Pino 8) e imprime `ALERTA` na tela (avisando o acionamento do cooler). Caso contrário, mantém o LED Verde (Pino 8) ligado (temperatura segura), LED Vermelho desligado e imprime `OK` no LCD.

---

## 2. Cenário e Teoria

### A Função `map()`
No Arduino Uno, a leitura de um sensor analógico de tensão de 0V a 5V (potenciômetro) é mapeada para uma escala digital de **0 a 1023**.
Para converter proporcionalmente a leitura do sensor em uma temperatura de $0$ a $60^{\circ}\text{C}$, utilizamos a função `map()`. 

#### Sintaxe:
```cpp
long map(long valor, long deMin, long deMax, long paraMin, long paraMax);
```

#### Como funciona matematicamente?
A função realiza uma interpolação linear utilizando a seguinte fórmula:

$$y = (valor - deMin) \times \frac{paraMax - paraMin}{deMax - deMin} + paraMin$$

No código do Arduino, mapeamos o sensor térmico usando:
```cpp
int tempC = map(leituraSensor, 0, 1023, 0, 60);
```

### Conversão Celsius para Fahrenheit
A conversão matemática clássica é dada pela fórmula:

$$F = C \times 1.8 + 32$$

No código C/C++ do Arduino, lembre-se de usar números de ponto flutuante (`1.8` ou `9.0 / 5.0`) para evitar o truncamento da divisão inteira.

---

### O Display LCD (HD44780) e o Flicker (Cintilação)
Displays LCD de caracteres possuem comunicação lenta. A chamada `LCD.clear()` leva cerca de **1,64 milissegundos** no hardware, pois o controlador desliga fisicamente os pixels. 
Se você limpar a tela continuamente dentro do `loop()`, o display passará mais tempo desligado do que exibindo informações estáticas, causando um tremor visual constante (**flicker**).

### Estratégia de Software: Atualização por Filtro de Estado
Para evitar o flicker em painéis profissionais:
1.  **Escrita Estática Única (setup):** Escreva rótulos fixos como `"PAINEL DE TEMPERATURA"`, `"Celsius:"`, `"Fahrenheit:"` e `"Status:"` apenas uma vez no `setup()`.
2.  **Comparação de Estado (loop):** Crie uma variável global `ultimoTempC` para registrar o último valor impresso.
3.  **Escrita Dinâmica sob Demanda:** O programa só escreve no display se a temperatura atual for diferente da última lida (`if (tempC != ultimoTempC)`).
4.  **Sobrescrita de Resíduos:** Limpe com espaços em branco `"   "` o local do número antigo antes de imprimir o novo para não acumular dígitos fantasmas (ex: `10` caindo para `9` e exibindo `90` por resíduo).

---

## 3. Componentes e Conexões
*   **Arduino Uno R3**
*   **Display LCD 20x4 (Ligação Paralela)**
    *   `RS` -> Pino 12 | `E` -> Pino 11
    *   `D4` -> Pino 5 | `D5` -> Pino 4 | `D6` -> Pino 3 | `D7` -> Pino 2
    *   `VCC` -> 5V | `GND` -> GND
*   **Sensor Térmico (Potenciômetro):** Cursor conectado ao pino analógico `A0`
*   **LED Vermelho (Alerta Bateria):** Conectado no pino digital 7 (com resistor de 220 ohms)
*   **LED Verde (Bateria Segura):** Conectado no pino digital 8 (com resistor de 220 ohms)

---

## 4. O Desafio (Mão na Massa)
1.  **Ponto de Partida:** Abra o arquivo [conversao_temperatura.ino](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/conversao_temperatura.ino).
2.  **Tarefa Intermediária:** Complete o código nas seções `# TODO` para realizar as leituras analógicas e imprimir no LCD. A tela pode piscar nesta etapa.
3.  **Tarefa Final (Desafio):** 
    *   Implemente a lógica de no-flicker (redesenho dinâmico somente sob variação).
    *   Implemente a lógica de controle de estado: se a temperatura atingir $40^{\circ}\text{C}$ ou mais, acione o LED vermelho, desligue o verde e mostre `ALERTA` no LCD. Caso contrário, mantenha o LED verde aceso, o vermelho apagado e exiba `OK` no LCD.

---

## 5. ✅ Checklist de Entrega
1.  **Etapa Intermediária:** Temperatura calculada e exibida no display.
2.  **Etapa Final:** Circuito operando no Wokwi sem piscar a tela, com controle de status visual de LEDs e exibição de `OK`/`ALERTA` no LCD 20x4.
3.  **Reflexão Técnica:** Preenchimento da reflexão obrigatória no cabeçalho do arquivo [conversao_temperatura.ino](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/conversao_temperatura.ino).
4.  **Explicação Oral:** Capacidade de explicar a lógica matemática do mapeamento e a lógica de condicionais para alarmes.

---

## 6. Conexão com a Indústria (APL/RS) 🏭
*Reflexão contextualizada para o Rio Grande do Sul:*
Na serra gaúcha (APL Vitivinícola) e na região metropolitana (APL Metalmecânico), a medição e sinalização local de temperatura e umidade em silos, adegas de maturação de vinhos ou caldeiras é crucial para a segurança do operador e a qualidade do produto. Exibições IHMs locais robustas e otimizadas evitam erros humanos de leitura causados por oscilações visuais de tela.

---

## 7. 🧠 Reflexão Técnica (No Código)
Responda à pergunta teórica obrigatória contida no cabeçalho do arquivo [conversao_temperatura.ino](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/conversao_temperatura.ino).

---

## 🤖 Dica de Prompt para IA (Uso Saudável)
> *"Estou no Experimento 1 de Arduino. Preciso ler um potenciômetro em A0 e mostrar Celsius e Fahrenheit em um LCD 20x4. Não me dê o código completo. Explique como usar a função map do Arduino para reescalar 0-1023 para 0-60 e como fazer a conversão matemática sem perder as casas decimais no cálculo em C++."*

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
