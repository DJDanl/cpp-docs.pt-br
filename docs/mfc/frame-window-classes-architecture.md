---
title: Classes de janela com moldura (arquitetura)
ms.date: 11/04/2016
helpviewer_keywords:
- frame window classes [MFC], document/view architecture
ms.assetid: 5da01fb4-f531-46cc-914f-e422e4f07f5d
ms.openlocfilehash: e3ae432c1adc881a5c67d6a6c292dc1f6a583ab3
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441257"
---
# <a name="frame-window-classes-architecture"></a>Classes de janela com moldura (arquitetura)

Na arquitetura de documento/exibição, janelas de quadros são janelas que contêm uma janela de exibição. Eles também dão suporte à exibição de barras de controle.

Em aplicativos de interface de vários documentos (MDI), a janela principal é derivada de `CMDIFrameWnd`. Ele indiretamente contém os quadros de documentos, que são `CMDIChildWnd` objetos. O `CMDIChildWnd` objetos, por sua vez, contêm as exibições dos documentos.

Em aplicativos de SDI (interface de documento único), a janela principal, derivada de `CFrameWnd`, contém a exibição do documento atual.

[CFrameWnd](../mfc/reference/cframewnd-class.md)<br/>
A classe base para a janela do quadro principal de um aplicativo SDI. Também a classe base para todas as outras classes de janela do quadro.

[CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md)<br/>
A classe base para a janela do quadro principal de um aplicativo MDI.

[CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)<br/>
A classe base para as janelas de quadro de documento de um aplicativo MDI.

[COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md)<br/>
Fornece a janela do quadro para uma exibição quando um documento do servidor está sendo editado no local.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
