# Guia: Como Iniciar um Laboratório (GitHub ➡️ Wokwi Web)
`#Wokwi` `#GitHub` `#Setup` `#PassoAPasso`

Este guia explica como você deve levar as orientações e arquivos base deste repositório para o simulador Wokwi na web.

---

## 🚀 O Processo em 3 Passos

### 1. Preparação (Lado GitHub)
Navegue até a pasta do laboratório desejado (ex: `LAB_05_Sensores_Serial`).
-   Abra o arquivo `README.md` para ler as instruções e desafios.
-   Se houver um arquivo `diagram.json`, abra-o e **copie todo o conteúdo** (Ctrl+A, Ctrl+C). Este arquivo contém o desenho do hardware.
-   Se houver um arquivo `sketch.ino`, faça o mesmo (Copie o código).

### 2. Criação (Lado Wokwi)
Abra a página de seleção do simulador ou use um link direto para a placa do seu laboratório:
*   🌐 [**Seleção de Placas (Escolha qualquer placa)**](https://wokwi.com/projects/new/)
*   🚀 [**Projeto Vazio: Wokwi Blank (Sem placa)**](https://wokwi.com/projects/new/blank)
*   🚀 [**Projeto Vazio: Arduino Uno**](https://wokwi.com/projects/new/arduino-uno)
*   🚀 [**Projeto Vazio: ESP32 DevKit v4**](https://wokwi.com/projects/new/esp32)
*   🚀 [**Projeto Vazio: Raspberry Pi Pico**](https://wokwi.com/projects/new/pi-pico)

### 3. Sincronização (O "Pulo do Gato")
Para não ter que desenhar o circuito do zero e manter as instruções à mão:
1.  No editor do Wokwi, procure a aba chamada **diagram.json**.
2.  Apague o conteúdo atual e **cole** o que você copiou do GitHub. *Os componentes aparecerão na tela!*
3.  Volte para a aba do código (geralmente `sketch.ino`). Cole o código base.

---

## 📂 Organização Interna (Dica do Prof!)
Para que seu projeto Wokwi fique completo e documentado, você pode criar arquivos dentro dele:
1.  No editor do Wokwi, clique na aba da seta ao lado de "sketch.ino" e escolha **New File**.
2.  Nomeie como **`README.md`**.
3.  **Cole o conteúdo do roteiro do GitHub aqui dentro.**
4.  Pronto! Agora você tem as instruções da aula diretamente no simulador, sem precisar trocar de aba.

---

## 🛠️ Outros Ajustes Necessários

### 📚 Bibliotecas
Se o laboratório usar componentes como DHT22 ou LCD I2C:
1.  Clique no ícone de **Library Manager** (ícone de livros na aba esquerda).
2.  Clique no botão **+** (Add).
3.  Digite o nome da biblioteca (ex: `DHT sensor library`) e selecione-a.

### 💾 Salvando seu Progresso
-   O Wokwi gera um link único para o seu projeto. **Salve este link!**
-   É este link que você deve enviar no Google Classroom ao final da aula.

---
**⬅️ [Voltar ao README Principal](../README.md)**

