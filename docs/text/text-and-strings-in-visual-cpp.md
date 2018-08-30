---
title: Texto e cadeias de caracteres no Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cf9133965a9009421c28f64c1f4157b4a6a6d6b3
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43223289"
---
# <a name="text-and-strings-in-visual-c"></a>Texto e cadeias de caracteres no Visual C++
Um aspecto importante do desenvolvimento de aplicativos para mercados internacionais é a representação adequada de conjuntos de caracteres local. O conjunto de caracteres ASCII define caracteres no intervalo 0x00 a 0x7F. Há outros conjuntos de caracteres, principalmente europeus, que definem os caracteres dentro do intervalo 0x00 a 0x7F de forma idêntica ao conjunto de caracteres ASCII e também definem um caractere estendido definido de 0x80 a 0xFF. Portanto, um conjunto de 8 bits, o caractere de byte único (SBCS) é suficiente para representar o conjunto de caracteres ASCII, bem como os conjuntos de caracteres de vários idiomas europeus. No entanto, alguns conjuntos de caracteres não europeus, como japonês Kanji, incluem muitos caracteres de um esquema de codificação de byte único pode representar e, portanto, exigem o conjunto de caracteres multibyte (MBCS) codificação.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)  
 Discute o suporte do Visual C++ para programação de Unicode e MBCS.  
  
 [Suporte para Unicode](../text/support-for-unicode.md)  
 Descreve o Unicode, uma especificação para dar suporte a todos os conjuntos de caracteres, incluindo conjuntos de caracteres que não podem ser representados em um único byte.  
  
 [Suporte para conjuntos de caracteres Multibyte (MBCS)](../text/support-for-multibyte-character-sets-mbcss.md)  
 Discute o MBCS, uma alternativa para o Unicode para dar suporte a conjuntos de caracteres, como japonês e chinês, o que não podem ser representado em um único byte.  
  
 [Mapeamentos de texto genéricos em Tchar.h](../text/generic-text-mappings-in-tchar-h.md)  
 Fornece os mapeamentos de texto genérico de específico da Microsoft para muitos tipos de dados, rotinas e outros objetos.  
  
 [Como converter entre diversos tipos de cadeias de caracteres](../text/how-to-convert-between-various-string-types.md)  
 Demonstra como converter diversos tipos de cadeia de caracteres do Visual C++ em outras cadeias de caracteres.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Internacionalização](../c-runtime-library/internationalization.md)  
 Discute o suporte internacional na biblioteca de tempo de execução C.  
  
 [Exemplos internacionais](https://msdn.microsoft.com/aa8d390c-cf4c-4dd8-9dea-74d81f93f2f8)  
 Fornece links para exemplos demonstram internacionalização no Visual C++.  
  
 [Idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)  
 Fornece as cadeias de caracteres de idioma e país/região na biblioteca de tempo de execução C.