---
title: Usando os operadores Additive
ms.date: 11/04/2016
helpviewer_keywords:
- operators [C++], addition
- additive operators
ms.assetid: 7d54841e-436d-4ae8-9865-1ac1829e6f22
ms.openlocfilehash: 0e2d802a77c56b8f458b614b29e86e2e1d30a55e
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56151423"
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

O valor de `i` é multiplicado pelo comprimento de um **float** e adicionado a `&x[4]`. O valor de ponteiro resultante é o endereço de `x[8]`.

```
j = &x[i] - &x[i-2];
```

Nesse exemplo, o endereço do terceiro elemento de `x` (determinado por `x[i-2]`) é subtraído do endereço do quinto elemento de `x` (determinado por `x[i]`). A diferença é dividida pelo comprimento de um **float**; o resultado é o valor inteiro 2.

## <a name="see-also"></a>Consulte também

[Operadores aditivos C](../c-language/c-additive-operators.md)
