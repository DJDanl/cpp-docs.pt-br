---
title: "Compilador aviso (nível 1) C4733 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4733
dev_langs:
- C++
helpviewer_keywords:
- C4733
ms.assetid: 7ef4f577-772d-4b66-a7bf-8958a6b250bc
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 9bc1fffa7140686dd987b7e96556cc75c3e7a49c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4733"></a>Compilador C4733 de aviso (nível 1)
asm embutido atribuindo para 'FS:0' : manipulador não registrado como manipulador seguro  
  
 Uma função modificando o valor em FS:0 para adicionar um novo manipulador de exceção pode não funcionar com as exceções de segurança, porque o manipulador não pode ser registrado como um manipulador de exceção válido (consulte [/SAFESEH](../../build/reference/safeseh-image-has-safe-exception-handlers.md)).  
  
 Para resolver esse aviso, ou remova a definição de FS:0 ou desativar esse aviso e usar [. /SafeSEH](../../assembler/masm/dot-safeseh.md) para especificar os manipuladores de exceção segura.  
  
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
