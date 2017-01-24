---
title: "Intervalo de valores de inteiro | Microsoft Docs"
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
ms.assetid: 0e9c6161-8f3f-4bfb-9fcc-a6c8dc97d702
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Intervalo de valores de inteiro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 3.1.2.5** As representações e os conjuntos de valores de vários tipos de inteiros  
  
 Inteiros contêm 32 bits \(quatro bytes\).  Os inteiros com sinal são representados no formato de dois complementos.  O bit mais significativo contém o sinal: 1 para o negativo, 0 para o sinal positivo e zero.  Os valores são listados abaixo:  
  
|Tipo|Mínimo e máximo|  
|----------|---------------------|  
|**unsigned short**|0 a 65535|  
|`signed short`|–32768 a 32767|  
|`unsigned long`|0 a 4294967295|  
|**signed long**|–2147483648 a 2147483647|  
  
## Consulte também  
 [Inteiros](../Topic/Integers.md)