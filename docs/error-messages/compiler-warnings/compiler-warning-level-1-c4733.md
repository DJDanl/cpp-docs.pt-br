---
title: Compilador aviso (nível 1) C4733
ms.date: 11/04/2016
f1_keywords:
- C4733
helpviewer_keywords:
- C4733
ms.assetid: 7ef4f577-772d-4b66-a7bf-8958a6b250bc
ms.openlocfilehash: 0d0b0b912ef15294f9a4362a79dffd6d7eeabed8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62221109"
---
# <a name="compiler-warning-level-1-c4733"></a>Compilador aviso (nível 1) C4733

Asm embutido atribuindo para 'FS:0': manipulador não registrado como manipulador seguro

Uma função modificando o valor no FS:0 para adicionar um novo manipulador de exceção pode não funcionar com exceções de segurança, porque o manipulador não pode ser registrado como um manipulador de exceção válido (consulte [/SAFESEH](../../build/reference/safeseh-image-has-safe-exception-handlers.md)).

Para resolver este aviso, ou remova a definição de FS:0 ou desativar esse aviso e usar [. SAFESEH](../../assembler/masm/dot-safeseh.md) para especificar os manipuladores de exceção segura.

O exemplo a seguir gera C4733:

```
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