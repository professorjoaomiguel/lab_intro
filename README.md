# Lab Intro – Atividades Práticas com Arduino

Este repositório contém atividades práticas de Arduino utilizando os simuladores **Tinkercad** e **Wokwi**, baseadas no material original da disciplina de Programação Básica. Cada pasta contém os códigos-fonte (`.ino`) e os esquemas de circuito para simulação.

## Estrutura do Repositório

```text
lab_intro/
│   README.md               # Este documento de orientações
│   .gitignore              # Arquivos ignorados pelo Git
│
├─ docs/                    # Guias e suporte para o simulador Wokwi e Arduino
│   ├─ Guia_Arduino_Uno.md
│   ├─ Guia_Wokwi_Inicio_Rapido.md
│   └─ Guia_Wokwi_VSCode_Integracao.md
│
├─ referencias/             # Apresentações originais (.pptx) e códigos-fonte base (.c)
├─ slides/                  # Apresentações de apoio (Modelo Slidev)
│
├─ tinkercad/               # Projetos para o Tinkercad (Códigos fonte .ino e templates)
│   ├─ conversao_temperatura/
│   ├─ aluguel_carro/
│   └─ telemetria_combustivel/
│
└─ wokwi/                   # Projetos prontos para simular no Wokwi (diagram.json, .ino e templates)
    ├─ conversao_temperatura/
    ├─ aluguel_carro/
    └─ telemetria_combustivel/
```

---

## Atividades Práticas

### 1. Conversão de Temperatura (Celsius para Fahrenheit)
* **Objetivo:** Ler a posição de um potenciômetro, mapeá-la para uma temperatura em Celsius (0 a 60 °C), realizar a conversão matemática para Fahrenheit ($F = C \times 1.8 + 32$) e exibir ambos os valores em um Display LCD 16x2.
* **Desafio Resolvido (Flicker/Oscilação):** O código foi otimizado para que os textos fixos (`TempC:` e `TempF:`) sejam impressos apenas uma vez no `setup()`. No `loop()`, os valores numéricos só são atualizados no display quando a temperatura realmente muda, eliminando completamente as piscadas indesejadas na tela.
* **Simuladores:**
  - Código-fonte em [tinkercad/conversao_temperatura](file:///C:/GitHub/lab_intro/tinkercad/conversao_temperatura/conversao_temperatura.ino)
  - Projeto completo em [wokwi/conversao_temperatura](file:///C:/GitHub/lab_intro/wokwi/conversao_temperatura/) (abra o `diagram.json` no Wokwi para simular).

### 2. Aluguel de Carro (Locadora "Sai da Frente")
* **Objetivo:** Simular as entradas do problema de aluguel de carros (dias de locação de 1 a 30 e quilometragem rodada de 1 a 1000 km) usando dois potenciômetros. O programa calcula o custo total com base na diária de R$ 30,00 e R$ 0,01 por km rodado, aplicando 10% de desconto no valor final, e exibe no LCD.
* **Simuladores:**
  - Código-fonte em [tinkercad/aluguel_carro](file:///C:/GitHub/lab_intro/tinkercad/aluguel_carro/aluguel_carro.ino)
  - Projeto completo em [wokwi/aluguel_carro](file:///C:/GitHub/lab_intro/wokwi/aluguel_carro/) com suporte a dois potenciômetros (Dias e Distância).

### 3. Telemetria e Autonomia de Combustível
* **Objetivo:** Projetar um painel de telemetria em um LCD 20x4 usando dois potenciômetros (nível de combustível de 0 a 50L e taxa de consumo de 0 a 20 L/h). Implementa proteção de software contra divisão por zero, uma barra de progresso horizontal gráfica e aciona um LED físico de alerta (pino 7) caso o nível entre na reserva (< 5L).
* **Simuladores:**
  - Código-fonte em [tinkercad/telemetria_combustivel](file:///C:/GitHub/lab_intro/tinkercad/telemetria_combustivel/telemetria_combustivel.ino)
  - Projeto completo em [wokwi/telemetria_combustivel](file:///C:/GitHub/lab_intro/wokwi/telemetria_combustivel/) com suporte a dois potenciômetros, LED de alerta e display 20x4.

---

## Como Usar

### Guias de Suporte Técnico
Consulte nossos guias práticos locais na pasta [docs/](file:///C:/GitHub/lab_intro/docs/):
*   [Guia Técnico do Arduino Uno](file:///C:/GitHub/lab_intro/docs/Guia_Arduino_Uno.md)
*   [Guia de Início Rápido do Wokwi Web](file:///C:/GitHub/lab_intro/docs/Guia_Wokwi_Inicio_Rapido.md)
*   [Guia de Integração do Wokwi com o VS Code](file:///C:/GitHub/lab_intro/docs/Guia_Wokwi_VSCode_Integracao.md)

### Usando o Wokwi (Simulação Imediata)
1. Certifique-se de ter a extensão **Wokwi** instalada no VS Code ou acesse [wokwi.com](https://wokwi.com).
2. Abra a pasta do projeto desejado dentro do diretório `wokwi/` (ex: `wokwi/conversao_temperatura/`).
3. Dê início à simulação para ver o circuito funcionando interativamente.

### Usando o Tinkercad
1. Crie ou acesse sua conta no [Tinkercad](https://www.tinkercad.com/).
2. Monte o circuito contendo um Arduino Uno, o display LCD correspondente (16x2 ou 20x4 ligado nos pinos indicados) e potenciômetro(s).
3. Copie o código contido no arquivo `.ino` ou no template correspondente da pasta `tinkercad/` e cole na aba de código do Tinkercad.

---

© 2026 João Miguel Lac Roehe – **Faculdade de Tecnologia SENAI Porto Alegre**

