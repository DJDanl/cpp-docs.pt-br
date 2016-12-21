---
title: "Manipulando o controle de progresso | Microsoft Docs"
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
  - "controlando controles de andamento"
  - "Classe CProgressCtrl, manipulando"
  - "Classe CProgressCtrl, usando"
  - "Classe CProgressCtrl, trabalhando com"
  - "controles de andamento [C++], manipulando"
ms.assetid: 9af561d1-980b-4003-a6da-ff79be15bf23
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipulando o controle de progresso
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Há três maneiras de alterar a posição atual de um controle de progresso \([CProgressCtrl](../mfc/reference/cprogressctrl-class.md)\).  
  
-   A posição pode ser alterada por uma quantidade predefinido de incremento.  
  
-   A posição pode ser alterada por uma quantidade arbitrária.  
  
-   A posição pode ser alterada para um valor específico.  
  
### Para alterar a posição por uma quantidade predefinido  
  
1.  Use a função de membro de [SetStep](../Topic/CProgressCtrl::SetStep.md) para definir a quantidade de incremento.  Por padrão, esse valor é 10.  Esse valor é normalmente definido como uma das configurações iniciais para o controle.  O valor da etapa pode ser negativo.  
  
2.  Use a função de membro de [StepIt](../Topic/CProgressCtrl::StepIt.md) para incrementar a posição.  Isso faz com que o controle redesenhe\-se.  
  
    > [!NOTE]
    >  `StepIt` fará a posição envolver.  Por exemplo, em um intervalo de 1 a 100, uma etapa de 20, e uma posição de 90, `StepIt` definirá à posição 10.  
  
### Para alterar a posição por uma quantidade arbitrária  
  
1.  Use a função de membro de [OffsetPos](../Topic/CProgressCtrl::OffsetPos.md) para alterar a posição.  `OffsetPos` aceitará valores negativos.  
  
    > [!NOTE]
    >  `OffsetPos`, ao contrário de `StepIt`, não envolverá a posição.  A nova posição é ajustada permanecer dentro do intervalo.  
  
### Para alterar a posição como um valor específico  
  
1.  Use a função de membro de [SetPos](../Topic/CProgressCtrl::SetPos.md) para definir a posição como um valor específico.  Se necessário, a nova posição é ajustada estar dentro do intervalo.  
  
 Normalmente, o controle do progresso é usado exclusivamente para saída.  Para obter a posição atual sem especificar um novo valor, use [GetPos](../Topic/CProgressCtrl::GetPos.md).  
  
## Consulte também  
 [Usando CProgressCtrl](../mfc/using-cprogressctrl.md)   
 [Controles](../mfc/controls-mfc.md)