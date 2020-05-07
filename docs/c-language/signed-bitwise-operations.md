---
title: Operações bit a bit com sinal
ms.date: 11/04/2016
helpviewer_keywords:
- bitwise operations
- signed bitwise operations
ms.assetid: 1e5cf65b-ee32-41a0-a5c2-82c1854091f6
ms.openlocfilehash: 43f65fd5d1ea14ef5e15f18d9c8516ccf5fb1e08
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62158306"
---
# <a name="signed-bitwise-operations"></a>Operações bit a bit com sinal

**ANSI 3.3** Os resultados de operações bit a bit em inteiros com sinal

As operações bit a bit em inteiros com sinal funcionam da mesma forma que as operações bit a bit em inteiros sem sinal. Por exemplo, `-16 & 99` pode ser expresso em binário como

```
  11111111 11110000
& 00000000 01100011
  _________________
  00000000 01100000
```

O resultado do AND bit a bit é 96.

## <a name="see-also"></a>Confira também

[Inteiros](../c-language/integers.md)
