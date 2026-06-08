# Experimento 00: Primeiro Contato com o Wokwi Web (O LED do Painel)

Bem-vindo à sua primeira atividade prática com Arduino! Se você nunca mexeu com programação ou simuladores de eletrônica, **esta atividade é para você**. 

Nosso objetivo hoje não é criar códigos complexos, mas sim aprender a navegar e usar a interface do simulador online **Wokwi Web**.

---

## 🚀 O que é o Wokwi Web?
O Wokwi é um simulador de eletrônica e microcontroladores moderno que roda diretamente no seu navegador de internet. Com ele, você pode desenhar circuitos com placas (como o Arduino Uno), conectar componentes físicos (como LEDs, botões e sensores) e testar seus códigos em tempo real sem medo de queimar nenhum componente físico!

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
4. *Olhe para a tela da direita:* **O circuito do Arduino Uno conectado a um LED vermelho surgiu magicamente na tela!**

---

### Passo 3: Copiar o Código de Programação (Software)
1. No seu computador local, abra o arquivo [00_introducao_wokwi.ino](file:///C:/GitHub/lab_intro/wokwi/00_introducao_wokwi/00_introducao_wokwi.ino) e **copie todo o texto**.
2. No Wokwi Web, clique na aba **`sketch.ino`** no painel da esquerda.
3. Apague o conteúdo padrão e **cole** o código copiado.

---

### Passo 4: Rodar a Simulação (A Primeira Vitória!)
1. No painel de circuito da direita, procure pelo **botão redondo verde (Play)** com a palavra *Start Simulation* e clique nele.
2. *Observe o circuito:* **O LED vermelho conectado ao Arduino começou a piscar lentamente a cada 1 segundo?**

> **🧪 Teste e Verifique (Vitória Rápida!):**
> Se o LED físico vermelho (e o LED interno marcado com a letra **L** na placa do Arduino) estiverem acendendo e apagando de forma ritmada, parabéns! Você acaba de rodar sua primeira simulação de sistemas embarcados!

---

### Passo 5: Modificar o Código (Entendendo o Software)
A programação altera o comportamento físico do hardware. Vamos alterar a velocidade da piscada:
1. Pare a simulação clicando no botão **Stop (vermelho)**.
2. No código da aba `sketch.ino`, procure pelas linhas que contêm `delay(1000);`. O número `1000` significa milissegundos (ou seja, 1 segundo).
3. Mude ambos os valores de `1000` para `200` (que equivale a 0.2 segundos).
4. Clique no botão de **Play (Iniciar Simulação)** novamente.

> **🧪 Teste e Verifique:**
> *   **O LED começou a piscar muito mais rápido na tela?**
> *   *Sensacional!* Você acabou de mudar a lógica interna do processador e viu a reação física na simulação.

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
> *   *Parabéns!* Você aprendeu a alterar propriedades físicas de componentes virtuais.

---

### Passo 7: Como Salvar e Entregar o Link
Ao final de cada aula prática, você deve enviar o link da sua simulação para avaliação do professor no Classroom. Veja como é fácil:
1. No menu superior da tela do Wokwi, clique no botão **Save**.
2. O Wokwi salvará o projeto na sua conta e a barra de endereços do seu navegador mudará para uma URL única (exemplo: `https://wokwi.com/projects/400039281...`).
3. Clique no botão **Share** no topo da tela e copie a URL gerada (ou copie direto da barra de endereço).
4. Cole este link na entrega da sua atividade!

---

## ✅ Checklist de Conclusão da Atividade
1.  [ ] Criou conta no Wokwi Web.
2.  [ ] Carregou o circuito (`diagram.json`) e o código base (`sketch.ino`).
3.  [ ] Testou o LED piscando a 1 segundo.
4.  [ ] Alterou o código para piscar o LED rapidamente a 0.2 segundos (200ms).
5.  [ ] Alterou a cor do LED no arquivo diagram.json para azul.
6.  [ ] Salvou o projeto e guardou o link de compartilhamento.

*Você concluiu o Experimento Zero com sucesso! Agora você sabe navegar no Wokwi e está pronto para o Experimento 1 (Monitor de Baterias).*

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**
