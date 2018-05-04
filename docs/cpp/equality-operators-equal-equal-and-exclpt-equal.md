---
title: 'Operadores de igualdade: = = e! = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- not_eq
- '!='
- ==
dev_langs:
- C++
helpviewer_keywords:
- '!= operator'
- equality operator
- not equal to comparison operator
- equality operator [C++], syntax
- == operator
- not_eq operator
- equal to operator
ms.assetid: ba4e9659-2392-4fb4-be5a-910a2a6df45a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 16e4a85f31777581df1a138de6d50b1057253e5b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="equality-operators--and-"></a>Operadores de igualdade: == e !=
## <a name="syntax"></a>Sintaxe  
  
```  
expression == expression  
expression != expression  
```  
  
## <a name="remarks"></a>Comentários  
 Operadores de igualdade binários comparam seus operandos em buscar de igualdades ou desigualdades estritas.  
  
 Os operadores de igualdade, igual a (`==`) e diferente de (`!=`), têm precedência mais baixa do que os operadores relacionais, mas se comportam de maneira semelhante. O tipo do resultado desses operadores é `bool`.  
  
 O operador igual a (`==`) retorna **true** (1) se ambos os operandos têm o mesmo valor; caso contrário, retornará **false** (0). O operador não-igual a (`!=`) retorna **true** se os operandos não têm o mesmo valor; caso contrário, retornará **false**.  
  
## <a name="operator-keyword-for-"></a>Palavra-chave do operador para !=  
 O operador `not_eq` é o equivalente de texto de `!=`. Há duas maneiras para acessar o `not_eq` operador em seus programas: incluem o arquivo de cabeçalho `iso646.h`, ou de compilação com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção de compilador (desabilitar extensões de linguagem).  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_Equality_Operators.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
  
int main() {  
   cout  << boolalpha  
         << "The true expression 3 != 2 yields: "  
         << (3 != 2) << endl  
         << "The false expression 20 == 10 yields: "  
         << (20 == 10) << endl;  
}  
```  
  
 Os operadores de igualdade podem comparar ponteiros a membros do mesmo tipo. Em comparação, as conversões de ponteiro para membro são executadas. Os ponteiros para membros também podem ser comparados a uma expressão constante que é avaliada como 0.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores relacionais e de igualdade C](../c-language/c-relational-and-equality-operators.md)