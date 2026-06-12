# Experimento 00: Primeiro Contato com o Wokwi Web (O LED do Painel)

Bem-vindo à sua primeira atividade prática com Arduino! Se você nunca mexeu com programação ou simuladores de eletrônica, **esta atividade é para você**. 

Nosso objetivo hoje não é criar códigos complexos, mas sim aprender a navegar, usar a interface do simulador online **Wokwi Web**, e entender como o microcontrolador se comunica com o computador.

---

## 🚀 O que é o Wokwi Web?
O Wokwi é um simulador de eletrônica e microcontroladores moderno que roda diretamente no seu navegador de internet. Com ele, você pode desenhar circuitos com placas (como o Arduino Uno), conectar componentes virtuais (como LEDs, botões e sensores) e testar seus códigos em tempo real sem medo de queimar nenhum componente físico!

---

## 🧭 Desvendando a Interface do Wokwi

Ao abrir o editor do Wokwi no seu navegador, a sua tela estará dividida em duas áreas principais:

```text
┌───────────────────────────────────────┬───────────────────────────────────────┐
│         PAINEL DA ESQUERDA            │          PAINEL DA DIREITA            │
│         (Código & Arquivos)           │         (Hardware & Circuito)         │
│                                       │                                       │
│  [Abas de Arquivos: ]                 │                                       │
│  sketch.ino    diagram.json           │  [Área de Visualização do Arduino]    │
│                                       │                                       │
│  1  void setup() {                    │             ┌─────────┐               │
│  2    pinMode(13, OUTPUT);            │             │ ARDUINO │   (LED)       │
│  3  }                                 │             │   UNO   │───[R]───( vermelho )
│                                       │             └─────────┘               │
│                                       │                                       │
│  [Console de Compilação]              │  [Botão Iniciar Simulação (Play Verde)]│
└───────────────────────────────────────┴───────────────────────────────────────┘
```

1.  **Painel da Esquerda (Editor de Software):** 
    *   Aqui é onde você edita os arquivos do projeto.
    *   A aba **`sketch.ino`** contém o código-fonte C++ que diz o que o Arduino deve fazer.
    *   A aba **`diagram.json`** contém o arquivo de configuração textual que desenha os fios e componentes no circuito.
2.  **Painel da Direita (Editor de Hardware):**
    *   É a representação física do laboratório. Aqui você vê a placa do Arduino, os componentes conectados e os fios de ligação.
    *   No topo desta área, você encontra o botão **Play (verde)** para ligar a simulação e o botão **`+` (azul)** para adicionar novos componentes.

---

## 🔌 O que é Comunicação Serial? (Explicado para Iniciantes)

Quando o Arduino está funcionando dentro de um veículo ou máquina, ele precisa enviar relatórios de dados para o computador principal ou painel de controle. Ele faz isso através da **Interface Serial**.

### Como isso acontece no mundo físico?
*   **Transmissão em Fila (Bit a Bit):** Imagine um fio de telégrafo muito fino. A comunicação serial é chamada de "serial" porque envia a informação em **série** (uma fila indiana de bits, um atrás do outro) por meio de um **único fio de transmissão (TX)**.
*   **Pulsos Elétricos (Tensão):** A placa do Arduino não entende palavras. Ela envia pulsos de energia elétrica:
    *   Quando ela quer enviar o bit **`1`**, ela aplica **5 Volts** (tensão alta) no fio.
    *   Quando ela quer enviar o bit **`0`**, ela aplica **0 Volts** (tensão baixa/GND) no fio.
*   **Decodificando Letras:** Se o Arduino quer enviar a letra **`A`**, o computador não lê a letra direto. O caractere `'A'` equivale ao número decimal **65** na tabela ASCII. Em binário (a linguagem do processador), 65 é escrito como **`01000001`**. O Arduino envia isso no fio na forma de pulsos rápidos de tensão:
    ```text
       0V     5V     0V     0V     0V     0V     0V     5V
    [  0  ][  1  ][  0  ][  0  ][  0  ][  0  ][  0  ][  1  ]  ===> Viajando pelo fio TX
    ```
*   **Baud Rate (A Velocidade da Conversa):** Para que o computador consiga ler esse sinal, ambos os lados precisam estar combinados sobre a velocidade de transmissão dos pulsos. Essa velocidade é chamada de **Baud Rate** (medida em bits por segundo). 
    *   No nosso código, usamos `Serial.begin(9600);`, o que significa que o Arduino transmitirá exatamente **9600 bits por segundo**. Se o computador tentar escutar em outra velocidade (como 115200), a conversa vira ruído e caracteres estranhos aparecerão na tela!

---

## 🏁 Passo a Passo: Sua Primeira Simulação

