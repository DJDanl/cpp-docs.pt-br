---
title: Texto e cadeias de caracteres no Visual C++
ms.date: 11/04/2016
helpviewer_keywords:
- globalization [C++], character sets
- programming [C++], international
- multiple language support [C++]
- Unicode [C++]
- international applications [C++], about international applications
- portability [C++]
- translation [C++], character sets
- non-European characters [C++]
- character sets [C++]
- globalization [C++]
- Japanese characters [C++]
- Kanji character support [C++]
- local character sets [C++]
- ASCII characters [C++]
- character sets [C++], about character sets
- localization [C++], character sets
- translating code [C++]
- localization [C++]
- character sets [C++], non-European
- portability [C++], character sets
- MBCS [C++], international programming
ms.assetid: a1bb27ac-abe5-4c6b-867d-f761d4b93205
ms.openlocfilehash: 80b7139996fddc82b206828d4a036922fa1446d5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80167596"
---
# <a name="text-and-strings-in-visual-c"></a>Texto e cadeias de caracteres no Visual C++

Um aspecto importante do desenvolvimento de aplicativos para mercados internacionais é a representação adequada dos conjuntos de caracteres locais. O conjunto de caracteres ASCII define os caracteres no intervalo 0x00 a 0x7F. Há outros conjuntos de caracteres, principalmente europeus, que definem os caracteres dentro do intervalo 0x00 a 0x7F de forma idêntica ao conjunto de caracteres ASCII e também definem um conjunto de caracteres estendidos de 0x80 para 0xFF. Portanto, um SBCS (conjunto de caracteres de byte único) de 8 bits é suficiente para representar o conjunto de caracteres ASCII, bem como os conjuntos de caracteres para muitos idiomas europeus. No entanto, alguns conjuntos de caracteres não europeus, como o japonês kanji, incluem muitos outros caracteres do que um esquema de codificação de byte único pode representar e, portanto, exigem a codificação de MBCS (conjunto de caracteres multibyte).

## <a name="in-this-section"></a>Nesta seção

[Unicode e MBCS](../text/unicode-and-mbcs.md)<br/>
Discute o suporte C++ Visual para programação Unicode e MBCS.

[Suporte para Unicode](../text/support-for-unicode.md)<br/>
Descreve o Unicode, uma especificação para dar suporte a todos os conjuntos de caracteres, incluindo conjuntos de caracteres que não podem ser representados em um único byte.

[Suporte para conjuntos de caracteres multibyte (MBCS)](../text/support-for-multibyte-character-sets-mbcss.md)<br/>
Discute MBCS, uma alternativa ao Unicode para dar suporte a conjuntos de caracteres, como japonês e chinês, que não podem ser representados em um único byte.

[Mapeamentos de texto genérico em tchar.h](../text/generic-text-mappings-in-tchar-h.md)<br/>
Fornece mapeamentos de texto genérico específicos da Microsoft para muitos tipos de dados, rotinas e outros objetos.

[Como converter entre diversos tipos de cadeias de caracteres](../text/how-to-convert-between-various-string-types.md)<br/>
Demonstra como converter vários tipos de C++ cadeias de caracteres visuais em outras cadeias.

## <a name="related-sections"></a>Seções relacionadas

[Internacionalização](../c-runtime-library/internationalization.md)<br/>
Discute o suporte internacional na biblioteca de tempo de execução do C.

[Exemplos internacionais](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/International)<br/>
Fornece links para exemplos que demonstram internacionalização C++no Visual.

[Idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)<br/>
Fornece as cadeias de caracteres de idioma e país/região na biblioteca de tempo de execução do C.
