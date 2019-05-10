---
title: 'Categorias de valor: Lvalues e Rvalues (C++)'
ms.date: 05/07/2019
helpviewer_keywords:
- R-values [C++]
- L-values [C++]
ms.assetid: a8843344-cccc-40be-b701-b71f7b5cdcaf
ms.openlocfilehash: 4e3cfa87a8f1ae9b17f7c08afd8faeabea7102b3
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65222010"
---
# <a name="lvalues-and-rvalues-c"></a>Lvalues e Rvalues (C++)

Cada expressão C++ tem um tipo e pertence a um *categoria de valor*. As categorias de valor são a base para regras que os compiladores devem seguir ao criar, copiar e mover objetos temporários durante a avaliação da expressão.

O padrão c++17 define categorias de valor de expressão da seguinte maneira:

- Um *glvalue* é uma expressão cuja avaliação determina a identidade de um objeto, um campo de bits ou uma função.
- Um *prvalue* é uma expressão cuja avaliação inicializa um objeto ou um campo de bits ou calcula o valor do operando de um operador, conforme especificado pelo contexto no qual ela aparece.
- Uma *xvalue* é um glvalue que denota um objeto ou um campo de bits cujos recursos podem ser reutilizados (normalmente porque ele está perto do fim do seu tempo de vida). Exemplo: Determinados tipos de expressões que envolvem as referências de rvalue (8.3.2) produzem xvalues, como uma chamada para uma função cujo tipo de retorno é uma referência rvalue ou uma conversão para um tipo de referência de rvalue.
- Uma *lvalue* é um que não seja um xvalue glvalue.
- Uma *rvalue* é um prvalue ou um xvalue.

O diagrama a seguir ilustra as relações entre as categorias:

![Categorias de valor de expressão C++](media/value_categories.png "categorias de valor de expressão C++")

Um lvalue tem um endereço que seu programa pode acessar. Exemplos de expressões de lvalue incluem nomes de variáveis, incluindo **const** chamadas que retornam uma referência de lvalue, campos de bits, uniões e membros de classe de função de variáveis, elementos de matriz.

Uma expressão de prvalue não possui endereço que é acessível pelo seu programa. Exemplos de expressões de prvalue incluem literais, chamadas de função que retornam um tipo de não referência e os objetos temporários criados durante a avaliação de expressão, mas acessíveis apenas pelo compilador.

Uma expressão de xvalue tem um endereço que não estarão mais acessíveis pelo seu programa, mas pode ser usado para inicializar uma referência de rvalue, que fornece acesso à expressão. Exemplos incluem chamadas de função que retornam uma referência de rvalue e o subscrito de matriz, membro e ponteiro para expressões de membro em que a matriz ou objeto é uma referência de rvalue.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra vários usos corretos e incorretos de l-values e r-values:

```cpp
// lvalues_and_rvalues2.cpp
int main()
{
    int i, j, *p;

    // Correct usage: the variable i is an lvalue and the literal 7 is a prvalue.
    i = 7;

    // Incorrect usage: The left operand must be an lvalue (C2106).`j * 4` is a prvalue.
    7 = i; // C2106
    j * 4 = 7; // C2106

    // Correct usage: the dereferenced pointer is an lvalue.
    *p = i;

    // Correct usage: the conditional operator returns an lvalue.
    ((i < 3) ? i : j) = 7;
    
    // Incorrect usage: the constant ci is a non-modifiable lvalue (C3892).
    const int ci = 7;
    ci = 9; // C3892
}
```

> [!NOTE]
> Os exemplos neste tópico ilustram o uso correto e incorreto quando os operadores não são sobrecarregados. Ao sobrecarregar os operadores, é possível tornar uma expressão como `j * 4` um l-value.

Os termos *lvalue* e *rvalue* geralmente são usadas quando você se referir a referências de objeto. Para obter mais informações sobre referências, consulte [Declarador de referência Lvalue: &](../cpp/lvalue-reference-declarator-amp.md) e [Declarador de referência Rvalue: & &](../cpp/rvalue-reference-declarator-amp-amp.md).

## <a name="see-also"></a>Consulte também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)<br/>
[Declarador de referência Lvalue: &](../cpp/lvalue-reference-declarator-amp.md)<br/>
[Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md)
