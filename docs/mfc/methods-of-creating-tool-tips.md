---
title: "M&#233;todos de cria&#231;&#227;o de dicas de ferramenta | Microsoft Docs"
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
  - "Classe CToolTipCtrl, criando dicas de ferramenta"
  - "dicas de ferramenta [C++], criando"
  - "dicas de ferramenta [C++], controles de dica de ferramenta"
ms.assetid: b015e9f4-ddfb-49a4-a5a6-fa2d45e4d328
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todos de cria&#231;&#227;o de dicas de ferramenta
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC O fornece três classes para criar e gerenciar o controle da dica de ferramenta: [CWnd](../Topic/CWnd%20Class.md), [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md), [CToolTipCtrl](../Topic/CToolTipCtrl%20Class.md) e [CMFCToolTipCtrl](../mfc/reference/cmfctooltipctrl-class.md).  As funções de membro da dica de ferramenta nessas classes envolvem o controle \(API do windows.  A classe `CToolBarCtrl` e a classe `CToolTipCtrl` são derivadas da classe `CWnd`.  
  
 `CWnd` fornece quatro funções de membro para criar e gerenciar dicas de ferramenta: [EnableToolTips](../Topic/CWnd::EnableToolTips.md), [CancelToolTips](../Topic/CWnd::CancelToolTips.md), [FilterToolTipMessage](../Topic/CWnd::FilterToolTipMessage.md), e [OnToolHitTest](../Topic/CWnd::OnToolHitTest.md).  Consulte estas funções de membro individuais para obter mais informações sobre como implementam dicas de ferramenta.  
  
 Se você criar uma barra de ferramentas usando `CToolBarCtrl`, você pode implementar dicas de ferramenta para essa barra de ferramentas diretamente usando as seguintes funções de membro: [GetToolTips](../Topic/CToolBarCtrl::GetToolTips.md) e [SetToolTips](../Topic/CToolBarCtrl::SetToolTips.md).  Consulte estas funções de membro individuais e [Notificações de dica de ferramenta de manipulação](../mfc/handling-tool-tip-notifications.md) para obter mais informações sobre como implementam dicas de ferramenta.  
  
 A classe de `CToolTipCtrl` fornece a funcionalidade de controle da dica de ferramenta comum do windows.  Um único controle da dica de ferramenta pode fornecer informações para mais de uma ferramenta.  Uma ferramenta é uma janela, como uma janela filho ou um controle, ou uma área retangular aplicativo definida na área do cliente de uma janela.  A classe de [CMFCToolTipCtrl](../mfc/reference/cmfctooltipctrl-class.md) é derivado de `CToolTipCtrl` e fornece estilos e a funcionalidade visuais adicionais.  
  
## Consulte também  
 [Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)   
 [Controles](../mfc/controls-mfc.md)