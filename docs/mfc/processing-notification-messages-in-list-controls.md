---
title: "Processando mensagens de notifica&#231;&#227;o em controles de lista | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "Classe CListCtrl, processando notificações"
  - "processando notificações"
ms.assetid: 1f0e296e-d2a3-48fc-ae38-51d7fb096f51
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Processando mensagens de notifica&#231;&#227;o em controles de lista
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como os usuários clicam em cabeçalhos de coluna, arraste ícones, rótulos de edição, e assim por diante, o controle da lista[CListCtrl](../Topic/CListCtrl%20Class.md)\(\) envia notificações à janela pai.  Tratar essas mensagens se você deseja fazer algo na resposta.  Por exemplo, quando o usuário clica em um cabeçalho de coluna, talvez você queira classificar itens com base no conteúdo da coluna clicada, como no Microsoft Outlook.  
  
 Mensagens de **WM\_NOTIFY** de processo do controle da lista na exibição ou a classe da caixa de diálogo.  Use a janela Propriedades para criar uma função de manipulador de [OnChildNotify](../Topic/CWnd::OnChildNotify.md) com uma instrução switch com base em notificação que está sendo tratada.  
  
 Para obter uma lista de notificações que um controle de lista pode enviar à janela pai, consulte [Referência do controle de exibição de lista](http://msdn.microsoft.com/library/windows/desktop/bb774737) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Usando CListCtrl](../Topic/Using%20CListCtrl.md)   
 [Controles](../mfc/controls-mfc.md)