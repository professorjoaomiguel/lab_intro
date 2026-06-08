# Experimento 03: Telemetria de Combustível e Autonomia Híbrida (VoltLog)

Este guia orienta o desenvolvimento do terceiro experimento prático de Arduino no simulador Wokwi Web. Siga cada etapa, valide seu progresso a cada teste e divirta-se criando um painel de telemetria profissional com gráficos e proteção matemática contra falhas!

---

## 🚀 Ponto de Partida: Onde você está?
Você é o desenvolvedor sênior na startup de mobilidade **VoltLog**. O utilitário híbrido está rodando rotas intermunicipais e você possui:
1.  Um circuito montado no Wokwi Web contendo um display LCD 20x4, dois potenciômetros (que representam os sensores analógicos de volume de combustível no tanque e taxa de consumo instantâneo) e um LED físico vermelho de alerta.
2.  Um código inicial em [telemetria_combustivel.ino](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/telemetria_combustivel.ino) contendo as marcações `# TODO`.

---

## 🎯 Destino Final: Onde você deve chegar?
Seu objetivo é entregar o **Módulo Computador de Bordo Híbrido** operando no painel. O LCD 20x4 deve exibir o nível do tanque, o consumo instantâneo e a autonomia em horas de forma fluida. O painel deve desenhar uma barra gráfica horizontal de preenchimento do tanque, possuir proteção matemática contra divisões por zero (quando o carro trafegar puramente em modo elétrico) e acionar um LED físico e aviso dinâmico na tela quando o combustível entrar na reserva (< 5.0 Litros).

---

