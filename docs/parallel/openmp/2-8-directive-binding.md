---
title: "2.8 Directive Binding | Microsoft Docs"
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
ms.assetid: 7bdac45e-ab55-42f0-bd47-a2e3d5bbab3e
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.8 Directive Binding
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A vinculação dinâmica das diretivas deve atender às seguintes regras:  
  
-   O  **para**,  **seções**,  **único**,  **mestre**, e  **barreira** diretivas ligar dinamicamente delimitador  **paralela**, se houver um, independentemente do valor de qualquer  **se** cláusula que pode estar presente nessa diretiva.  Se nenhuma região paralela está atualmente sendo executada, as diretivas são executadas por uma equipe composta apenas o segmento principal.  
  
-   O  **ordenada** diretiva vincula a dinamicamente delimitador  **para**.  
  
-   O  **atômica** diretiva impõe o acesso exclusivo com relação a  **atômica** diretivas em todos os segmentos, não apenas a equipe atual.  
  
-   O  **crítica** diretiva impõe o acesso exclusivo com relação a  **crítica** diretivas em todos os segmentos, não apenas a equipe atual.  
  
-   Uma diretiva nunca pode vincular qualquer diretiva fora o mais próximo dinamicamente delimitador  **paralela**.