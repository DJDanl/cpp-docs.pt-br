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
ms.openlocfilehash: 94bbfda3a5fd15885f3d8276d506541418a9489f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169585"
---
# <a name="calling-c-functions-in-inline-assembly"></a>Chamando funções C no assembly embutido

**Seção específica da Microsoft**

Um bloco de `__asm` pode chamar funções C, incluindo rotinas de biblioteca C. O exemplo a seguir chama a rotina de biblioteca de `printf`:

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

o exemplo envia ponteiros para `world`, `hello`e `format`, nessa ordem, e, em seguida, chama `printf`.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
