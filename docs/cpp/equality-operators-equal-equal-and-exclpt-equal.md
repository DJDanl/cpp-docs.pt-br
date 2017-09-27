---
title: 'Operadores de igualdade: = = e! = | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
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
- equality operator, syntax
- == operator
- not_eq operator
- equal to operator
ms.assetid: ba4e9659-2392-4fb4-be5a-910a2a6df45a
caps.latest.revision: 7
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
ms.openlocfilehash: 5412869204f088e321d2a41da407026f9447eb82
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
