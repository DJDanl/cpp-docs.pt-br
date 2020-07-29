---
title: Aviso do compilador (nível 4) C4740
ms.date: 11/04/2016
f1_keywords:
- C4740
helpviewer_keywords:
- C4740
ms.assetid: 85528969-966a-44b4-8a2f-971704c64477
ms.openlocfilehash: 0aa4cb9df3f6f9d7499c67fb0b07bee5dabd6d73
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219827"
---
# <a name="compiler-warning-level-4-c4740"></a>Aviso do compilador (nível 4) C4740

o fluxo para dentro ou para fora do código asm embutido suprime a otimização global

Quando há um salto para dentro ou para fora de um **`asm`** bloco, as otimizações globais são desabilitadas para essa função.

O exemplo a seguir gera C4740:

```cpp
// C4740.cpp
// compile with: /O2 /W4
// processor: x86
int main() {
   __asm jmp tester
   tester:;
}
```
