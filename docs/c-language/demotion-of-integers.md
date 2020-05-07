---
title: Rebaixamentos de inteiros
ms.date: 11/04/2016
helpviewer_keywords:
- demoting integers
ms.assetid: 51fb3654-60b0-4de7-80eb-bd910086c18a
ms.openlocfilehash: edfb8f03094c10cf0cf33b0eb799d5d822ac017d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62234399"
---
# <a name="demotion-of-integers"></a>Rebaixamentos de inteiros

**ANSI 3.2.1.2** O resultado da conversão de um inteiro para um número inteiro com sinal mais curto ou o resultado da conversão de um número inteiro sem sinal para um número inteiro com sinal de mesmo comprimento, se o valor não puder ser representado

Quando um inteiro **long** é convertido em **short** ou **short** é convertido em `char`, os bytes menos significativos são retidos.

Por exemplo, esta linha

```
short x = (short)0x12345678L;
```

atribui o valor 0x5678 a `x`, e esta linha

```
char y = (char)0x1234;
```

atribui o valor 0x34 a `y`.

Quando variáveis com sinal são convertidas em sem sinal e vice-versa, os padrões de bits permanecem os mesmos. Por exemplo, converter -2 (0xFE) em um valor sem sinal gera 254 (também 0xFE).

## <a name="see-also"></a>Confira também

[Inteiros](../c-language/integers.md)
