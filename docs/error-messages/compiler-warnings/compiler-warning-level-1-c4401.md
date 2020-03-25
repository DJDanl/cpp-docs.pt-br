---
title: Aviso do compilador (nível 1) C4401
ms.date: 11/04/2016
f1_keywords:
- C4401
helpviewer_keywords:
- C4401
ms.assetid: 2e7ca136-f144-4b40-b847-82976e8643fc
ms.openlocfilehash: fe08509a05eed00f7e7d492e723e873d05e451ad
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80162654"
---
# <a name="compiler-warning-level-1-c4401"></a>Aviso do compilador (nível 1) C4401

' área de bits ': membro é campo de bit

O código de assembly embutido tenta acessar um membro de campo de bits. O assembly embutido não pode acessar membros de campo de bits, portanto, o último limite de remessa antes do membro de campo de bits é usado.

Para evitar esse aviso, converta o campo de bits para um tipo apropriado antes de fazer a referência no código de assembly embutido. O exemplo a seguir gera C4401:

```cpp
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
