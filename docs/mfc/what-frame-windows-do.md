---
title: O que fazem janelas de quadro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- frame windows [MFC], about frame widows
- frame windows [MFC], tasks
- MFC, frame windows
ms.assetid: 1148a952-6786-4622-b5a8-68a2d7eae584
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8ed903238a812188d73093211265c9c8c028b0ab
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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

