---
title: Usando os operadores Additive
ms.date: 11/04/2016
helpviewer_keywords:
- operators [C++], addition
- additive operators
ms.assetid: 7d54841e-436d-4ae8-9865-1ac1829e6f22
ms.openlocfilehash: 06d71f3ad1944976a8d415be9487cb5ea365fa26
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213678"
---
# <a name="using-the-additive-operators"></a>Usando os operadores Additive

Os exemplos a seguir, que ilustram os operadores de adição e subtração, usam estas declarações:

```
int i = 4, j;
float x[10];
float *px;
```

Estas instruções são equivalentes:

```
px = &x[4 + i];
px = &x[4] + i;
```

O valor de `i` é multiplicado pelo comprimento de um **`float`** e adicionado a `&x[4]` . O valor de ponteiro resultante é o endereço de `x[8]`.

```
j = &x[i] - &x[i-2];
```

Nesse exemplo, o endereço do terceiro elemento de `x` (determinado por `x[i-2]`) é subtraído do endereço do quinto elemento de `x` (determinado por `x[i]`). A diferença é dividida pelo comprimento de a **`float`** ; o resultado é o valor inteiro 2.

## <a name="see-also"></a>Confira também

[Operadores aditivos C](../c-language/c-additive-operators.md)
