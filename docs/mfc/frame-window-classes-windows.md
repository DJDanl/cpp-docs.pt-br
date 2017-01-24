---
title: "Classes de janela com moldura (Windows) | Microsoft Docs"
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
  - "vc.classes.frame"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de janela com moldura, referência"
ms.assetid: 6342ec5f-f922-4da8-a78e-2f5f994c7142
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de janela com moldura (Windows)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As janelas de peças são as janelas que enquadram um aplicativo ou parte de um aplicativo.  As janelas do quadro normalmente contêm outras janelas, como exibições, barras de ferramentas, e barras de status.  No caso de `CMDIFrameWnd`, podem conter objetos de `CMDIChildWnd` indiretamente.  
  
 [CFrameWnd](../mfc/reference/cframewnd-class.md)  
 A classe base da janela principal do quadro de um aplicativo de SDI.  Também a classe base para qualquer outro quadro de janela de classificação.  
  
 [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md)  
 A classe base da janela principal do quadro de um aplicativo MDI.  
  
 [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)  
 A classe base para o windows do quadro do documento de um aplicativo MDI.  
  
 [CMiniFrameWnd](../mfc/reference/cminiframewnd-class.md)  
 Uma janela do quadro de meia altura normalmente consultada em torno das barras de ferramentas flutuante.  
  
 [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md)  
 Fornece a janela do quadro para uma exibição quando um documento de servidor está sendo editado no lugar.  
  
## Classe relacionada  
 A classe `CMenu` fornece uma interface via que para acessar os menus do seu aplicativo.  É útil para manipular menus dinamicamente em tempo de execução; por exemplo, ao adicionar ou excluir itens de menu de acordo com o contexto.  Embora os menus sejam os geralmente usados com o windows do quadro, também podem ser usados com caixas de diálogo e outras janelas de nonchild.  
  
 [CMenu](../mfc/reference/cmenu-class.md)  
 Encapsula um identificador de `HMENU` à barra de menus e no menu pop\-up de aplicativo.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)