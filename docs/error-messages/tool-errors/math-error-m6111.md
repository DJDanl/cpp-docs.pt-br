---
title: Erro M6111 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- M6111
dev_langs:
- C++
helpviewer_keywords:
- M6111
ms.assetid: c0fc13f8-33c8-4e3f-a440-126cc623441b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 95a55ec6b7cdf0b6e4c15bd283dde77c610698fa
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46074819"
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