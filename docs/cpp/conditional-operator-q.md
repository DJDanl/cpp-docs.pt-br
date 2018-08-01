---
title: 'Operador condicional:? : | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- '?:'
- '?'
dev_langs:
- C++
helpviewer_keywords:
- conditional operators [C++]
- '? : operator'
ms.assetid: 88643ee8-7100-4f86-880a-705ec22b6271
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 205a03323a765940ce8cdc5def413faa716fa2fc
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39402198"
---
# <a name="conditional-operator--"></a>Operador condicional:? :
## <a name="syntax"></a>Sintaxe  
  
``` 
expression ? expression : expression  
``` 
  
## <a name="remarks"></a>Comentários  
 O operador condicional (**?:**) é um operador ternário (utiliza três operandos). O operador condicional funciona desta forma:  
  
-   O primeiro operando é convertido implicitamente em **bool**. É avaliado e todos os efeitos colaterais são concluídos antes de continuar.  
  
-   Se o primeiro operando for avaliado como **verdadeira** (1), o segundo operando é avaliado.  
  
-   Se o primeiro operando for avaliado como **falsos** (0), o terceiro operando é avaliado.  
  
 O resultado do operador condicional é o resultado de qualquer operando avaliado — o segundo ou o terceiro. Somente um dos dois operandos dos dois mais recentes é avaliado em uma expressão condicional.  
  
 As expressões condicionais têm a capacidade da direita para a esquerda. O primeiro operando deve ser do tipo integral ou ponteiro. As seguintes regras se aplicam para o segundo e terceiro operandos:  
  
-   Se ambos os operandos forem do mesmo tipo, o resultado é desse tipo.  
  
-   Se ambos os operandos forem de tipos de aritmética ou de enumeração, as conversões aritméticas comuns (abordados [conversões padrão](standard-conversions.md)) serão executadas para convertê-los em um tipo comum.  
  
-   Se ambos os operandos forem de tipos de ponteiro ou se uma é um tipo de ponteiro e o outro é uma expressão constante que é avaliada como 0, conversões de ponteiro serão executadas para convertê-los em um tipo comum.  
  
-   Se ambos os operandos forem de tipos de referência, conversões de referência serão executadas para convertê-los em um tipo comum.  
  
-   Se ambos os operandos forem do tipo void, o tipo comum será do tipo nulo.  
  
-   Se ambos os operandos forem do mesmo tipo definido pelo usuário, o tipo comum é desse tipo.  
  
-   Se os operandos têm tipos diferentes e pelo menos um dos operandos tem tipo definido pelo usuário, em seguida, as regras do idioma são usadas para determinar o tipo comum. (Consulte aviso abaixo).  
  
 Todas as combinações do segundo e do terceiro operando que não estiverem na lista anterior são ilegais. O tipo de resultado é o tipo comum, e é um l-value se o segundo e o terceiro operandos forem do mesmo tipo e ambos forem l-values.  
  
> [!WARNING]
>  Se os tipos do segundo e terceiro operandos não forem idênticos, regras de conversão de tipo complexo, conforme especificado no padrão do C++, são invocadas. Essas conversões podem resultar em comportamento inesperado, incluindo a construção e destruição de objetos temporários. Por esse motivo, recomendamos enfaticamente a qualquer um (1) Evite usar tipos definidos pelo usuário como operandos com o operador condicional ou (2) se você usar tipos definidos pelo usuário, então converter explicitamente cada operando em um tipo comum.  
  
## <a name="example"></a>Exemplo  
  
```cpp 
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
 [Operadores C++ internos, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operador de expressão condicional](../c-language/conditional-expression-operator.md)