# Experimento 01: Monitor Térmico das Baterias (VoltLog)

Este guia orienta o desenvolvimento do primeiro experimento prático de Arduino no simulador Wokwi Web. O código inicial **já funciona** — você vai observá-lo, entendê-lo e depois evoluí-lo em etapas!

---

## 🚀 Ponto de Partida: Onde você está?
Você é um desenvolvedor na startup de mobilidade **VoltLog**. O utilitário elétrico de entregas está na oficina e você tem em mãos:
1.  Um circuito montado no Wokwi Web contendo um display LCD 20x4, um potenciômetro (que simula o sensor de temperatura do banco de baterias) e dois LEDs indicadores (verde e vermelho).
2.  O arquivo [conversao_temperatura.ino](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/conversao_temperatura.ino) — que já vem com a **Etapa 1 funcional** para você observar e depois modificar.

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
4. No painel de arquivos da esquerda no Wokwi, clique em **New File**, crie o arquivo **`README.md`** e cole todo o conteúdo deste roteiro local ([README.md](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/README.md)) para ler as instruções lado a lado.
5. Crie também o arquivo **`folha_respostas.md`** clicando em **New File** e cole as perguntas contidas no arquivo local ([folha_respostas.md](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/folha_respostas.md)) para respondê-las online.

---

### Passo 1: Veja o Painel Funcionando (Partida)

Clique em ▶️ **Play** para iniciar a simulação. O código já está funcionando!

> **🧪 Teste e Verifique:**
> Gire o potenciômetro azul no simulador.
> *   **Os valores de Celsius e Fahrenheit mudam no LCD?**
> *   **A tela está piscando rapidamente?** Isso é normal nesta etapa — é o efeito *flicker* causado pelo `LCD.clear()` que apaga e reescreve tudo a cada 100ms.
> *   *Parabéns!* O circuito está funcionando. Agora você vai entender o código e começar a evoluí-lo.

---

### Passo 2: Entendendo a Leitura Analógica

Observe nas linhas 83–87 do código como a leitura funciona:

```cpp
int potenciometro = analogRead(A0);
int tempC = map(potenciometro, 0, 1023, 0, 60);
```

O `analogRead(A0)` retorna um número entre 0 e 1023 (o Arduino possui 10 bits de resolução). A função `map()` converte essa escala para a faixa de temperatura desejada (0 a 60 °C).

> **🧪 Teste e Verifique:**
> Faça o cálculo no papel: se o potenciômetro está exatamente no meio (leitura `512`), qual deve ser a temperatura em Celsius?
> *   *Dica:* Abra o Monitor Serial temporariamente. Adicione `Serial.begin(9600)` no `setup()` e `Serial.println(potenciometro)` no `loop()`. Confira se a leitura bate com a conta.

---

### Passo 3: Entendendo a Exibição no LCD (Etapa 1)

Observe nas linhas 92–117 como a **Etapa 1** desenha a tela:

```cpp
LCD.clear();
LCD.setCursor(0, 0);
LCD.print("PAINEL DE TEMPERATURA");
LCD.setCursor(0, 1);
LCD.print("Celsius: ");
LCD.print(tempC);
...
```

O `setCursor(coluna, linha)` posiciona o cursor. O LCD tem colunas de 0 a 19 e linhas de 0 a 3. O `LCD.clear()` limpa toda a tela antes de redesenhar — essa é a causa do *flicker*.

> **🧪 Teste e Verifique (Entrega Intermediária):**
> Confirme que ao girar o potenciômetro o valor atualiza. A tela pisca — isso **comprova** que a Etapa 1 está funcional. **Você completou a Etapa Intermediária!**

---

### Passo 4: Ativando o Painel Profissional — Etapa 2 (No-Flicker + Alarme)

Agora vamos agir como engenheiros profissionais. O painel de um carro não pode piscar!

A **Etapa 2** já está escrita no código — mas está dentro de um bloco `/* ... */` que desativa o código. Você vai:

**A) Desativar a Etapa 1:** Adicione `//` no início de cada linha da seção `ETAPA 1` (linhas 101–117), começando pelo `LCD.clear()`.

**B) Ativar a Etapa 2:** Remova os comentários `/*` da linha 127 e `*/` da linha 167.

**C) Completar as duas linhas que faltam na Etapa 2:**

No bloco de alarme (dentro do `if/else`), localize os comentários `// <-- COMPLETE AQUI` e substitua os `...` pelos valores corretos:

*   Quando a temperatura for **≥ 40°C** (bateria quente), o LED verde deve ser **apagado**:
    ```cpp
    digitalWrite(pinoVerde, LOW);   // substitui o "..."
    ```
*   Quando a temperatura for **< 40°C** (seguro), o LED vermelho deve ser **apagado**:
    ```cpp
    digitalWrite(pinoVermelho, LOW);  // substitui o "..."
    ```

**D) Ativar os textos estáticos no `setup()`:** Descomente as 8 linhas do bloco `[INSTRUÇÃO ETAPA 2]` no `setup()` (linhas 72–79), removendo o `//` do início de cada uma.

> **🧪 Teste e Verifique:**
> Inicie a simulação e gire o potenciômetro.
> *   **A tela parou de piscar completamente?**
> *   **Os valores numéricos atualizam de forma suave?**
> *   **O LED vermelho acende e "ALERTA" aparece quando passa de 40°C?**
> *   *Excelente!* Você dominou o conceito de Filtro de Estado em sistemas embarcados!

> **💡 Altere, teste e veja o que acontece!**
> Quer ver o poder da programação em suas mãos? Experimente alterar o limite de temperatura de segurança de `40` para `43` (ou qualquer outro valor de sua escolha) diretamente no seu código. Inicie a simulação novamente.
> *   **O LED vermelho agora só acende quando ultrapassa esse novo limite?**
> *   *Percebeu como apenas uma mudança simples no código altera completamente o comportamento físico do circuito?*

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
    3. Faça o upload de cada um dos arquivos individuais extraídos (`conversao_temperatura.ino`, `diagram.json`, `README.md` e `folha_respostas.md`) diretamente na entrega da atividade.

> [!IMPORTANT]
> Antes de entregar, certifique-se de:
> * Preencher seu **Nome** e **Data** no cabeçalho do código (`conversao_temperatura.ino`).
> * Responder a todas as perguntas de Reflexão Técnica no arquivo **`folha_respostas.md`**.

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**
