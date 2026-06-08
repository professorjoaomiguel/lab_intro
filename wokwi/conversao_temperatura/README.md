# Experimento 01: Monitor Térmico das Baterias (VoltLog)

Este guia orienta o desenvolvimento do primeiro experimento prático de Arduino no simulador Wokwi Web. Ele foi projetado em pequenos passos para garantir que você valide seu progresso a cada etapa e conquiste vitórias rápidas!

---

## 🚀 Ponto de Partida: Onde você está?
Você é um desenvolvedor na startup de mobilidade **VoltLog**. O utilitário elétrico de entregas está na oficina e você tem em mãos:
1.  Um circuito montado no Wokwi Web contendo um display LCD 20x4, um potenciômetro (que simula o sensor de temperatura do banco de baterias) e dois LEDs indicadores (verde e vermelho).
2.  Um código inicial limpo em [conversao_temperatura.ino](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/conversao_temperatura.ino) contendo as marcações `# TODO`.

---

## 🎯 Destino Final: Onde você deve chegar?
Seu objetivo é entregar o **Módulo de Monitoramento Térmico** funcionando sem oscilação na tela (*no-flicker*) e com alarme visual ativo: se as baterias ultrapassarem $40^{\circ}\text{C}$, o LED vermelho acende e o display avisa `ALERTA`. Em temperatura normal, o LED verde fica aceso e o display exibe `OK`.

---

## 🛠️ Caixa de Ferramentas (O que você vai usar)
Consulte a documentação oficial do Arduino se tiver dúvidas de sintaxe:
*   [analogRead()](https://www.arduino.cc/reference/pt/language/functions/analog-io/analogread/) — Lê o sensor analógico de 0 a 1023.
*   [map()](https://www.arduino.cc/reference/pt/language/functions/math/map/) — Converte escalas proporcionalmente.
*   [pinMode()](https://www.arduino.cc/reference/pt/language/functions/digital-io/pinmode/) — Configura pinos como entrada ou saída.
*   [digitalWrite()](https://www.arduino.cc/reference/pt/language/functions/digital-io/digitalwrite/) — Acende ou apaga pinos digitais.
*   [LiquidCrystal](https://www.arduino.cc/reference/en/libraries/liquidcrystal/) — Controla o display de texto.

---

## 🏁 Jornada de Desenvolvimento (Passo a Passo Interativo)

Siga os passos abaixo, teste o circuito a cada etapa e comemore suas conquistas!

### 💻 Como Iniciar no Navegador:
1. Acesse [wokwi.com/projects/new/arduino-uno](https://wokwi.com/projects/new/arduino-uno).
2. Abra a aba **`diagram.json`** no simulador, apague o conteúdo e cole o código do arquivo local [diagram.json](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/diagram.json). *O circuito surgirá conectado!*
3. Abra a aba **`sketch.ino`** e cole o código do arquivo local [conversao_temperatura.ino](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/conversao_temperatura.ino).

---

### Passo 1: Capturando o Sinal Físico (Entrada)
No `loop()`, implemente a leitura analógica do potenciômetro conectado no pino `A0` usando a função `analogRead()`. Salve o valor na variável `potenciometro`.

> **🧪 Teste e Verifique:** 
> Insira temporariamente o comando `Serial.begin(9600);` no `setup()` e `Serial.println(potenciometro);` no `loop()`. Inicie a simulação e abra o *Serial Monitor* no canto inferior. Gire o potenciômetro.
> *   **Você viu os números variarem suavemente entre 0 e 1023?**
> *   *Se sim, parabéns!* Você acabou de capturar uma informação do mundo físico e digitalizá-la no microcontrolador. **Sua primeira vitória!** (Pode remover os comandos Serial de teste).

---

### Passo 2: Calibrando as Escalas (Processamento)
Converta a leitura do potenciômetro (`0` a `1023`) para a escala de temperatura da bateria (`0` a `60` graus Celsius). Use a função `map()`.

> **🧪 Teste e Verifique:**
> Faça a conta no papel: se o potenciômetro estiver exatamente no meio (leitura `512`), a temperatura deve ser próxima de `30` °C. Se estiver no máximo (`1023`), deve ser `60` °C. 
> *   *Dica de Ouro:* Para converter Celsius para Fahrenheit, aplique a fórmula: `tempF = tempC * 1.8 + 32.0;`. Use números decimais para não perder a precisão do cálculo em C++!

---

### Passo 3: Exibindo no Painel do Carro (Saída)
Inicialize o LCD no `setup()` com `LCD.begin(20, 4);`. No `loop()`, limpe a tela com `LCD.clear()`, use `LCD.setCursor()` para posicionar o cursor e exiba os valores de temperatura calculados.

> **🧪 Teste e Verifique (Entrega Intermediária):**
> Inicie a simulação. Gire o potenciômetro. 
> *   **Os valores de temperatura atualizam no LCD conforme você mexe no sensor?**
> *   **A tela está piscando rapidamente de forma incômoda?**
> *   *Não se preocupe!* Esse efeito é o *flicker* causado pela função `LCD.clear()` rodando repetidamente. Isso prova que sua lógica matemática e conexões estão funcionando. **Você completou a Etapa Intermediária!**

---

### Passo 4: Otimizando o Painel (Desafio No-Flicker)
Agora vamos agir como engenheiros profissionais. O painel de um carro não pode piscar!
1. Mova os textos fixos (`PAINEL DE TEMPERATURA`, `Celsius:`, `Fahrenheit:`, `Status:`) para dentro da função `setup()`. Eles devem ser escritos apenas **uma vez** na inicialização.
2. No `loop()`, envolva toda a lógica de escrita do display em um bloco condicional: `if (tempC != ultimoTempC)`.
3. Ao escrever o novo valor no LCD, posicione o cursor, imprima alguns espaços vazios `"   "` (para apagar os resíduos do número anterior) e depois escreva o valor atualizado. Por fim, atualize a variável `ultimoTempC = tempC;`.

> **🧪 Teste e Verifique:**
> Inicie a simulação e gire o potenciômetro.
> *   **A tela parou de piscar completamente?**
> *   **Os valores numéricos atualizam de forma instantânea e suave?**
> *   *Excelente!* Você dominou o conceito de Filtro de Estado em sistemas embarcados. Sua interface está profissional!

---

### Passo 5: Ativando a Proteção e Alarme (Desafio Final)
No `setup()`, configure os pinos dos LEDs vermelho e verde como saídas (`OUTPUT`). No `loop()`, adicione a lógica condicional de alerta de temperatura:
*   Se a temperatura for **igual ou maior que 40 °C**: liga o LED Vermelho, desliga o LED Verde e exibe a palavra `ALERTA` na linha 3.
*   Caso contrário: apaga o LED Vermelho, liga o LED Verde e exibe `OK` na linha 3.

> **🧪 Teste e Verifique (Entrega Final):**
> Simule e faça o teste final:
> 1. Coloque a temperatura em 35 °C. O LED verde deve estar aceso e a tela mostrando `OK`.
> 2. Gire o potenciômetro para passar de 40 °C. O LED verde deve apagar instantaneamente, o LED vermelho acender e a tela exibir `ALERTA`.
> 3. Retorne a temperatura para menos de 40 °C. O sistema restaura o estado seguro?
> *   *Sucesso total!* Você concluiu o desafio final do Módulo Térmico de Baterias da VoltLog. Preencha a **Reflexão Técnica** no cabeçalho do arquivo `.ino` e chame o professor para avaliar seu projeto!

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**
