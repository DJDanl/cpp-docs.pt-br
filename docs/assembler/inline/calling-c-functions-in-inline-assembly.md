---
title: Chamando funções C no assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- function calls, C functions
- function calls, in inline assembly
- functions [C], calling in inline assembly
- Visual C, functions
- inline assembly, calling functions
- __asm keyword [C++], calling functions
ms.assetid: f8a8d568-d175-4e23-9b24-36ef60a4cab3
ms.openlocfilehash: 4d12321cd90f596c94c2337e100663436d512107
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62167174"
---
# <a name="calling-c-functions-in-inline-assembly"></a>Chamando funções C no assembly embutido

**Seção específica da Microsoft**

Um `__asm` bloco pode chamar funções de C, incluindo as rotinas da biblioteca C. A exemplo a seguir chama o `printf` rotina da biblioteca:

```cpp
// InlineAssembler_Calling_C_Functions_in_Inline_Assembly.cpp
// processor: x86
#include <stdio.h>

char format[] = "%s %s\n";
char hello[] = "Hello";
char world[] = "world";
int main( void )
{
   __asm
   {
      mov  eax, offset world
      push eax
      mov  eax, offset hello
      push eax
      mov  eax, offset format
      push eax
      call printf
      //clean up the stack so that main can exit cleanly
      //use the unused register ebx to do the cleanup
      pop  ebx
      pop  ebx
      pop  ebx
   }
}
```

Como argumentos de função são passados na pilha, você simplesmente enviar por push os argumentos necessários — ponteiros, no exemplo anterior da cadeia de caracteres — antes de chamar a função. Os argumentos são empurrados na ordem inversa, para que eles vêm da pilha na ordem desejada. Para emular a instrução de C

```cpp
printf( format, hello, world );
```

o exemplo envia por push ponteiros para `world`, `hello`, e `format`, nessa ordem e, em seguida, chama `printf`.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>