## 🛠️ Caixa de Ferramentas (O que você vai usar)
Consulte a documentação oficial do Arduino se tiver dúvidas de sintaxe:
*   [analogRead()](https://www.arduino.cc/reference/pt/language/functions/analog-io/analogread/) — Lê os sensores analógicos (0 a 1023).
*   [pinMode()](https://www.arduino.cc/reference/pt/language/functions/digital-io/pinmode/) e [digitalWrite()](https://www.arduino.cc/reference/pt/language/functions/digital-io/digitalwrite/) — Controlam o LED de alarme físico.
*   [LiquidCrystal](https://www.arduino.cc/reference/en/libraries/liquidcrystal/) — Controla o display de texto.
*   *Função de Escrita de Bytes do LCD:* `LCD.write(255)` — Imprime o caractere de bloco preenchido (ASCII 255) no display para o gráfico.

---

## 🏁 Jornada de Desenvolvimento (Passo a Passo Interativo)

### 💻 Como Iniciar no Navegador:
1. Acesse [wokwi.com/projects/new/arduino-uno](https://wokwi.com/projects/new/arduino-uno).
2. Abra a aba **`diagram.json`** no simulador, apague o conteúdo e cole o código do arquivo local [diagram.json](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/diagram.json). *O circuito surgirá conectado!*
3. Abra a aba **`sketch.ino`** e cole o código do arquivo local [telemetria_combustivel.ino](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/telemetria_combustivel.ino).

---

### Passo 1: Lendo Sensores em Ponto Flutuante (Entrada)
No `loop()`, leia o pino analógico `A0` (sensor de tanque) e converta para a faixa real de `0.0 a 50.0` litros. Leia o pino `A1` (sensor de consumo) e mapeie para a faixa de `0.0 a 20.0` L/h.
*   *Dica de Ouro:* Faça cálculos utilizando floats para manter a precisão: `volume = (analogRead(A0) / 1023.0) * 50.0;`.

> **🧪 Teste e Verifique:** 
> Imprima os valores de `volume` e `consumo` via Serial Monitor. Mova os potenciômetros e certifique-se de que eles mostram valores com casas decimais (ex: `12.5 Litros` e `5.4 L/h`).
> *   **Conseguiu ver os valores em float corretos?**
> *   *Excelente!* A leitura física e conversão de ponto flutuante estão operando perfeitamente. **Sua primeira conquista!** (Pode remover os comandos Serial de teste).

---

### Passo 2: Proteção de Software Contra Divisão por Zero (Processamento)
A autonomia é calculada por `volume / consumo`. Porém, se o carro rodar em modo 100% elétrico, o consumo de combustível líquido será **zero**. Tentar dividir por zero travará o processador ou produzirá dados inválidos.
*   Implemente uma estrutura condicional: se `consumo` for menor que `0.1` L/h, marque uma flag de segurança `divisaoPorZero = true` e defina a autonomia como `0.0`. Caso contrário, faça a divisão matemática padrão.

---

### Passo 3: Exibição Digital Básica (Saída com Flicker)
No `setup()`, inicialize o LCD com `LCD.begin(20, 4);`. No `loop()`, limpe a tela (`LCD.clear()`) e exiba o tanque, o consumo e a autonomia (se a flag de divisão por zero estiver ativa, imprima `"INF"`, senão, imprima o valor numérico com 2 casas decimais).

> **🧪 Teste e Verifique (Entrega Intermediária):**
> Inicie a simulação.
> *   **Gire o potenciômetro de consumo para o mínimo. O LCD exibe "INF" em vez de quebrar ou dar erro?**
> *   **Os dados de volume e consumo atualizam no display?**
> *   *Sucesso!* O tratamento preventivo de falhas de hardware/software está funcionando. A tela pisca, mas a lógica está validada! **Você concluiu a Etapa Intermediária.**

---

### Passo 4: Otimizando o Painel (Filtro de Estado)
Vamos tornar o painel estável e sem piscar:
1. Mova os textos fixos (`PAINEL DE TELEMETRIA`, `Tanque:     L`, `Autonomia:        h`) para o `setup()`.
2. No `loop()`, envolva a atualização de dados no LCD em um bloco `if` baseado no percentual inteiro do tanque e no consumo (convertido para inteiro de uma casa decimal para o filtro):
   `if (percentualInt != ultimoPercentual || consumoInt != ultimoConsumoInt)`
3. Use espaços vazios para limpar resíduos de dados antigos antes de reescrever novos valores. Atualize as variáveis de estado no final do bloco.

> **🧪 Teste e Verifique:**
> Simule e gire os sensores. A tela parou de piscar? Os valores de litros e consumo mudam de forma limpa e estável? *Ótimo! Sua interface está profissional.*

---

### Passo 5: Desenhando a Barra Gráfica (Desafio Final - 1)
Na linha 2 do LCD, desenhe a barra gráfica do tanque (0 a 10 blocos). O número de blocos a desenhar é dado por `percentualInt / 10`.
*   Use um laço `for (int i = 0; i < 10; i++)`. Se o índice `i` for menor que o número de blocos, escreva o caractere sólido `LCD.write(255)`. Caso contrário, escreva o caractere de espaço em branco `" "`.

> **🧪 Teste e Verifique:**
> Inicie a simulação. Gire o potenciômetro do tanque.
> *   **A barra gráfica de blocos sólidos [████      ] cresce e encolhe proporcionalmente com a porcentagem?**
> *   *Parabéns!* Você acabou de desenhar seu primeiro elemento gráfico personalizado em um display digital de caracteres!

---

### Passo 6: Alarme de Combustível em Reserva (Desafio Final - 2)
No `setup()`, configure o pino digital do LED indicador de reserva (Pino 7) como saída (`OUTPUT`).
No `loop()`, adicione a lógica: se o volume do tanque for **menor que 5.0 Litros**:
*   Acenda o LED de alerta (HIGH).
*   Altere dinamicamente a string da linha 3 no LCD de `Autonomia:` para a string de emergência `!RESERVA!`.
*   Se o nível retornar para 5.0 L ou mais, apague o LED e restaure a string original.

> **🧪 Teste e Verifique (Entrega Final):**
> Execute o teste final de integridade da telemetria da VoltLog:
> 1. Regule o potenciômetro do tanque para um valor seguro (ex: 20 Litros). A barra deve estar parcialmente preenchida, o LED vermelho apagado e a linha 3 exibindo a autonomia.
> 2. Gire o sensor até o tanque ficar abaixo de 5.0 Litros. O LED de emergência acende no painel e a tela muda dinamicamente exibindo `!RESERVA!` no lugar do rótulo padrão?
> *   *Espetacular!* Seu computador de bordo híbrido de telemetria VoltLog está totalmente operacional e homologado. Preencha a **Reflexão Técnica** no cabeçalho do arquivo `.ino` e apresente ao professor!

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**
