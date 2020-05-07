---
title: Caracteres multibyte e largos
ms.date: 11/04/2016
helpviewer_keywords:
- globalization [C++], character sets
- character data types [C]
- Unicode [C++], wide character set
- types [C], character
- characters [C++], wide
- international applications [C++], character display
- multibyte characters [C++]
- wide characters [C++]
- characters [C++], codes
- character codes [C++], wide
- character codes [C++], multibyte
ms.assetid: 1943c469-200d-4724-b18f-781d70520f9e
ms.openlocfilehash: 0d573fac938f5e4d62c99c8cd6e676b96123a0c4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62232904"
---
# <a name="multibyte-and-wide-characters"></a>Caracteres multibyte e largos

Um caractere multibyte é um caractere composto por sequências de um ou mais bytes. Cada sequência de bytes representa um único caractere no conjunto de caracteres estendido. Os caracteres multibyte são usados nos conjuntos de caracteres como Kanji.

Os caracteres largos são códigos de caracteres multilíngues que sempre têm 16 bits de largura. O tipo para constantes de caractere é `char`; para caracteres largos, o tipo é `wchar_t`. Como os caracteres largos são sempre de tamanho fixo, usar caracteres largos simplifica a programação com conjuntos de caracteres internacionais.

O literal de cadeia de caracteres largos `L"hello"` se torna uma matriz de seis inteiros do tipo `wchar_t`.

```
{L'h', L'e', L'l', L'l', L'o', 0}
```

A especificação Unicode é a especificação de caracteres largos. As rotinas da biblioteca em tempo de execução para converter entre caracteres multibyte e largos incluem `mbstowcs`, `mbtowc`, `wcstombs` e `wctomb`.

## <a name="see-also"></a>Confira também

[Identificadores de C](../c-language/c-identifiers.md)
