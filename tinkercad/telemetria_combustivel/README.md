# Experimento 03: Telemetria de Combustível e Autonomia (LCD 20x4)

## 1. Objetivos de Aprendizagem
*   **Nível Intermediário:** Ler e processar dados de dois potenciômetros (nível de combustível e consumo instantâneo), realizar a divisão de autonomia com tratamento de divisão por zero e exibir os valores numéricos no LCD 20x4.
*   **Nível Final (Desafio):** 
    1.  Eliminar o flicker do display LCD 20x4 com o padrão de filtro de estado composto.
    2.  Implementar uma **barra de progresso horizontal gráfica** no LCD para indicar visualmente a quantidade de combustível.
    3.  Acionar um LED de alerta físico e mostrar um aviso no LCD se a quantidade de combustível cair abaixo do limiar de reserva (menos de 5 litros).

---

## 2. Cenário e Teoria

### Transição Didática: O Display LCD 20x4 (HD44780)
O LCD 20x4 opera exatamente sob o mesmo protocolo físico do LCD 16x2. A pinagem e a biblioteca `LiquidCrystal` utilizada são idênticas. A diferença reside na inicialização e na coordenada de posicionamento:
*   **Inicialização:** `LCD.begin(20, 4);`
*   **Linhas:** O cursor de linha pode ser posicionado de `0` a `3`. O cursor de coluna vai de `0` a `19`.
*   **Vantagem:** O espaço extra permite criar interfaces ricas de telemetria, simulando painéis de controle industriais reais.

### Proteção de Software: Divisão por Zero
A autonomia de tempo é dada pela fórmula física:

$$\text{Autonomia (horas)} = \frac{\text{Volume Restante (Litros)}}{\text{Taxa de Consumo (L/h)}}$$

Se a taxa de consumo for remapeada de forma que seu valor mínimo seja zero, a execução da divisão direta causará uma exceção de hardware ou retornará um valor indefinido (infinito). Em sistemas embarcados, **é obrigatório proteger a CPU contra divisão por zero**:
```cpp
if (consumo == 0.0) {
  autonomia = 99.9; // Valor simbólico de autonomia máxima ou "infinito"
} else {
  autonomia = volume / consumo;
}
```

### Barra de Progresso Gráfica com Caracteres
Para gerar um impacto visual premium, criamos uma barra de progresso textual de 10 caracteres no LCD. Se o tanque está em $100\%$ ($50$ Litros), a barra estará cheia. Se está em $50\%$, exibirá metade.
Para criar a barra, calculamos o número de blocos a serem exibidos:

$$\text{Número de Blocos} = \text{percentual} / 10$$

No LCD, o caractere de código ASCII `255` (`char(255)`) é exibido como um bloco sólido `█`. Podemos preencher a barra escrevendo caracteres de bloco e espaços vazios:
*   Se blocos = 4: `[████      ]` (4 blocos sólidos e 6 espaços).

---

## 3. Componentes e Conexões (Wokwi)
*   **Arduino Uno R3**
*   **Display LCD 20x4 (Ligação Paralela)**
    *   `RS` -> Pino 12 | `E` -> Pino 11
    *   `D4` -> Pino 5 | `D5` -> Pino 4 | `D6` -> Pino 3 | `D7` -> Pino 2
    *   `VCC` -> 5V | `GND` -> GND
*   **Potenciômetro 1 (Nível - A0)**
*   **Potenciômetro 2 (Consumo - A1)**
*   **LED Vermelho de Alerta:** Conectado no Pino Digital 7 (com resistor de 220 ohms)

---

## 4. O Desafio (Mão na Massa)
1.  **Ponto de Partida:** Abra o arquivo [telemetria_combustivel_template.ino](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/telemetria_combustivel_template.ino).
2.  **Tarefa Intermediária:** Complete o mapeamento analógico ($0$ a $50$ Litros para volume; $0$ a $20$ L/h para consumo). Implemente a exibição formatada das variáveis.
3.  **Tarefa Final (Desafio):** 
    *   Crie o filtro de estado para que a tela não pisque ao rotacionar os potenciômetros.
    *   Desenhe a barra de progresso gráfica horizontal na linha 2.
    *   Implemente a lógica de reserva: se `volume < 5.0` Litros, pisque o LED do pino 7 e altere a linha 4 para exibir o aviso `* RESERVA CRITICA *`.

---

## 5. ✅ Checklist de Entrega
1.  **Etapa Intermediária:** Cálculo de autonomia correto exibido no LCD 20x4.
2.  **Etapa Final:** Barra de progresso funcional, ausência de flicker e sistema de alerta de reserva ativo (LED + LCD).
3.  **Reflexão Técnica:** Preenchimento da reflexão técnica obrigatória no cabeçalho do código.
4.  **Explicação Oral:** Explicação da proteção de divisão por zero e da lógica de iteração para desenhar a barra de progresso.

---

## 6. Conexão com a Indústria (APL/RS) 🏭
*Reflexão contextualizada para o Rio Grande do Sul:*
No polo metalmecânico e agrícola gaúcho (regiões de Passo Fundo, Erechim e Não-Me-Toque), estão localizadas grandes montadoras e fabricantes de implementos agrícolas. O projeto de IHMs e painéis de telemetria digital embarcada em colheitadeiras e tratores exige a exibição gráfica clara de parâmetros operacionais críticos sob severas condições de ruído e vibração no campo.

---

## 7. 🧠 Reflexão Técnica (No Código)
Responda à pergunta teórica obrigatória contida no cabeçalho do arquivo [telemetria_combustivel_template.ino](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/telemetria_combustivel_template.ino).

---

## 🤖 Dica de Prompt para IA (Uso Saudável)
> *"Estou no Experimento 3 de Arduino com display LCD 20x4. Preciso desenhar uma barra de progresso horizontal com 10 caracteres baseada no percentual de combustível (0 a 100%). Como posso fazer uma lógica com um loop for para imprimir o caractere char(255) para a parte cheia e espaço em branco ' ' para a parte vazia? Não me dê o código pronto."*

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
