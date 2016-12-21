---
title: "Tipos escalares | Microsoft Docs"
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
ms.assetid: 07c9195e-b6c7-4083-8ef0-8a93032e4d1e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Tipos escalares
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Embora o acesso de dados pode vir de qualquer alinhamento, recomenda\-se que os dados sejam alinhados no seu limite natural para evitar a perda de desempenho \(ou um múltiplo dele\). Enumerações são inteiros constantes e são tratadas como inteiros de 32 bits. A tabela a seguir descreve a definição de tipo e o armazenamento recomendado para ela relacionada ao alinhamento usando os seguintes valores de alinhamento:  
  
-   Byte – 8 bits  
  
-   Word – 16 bits  
  
-   Palavra dupla – 32 bits  
  
-   Word Quad – 64 bits  
  
-   Octa Word – 128 bits  
  
|||||  
|-|-|-|-|  
|Tipo escalar|Tipo de dados C|Tamanho de armazenamento \(em bytes\)|Alinhamento recomendado|  
|**INT8**|`char`|1|Bytes|  
|**UINT8**|`unsigned char`|1|Bytes|  
|**INT16**|**short**|2|Palavra|  
|**UINT16**|**unsigned short**|2|Palavra|  
|**INT32**|**int, long**|4|Palavras duplas|  
|**UINT32**|**unsigned int, unsigned long**|4|Palavras duplas|  
|**INT64**|`__int64`|8|Quadword|  
|**UINT64**|**Int64 sem sinal**|8|Quadword|  
|**FP32 \(precisão simples\)**|**float**|4|Palavras duplas|  
|**FP64 \(precisão dupla\)**|**double**|8|Quadword|  
|**PONTEIRO**|**\***|8|Quadword|  
|`__m64`|**struct m64**|8|Quadword|  
|`__m128`|**struct m128**|16|Octaword|  
  
## Consulte também  
 [Tipos e armazenamento](../build/types-and-storage.md)