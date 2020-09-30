---
title: Conjuntos de caracteres de byte único e multibyte
description: Uma introdução aos conjuntos de caracteres únicos e múltiplos bytes na biblioteca de tempo de execução da Microsoft.
ms.topic: conceptual
ms.date: 11/04/2016
helpviewer_keywords:
- SBCS (single byte character set)
- MBCS [C++], about MBCS
- character sets [C++], multibyte
- character sets [C++], single byte
ms.assetid: 2cbc78ea-33c0-4cfb-b0df-7ce2458431ce
ms.openlocfilehash: 6668285915ab9f1939c1baf8a2d3da2d00543528
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91590167"
---
# <a name="single-byte-and-multibyte-character-sets"></a>Conjuntos de caracteres de byte único e multibyte

O conjunto de caracteres ASCII define caracteres no intervalo 0x00 – 0x7F. Há uma série de outros conjuntos de caracteres, principalmente europeus, que definem os caracteres dentro do intervalo 0x00 – 0x7F de forma idêntica ao conjunto de caracteres ASCII e também definem um conjunto de caracteres estendido de 0x80 – 0xFF.  Um SBCS (conjunto de caracteres de byte único) de 8 bits é suficiente para representar o conjunto de caracteres ASCII, bem como os conjuntos de caracteres para muitos idiomas europeus. No entanto, alguns conjuntos de caracteres não europeus, como o japonês kanji, incluem muitos outros caracteres do que podem ser representados em um esquema de codificação de byte único e, portanto, exigem codificação de MBCS (conjunto de caracteres multibyte).

> [!NOTE]
> Muitas rotinas de SBCS da biblioteca em tempo de execução da Microsoft tratam bytes, caracteres e cadeias de caracteres multibyte apropriadamente. Muitos conjuntos de caracteres multibyte definem o conjunto de caracteres ASCII como um subconjunto. Em muitos conjuntos de caracteres multibyte, cada caractere no intervalo 0x00 – 0x7F é idêntico ao caractere que tem o mesmo valor no conjunto de caracteres ASCII. Por exemplo, nas cadeias de caracteres ASCII e MBCS, o caractere de um byte nulo ('\0') tem valor 0x00 e indica o caractere nulo de terminação.

Um conjunto de caracteres multibyte pode consistir em caracteres de um byte e de dois bytes. Uma cadeia de caracteres multibyte pode conter uma mistura de caracteres de byte único e de byte duplo. Um caractere multibyte de dois bytes tem um byte inicial e um byte final. Em um conjunto de caracteres multibyte, os bytes iniciais ficam dentro de um determinado intervalo, assim como os bytes finais. Quando esses intervalos se sobrepõem, talvez seja necessário avaliar o contexto para determinar se um determinado byte está funcionando como um byte de Lead ou um byte de trilha.

## <a name="see-also"></a>Confira também

[Internacionalização](../c-runtime-library/internationalization.md)<br/>
[Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
