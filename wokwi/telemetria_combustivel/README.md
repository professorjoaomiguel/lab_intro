# Experimento 03: Telemetria de Combustível e Autonomia Híbrida (VoltLog)

Este guia orienta o desenvolvimento do terceiro experimento prático de Arduino no simulador Wokwi Web. O código inicial **já funciona** — você vai observá-lo, entendê-lo e depois evoluí-lo em etapas!

---

## 🚀 Ponto de Partida: Onde você está?
Você é o desenvolvedor sênior na startup de mobilidade **VoltLog**. O utilitário híbrido está rodando rotas intermunicipais e você possui:
1.  Um circuito montado no Wokwi Web contendo um display LCD 20x4, dois potenciômetros (que representam os sensores analógicos de volume de combustível no tanque e taxa de consumo instantâneo) e um LED físico vermelho de alerta.
2.  O arquivo [telemetria_combustivel.ino](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/telemetria_combustivel.ino) — que já vem com a **Etapa 1 funcional** para você observar e depois modificar.

---

## 🎯 Destino Final: Onde você deve chegar?
Seu objetivo é entregar o **Módulo Computador de Bordo Híbrido** com LCD 20x4 exibindo o nível do tanque, o consumo instantâneo e a autonomia de forma fluida. O painel deve desenhar uma barra gráfica horizontal de preenchimento do tanque, possuir proteção matemática contra divisões por zero e acionar um LED físico e aviso dinâmico na tela quando o combustível entrar na reserva (< 5.0 Litros).

---

