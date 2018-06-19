---
title: 'Unicode: o conjunto de caracteres amplo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- c.international
dev_langs:
- C++
helpviewer_keywords:
- Unicode [C++], wide character set
- wide characters [C++], Unicode
ms.assetid: b6a05a21-59a5-4d30-8c85-2dbe185f7a74
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4fcd1c874c1701f471026deec73ab596971d3ad4
ms.sourcegitcommit: 6e3cf8df676d59119ce88bf5321d063cf479108c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/22/2018
ms.locfileid: "34450791"
---
# <a name="unicode-the-wide-character-set"></a>Unicode: o conjunto de caracteres amplo

Um caractere largo é um código de caractere multilíngue de 2 bytes. Qualquer caractere utilizado na computação moderna em todo o mundo, incluindo símbolos técnicos e caracteres de publicação especiais, pode ser representado de acordo com a especificação Unicode como caractere largo. Desenvolvido e mantido por um consórcio grande que inclui a Microsoft, o padrão Unicode agora é amplamente aceito.

Um caractere largo é do tipo **wchar_t**. Uma cadeia de caracteres larga é representada como uma matriz **wchar_t[]** e é indicada por um ponteiro `wchar_t*`. Qualquer caractere ASCII pode ser representado como um caractere largo usando a letra **L** como prefixo do caractere. Por exemplo, L'\0' é o caractere nulo largo de terminação (16 bits). Da mesma forma, qualquer literal da cadeia de caracteres ASCII pode ser representado como literal da cadeia de caracteres largos usando a letra L como prefixo do literal ASCII (L"Hello").

Em geral, caracteres largos ocupam mais espaço na memória do que caracteres multibyte, mas eles são mais rápidos de processar. Além disso, apenas um código de idioma pode ser representado por vez na codificação multibyte, enquanto que todos os conjuntos de caracteres do mundo são representados simultaneamente na representação Unicode.

## <a name="see-also"></a>Consulte também

[Internacionalização](../c-runtime-library/internationalization.md)<br/>
[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
