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
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56148966"
---
# <a name="simple-assignment-c"></a>Atribuição simples (C)

O operador de atribuição simples atribui o operando à direita ao operando à esquerda. O valor do operando à direita é convertido no tipo da expressão de atribuição e substituir o valor armazenado no objeto designado pelo operando à esquerda. As regras de conversão para a atribuição se aplicam (consulte [Conversões de atribuição](../c-language/assignment-conversions.md)).

```
double x;
int y;

x = y;
```

Neste exemplo, o valor de `y` é convertido para o tipo **double** e é atribuído a `x`.

## <a name="see-also"></a>Consulte também

[Operadores de atribuição C](../c-language/c-assignment-operators.md)
