---
title: 'Categorias de valor: lvalues e rvalues (C++)'
ms.date: 05/07/2019
helpviewer_keywords:
- R-values [C++]
- L-values [C++]
ms.assetid: a8843344-cccc-40be-b701-b71f7b5cdcaf
ms.openlocfilehash: b4b3ba5fdbc11ec97870b0f06fd1aabd3b57f5ca
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225963"
---
# <a name="lvalues-and-rvalues-c"></a>Lvalues e Rvalues (C++)

Cada expressão C++ tem um tipo e pertence a uma *categoria de valor*. As categorias de valor são a base para as regras que os compiladores devem seguir ao criar, copiar e mover objetos temporários durante a avaliação da expressão.

O padrão C++ 17 define as categorias de valor de expressão da seguinte maneira:

- Um *glvalue* é uma expressão cuja avaliação determina a identidade de um objeto, um campo de bits ou uma função.
- Um *não prvalue* é uma expressão cuja avaliação Inicializa um objeto ou um campo de bits, ou computa o valor do operando de um operador, conforme especificado pelo contexto no qual ele aparece.
- Um *xValue* é um glvalue que denota um objeto ou um campo de bits cujos recursos podem ser reutilizados (geralmente porque está próximo ao final do seu tempo de vida). Exemplo: determinados tipos de expressões que envolvem referências a rvalue (8.3.2) produzem XValues, como uma chamada para uma função cujo tipo de retorno é uma referência rvalue ou uma conversão para um tipo de referência rvalue.
- Um *lvalue* é um glvalue que não é um xValue.
- Um *rvalue* é um não prvalue ou um xValue.

O diagrama a seguir ilustra as relações entre as categorias:

![Categorias de valor de expressão do C++](media/value_categories.png "Categorias de valor de expressão do C++")

Um lvalue tem um endereço que seu programa pode acessar. Exemplos de expressões lvalue incluem nomes de variáveis, incluindo **`const`** variáveis, elementos de matriz, chamadas de função que retornam uma referência de lvalue, campos de bits, uniões e membros de classe.

Uma expressão não prvalue não tem endereço acessível por seu programa. Exemplos de expressões não prvalue incluem literais, chamadas de função que retornam um tipo de não referência e objetos temporários que são criados durante a expressão evalution, mas acessíveis somente pelo compilador.

Uma expressão xValue tem um endereço que não é mais acessível pelo seu programa, mas pode ser usada para inicializar uma referência rvalue, que fornece acesso à expressão. Os exemplos incluem chamadas de função que retornam uma referência rvalue e o subscrito, o membro e o ponteiro da matriz para expressões de membro em que a matriz ou o objeto é uma referência rvalue.

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

Os termos *lvalue* e *rvalue* geralmente são usados quando você faz referência a referências de objeto. Para obter mais informações sobre referências, consulte [Declarador de referência lvalue: &](../cpp/lvalue-reference-declarator-amp.md) e o [Declarador de referência rvalue:  &&](../cpp/rvalue-reference-declarator-amp-amp.md).

## <a name="see-also"></a>Confira também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)<br/>
[Declarador de referência Lvalue: &](../cpp/lvalue-reference-declarator-amp.md)<br/>
[Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md)