## 🛠️ Caixa de Ferramentas (O que você vai usar)
Consulte a documentação oficial do Arduino se tiver dúvidas de sintaxe:
*   [analogRead()](https://www.arduino.cc/reference/pt/language/functions/analog-io/analogread/) — Lê os sensores analógicos (0 a 1023).
*   [pinMode()](https://www.arduino.cc/reference/pt/language/functions/digital-io/pinmode/) e [digitalWrite()](https://www.arduino.cc/reference/pt/language/functions/digital-io/digitalwrite/) — Controlam o LED de alarme físico.
*   [LiquidCrystal](https://www.arduino.cc/reference/en/libraries/liquidcrystal/) — Controla o display de texto.
*   *Bloco gráfico do LCD:* `LCD.write(255)` — Imprime um bloco sólido preenchido (ASCII 255) no display.

---

## 🏁 Jornada de Desenvolvimento (Passo a Passo Interativo)

### 💻 Como Iniciar no Navegador:
1. Acesse [wokwi.com/projects/new/arduino-uno](https://wokwi.com/projects/new/arduino-uno).
2. Abra a aba **`diagram.json`** no simulador, apague o conteúdo e cole o código do arquivo local [diagram.json](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/diagram.json). *O circuito surgirá conectado!*
3. Abra a aba **`sketch.ino`** e cole o código do arquivo local [telemetria_combustivel.ino](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/telemetria_combustivel.ino).
4. No painel de arquivos da esquerda no Wokwi, clique em **New File**, crie o arquivo **`README.md`** e cole todo o conteúdo deste roteiro local ([README.md](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/README.md)) para ler as instruções lado a lado.
5. Crie também o arquivo **`folha_respostas.md`** clicando em **New File** e cole as perguntas contidas no arquivo local ([folha_respostas.md](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/folha_respostas.md)) para respondê-las online.

---

### Passo 1: Veja o Painel Funcionando (Partida)

Clique em ▶️ **Play** para iniciar a simulação. O código já está funcionando!

> **🧪 Teste e Verifique:**
> Gire os dois potenciômetros e observe o LCD.
> *   **O volume do tanque e o consumo atualizam no display?**
> *   **Quando o potenciômetro de consumo está no mínimo (próximo de zero), o LCD exibe "INF (elet)"?** Isso é a proteção contra divisão por zero em ação.
> *   **Quando o tanque vai abaixo de 5.0 L, o LED vermelho acende?** O alarme já está ativo!
> *   *Parabéns!* A Etapa 1 está completa e funcional. Agora vamos entender e evoluir o código.

---

### Passo 2: Entendendo a Leitura em Ponto Flutuante

Observe nas linhas 74–77 do código:

```cpp
float volume  = (analogRead(A0) / 1023.0) * 50.0;
float consumo = (analogRead(A1) / 1023.0) * 20.0;
```

Note o uso de `1023.0` (com `.0`) — isso garante que a divisão seja feita em *ponto flutuante*, preservando as casas decimais. Se usássemos apenas `1023`, o resultado seria um inteiro (sem decimais) e perderiamos a precisão.

> **🧪 Teste e Verifique:**
> Gire o potenciômetro de volume até o máximo. O LCD deve mostrar próximo de `50.0 L`. No meio (~512), deve mostrar ~`25.0 L`.

---

### Passo 3: Entendendo a Proteção contra Divisão por Zero

Observe nas linhas 89–97 do código:

```cpp
if (consumo < 0.1) {
    divisaoPorZero = true;
    autonomia = 0.0;
} else {
    autonomia = volume / consumo;
}
```

Se o carro rodar 100% no motor elétrico, o consumo de combustível é praticamente zero. Dividir por zero em um microcontrolador pode gerar valores inválidos ou travar o sistema. O `if` detecta esse caso e ativa uma flag de segurança.

> **🧪 Teste e Verifique (Entrega Intermediária):**
> Gire o potenciômetro de consumo até o mínimo. O LCD exibe "INF (elet)" em vez de um número absurdo ou erro?
> *   *Sucesso!* O tratamento preventivo de falhas está funcionando. **Você completou a Etapa Intermediária!**

---

### Passo 4: Ativando o Painel Profissional — Etapa 2 (No-Flicker + Barra Gráfica)

Vamos tornar o painel estável, sem piscar, e adicionar a barra gráfica:

**A) Desativar a Etapa 1:** Adicione `//` no início de cada linha da seção `ETAPA 1` no `loop()` (o bloco que começa com `LCD.clear()` e vai até o segundo `digitalWrite(pinoAlerta, LOW)`).

**B) Ativar a Etapa 2:** Remova os comentários `/*` e `*/` que envolvem o bloco da Etapa 2.

**C) Completar as quatro linhas que faltam na Etapa 2:**

Dentro do bloco `if (volume < 5.0)` localize os comentários `// <-- COMPLETE AQUI` e preencha:

*   Quando o tanque for < 5.0 L (reserva), o LED deve **acender**:
    ```cpp
    digitalWrite(pinoAlerta, HIGH);   // substitui o "..."
    ```
*   Quando o tanque for ≥ 5.0 L (seguro), o LED deve **apagar**:
    ```cpp
    digitalWrite(pinoAlerta, LOW);    // substitui o "..."
    ```
*   No final do `if` de Filtro de Estado, atualize o estado anterior:
    ```cpp
    ultimoPercentual = percentualInt;   // substitui o "..."
    ultimoConsumoInt = consumoInt;      // substitui o "..."
    ```

**D) Ativar os textos estáticos no `setup()`:** Descomente as 6 linhas do bloco `[INSTRUÇÃO ETAPA 2]` no `setup()`, removendo o `//` do início de cada uma.

> **🧪 Teste e Verifique:**
> Simule e gire os potenciômetros.
> *   **A tela parou de piscar?**
> *   **A barra gráfica `[████      ]` cresce e encolhe proporcionalmente ao nível do tanque?**
> *   **O LED vermelho e o aviso `!RESERVA!` aparecem quando o tanque fica abaixo de 5.0 L?**
> *   *Espetacular!* Seu computador de bordo híbrido de telemetria VoltLog está totalmente operacional!

> **💡 Altere, teste e veja o que acontece!**
> Que tal alterar a sensibilidade do alarme de reserva? Mude o valor de segurança de `5.0` Litros para `8.0` Litros no seu código. Simule e esvazie o tanque aos poucos.
> *   **O LED vermelho e o aviso dinâmico na tela dispararam mais cedo, quando o tanque atingiu 8 Litros?**
> *   *Excelente!* Você percebeu como alterar constantes de software é o segredo para calibrar alarmes físicos em hardware real!

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
    3. Faça o upload de cada um dos arquivos individuais extraídos (`telemetria_combustivel.ino`, `diagram.json`, `README.md` e `folha_respostas.md`) diretamente na entrega da atividade.

> [!IMPORTANT]
> Antes de entregar, certifique-se de:
> * Preencher seu **Nome** e **Data** no cabeçalho do código (`telemetria_combustivel.ino`).
> * Responder a todas as perguntas de Reflexão Técnica no arquivo **`folha_respostas.md`**.

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**
