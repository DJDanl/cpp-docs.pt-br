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
ms.openlocfilehash: b22f5a29a4dc088ea4f3db863d635badee048d2c
ms.sourcegitcommit: 6b749db14b4cf3a2b8d581fda6fdd8cb98bc3207
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/05/2020
ms.locfileid: "82825685"
---
# <a name="structure-and-union-members"></a>Membros de união e estrutura

Uma "expressão de seleção de membros" faz referência a membros de estruturas e de uniões. Essas expressões têm o valor e o tipo do membro selecionado.

> *expressão de sufixo* **.** *ID*\
> **->** *identificador* *de expressão de sufixo*

A lista a seguir descreve os dois formatos de expressões de seleção de membros:

1. No primeiro formato, *postfix-expression* representa um valor do tipo **struct** ou **union** e *identifier* nomeia um membro da estrutura ou da união especificada. O valor da operação é o de *identificador* e é um l-value se *postfix-expression* for um l-value. Consulte [Expressões de L-value e R-value](../c-language/l-value-and-r-value-expressions.md) para obter mais informações.

1. No segundo formato, *postfix-expression* representa um ponteiro para uma estrutura ou união e *identificador* nomeia um membro da estrutura ou união especificada. O valor é o de *identificador* e é um l-value.

Os dois formatos de expressões de seleção de membros têm efeitos semelhantes.

Na verdade, uma expressão que envolve o operador de seleção de**->** membro () é uma versão abreviada de uma expressão usando o ponto final (**.**) se a expressão antes do período consistir no operador<strong>\*</strong>de indireção () aplicado a um valor de ponteiro. Portanto:

```cpp
expression->identifier
```

é equivalente a

```cpp
(*expression).identifier
```

quando *expressão* for um valor do ponteiro.

## <a name="examples"></a>Exemplos

Os exemplos a seguir fazem referência a essa declaração de estrutura. Para obter informações sobre o operador de indireção<strong>\*</strong>() usado nesses exemplos, consulte [indireção e operadores de endereço](../c-language/indirection-and-address-of-operators.md).

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

Neste exemplo, a expressão `item.sp` de ponteiro é usada com o operador de seleção de membro**->**() para atribuir um valor ao membro `a`.

```
list[8].b = 12;
```

Essa instrução mostra como selecionar um membro individual da estrutura em uma matriz de estruturas.

## <a name="see-also"></a>Confira também

[Operadores de acesso de membro: . e ->](../cpp/member-access-operators-dot-and.md)
