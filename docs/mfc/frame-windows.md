---
title: Windows de quadro | Microsoft Docs
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
- frame windows [MFC], about frame windows
- MFC, frame windows
- MDI [MFC], frame windows
- splitter windows [MFC], and frame windows
ms.assetid: 40677339-8135-4f5e-aba6-3fced3078077
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 895476da05d4480741577a04749df4be43016006
ms.sourcegitcommit: e4a690bf33b44432179de0bc537e26616d13c553
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/09/2018
ms.locfileid: "48892170"
---
# <a name="frame-windows"></a>Janelas com moldura

Quando um aplicativo é executado em Windows, o usuário interage com documentos exibidos em janelas com moldura. Uma janela de quadro do documento tem dois componentes principais: o quadro e o conteúdo que ela se enquadra. Uma janela de quadro do documento pode ser um [interface SDI](../mfc/sdi-and-mdi.md) janela de quadro (SDI) ou um [interface de documentos múltiplos](../mfc/sdi-and-mdi.md) janela filho da (MDI). Windows gerencia a maioria da interação do usuário com a janela do quadro: mover e redimensionar a janela, fechá-la e minimizar e maximizando a ele. Você gerencia o conteúdo dentro do quadro.

## <a name="frame-windows-and-views"></a>Modos de exibição e o Windows de quadro

Estrutura MFC usa janelas de quadro contenha modos de exibição. Os dois componentes — quadro e conteúdo — são representados e gerenciados por duas classes diferentes no MFC. Uma classe de janela com moldura gerencia o quadro e uma classe de exibição gerencia o conteúdo. A janela de exibição é um filho da janela do quadro. Desenho e outra interação do usuário com o documento assumir o lugar na área de cliente do modo de exibição, não área de cliente da janela do quadro. A janela do quadro fornece um quadro visível em torno de uma exibição, completo com uma barra de legenda e os controles de janela padrão como um menu de controle, botões minimizar e maximizar a janela e controles para redimensionamento da janela. O "conteúdo" consistem em área de cliente da janela, que fica totalmente ocupada por uma janela filho — o modo de exibição. A figura a seguir mostra a relação entre uma janela de quadro em uma exibição.

![Exibição da janela de quadro](../mfc/media/vc37fx1.gif "vc37fx1") janela de quadro e o modo de exibição

## <a name="frame-windows-and-splitter-windows"></a>Quadro Windows e Windows divisor

Outra organização comum é para a janela do quadro enquadrar vários modos de exibição, normalmente usando um [janela divisora](../mfc/multiple-document-types-views-and-frame-windows.md). Em uma janela separadora, área de cliente da janela de quadro está ocupada por uma janela separadora, que por sua vez, tem várias janelas filho, chamadas de painéis, que são exibições.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

**Tópicos da janela de quadro geral**

- [Objetos de janela](../mfc/window-objects.md)

- [Classes de janela com moldura](../mfc/frame-window-classes.md)

- [As classes de janela com moldura criadas pelo Assistente de aplicativo](../mfc/frame-window-classes-created-by-the-application-wizard.md)

- [Estilos de janela de quadro](../mfc/frame-window-styles-cpp.md)

- [O que fazem janelas com moldura](../mfc/what-frame-windows-do.md)

**Tópicos sobre como usar o Windows de quadro**

- [Usando janelas com moldura](../mfc/using-frame-windows.md)

- [Criando janelas com moldura de documento](../mfc/creating-document-frame-windows.md)

- [Destruindo janelas com moldura](../mfc/destroying-frame-windows.md)

- [Gerenciando janelas filhos MDI](../mfc/managing-mdi-child-windows.md)

- [Gerenciando a exibição atual](../mfc/managing-the-current-view.md) em uma janela do quadro que contém mais de uma exibição

- [Gerenciando menus, barras de controle e aceleradores (outros objetos que compartilham o espaço da janela de quadro)](../mfc/managing-menus-control-bars-and-accelerators.md)

**Tópicos sobre os recursos especiais do quadro de janela**

- [Arrastando e soltando arquivos](../mfc/dragging-and-dropping-files-in-a-frame-window.md) do Explorador de arquivos ou do Gerenciador de arquivo em uma janela do quadro

- [Respondendo à troca dinâmica de dados (DDE)](../mfc/responding-to-dynamic-data-exchange-dde.md)

- [Estados semimodais: Ajuda do Windows contextual (Orquestrando outras ações de janela)](../mfc/orchestrating-other-window-actions.md)

- [Estados semimodais: impressão e visualização de impressão (Orquestrando outras ações de janela)](../mfc/orchestrating-other-window-actions.md)

**Tópicos sobre outros tipos de Windows**

- [Usando exibições](../mfc/using-views.md)

- [Caixas de diálogo](../mfc/dialog-boxes.md)

- [Controles](../mfc/controls-mfc.md)

## <a name="see-also"></a>Consulte também

[Windows](../mfc/windows.md)

