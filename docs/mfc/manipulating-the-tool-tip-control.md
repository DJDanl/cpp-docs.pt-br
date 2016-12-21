---
title: "Manipulando o controle da dica de ferramenta | Microsoft Docs"
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
  - "Classe CToolTipCtrl, manipulando atributos de dica de ferramenta"
  - "dicas de ferramenta [C++], atributos"
ms.assetid: 3600afe5-712a-4b56-8456-96e85fe879af
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipulando o controle da dica de ferramenta
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe `CToolTipCtrl` fornece um grupo de funções de membro que controlam os vários atributos de objeto de `CToolTipCtrl` e na janela da dica de ferramenta.  
  
 Durações inicial, as pop\-up, e de reshow para as janelas de dica de ferramenta podem ser definidas e recuperadas com chamadas a [GetDelayTime](../Topic/CToolTipCtrl::GetDelayTime.md) e a [SetDelayTime](../Topic/CToolTipCtrl::SetDelayTime.md).  
  
 Alterar a aparência do windows da dica de ferramenta com as seguintes funções:  
  
-   [GetMargin](../Topic/CToolTipCtrl::GetMargin.md) e [SetMargin](../Topic/CToolTipCtrl::SetMargin.md) recuperam e definem a largura entre a borda da dica de ferramenta e o texto da dica de ferramenta.  
  
-   [GetMaxTipWidth](../Topic/CToolTipCtrl::GetMaxTipWidth.md) e [SetMaxTipWidth](../Topic/CToolTipCtrl::SetMaxTipWidth.md) recuperam e definem a largura máxima da janela da dica de ferramenta.  
  
-   [GetTipBkColor](../Topic/CToolTipCtrl::GetTipBkColor.md) e [SetTipBkColor](../Topic/CToolTipCtrl::SetTipBkColor.md) recuperam e definem a cor do plano de fundo da janela da dica de ferramenta.  
  
-   [GetTipTextColor](../Topic/CToolTipCtrl::GetTipTextColor.md) e [SetTipTextColor](../Topic/CToolTipCtrl::SetTipTextColor.md) recuperam e definem a cor do texto da janela da dica de ferramenta.  
  
 Para que o controle da dica de ferramenta é notificado de mensagens importantes, como mensagens de **WM\_LBUTTONXXX** , você deve retransmitir mensagens ao controle da dica de ferramenta.  O melhor método para este utility é fazer uma chamada a [CToolTipCtrl::RelayEvent](../Topic/CToolTipCtrl::RelayEvent.md), na função de `PreTranslateMessage` da janela do proprietário.  O exemplo a seguir ilustra um método possível \(supondo que o controle da dica de ferramenta é chamado `m_ToolTip`\):  
  
 [!code-cpp[NVC_MFCControlLadenDialog#41](../mfc/codesnippet/CPP/manipulating-the-tool-tip-control_1.cpp)]  
  
 Para remover imediatamente uma janela de dica de ferramenta, chame a função de membro de [Pop](../Topic/CToolTipCtrl::Pop.md) .  
  
## Consulte também  
 [Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)   
 [Controles](../mfc/controls-mfc.md)