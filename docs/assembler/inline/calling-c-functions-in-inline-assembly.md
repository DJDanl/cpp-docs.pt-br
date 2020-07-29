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
ms.openlocfilehash: 73be1142747dc608d683e6bd847639b9df718a13
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87192620"
---
# <a name="calling-c-functions-in-inline-assembly"></a>Chamando funções C no assembly embutido

**Específico da Microsoft**

Um **`__asm`** bloco pode chamar as funções c, incluindo as rotinas da biblioteca c. O exemplo a seguir chama a `printf` rotina de biblioteca:

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

Como os argumentos de função são passados na pilha, você simplesmente envia os argumentos necessários – ponteiros de cadeia de caracteres, no exemplo anterior, antes de chamar a função. Os argumentos são enviados por push na ordem inversa, portanto, eles aparecem na pilha na ordem desejada. Para emular a instrução C

```cpp
printf( format, hello, world );
```

o exemplo envia ponteiros para `world` , `hello` e `format` , nessa ordem e, em seguida, chama `printf` .

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
