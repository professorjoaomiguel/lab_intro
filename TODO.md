# TODO — lab_intro

Registro de melhorias, correções e tarefas pendentes do projeto.

---

## 🔴 Pendente

### Adequar textos para 50 colunas (exibição no Wokwi)

O monitor Serial do Wokwi exibe **50 colunas** por padrão. Strings longas quebram a
formatação visual. Todos os `Serial.println()` e `LCD.print()` devem ser revisados
para caber em 50 caracteres por linha.

Arquivos afetados:

- [ ] `wokwi/00_introducao_wokwi/00_introducao_wokwi.ino`
  - Revisar mensagens no `Serial.println()`
- [ ] `wokwi/aluguel_carro/aluguel_carro.ino`
  - Revisar strings do `LCD.print()`
- [ ] `wokwi/conversao_temperatura/conversao_temperatura.ino`
  - Revisar strings do `LCD.print()`
- [ ] `wokwi/telemetria_combustivel/telemetria_combustivel.ino`
  - Revisar strings do `LCD.print()` (incluindo linha `"Autonomia: INF (elet)"` — 22 chars, OK)

---

## ✅ Concluído

_(nenhum item ainda)_

---

> Atualizado em: 2026-06-11
