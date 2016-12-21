---
title: "2.9 Directive Nesting | Microsoft Docs"
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
ms.assetid: 6565a43c-fd2d-4366-8322-8d75e1b06600
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.9 Directive Nesting
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Aninhamento dinâmico das diretivas deve atender às seguintes regras:  
  
-   A  **paralela** diretiva dinamicamente dentro de outro  **paralela** logicamente estabelece uma nova equipe, que é composta de apenas o segmento atual, a menos que o paralelismo de aninhado é ativada.  
  
-   **para**,  **seções**, e  **único** diretivas que ligar para o mesmo  **paralela** não são permitidas aninhado em si.  
  
-   **crítica** diretivas com o mesmo nome não pode ser aninhada dentro de si.  Observe que essa restrição não é suficiente para evitar o deadlock.  
  
-   **para**,  **seções**, e  **único** diretivas não são permitidas na extensão dinâmica de  **crítica**,  **ordenada**, e  **mestre** regiões se as diretivas de ligação com o mesmo  **paralela** como as regiões.  
  
-   **barreira** diretivas não são permitidas na extensão dinâmica de  **para**,  **ordenada**,  **seções**,  **único**,  **mestre**, e  **crítica** regiões se as diretivas de ligação com o mesmo  **paralela** como as regiões.  
  
-   **mestre** diretivas não são permitidas na extensão dinâmica de  **para**,  **seções**, e  **único** diretivas se a  **mestre** diretivas ligar para o mesmo  **paralela** como as diretivas de compartilhamento de trabalho.  
  
-   **ordenada** diretivas não são permitidas na extensão dinâmica de  **crítica** regiões se as diretivas de ligação com o mesmo  **paralela** como as regiões.  
  
-   Qualquer diretiva que é permitida quando executada dinamicamente dentro de uma região paralela também é permitida quando executado fora de uma região paralela.  Quando executada dinamicamente fora de uma região paralela especificado pelo usuário, a diretiva é executada por uma equipe composta apenas o segmento principal.