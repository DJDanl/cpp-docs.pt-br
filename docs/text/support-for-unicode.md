---
title: Suporte para Unicode
ms.date: 01/09/2018
helpviewer_keywords:
- globalization [C++], character sets
- portable data types [MFC]
- Unicode [C++]
- wide characters [C++], about wide characters
- character sets [C++], Unicode
- localization [C++], character sets
- Unicode [C++], installing support
ms.openlocfilehash: 0b61407920a0ce35a1c6a8466458736e983e271e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168558"
---
# <a name="support-for-unicode"></a>Suporte para Unicode

O Unicode é uma especificação para dar suporte a todos os conjuntos de caracteres, incluindo aqueles que não podem ser representados em um único byte.  Se você estiver programando para um mercado internacional, recomendamos o uso de Unicode ou um [conjunto de caracteres multibyte](../text/support-for-multibyte-character-sets-mbcss.md) (MBCS). Ou então, codifique seu programa para que você possa compilá-lo para qualquer um deles alterando uma opção.

Um caractere largo é um código de caractere multilíngue de 2 bytes. Dezenas de milhares de caracteres, que compreendem quase todos os caracteres usados na computação moderna em todo o mundo, incluindo símbolos técnicos e caracteres de publicação especiais, podem ser representados de acordo com a especificação Unicode como um único caractere largo codificado por usando UTF-16. Os caracteres que não podem ser representados em apenas um caractere largo podem ser representados em um par Unicode usando o recurso de par substituto Unicode. Como quase todos os caracteres em uso comum são representados em UTF-16 em um único caractere largo de 16 bits, o uso de caracteres largos simplifica a programação com conjuntos de caracteres internacionais. Caracteres largos codificados usando UTF-16LE (para little-endian) são o formato de caractere nativo para o Windows.

Uma cadeia de caracteres largos é representada como uma matriz `wchar_t[]` e é indicada por um ponteiro `wchar_t*`. Qualquer caractere ASCII pode ser representado como um caractere largo usando a letra L como prefixo do caractere. Por exemplo, L'\0' é o caractere largo de terminação NULL (16 bits). Da mesma forma, qualquer literal da cadeia de caracteres ASCII pode ser representado como literal da cadeia de caracteres larga usando a letra L como prefixo do literal ASCII (L"Hello").

Em geral, caracteres largos ocupam mais espaço na memória do que caracteres multibyte, mas eles são mais rápidos de processar. Além disso, apenas uma localidade pode ser representada por vez em uma codificação multibyte, enquanto que todos os conjuntos de caracteres no mundo são representados simultaneamente pela representação Unicode.

A estrutura de MFC é completamente habilitada para Unicode, e o MFC realiza a ativação de Unicode usando macros portáteis, como mostrado na tabela a seguir.

## <a name="portable-data-types-in-mfc"></a>Tipos de dados portáteis no MFC

|Tipo de dados não portátil|Substituído por este macro|
|-----------------------------|----------------------------|
|`char`, `wchar_t`|`_TCHAR`|
|`char*`, `LPSTR` (tipo de dados do Win32), `LPWSTR`|`LPTSTR`|
|`const char*`, `LPCSTR` (tipo de dados do Win32), `LPCWSTR`|`LPCTSTR`|

A classe `CString` usa `_TCHAR` como base e fornece construtores e operadores para conversões fáceis. A maioria das operações com cadeias para Unicode pode ser gravada com a mesma lógica usada para lidar com o conjunto de caracteres ANSI do Windows, exceto pelo fato de que a unidade básica de operação é um caractere de 16 bits, ao invés de um byte de 8 bits. Diferente de trabalhar com conjuntos de caractere multibyte, você não precisa (e não deve) tratar um caractere Unicode como se ele fosse dois bytes distintos. No entanto, você precisa lidar com a possibilidade de um único caractere representado por um par substituto de caracteres largos. Em geral, não escreva o código que assume que o comprimento de uma cadeia de caracteres é igual ao número de caracteres, seja limitado ou largo, que ele contém.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Usar o MFC Unicode e o conjunto de caracteres multibyte (MBCS) suporte](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md)

- [Habilitar Unicode em meu programa](../text/international-enabling.md)

- [Habilitar Unicode e MBCS em meu programa](../text/internationalization-strategies.md)

- [Usar o Unicode para criar um programa internacionalizado](../text/unicode-programming-summary.md)

- [Conheça os benefícios do Unicode](../text/benefits-of-character-set-portability.md)

- [Usar wmain para que eu possa passar argumentos de caracteres largos para o meu programa](../text/support-for-using-wmain.md)

- [Veja um resumo da programação Unicode](../text/unicode-programming-summary.md)

- [Saiba mais sobre mapeamentos de texto genérico para portabilidade de largura de byte](../text/generic-text-mappings-in-tchar-h.md)

## <a name="see-also"></a>Confira também

[Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)<br/>
[Suporte para usar wmain](../text/support-for-using-wmain.md)
