# Experimento 02: Cálculo de Aluguel de Carro com Display LCD

Este guia orienta o desenvolvimento do segundo experimento prático de Arduino. Leia atentamente as seções abaixo para entender as etapas, a teoria por trás da atividade e como simular o circuito.

---

## 🧭 Guia do Aluno: Como Iniciar
1.  **Onde programar:** Abra o arquivo [aluguel_carro.ino](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/aluguel_carro.ino) localizado nesta pasta. Ele é o seu template de trabalho e contém comentários marcados com `# TODO` onde você deve inserir seu código.
2.  **Onde simular:** 
    *   **VS Code:** Certifique-se de ter a extensão **Wokwi Simulator** instalada. Pressione a tecla **F1**, selecione `Wokwi: Start Simulator` (ou abra o arquivo `diagram.json` e clique no botão verde de play no circuito).
    *   **Wokwi Web:** Consulte o [Guia de Início Rápido do Wokwi Web](file:///C:/GitHub/lab_intro/docs/Guia_Wokwi_Inicio_Rapido.md) na pasta `docs/` para colar o layout do hardware (`diagram.json`) e seu código.

---

## 1. Objetivos de Aprendizagem
*   **Nível Intermediário:** Implementar a lógica de leitura de duas entradas analógicas independentes, convertendo-as para as faixas de tempo ($1$ a $30$ dias) e distância ($1$ a $1000$ km). Calcular o valor final com 10% de desconto e exibi-los no LCD 16x2.
*   **Nível Final (Desafio):** 
    1.  Integrar a detecção de mudança de estado duplo para que o LCD seja atualizado apenas sob variação em alguma das entradas, eliminando a oscilação (*flicker*) do display.
    2.  Implementar controle de categoria do veículo via hardware: use uma chave tipo slide no pino **9** (`INPUT_PULLUP`). 
        - Chave em `LOW` (Esquerda): Categoria **Popular** (`POP`) com diária de R$ 30,00 e R$ 0,01 por km.
        - Chave em `HIGH` (Direita): Categoria **SUV** (`SUV`) com diária de R$ 80,00 e R$ 0,05 por km.
        - Exibir o indicador da categoria (`POP` ou `SUV`) no LCD.

---

## 2. Cenário e Teoria

### O Problema da Locadora "Sai da Frente"
O algoritmo deve calcular o valor total de uma locação junina nas seguintes condições:
*   Preço da diária: **R$ 30,00** (Popular) ou **R$ 80,00** (SUV).
*   Preço por quilômetro rodado: **R$ 0,01** (Popular) ou **R$ 0,05** (SUV).
*   Desconto especial: **10%** sobre o valor total ($Total \times 0.9$).

### Mapeamento de Múltiplas Entradas Analógicas
Diferente da atividade de termômetro, aqui controlamos duas grandezas independentes. Usaremos dois potenciômetros:
1.  **Tempo de Locação:** Conectado ao pino analógico `A0` e remapeado de `0 a 1023` para a faixa de `1 a 30` dias.
2.  **Distância Percorrida:** Conectado ao pino analógico `A1` e remapeado de `0 a 1023` para a faixa de `1 a 1000` km.

Exemplo de mapeamento múltiplo:
```cpp
int tempo = map(analogRead(A0), 0, 1023, 1, 30);
int distancia = map(analogRead(A1), 0, 1023, 1, 1000);
```

---

### O Display LCD (HD44780) e a Origem do Flicker (Cintilação)
Displays LCD de caracteres (como o modelo de 16 colunas e 2 linhas) possuem um controlador interno que gerencia o acendimento físico dos cristais líquidos. A comunicação com este circuito integrado auxiliar é relativamente lenta se comparada ao clock do Arduino:
*   **O comando `LCD.clear()`:** Ao chamar a função `LCD.clear()`, o controlador interno do LCD desliga fisicamente todos os pixels e envia o cursor para a posição inicial. Essa operação exige cerca de **1,64 milissegundos** para ser finalizada no hardware.
*   **Como o flicker acontece:** Se o programa do microcontrolador executar comandos de limpeza total ou reescrever os textos fixos repetidamente dentro do `loop()`, o display passará mais tempo no processo de apagar/redesenhar pixels do que exibindo informações estáticas. Visualmente, isso é percebido como uma **tela piscando constantemente (flicker)**.

### Estratégia de Software: Atualização por Filtro de Estado Multi-Variável
A rotina correta de controle de telas em sistemas embarcados segue os seguintes princípios:
1.  **Escrita Estática Única (setup):** Rótulos fixos como `"T:   d  D:    km"` e `"Total: R$       "` são definidos apenas uma vez durante a inicialização no `setup()`.
2.  **Comparação de Estado Composto (loop):** Mantemos variáveis globais para registrar os últimos valores exibidos (`ultimoTempo` e `ultimaDistancia`).
3.  **Escrita Dinâmica sob Demanda com Operador Lógico `||`:** Comparamos os valores atuais com os anteriores. O envio de dados para o display só é feito se o tempo **ou** a distância sofrerem alteração (`if (tempo != ultimoTempo || distancia != ultimaDistancia)`).
4.  **Sobrescrita de Resíduos:** Para evitar que o display exiba caracteres "fantasmas" (por exemplo, a quilometragem cair de `1000` para `9` e exibir `9000` por não limpar as casas decimais extras), posicionamos o cursor, escrevemos espaços em branco (`"    "`) para apagar o resíduo anterior e só então escrevemos o novo valor.

---

## 3. Componentes e Conexões (Wokwi)
*   **Arduino Uno R3**
*   **Display LCD 16x2 (Ligação Paralela)**
    *   `RS` -> Pino 12 | `E` -> Pino 11
    *   `D4` -> Pino 5 | `D5` -> Pino 4 | `D6` -> Pino 3 | `D7` -> Pino 2
    *   `VCC` -> 5V | `GND` -> GND
*   **Potenciômetro 1 (Dias):** Cursor no pino analógico `A0`
*   **Potenciômetro 2 (Distância):** Cursor no pino analógico `A1`
*   **Chave Slide (Seletor de Categoria):** Pino central conectado ao pino digital **9** (utilizando pull-up interno: `INPUT_PULLUP`). Outro pino ao GND.

---

## 4. O Desafio (Mão na Massa)
1.  **Ponto de Partida:** Abra o arquivo [aluguel_carro.ino](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/aluguel_carro.ino).
2.  **Tarefa Intermediária:** Complete a lógica do cálculo e a fiação no simulador. Realize a apresentação no LCD no seguinte padrão de texto (mesmo com flicker):
    ```text
    T:12d K:1000 POP
    Total: R$ 306.00
    ```
3.  **Tarefa Final (Desafio):** 
    *   Implemente a fiação da chave slide e a lógica condicional para mudar as tarifas (POP vs SUV).
    *   Elimine a oscilação do display: as etiquetas fixas (`T:`, `d K:`, `Total: R$`) devem ser escritas somente no `setup()`. A escrita dinâmica no `loop()` só pode ocorrer se `tempo != ultimoTempo` **ou** `distancia != ultimaDistancia` **ou** `categoria != ultimaCategoria`.

---

## 5. ✅ Checklist de Entrega
1.  **Etapa Intermediária:** Leitura simultânea das duas faixas de dados e cálculo matemático correto exibido no LCD.
2.  **Etapa Final:** Controle de tarifas funcional via chave slide mudando o valor da diária, taxa por km e rótulo (`POP`/`SUV`), com visualização suave e sem flicker no display.
3.  **Reflexão Técnica:** Preenchimento da reflexão obrigatória no cabeçalho do arquivo [aluguel_carro.ino](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/aluguel_carro.ino).
4.  **Explicação Oral:** Explicação de como a chave slide altera as constantes da equação de processamento e a lógica condicional complexa de atualização (`||`).

---

## 6. Conexão com a Indústria (APL/RS) 🏭
*Reflexão contextualizada para o Rio Grande do Sul:*
No APL de Logística e Transportes de Carga (região do Porto Seco e fronteira de Uruguaiana/RS) ou no APL de Ecoturismo de Gramado e Canela, sistemas de parametrização local em painéis industriais embarcados são essenciais para configuração inicial de diárias de serviço e taxas operacionais de forma manual e rápida. A robustez de interface com displays é de extrema importância nestes sistemas industriais de campo.

---

## 7. 🧠 Reflexão Técnica (No Código)
Responda à pergunta teórica obrigatória contida no cabeçalho do arquivo [aluguel_carro.ino](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/aluguel_carro.ino).

---

## 🤖 Dica de Prompt para IA (Uso Saudável)
> *"Estou no Experimento 2 de Arduino. Preciso programar o cálculo de aluguel de carro com diária de R$ 30,00 e R$ 0,01 por km rodado, mais 10% de desconto. Como posso implementar a leitura de dois potenciômetros (tempo e distância) no Arduino e atualizar o LCD somente se houver alteração em alguma das duas variáveis? Não me dê o código completo."*

---

## 8. Referências e Documentação Oficial
Para aprofundar seu conhecimento sobre a sintaxe, hardware e funções utilizadas, consulte os seguintes links no Portal do Arduino:
-   [Documentação da Biblioteca LiquidCrystal](https://www.arduino.cc/reference/en/libraries/liquidcrystal/) — Instruções de uso e funções para displays de cristal líquido.
-   [Referência da Função pinMode()](https://www.arduino.cc/reference/pt/language/functions/digital-io/pinmode/) — Configuração de um pino digital como entrada ou saída.
-   [Referência da Função digitalWrite()](https://www.arduino.cc/reference/pt/language/functions/digital-io/digitalwrite/) — Escrita de estados lógicos HIGH ou LOW em pinos de saída digital.
-   [Referência da Função analogRead()](https://www.arduino.cc/reference/pt/language/functions/analog-io/analogread/) — Leitura dos canais conversores de sinal analógico para digital (ADC).
-   [Referência da Função map()](https://www.arduino.cc/reference/pt/language/functions/math/map/) — Sintaxe matemática do mapeamento proporcional de valores.
-   [Referência da Função delay()](https://www.arduino.cc/reference/pt/language/functions/time/delay/) — Pausa na execução do programa por um período de tempo em milissegundos.
-   [Página de Referência Geral da Linguagem (Português)](https://www.arduino.cc/reference/pt/) — Dicionário de comandos, estruturas de repetição e tipos de variáveis in C++.
