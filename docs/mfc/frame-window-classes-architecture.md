---
title: Classes de janela com moldura (arquitetura)
ms.date: 11/04/2016
helpviewer_keywords:
- frame window classes [MFC], document/view architecture
ms.assetid: 5da01fb4-f531-46cc-914f-e422e4f07f5d
ms.openlocfilehash: 483112d197b7c7211989ecda8b774deb9f30d49e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624604"
---
# <a name="frame-window-classes-architecture"></a>Classes de janela com moldura (arquitetura)

Na arquitetura de documento/exibição, janelas de quadros são janelas que contêm uma janela de exibição. Eles também dão suporte à exibição de barras de controle.

Em aplicativos de interface de vários documentos (MDI), a janela principal é derivada de `CMDIFrameWnd` . Ele indiretamente contém os quadros de documentos, que são `CMDIChildWnd` objetos. Os `CMDIChildWnd` objetos, por sua vez, contêm as exibições dos documentos.

Em aplicativos de SDI (interface de documento único), a janela principal, derivada de `CFrameWnd` , contém a exibição do documento atual.

[CFrameWnd](reference/cframewnd-class.md)<br/>
A classe base para a janela do quadro principal de um aplicativo SDI. Também a classe base para todas as outras classes de janela do quadro.

[CMDIFrameWnd](reference/cmdiframewnd-class.md)<br/>
A classe base para a janela do quadro principal de um aplicativo MDI.

[CMDIChildWnd](reference/cmdichildwnd-class.md)<br/>
A classe base para as janelas de quadro de documento de um aplicativo MDI.

[COleIPFrameWnd](reference/coleipframewnd-class.md)<br/>
Fornece a janela do quadro para uma exibição quando um documento do servidor está sendo editado no local.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
