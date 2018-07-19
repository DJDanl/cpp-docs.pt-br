---
title: -while instrução (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- do_cpp
dev_langs:
- C++
helpviewer_keywords:
- do keyword [C++], do-while
- do-while keyword [C++]
- do keyword [C++]
- while keyword [C++], do-while
ms.assetid: e01e6f7c-7da1-4591-87f9-c26ff848e7b0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d2de180d58c31f4bd6c8b15eb69076b99f8b57b0
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942275"
---
# <a name="do-while-statement-c"></a>Instrução do-while (C++)
Executa um *instrução* repetidamente até que a condição de término especificada (o *expressão*) é avaliada como zero.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
do  
   statement  
while ( expression ) ;  
```  
  
## <a name="remarks"></a>Comentários  
 O teste da condição de término é realizado após cada execução do loop; Portanto, uma **fazer-enquanto** loop é executado uma ou mais vezes, dependendo do valor da expressão de término. O **fazer-Embora** instrução também pode terminar quando um [quebra](../cpp/break-statement-cpp.md), [goto](../cpp/goto-statement-cpp.md), ou [retornar](../cpp/return-statement-cpp.md) instrução é executada dentro do corpo da instrução.  
  
 A *expressão* deve ter o tipo aritmético ou ponteiro. A execução procede da seguinte maneira:  
  
1.  O corpo da instrução é executado.  
  
2.  Em seguida, a *expressão* é avaliada. Se *expressão* é false, o **fazer-enquanto** instrução finaliza e o controle passará para a próxima instrução no programa. Se a *expressão* for verdadeira (diferente de zero), o processo será repetido, começando da etapa 1.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra a **fazer-enquanto** instrução:  
  
```cpp 
// do_while_statement.cpp  
#include <stdio.h>  
int main()  
{  
    int i = 0;  
    do  
    {  
        printf_s("\n%d",i++);  
    } while (i < 3);  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Instruções de Iteração](../cpp/iteration-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Instrução while (C++)](../cpp/while-statement-cpp.md)   
 [Instrução for (C++)](../cpp/for-statement-cpp.md)   
 [Instrução for baseada intervalo (C++)](../cpp/range-based-for-statement-cpp.md)