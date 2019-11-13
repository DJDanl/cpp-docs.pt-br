---
title: Aviso do compilador (nível 1) C4405
ms.date: 11/04/2016
f1_keywords:
- C4405
helpviewer_keywords:
- C4405
ms.assetid: 155c64d6-58ae-4455-b61f-ccd711c5da96
ms.openlocfilehash: 182f9ff061fd2a8ebe5ea0046545412fca5f646a
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73965583"
---
# <a name="compiler-warning-level-1-c4405"></a>Aviso do compilador (nível 1) C4405

' identifier ': o identificador é uma palavra reservada

Uma palavra reservada para assembly embutido é usada como um nome de variável. Isso pode causar resultados imprevisíveis. Para corrigir esse aviso, evite nomear variáveis com palavras reservadas para o assembly embutido. O exemplo a seguir gera C4405:

```cpp
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