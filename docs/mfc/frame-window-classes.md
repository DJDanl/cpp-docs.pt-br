---
title: "Classes de janela com moldura | Microsoft Docs"
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
  - "classes [C++], janela"
  - "janelas de documento com moldura, Classes "
  - "classes de janela com moldura"
  - "classes de janela com moldura, sobre classes de janela com moldura"
  - "MDI [C++], janelas com moldura"
  - "MFC [C++], janelas com moldura"
  - "single document interface (SDI), janelas com moldura"
  - "classes de janela, moldura"
  - "janelas [C++], MDI"
ms.assetid: c27e43a7-8ad0-4759-b1b7-43f4725f4132
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de janela com moldura
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada aplicativo tem uma “quadro de janela principal,” uma janela de área de trabalho que tem normalmente o nome de aplicativo na sua legenda.  Cada documento normalmente tem uma “quadro de janela de documento.” Uma janela do quadro de documento contém pelo menos uma exibição, que apresenta os dados de documento.  
  
## Janelas de quadro em aplicativos de SDI e de documentos  
 Para um aplicativo de SDI, há uma janela do quadro derivada da classe [CFrameWnd](../mfc/reference/cframewnd-class.md).  Esta janela é a janela do quadro principal e a janela do quadro do documento.  Para um aplicativo MDI, a janela principal do quadro é derivada da classe [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md), e as janelas do quadro do documento, que são janelas filho MDI, são derivadas da classe [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md).  
  
## Use a classe de Quadro\- a janela do, ou derive\-a delas?  
 Essas classes fornecem a maioria da funcionalidade de quadro\- janela que você precisa para seus aplicativos.  Em condições normais, o comportamento e a aparência padrão que fornece serirão suas necessidades.  Se você precisar da funcionalidade adicional, derivar dessas classes.  
  
### Que você deseja saber mais?  
  
-   [Classes de Quadro\- janela criadas pelo assistente de aplicativo](../mfc/frame-window-classes-created-by-the-application-wizard.md)  
  
-   [Estilos de Quadro\- janela](../Topic/Frame-Window%20Styles%20\(C++\).md)  
  
-   [Alterando os estilos de uma janela criada por MFC](../Topic/Changing%20the%20Styles%20of%20a%20Window%20Created%20by%20MFC.md)  
  
## Consulte também  
 [Janelas com moldura](../mfc/frame-windows.md)