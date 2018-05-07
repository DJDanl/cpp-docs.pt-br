---
title: Compilador (nível 1) de aviso C4715 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4715
dev_langs:
- C++
helpviewer_keywords:
- C4715
ms.assetid: 1c819bf7-0d8b-4f5e-b338-9cc292870439
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 57bd7f86a06c060a469d31e5fbdfcfbd7afb8c80
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4715"></a>Compilador C4715 de aviso (nível 1)
'function': nem todos os caminhos de controle retornam um valor  
  
 A função especificada potencialmente não pode retornar um valor.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4715a.cpp  
// compile with: /W1 /LD  
int func1( int i )  
{  
   if( i )  
   return 3;  // C4715 warning, nothing returned if i == 0  
}  
```  
  
 Para evitar este aviso, modifique o código para que todos os caminhos de atribuir um valor de retorno da função:  
  
```  
// C4715b.cpp  
// compile with: /LD  
int func1( int i )  
{  
   if( i ) return 3;  
   else return 0;     // OK, always returns a value  
}  
```  
  
 É possível que seu código pode conter uma chamada para uma função que nunca retorna, como no exemplo a seguir:  
  
```  
// C4715c.cpp  
// compile with: /W1 /LD  
void fatal()  
{  
}  
int glue()  
{  
   if(0)  
      return 1;  
   else if(0)  
      return 0;  
   else  
      fatal();   // C4715  
}  
```  
  
 Esse código também gera um aviso, porque o compilador não sabe que `fatal` nunca retorna. Para impedir que esse código gera uma mensagem de erro, declare `fatal` usando [__declspec(noreturn)](../../cpp/noreturn.md).