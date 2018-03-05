---
title: "Operador de negação lógica: ! | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- '!'
- Not
dev_langs:
- C++
helpviewer_keywords:
- '! operator'
- NOT operator
- logical negation
ms.assetid: 650add9f-a7bc-426c-b01d-5fc6a81c8b62
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f63d36fc5974241fb624dd3a2afc863142516e9b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="logical-negation-operator-"></a>Operador de negação lógica: !
## <a name="syntax"></a>Sintaxe  
  
```  
  
! cast-expression  
```  
  
## <a name="remarks"></a>Comentários  
 O operador de negação lógica (**!**) reverte o significado de seu operando. O operando deve ser do tipo aritmético ou ponteiro (ou uma expressão que é avaliada para o tipo aritmético ou ponteiro). O operando é convertido implicitamente no tipo `bool`. O resultado é **true** se o operando convertido **false**; o resultado é **false** se o operando convertido **true**. O resultado é do tipo `bool`.  
  
 Para uma expressão *e*, a expressão unária **!** *e* é equivalente à expressão **(***e* `==` 0), exceto onde os operadores sobrecarregados são envolvidos.  
  
## <a name="operator-keyword-for-"></a>Palavra-chave de operador para !  
 O **não** operador é equivalente a texto **!**. Há duas maneiras para acessar o **não** operador em seus programas: incluem o arquivo de cabeçalho `iso646.h`, ou de compilação com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção de compilador (desabilitar extensões de linguagem).  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_Logical_NOT_Operator.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main() {  
   int i = 0;  
   if (!i)  
      cout << "i is zero" << endl;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores aritméticos unários](../c-language/unary-arithmetic-operators.md)