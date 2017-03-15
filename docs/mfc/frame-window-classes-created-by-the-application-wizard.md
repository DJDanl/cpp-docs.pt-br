---
title: "Classes de janela com moldura criadas pelo Assistente de Aplicativo | Microsoft Docs"
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
  - "CMainFrame"
  - "CMainFrame::PreCreateWindow"
  - "CMainFrame.PreCreateWindow"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "assistentes de aplicativo [C++], classes de janela com moldura criadas por"
  - "Classe CFrameWnd, janelas com moldura"
  - "classes [C++], janela com moldura"
  - "Classe CMainFrame"
  - "Classe CMDIChildWnd, janelas com moldura"
  - "Classe CMDIFrameWnd, janelas com moldura"
  - "classes de janela com moldura, criadas por assistentes de aplicativo"
  - "classes de janela"
  - "classes de janela, moldura"
ms.assetid: 9947df73-4470-49a0-ac61-7b6ee401a74e
caps.latest.revision: 8
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de janela com moldura criadas pelo Assistente de Aplicativo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você usa [Assistente de aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md) para criar um aplicativo do esqueleto, além do aplicativo, o documento, e as classes de exibição, o assistente de aplicativo cria uma classe derivada de quadro\- janela para a janela principal do quadro do seu aplicativo.  A classe é chamada `CMainFrame` por padrão, e os arquivos que contêm o são nomeados MAINFRM.H e MAINFRM.CPP.  
  
 Se seu aplicativo for SDI, sua classe de `CMainFrame` é derivada da classe [CFrameWnd](../mfc/reference/cframewnd-class.md).  
  
 Se seu aplicativo for MDI, `CMainFrame` é derivado da classe [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md).  Nesse caso `CMainFrame` implementa o quadro principal, que mantém o menu, na barra de ferramentas, e as barras de status.  O assistente de aplicativo não deve derivar uma classe de quadro\- janela de documento novo para você.  Em vez disso, usar a implementação padrão em [Classe de CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md).  A estrutura de MFC cria uma janela filho para conter e assim por diante cada exibição \(que pode ser do tipo `CScrollView`, `CEditView`, `CTreeView`, `CListView`,\) que o aplicativo exige.  Se você precisar personalizar a janela do quadro do documento, você pode criar uma classe de quadro\- nova janela de documento \(consulte [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)\).  
  
 Se você escolher para oferecer suporte a uma barra de ferramentas, a classe também tem as variáveis do tipo member [CToolBar](../mfc/reference/ctoolbar-class.md) e [CStatusBar](../mfc/reference/cstatusbar-class.md) e uma função retornadas manipulador de `OnCreate` para inicializar dois [barras de controle](../Topic/Control%20Bars.md).  
  
 Essas classes de quadro\- janela funcionam como criado, mas para aprimorar a funcionalidade, você deve adicionar variáveis e funções do membro.  Você também pode querer fazer com que as classes da janela lidar com outras mensagens do windows.  Para obter mais informações, consulte [Alterando os estilos de uma janela criada por MFC](../Topic/Changing%20the%20Styles%20of%20a%20Window%20Created%20by%20MFC.md).  
  
## Consulte também  
 [Classes de janela com moldura](../mfc/frame-window-classes.md)   
 [Programa MFC ou origem de controle e arquivos de cabeçalho](../ide/mfc-program-or-control-source-and-header-files.md)