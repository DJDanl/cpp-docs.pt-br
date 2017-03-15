---
title: "M&#233;todos de cria&#231;&#227;o de uma barra de ferramentas | Microsoft Docs"
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
  - "Classe CToolBar, criando barras de ferramentas"
  - "Classe CToolBarCtrl, e classe CToolBar"
  - "Classe CToolBarCtrl, criando barras de ferramentas"
  - "Barras de ferramentas MFC"
  - "controles de barra de ferramentas [MFC]"
  - "controles de barra de ferramentas [MFC], criando"
ms.assetid: f19d8d65-d49f-445c-abe8-d47d3e4101c8
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todos de cria&#231;&#227;o de uma barra de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC O fornece duas classes para criar barras de ferramentas: [CToolBar](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) \(que envolve o controle \(API do windows\).  `CToolBar` fornece toda a funcionalidade de controle comuns da barra de ferramentas, e gerencia muitas das configurações necessárias e as estruturas de controle comum para você; no entanto, o executável resultante será geralmente maior do que criado usando `CToolBarCtrl`.  
  
 `CToolBarCtrl` geralmente resultam em um executável menor, e você pode preferir usar `CToolBarCtrl` se você não pretende integrar a barra de ferramentas na arquitetura de MFC.  Se você planeja usar `CToolBarCtrl` e integrar a barra de ferramentas na arquitetura de MFC, você deve tomar adicional para comunicar manipulações de controle da barra de ferramentas ao MFC.  Essa comunicação não é difícil; no entanto, é o trabalho adicional que é desnecessárias quando você usa `CToolBar`.  
  
 Visual C\+\+ fornece dois modos de aproveitar o controle comuns da barra de ferramentas.  
  
-   Crie a barra de ferramentas usando `CToolBar`, e chame [CToolBar::GetToolBarCtrl](../Topic/CToolBar::GetToolBarCtrl.md) para obter acesso às funções de membro de `CToolBarCtrl` .  
  
-   Crie a barra de ferramentas usando o construtor de [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) .  
  
 Um ou outro método apresentará o acesso às funções de membro de controle da barra de ferramentas.  Quando você chama `CToolBar::GetToolBarCtrl`, retorna uma referência a um objeto de `CToolBarCtrl` assim que você pode usar um conjunto de funções de membro.  Consulte [CToolBar](../mfc/reference/ctoolbar-class.md) para obter informações sobre como construir e criar uma barra de ferramentas usando `CToolBar`.  
  
## Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)