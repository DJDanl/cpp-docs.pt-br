---
title: "Classes de janela com moldura (arquitetura) | Microsoft Docs"
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
  - "classes de janela com moldura, arquitetura de documento/exibição"
ms.assetid: 5da01fb4-f531-46cc-914f-e422e4f07f5d
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de janela com moldura (arquitetura)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na arquitetura do documento\/exibição, as janelas de peças são as janelas que contêm uma janela de exibição.  Também dão suporte a ter as barras de controle anexadas a eles.  
  
 Em aplicativos \(MDI\) de interface de documentos, a janela principal é derivada de `CMDIFrameWnd`.  Contém indiretamente os itens dos documentos, que são objetos de `CMDIChildWnd` .  `CMDIChildWnd` objetos, por sua vez, contém as exibições de documentos.  
  
 Em aplicativos \(SDI\) da interface de único documento, a janela principal, derivada de `CFrameWnd`, contém a exibição do documento atual.  
  
 [CFrameWnd](../mfc/reference/cframewnd-class.md)  
 A classe base da janela principal do quadro de um aplicativo de SDI.  Também a classe base para qualquer outro quadro de janela de classificação.  
  
 [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md)  
 A classe base da janela principal do quadro de um aplicativo MDI.  
  
 [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)  
 A classe base para o windows do quadro do documento de um aplicativo MDI.  
  
 [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md)  
 Fornece a janela do quadro para uma exibição quando um documento de servidor está sendo editado no lugar.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)