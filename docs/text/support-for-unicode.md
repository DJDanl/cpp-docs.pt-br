---
title: "Suporte para Unicode | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "conjunto de caracteres [C++], Unicode"
  - "globalização [C++], conjuntos de caracteres"
  - "localização [C++], conjuntos de caracteres"
  - "tipos de dados portáteis [MFC]"
  - "Unicode [C++]"
  - "Unicode [C++], instalando suporte"
  - "caracteres largos [C++], sobre caracteres largos"
ms.assetid: 180f1d10-8543-4f79-85ce-293d3cb443bb
caps.latest.revision: 10
caps.handback.revision: 10
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Suporte para Unicode
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Unicode é uma especificação de suporte a todos os conjuntos de caracteres, inclusive aqueles que não podem ser representados apenas em byte.  Se estiver se programando para o mercado internacional, recomendamos que você utilize Unicode ou MBCSs \([conjuntos de caracteres multibyte](../text/support-for-multibyte-character-sets-mbcss.md)\) ou que ative seu programa para que seja possível compilá\-lo para qualquer uma dessas opções mudando apenas uma chave.  
  
 Um caractere largo é um código de caractere multilíngue de 2 bytes.  A maioria dos caracteres utilizados na computação moderna em todo o mundo, incluindo símbolos técnicos e caracteres de publicação especiais, pode ser representada de acordo com a especificação Unicode como caractere largo.  Caracteres que não podem ser representados em um único caractere largo podem ser representados em um par Unicode usando o recurso de substituto Unicode.  Como cada caractere largo é representado por um tamanho fixo de 16 bits, usar caracteres largos simplifica a programação com conjuntos de caracteres internacionais.  
  
 Uma cadeia de caracteres larga é representada como uma matriz **wchar\_t\[\]** e é indicada por um ponteiro `wchar_t*`.  Qualquer caractere ASCII pode ser representado como um caractere largo usando a letra L como prefixo do caractere.  Por exemplo, L'\\0' é o caractere largo de terminação **NULL** \(16 bits\).  Da mesma forma, qualquer literal da cadeia de caracteres ASCII pode ser representado como literal da cadeia de caracteres larga usando a letra L como prefixo do literal ASCII \(L"Hello"\).  
  
 Em geral, caracteres largos ocupam mais espaço na memória do que caracteres multibyte, mas eles são mais rápidos de processar.  Além disso, apenas um código de idioma pode ser representado por vez na codificação multibyte, enquanto que todos os conjuntos de caracteres do mundo são representados simultaneamente na representação Unicode.  
  
 A estrutura de MFC é completamente habilitada para Unicode, e o MFC realiza a ativação de Unicode usando macros portáteis, como mostrado na tabela a seguir.  
  
### Tipos de dados portáteis no MFC  
  
|Tipo de dados não portátil|Substituído por este macro|  
|--------------------------------|--------------------------------|  
|`char`|\_**TCHAR**|  
|**char\***, **LPSTR \(tipo de dados Win32\)**|`LPTSTR`|  
|**const char\*, LPCSTR \(tipo de dados Win32\)**|`LPCTSTR`|  
  
 A classe `CString` usa **\_TCHAR** como base e oferece construtores e operadores para conversões fáceis.  A maioria das operações com cadeias para Unicode pode ser gravada com a mesma lógica usada para lidar com o conjunto de caracteres ANSI do Windows, exceto pelo fato de que a unidade básica de operação é um caractere de 16 bits, ao invés de um byte de 8 bits.  Diferente de trabalhar com conjuntos de caractere multibyte, você não precisa \(e não deve\) tratar um caractere Unicode como se ele fosse dois bytes distintos.  
  
## O que você deseja fazer?  
  
-   [Instalar suporte a Unicode via MFC](../mfc/unicode-in-mfc.md)  
  
-   [Habilitar Unicode em meu programa](../text/international-enabling.md)  
  
-   [Habilitar Unicode e MBCS em meu programa](../text/internationalization-strategies.md)  
  
-   [Usar Unicode para criar um programa internacionalizado](../text/unicode-programming-summary.md)  
  
-   [Aprender sobre os benefícios do Unicode, inclusive sobre como o uso de Unicode torna meu programa mais eficiente no Windows 2000](../text/benefits-of-character-set-portability.md)  
  
-   [Usar wmain para transferir argumentos de caractere largo para meu programa](../text/support-for-using-wmain.md)  
  
-   [Ver um resumo da programação Unicode](../text/unicode-programming-summary.md)  
  
-   [Aprender sobre mapeamentos de texto genérico para portabilidade de largura de byte](../Topic/Generic-Text%20Mappings%20in%20Tchar.h.md)  
  
## Consulte também  
 [Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)   
 [Suporte para usar wmain](../text/support-for-using-wmain.md)