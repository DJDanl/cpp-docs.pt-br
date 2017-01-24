---
title: "Conjuntos de caracteres de byte &#250;nico e multibyte | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.character.multibyte"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "conjunto de caracteres [C++], multibyte"
  - "conjunto de caracteres [C++], byte único"
  - "MBCS [C++], sobre MBCS"
  - "SBCS (conjunto de caracteres de byte único)"
ms.assetid: 2cbc78ea-33c0-4cfb-b0df-7ce2458431ce
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Conjuntos de caracteres de byte &#250;nico e multibyte
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O conjunto de caracteres ASCII define caracteres no intervalo 0x00 – 0x7F.  Há vários outros conjuntos de caracteres, primeiro europeus, que definem os caracteres dentro do intervalo 0x00 – 0x7F idêntica ao conjunto de caracteres ASCII e também define um conjunto de caracteres estendida de 0x80 – 0xFF.  Para um de 8 bits, conjunto de caracteres de um byte \(`SBCS`\) é suficiente para representar o conjunto de caracteres ASCII bem como os conjuntos de caracteres para muitos idiomas europeus.  No entanto, alguns conjuntos de caracteres não europeus, como o Kanji japonês, incluem muito mais caracteres de que pode ser representado em um código de um byte e, consequentemente exigem codificação de conjunto de multibyte\- caractere \(`MBCS`\).  
  
> [!NOTE]
>  Muitas rotinas de `SBCS` em bytes, em caracteres, e nas cadeias de caracteres multibyte do identificador da biblioteca de tempo de execução Microsoft conforme apropriado.  Muitos conjuntos de multibyte\- caractere definem o conjunto de caracteres ASCII como um subconjunto.  Em muitos conjuntos de caracteres multibyte, cada caractere no intervalo 0x00 – 0x7F é idêntico ao caractere que tem o mesmo valor no conjunto de caracteres ASCII.  Por exemplo, em `ASCII` e em cadeias de caracteres de `MBCS` , o caractere de `NULL` de um byte \(“\\ " 0\) tem o valor 0x00 e indica o caractere nulo sendo encerrado.  
  
 Um conjunto de caracteres multibyte pode consistir em um byte e em caracteres de dois bytes.  Para uma cadeia de caracteres de multibyte\- caractere pode conter uma mistura de byte único e de caracteres de dois bytes.  Um caracteres de dois bytes multibyte tem um byte inicial e um byte final.  Em um conjunto específico de multibyte\- caractere, os bytes iniciais estão em um determinado intervalo, como faz os bytes finais.  Quando esses intervalos sobrepostos, pode ser necessário avaliar o contexto específico para determinar se um byte determinado está funcionando como um byte inicial ou um byte final.  
  
## Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)