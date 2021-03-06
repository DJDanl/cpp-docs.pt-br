---
title: Campos de bit C++
ms.date: 11/19/2018
helpviewer_keywords:
- bitfields [C++]
- fields [C++], bit
- bit fields
ms.assetid: 6f4b62e3-cc1d-4e5d-bf34-05904104f71a
ms.openlocfilehash: 7c2dbb6e2932265984c8cb4e1e34504921e5d666
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221777"
---
# <a name="c-bit-fields"></a>Campos de bit C++

As classes e as estruturas podem conter membros que ocupam menos armazenamento do que um tipo integral. Esses membros são especificados como campos de bits. A sintaxe da especificação de *Declarador de membro* de campo de bits segue:

## <a name="syntax"></a>Sintaxe

*Declarador* **:** *expressão de constante*

## <a name="remarks"></a>Comentários

O *Declarador* (opcional) é o nome pelo qual o membro é acessado no programa. Deve ser um tipo integral (incluindo tipos enumerados). A *expressão Constant* especifica o número de bits que o membro ocupa na estrutura. Campos de bits anônimos - ou seja, membros de campos de bits sem identificador - podem ser usados para preenchimento.

> [!NOTE]
> Um campo de bits não nomeado de largura 0 força o alinhamento do próximo campo de bits para o próximo limite de **tipo** , em que **Type** é o tipo do membro.

O exemplo a seguir declara uma estrutura que contém campos de bits:

```cpp
// bit_fields1.cpp
// compile with: /LD
struct Date {
   unsigned short nWeekDay  : 3;    // 0..7   (3 bits)
   unsigned short nMonthDay : 6;    // 0..31  (6 bits)
   unsigned short nMonth    : 5;    // 0..12  (5 bits)
   unsigned short nYear     : 8;    // 0..100 (8 bits)
};
```

O layout de memória conceitual de um objeto do tipo `Date` é mostrado na figura a seguir.

![Layout de memória de um objeto de data](../cpp/media/vc38uq1.png "Layout de memória de um objeto de data") <br/>
Layout de memória de um objeto Date

Observe que `nYear` tem 8 bits de comprimento e excederia o limite de palavras do tipo declarado, **`unsigned short`** . Portanto, ele é iniciado no início de um novo **`unsigned short`** . Não é necessário que todos os campos de bits caibam em um mesmo objeto do tipo subjacente; novas unidades de armazenamento são alocadas de acordo com o número de bits solicitados na declaração.

**Específico da Microsoft**

A ordenação dos dados declarados como campos de bits vai do bit inferior até o superior, como mostra a figura acima.

**FINAL específico da Microsoft**

Se a declaração de uma estrutura inclui um campo não nomeado de comprimento 0, como mostrado no exemplo a seguir,

```cpp
// bit_fields2.cpp
// compile with: /LD
struct Date {
   unsigned nWeekDay  : 3;    // 0..7   (3 bits)
   unsigned nMonthDay : 6;    // 0..31  (6 bits)
   unsigned           : 0;    // Force alignment to next boundary.
   unsigned nMonth    : 5;    // 0..12  (5 bits)
   unsigned nYear     : 8;    // 0..100 (8 bits)
};
```

em seguida, o layout de memória é mostrado na figura a seguir:

![Layout do objeto de data com zero&#45;campo de comprimento de bits](../cpp/media/vc38uq2.png "Layout do objeto de data com zero&#45;campo de comprimento de bits") <br/>
Layout do objeto Date com campo de bits de comprimento zero

O tipo subjacente de um campo de bits deve ser um tipo integral, conforme descrito em [tipos internos](../cpp/fundamental-types-cpp.md).

Se o inicializador de uma referência do tipo `const T&` for um lvalue que se refere a um campo de bits do tipo `T` , a referência não será associada ao campo de bits diretamente. Em vez disso, a referência é associada a um inicializador temporário para conter o valor do campo de bits.

## <a name="restrictions-on-bit-fields"></a>Restrições em campos de bits

A lista a seguir detalha as operações erradas em campos de bits:

- Obtendo o endereço de um campo de bits.

- Inicializando uma não **`const`** referência com um campo de bits.

## <a name="see-also"></a>Confira também

[Classes e structs](../cpp/classes-and-structs-cpp.md)
