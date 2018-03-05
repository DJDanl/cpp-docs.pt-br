---
title: Restrict | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __restrict_cpp
dev_langs:
- C++
helpviewer_keywords:
- __restrict keyword [C++]
ms.assetid: 2d151b4d-f930-49df-bd16-d8757ec7fa83
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f2c21872c5d6fe6000038a3a2f4fe39451b566dd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="restrict"></a>__restrict
Como o **declspec ( [restringir](../cpp/restrict.md) )** modificador, do `__restrict` palavra-chave indica que um símbolo não é um alias no escopo atual. A palavra-chave `__restrict` difere do modificador `__declspec ( restrict )` das seguintes maneiras:  
  
-   A palavra-chave `__restrict` só é válida em variáveis, e `__declspec ( restrict )` só é válido em declarações e definições de função.  
  
-   `__restrict` é semelhante a `restrict` das especificações C99, mas `__restrict` pode ser usado em programas C ou C++.  
  
-   Quando `__restrict` é usado, o compilador não propaga a propriedade no-alias de uma variável. Ou seja, se você atribuir um `__restrict` variável ao não`__restrict` variável, o compilador ainda permitirá que o não- Restrict variável para receber um alias. Isso é diferente do comportamento da palavra-chave `restrict` da especificação C99.  
  
 Em geral, se você afeta o comportamento de uma função inteira, é melhor usar `__declspec ( restrict )` que a palavra-chave.  
  
 No Visual Studio 2015 e posteriores, `__restrict` pode ser usado em referências do C++.  
  
> [!NOTE]
>  Quando usado em uma variável que também tenha o [volátil](../cpp/volatile-cpp.md) palavra-chave, `volatile` terá precedência.  
  
## <a name="example"></a>Exemplo  
  
```  
// __restrict_keyword.c  
// compile with: /LD  
// In the following function, declare a and b as disjoint arrays  
// but do not have same assurance for c and d.  
void sum2(int n, int * __restrict a, int * __restrict b,   
          int * c, int * d) {  
   int i;  
   for (i = 0; i < n; i++) {  
      a[i] = b[i] + c[i];  
      c[i] = b[i] + d[i];  
    }  
}  
  
// By marking union members as __restrict, tell compiler that  
// only z.x or z.y will be accessed in any given scope.  
union z {  
   int * __restrict x;  
   double * __restrict y;  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)