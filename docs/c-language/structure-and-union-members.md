---
title: Membros de união e estrutura
ms.date: 11/04/2016
helpviewer_keywords:
- member-selection operators
- structure members, referencing
- -> operator, structure and union members
- dot operator (.)
- referencing structure members
- . operator
- operators [C], member selection
- structure member selection
ms.assetid: bb1fe304-af49-4f98-808d-afdc99b3e319
ms.openlocfilehash: 70c89344e6afcdf52981f779c441c5ec47791a77
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211639"
---
# <a name="structure-and-union-members"></a>Membros de união e estrutura

Uma "expressão de seleção de membros" faz referência a membros de estruturas e de uniões. Essas expressões têm o valor e o tipo do membro selecionado.

> *expressão de sufixo* **.** *ID*\
> *expressão* **->** de sufixo *identificador* do

A lista a seguir descreve os dois formatos de expressões de seleção de membros:

1. No primeiro formulário, o *sufixo-expressão* representa um valor **`struct`** ou **`union`** tipo, e o *identificador* nomeia um membro da estrutura ou União especificada. O valor da operação é o de *identificador* e é um l-value se *postfix-expression* for um l-value. Consulte [Expressões de L-value e R-value](../c-language/l-value-and-r-value-expressions.md) para obter mais informações.

1. No segundo formato, *postfix-expression* representa um ponteiro para uma estrutura ou união e *identificador* nomeia um membro da estrutura ou união especificada. O valor é o de *identificador* e é um l-value.

Os dois formatos de expressões de seleção de membros têm efeitos semelhantes.

Na verdade, uma expressão que envolve o operador de seleção de membro ( **->** ) é uma versão abreviada de uma expressão usando o ponto final (**.**) se a expressão antes do período consistir no operador de indireção ( <strong>\*</strong> ) aplicado a um valor de ponteiro. Portanto,

```cpp
expression->identifier
```

é equivalente a

```cpp
(*expression).identifier
```

quando *expressão* for um valor do ponteiro.

## <a name="examples"></a>Exemplos

Os exemplos a seguir fazem referência a essa declaração de estrutura. Para obter informações sobre o operador de indireção ( <strong>\*</strong> ) usado nesses exemplos, consulte [indireção e operadores de endereço](../c-language/indirection-and-address-of-operators.md).

```
struct pair
{
    int a;
    int b;
    struct pair *sp;
} item, list[10];
```

Uma expressão de seleção de membros para a estrutura `item` é semelhante a:

```
item.sp = &item;
```

No exemplo anterior, o endereço da estrutura `item` é atribuído ao membro `sp` da estrutura. Isso significa que `item` contém um ponteiro para si mesmo.

```
(item.sp)->a = 24;
```

Neste exemplo, a expressão de ponteiro `item.sp` é usada com o operador de seleção de membro ( **->** ) para atribuir um valor ao membro `a` .

```
list[8].b = 12;
```

Essa instrução mostra como selecionar um membro individual da estrutura em uma matriz de estruturas.

## <a name="see-also"></a>Confira também

[Operadores de acesso de membro: . e ->](../cpp/member-access-operators-dot-and.md)
