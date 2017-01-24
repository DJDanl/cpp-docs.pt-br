---
title: "Sequ&#234;ncia de destrui&#231;&#227;o da janela | Microsoft Docs"
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
  - "Objetos CWnd, sequência de destruição"
  - "destruindo janelas"
  - "destruição, janelas"
  - "sequência [C++]"
  - "sequência [C++], destruição de janela"
  - "janelas [C++], destruindo"
ms.assetid: 2d819196-6240-415f-a308-db43745e616c
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sequ&#234;ncia de destrui&#231;&#227;o da janela
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na estrutura de MFC, quando o usuário fecha a janela do quadro, o manipulador padrão de [OnClose](../Topic/CWnd::OnClose.md) da janela chama [DestroyWindow](../Topic/CWnd::DestroyWindow.md).  A função de membro a última chamada quando a janela do windows é destruída é [OnNcDestroy](../Topic/CWnd::OnNcDestroy.md), que faz qualquer limpeza, chama a função de membro de [Opção](../Topic/CWnd::Default.md) para executar a limpeza do windows, e chama alteração da função de membro virtual [PostNcDestroy](../Topic/CWnd::PostNcDestroy.md).  A implementação de [CFrameWnd](../mfc/reference/cframewnd-class.md) de `PostNcDestroy` exclui o objeto da janela C\+\+.  
  
## Que você deseja saber mais?  
  
-   [Atribuindo e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)  
  
-   [Desanexando um CWnd do HWND](../Topic/Detaching%20a%20CWnd%20from%20Its%20HWND.md)  
  
## Consulte também  
 [Destruindo objetos de janela](../mfc/destroying-window-objects.md)