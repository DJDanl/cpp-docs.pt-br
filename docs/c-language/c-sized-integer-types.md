---
title: Tipos de inteiro dimensionados C
ms.date: 11/04/2016
helpviewer_keywords:
- sized integer types
ms.assetid: 0d6199b4-d0ab-4e8c-a769-785f5afb92eb
ms.openlocfilehash: 136065466d3adb4017cf18f2baf8c3387ffbd035
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62313292"
---
# <a name="c-sized-integer-types"></a>Tipos de inteiro dimensionados C

**Específico da Microsoft**

Suporte dos recursos do Microsoft C para tipos de inteiros dimensionados. Você pode declarar variáveis de inteiro de 8, 16, 32 ou 64 bits usando o especificador de tipo __int*n*, em que *n* é o tamanho, em bits, da variável de inteiro. O valor de *n* pode ser 8, 16, 32 ou 64. O exemplo a seguir declara uma variável de cada um dos quatro tipos de inteiros dimensionados:

```
__int8 nSmall;      // Declares 8-bit integer
__int16 nMedium;    // Declares 16-bit integer
__int32 nLarge;     // Declares 32-bit integer
__int64 nHuge;      // Declares 64-bit integer
```

Os primeiros três tipos de inteiros dimensionados são sinônimos para os tipos ANSI que têm o mesmo tamanho, e são úteis para escrever o código portátil que se comporta de forma idêntica em várias plataformas. Observe que o tipo de dados __int8 é sinônimo de tipo Char, \__int16 é sinônimo de tipo short e \__int32 é sinônimo de tipo int. O \_tipo de _int64 não tem uma equivalente ANSI equivalente.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)
