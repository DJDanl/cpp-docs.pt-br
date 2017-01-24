---
title: "M&#233;todos de cria&#231;&#227;o de uma barra de status | Microsoft Docs"
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
  - "Classe CStatusBar, vs. CStatusBarCtrl"
  - "Classe CStatusBarCtrl, criando"
  - "Classe CStatusBarCtrl, vs. CStatusBar"
  - "métodos [MFC]"
  - "métodos [MFC], criando barras de status"
  - "barras de status, criando"
ms.assetid: 9aeaf290-7099-4762-a5ba-9c26705333c9
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todos de cria&#231;&#227;o de uma barra de status
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC O fornece duas classes para criar barras de status: [CStatusBar](../mfc/reference/cstatusbar-class.md) e [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md) \(que envolve o controle \(API do windows\).  `CStatusBar` fornece toda a funcionalidade de controle comuns da barra de status, interage automaticamente com os menus e barras de ferramentas, e gerencia muitas das configurações necessárias e as estruturas de controle comum para você; no entanto, o executável resultante será geralmente maior do que criado usando `CStatusBarCtrl`.  
  
 `CStatusBarCtrl` geralmente resultam em um executável menor, e você pode preferir usar `CStatusBarCtrl` se você não pretende integrar a barra de status na arquitetura de MFC.  Se você planeja usar `CStatusBarCtrl` e integrar a barra de status na arquitetura de MFC, você deve tomar adicional para comunicar manipulações de controle da barra de status ao MFC.  Essa comunicação não é difícil; no entanto, é o trabalho adicional que é desnecessárias quando você usa `CStatusBar`.  
  
 Visual C\+\+ fornece dois modos de aproveitar o controle comuns da barra de status.  
  
-   Crie a barra de status usando `CStatusBar`, e chame [CStatusBar::GetStatusBarCtrl](../Topic/CStatusBar::GetStatusBarCtrl.md) para obter acesso às funções de membro de `CStatusBarCtrl` .  
  
-   Crie a barra de status usando o construtor de [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md) .  
  
 Um ou outro método apresentará o acesso às funções de membro do controle da barra de status.  Quando você chama `CStatusBar::GetStatusBarCtrl`, retorna uma referência a um objeto de `CStatusBarCtrl` assim que você pode usar um conjunto de funções de membro.  Consulte [CStatusBar](../mfc/reference/cstatusbar-class.md) para obter informações sobre como construir e criar uma barra de status usando `CStatusBar`.  
  
## Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)