# Experimento 02: Computador de Tarifação Dinâmica - Car Sharing (VoltLog)

Este guia orienta o desenvolvimento do segundo experimento prático de Arduino no simulador Wokwi Web. O código inicial **já funciona** — você vai observá-lo, entendê-lo e depois evoluí-lo em etapas!

---

## 🚀 Ponto de Partida: Onde você está?
Você continua como desenvolvedor na startup de mobilidade **VoltLog**. O utilitário elétrico de entregas está equipado com:
1.  Um circuito montado no Wokwi Web contendo um display LCD 20x4, dois potenciômetros (para simular a quantidade de dias de turno e os quilômetros rodados pelo entregador) e uma chave seletora slide (para mudar a categoria de veículo).
2.  O arquivo [aluguel_carro.ino](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/aluguel_carro.ino) — que já vem com a **Etapa 1 funcional** para você observar e depois modificar.

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

### Passo 1: Veja o Painel Funcionando (Partida)

Clique em ▶️ **Play** para iniciar a simulação. O código já está funcionando!

> **🧪 Teste e Verifique:**
> Gire os dois potenciômetros e clique na chave slide para alternar entre POP e SUV.
> *   **Os dias, km e valor total atualizam corretamente no LCD?**
> *   **O rótulo [POP] ou [SUV] muda quando você clica na chave?**
> *   **A tela está piscando?** Isso é normal nesta etapa — causado pelo `LCD.clear()`. Vamos resolver isso na Etapa 2.

---

### Passo 2: Entendendo as Duas Leituras Analógicas

Observe nas linhas 82–87 do código:

```cpp
int tempo    = map(analogRead(A0), 0, 1023, 1, 30);
int distancia = map(analogRead(A1), 0, 1023, 1, 1000);
```

Dois potenciômetros são lidos independentemente — cada um em um pino analógico diferente (`A0` e `A1`). A função `map()` converte a leitura bruta (0–1023) para a escala de negócio.

> **🧪 Teste e Verifique:**
> Verifique no paper: se `A0` está na metade (~512), quantos dias isso representa? E se `A1` está no máximo (1023), qual a distância?

---

### Passo 3: Entendendo a Lógica de Tarifação

Observe nas linhas 90–102 como a categoria influencia o cálculo:

```cpp
float diaria = 30.0;    // Padrão: Popular
float taxaKm = 0.01;
if (categoria == HIGH) {
    diaria = 80.0;      // SUV: diária maior
    taxaKm = 0.05;
}
float valorTotal = (tempo * diaria + distancia * taxaKm) * 0.90;
```

A chave slide controla qual `if` é executado — isso altera as variáveis `diaria` e `taxaKm` antes do cálculo.

> **🧪 Teste e Verifique (Entrega Intermediária):**
> Configure 10 dias e 100 km. Com a chave em POP, o valor deve ser:
> `(10 × 30 + 100 × 0.01) × 0.90 = R$ 270,90`
> *   **O valor no LCD bate com o calculado?** Parabéns — a matemática está certa! **Você completou a Etapa Intermediária!**

---

### Passo 4: Ativando o Painel Profissional — Etapa 2 (No-Flicker)

Agora vamos eliminar o *flicker* e criar um painel profissional:

**A) Desativar a Etapa 1:** Adicione `//` no início de cada linha da seção `ETAPA 1` no `loop()` (o bloco que começa com `LCD.clear()` e vai até o `LCD.print(valorTotal, 2)`).

**B) Ativar a Etapa 2:** Remova os comentários `/*` e `*/` que envolvem o bloco da Etapa 2.

**C) Completar as três linhas que faltam na Etapa 2:**

Localize os comentários `// <-- COMPLETE AQUI` dentro do bloco `if (tempo != ultimoTempo ...)` e preencha:

```cpp
ultimoTempo = tempo;          // substitui o comentário "COMPLETE AQUI"
ultimaDistancia = distancia;  // substitui o comentário "COMPLETE AQUI"
ultimaCategoria = categoria;  // substitui o comentário "COMPLETE AQUI"
```

**D) Ativar os textos estáticos no `setup()`:** Descomente as 8 linhas do bloco `[INSTRUÇÃO ETAPA 2]` no `setup()`, removendo o `//` do início de cada uma.

> **🧪 Teste e Verifique:**
> Inicie a simulação e gire os potenciômetros.
> *   **A tela parou de piscar completamente?**
> *   **Os números atualizam sem deixar resíduos de dígitos antigos na tela?**
> *   **Ao mudar a chave para SUV, o valor recalcula instantaneamente?**
> *   *Sucesso!* Você implementou um Filtro de Estado Composto profissional.

> **💡 Altere, teste e veja o que acontece!**
> Que tal recalibrar o modelo de negócios? Experimente alterar o preço da diária do modelo SUV de `80.0` para `100.0` (ou a taxa do Km de `0.05` para `0.10`) no código. Rode a simulação e mude a chave seletora.
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
> * Responder a todas as perguntas de Reflexão Técnica no arquivo **`folha_respostas.md`**.

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**
