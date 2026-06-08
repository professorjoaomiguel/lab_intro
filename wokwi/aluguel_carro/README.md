# Experimento 02: Computador de Tarifação Dinâmica - Car Sharing (VoltLog)

Este guia orienta o desenvolvimento do segundo experimento prático de Arduino no simulador Wokwi Web. Siga cada passo, verifique seus resultados e comemore suas conquistas à medida que avança na programação do painel do veículo!

---

## 🚀 Ponto de Partida: Onde você está?
Você continua como desenvolvedor na startup de mobilidade **VoltLog**. O utilitário elétrico de entregas está equipado com:
1.  Um circuito montado no Wokwi Web contendo um display LCD 20x4, dois potenciômetros (para simular a quantidade de dias de turno e os quilômetros rodados pelo entregador) e uma chave seletora slide (para mudar a categoria de veículo).
2.  Um código inicial limpo em [aluguel_carro.ino](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/aluguel_carro.ino) contendo as marcações `# TODO`.

---

## 🎯 Destino Final: Onde você deve chegar?
Seu objetivo é entregar o **Módulo de Tarifação Dinâmica** operando de forma otimizada no painel. O entregador deve poder alterar a categoria do veículo (chave em LOW = Popular, chave em HIGH = SUV) e ver as tarifas e o valor total (com 10% de desconto) atualizados suavemente no LCD 20x4.

---

