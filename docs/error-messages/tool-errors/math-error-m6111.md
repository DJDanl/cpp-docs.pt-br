---
title: Erro M6111 (Math)
ms.date: 11/04/2016
f1_keywords:
- M6111
helpviewer_keywords:
- M6111
ms.assetid: c0fc13f8-33c8-4e3f-a440-126cc623441b
ms.openlocfilehash: 44f406881d64d13e23ca2c0911ee278c864a2c11
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393402"
---
# <a name="math-error-m6111"></a>Erro M6111 (Math)

estouro negativo de pilha

Uma operação de ponto flutuante resultou em um estouro de pilha em coprocessador 8087/287/387 ou no emulador.

Esse erro geralmente é causado por uma chamada para um `long double` função que retorna um valor. Por exemplo, a seguir gera este erro quando compilado e executado:

```
long double ld() {};
main ()
{
  ld();
}
```

Programa é encerrado com código de saída 139.