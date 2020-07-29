---
title: Rebaixamentos de inteiros
ms.date: 11/04/2016
helpviewer_keywords:
- demoting integers
ms.assetid: 51fb3654-60b0-4de7-80eb-bd910086c18a
ms.openlocfilehash: aee0a5041cd37b1fbad785b760b8cefde74eb195
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218878"
---
# <a name="demotion-of-integers"></a>Rebaixamentos de inteiros

**ANSI 3.2.1.2** O resultado da conversão de um inteiro para um número inteiro com sinal mais curto ou o resultado da conversão de um número inteiro sem sinal para um número inteiro com sinal de mesmo comprimento, se o valor não puder ser representado

Quando um **`long`** inteiro é convertido em um **`short`** , ou um **`short`** é convertido em um **`char`** , os bytes menos significativos são mantidos.

Por exemplo, esta linha

```
short x = (short)0x12345678L;
```

atribui o valor 0x5678 a `x`, e esta linha

```
char y = (char)0x1234;
```

atribui o valor 0x34 a `y`.

Quando **`signed`** as variáveis são convertidas **`unsigned`** e vice-versa, os padrões de bit permanecem os mesmos. Por exemplo, a conversão-2 (0xFE) em um **`unsigned`** valor produz 254 (também 0xFE).

## <a name="see-also"></a>Confira também

[Inteiros](../c-language/integers.md)
