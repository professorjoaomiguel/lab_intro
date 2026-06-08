# Experimento 02: Computador de Tarifação Dinâmica - Car Sharing (VoltLog)

Este guia orienta o desenvolvimento do segundo experimento prático de Arduino no simulador Wokwi Web, inserido no contexto de mobilidade elétrica da startup **VoltLog**.

---

## 🧭 Guia do Aluno: Como Iniciar
1.  **Onde programar:** Abra o arquivo [aluguel_carro.ino](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/aluguel_carro.ino) localizado nesta pasta. Ele é o seu template de trabalho e contém comentários marcados com `# TODO` onde você deve inserir seu código.
2.  **Como simular no Wokwi Web (Navegador):**
    *   Acesse [wokwi.com/projects/new/arduino-uno](https://wokwi.com/projects/new/arduino-uno).
    *   Substitua o conteúdo da aba **`diagram.json`** no simulador pelo conteúdo do arquivo [diagram.json](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/diagram.json) desta pasta para carregar o circuito automaticamente.
    *   Copie o código de [aluguel_carro.ino](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/aluguel_carro.ino) e cole-o no arquivo de código principal do simulador (`sketch.ino`).
    *   *(Opcional)* Crie um arquivo `README.md` no Wokwi e cole o conteúdo deste roteiro para lê-lo diretamente na tela da simulação. Consulte o [Guia de Início Rápido do Wokwi Web](file:///C:/GitHub/lab_intro/docs/Guia_Wokwi_Inicio_Rapido.md) para mais detalhes.

---

## 1. O Cenário da Atividade: Car Sharing na **VoltLog**
A **VoltLog** disponibiliza seus utilitários elétricos de carga para entregadores parceiros por turnos de trabalho. Ao término do turno, o entregador encerra a corrida e o computador de bordo embarcado calcula em tempo real o valor final da locação com base no uso.
Seu desafio é programar esse firmware de tarifação dinâmica no painel do veículo com display **LCD 20x4**.

*   **Nível Intermediário:** Ler e reescalar duas entradas analógicas independentes representando o tempo de turno (potenciômetro A0, de $1$ a $30$ dias) e a distância percorrida (potenciômetro A1, de $1$ a $1000$ km). Calcular o valor final da locação com 10% de desconto de fidelidade e exibi-lo no LCD 20x4.
*   **Nível Final (Desafio):** 
    1.  Otimizar o código para eliminar a oscilação (*flicker*) do display LCD 20x4.
    2.  Integrar uma chave física (slide switch no pino 9) para selecionar o tipo de veículo alugado:
        *   **LOW (Popular - `POP`):** Utiliza tarifas mais baixas: diária de R$ 30,00 e R$ 0,01 por km.
        *   **HIGH (Utilitário SUV - `SUV`):** Veículo pesado de carga: diária de R$ 80,00 e R$ 0,05 por km.
        *   Exibir o rótulo da categoria no LCD dentro de colchetes, ex: `[POP]` ou `[SUV]`.

---

## 2. Cenário e Teoria

### Mapeamento de Múltiplas Entradas Analógicas
No Arduino Uno, controlamos duas grandezas independentes via dois potenciômetros:
1.  **Tempo de Locação:** Conectado ao pino analógico `A0` e remapeado de `0 a 1023` para a faixa de `1 a 30` dias.
2.  **Distância Percorrida:** Conectado ao pino analógico `A1` e remapeado de `0 a 1023` para a faixa de `1 a 1000` km.

Exemplo de mapeamento múltiplo:
```cpp
int tempo = map(analogRead(A0), 0, 1023, 1, 30);
int distancia = map(analogRead(A1), 0, 1023, 1, 1000);
```

---

### O Display LCD (HD44780) e a Origem do Flicker (Cintilação)
Displays LCD de caracteres possuem comunicação lenta. A chamada `LCD.clear()` leva cerca de **1,64 milissegundos** no hardware, pois o controlador desliga fisicamente os pixels. 
Se você limpar a tela continuamente dentro do `loop()`, o display passará mais tempo desligado do que exibindo informações estáticas, causando um tremor visual constante (**flicker**).

### Estratégia de Software: Atualização por Filtro de Estado Multi-Variável
A rotina de controle de telas profissional segue os seguintes princípios:
1.  **Escrita Estática Única (setup):** Rótulos fixos como `"LOCADORA SAI FRENTE"`, `"Tempo:    dias"`, `"Dist:     km  [   ]"` e `"Total: R$ "` são definidos apenas uma vez durante a inicialização no `setup()`.
2.  **Comparação de Estado Composto (loop):** Mantemos variáveis globais para registrar os últimos valores exibidos (`ultimoTempo`, `ultimaDistancia`, `ultimaCategoria`).
3.  **Escrita Dinâmica sob Demanda com Operador Lógico `||`:** Comparamos os valores atuais com os anteriores. O envio de dados para o display só é feito se o tempo, a distância **ou** a categoria sofrerem alteração:
    `if (tempo != ultimoTempo || distancia != ultimaDistancia || categoria != ultimaCategoria)`
4.  **Sobrescrita de Resíduos:** Para evitar caracteres "fantasmas", posicionamos o cursor, escrevemos espaços em branco (`"   "`) para apagar o resíduo anterior e só então escrevemos o novo valor.

---

## 3. Componentes e Conexões
*   **Arduino Uno R3**
*   **Display LCD 20x4 (Ligação Paralela)**
    *   `RS` -> Pino 12 | `E` -> Pino 11
    *   `D4` -> Pino 5 | `D5` -> Pino 4 | `D6` -> Pino 3 | `D7` -> Pino 2
    *   `VCC` -> 5V | `GND` -> GND
*   **Potenciômetro 1 (Tempo):** Cursor no pino analógico `A0`
*   **Potenciômetro 2 (Distância):** Cursor no pino analógico `A1`
*   **Chave Slide (Seletor de Categoria):** Pino central conectado ao pino digital **9** (utilizando pull-up interno: `INPUT_PULLUP`). Outro pino ao GND.

---

## 4. O Desafio (Mão na Massa)
1.  **Ponto de Partida:** Abra o arquivo [aluguel_carro.ino](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/aluguel_carro.ino).
2.  **Tarefa Intermediária:** Complete a lógica do cálculo e a fiação no simulador. Realize a apresentação no LCD no seguinte padrão de texto (mesmo com flicker):
    ```text
    LOCADORA SAI FRENTE
    Tempo: 12 dias
    Dist: 1000 km  [POP]
    Total: R$ 306.00
    ```
3.  **Tarefa Final (Desafio):** 
    *   Implemente a fiação da chave slide e a lógica condicional para mudar as tarifas (POP vs SUV).
    *   Elimine a oscilação do display: as etiquetas fixas (`LOCADORA SAI FRENTE`, `Tempo:    dias`, `Dist:     km  [   ]`, `Total: R$ `) devem ser escritas somente no `setup()`. A escrita dinâmica no `loop()` só pode ocorrer se `tempo != ultimoTempo` **ou** `distancia != ultimaDistancia` **ou** `categoria != ultimaCategoria`.

---

## 5. ✅ Checklist de Entrega
1.  **Etapa Intermediária:** Leitura simultânea das duas faixas de dados e cálculo matemático correto exibido no LCD 20x4.
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
-   [Página de Referência Geral da Linguagem (Português)](https://www.arduino.cc/reference/pt/) — Dicionário de comandos, estruturas de repetição e tipos de variáveis em C++.
