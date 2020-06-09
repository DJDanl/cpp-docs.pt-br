---
title: Janelas com moldura
ms.date: 11/19/2018
helpviewer_keywords:
- document frame windows [MFC]
- windows [MFC], MDI
- window classes [MFC], frame
- single document interface (SDI) [MFC]
- single document interface (SDI) [MFC], frame windows
- views [MFC], and frame windows
- CFrameWnd class [MFC], frame windows
- frame windows [MFC]
- frame windows [MFC], about frame windows
- MFC, frame windows
- MDI [MFC], frame windows
- splitter windows [MFC], and frame windows
ms.assetid: 40677339-8135-4f5e-aba6-3fced3078077
ms.openlocfilehash: 39c0b4b866fa123d8bcae639342c925570d96e1b
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625818"
---
# <a name="frame-windows"></a>Janelas com moldura

Quando um aplicativo é executado no Windows, o usuário interage com os documentos exibidos em janelas de quadros. Uma janela de quadro de documento tem dois componentes principais: o quadro e o conteúdo que ele emoldura. Uma janela de quadro de documento pode ser uma janela de quadro de SDI ( [interface de documento único](sdi-and-mdi.md) ) ou uma janela filho MDI ( [interface de vários documentos](sdi-and-mdi.md) ). O Windows gerencia a maior parte da interação do usuário com a janela do quadro: movendo e redimensionando a janela, fechando-a e minimizando-a e maximizando-a. Você gerencia o conteúdo dentro do quadro.

## <a name="frame-windows-and-views"></a>Janelas de quadros e exibições

A estrutura MFC usa janelas de quadros para conter exibições. Os dois componentes — quadro e conteúdo — são representados e gerenciados por duas classes diferentes no MFC. Uma classe de janela de quadro gerencia o quadro e uma classe de exibição gerencia o conteúdo. A janela exibição é um filho da janela do quadro. O desenho e outra interação do usuário com o documento ocorrem na área cliente da exibição, não na área cliente da janela do quadro. A janela do quadro fornece um quadro visível em uma exibição, completa com uma barra de legenda e controles de janela padrão, como um menu de controle, botões para minimizar e maximizar a janela e controles para redimensionar a janela. O "conteúdo" consiste na área do cliente da janela, que é totalmente ocupada por uma janela filho — a exibição. A figura a seguir mostra a relação entre uma janela de quadro e uma exibição.

![Exibição de janela do quadro](../mfc/media/vc37fx1.gif "Exibição de janela do quadro") <br/>
Janela e exibição do quadro

## <a name="frame-windows-and-splitter-windows"></a>Janelas de quadro e janelas de Splitter

Outra organização comum é a janela do quadro para emoldurar várias exibições, geralmente usando uma [janela](multiple-document-types-views-and-frame-windows.md)separadora. Em uma janela separadora, a área do cliente da janela do quadro é ocupada por uma janela separadora que, por sua vez, tem várias janelas filhas, chamadas painéis, que são exibições.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

**Tópicos da janela de quadro geral**

- [Objetos de janela](window-objects.md)

- [Classes de janela do quadro](frame-window-classes.md)

- [As classes de janela de quadro criadas pelo assistente de aplicativo](frame-window-classes-created-by-the-application-wizard.md)

- [Estilos de janela do quadro](frame-window-styles-cpp.md)

- [O que as janelas de quadro fazem](what-frame-windows-do.md)

**Tópicos sobre como usar janelas de quadros**

- [Usando janelas com moldura](using-frame-windows.md)

- [Criando janelas de quadro de documento](creating-document-frame-windows.md)

- [Destruindo janelas com moldura](destroying-frame-windows.md)

- [Gerenciando janelas filho MDI](managing-mdi-child-windows.md)

- [Gerenciando a exibição atual](managing-the-current-view.md) em uma janela de quadro que contém mais de uma exibição

- [Gerenciando menus, barras de controle e aceleradores (outros objetos que compartilham o espaço da janela do quadro)](managing-menus-control-bars-and-accelerators.md)

**Tópicos sobre recursos de janela de quadro especial**

- [Arrastando e soltando arquivos](dragging-and-dropping-files-in-a-frame-window.md) do explorador de arquivos ou do Gerenciador de arquivos em uma janela de quadro

- [Respondendo ao DDE (intercâmbio de dados dinâmicos)](responding-to-dynamic-data-exchange-dde.md)

- [Estados de semimodal: Ajuda contextual do Windows (orquestrando outras ações de janela)](orchestrating-other-window-actions.md)

- [Estados semimodal: impressão e visualização de impressão (orquestrando outras ações de janela)](orchestrating-other-window-actions.md)

**Tópicos sobre outros tipos de Windows**

- [Usando exibições](using-views.md)

- [Caixas de diálogo](dialog-boxes.md)

- [Controles](controls-mfc.md)

## <a name="see-also"></a>Consulte também

[Windows](windows.md)
