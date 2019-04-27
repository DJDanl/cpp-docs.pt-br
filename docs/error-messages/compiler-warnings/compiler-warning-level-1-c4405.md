---
title: Compilador aviso (nível 1) C4405
ms.date: 11/04/2016
f1_keywords:
- C4405
helpviewer_keywords:
- C4405
ms.assetid: 155c64d6-58ae-4455-b61f-ccd711c5da96
ms.openlocfilehash: e85bdc995fe16f91e2e9c734dacc65ca0b7b622d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62182373"
---
# <a name="compiler-warning-level-1-c4405"></a>Compilador aviso (nível 1) C4405

'identifier': identificador é palavra reservada

Uma palavra reservada para assembly embutido é usada como um nome de variável. Isso pode causar resultados imprevisíveis. Para corrigir este aviso, evite a nomenclatura de variáveis com palavras reservadas para assembly embutido. O exemplo a seguir gera C4405:

```
// C4405.cpp
// compile with: /W1
// processor: x86
void func1() {
   int mov = 0, i = 0;
   _asm {
      mov mov, 0;   // C4405
      // instead, try ..
      // mov i, 0;
   }
}

int main() {
}
```