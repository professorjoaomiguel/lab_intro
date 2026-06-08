# Lab Intro – Atividades Práticas com Arduino

Bem-vindo ao repositório de atividades práticas de Arduino da disciplina de **Programação Básica**. Este material foi preparado para apoiar o seu aprendizado em lógica de programação associada ao hardware, utilizando os simuladores **Wokwi** (Web) e **Tinkercad** (Web).

---

## 🧭 Trilhas de Aprendizagem

Este repositório está dividido em duas trilhas distintas de laboratórios:

### 🌐 Trilha 1: Wokwi (Moderna e Renovada)
Esta trilha utiliza o simulador online **Wokwi Web** e traz implementações modernas, incluindo controle avançado de periféricos, exibição gráfica, e tratamento de estados.
*   **Como fazer:** O repositório serve apenas como o ponto de partida. O aluno deve acessar a pasta da atividade, copiar o conteúdo dos arquivos para o simulador online e realizar todo o desenvolvimento diretamente no navegador.
*   **O que buscar em cada pasta:**
    *   `README.md`: O roteiro didático que você pode colar na aba de documentação do Wokwi.
    *   `diagram.json`: O arquivo de configuração do circuito. Basta colar na aba `diagram.json` do Wokwi para carregar os componentes automaticamente.
    *   `[nome].ino`: O código inicial (template com marcações `# TODO`) para começar sua programação.
*   **Projetos:**
    1.  [Experimento 01: Conversão de Temperatura com LCD e Alarme](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/)
    2.  [Experimento 02: Aluguel de Carro com LCD e Seleção de Categoria](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/)
    3.  [Experimento 03: Telemetria de Combustível com Barra Gráfica (LCD 20x4)](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/)

### 🛠️ Trilha 2: Tinkercad (Clássica e Original)
Esta trilha mantém os projetos originais criados originalmente para o **Tinkercad**, sem novas implementações, servindo para compatibilidade com o material clássico da disciplina.
*   **Como fazer:** O aluno deve abrir o Tinkercad, montar o circuito manualmente a partir do manual de pinagem e colar o código inicial (`.ino`) na aba de código do simulador.
*   **Projetos:**
    1.  [Experimento 01: Conversão de Temperatura com LCD (Original)](file:///C:/GitHub/lab_intro/tinkercad/conversao_temperatura/)
    2.  [Experimento 02: Aluguel de Carro com LCD (Original)](file:///C:/GitHub/lab_intro/tinkercad/aluguel_carro/)

---

## 🧭 Guia Rápido do Aluno: Fluxo do Wokwi Web

Se você está realizando as atividades no **Wokwi**, siga estes 3 passos simples para iniciar:

1.  **Crie o Projeto:** Acesse [wokwi.com/projects/new/arduino-uno](https://wokwi.com/projects/new/arduino-uno) no seu navegador para abrir um projeto em branco.
2.  **Carregue o Circuito:** Acesse a aba **`diagram.json`** no editor do Wokwi, apague tudo o que estiver lá e cole o conteúdo do arquivo `diagram.json` que está na pasta da atividade. *Os componentes aparecerão conectados na tela!*
3.  **Cole o Código e Roteiro:** Cole o conteúdo do arquivo `.ino` na aba principal de código e, opcionalmente, crie um arquivo chamado `README.md` no Wokwi para colar as instruções da aula e ler tudo na mesma tela.

---

## 📂 Estrutura do Repositório

```text
lab_intro/
│   README.md                   # Este guia de orientações
│
├─ docs/                        # Guias práticos de suporte online
│   ├─ Guia_Arduino_Uno.md
│   └─ Guia_Wokwi_Inicio_Rapido.md
│
├─ solucoes/                    # Gabarito com as soluções completas do Wokwi
│   ├─ conversao_temperatura_solucao.ino
│   ├─ aluguel_carro_solucao.ino
│   └─ telemetria_combustivel_solucao.ino
│
├─ referencias/                 # Slides originais (.pptx) da disciplina
├─ slides/                      # Apresentações de apoio modernas (Slidev)
│
├─ tinkercad/                   # Projetos Originais Tinkercad (Sem modificações)
│   ├─ conversao_temperatura/   # README clássico + Template original
│   └─ aluguel_carro/           # README clássico + Template original
│
└─ wokwi/                       # Projetos Renovados Wokwi (Simulação Web)
    ├─ conversao_temperatura/   # Esquema, roteiro e código renovados
    ├─ aluguel_carro/           # Esquema, roteiro e código renovados
    └─ telemetria_combustivel/  # Esquema, roteiro e código renovados
```

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**
