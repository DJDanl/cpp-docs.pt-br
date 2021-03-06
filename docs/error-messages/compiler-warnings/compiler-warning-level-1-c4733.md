---
title: Aviso do compilador (nível 1) C4733
ms.date: 11/04/2016
f1_keywords:
- C4733
helpviewer_keywords:
- C4733
ms.assetid: 7ef4f577-772d-4b66-a7bf-8958a6b250bc
ms.openlocfilehash: 39674c32deb506725aa5f7c1f5f875e771519938
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185666"
---
# <a name="compiler-warning-level-1-c4733"></a>Aviso do compilador (nível 1) C4733

Asm embutido atribuindo a ' FS: 0 ': manipulador não registrado como manipulador seguro

Uma função que modifica o valor em FS: 0 a adição de um novo manipulador de exceção pode não funcionar com exceções seguras, pois o manipulador pode não ser registrado como um manipulador de exceção válido (consulte [/SAFESEH](../../build/reference/safeseh-image-has-safe-exception-handlers.md)).

Para resolver esse aviso, remova o FS: 0 definição ou desative este aviso e use [. SAFESEH](../../assembler/masm/dot-safeseh.md) para especificar os manipuladores de exceção segura.

O exemplo a seguir gera C4733:

```cpp
// C4733.cpp
// compile with: /W1 /c
// processor: x86
#include "stdlib.h"
#include "stdio.h"
void my_handler()
{
   printf("Hello from my_handler\n");
   exit(1);
}

int main()
{
   _asm {
      push    my_handler
      mov     eax, DWORD PTR fs:0
      push    eax
      mov     DWORD PTR fs:0, esp   // C4733
   }

   *(int*)0 = 0;
}
```
