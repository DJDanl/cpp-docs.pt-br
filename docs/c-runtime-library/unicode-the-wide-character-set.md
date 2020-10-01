---
title: 'Unicode: o conjunto de caracteres amplo'
description: Uma introdução ao conjunto de caracteres Unicode largos no tempo de execução do Microsoft C.
ms.topic: conceptual
ms.date: 11/04/2016
helpviewer_keywords:
- Unicode [C++], wide character set
- wide characters [C++], Unicode
ms.assetid: b6a05a21-59a5-4d30-8c85-2dbe185f7a74
ms.openlocfilehash: 751017a62a960eaf2afa2354a43a13971b89252a
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91590154"
---
# <a name="unicode-the-wide-character-set"></a>Unicode: o conjunto de caracteres amplo

Um caractere largo é um código de caractere multilíngue de 2 bytes. Qualquer caractere utilizado na computação moderna em todo o mundo, incluindo símbolos técnicos e caracteres de publicação especiais, pode ser representado de acordo com a especificação Unicode como caractere largo. Desenvolvido e mantido por um consórcio grande que inclui a Microsoft, o padrão Unicode agora é amplamente aceito.

Um caractere largo é do tipo **`wchar_t`** . Uma cadeia de caracteres largos é representada como uma **`wchar_t[]`** matriz. Você aponta para a matriz com um `wchar_t*` ponteiro. 

Você pode representar qualquer caractere ASCII como um caractere largo prefixando a letra `L` . Por exemplo, `L'\0'` é o caractere nulo de terminação (16 bits).

Você pode representar qualquer literal de cadeia de caracteres ASCII como um literal de cadeia de caracteres largos prefixando a letra `L` . Por exemplo, `L"Hello"`.

Geralmente, caracteres largos usam mais espaço na memória do que caracteres multibyte. Mas caracteres largos são mais rápidos de processar. Somente uma localidade pode ser representada por vez em uma codificação multibyte. Todos os conjuntos de caracteres no mundo são representados simultaneamente pela representação Unicode.

## <a name="see-also"></a>Confira também

[Internacionalização](../c-runtime-library/internationalization.md)\
[Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)
