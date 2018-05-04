---
title: 'Operador AND lógico: &amp; &amp; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- '&&'
dev_langs:
- C++
helpviewer_keywords:
- logical AND operator
- AND operator
- '&& operator'
ms.assetid: 50cfa664-a8c4-4b31-9bab-2f80d7cd2d1f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f683b7ff17a1dd3945f5cb554a7440ab47fad454
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="logical-and-operator-ampamp"></a>Operador AND lógico: &amp;&amp;
## <a name="syntax"></a>Sintaxe  
  
```  
  
expression   
&&  
 expression  
  
```  
  
## <a name="remarks"></a>Comentários  
 O operador AND lógico (**&&**) retorna um valor booliano **true** se ambos os operandos forem **true** e retorna **false** Caso contrário. Os operandos são convertidos implicitamente no tipo `bool` antes da avaliação, e o resultado é do tipo `bool`. O AND lógico tem associatividade da esquerda para a direita.  
  
 Os operandos para o operador AND lógico não precisam ser do mesmo tipo, mas devem ser de tipo integral ou ponteiro. Os operandos são geralmente expressões relacionais ou de igualdade.  
  
 O primeiro operando é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar a avaliação da expressão AND lógica.  
  
 O segundo operando é avaliado somente se o primeiro operando for avaliado como true (diferente de zero). Essa avaliação elimina a avaliação desnecessária do segundo operando quando a expressão AND lógica for false. Você pode usar a avaliação de curto-circuito para evitar a remoção de referência do ponteiro nulo, conforme mostrado no seguinte exemplo:  
  
```  
char *pch = 0;  
...  
(pch) && (*pch = 'a');  
```  
  
 Se `pch` for nulo (0), o lado direito da expressão nunca será avaliado. Portanto, a atribuição por meio de um ponteiro nulo é impossível.  
  
## <a name="operator-keyword-for-"></a>Palavra-chave do operador para &&  
 O **e** operador é equivalente a texto **&&**. Há duas maneiras para acessar o **e** operador em seus programas: incluem o arquivo de cabeçalho `iso646.h`, ou de compilação com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção de compilador (desabilitar extensões de linguagem).  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_Logical_AND_Operator.cpp  
// compile with: /EHsc  
// Demonstrate logical AND  
#include <iostream>  
  
using namespace std;  
  
int main() {  
   int a = 5, b = 10, c = 15;  
   cout  << boolalpha  
         << "The true expression "  
         << "a < b && b < c yields "  
         << (a < b && b < c) << endl  
         << "The false expression "  
         << "a > b && b < c yields "  
         << (a > b && b < c) << endl;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Operadores C++ internos Precedence and Associativity](cpp-built-in-operators-precedence-and-associativity.md) [operadores C++ internos, precedência e associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores lógicos C](../c-language/c-logical-operators.md)