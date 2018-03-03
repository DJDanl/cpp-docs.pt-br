---
title: Classes de janela (Windows) do quadro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.classes.frame
dev_langs:
- C++
helpviewer_keywords:
- frame window classes [MFC], reference
ms.assetid: 6342ec5f-f922-4da8-a78e-2f5f994c7142
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c2668a8334192d4de199f1c42a648b74add1ca5c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="frame-window-classes-windows"></a>Classes de janela com moldura (Windows)
Janelas de quadro são janelas que um aplicativo ou uma parte de um aplicativo do quadro. Janelas com moldura geralmente contêm outras janelas, como exibições, barras de ferramentas e barras de status. No caso de `CMDIFrameWnd`, elas podem conter `CMDIChildWnd` objetos indiretamente.  
  
 [CFrameWnd](../mfc/reference/cframewnd-class.md)  
 A classe base para a janela do quadro principal do aplicativo SDI. Também é a classe base para todas as outras classes de janela do quadro.  
  
 [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md)  
 A classe base para a janela do quadro principal do aplicativo MDI.  
  
 [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)  
 A classe base para janelas de quadro de documento do aplicativo MDI.  
  
 [CMiniFrameWnd](../mfc/reference/cminiframewnd-class.md)  
 Uma janela do quadro de meia altura geralmente Vista em torno de flutuando barras de ferramentas.  
  
 [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md)  
 Fornece a janela do quadro para um modo de exibição quando um documento do servidor está sendo editado no local.  
  
## <a name="related-class"></a>Classe relacionada  
 Classe `CMenu` fornece uma interface por meio do qual acessar menus do aplicativo. É útil para manipulando menus dinamicamente em tempo de execução; Por exemplo, ao adicionar ou excluir itens de menu de acordo com o contexto. Embora os menus são geralmente usados com janelas com moldura, eles também podem ser usados com caixas de diálogo e outras janelas nonchild.  
  
 [CMenu](../mfc/reference/cmenu-class.md)  
 Encapsula um `HMENU` identificador para a barra de menus e menus pop-up do aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

