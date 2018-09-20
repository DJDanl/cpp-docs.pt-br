---
title: Windows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- objects [MFC], window
- windows [MFC]
- MFC, windows
- window objects [MFC], MFC Framework
ms.assetid: dd92bf34-842e-40fe-8aea-3028b55314d5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 664afc2d842a7072ed41d579939e530e01c6e33f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46431769"
---
# <a name="windows"></a>Windows

Essa família de artigos aborda os objetos de janela na estrutura MFC. Todas as janelas MFC derivam da classe [CWnd](../mfc/reference/cwnd-class.md), incluindo janelas de quadro, modos de exibição, caixas de diálogo e controles.

O primeiro grupo de artigos descreve [objetos de janela](../mfc/window-objects.md) em geral. Fazer referência a esse grupo para obter informações gerais sobre os objetos de janela C++, como eles encapsulam um `HWND`, e como você usá-los ao criar suas próprias janelas, como janelas filho.

O segundo grupo de artigos descreve [janelas com moldura](../mfc/frame-windows.md)— windows que colocar um quadro em torno do conteúdo — em particular. Se referir a esse grupo para obter informações sobre como a estrutura MFC gerencia janelas de quadro e o conteúdo que o quadro, incluindo exibições e barras de controle.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

*Tópicos sobre objetos de janela em geral*

- [Objetos de janela](../mfc/window-objects.md)

- [Relação entre um C++ lida com objetos de janela e HWND](../mfc/relationship-between-a-cpp-window-object-and-an-hwnd.md)

- [Classes de janela derivadas](../mfc/derived-window-classes.md)

- [Criando objetos de janela](../mfc/creating-windows.md)

- [Destruindo objetos de janela](../mfc/destroying-window-objects.md)

- [Registrando classes"janela"](../mfc/registering-window-classes.md)

- [Trabalhando com objetos de janela](../mfc/working-with-window-objects.md)

- [Contextos de dispositivo](../mfc/device-contexts.md): objetos que tornam a criação do Windows independente de dispositivo

- [Objetos gráficos](../mfc/graphic-objects.md): canetas, pincéis, fontes, bitmaps, paletas, regiões

*Tópicos da janela de quadro*

- [Janelas com moldura](../mfc/frame-windows.md): objetos de janela que fornecem quadros

- [Exibições e janelas com moldura](../mfc/frame-windows.md)

- [Classes de janela com moldura](../mfc/frame-window-classes.md)

- [Estilos de janela com moldura](../mfc/frame-window-styles-cpp.md)

- [Alternando os estilos de uma janela criada por MFC](../mfc/changing-the-styles-of-a-window-created-by-mfc.md)

- [O que fazem janelas com moldura](../mfc/what-frame-windows-do.md)

- [Usando janelas com moldura](../mfc/using-frame-windows.md)

- [Gerenciando janelas filho/MD (a janela MDICLIENT)](../mfc/managing-mdi-child-windows.md)

- [Gerenciando menus, barras de controle e aceleradores](../mfc/managing-menus-control-bars-and-accelerators.md)

- [CFrameWnd](../mfc/reference/cframewnd-class.md)

- [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md)

- [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)

- [Usando exibições](../mfc/using-views.md)

- [Vários tipos de documento, exibições e Windows de quadro (janelas separadoras)](../mfc/multiple-document-types-views-and-frame-windows.md)

- [Mensagens (mapas e funções do manipulador)](../mfc/messages.md)

*Criar e destruir o Windows*

- [Sequência de criação da janela geral](../mfc/general-window-creation-sequence.md)

- [Destruir objetos de janela](../mfc/destroying-window-objects.md)

- [Crie janelas com moldura de documento](../mfc/creating-document-frame-windows.md)

- [Destruir janelas com moldura](../mfc/destroying-frame-windows.md)

*Criar Windows divisor*

- [Criar janelas separadoras](../mfc/multiple-document-types-views-and-frame-windows.md)

*Gerenciar o Windows filho e o modo de exibição atual*

- [Gerenciar janelas filho MDI](../mfc/managing-mdi-child-windows.md)

- [Gerenciar o modo de exibição atual](../mfc/managing-the-current-view.md)

- [Gerenciar os menus, barras de controle e aceleradores](../mfc/managing-menus-control-bars-and-accelerators.md)

*Trabalhar com estilos de janela e contextos de dispositivo*

- [Usar canetas e outros objetos gráficos em um contexto de dispositivo](../mfc/graphic-objects.md)

- [Alterar os estilos de uma janela criada por MFC](../mfc/changing-the-styles-of-a-window-created-by-mfc.md)

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)<br/>
[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Barras de ferramentas](../mfc/toolbars.md)<br/>
[Barras de status](../mfc/status-bars.md)<br/>
[Barras da caixa de diálogo](../mfc/dialog-bars.md)

