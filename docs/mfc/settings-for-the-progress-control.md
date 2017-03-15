---
title: "Configura&#231;&#245;es para o controle de progresso | Microsoft Docs"
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
  - "Classe CProgressCtrl, configurações"
  - "controles de andamento [C++], configurações"
ms.assetid: f4616e91-74fa-4000-ba0d-d3ddc0ee075b
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Configura&#231;&#245;es para o controle de progresso
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As configurações básicas para o controle do progresso \([CProgressCtrl](../mfc/reference/cprogressctrl-class.md)\) é o intervalo e a posição atual.  O intervalo representa a duração inteira da operação.  A posição atual representa o progresso que seu aplicativo tiver feito para concluir a operação.  Algumas alterações ao intervalo ou à causa da posição o controle do progresso redesenhar\-se.  
  
 Por padrão, o intervalo é definido como 0 – 100, a posição inicial e são definidos como 0.  Para recuperar as configurações atuais do intervalo para o controle do progresso, use a função de membro de [GetRange](../Topic/CProgressCtrl::GetRange.md) .  Para alterar o intervalo, use a função de membro de [SetRange](../Topic/CProgressCtrl::SetRange.md) .  
  
 Para definir a posição, use [SetPos](../Topic/CProgressCtrl::SetPos.md).  Para recuperar a posição atual sem especificar um novo valor, use [GetPos](../Topic/CProgressCtrl::GetPos.md).  Por exemplo, você pode querer ver apenas o status da operação atual.  
  
 Para percorrer a posição atual do controle de progresso, use [StepIt](../Topic/CProgressCtrl::StepIt.md).  Para definir a quantidade de cada etapa, use [SetStep](../Topic/CProgressCtrl::SetStep.md)  
  
## Consulte também  
 [Usando CProgressCtrl](../mfc/using-cprogressctrl.md)   
 [Controles](../mfc/controls-mfc.md)