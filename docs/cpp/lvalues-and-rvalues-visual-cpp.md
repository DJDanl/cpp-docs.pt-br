---
title: 'Categorias de valor: Lvalues e Rvalues (Visual C++) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- R-values [C++]
- L-values [C++]
ms.assetid: a8843344-cccc-40be-b701-b71f7b5cdcaf
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 34513ba6799b1f70d16867571d38185420fa3576
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="lvalues-and-rvalues-visual-c"></a>Lvalues e Rvalues (Visual C++)
Cada expressão C++ tem um tipo e pertence a um *categoria valor*. As categorias de valor são a base para regras que compiladores devem seguir ao criar, copiar e mover objetos temporários durante a avaliação da expressão. 

 O padrão C++ 17 define categorias de valor de expressão da seguinte maneira:

- Um *glvalue* é uma expressão cuja avaliação determina a identidade de um objeto, um campo de bits ou uma função. 
- Um *não prvalue* é uma expressão cuja avaliação inicializa um objeto ou um campo de bits ou calcula o valor do operando de um operador, conforme especificado pelo contexto no qual ela aparece. 
- Um *xvalue* é um glvalue que denota um objeto ou um campo de bits cujos recursos podem ser reutilizados (normalmente porque é próximo ao final de sua vida útil). [Exemplo: determinados tipos de expressões que envolvem referências a rvalue (8.3.2) geram xvalues, como uma chamada para uma função cujo tipo de retorno é uma referência rvalue ou uma conversão para um tipo de referência de rvalue. ] 
- Um *lvalue* é um glvalue que não seja um xvalue. 
- Um *rvalue* é um não prvalue ou um xvalue. 

O diagrama a seguir ilustra as relações entre as categorias:

 ![Categorias de valor de expressão C++](media/value_categories.png "categorias de valor de expressão C++")  
 
 Lvalue tem um endereço que seu programa pode acessar. Exemplos de expressões de lvalue nomes de variável, incluindo `const` chamadas que retornam uma referência lvalue, os campos de bits, uniões e membros de classe de função de variáveis, elementos de matriz. 
 
 Uma expressão não prvalue não tem endereço acessível pelo seu programa. Exemplos de expressões não prvalue incluem literais, chamadas de função que retornam um tipo de referência não e objetos temporários criados durante a avaliação da expressão, mas acessível somente pelo compilador. 

 Uma expressão de xvalue não tem um endereço, mas pode ser usada para inicializar uma referência de rvalue, que fornece acesso à expressão. Exemplos incluem as chamadas de função que retornam uma referência de rvalue e de subscrito de matriz, membro e ponteiro para expressões de membro onde a matriz ou o objeto é uma referência rvalue. 
 
 O exemplo a seguir demonstra vários usos corretos e incorretos de l-values e r-values:  
  
```  
// lvalues_and_rvalues2.cpp  
int main()  
{  
   int i, j, *p;  
  
   // Correct usage: the variable i is an lvalue and the literal 7 is a prvalue.  
   i = 7;  
  
   // Incorrect usage: The left operand must be an lvalue (C2106).  `j * 4` is a prvalue.
   7 = i; // C2106  
   j * 4 = 7; // C2106  
  
   // Correct usage: the dereferenced pointer is an lvalue.  
   *p = i;   
  
   const int ci = 7;  
   // Incorrect usage: the variable is a non-modifiable lvalue (C3892).  
   ci = 9; // C3892  
  
   // Correct usage: the conditional operator returns an lvalue.  
   ((i < 3) ? i : j) = 7;  
}  
```  
  
> [!NOTE]
>  Os exemplos neste tópico ilustram o uso correto e incorreto quando os operadores não são sobrecarregados. Ao sobrecarregar os operadores, é possível tornar uma expressão como `j * 4` um l-value.  

  
 Os termos de *lvalue* e *rvalue* são geralmente usados quando você se referir a referências de objeto. Para obter mais informações sobre referências, consulte [Declarador de referência Lvalue: &](../cpp/lvalue-reference-declarator-amp.md) e [Declarador de referência Rvalue: & &](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos básicos](../cpp/basic-concepts-cpp.md)   
 [Declarador de referência lvalue: &](../cpp/lvalue-reference-declarator-amp.md)   
 [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md)