# Experimento 01: Conversão de Temperatura com Display LCD

## 1. Objetivos de Aprendizagem
*   **Nível Intermediário:** Realizar a leitura analógica de um potenciômetro, mapeá-la para uma faixa de $0$ a $60^{\circ}\text{C}$, converter para Fahrenheit e exibir ambas as informações no LCD 16x2.
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

$$F = C \times \frac{9}{5} + 32$$

No código C/C++ do Arduino, lembre-se de usar números reais (`9.0` e `5.0`) na divisão para evitar o truncamento da divisão inteira.

---

## 3. Componentes e Conexões (Wokwi)
*   **Arduino Uno R3**
*   **Display LCD 16x2 (Ligação Paralela)**
    *   `RS` -> Pino 12
    *   `E` -> Pino 11
    *   `D4` -> Pino 5
    *   `D5` -> Pino 4
    *   `D6` -> Pino 3
    *   `D7` -> Pino 2
    *   `VCC` -> 5V | `GND` -> GND
*   **Potenciômetro**
    *   Terminais externos -> 5V e GND
    *   Terminal central (sinal) -> Pino analógico `A0`

---

## 4. O Desafio (Mão na Massa)
1.  **Ponto de Partida:** Abra o arquivo [conversao_temperatura_template.ino](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/conversao_temperatura_template.ino).
2.  **Tarefa Intermediária:** Complete o código nas seções `# TODO` para realizar as leituras analógicas e imprimir no LCD. A tela pode piscar nesta etapa.
3.  **Tarefa Final (Desafio):** Implemente a lógica de detecção de mudança de estado. Imprima as etiquetas fixas no `setup()` e só atualize os valores no `loop()` se a temperatura atual for diferente da temperatura anterior.

---

## 5. ✅ Checklist de Entrega
1.  **Etapa Intermediária:** Temperatura calculada e exibida no display.
2.  **Etapa Final:** Circuito operando sem piscar a tela ao alterar a posição do potenciômetro.
3.  **Reflexão Técnica:** Preenchimento da reflexão obrigatória no código-fonte.
4.  **Explicação Oral:** Capacidade de explicar as conexões físicas e a lógica matemática do mapeamento e conversão.

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
