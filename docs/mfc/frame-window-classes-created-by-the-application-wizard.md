---
title: Classes de janela com moldura criadas pelo Assistente de aplicativo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CMainFrame
dev_langs:
- C++
helpviewer_keywords:
- application wizards [MFC], frame window classes created by
- window classes [MFC]
- classes [MFC], frame-window
- CMDIFrameWnd class [MFC], frame windows
- window classes [MFC], frame
- CFrameWnd class [MFC], frame windows
- CMDIChildWnd class [MFC], frame windows
- frame window classes [MFC], created by application wizards
- CMainFrame class [MFC]
ms.assetid: 9947df73-4470-49a0-ac61-7b6ee401a74e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 497dd21bba3e807349b793e3b37e774c833ccb40
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="frame-window-classes-created-by-the-application-wizard"></a>Classes de janela com moldura criadas pelo Assistente de Aplicativo
Quando você usa o [Assistente de aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md) para criar um aplicativo de esqueleto, além de aplicativo, documentos e classes de exibição, o Assistente de aplicativo cria uma classe derivada da janela do quadro de janela do quadro principal do seu aplicativo. A classe é chamada `CMainFrame` por padrão e os arquivos que contêm a ele são nomeados MAINFRM. H e MAINFRM. CPP.  
  
 Se seu aplicativo for SDI, seu `CMainFrame` classe é derivada da classe [CFrameWnd](../mfc/reference/cframewnd-class.md).  
  
 Se seu aplicativo for MDI, `CMainFrame` é derivado da classe [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md). Nesse caso `CMainFrame` implementa o quadro principal, que mantém as barras de menu, barra de ferramentas e status. O Assistente de aplicativo não derivar uma nova classe de janela com moldura de documento para você. Em vez disso, ele usa a implementação padrão em [classe CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md). A estrutura MFC cria uma janela filho para conter cada modo de exibição (que pode ser do tipo `CScrollView`, `CEditView`, `CTreeView`, `CListView`e assim por diante) que o aplicativo requer. Se você precisar personalizar a janela do quadro do documento, você pode criar uma nova classe de janela com moldura de documento (consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md)).  
  
 Se você escolher dar suporte a uma barra de ferramentas, a classe também tem variáveis de membro de tipo [CToolBar](../mfc/reference/ctoolbar-class.md) e [CStatusBar](../mfc/reference/cstatusbar-class.md) e um `OnCreate` função de manipulador de mensagens para inicializar os dois [ barras de controle](../mfc/control-bars.md).  
  
 Essas classes de janela com moldura funcionam como criado, mas para aprimorar a funcionalidade, você deve adicionar variáveis de membro e funções de membro. Talvez você queira ter suas classes de janela lidar com outras mensagens do Windows. Para obter mais informações, consulte [alternando os estilos de uma janela criada por MFC](../mfc/changing-the-styles-of-a-window-created-by-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classes de janela com moldura](../mfc/frame-window-classes.md)   
 [Programa MFC ou origem de controle e arquivos de cabeçalho](../ide/mfc-program-or-control-source-and-header-files.md)

