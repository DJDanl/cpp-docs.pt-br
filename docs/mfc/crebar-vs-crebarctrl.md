---
title: "CReBar vs. CReBarCtrl | Microsoft Docs"
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
  - "CReBar"
  - "CReBarCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CReBar, vs. CReBarCtrl"
  - "Classe GetReBarCtrl"
  - "controles rebar, Classe CReBarCtrl"
ms.assetid: 7f9c1d7e-5d5f-4956-843c-69ed3df688d0
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CReBar vs. CReBarCtrl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC O fornece duas classes para criar rebars: [CReBar](../mfc/reference/crebar-class.md) e [CReBarCtrl](../mfc/reference/crebarctrl-class.md) \(que envolve o controle \(API do windows\).  **CReBar** fornece toda a funcionalidade de controle do rebar, e gerencia muitas das configurações necessárias e as estruturas de controle comum para você.  
  
 `CReBarCtrl` é uma classe de invólucro para o controle de rebar do Win32, e em virtude disso pode ser mais fácil de implementar se você não pretende integrar o rebar na arquitetura de MFC.  Se você planeja usar `CReBarCtrl` e integrar o rebar na arquitetura de MFC, você deve tomar adicional para comunicar manipulações de controle de rebar MFC ao.  Essa comunicação não é difícil; no entanto, é o trabalho adicional que é desnecessárias quando você usa **CReBar**.  
  
 Visual C\+\+ fornece dois modos de aproveitar o controle comuns de rebar.  
  
-   Crie o rebar usando **CReBar**, e chame [CReBar::GetReBarCtrl](../Topic/CReBar::GetReBarCtrl.md) para obter acesso às funções de membro de `CReBarCtrl` .  
  
    > [!NOTE]
    >  `CReBar::GetReBarCtrl` é uma função de membro embutido que converte o ponteiro de **this** do objeto de rebar.  Isso significa que, em tempo de execução, a chamada de função não tem sobrecarga.  
  
-   Crie o rebar usando o construtor de [CReBarCtrl](../mfc/reference/crebarctrl-class.md) .  
  
 Um ou outro método apresentará o acesso às funções de membro de controle de rebar.  Quando você chama `CReBar::GetReBarCtrl`, retorna uma referência a um objeto de `CReBarCtrl` assim que você pode usar um conjunto de funções de membro.  Consulte [CReBar](../mfc/reference/crebar-class.md) para obter informações sobre como construir e criar um rebar usando **CReBar**.  
  
## Consulte também  
 [Usando CReBarCtrl](../Topic/Using%20CReBarCtrl.md)   
 [Controles](../mfc/controls-mfc.md)