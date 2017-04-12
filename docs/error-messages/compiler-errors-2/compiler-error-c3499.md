---
title: C3499 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3499
dev_langs:
- C++
helpviewer_keywords:
- C3499
ms.assetid: 6717de5c-ae0f-4024-bdf2-b5598009e7b6
caps.latest.revision: 8
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
ms.openlocfilehash: 51213128e2f0492f4b296c1abbfac0cdab214174
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3499"></a>C3499 de erro do compilador
um lambda cujo tipo de retorno foi especificado como void não pode retornar um valor  
  
 O compilador gera este erro quando uma expressão lambda que especifique `void` como o tipo de retorno retorna um valor; ou quando uma expressão lambda contiver mais de uma instrução e retorna um valor, mas não especifica seu tipo de retorno.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Retorna um valor da expressão lambda, ou  
  
-   Forneça o tipo de retorno da expressão lambda, ou  
  
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
 O exemplo a seguir mostra duas possíveis resoluções para C3499. A resolução primeiro fornece o tipo de retorno da expressão lambda. A segunda resolução combina as instruções que constituem o corpo da expressão lambda em uma única instrução.  
  
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
