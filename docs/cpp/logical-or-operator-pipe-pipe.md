---
title: 'Lógica ou operador: | | | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- '||'
dev_langs:
- C++
helpviewer_keywords:
- OR operator [C++], logical
- '|| operator'
- OR operator
- logical OR operator
ms.assetid: 31837c99-2655-4bf3-8ded-f13b7a9dc533
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bd0642e9759eaa4d39eac680ba165af7dbbb0d44
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="logical-or-operator-"></a>Operador OR lógico: ||
## <a name="syntax"></a>Sintaxe  
  
```  
  
logical-or-expression   
||  
 logical-and-expression  
  
```  
  
## <a name="remarks"></a>Comentários  
 O operador lógico OR (`||`) retorna um valor booliano **true** se um ou ambos os operandos é **true** e retorna **false** caso contrário. Os operandos são convertidos implicitamente no tipo `bool` antes da avaliação, e o resultado é do tipo `bool`. O OR lógico tem associatividade da esquerda para a direita.  
  
 Os operandos para o operador OR lógico não precisam ser do mesmo tipo, mas devem ser de tipo integral ou ponteiro. Os operandos são geralmente expressões relacionais ou de igualdade.  
  
 O primeiro operando é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar a avaliação da expressão OR lógica.  
  
 O segundo operando é avaliado somente se o primeiro operando for avaliado como false (0). Isso elimina a avaliação desnecessária do segundo operando quando a expressão OR lógica for true.  
  
```  
printf( "%d" , (x == w || x == y || x == z) );  
```  
  
 No exemplo acima, se `x` for igual a `w`, `y` ou `z`, o segundo argumento para a função `printf` será avaliado como true e o valor 1 será impresso. Caso contrário, será avaliado como false, e o valor 0 será impresso. Assim que uma das condições for avaliada como true, a avaliação é encerrada.  
  
## <a name="operator-keyword-for-124124"></a>Palavra-chave de operador para&#124;&#124;  
 O **ou** operador é equivalente a texto `||`. Há duas maneiras para acessar o **ou** operador em seus programas: incluem o arquivo de cabeçalho `iso646.h`, ou de compilação com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção de compilador (desabilitar extensões de linguagem).  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_Logical_OR_Operator.cpp  
// compile with: /EHsc  
// Demonstrate logical OR  
#include <iostream>  
using namespace std;  
int main() {  
   int a = 5, b = 10, c = 15;  
   cout  << boolalpha  
         << "The true expression "  
         << "a < b || b > c yields "  
         << (a < b || b > c) << endl  
         << "The false expression "  
         << "a > b || b > c yields "  
         << (a > b || b > c) << endl;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
[Operadores C++ internos Precedence and Associativity](cpp-built-in-operators-precedence-and-associativity.md) [operadores C++ internos, precedência e associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores lógicos C](../c-language/c-logical-operators.md)