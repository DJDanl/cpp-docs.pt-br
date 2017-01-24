---
title: "Convers&#227;o de tipo de objetos de classe MFC | Microsoft Docs"
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
  - "vc.mfc.macros.classes"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "convertendo tipos"
  - "Macros , convertendo ponteiros"
  - "Macros , conversão de tipo"
  - "ponteiros, conversão de tipo"
  - "conversões de tipo"
ms.assetid: e138465e-c35f-4e84-b788-bd200ccf2f0e
caps.latest.revision: 15
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#227;o de tipo de objetos de classe MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Macros de conversão de tipo fornecem uma maneira para converter um ponteiro fornecido a um ponteiro que aponta para um objeto de classe específica, com ou sem verificar se a conversão é válido.  
  
 A tabela a seguir lista as macros de conversão de tipo MFC.  
  
### Macros que os ponteiros convertidos em objetos de classificação MFC  
  
|||  
|-|-|  
|[DYNAMIC\_DOWNCAST](../Topic/DYNAMIC_DOWNCAST.md)|Converte um ponteiro para um ponteiro para um objeto da classe em verifique se a conversão é válido.|  
|[STATIC\_DOWNCAST](../Topic/STATIC_DOWNCAST.md)|Converte um ponteiro para um objeto de uma classe em um ponteiro de um tipo relacionada.  Em uma compilação de depuração, faz **DECLARAR** se o objeto não for um tipo “” do tipo de destino.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)