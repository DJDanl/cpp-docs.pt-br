---
title: Suporte para Unicode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
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
ms.assetid: 180f1d10-8543-4f79-85ce-293d3cb443bb
caps.latest.revision: "10"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 150f161b71efc07bc7b5a08d79e17fac0dea7931
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="support-for-unicode"></a>Suporte para Unicode
Unicode é uma especificação de suporte a todos os conjuntos de caracteres, inclusive aqueles que não podem ser representados apenas em byte. Se você estiver programando para um mercado internacional, recomendamos que você use o Unicode ou [conjuntos de caracteres multibyte](../text/support-for-multibyte-character-sets-mbcss.md) (MBCSs), ou habilitar o programa para construí-lo para um alterando uma opção.  
  
 Um caractere largo é um código de caractere multilíngue de 2 bytes. A maioria dos caracteres utilizados na computação moderna em todo o mundo, incluindo símbolos técnicos e caracteres de publicação especiais, pode ser representada de acordo com a especificação Unicode como caractere largo. Caracteres que não podem ser representados em um único caractere largo podem ser representados em um par Unicode usando o recurso de substituto Unicode. Como cada caractere largo é representado por um tamanho fixo de 16 bits, usar caracteres largos simplifica a programação com conjuntos de caracteres internacionais.  
  
 Uma cadeia de caracteres largos é representada como um **[wchar_t]** matriz e é apontada por um `wchar_t*` ponteiro. Qualquer caractere ASCII pode ser representado como um caractere largo usando a letra L como prefixo do caractere. Por exemplo, '\0' está a terminação ampla (16 bits) **nulo** caracteres. Da mesma forma, qualquer literal da cadeia de caracteres ASCII pode ser representado como literal da cadeia de caracteres larga usando a letra L como prefixo do literal ASCII (L"Hello").  
  
 Em geral, caracteres largos ocupam mais espaço na memória do que caracteres multibyte, mas eles são mais rápidos de processar. Além disso, apenas um código de idioma pode ser representado por vez na codificação multibyte, enquanto que todos os conjuntos de caracteres do mundo são representados simultaneamente na representação Unicode.  
  
 A estrutura de MFC é completamente habilitada para Unicode, e o MFC realiza a ativação de Unicode usando macros portáteis, como mostrado na tabela a seguir.  
  
### <a name="portable-data-types-in-mfc"></a>Tipos de dados portáteis no MFC  
  
|Tipo de dados não portátil|Substituído por este macro|  
|-----------------------------|----------------------------|  
|`char`|_**TCHAR**|  
|**char\***, **LPSTR (tipo de dados de Win32)**|`LPTSTR`|  
|**char const\*, LPCSTR (tipo de dados de Win32)**|`LPCTSTR`|  
  
 Classe `CString` usa **TCHAR** como base e fornece construtores e operadores de conversões fácil. A maioria das operações com cadeias para Unicode pode ser gravada com a mesma lógica usada para lidar com o conjunto de caracteres ANSI do Windows, exceto pelo fato de que a unidade básica de operação é um caractere de 16 bits, ao invés de um byte de 8 bits. Diferente de trabalhar com conjuntos de caractere multibyte, você não precisa (e não deve) tratar um caractere Unicode como se ele fosse dois bytes distintos.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Instalar o suporte a Unicode por meio do MFC](../mfc/unicode-in-mfc.md)  
  
-   [Habilitar o Unicode no meu programa](../text/international-enabling.md)  
  
-   [Habilitar o Unicode e MBCS no meu programa](../text/internationalization-strategies.md)  
  
-   [Usar Unicode para criar um programa internacionalizado](../text/unicode-programming-summary.md)  
  
-   [Saiba mais sobre os benefícios do Unicode, incluindo como o uso do Unicode torna meu programa mais eficiente no Windows 2000](../text/benefits-of-character-set-portability.md)  
  
-   [Usar wmain, portanto, pode passar argumentos de caractere largo para meu programa](../text/support-for-using-wmain.md)  
  
-   [Ver um resumo de programação Unicode](../text/unicode-programming-summary.md)  
  
-   [Saiba mais sobre mapeamentos de texto genérico para a portabilidade de largura de bytes](../text/generic-text-mappings-in-tchar-h.md)  
  
## <a name="see-also"></a>Consulte também  
 [Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)   
 [Suporte para usar wmain](../text/support-for-using-wmain.md)