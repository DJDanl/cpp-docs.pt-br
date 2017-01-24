---
title: "O que fazem janelas de quadro | Microsoft Docs"
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
  - "janelas com moldura, sobre janelas com moldura"
  - "janelas com moldura, tarefas"
  - "MFC, janelas com moldura"
ms.assetid: 1148a952-6786-4622-b5a8-68a2d7eae584
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# O que fazem janelas de quadro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Além de simplesmente moldar uma exibição, as janelas de peças são responsáveis pelas várias tarefas envolvidas no coordenam o quadro com sua exibição e ao aplicativo.  [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) e [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) herdam de [CFrameWnd](../mfc/reference/cframewnd-class.md), para que tenha os recursos de `CFrameWnd` bem como os novos recursos que adiciona.  Os exemplos das janelas filho incluem exibições, controla como os botões e as caixas de listagem, e barras de controle, inclusive barras de ferramentas, barras de status, e barras da caixa de diálogo.  
  
 A janela do quadro é responsável por gerenciar o layout das janelas filho.  Na estrutura, MFC uma janela do quadro posiciona todas as barras de controle, exibições, e outras janelas filho dentro da área do cliente.  
  
 A janela do quadro também encaminha comandos às exibições e pode responder às notificações do windows de controle.  
  
## Que você deseja saber mais?  
  
-   [Barras de controle \(como se ajustaram a na janela do quadro\)](../Topic/Control%20Bars.md)  
  
-   [Gerenciando menus, barras de controle, e aceleradores \(como se ajustaram a na janela do quadro\)](../mfc/managing-menus-control-bars-and-accelerators.md)  
  
-   [Roteamento de comando \(quadro da janela da sua exibição e outros destinos de comando\)](../mfc/command-routing.md)  
  
-   [Arquitetura de \/View do documento](../Topic/Document-View%20Architecture.md)  
  
-   [Barras de controle](../Topic/Control%20Bars.md)  
  
-   [Controles](../mfc/controls-mfc.md)  
  
## Consulte também  
 [Janelas com moldura](../mfc/frame-windows.md)