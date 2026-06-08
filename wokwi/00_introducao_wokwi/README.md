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

### Passo 4: Rodar a Simulação (A Primeira Vitória!)
1. No painel de circuito da direita, procure pelo **botão redondo verde (Play)** com a palavra *Start Simulation* e clique nele.
2. *Observe o circuito:* **O LED vermelho conectado ao Arduino começou a piscar lentamente a cada 1 segundo?**
3. *Observe o painel inferior:* **Uma aba chamada "Serial Monitor" abriu exibindo as mensagens de "LED LIGADO" e "LED DESLIGADO" em tempo real?**

> **🧪 Teste e Verifique (Vitória Rápida!):**
> Se o LED físico vermelho estiver acendendo e o painel inferior estiver mostrando as mensagens de texto correndo de segundo em segundo, parabéns! Você acabou de rodar sua primeira simulação e ler dados enviados via porta serial!

---

### Passo 5: Modificar o Código (Entendendo o Software)
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

### Passo 6: Modificar o Circuito (Entendendo o Hardware)
Podemos mudar as propriedades físicas dos componentes diretamente no arquivo de configuração do hardware. Vamos mudar a cor do LED:
1. Pare a simulação.
2. No painel esquerdo, clique na aba **`diagram.json`**.
3. Procure pela linha 8 do texto: `"color": "red"`.
4. Mude a palavra `"red"` para `"blue"`.
5. Inicie a simulação novamente.

> **🧪 Teste e Verifique:**
> *   **O LED físico piscando na tela mudou da cor vermelha para a cor azul?**
> *   *Parabéns!* Você aprendeu a alterar propriedades físicas de componentes virtuais diretamente no arquivo JSON.

### Passo 7: Praticando no Editor Visual (Adicionar e Customizar Componentes)

Agora vamos mexer no hardware usando as mãos (virtualmente) e atalhos rápidos! Vamos adicionar um novo LED ao nosso circuito para praticar:
1. Pare a simulação clicando em **Stop** (se ela estiver rodando).
2. Clique em qualquer área em branco do painel da direita (o painel de circuitos) para focar nele.
3. Pressione a tecla **`A`** no seu teclado. O menu de seleção de componentes surgirá na tela.
4. Digite **`LED`** na barra de pesquisa e selecione o componente **LED** comum. Ele aparecerá no centro do painel.
5. Arraste esse novo LED para uma posição vazia próxima ao Arduino.
6. Com o LED selecionado (ele ficará com um contorno tracejado azul):
   * Pressione a tecla **`R`** algumas vezes. *Observe como ele gira 90 graus a cada clique!* Isso ajuda muito a alinhar resistores e outros componentes.
   * Pressione a tecla **`D`** uma vez. *Um segundo LED idêntico surgirá ao lado dele!* (Você pode deletar este LED extra clicando nele e pressionando a tecla **`Delete`**).
7. Vamos conectar o LED original:
   * Coloque o mouse sobre a perna esquerda do LED (chamada *Cathode* ou terminal negativo).
   * Clique nela e depois clique em qualquer pino cinza escrito **`GND`** no Arduino Uno. Um fio de ligação verde ou preto será gerado automaticamente.
   * Coloque o mouse sobre a perna direita do LED (chamada *Anode* ou terminal positivo).
   * Clique nela e depois clique no pino **`12`** do Arduino Uno.
8. Customizando as cores dos fios com atalhos de teclado:
   * Clique em cima do fio que você conectou ao pino 12 para selecioná-lo.
   * Com o fio selecionado, pressione a tecla **`2`** no seu teclado. *O fio mudará de cor instantaneamente para Vermelho!*
   * Agora selecione o fio conectado ao GND e pressione a tecla **`0`** para pintá-lo de **Preto** (o padrão de circuitos eletrônicos para cabos terra).

> **🧪 Teste e Verifique:**
> *   **Você conseguiu adicionar, rotacionar e conectar o LED usando apenas as teclas do teclado e o mouse?**
> *   **Os fios mudaram de cor ao pressionar `2` e `0`?**
> *   *Perfeito!* Você acaba de dominar as ferramentas visuais do simulador de circuitos. Agora o desenho de qualquer circuito será incrivelmente ágil!

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

### Passo 8: Como Salvar e Entregar o Link
Ao final de cada aula prática, você deve enviar o link da sua simulação para avaliação do professor no Classroom. Veja como é fácil:
1. No menu superior da tela do Wokwi, clique no botão **Save**.
2. O Wokwi salvará o projeto na sua conta e a barra de endereços do seu navegador mudará para uma URL única (exemplo: `https://wokwi.com/projects/400039281...`).
3. Clique no botão **Share** no topo da tela e copie a URL gerada (ou copie direto da barra de endereço).
4. Cole este link na entrega da sua atividade!

---

## ✅ Checklist de Conclusão da Atividade
1.  [ ] Criou conta no Wokwi Web.
2.  [ ] Carregou o circuito (`diagram.json`) e o código base (`sketch.ino`).
3.  [ ] Viu o LED vermelho piscar e leu as mensagens no Monitor Serial inferior.
4.  [ ] Alterou o código para piscar o LED e enviar dados rapidamente a 0.2 segundos (200ms).
5.  [ ] Alterou a cor do LED no arquivo diagram.json para azul.
6.  [ ] Adicionou um LED pelo painel visual, rotacionou-o e alterou as cores dos fios usando atalhos (`2` e `0`).
7.  [ ] Salvou o projeto e guardou o link de compartilhamento.

*Você concluiu o Experimento Zero com sucesso! Agora você sabe como a informação corre em fios elétricos e como operar o simulador. Você está pronto para iniciar as atividades práticas da VoltLog!*

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**
