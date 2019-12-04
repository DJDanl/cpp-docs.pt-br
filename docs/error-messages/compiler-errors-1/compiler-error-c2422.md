---
title: Erro do compilador C2422
ms.date: 11/04/2016
f1_keywords:
- C2422
helpviewer_keywords:
- C2422
ms.assetid: ef0ec302-4028-4778-b134-0b8cea4bcad9
ms.openlocfilehash: 39f779ee846cf4f328f9c7af59ae394d97d7a3ca
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74744726"
---
# <a name="compiler-error-c2422"></a>Erro do compilador C2422

substituição de segmento ilegal em ' operando '

O código de assembly embutido usa incorretamente um operador de substituição de segmento (dois-pontos) em um operando.  As possíveis causas incluem:

- O registro anterior ao operador não é um registro de segmento.

- O registro que antecede o operador não é o único registro de segmento no operando.

- O operador de substituição de segmento aparece dentro de um operador de indireção (colchetes).

- A expressão após o operador de substituição de segmento não é um operando imediato ou um operando de memória.

O exemplo a seguir gera C2422:

```cpp
// C2422.cpp
// processor: x86
int main() {
   _asm {
      mov AX, [BX:ES]   // C2422
      mov AX, ES   // OK
   }
}
```
