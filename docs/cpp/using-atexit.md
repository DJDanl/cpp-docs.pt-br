---
title: "Usando atexit | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "atexit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função atexit"
ms.assetid: d28fda17-c3d4-4af6-ba44-f44886bbb237
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando atexit
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Com a função [atexit](../c-runtime-library/reference/atexit.md), você pode especificar uma função de processamento de saída que é executado antes do término do programa.  Nenhum objeto estático global inicializado antes da chamada a `atexit` é destruído antes da execução da função de processamento por saída.  
  
## Consulte também  
 [Considerações de término adicionais](../cpp/additional-termination-considerations.md)