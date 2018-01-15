---
title: O que fazem janelas de quadro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- frame windows [MFC], about frame widows
- frame windows [MFC], tasks
- MFC, frame windows
ms.assetid: 1148a952-6786-4622-b5a8-68a2d7eae584
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f5143bab1ea84392efe1bd5783889c45375365ff
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="what-frame-windows-do"></a>O que fazem janelas de quadro
Além de simplesmente uma exibição de enquadramento, janelas com moldura serão responsáveis por várias tarefas envolvidas na coordenar o quadro com o modo de exibição e com o aplicativo. [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) e [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) herdam [CFrameWnd](../mfc/reference/cframewnd-class.md), para que tenham `CFrameWnd` recursos, bem como novos recursos que eles adicionar. Janelas filho exemplos de modos de exibição, os controles como botões e caixas de listagem e barras de controle, incluindo as barras de ferramentas, barras de status e barras da caixa de diálogo.  
  
 A janela do quadro é responsável por gerenciar o layout de janelas filho. Na estrutura MFC, uma janela do quadro posiciona as barras de controle, exibições e outras janelas filho dentro de sua área cliente.  
  
 A janela do quadro também encaminha comandos para seus modos de exibição e responder às mensagens de notificação do windows do controle.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Barras de controle (como eles se encaixam a janela do quadro)](../mfc/control-bars.md)  
  
-   [Gerenciando menus, barras de controle e aceleradores (como eles se encaixam a janela do quadro)](../mfc/managing-menus-control-bars-and-accelerators.md)  
  
-   [Roteamento de comando (da janela do quadro para o modo de exibição e outros destinos de comando)](../mfc/command-routing.md)  
  
-   [Arquitetura de /View do documento](../mfc/document-view-architecture.md)  
  
-   [Barras de controle](../mfc/control-bars.md)  
  
-   [Controles](../mfc/controls-mfc.md)  
  
## <a name="see-also"></a>Consulte também  
 [Janelas com moldura](../mfc/frame-windows.md)

