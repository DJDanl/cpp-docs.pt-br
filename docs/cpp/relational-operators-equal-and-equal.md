---
title: 'Operadores relacionais: &lt;, &gt;, &lt;=, e &gt;= | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- <
- '>'
dev_langs:
- C++
helpviewer_keywords:
- '> operator'
- less than operator
- relational operators [C++], syntax
- '>= operator'
- greater than or equal to operators [C++]
- greater than operators [C++]
- < operator
- less than or equal to operator
- <= operator
ms.assetid: d346b53d-f14d-4962-984f-89d39a17ca0f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 28d7cf77f9bea05a9220aea3d4006f64899b84ec
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="relational-operators-lt-gt-lt-and-gt"></a>Operadores relacionais: &lt;, &gt;, &lt;=, e&gt;=
## <a name="syntax"></a>Sintaxe  
  
```  
expression < expression  
expression > expression  
expression <= expression  
expression >= expression  
```  
  
## <a name="remarks"></a>Comentários  
 Os operadores relacionais binários determinam as seguintes relações:  
  
-   Menor que (**\<**)  
  
-   Maior que (**>**)  
  
-   Menor ou igual a (**\<=**)  
  
-   Maior que ou igual a (**>=**)  
  
 Esses operadores relacionais possuem associatividade da esquerda para a direita. Ambos os operandos de operadores relacionais devem ser do tipo aritmético ou de ponteiro. Eles resultam em valores do tipo `bool`. O valor retornado é **false** (0) se a relação na expressão for false; caso contrário, o valor retornado é **true** (1).  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_Relational_Operators.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
  
int main() {  
   cout  << "The true expression 3 > 2 yields: "  
         << (3 > 2) << endl  
         << "The false expression 20 < 10 yields: "  
         << (20 < 10) << endl;  
}  
```  
  
 As expressões no exemplo anterior devem ser colocadas entre parênteses, porque o operador de inserção de fluxo (**<<**) tem precedência maior do que os operadores relacionais. Portanto, a primeira expressão sem parênteses seria avaliada como:  
  
```  
(cout << "The true expression 3 > 2 yields: " << 3) < (2 << "\n");  
```  
  
 Conversões aritméticas usuais abordados [conversões padrão](standard-conversions.md) são aplicados a operandos de tipos aritméticos.  
  
## <a name="comparing-pointers"></a>Comparando ponteiros  
 Quando dois ponteiros para objetos do mesmo tipo são comparados, o resultado é determinado pelo local dos objetos apontados no espaço de endereço do programa. Os ponteiros também podem ser comparados a uma expressão constante que é avaliada como 0 ou a um ponteiro do tipo nulo *. Se uma comparação de ponteiro é feita em relação a um ponteiro de tipo void \*, o outro ponteiro é convertido implicitamente para tipo void \*. Então, a comparação será feita.  
  
 Dois ponteiros de tipos diferentes não podem ser comparados, a menos que:  
  
-   Um tipo é um tipo de classe derivado de outro tipo.  
  
-   Pelo menos um dos ponteiros é convertido explicitamente (conversão) no tipo nulo *. (O outro ponteiro é convertido implicitamente para tipo void \* para a conversão.)  
  
 Dois ponteiros do mesmo tipo que apontam para o mesmo objeto são obrigatoriamente comparados como iguais. Se dois ponteiros para membros não estáticos de um objeto são comparados, as seguintes regras se aplicam:  
  
-   Se o tipo de classe não é uma união, e se os dois membros não são separados por um *especificador de acesso*, como pública, protegida ou privada, o ponteiro para o membro declarado última comparará maior do que o ponteiro para o membro declarado anteriormente.  
  
-   Se os dois membros são separados por um *especificador de acesso*, os resultados serão indefinidos.  
  
-   Se o tipo de classe for uma união, os ponteiros para membros de dados diferentes nessa união serão comparados como iguais.  
  
 Se dois ponteiros apontarem para elementos da mesma matriz ou para o elemento além do final da matriz, o ponteiro para o objeto com o subscrito mais alto será comparado como superior. A comparação dos ponteiros é garantida como válida somente quando os ponteiros se referem a objetos na mesma matriz ou ao local após o término da matriz.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores relacionais e de igualdade C](../c-language/c-relational-and-equality-operators.md)