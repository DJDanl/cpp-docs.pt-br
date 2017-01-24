---
title: "O que me custa derivar uma classe a partir de CObject? | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CObject, sobrecarga de classes derivadas"
ms.assetid: 9b92c98b-b3dd-48a7-9d24-c3b8554edf90
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# O que me custa derivar uma classe a partir de CObject?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A sobrecarga na derivação da classe [CObject](../Topic/CObject%20Class.md) é mínima.  A sua classe derivada herda apenas quatro funções virtuais e um único objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) .  
  
## Consulte também  
 [Classe CObject: perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)