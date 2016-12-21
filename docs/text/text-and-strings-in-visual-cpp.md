---
title: "Texto e cadeias de caracteres no Visual C++ | Microsoft Docs"
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
  - "Caracteres ASCII [C++]"
  - "conjunto de caracteres [C++]"
  - "conjunto de caracteres [C++], sobre conjuntos de caracteres"
  - "conjunto de caracteres [C++], não europeu"
  - "globalização [C++]"
  - "globalização [C++], conjuntos de caracteres"
  - "aplicativos internacionais [C++], sobre aplicativos internacionais"
  - "Caracteres japoneses [C++]"
  - "Suporte a caracteres de Kanji [C++]"
  - "conjuntos de caracteres locais [C++]"
  - "localização [C++]"
  - "localização [C++], conjuntos de caracteres"
  - "MBCS [C++], programação internacional"
  - "suporte a vários idiomas [C++]"
  - "caracteres não europeus [C++]"
  - "portabilidade [C++]"
  - "portabilidade [C++], conjuntos de caracteres"
  - "programação [C++], internacional"
  - "traduzindo código [C++]"
  - "tradução [C++], conjuntos de caracteres"
  - "Unicode [C++]"
ms.assetid: a1bb27ac-abe5-4c6b-867d-f761d4b93205
caps.latest.revision: 12
caps.handback.revision: 12
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Texto e cadeias de caracteres no Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um aspecto importante de desenvolvendo aplicativos para mercados internacionais é suficiente a representação de conjuntos de caracteres locais.  O conjunto de caracteres ASCII define caracteres no intervalo 0x00 a 0x7F.  Há outros conjuntos de caracteres, primeiro europeus, que definem os caracteres dentro do intervalo 0x00 a 0x7F idêntica ao conjunto de caracteres ASCII e também definem um conjunto de caracteres estendida de 0x80 a 0xFF.  Assim, um de 8 bits, conjunto de caracteres de um byte \(SBCS\) é suficiente para representar o conjunto de caracteres ASCII, bem como os conjuntos de caracteres para muitos idiomas europeus.  No entanto, alguns conjuntos de caracteres não europeus, como o Kanji japonês, incluem muito mais caracteres de que um código de um byte pode representar, e requer como consequência codificação de conjunto \(MBCS\) de multibyte\- caractere.  
  
## Nesta seção  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)  
 Aborda o suporte do Visual C\+\+ para Unicode e programação de MBCS.  
  
 [Suporte para Unicode](../text/support-for-unicode.md)  
 Descreve Unicode, uma especificação para dar suporte a todos os conjuntos de caracteres, incluindo os conjuntos de caracteres que não podem ser representados em um único byte.  
  
 [Suporte a conjuntos de caracteres de vários bytes \(MBCS\)](../text/support-for-multibyte-character-sets-mbcss.md)  
 Discute o MBCS, uma alternativa para Unicode para conjuntos de caracteres de suporte, como chinês, japonês e que não pode ser representado em um único byte.  
  
 [Mapeamentos de Genérico\- texto em Tchar.h](../Topic/Generic-Text%20Mappings%20in%20Tchar.h.md)  
 Fornece mapeamentos microsoft específicos de genérico\- texto para muitos tipos de dados, rotinas, e outros objetos.  
  
 [Como converter entre diversos tipos de cadeia de caracteres](../Topic/How%20to:%20Convert%20Between%20Various%20String%20Types.md)  
 Demonstra como converter vários tipos de cadeia de caracteres do Visual C\+\+ em outras cadeias de caracteres.  
  
## Seções relacionadas  
 [Internacionalização](../c-runtime-library/internationalization.md)  
 Aborda o suporte internacional na biblioteca de tempo de execução C.  
  
 [Exemplos internacionais](http://msdn.microsoft.com/pt-br/aa8d390c-cf4c-4dd8-9dea-74d81f93f2f8)  
 Fornece links para exemplos que demonstram a internacionalização no Visual C\+\+.  
  
 [Idioma e país\/região de cadeias de caracteres](../c-runtime-library/locale-names-languages-and-country-region-strings.md)  
 Fornece o idioma e o país\/cadeias de caracteres da região na biblioteca de tempo de execução C.