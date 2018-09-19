---
title: bool (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- bool_cpp
- __BOOL_DEFINED
dev_langs:
- C++
helpviewer_keywords:
- bool keyword [C++]
- __BOOL_DEFINED macro
ms.assetid: 9abed3f2-d21c-4eb4-97c5-716342e613d8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ce07cfce4b7361486489c2f00c3e4b395c71e200
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46058504"
---
# <a name="bool-c"></a>bool (C++)

Essa palavra-chave é um tipo interno. Uma variável desse tipo pode ter valores [verdadeira](../cpp/true-cpp.md) e [falso](../cpp/false-cpp.md). As expressões condicionais têm o tipo **bool** e, portanto os valores do tipo **bool**. Por exemplo, `i!=0` agora tem TRUE ou FALSE dependendo do valor de `i`.

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): O operando de um sufixo ou prefixo incremento ou decremento operador não pode ser do tipo **bool**. Em outras palavras, dada uma variável `b` do tipo **bool**, essas expressões não são permitidas:

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

Se `condexpr1` for TRUE, `statement1` sempre será executado; se `condexpr1` for FALSE, `statement1` nunca será executado.

Quando um sufixo ou prefixo **++** operador é aplicado a uma variável do tipo **bool**, a variável é definida como TRUE.
**Visual Studio 2017 versão 15.3 e posterior**: operator + + de **bool** foi removida da linguagem e não é mais suportada.

Sufixo ou prefixo **--** operador não pode ser aplicado a uma variável desse tipo.

O **bool** tipo participa de promoções de integral. Um valor de r do tipo **bool** pode ser convertido em um valor de r do tipo **int**, tornando-se falso com o zero e TRUE se tornando um. Como um tipo diferente, **bool** participa da resolução de sobrecarga.

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tipos fundamentais](../cpp/fundamental-types-cpp.md)