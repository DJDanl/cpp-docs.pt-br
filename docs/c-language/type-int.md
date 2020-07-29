---
title: Tipo int
ms.date: 11/04/2016
helpviewer_keywords:
- int data type
- type int
- portability [C++], type int
- signed integers
ms.assetid: 0067ce9a-281e-491a-ae63-632952981e13
ms.openlocfilehash: 2bfd9e108b36f073635c6d9e55e2299764dcb309
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87198860"
---
# <a name="type-int"></a>Tipo int

O tamanho de um **`signed int`** **`unsigned int`** item ou é o tamanho padrão de um inteiro em um determinado computador. Por exemplo, em sistemas operacionais de 16 bits, o **`int`** tipo geralmente é 16 bits ou 2 bytes. Em sistemas operacionais de 32 bits, o **`int`** tipo geralmente é de 32 bits ou 4 bytes. Portanto, o **`int`** tipo é equivalente ao **`short int`** **`long int`** tipo ou, e o **`unsigned int`** tipo é equivalente ao **`unsigned short`** ou ao **`unsigned long`** tipo, dependendo do ambiente de destino. Os **`int`** tipos todos representam valores assinados, a menos que especificado de outra forma.

Os especificadores de tipo **`int`** e **`unsigned int`** (ou simplesmente **`unsigned`** ) definem determinados recursos da linguagem C (por exemplo, o **`enum`** tipo). Nesses casos, as definições de **`int`** e **`unsigned int`** para uma implementação específica determinam o armazenamento real.

**Específico da Microsoft**

Os inteiros com sinal são representados no formato de dois complementos. O bit mais significativo contém o sinal: 1 para o negativo, 0 para o sinal positivo e zero. O intervalo de valores é fornecido em [limites de inteiro C e C++](../c-language/cpp-integer-limits.md), que é obtido dos limites. Arquivo de cabeçalho H.

**FINAL específico da Microsoft**

> [!NOTE]
> Os **`int`** **`unsigned int`** especificadores e de tipo são amplamente usados em programas C porque permitem que um computador específico manipule valores inteiros da maneira mais eficiente para esse computador. No entanto, como os tamanhos **`int`** dos **`unsigned int`** tipos e variam, os programas que dependem de um **`int`** tamanho específico podem não ser portáteis para outros computadores. Para tornar os programas mais portáteis, você pode usar expressões com o **`sizeof`** operador (conforme discutido [no `sizeof` operador](../c-language/sizeof-operator-c.md)) em vez de tamanhos de dados embutidos em código.

## <a name="see-also"></a>Confira também

[Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)
