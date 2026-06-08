# Lab Intro – Atividades Práticas com Arduino

Bem-vindo ao repositório de atividades práticas de Arduino da disciplina de **Programação Básica**. Este material foi preparado para apoiar o seu aprendizado em lógica de programação associada ao hardware, utilizando os simuladores **Wokwi** e **Tinkercad**.

---

## 🧭 Guia Rápido do Aluno (FAQ)

### 1. O que eu tenho que fazer?
Você deve resolver os desafios propostos em cada atividade prática. O desenvolvimento é dividido em duas etapas para ajudar na sua evolução:
*   **Etapa Intermediária:** Foco na lógica de programação básica (leitura analógica, cálculos e exibição no LCD).
*   **Etapa Final (Desafio):** Otimização profissional de tela (eliminação do *flicker*/cintilação) e lógica de controle avançado (alarmes com LEDs e chaves de hardware).

### 2. Onde eu escrevo o meu código?
O código deve ser desenvolvido diretamente no arquivo `.ino` localizado na pasta do experimento correspondente:
*   **No Wokwi:** Abra o arquivo `[experimento].ino` dentro da pasta `wokwi/[experimento]/`.
*   **No Tinkercad:** Abra o arquivo `[experimento].ino` dentro da pasta `tinkercad/[experimento]/`.
*(Estes arquivos já contêm comentários indicando `# TODO` onde você deve inserir seu código).*

> [!IMPORTANT]
> **Atenção:** As soluções completas de referência do professor estão guardadas na pasta [/solucoes](file:///C:/GitHub/lab_intro/solucoes/) na raiz do repositório. Use-as apenas para tirar dúvidas após tentar resolver a atividade.

### 3. Como eu rodo a simulação?
*   **Pelo VS Code (Wokwi):**
    1. Abra o VS Code e instale a extensão **Wokwi Simulator**.
    2. Abra a pasta do experimento (ex: [wokwi/conversao_temperatura/](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/)).
    3. Pressione a tecla **F1**, selecione `Wokwi: Start Simulator` (ou clique no botão de Play na tela de diagram.json) para rodar o circuito simulado interativamente.
*   **Pelo Navegador (Wokwi Web ou Tinkercad):**
    1. Consulte o [Guia de Início Rápido do Wokwi Web](file:///C:/GitHub/lab_intro/docs/Guia_Wokwi_Inicio_Rapido.md) na pasta [docs/](file:///C:/GitHub/lab_intro/docs/) para ver como carregar os arquivos `.ino` e `diagram.json` online.
    2. Se preferir o Tinkercad, consulte o [Guia Técnico do Arduino Uno](file:///C:/GitHub/lab_intro/docs/Guia_Arduino_Uno.md) para montar a pinagem descrita no manual de cada projeto.

### 4. O que eu tenho que entregar ao professor?
Para cada atividade, você deve entregar:
1.  O arquivo **`.ino`** completo com o seu código.
2.  A seção **Reflexão Técnica** respondida diretamente no cabeçalho do arquivo `.ino`.
3.  A demonstração do circuito funcionando na simulação (link público do Wokwi Web ou apresentação ao vivo no computador para o professor).

---

## 📂 Estrutura do Repositório

```text
lab_intro/
│   README.md                   # Este guia de orientações para o aluno
│   .gitignore                  # Arquivos ignorados pelo Git
│
├─ docs/                        # Guias práticos de configuração e uso
│   ├─ Guia_Arduino_Uno.md
│   ├─ Guia_Wokwi_Inicio_Rapido.md
│   └─ Guia_Wokwi_VSCode_Integracao.md
│
├─ solucoes/                    # Gabarito do professor (códigos completos resolvidos)
│   ├─ conversao_temperatura_solucao.ino
│   ├─ aluguel_carro_solucao.ino
│   └─ telemetria_combustivel_solucao.ino
│
├─ referencias/                 # Slides originais (.pptx) da disciplina
├─ slides/                      # Apresentações de apoio modernas (Slidev)
│
├─ tinkercad/                   # Templates e instruções para uso no Tinkercad
│   ├─ conversao_temperatura/
│   ├─ aluguel_carro/
│   └─ telemetria_combustivel/
│
└─ wokwi/                       # Projetos prontos para simular localmente no Wokwi
    ├─ conversao_temperatura/   # Circuito + Template de programação do aluno
    ├─ aluguel_carro/           # Circuito + Template de programação do aluno
    └─ telemetria_combustivel/  # Circuito + Template de programação do aluno
```

---

## 🛠️ Atividades Práticas

### [1. Conversão de Temperatura (Celsius para Fahrenheit)](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/)
*   **O que fazer:** Ler o valor analógico de um potenciômetro, convertê-lo proporcionalmente para Celsius ($0$ a $60^{\circ}\text{C}$), calcular a temperatura em Fahrenheit ($F = C \times 1.8 + 32$), controlar LEDs indicadores de status (Verde para normal, Vermelho para quente) e exibir tudo em um LCD 16x2 sem flicker.
*   **Material:** [Roteiro detalhado do Experimento 1](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/README.md)

### [2. Aluguel de Carro (Locadora "Sai da Frente")](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/)
*   **O que fazer:** Controlar duas variáveis analógicas independentes usando dois potenciômetros (tempo de 1 a 30 dias, distância de 1 a 1000 km). Usar uma chave slide para escolher o tipo de carro (Popular ou SUV) e reajustar os preços da diária e do quilômetro rodado automaticamente. Calcular o total com 10% de desconto e exibir no LCD de forma otimizada.
*   **Material:** [Roteiro detalhado do Experimento 2](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/README.md)

### [3. Telemetria e Autonomia de Combustível](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/)
*   **O que fazer:** Projetar um display de painel automotivo em um LCD 20x4 contendo o volume do tanque (0 a 50L) e taxa de consumo (0 a 20 L/h) configurados por potenciômetros. Implementar proteção de divisão por zero na autonomia, desenhar uma barra de progresso gráfica horizontal (bloco `char(255)`) e acionar um alerta no pino 7 se o nível entrar na reserva (< 5L).
*   **Material:** [Roteiro detalhado do Experimento 3](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/README.md)

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**
