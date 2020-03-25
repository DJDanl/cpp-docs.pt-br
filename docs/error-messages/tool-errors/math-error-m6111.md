---
title: Erro M6111 (Math)
ms.date: 11/04/2016
f1_keywords:
- M6111
helpviewer_keywords:
- M6111
ms.assetid: c0fc13f8-33c8-4e3f-a440-126cc623441b
ms.openlocfilehash: e8abedf6a326a826d0c8ac513b15037c8bf89bce
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80173685"
---
# <a name="math-error-m6111"></a>Erro M6111 (Math)

estouro negativo de pilha

Uma operação de ponto flutuante resultou em um estouro negativo de pilha no coprocessador 8087/287/387 ou no emulador.

Esse erro geralmente é causado por uma chamada a uma função `long double` que não retorna um valor. Por exemplo, o seguinte gera esse erro quando compilado e executado:

```
long double ld() {};
main ()
{
  ld();
}
```

O programa é encerrado com o código de saída 139.
