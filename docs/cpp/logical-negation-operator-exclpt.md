---
title: 'Operador de negação lógica: ! | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4f911c6f01dfc188c26355a3749d8a130f0d6951
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39403583"
---
# <a name="logical-negation-operator-"></a>Operador de negação lógica: !
## <a name="syntax"></a>Sintaxe  
  
```  
! cast-expression  
```  
  
## <a name="remarks"></a>Comentários  
 O operador de negação lógica (**!**) inverte o significado do respectivo operando. O operando deve ser do tipo aritmético ou ponteiro (ou uma expressão que é avaliada para o tipo aritmético ou ponteiro). O operando é convertido implicitamente no tipo **bool**. O resultado será TRUE se o operando convertido for FALSE; o resultado será FALSE se o operando convertido for TRUE. O resultado é do tipo **bool**.  
  
 Para uma expressão *eletrônico*, a expressão unária **! * * * e* é equivalente à expressão **(* * * eletrônico* `==` 0), exceto onde operadores sobrecarregados estão envolvidos.  
  
## <a name="operator-keyword-for-"></a>Palavra-chave de operador para !  
 O **não** operador é o equivalente de texto de **!**. Há duas maneiras para acessar o **não** operador em seus programas: incluir o arquivo de cabeçalho `iso646.h`, ou compilando com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção do compilador (desabilitar extensões de linguagem).  
  
## <a name="example"></a>Exemplo  
  
```cpp 
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
 [Operadores C++ internos, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores aritméticos unários](../c-language/unary-arithmetic-operators.md)