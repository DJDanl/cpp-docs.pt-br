---
title: Janelas com moldura | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- document frame windows [MFC]
- windows [MFC], MDI
- window classes [MFC], frame
- single document interface (SDI) [MFC]
- single document interface (SDI) [MFC], frame windows
- views [MFC], and frame windows
- CFrameWnd class [MFC], frame windows
- frame windows [MFC]
- frame windows [MFC], about frame widows
- MFC, frame windows
- MDI [MFC], frame windows
- splitter windows [MFC], and frame windows
ms.assetid: 40677339-8135-4f5e-aba6-3fced3078077
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 515df19bcc11f7a6706985014fc44bc4ff315f36
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="frame-windows"></a>Janelas com moldura
Quando um aplicativo é executado no Windows, o usuário interage com documentos exibidos nas janelas de quadro. Uma janela de quadro do documento tem dois componentes principais: o quadro e o conteúdo que ele quadros. Uma janela do quadro de documento pode ser um [única interface de documento](../mfc/sdi-and-mdi.md) janela do quadro (SDI) ou um [interface de múltiplos documentos](../mfc/sdi-and-mdi.md) janela filho (MDI). O Windows gerencia a maioria da interação do usuário com a janela do quadro: movendo e redimensionando a janela, fechá-lo e minimizar e maximizando a ele. Você gerencia o conteúdo dentro do quadro.  
  
## <a name="frame-windows-and-views"></a>Exibições e janelas com moldura  
 A estrutura MFC usa janelas de quadro para conter os modos de exibição. Os dois componentes — quadro e conteúdo — são representados e gerenciadas por duas classes diferentes em MFC. Uma classe de janela com moldura gerencia o quadro e uma classe de exibição gerencia o conteúdo. A janela de exibição é um filho da janela do quadro. Desenho e outra interação do usuário com o documento assumir o lugar na área do cliente do modo de exibição, não os área de cliente da janela do quadro. A janela do quadro fornece um quadro visível em torno de uma exibição, com uma barra de legenda e os controles de janela padrão como um menu de controle, botões para minimizar e maximizar a janela e controles de redimensionamento de janela. O "conteúdo" consistem em área de cliente da janela, que é totalmente ocupada por uma janela filho, o modo de exibição. A figura a seguir mostra a relação entre um modo de exibição e de uma janela do quadro.  
  
 ![Modo de exibição da janela do quadro](../mfc/media/vc37fx1.gif "vc37fx1")  
Modo de exibição e a janela do quadro  
  
## <a name="frame-windows-and-splitter-windows"></a>Janelas com moldura e janelas separadoras  
 Outra organização comum é para a janela do quadro para quadro vários modos de exibição, normalmente usando um [janela separadora](../mfc/multiple-document-types-views-and-frame-windows.md). Em uma janela separadora, área cliente da janela do quadro está ocupada por uma janela separadora, que por sua vez, tem várias janelas filho, chamadas de painéis, que são modos de exibição.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
 **Tópicos de janela do quadro geral**  
  
-   [Objetos de janela](../mfc/window-objects.md)  
  
-   [Classes de janela com moldura](../mfc/frame-window-classes.md)  
  
-   [As classes de janela com moldura criadas pelo Assistente de aplicativo](../mfc/frame-window-classes-created-by-the-application-wizard.md)  
  
-   [Estilos de janela do quadro](../mfc/frame-window-styles-cpp.md)  
  
-   [O que fazem janelas com moldura](../mfc/what-frame-windows-do.md)  
  
 **Tópicos sobre o uso de janelas com moldura**  
  
-   [Usando janelas com moldura](../mfc/using-frame-windows.md)  
  
-   [Criando janelas com moldura de documento](../mfc/creating-document-frame-windows.md)  
  
-   [Destruindo janelas com moldura](../mfc/destroying-frame-windows.md)  
  
-   [Gerenciando janelas filhos MDI](../mfc/managing-mdi-child-windows.md)  
  
-   [Gerenciando a exibição atual](../mfc/managing-the-current-view.md) em uma janela do quadro que contém mais de uma exibição  
  
-   [Gerenciando menus, barras de controle e aceleradores (outros objetos que compartilham o espaço da janela do quadro)](../mfc/managing-menus-control-bars-and-accelerators.md)  
  
 **Tópicos sobre recursos de janela do quadro especiais**  
  
-   [Arrastando e soltando arquivos](../mfc/dragging-and-dropping-files-in-a-frame-window.md) do Explorador de arquivos ou no Gerenciador de arquivos em uma janela do quadro  
  
-   [Respondendo à troca dinâmica de dados (DDE)](../mfc/responding-to-dynamic-data-exchange-dde.md)  
  
-   [Estados semimodais: sensível ao contexto (Orquestrando outras ações de janela) ajuda do Windows](../mfc/orchestrating-other-window-actions.md)  
  
-   [Estados semimodais: impressão e visualização de impressão (Orquestrando outras ações de janela)](../mfc/orchestrating-other-window-actions.md)  
  
 **Tópicos sobre outros tipos de janelas**  
  
-   [Usando exibições](../mfc/using-views.md)  
  
-   [Caixas de diálogo](../mfc/dialog-boxes.md)  
  
-   [Controles](../mfc/controls-mfc.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows](../mfc/windows.md)

