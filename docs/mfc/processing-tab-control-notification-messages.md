---
title: "Processando mensagens de notifica&#231;&#227;o do controle de guia | Microsoft Docs"
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
  - "Classe CTabCtrl, processando notificações"
  - "notificações, processando em CTabCtrl"
  - "notificações, controles de guia"
  - "processando notificações"
  - "controles de guia, processando notificações"
ms.assetid: 758ccb7a-9e73-48f8-9073-23f7cb09918c
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Processando mensagens de notifica&#231;&#227;o do controle de guia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como os usuários clicam em guias ou botões, o controle da guia \([CTabCtrl](../Topic/CTabCtrl%20Class.md)\) envia notificações à janela pai.  Tratar essas mensagens se você deseja fazer algo na resposta.  Por exemplo, quando o usuário clica em uma guia, você pode querer pré\-ajustar dados de controle na página antes de exibição.  
  
 Mensagens de **WM\_NOTIFY** de processo do controle da guia na exibição ou a classe da caixa de diálogo.  Use a janela Propriedades para criar uma função de manipulador de [OnChildNotify](../Topic/CWnd::OnChildNotify.md) com uma instrução switch com base em notificação que está sendo tratada.  Para obter uma lista de notificações que um controle da guia pode enviar à janela pai, consulte a seção de **Notificações** de [Referência de controle da guia](http://msdn.microsoft.com/library/windows/desktop/bb760548) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Usando CTabCtrl](../mfc/using-ctabctrl.md)   
 [Controles](../mfc/controls-mfc.md)