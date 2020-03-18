---
title: Conjuntos de caracteres de byte único e multibyte
ms.date: 11/04/2016
helpviewer_keywords:
- SBCS (single byte character set)
- MBCS [C++], about MBCS
- character sets [C++], multibyte
- character sets [C++], single byte
ms.assetid: 2cbc78ea-33c0-4cfb-b0df-7ce2458431ce
ms.openlocfilehash: a6a0f3aaaa463297b7c51b035acc7b2f4a40b6cf
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79444654"
---
# <a name="single-byte-and-multibyte-character-sets"></a>Conjuntos de caracteres de byte único e multibyte

O conjunto de caracteres ASCII define caracteres no intervalo 0x00 – 0x7F. Há uma série de outros conjuntos de caracteres, principalmente europeus, que definem os caracteres dentro do intervalo 0x00 – 0x7F de forma idêntica ao conjunto de caracteres ASCII e também definem um conjunto de caracteres estendido de 0x80 – 0xFF. Portanto, um SBCS (conjunto de caracteres de um byte) de 8 bits é suficiente para representar o conjunto de caracteres ASCII e também os conjuntos de caracteres de vários idiomas europeus. No entanto, alguns conjuntos de caracteres não europeus, como japonês Kanji, incluem muitos caracteres além dos que podem ser representados em um esquema de codificação de um byte e, portanto, exigem a codificação de um MBCS (conjunto de caracteres multibyte).

> [!NOTE]
> Muitas rotinas de SBCS da biblioteca em tempo de execução da Microsoft tratam bytes, caracteres e cadeias de caracteres multibyte apropriadamente. Muitos conjuntos de caracteres multibyte definem o conjunto de caracteres ASCII como um subconjunto. Em muitos conjuntos de caracteres multibyte, cada caractere no intervalo 0x00 – 0x7F é idêntico ao caractere que tem o mesmo valor no conjunto de caracteres ASCII. Por exemplo, nas cadeias de caracteres ASCII e MBCS, o caractere de um byte nulo ('\0') tem valor 0x00 e indica o caractere nulo de terminação.

Um conjunto de caracteres multibyte pode consistir em caracteres de um byte e dois bytes. Portanto, uma cadeia de caracteres multibyte pode conter uma mistura de caracteres de byte único e duplo. Um caractere multibyte de dois bytes tem um byte inicial e um byte final. Em um conjunto de caracteres multibyte, os bytes iniciais ficam dentro de um determinado intervalo, assim como os bytes finais. Quando esses intervalos se sobrepõem, pode ser necessário avaliar o contexto específico para determinar se um byte está funcionando como byte inicial ou byte final.

## <a name="see-also"></a>Consulte também

[Internacionalização](../c-runtime-library/internationalization.md)<br/>
[Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
