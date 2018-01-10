---
title: "Conjuntos de caracteres de byte único e multibyte | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: c.character.multibyte
dev_langs: C++
helpviewer_keywords:
- SBCS (single byte character set)
- MBCS [C++], about MBCS
- character sets [C++], multibyte
- character sets [C++], single byte
ms.assetid: 2cbc78ea-33c0-4cfb-b0df-7ce2458431ce
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b1ee6738d55f2a925c510ff342cd289f26bc8669
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="single-byte-and-multibyte-character-sets"></a>Conjuntos de caracteres de byte único e multibyte
O conjunto de caracteres ASCII define caracteres no intervalo 0x00 – 0x7F. Há uma série de outros conjuntos de caracteres, principalmente europeus, que definem os caracteres dentro do intervalo 0x00 – 0x7F de forma idêntica ao conjunto de caracteres ASCII e também definem um conjunto de caracteres estendido de 0x80 – 0xFF. Portanto, um conjunto de caracteres de byte único de 8 bits (`SBCS`) é suficiente para representar o conjunto de caracteres ASCII e também os conjuntos de caracteres de vários idiomas europeus. No entanto, alguns conjuntos de caracteres não europeus, como japonês Kanji, incluem muitos caracteres além dos que podem ser representados em um esquema de codificação de byte único e, portanto, exigem a codificação de um conjunto de caracteres multibyte (`MBCS`).  
  
> [!NOTE]
>  Muitos rotinas de `SBCS` da biblioteca de tempo de execução do Microsoft tratam bytes, caracteres e cadeias de caracteres multibyte apropriadamente. Muitos conjuntos de caracteres multibyte definem o conjunto de caracteres ASCII como um subconjunto. Em muitos conjuntos de caracteres multibyte, cada caractere no intervalo 0x00 – 0x7F é idêntico ao caractere que tem o mesmo valor no conjunto de caracteres ASCII. Por exemplo, nas cadeias de caracteres `ASCII` e `MBCS`, o caractere de um byte `NULL` ('\0') tem valor 0x00 e indica o caractere nulo de terminação.  
  
 Um conjunto de caracteres multibyte pode consistir em caracteres de um byte e dois bytes. Portanto, uma cadeia de caracteres multibyte pode conter uma mistura de caracteres de byte único e duplo. Um caractere multibyte de dois bytes tem um byte inicial e um byte final. Em um conjunto de caracteres multibyte, os bytes iniciais ficam dentro de um determinado intervalo, assim como os bytes finais. Quando esses intervalos se sobrepõem, pode ser necessário avaliar o contexto específico para determinar se um byte está funcionando como byte inicial ou byte final.  
  
## <a name="see-also"></a>Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)