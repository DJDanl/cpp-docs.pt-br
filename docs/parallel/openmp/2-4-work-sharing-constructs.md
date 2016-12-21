---
title: "2.4 Work-sharing Constructs | Microsoft Docs"
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
ms.assetid: 25bb4ded-8466-4daa-a863-766b5a99b995
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.4 Work-sharing Constructs
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma construção de compartilhamento de trabalho distribui a execução da instrução associada entre os membros da equipe que encontrar a ele.  As diretivas de compartilhamento de trabalho não iniciará a novos segmentos, e não há nenhuma barreira implícita na entrada para uma construção de compartilhamento de trabalho.  
  
 A seqüência de compartilhamento de trabalho constrói e  **barreira** encontradas as diretivas devem ser iguais para todos os threads em uma equipe.  
  
 O OpenMP define as seguintes construções de compartilhamento de trabalho e eles são descritos nas seções a seguir:  
  
-   **para** diretiva  
  
-   **seções** diretiva  
  
-   **único** diretiva