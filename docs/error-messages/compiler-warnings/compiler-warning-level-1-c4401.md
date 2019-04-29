---
title: Compilador aviso (nível 1) C4401
ms.date: 11/04/2016
f1_keywords:
- C4401
helpviewer_keywords:
- C4401
ms.assetid: 2e7ca136-f144-4b40-b847-82976e8643fc
ms.openlocfilehash: c7e6cf8a52288d895b74481678dc91fee387a6a3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62280419"
---
# <a name="compiler-warning-level-1-c4401"></a>Compilador aviso (nível 1) C4401

'campo de bits': membro é campo de bits

Código de assembly embutido tenta acessar um membro de campo de bits. Assembly embutido não pode acessar membros de campo de bits, portanto, o limite de remessa último antes do membro de campo de bits é usado.

Para evitar esse aviso, converta o campo de bits para um tipo apropriado antes de fazer a referência de código de assembly embutido. O exemplo a seguir gera C4401:

```
// C4401.cpp
// compile with: /W1
// processor: x86
typedef struct bitfield {
   signed bit : 1;
} mybitfield;

int main() {
   mybitfield bf;
   bf.bit = 0;
   __asm {
      mov bf.bit,0;   // C4401
   }

   /* use the following __asm block to resolve the warning
   int i = (int)bf.bit;
   __asm {
      mov i,0;
   }
   */
}
```