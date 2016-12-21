---
title: "Acesso fortemente tipado a controles sem assistentes de c&#243;digo | Microsoft Docs"
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
  - "controles de caixas de diálogo, acessando"
  - "caixas de diálogo, acessando controles"
ms.assetid: 325b4927-d49b-42b4-8e0b-fc84f31fb059
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acesso fortemente tipado a controles sem assistentes de c&#243;digo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A primeira abordagem para criar o acesso fortemente tipado nos controles usa uma função de membro embutida para converter o tipo de retorno de função de membro de `CWnd``GetDlgItem` da classe com o tipo apropriado de controle C\+\+, como neste exemplo:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#50](../mfc/codesnippet/CPP/type-safe-access-to-controls-without-code-wizards_1.cpp)]  
  
 Você pode usar essa função de membro para acessar o controle de uma maneira fortemente tipado com o código semelhante ao seguinte:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#51](../mfc/codesnippet/CPP/type-safe-access-to-controls-without-code-wizards_2.cpp)]  
  
## Consulte também  
 [Acesso fortemente tipado a controles em uma caixa de diálogo](../Topic/Type-Safe%20Access%20to%20Controls%20in%20a%20Dialog%20Box.md)   
 [Acesso fortemente tipado a controles com assistentes de código](../mfc/type-safe-access-to-controls-with-code-wizards.md)