---
title: "Siga-enquanto a instrução (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
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
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 8c81bbeea9f841a834d59186017b2932f83de862
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="do-while-statement-c"></a>Instrução do-while (C++)
Executa um *instrução* repetidamente até que a condição de término especificada (o *expressão*) for avaliada como zero.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
do  
   statement  
while ( expression ) ;  
```  
  
## <a name="remarks"></a>Comentários  
 O teste da condição de término é realizado após cada execução do loop; portanto, um loop `do-while` é executado uma ou mais vezes, dependendo do valor da expressão de término. O `do-while` instrução também pode encerrar quando um [quebra](../cpp/break-statement-cpp.md), [goto](../cpp/goto-statement-cpp.md), ou [retornar](../cpp/return-statement-cpp.md) instrução é executada dentro do corpo de instrução.  
  
 A *expressão* deve ter o tipo aritmético ou ponteiro. A execução procede da seguinte maneira:  
  
1.  O corpo da instrução é executado.  
  
2.  Em seguida, a *expressão* é avaliada. Se a *expressão* for falsa, a instrução `do-while` será finalizada e o controle será passado para a próxima instrução no programa. Se a *expressão* for verdadeira (diferente de zero), o processo será repetido, começando da etapa 1.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra a instrução `do-while`:  
  
```  
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
