---
title: C3484 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3484
dev_langs:
- C++
helpviewer_keywords:
- C3484
ms.assetid: 2fe847fa-f6ee-4978-bc1d-b6dc6ae906ac
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5de302987e4ea56e9ee6f29bed1b5842579a8f5b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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
 O exemplo a seguir elimina C3484 fornecendo `->` antes do tipo de retorno da expressão lambda:  
  
```  
// C3484b.cpp  
  
int main()  
{  
   return []() -> int { return 42; }();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)