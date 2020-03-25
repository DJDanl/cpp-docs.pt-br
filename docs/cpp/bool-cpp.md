---
title: bool (C++)
ms.date: 11/04/2016
f1_keywords:
- bool_cpp
- __BOOL_DEFINED
helpviewer_keywords:
- bool keyword [C++]
- __BOOL_DEFINED macro
ms.assetid: 9abed3f2-d21c-4eb4-97c5-716342e613d8
ms.openlocfilehash: db246cda79c778f37c5afbfda4a68c191c474e12
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190489"
---
# <a name="bool-c"></a>bool (C++)

Essa palavra-chave é um tipo interno. Uma variável desse tipo pode ter valores [true](../cpp/true-cpp.md) e [false](../cpp/false-cpp.md). Expressões condicionais têm o tipo **bool** e, portanto, têm valores do tipo **bool**. Por exemplo, `i!=0` agora tem TRUE ou FALSE, dependendo do valor de `i`.

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): o operando de um sufixo ou incremento de prefixo ou um operador de decréscimo não pode ser do tipo **bool**. Em outras palavras, dadas uma variável `b` do tipo **bool**, essas expressões não são mais permitidas:

```cpp
    b++;
    ++b;
    b--;
    --b;
```

Os valores TRUE e FALSE têm a seguinte relação:

```cpp
!false == true
!true == false
```

Na instrução a seguir:

```cpp
if (condexpr1) statement1;
```

Se `condexpr1` for TRUE, `statement1` será sempre executado; se `condexpr1` for FALSE, `statement1` nunca será executado.

Quando um sufixo ou prefixo **++** operador é aplicado a uma variável do tipo **bool**, a variável é definida como true.
**Visual Studio 2017 versão 15,3 e posterior**: o operador + + para **bool** foi removido do idioma e não tem mais suporte.

Não é possível aplicar o sufixo ou o prefixo **--** operador a uma variável desse tipo.

O tipo **bool** participa de promoções integrais. Um valor de r do tipo **bool** pode ser convertido em um r-value do tipo **int**, com false se tornando zero e verdadeiro se tornando um. Como um tipo distinto, **bool** participa da resolução de sobrecarga.

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tipos internos](../cpp/fundamental-types-cpp.md)
