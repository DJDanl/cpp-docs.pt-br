---
title: C3499 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3499
dev_langs:
- C++
helpviewer_keywords:
- C3499
ms.assetid: 6717de5c-ae0f-4024-bdf2-b5598009e7b6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: de299c5da66790276433da22227a3aa97cb55c82
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33257452"
---
# <a name="compiler-error-c3499"></a>C3499 de erro do compilador
uma expressão lambda que foi especificada para ter um tipo de retorno void não pode retornar um valor  
  
 O compilador gera este erro quando uma expressão lambda que especifica `void` como o tipo de retorno retorna um valor; ou quando uma expressão lambda contém mais de uma instrução e retorna um valor, mas não especificar seu tipo de retorno.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Retorna um valor da expressão lambda ou  
  
-   Fornece o tipo de retorno da expressão lambda, ou  
  
-   Combine as instruções que constituem o corpo da expressão lambda em uma única instrução.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3499 porque o corpo de uma expressão lambda contém várias instruções e retorna um valor, mas a expressão lambda não especifica o tipo de retorno:  
  
```  
// C3499a.cpp  
  
int main()  
{  
   [](int x) { int n = x * 2; return n; } (5); // C3499  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra duas possíveis resoluções para C3499. A primeira resolução fornece o tipo de retorno da expressão lambda. A segunda resolução combina as instruções que constituem o corpo da expressão lambda em uma única instrução.  
  
```  
// C3499b.cpp  
  
int main()  
{  
   // Possible resolution 1:   
   // Provide the return type of the lambda expression.  
   [](int x) -> int { int n = x * 2; return n; } (5);  
  
   // Possible resolution 2:   
   // Combine the statements that make up the body of   
   // the lambda expression into a single statement.  
   [](int x) { return x * 2; } (5);  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)