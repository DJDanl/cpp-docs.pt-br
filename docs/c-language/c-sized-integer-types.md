---
title: Tipos de inteiro dimensionados C | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: sized integer types
ms.assetid: 0d6199b4-d0ab-4e8c-a769-785f5afb92eb
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 609d932b92d40fd4e080d12d13a8872417b56440
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-sized-integer-types"></a>Tipos de inteiro dimensionados C
**Seção específica da Microsoft**  
  
 Suporte dos recursos do Microsoft C para tipos de inteiros dimensionados. Você pode declarar variáveis de inteiros de 8, 16, 32 ou 64 bits usando o especificador de tipo __int*n*, em que *n* é o tamanho, em bits, da variável de inteiro. O valor de *n* pode ser 8, 16, 32 ou 64. O exemplo a seguir declara uma variável de cada um dos quatro tipos de inteiros dimensionados:  
  
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