---
title: Caracteres multibyte e largos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2522761389a7f97acf4157683f8fce19e94429d8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46100520"
---
# <a name="multibyte-and-wide-characters"></a>Caracteres multibyte e largos

Um caractere multibyte é um caractere composto por sequências de um ou mais bytes. Cada sequência de bytes representa um único caractere no conjunto de caracteres estendido. Os caracteres multibyte são usados nos conjuntos de caracteres como Kanji.

Os caracteres largos são códigos de caracteres multilíngues que sempre têm 16 bits de largura. O tipo para constantes de caractere é `char`; para caracteres largos, o tipo é `wchar_t`. Como os caracteres largos são sempre de tamanho fixo, usar caracteres largos simplifica a programação com conjuntos de caracteres internacionais.

O literal de cadeia de caracteres largos `L"hello"` se torna uma matriz de seis inteiros do tipo `wchar_t`.

```
{L'h', L'e', L'l', L'l', L'o', 0}
```

A especificação Unicode é a especificação de caracteres largos. As rotinas da biblioteca em tempo de execução para converter entre caracteres multibyte e largos incluem `mbstowcs`, `mbtowc`, `wcstombs` e `wctomb`.

## <a name="see-also"></a>Consulte também

[Identificadores C](../c-language/c-identifiers.md)