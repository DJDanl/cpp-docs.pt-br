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
ms.openlocfilehash: 8cd035686a07285f52fe24aa7ab4f360619d5e1f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229071"
---
# <a name="bool-c"></a>bool (C++)

Essa palavra-chave é um tipo interno. Uma variável desse tipo pode ter valores [`true`](../cpp/true-cpp.md) e [`false`](../cpp/false-cpp.md) . As expressões condicionais têm o tipo **`bool`** e, portanto, têm valores do tipo **`bool`** . Por exemplo, `i != 0` agora tem **`true`** ou **`false`** depende do valor de `i` .

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): o operando de um sufixo ou incremento de prefixo ou um operador de decréscimo não pode ser do tipo **`bool`** . Em outras palavras, dada uma variável `b` do tipo **`bool`** , essas expressões não são mais permitidas:

```cpp
    b++;
    ++b;
    b--;
    --b;
```

Os valores **`true`** e **`false`** têm a seguinte relação:

```cpp
!false == true
!true == false
```

Na instrução a seguir:

```cpp
if (condexpr1) statement1;
```

Se `condexpr1` for **`true`** , `statement1` será sempre executado; se `condexpr1` for **`false`** , `statement1` nunca será executado.

Quando um operador de sufixo ou prefixo **`++`** é aplicado a uma variável do tipo **`bool`** , a variável é definida como **`true`** .

O **Visual Studio 2017 versão 15,3 e posteriores**: `operator++` para **`bool`** foi removido do idioma e não tem mais suporte.

O operador sufixo ou prefix **`--`** não pode ser aplicado a uma variável desse tipo.

O **`bool`** tipo participa de promoções de integral padrão. Um valor de r-value do tipo **`bool`** pode ser convertido em um r-value do tipo **`int`** , com **`false`** tornar-se zero e **`true`** se tornar um. Como um tipo distinto, **`bool`** participa da resolução de sobrecarga.

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tipos internos](../cpp/fundamental-types-cpp.md)
