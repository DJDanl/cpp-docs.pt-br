---
title: C3484 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3484
dev_langs:
- C++
helpviewer_keywords:
- C3484
ms.assetid: 2fe847fa-f6ee-4978-bc1d-b6dc6ae906ac
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 007dfdb97702a94f31075126b15f9765c3c5cdce
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3484"></a>C3484 de erro do compilador
esperado '->' antes do tipo de retorno  
  
 Você deve fornecer `->` antes do tipo de retorno de uma expressão lambda.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Fornecer `->` antes do tipo de retorno.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3484:  
  
```  
// C3484a.cpp  
  
int main()  
{  
   return []() . int { return 42; }(); // C3484  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir resolve C3484 fornecendo `->` antes do tipo de retorno da expressão lambda:  
  
```  
// C3484b.cpp  
  
int main()  
{  
   return []() -> int { return 42; }();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
