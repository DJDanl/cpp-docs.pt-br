---
title: Tipos de inteiro dimensionados C
ms.date: 07/22/2020
helpviewer_keywords:
- sized integer types
ms.assetid: 0d6199b4-d0ab-4e8c-a769-785f5afb92eb
ms.openlocfilehash: 7f785efb2fc93d2ec57783dd20a43642c87e4a4c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226497"
---
# <a name="c-sized-integer-types"></a>Tipos de inteiro dimensionados C

**Específico da Microsoft**

Suporte dos recursos do Microsoft C para tipos de inteiros dimensionados. Você pode declarar variáveis de inteiro de 8, 16, 32-ou 64 bits usando o `__intN` especificador de tipo, em que *`N`* é o tamanho, em bits, da variável de inteiro. O valor de *n* pode ser 8, 16, 32 ou 64. O exemplo a seguir declara uma variável de cada um dos quatro tipos de inteiros dimensionados:

```C
__int8  nSmall;     // Declares 8-bit integer
__int16 nMedium;    // Declares 16-bit integer
__int32 nLarge;     // Declares 32-bit integer
__int64 nHuge;      // Declares 64-bit integer
```

Os três primeiros tipos de inteiros de tamanho são sinônimos para os tipos ANSI que têm o mesmo tamanho. Eles são úteis para escrever código portátil que se comporta de forma idêntica em várias plataformas. O **`__int8`** tipo de dados é sinônimo de tipo **`char`** , **`__int16`** é sinônimo de tipo **`short`** , **`__int32`** é sinônimo de tipo **`int`** e **`__int64`** é sinônimo de tipo **`long long`** .

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)
