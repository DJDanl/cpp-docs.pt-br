---
title: Suporte para Unicode | Microsoft Docs
ms.custom: 
ms.date: 1/09/2018
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- globalization [C++], character sets
- portable data types [MFC]
- Unicode [C++]
- wide characters [C++], about wide characters
- character sets [C++], Unicode
- localization [C++], character sets
- Unicode [C++], installing support
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 110d99cd6bf745f20db0a92a87189fb8add68e9b
ms.sourcegitcommit: 56f6fce7d80e4f61d45752f4c8512e4ef0453e58
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/12/2018
---
# <a name="support-for-unicode"></a>Suporte para Unicode

Unicode é uma especificação para dar suporte a todos os conjuntos de caracteres, incluindo aqueles que não pode ser representado em apenas um byte (ou seja, a maioria deles). Se você estiver programando para um mercado internacional, recomendamos que você use o Unicode ou uma [conjunto de caracteres multibyte](../text/support-for-multibyte-character-sets-mbcss.md) (MBCS), ou o programa de código para construí-lo para um alterando uma opção.

Um caractere largo é um código de caractere multilíngue de 2 bytes. Dezenas de milhares de caracteres, que consiste em quase todos os caracteres usados na computação moderna em todo o mundo, incluindo símbolos técnicos e caracteres especiais de publicação, podem ser representadas de acordo com a especificação Unicode como um todo o único caractere codificado por usando UTF-16. Caracteres que não podem ser representados em apenas um caractere largo podem ser representados em um par de Unicode usando o recurso de par de substitutos de Unicode. Como quase todos os caracteres de uso comum é representada em UTF-16 em um caractere largo único de 16 bits, usar caracteres largos simplifica a programação com conjuntos de caracteres internacionais. Caracteres largos codificados usando UTF-16LE (little endian) são o formato de caractere nativo do Windows.

Uma cadeia de caracteres largos é representada como uma matriz `wchar_t[]` e é indicada por um ponteiro `wchar_t*`. Qualquer caractere ASCII pode ser representado como um caractere largo usando a letra L como prefixo do caractere. Por exemplo, '\0' está a terminação ampla (16 bits) **nulo** caracteres. Da mesma forma, qualquer literal da cadeia de caracteres ASCII pode ser representado como literal da cadeia de caracteres larga usando a letra L como prefixo do literal ASCII (L"Hello").

Em geral, caracteres largos ocupam mais espaço na memória do que caracteres multibyte, mas eles são mais rápidos de processar. Além disso, somente um local pode ser representado por vez em uma codificação multibyte, enquanto o conjunto de todos os caracteres no mundo são representados simultaneamente, a representação Unicode.

A estrutura de MFC é completamente habilitada para Unicode, e o MFC realiza a ativação de Unicode usando macros portáteis, como mostrado na tabela a seguir.

## <a name="portable-data-types-in-mfc"></a>Tipos de dados portáteis no MFC

|Tipo de dados não portátil|Substituído por este macro|
|-----------------------------|----------------------------|
|`char`, `wchar_t`|`_TCHAR`|
|`char*`, `LPSTR` (Tipo de dados de Win32),`LPWSTR`|`LPTSTR`|
|`const char*`, `LPCSTR` (Tipo de dados de Win32),`LPCWSTR`|`LPCTSTR`|

Classe `CString` usa `_TCHAR` como base e fornece construtores e operadores de conversões fácil. A maioria das operações com cadeias para Unicode pode ser gravada com a mesma lógica usada para lidar com o conjunto de caracteres ANSI do Windows, exceto pelo fato de que a unidade básica de operação é um caractere de 16 bits, ao invés de um byte de 8 bits. Diferente de trabalhar com conjuntos de caractere multibyte, você não precisa (e não deve) tratar um caractere Unicode como se ele fosse dois bytes distintos. No entanto,, você precisa lidar com a possibilidade de um único caractere representado por um par substituto de caracteres largos. Em geral, não escreva código que pressupõe que o comprimento de uma cadeia de caracteres é o mesmo que o número de caracteres, se estreita ou grande, o que ele contém.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Usar MFC suporte a Unicode e caracteres Multibyte (MBCS) do conjunto](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md)

- [Habilitar o Unicode no meu programa](../text/international-enabling.md)

- [Habilitar o Unicode e MBCS no meu programa](../text/internationalization-strategies.md)

- [Usar Unicode para criar um programa internacionalizado](../text/unicode-programming-summary.md)

- [Saiba mais sobre os benefícios do Unicode, incluindo como o uso do Unicode torna meu programa mais eficiente no Windows 2000](../text/benefits-of-character-set-portability.md)

- [Usar wmain, portanto, pode passar argumentos de caractere largo para meu programa](../text/support-for-using-wmain.md)

- [Ver um resumo de programação Unicode](../text/unicode-programming-summary.md)

- [Saiba mais sobre mapeamentos de texto genérico para a portabilidade de largura de bytes](../text/generic-text-mappings-in-tchar-h.md)

## <a name="see-also"></a>Consulte também

[Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)  
[Suporte para usar wmain](../text/support-for-using-wmain.md)  
