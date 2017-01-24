---
title: "Tipos de inteiro dimensionados C | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "tipos de inteiros dimensionados"
ms.assetid: 0d6199b4-d0ab-4e8c-a769-785f5afb92eb
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipos de inteiro dimensionados C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Suporte dos recursos do Microsoft C para tipos de inteiros dimensionados.  Você pode declarar variáveis de inteiro de 8, 16, 32 ou 64 bits usando o especificador de tipo \_\_int*n*, onde *n* é o tamanho, em bits, da variável de inteiro.  O valor de *n* pode ser 8, 16, 32 ou 64.  O exemplo a seguir declara uma variável de cada um dos quatro tipos de inteiros dimensionados:  
  
```  
__int8 nSmall;      // Declares 8-bit integer  
__int16 nMedium;    // Declares 16-bit integer  
__int32 nLarge;     // Declares 32-bit integer  
__int64 nHuge;      // Declares 64-bit integer  
```  
  
 Os primeiros três tipos de inteiros dimensionados são sinônimos para os tipos ANSI que têm o mesmo tamanho, e são úteis para escrever o código portátil que se comporta de forma idêntica em várias plataformas.  Observe que o tipo de dados \_\_int8 é sinônimo do tipo char, \_\_int16 é sinônimo do tipo short, e \_\_int32 é sinônimo do tipo int.  O tipo \_\_int64 não tem contraparte ANSI equivalente.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)