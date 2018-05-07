---
title: Compilador (nível 1) de aviso C4733 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4733
dev_langs:
- C++
helpviewer_keywords:
- C4733
ms.assetid: 7ef4f577-772d-4b66-a7bf-8958a6b250bc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 59d702867fb4950b97ee2d2c6249c26229aac975
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4733"></a>Compilador C4733 de aviso (nível 1)
Asm embutido atribuindo para 'FS:0': manipulador não registrado como manipulador seguro  
  
 Uma função de modificação do valor em FS:0 para adicionar um novo manipulador de exceção pode não funcionar com exceções de segurança, porque o manipulador não pode ser registrado como um manipulador de exceção válido (consulte [/SAFESEH](../../build/reference/safeseh-image-has-safe-exception-handlers.md)).  
  
 Para resolver este aviso, ou remova a definição de FS:0 ou desativar esse aviso e usar [. SAFESEH](../../assembler/masm/dot-safeseh.md) para especificar os manipuladores de exceção de segurança.  
  
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