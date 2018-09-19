---
title: Usando os operadores Additive | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], addition
- additive operators
ms.assetid: 7d54841e-436d-4ae8-9865-1ac1829e6f22
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 050db08d00d79e3cfee0ab7549532d78a51b1ade
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46078862"
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