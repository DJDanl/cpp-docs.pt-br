---
title: Atribuição simples (C)
ms.date: 11/04/2016
helpviewer_keywords:
- type conversion [C++], simple assignment
- data type conversion [C++], simple assignment
- operators [C], simple assignment
- assignment operators [C++], simple
- simple assignment operator
- equal sign
ms.assetid: e7140a0a-7104-4b3a-b293-7adcc1fdd52b
ms.openlocfilehash: 64112a54828a9a6626e78e556e8fe6dc52a3300f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229539"
---
# <a name="simple-assignment-c"></a>Atribuição simples (C)

O operador de atribuição simples atribui o operando à direita ao operando à esquerda. O valor do operando à direita é convertido no tipo da expressão de atribuição e substituir o valor armazenado no objeto designado pelo operando à esquerda. As regras de conversão para a atribuição se aplicam (consulte [Conversões de atribuição](../c-language/assignment-conversions.md)).

```
double x;
int y;

x = y;
```

Neste exemplo, o valor de `y` é convertido em tipo **`double`** e atribuído a `x` .

## <a name="see-also"></a>Confira também

[Operadores de atribuição de C](../c-language/c-assignment-operators.md)
