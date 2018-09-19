---
title: Operações bit a bit com sinal | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- bitwise operations
- signed bitwise operations
ms.assetid: 1e5cf65b-ee32-41a0-a5c2-82c1854091f6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 184fd5a0e6c12cb58e9fed759459e7b8172896f8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46038289"
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