Siga as etapas abaixo para ligar seu circuito pela primeira vez!

### Passo 1: Preparar o Wokwi Online
1. Abra seu navegador e acesse: [wokwi.com/projects/new/arduino-uno](https://wokwi.com/projects/new/arduino-uno).
2. Se você quiser salvar seu projeto depois, clique em **Sign up** no canto superior direito para criar uma conta gratuita rápida usando seu e-mail ou conta Google.

---

### Passo 2: Copiar o Circuito Pronto (Hardware)
1. No seu computador local, abra o arquivo [diagram.json](file:///C:/GitHub/lab_intro/wokwi/00_introducao_wokwi/diagram.json) desta pasta e **copie todo o texto** (use Ctrl+A e Ctrl+C).
2. No site do Wokwi Web, clique na aba **`diagram.json`** no painel da esquerda.
3. Apague o texto que está lá e **cole** o conteúdo copiado (Ctrl+V).
4. *Olhe para a tela da direita:* **O circuito do Arduino Uno conectado a um LED vermelho surgiu na tela!**

---

### Passo 3: Copiar o Código de Programação (Software)
1. No seu computador local, abra o arquivo [00_introducao_wokwi.ino](file:///C:/GitHub/lab_intro/wokwi/00_introducao_wokwi/00_introducao_wokwi.ino) e **copie todo o texto**.
2. No Wokwi Web, clique na aba **`sketch.ino`** no painel da esquerda.
3. Apague o conteúdo padrão e **cole** o código copiado.

---

### Passo 4: Trazer o Roteiro para o Simulador (Leitura Lado a Lado)
Para poder ler estas instruções de forma integrada diretamente no simulador:
1. No painel de arquivos da esquerda no Wokwi Web, clique no botão **New File** (ícone de papel com sinal de mais).
2. Digite o nome exatamente como **`README.md`** e pressione Enter.
3. No seu computador local, abra este arquivo [README.md](file:///C:/GitHub/lab_intro/wokwi/00_introducao_wokwi/README.md) e copie todo o seu texto (Ctrl+A e Ctrl+C).
4. No Wokwi Web, cole o texto na aba `README.md` criada. O simulador mostrará o roteiro formatado diretamente na tela ao lado do circuito e código!

---

### Passo 5: Rodar a Simulação (A Primeira Vitória!)
1. No painel de circuito da direita, procure pelo **botão redondo verde (Play)** com a palavra *Start Simulation* e clique nele.
2. *Observe o circuito:* **O LED vermelho e o LED verde estão piscando de forma alternada — quando um acende, o outro apaga?**
3. *Observe o painel inferior:* **Uma aba chamada "Serial Monitor" abriu exibindo as mensagens de estado dos dois LEDs em tempo real?**

> **🧪 Teste e Verifique (Vitória Rápida!):**
> Se os dois LEDs estiverem alternando (vermelho ↔ verde) e o painel inferior mostrar as mensagens correndo a cada segundo, parabéns! Você acabou de rodar sua primeira simulação com dois pinos controlados de forma sincronizada!

---

### Passo 6: Modificar o Código (Entendendo o Software)
A programação altera o comportamento físico do hardware. Vamos alterar a velocidade da piscada:
1. Pare a simulação clicando no botão **Stop (vermelho)**.
2. No código da aba `sketch.ino`, procure pelas linhas que contêm `delay(1000);`. O número `1000` significa milissegundos (ou seja, 1 segundo).
3. Mude ambos os valores de `1000` para `200` (que equivale a 0.2 segundos).
4. Clique no botão de **Play (Iniciar Simulação)** novamente.

> **🧪 Teste e Verifique:**
> *   **O LED começou a piscar muito mais rápido na tela?**
> *   **As mensagens na tela do console Serial correm muito mais depressa?**
> *   *Sensacional!* Você acabou de mudar a velocidade de envio dos bits no fio TX e a frequência com que o pino 13 aplica tensão no LED!

---

### Passo 7: Modificar o Circuito (Entendendo o Hardware)
Podemos mudar as propriedades físicas dos componentes diretamente no arquivo de configuração do hardware. Vamos mudar a cor do LED:
1. Pare a simulação.
2. No painel esquerdo, clique na aba **`diagram.json`**.
3. Procure pela linha 8 do texto: `"color": "red"`.
4. Mude a palavra `"red"` para `"blue"`.
5. Inicie a simulação novamente.

> **🧪 Teste e Verifique:**
> *   **O LED físico piscando na tela mudou da cor vermelha para a cor azul?**
> *   *Parabéns!* Você aprendeu a alterar propriedades físicas de componentes virtuais diretamente no arquivo JSON.

### Passo 8: Altere, Teste e Veja o Que Acontece!

O circuito já possui **dois LEDs** prontos: o **vermelho** (pino 13) e o **verde** (pino 12).
Eles piscam de forma alternada — quando um acende, o outro apaga.

Agora é a sua vez de modificar o comportamento deles! Experimente os desafios abaixo:

#### 🟡 Desafio 1 — Mudar a velocidade da alternância
1. Pare a simulação.
2. No código, localize as duas linhas com `delay(1000);`.
3. Altere os dois valores de `1000` para `300` (0,3 segundo).
4. Inicie a simulação novamente.

> **🧪 Teste e Verifique:**
> *   **Os LEDs passaram a alternar muito mais rápido?**
> *   **As mensagens no Monitor Serial correm mais depressa?**

#### 🟠 Desafio 2 — Fazer os LEDs piscarem em tempos diferentes
E se o LED vermelho ficasse ligado por mais tempo que o verde?
1. Pare a simulação.
2. Separe os dois `delay()` do código para terem valores diferentes:
   * Após ligar o LED vermelho (e desligar o verde): use `delay(800);`
   * Após ligar o LED verde (e desligar o vermelho): use `delay(200);`
3. Inicie a simulação novamente.

> **🧪 Teste e Verifique:**
> *   **O LED vermelho fica aceso por mais tempo que o verde?**
> *   *Isso simula um semáforo assimétrico — ótima introdução ao controle de tempo!*

#### 🔴 Desafio 3 — Inverter quem começa ligado
E se o LED **verde** fosse o primeiro a acender ao ligar o Arduino?
1. Pare a simulação.
2. Na **FASE 1** do loop, troque os valores:
   * `digitalWrite(13, HIGH)` → `digitalWrite(13, LOW)`
   * `digitalWrite(12, LOW)`  → `digitalWrite(12, HIGH)`
3. Faça o mesmo ajuste na **FASE 2** (invertendo de volta).
4. Inicie a simulação e observe qual LED acende primeiro!

> **🧪 Teste e Verifique:**
> *   **O LED verde agora é o primeiro a acender?**
> *   *Perceba que a lógica de alternância é a mesma — só a ordem de início mudou!*

---

## 🛠️ Superpoderes da Interface do Wokwi (Ferramentas Extras)

À medida que as aulas avançam, você precisará usar outros recursos do Wokwi. Veja como turbinar seu fluxo de trabalho:

### 1. Library Manager (Gerenciador de Bibliotecas)
Se o projeto precisar de um componente inteligente (como uma tela de LCD), você precisará instalar a biblioteca correspondente:
* Na barra de ferramentas lateral esquerda do Wokwi Web, clique no **ícone de livrinhos** (Library Manager).
* Clique em **+ Add library**, digite o nome (exemplo: `LiquidCrystal`) e selecione-a para instalar no seu projeto instantaneamente!

### 2. Atalhos de Teclado do Editor (Software)
Escrever código diretamente na web fica muito mais prático com os atalhos integrados:
* **Autoformatar Código:** Pressione `Alt + Shift + F` (Windows/Linux) ou `⌥ + ⇧ + F` (Mac) para identar e arrumar a estrutura do código automaticamente.
* **Autocompletar Código:** Pressione `Ctrl + Space` para abrir a caixa de sugestões e autocompletar comandos do Arduino.
* **Comentar/Descomentar Linha:** Selecione a linha ou bloco e pressione `Ctrl + /` (Windows/Linux) ou `⌘ + /` (Mac).
* **Iniciar Simulação:** Pressione `Ctrl + Enter` (Windows/Linux) ou `⌘ + Enter` (Mac) para rodar o circuito sem precisar clicar em nada.
* **Salvar Projeto:** Pressione `Ctrl + S` (Windows/Linux) ou `⌘ + S` (Mac).
* **Paleta de Comandos:** Pressione `F1` para buscar qualquer funcionalidade interna do editor de código.
* Para ver a lista completa de atalhos de programação, consulte: [Editor Keyboard Shortcuts](https://docs.wokwi.com/keyboard-shortcuts).

### 3. Segredos do Editor de Diagramas (Hardware)
Desenhar circuitos fica muito mais rápido se você dominar estas técnicas:
* **Adicionar Componente:** Pressione a tecla `A` com a área de circuito em foco para abrir o menu de componentes.
* **Rotacionar Componente:** Selecione um componente e pressione `R` para girá-lo 90 graus.
* **Duplicar Componente:** Pressione `D` para clonar o componente selecionado rapidamente.
* **Apagar Componentes ou Fios:** Selecione a peça e pressione `Delete` (ou dê um clique duplo em um fio para removê-lo).
* **Cores de Fios Instantâneas:** Enquanto arrasta um novo fio ou com um fio selecionado, pressione las teclas numéricas de `0` a `9` ou as letras `C` (Ciano), `L` (Lima), `M` (Magenta), `P` (Roxo/Purple) e `Y` (Amarelo) para mudar a cor na hora. Ex: `0` para Preto (GND), `2` para Vermelho (VCC).
* **Grade e Réguas:** Pressione `G` para exibir a grade milimétrica e réguas de medição física. Segure `Shift` ao arrastar um componente para desativar a grade temporariamente, ou `Ctrl` / `Alt` para usar uma grade ultrafina.
* **Copiar e Colar Circuitos:** Segurando a tecla `Shift`, clique em múltiplos componentes. Copie com `Ctrl + C` (o circuito é copiado em JSON para sua área de transferência, incluindo os fios internos!) e cole com `Ctrl + V` em qualquer outro projeto do Wokwi!
* Para entender todos os recursos de montagem visual, consulte: [Wokwi Diagram Editor Guide](https://docs.wokwi.com/guides/diagram-editor).

### 4. Dicas Avançadas do Monitor Serial
Como vimos, a comunicação serial envia bits fisicamente pelo cabo TX:
* **Abertura Inteligente:** Por padrão, o console inferior abre sozinho apenas após o Arduino enviar a primeira linha de texto. Se quiser que ele fique sempre aberto ou inicie como um Plotter Gráfico, você pode editar a seção `"serialMonitor"` no arquivo [diagram.json](file:///C:/GitHub/lab_intro/wokwi/00_introducao_wokwi/diagram.json).
* **Suporte a Cores:** Você pode imprimir mensagens com cores diferentes (como alertas vermelhos ou logs verdes) usando códigos ANSI especiais se habilitar o modo terminal no [diagram.json](file:///C:/GitHub/lab_intro/wokwi/00_introducao_wokwi/diagram.json).
* Para detalhes de configuração do console e envio de comandos para o Arduino, consulte: [Wokwi Serial Monitor Guide](https://docs.wokwi.com/guides/serial-monitor).

---

### Passo 9: Como Salvar e Entregar a Atividade

Você possui duas opções para entregar a sua atividade prática no Classroom. Escolha uma delas conforme a orientação do professor:

*   **Opção 1: Enviar o Link do Wokwi (Recomendado):**
    1. No menu superior da tela do Wokwi Web, clique no botão **Save**.
    2. Clique no botão **Share** no topo da tela e copie a URL única gerada (ou copie direto da barra de endereço).
    3. Cole este link na entrega da sua atividade no Classroom.
*   **Opção 2: Enviar os Arquivos Individuais:**
    1. Clique em **Download Project** no menu do Wokwi (isso baixará um arquivo compactado `.zip`).
    2. **IMPORTANTE: NÃO envie o arquivo .zip no Classroom.** Extraia a pasta compactada no seu computador.
    3. Faça o upload de cada um dos arquivos individuais extraídos (`sketch.ino`, `diagram.json`, `README.md` e `folha_respostas.md`) diretamente na entrega da atividade.

> [!IMPORTANT]
> Antes de entregar, certifique-se de:
> * Preencher seu **Nome** e **Data** no cabeçalho do código (`00_introducao_wokwi.ino`).
> * Responder às perguntas obrigatórias no arquivo **`folha_respostas.md`** (veja as instruções de criação no checklist abaixo).

---

## ✅ Checklist de Conclusão da Atividade
1.  [ ] Criou conta no Wokwi Web.
2.  [ ] Criou o arquivo `README.md` no simulador e colou o roteiro para leitura integrada lado a lado.
3.  [ ] Criou o arquivo `folha_respostas.md` no simulador e respondeu às reflexões rápidas.
4.  [ ] Carregou o circuito (`diagram.json`) e o código base (`sketch.ino`).
5.  [ ] Viu os dois LEDs (vermelho e verde) alternando e leu as mensagens no Monitor Serial.
6.  [ ] Alterou o código para piscar os LEDs rapidamente a 0.3 segundos (300ms) — Desafio 1.
7.  [ ] Fez os LEDs alternarem em tempos diferentes (800ms × 200ms) — Desafio 2.
8.  [ ] Inverteu a ordem de início dos LEDs (verde acende primeiro) — Desafio 3.
9.  [ ] Alterou a cor do LED no arquivo diagram.json para azul (Passo 7).
10. [ ] Salvou o projeto, fez o download dos arquivos individuais (ou copiou o link) e entregou.

*Você concluiu o Experimento Zero com sucesso! Agora você sabe como a informação corre em fios elétricos e como operar o simulador. Você está pronto para iniciar as atividades práticas da VoltLog!*

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**
