---
title: Tipos de inteiro dimensionados C | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- sized integer types
ms.assetid: 0d6199b4-d0ab-4e8c-a769-785f5afb92eb
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: d4e607f396262c3de6601bcedc4c49cd1ae2200d
ms.lasthandoff: 02/25/2017

---
# <a name="c-sized-integer-types"></a>Tipos de inteiro dimensionados C
**Seção específica da Microsoft**  
  
 Suporte dos recursos do Microsoft C para tipos de inteiros dimensionados. Você pode declarar variáveis de inteiro de 8, 16, 32 ou 64 bits usando o especificador de tipo __int*n*, em que *n* é o tamanho, em bits, da variável de inteiro. O valor de *n* pode ser 8, 16, 32 ou 64. O exemplo a seguir declara uma variável de cada um dos quatro tipos de inteiros dimensionados:  
  
```  
__int8 nSmall;      // Declares 8-bit integer  
__int16 nMedium;    // Declares 16-bit integer  
__int32 nLarge;     // Declares 32-bit integer  
__int64 nHuge;      // Declares 64-bit integer  
```  
  
 Os primeiros três tipos de inteiros dimensionados são sinônimos para os tipos ANSI que têm o mesmo tamanho, e são úteis para escrever o código portátil que se comporta de forma idêntica em várias plataformas. Observe que o tipo de dados __int8 é sinônimo do tipo char, \__int16 é sinônimo do tipo short e \__int32 é sinônimo do tipo int. O tipo \__int64 não tem contraparte ANSI equivalente.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)
