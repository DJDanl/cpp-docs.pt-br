---
title: Erro M6111 (Math)
ms.date: 11/04/2016
f1_keywords:
- M6111
helpviewer_keywords:
- M6111
ms.assetid: c0fc13f8-33c8-4e3f-a440-126cc623441b
ms.openlocfilehash: 986c0e53edcddfc47eb9ba970f3c32385e0a57d9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225183"
---
# <a name="math-error-m6111"></a>Erro M6111 (Math)

estouro negativo de pilha

Uma operação de ponto flutuante resultou em um estouro negativo de pilha no coprocessador 8087/287/387 ou no emulador.

Esse erro geralmente é causado por uma chamada para uma **`long double`** função que não retorna um valor. Por exemplo, o seguinte gera esse erro quando compilado e executado:

```
long double ld() {};
main ()
{
  ld();
}
```

O programa é encerrado com o código de saída 139.
