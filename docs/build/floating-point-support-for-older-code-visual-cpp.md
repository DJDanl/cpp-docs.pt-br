---
title: "Suporte de ponto flutuante para c&#243;digo anterior (Visual C++) | Microsoft Docs"
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
ms.assetid: a2a26b96-7bc2-418a-981a-51aa1a0294a2
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Suporte de ponto flutuante para c&#243;digo anterior (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O MMX e os registros de ponto flutuante a pilha \(MM0\-MM7\/ST0\-ST7\) são preservadas a alternâncias de contexto.  Não há nenhuma convenção de chamada explícita para esses registros.  O uso desses registra é proibido strict no código do kernel.  
  
## Consulte também  
 [Convenção de chamada](../build/calling-convention.md)