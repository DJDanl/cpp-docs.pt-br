---
title: Funções de chamada C em Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- function calls, C functions
- function calls, in inline assembly
- functions [C], calling in inline assembly
- Visual C, functions
- inline assembly, calling functions
- __asm keyword [C++], calling functions
ms.assetid: f8a8d568-d175-4e23-9b24-36ef60a4cab3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c3f6d03ba77c7a4cdb3478a1bfe8729019dea002
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32049512"
---
# <a name="calling-c-functions-in-inline-assembly"></a>Chamando funções C no assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Um `__asm` bloco pode chamar funções de C, incluindo as rotinas de biblioteca C. A exemplo a seguir chama o `printf` rotina de biblioteca:  
  
```  
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
  
 Como argumentos de função são passados na pilha, você simplesmente enviar por push os argumentos necessários — ponteiros, no exemplo anterior de cadeia de caracteres — antes de chamar a função. Os argumentos são enviados na ordem inversa, para que eles vêm da pilha na ordem desejada. Para emular a instrução de C  
  
```  
printf( format, hello, world );  
```  
  
 o exemplo envia ponteiros para `world`, `hello`, e `format`, na ordem e, em seguida, chama `printf`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)