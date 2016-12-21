---
title: "2.6.1 master Construct | Microsoft Docs"
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
ms.assetid: c092064b-ea57-4d4e-9c99-a004d65656fe
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.6.1 master Construct
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **mestre** diretiva identifica uma construção que especifica um bloco estruturado que é executado pelo thread mestre da equipe.  A sintaxe do  **mestre** diretiva é o seguinte:  
  
```  
#pragma omp master new-line  
   structured-block  
```  
  
 Outros threads na equipe não executarão o bloco estruturado associado.  Não há nenhuma barreira implícita tanto na entrada ou saída da construção mestre.