## 🛠️ Caixa de Ferramentas (O que você vai usar)
Consulte a documentação oficial do Arduino se tiver dúvidas de sintaxe:
*   [analogRead()](https://www.arduino.cc/reference/pt/language/functions/analog-io/analogread/) — Lê os potenciômetros (0 a 1023).
*   [digitalRead()](https://www.arduino.cc/reference/pt/language/functions/digital-io/digitalread/) — Lê o estado da chave slide (HIGH ou LOW).
*   [map()](https://www.arduino.cc/reference/pt/language/functions/math/map/) — Remapeia escalas proporcionais.
*   [LiquidCrystal](https://www.arduino.cc/reference/en/libraries/liquidcrystal/) — Controla o display de texto.

---

## 🏁 Jornada de Desenvolvimento (Passo a Passo Interativo)

### 💻 Como Iniciar no Navegador:
1. Acesse [wokwi.com/projects/new/arduino-uno](https://wokwi.com/projects/new/arduino-uno).
2. Abra a aba **`diagram.json`** no simulador, apague o conteúdo e cole o código do arquivo local [diagram.json](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/diagram.json). *O circuito surgirá conectado!*
3. Abra a aba **`sketch.ino`** e cole o código do arquivo local [aluguel_carro.ino](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/aluguel_carro.ino).
4. No painel de arquivos da esquerda no Wokwi, clique em **New File**, crie o arquivo **`README.md`** e cole todo o conteúdo deste roteiro local ([README.md](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/README.md)) para ler as instruções lado a lado.
5. Crie também o arquivo **`folha_respostas.md`** clicando em **New File** e cole as perguntas contidas no arquivo local ([folha_respostas.md](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/folha_respostas.md)) para respondê-las online.

---

### Passo 1: Lendo as Duas Variáveis Analógicas (Entrada)
No `loop()`, leia o potenciômetro conectado ao pino `A0` (tempo) e converta-o de `0-1023` para a faixa de `1 a 30` dias usando `map()`. Em seguida, leia o potenciômetro conectado a `A1` (distância) e mapeie para a faixa de `1 a 1000` km.

> **🧪 Teste e Verifique:** 
> Insira comandos `Serial` para imprimir as variáveis `tempo` e `distancia`. Inicie a simulação e abra o monitor serial.
> *   **Ao girar o potenciômetro 1, o valor muda de 1 a 30?**
> *   **Ao girar o potenciômetro 2, o valor muda de 1 a 1000?**
> *   *Excelente!* Você controlou com sucesso duas variáveis analógicas independentes. **Seu primeiro Quick Win!** (Pode remover os comandos Serial de teste).

---

### Passo 2: A Conta Matemática (Processamento)
Calcule o valor total da locação nas condições básicas padrão:
*   Preço da diária: **R$ 30,00**.
*   Preço por quilômetro rodado: **R$ 0,01**.
*   Desconto especial: **10%** sobre o valor total ($Custo = (Dias \times 30.0 + Distancia \times 0.01) \times 0.90$).

---

### Passo 3: Apresentando os Resultados (Saída com Flicker)
No `setup()`, inicialize o LCD com `LCD.begin(20, 4);`. No `loop()`, limpe a tela (`LCD.clear()`) e exiba a quantidade de dias, os quilômetros rodados e o valor total a pagar no LCD.

> **🧪 Teste e Verifique (Entrega Intermediária):**
> Inicie a simulação e gire ambos os potenciômetros.
> *   **O LCD mostra a contagem de tempo, km e o valor total correto?**
> *   *Parabéns!* A matemática está correta e a tela atualiza as informações. A tela pisca rápido por causa do clear, mas a lógica está validada! **Você completou a Etapa Intermediária.**

---

### Passo 4: Otimizando o Painel (Filtro de Estado Composto)
Agora vamos eliminar a oscilação da tela para criar um painel profissional:
1. Mova os textos fixos (`LOCADORA SAI FRENTE`, `Tempo:    dias`, `Dist:     km  [   ]`, `Total: R$ `) para o `setup()`.
2. No `loop()`, envolva toda a escrita do LCD em um `if` composto usando o operador lógico OR (`||`):
   `if (tempo != ultimoTempo || distancia != ultimaDistancia || categoria != ultimaCategoria)`
3. Limpe as casas numéricas dinâmicas com espaços em branco `"   "` antes de reescrever novos valores. Atualize as variáveis globais de estado ao final do `if`.

> **🧪 Teste e Verifique:**
> Inicie a simulação. Gire os potenciômetros.
> *   **A tela parou de piscar?**
> *   **Os números variam perfeitamente sem deixar caracteres "órfãos" residuais na tela?**
> *   *Sucesso!* Você implementou um Filtro de Estado Composto profissional.

---

### Passo 5: Integrando a Categoria do Veículo (Desafio Final)
No `setup()`, configure o pino digital da chave slide (pino 9) como entrada utilizando o resistor de pull-up interno: `pinMode(pinoChave, INPUT_PULLUP)`. No `loop()`, faça a leitura da chave (`digitalRead(pinoChave)`).
*   Se a chave estiver em `LOW` (Popular - `POP`): Diária = R$ 30,00 | Km = R$ 0,01.
*   Se a chave estiver em `HIGH` (Utilitário - `SUV`): Diária = R$ 80,00 | Km = R$ 0,05.
*   Exiba o rótulo correspondente no display na coluna 15 da linha 2 (ex: `[POP]` ou `[SUV]`).

> **🧪 Teste e Verifique (Entrega Final):**
> Faça o teste de aceitação final:
> 1. Defina 10 dias e 100 km rodados. Com a chave em Popular (`POP`), o custo deve ser R$ 270,90.
> 2. Mude a chave para a direita (`SUV`). O painel altera instantaneamente as diárias e atualiza o custo para R$ 724,50?
> 3. O texto dinâmico `[POP]` mudou para `[SUV]` sem bagunçar o layout?
> *   *Incrível!* Seu computador de bordo dinâmico de Car Sharing da VoltLog está completo!

> **💡 Altere, teste e veja o que acontece!**
> Que tal recalibrar o modelo de negócios? Experimente alterar o preço da diária do modelo SUV de `80` para `100` (ou a taxa do Km de `0.05` para `0.10`) no código. Rode a simulação e mude a chave seletora.
> *   **O painel recalculou as diárias e o valor total dinamicamente na tela?**
> *   *Sensacional!* Você provou que seu software é flexível e que mudar parâmetros de tarifação no código altera imediatamente as contas calculadas pelo veículo!

---

## 🏁 Como Salvar e Entregar a Atividade

Você possui duas opções para entregar a sua atividade prática no Classroom. Escolha uma delas conforme a orientação do professor:

*   **Opção 1: Enviar o Link do Wokwi (Recomendado):**
    1. No menu superior da tela do Wokwi Web, clique em **Save**.
    2. Clique no botão **Share** no topo da tela e copie a URL única gerada.
    3. Cole este link na entrega da sua atividade no Classroom.
*   **Opção 2: Enviar os Arquivos Individuais:**
    1. Clique em **Download Project** no menu do Wokwi (isso baixará um arquivo compactado `.zip`).
    2. **IMPORTANTE: NÃO envie o arquivo .zip no Classroom.** Extraia a pasta compactada no seu computador.
    3. Faça o upload de cada um dos arquivos individuais extraídos (`aluguel_carro.ino`, `diagram.json`, `README.md` e `folha_respostas.md`) diretamente na entrega da atividade.

> [!IMPORTANT]
> Antes de entregar, certifique-se de:
> * Preencher seu **Nome** e **Data** no cabeçalho do código (`aluguel_carro.ino`).
> * Criar o arquivo **`folha_respostas.md`** no simulador e responder a todas as perguntas de Reflexão Técnica nele.

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**
