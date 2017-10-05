---
title: 'Operador condicional:? : | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- '?:'
- '?'
dev_langs:
- C++
helpviewer_keywords:
- conditional operators
- '? : operator'
ms.assetid: 88643ee8-7100-4f86-880a-705ec22b6271
caps.latest.revision: 10
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
ms.openlocfilehash: f66e1eb9364503988178c70f3628b44fa3d5b93a
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="conditional-operator--"></a>Operador condicional:? :
## <a name="syntax"></a>Sintaxe  
  
```  
  
expression ? expression : expression  
```  
  
## <a name="remarks"></a>Comentários  
 O operador condicional (**?:**) é um operador ternário (usa três operandos). O operador condicional funciona desta forma:  
  
-   O primeiro operando é convertido implicitamente em `bool`. É avaliado e todos os efeitos colaterais são concluídos antes de continuar.  
  
-   Se o primeiro operando é avaliado como **true** (1), o segundo operando é avaliado.  
  
-   Se o primeiro operando é avaliado como **false** (0), o terceiro operando é avaliado.  
  
 O resultado do operador condicional é o resultado de qualquer operando avaliado — o segundo ou o terceiro. Somente um dos dois operandos dos dois mais recentes é avaliado em uma expressão condicional.  
  
 As expressões condicionais têm a capacidade da direita para a esquerda. O primeiro operando deve ser do tipo integral ou ponteiro. As seguintes regras se aplicam ao segundo e terceiro operandos:  
  
-   Se ambos os operandos forem do mesmo tipo, o resultado será daquele tipo.  
  
-   Se ambos os operandos forem de tipos de aritmética ou de enumeração, as conversões aritméticas normais (abordados [conversões padrão](standard-conversions.md)) são executadas para convertê-los em um tipo comum.  
  
-   Se ambos os operandos forem de tipos de ponteiro ou se uma é um tipo de ponteiro e a outra é uma expressão constante que é avaliada como 0, conversões de ponteiro são executadas para convertê-los em um tipo comum.  
  
-   Se ambos os operandos forem de tipos de referência, conversões de referência são executadas para convertê-los em um tipo comum.  
  
-   Se ambos os operandos forem do tipo void, o tipo comum é tipo void.  
  
-   Se ambos os operandos forem do mesmo tipo definido pelo usuário, o tipo comum é desse tipo.  
  
-   Se os operandos tiverem tipos diferentes e pelo menos um dos operandos tem tipo definido pelo usuário, em seguida, as regras do idioma são usadas para determinar o tipo comum. (Consulte abaixo de aviso).  
  
 Todas as combinações do segundo e do terceiro operando que não estiverem na lista anterior são ilegais. O tipo de resultado é o tipo comum, e é um l-value se o segundo e o terceiro operandos forem do mesmo tipo e ambos forem l-values.  
  
> [!WARNING]
>  Se os tipos de segundo e terceiro operandos não forem idênticos, regras de conversão de tipo complexo, conforme especificado no C++ padrão, são invocadas. Essas conversões podem resultar em comportamento inesperado, incluindo a construção e a destruição de objetos temporários. Por esse motivo, recomendamos enfaticamente a um (1) Evite usar tipos definidos pelo usuário como operandos com o operador condicional ou (2) se você usar tipos definidos pelo usuário, converter explicitamente cada operando em um tipo comum.  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_Expressions_with_the_Conditional_Operator.cpp  
// compile with: /EHsc  
// Demonstrate conditional operator  
#include <iostream>  
using namespace std;  
int main() {  
   int i = 1, j = 2;  
   cout << ( i > j ? i : j ) << " is greater." << endl;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operador de expressão condicional](../c-language/conditional-expression-operator.md)
