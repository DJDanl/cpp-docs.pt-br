---
title: "Operador de vírgula:, | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- '%2C'
- ','
dev_langs:
- C++
helpviewer_keywords:
- comma operator
ms.assetid: 38e0238e-19da-42ba-ae62-277bfdab6090
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
ms.openlocfilehash: e5e7af401a0c435931f6952674d97752d2ac7730
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comma-operator-"></a>Operador de vírgula: ,
Permite agrupar duas instruções onde uma é esperado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
expression , expression  
```  
  
## <a name="remarks"></a>Comentários  
 O operador vírgula tem associatividade da esquerda para a direita. Duas expressões separadas por uma vírgula são avaliadas da esquerda para a direita. O operando à esquerda é sempre avaliado, e todos os efeitos colaterais são concluídos antes de o operando à direita ser avaliado.  
  
 As vírgulas podem ser usadas como separadores em alguns contextos, como listas de argumentos de função. Não confunda o uso da vírgula como separador com seu uso como operador; os dois usos são completamente diferentes.  
  
 Considere a expressão  
  
 *E1* , *e2*  
  
 O tipo e o valor da expressão são o tipo e o valor de *e2*; o resultado da avaliação *e1* é descartado. O resultado será um valor l se o operando à direita for um valor l.  
  
 Onde a vírgula é geralmente usada como separador (por exemplo, nos argumentos reais para funções ou inicializadores agregados), o operador vírgula e seus operandos devem ser colocados entre parênteses. Por exemplo:  
  
```  
func_one( x, y + 2, z );  
func_two( (x--, y + 2), z );  
```  
  
 Na chamada de função para `func_one` acima, três argumentos, separados por vírgulas, são passados: `x`, `y + 2` e `z`. Na chamada da função para `func_two`, os parênteses forçam o compilador a interpretar a primeira vírgula como o operador de avaliação sequencial. Essa chamada de função passa dois argumentos para `func_two`. O primeiro argumento é o resultado da operação de avaliação sequencial `(x--, y + 2)`, que tem o valor e o tipo da expressão `y + 2`; o segundo argumento é `z`.  
  
## <a name="example"></a>Exemplo  
  
```  
// cpp_comma_operator.cpp  
#include <stdio.h>  
int main () {  
   int i = 10, b = 20, c= 30;  
   i = b, c;  
   printf("%i\n", i);  
  
   i = (b, c);  
   printf("%i\n", i);  
}  
```  
  
```Output  
20  
30  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operador de avaliação sequencial](../c-language/sequential-evaluation-operator.md)
