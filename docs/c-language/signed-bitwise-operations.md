---
title: Operações bit a bit com sinal
ms.date: 11/04/2016
helpviewer_keywords:
- bitwise operations
- signed bitwise operations
ms.assetid: 1e5cf65b-ee32-41a0-a5c2-82c1854091f6
ms.openlocfilehash: d178900a25a5d7a080068fb1919fcba2853bef14
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50652004"
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

## <a name="see-also"></a>Consulte também

[Inteiros](../c-language/integers.md)