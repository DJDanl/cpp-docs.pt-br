---
title: Erro do compilador C2422
ms.date: 11/04/2016
f1_keywords:
- C2422
helpviewer_keywords:
- C2422
ms.assetid: ef0ec302-4028-4778-b134-0b8cea4bcad9
ms.openlocfilehash: 524eeadb6cf066d3eba3a7e88c45a9e2b993c0ae
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402862"
---
# <a name="compiler-error-c2422"></a>Erro do compilador C2422

substituição de segmento inválido em 'operando'

Código de assembly embutido incorretamente usa um operador de substituição de segmento (dois-pontos) em um operando.  Possíveis causas incluem:

- O registro anterior o operador não é um registro de segmento.

- O registro anterior o operador não é o registro de segmento único no operando.

- O operador de substituição de segmento aparece dentro de um operador de indireção (colchetes).

- A expressão que segue o operador de substituição de segmento não é um operando imediato ou um operando de memória.

O exemplo a seguir gera C2422:

```
// C2422.cpp
// processor: x86
int main() {
   _asm {
      mov AX, [BX:ES]   // C2422
      mov AX, ES   // OK
   }
}
```