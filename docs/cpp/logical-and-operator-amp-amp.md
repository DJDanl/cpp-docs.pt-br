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
ms.openlocfilehash: 4921a6de3072ef402ba355714ddd67328c3a3541
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39406826"
---
# <a name="logical-and-operator-ampamp"></a>Operador AND lógico: &amp;&amp;
## <a name="syntax"></a>Sintaxe  
  
```  
expression && expression  
```  
  
## <a name="remarks"></a>Comentários  
 O operador AND lógico (**&&**) retorna um valor booliano TRUE se ambos os operandos forem TRUE e retornará FALSE caso contrário. Os operandos são implicitamente convertidos para o tipo **bool** antes da avaliação e o resultado é do tipo **bool**. O AND lógico tem associatividade da esquerda para a direita.  
  
 Os operandos para o operador AND lógico não precisam ser do mesmo tipo, mas devem ser de tipo integral ou ponteiro. Os operandos são geralmente expressões relacionais ou de igualdade.  
  
 O primeiro operando é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar a avaliação da expressão AND lógica.  
  
 O segundo operando é avaliado somente se o primeiro operando for avaliado como true (diferente de zero). Essa avaliação elimina a avaliação desnecessária do segundo operando quando a expressão AND lógica for false. Você pode usar a avaliação de curto-circuito para evitar a remoção de referência do ponteiro nulo, conforme mostrado no seguinte exemplo:  
  
```cpp 
char *pch = 0;  
...  
(pch) && (*pch = 'a');  
```  
  
 Se `pch` for nulo (0), o lado direito da expressão nunca será avaliado. Portanto, a atribuição por meio de um ponteiro nulo é impossível.  
  
## <a name="operator-keyword-for-"></a>Palavra-chave do operador para &&  
 O **e** operador é o equivalente de texto de **&&**. Há duas maneiras para acessar o **e** operador em seus programas: incluir o arquivo de cabeçalho `iso646.h`, ou compilando com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção do compilador (desabilitar extensões de linguagem).  
  
## <a name="example"></a>Exemplo  
  
```cpp 
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
 [Operadores C++ internos precedência e associatividade](cpp-built-in-operators-precedence-and-associativity.md)  
 [Operadores C++ internos, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores lógicos C](../c-language/c-logical-operators.md)