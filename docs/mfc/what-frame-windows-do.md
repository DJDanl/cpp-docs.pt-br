---
title: O que fazem janelas de quadro
ms.date: 11/04/2016
helpviewer_keywords:
- frame windows [MFC], about frame windows
- frame windows [MFC], tasks
- MFC, frame windows
ms.assetid: 1148a952-6786-4622-b5a8-68a2d7eae584
ms.openlocfilehash: 594700ef1cbe0030bbe452adaa40b29b4a72f4d0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405671"
---
# <a name="what-frame-windows-do"></a>O que fazem janelas de quadro

Além de simplesmente uma exibição de enquadramento, janelas de quadro são responsáveis por diversas tarefas envolvidas na coordenação o quadro com seu modo de exibição e com o aplicativo. [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) e [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) herdam [CFrameWnd](../mfc/reference/cframewnd-class.md), para que eles tenham `CFrameWnd` recursos, bem como novos recursos que adicionam. Exemplos de janelas filho incluem exibições, controles como botões e caixas de listagem e barras de controle, incluindo as barras de ferramentas, barras de status e as barras de caixa de diálogo.

A janela do quadro é responsável por gerenciar o layout de suas janelas filho. No framework MFC, uma janela de quadro posiciona as barras de controle, exibições e outras janelas filho dentro de sua área de cliente.

A janela do quadro também encaminha comandos para seus modos de exibição e responder às mensagens de notificação do windows do controle.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Barras de controle (como elas se encaixam na janela de quadro)](../mfc/control-bars.md)

- [Gerenciando menus, barras de controle e aceleradores (como elas se encaixam na janela de quadro)](../mfc/managing-menus-control-bars-and-accelerators.md)

- [Roteamento de comando (da janela do quadro para o seu modo de exibição e outros destinos de comando)](../mfc/command-routing.md)

- [Arquitetura do documento /View](../mfc/document-view-architecture.md)

- [Barras de controle](../mfc/control-bars.md)

- [Controles](../mfc/controls-mfc.md)

## <a name="see-also"></a>Consulte também

[Janelas com moldura](../mfc/frame-windows.md)
