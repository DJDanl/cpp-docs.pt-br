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
ms.openlocfilehash: 77c61101e9540a0d9469e7176eb15992a73b4b09
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62158274"
---
# <a name="simple-assignment-c"></a>Atribuição simples (C)

O operador de atribuição simples atribui o operando à direita ao operando à esquerda. O valor do operando à direita é convertido no tipo da expressão de atribuição e substituir o valor armazenado no objeto designado pelo operando à esquerda. As regras de conversão para a atribuição se aplicam (consulte [Conversões de atribuição](../c-language/assignment-conversions.md)).

```
double x;
int y;

x = y;
```

Neste exemplo, o valor de `y` é convertido para o tipo **double** e é atribuído a `x`.

## <a name="see-also"></a>Confira também

[Operadores de atribuição C](../c-language/c-assignment-operators.md)
