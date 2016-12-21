---
title: "Chamando fun&#231;&#245;es C em assembly embutido | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __asm [C++], chamando funções"
  - "chamadas de função, funções C"
  - "chamadas de função, em assembly embutido"
  - "funções [C], chamando em assembly embutido"
  - "assembly embutido, chamando funções"
  - "Visual C, Funções "
ms.assetid: f8a8d568-d175-4e23-9b24-36ef60a4cab3
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Chamando fun&#231;&#245;es C em assembly embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Um bloco de `__asm` pode chamar funções C, incluindo rotinas de biblioteca C.  O exemplo a seguir chama a rotina de biblioteca de `printf` :  
  
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
  
 Como os argumentos de função são passados na pilha, você simplesmente empurra os argumentos necessários — cadeia ponteiros, no exemplo anterior — antes de chamar a função.  Os argumentos forem enviados por push a ordem inversa, o que vêm da pilha na ordem desejada.  Para emular a instrução C  
  
```  
printf( format, hello, world );  
```  
  
 o exemplo empurra ponteiros para `world`, `hello`, e `format`, nessa ordem, e chame `printf`.  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)