# Wokwi e VS Code - Guia Técnico S122

## 1. Visão Geral (O Básico)
**Para que serve:** Simulação de hardware IoT integrada ao ambiente profissional de desenvolvimento do VS Code.
**Contexto M3F:** [X] Percepção (Edge) | [ ] Transporte (Fog) | [ ] Aplicação (Cloud)

## 2. Fluxo de Dados (I/O)
- **Entrada (Input):** Código Python/C, arquivos de configuração de circuito (`diagram.json`).
- **Saída (Output):** Simulação visual de periféricos (LEDs, LCDs, Sensores), monitor serial simulado.

## 3. Instalação e Configuração

### 🪟 Windows / 🐧 Linux
1.  **Download VS Code:** https://code.visualstudio.com
2.  **Instalação da Extensão:** Procure por "Wokwi Simulator" no marketplace do VS Code.
3.  **Wokwi CLI (Opcional - Recomendado para Validação):**
    - Instale a ferramenta CLI para validar seus esquemas:
      `npm install -g wokwi-cli`
    - Use o comando `wokwi-cli lint` para validar seu `diagram.json`.
4.  **Procedimento:** Crie os arquivos `diagram.json` e `wokwi.toml` na raiz do seu projeto.
5.  **Verificação:** `F1 > Wokwi: Start Simulator`.

## 4. Integração (Ecossistema S122)
- **Conecta com:** VS Code para edição de código assistida por IA (Edge Copilot).
- **Substitui:** O hardware físico durante a fase de prototipagem lógica.
- **Validação:** Use o `wokwi-cli lint` para garantir que as conexões e componentes no `diagram.json` estão corretos antes de iniciar a simulação.

**Links Relacionados (CORE):**
- Guia VS Code: (Integrado neste documento)
- Guia ESP32: Guia_ESP32_MicroPython.md
- Documentação Wokwi CLI: https://docs.wokwi.com/wokwi-ci/cli-usage

## 5. Referências e Repositórios
- **Documentação Wokwi:** https://docs.wokwi.com
- **Wokwi VS Code Extension:** https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode

## 6. Solução de Problemas (Troubleshooting)
- **Erro de Licença:** A extensão exige ativação via browser no primeiro uso.
- **Simulação Lenta:** Verifique se há muitos componentes complexos ou loops sem `time.sleep()` no código.

## 7. Fontes de Consulta (AI & Web)
- Wokwi Docs: https://docs.wokwi.com/
- Visual Studio Code Docs: https://code.visualstudio.com/docs

---
**⬅️ [Voltar ao README Principal](../README.md)**

*Documento em constante atualização. Versão: 2026/1*

