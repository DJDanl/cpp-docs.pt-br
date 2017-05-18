---
title: "Compilador aviso (nível 1) C4715 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4715
dev_langs:
- C++
helpviewer_keywords:
- C4715
ms.assetid: 1c819bf7-0d8b-4f5e-b338-9cc292870439
caps.latest.revision: 7
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a992e4e5afe21dcbc42e25e97a0a676b40c8889a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4715"></a>Compilador C4715 de aviso (nível 1)
'function': nem todos os caminhos de controle retornam um valor  
  
 A função especificada não pode retornar um valor.  
  
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
  
 Para evitar esse aviso, modifique o código para que todos os caminhos de atribuir um valor de retorno para a função:  
  
```  
// C4715b.cpp  
// compile with: /LD  
int func1( int i )  
{  
   if( i ) return 3;  
   else return 0;     // OK, always returns a value  
}  
```  
  
 É possível que seu código pode conter uma chamada para uma função que nunca retorne, como no exemplo a seguir:  
  
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
  
 Esse código também gera um aviso, porque o compilador não sabe que `fatal` nunca retorna. Para impedir que esse código gera uma mensagem de erro, declarar `fatal` usando [__declspec(noreturn)](../../cpp/noreturn.md).
