---
title: "Campos de bits | Microsoft Docs"
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
  - "campos de bits"
ms.assetid: e9a1010d-1e1b-487f-9943-3c574e08f544
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Campos de bits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os campos de bits de estrutura são limitados a 64 bits e podem ser assinado de int, int de tipo sem sinal, de int64, ou de um int64 sem sinal.  Os campos de bits que cruzam o limite de tipo saltarão bits para alinhar o bitfield ao alinhamento de tipo seguir.  Por exemplo, os bitfields inteiros não podem cruzar o limite de 32 bits.  
  
## Consulte também  
 [Tipos e armazenamento](../build/types-and-storage.md)