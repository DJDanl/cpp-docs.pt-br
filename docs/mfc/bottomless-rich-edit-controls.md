---
title: Controles de edição avançada sem parte inferior
ms.date: 11/04/2016
helpviewer_keywords:
- bottomless rich edit controls
- rich edit controls [MFC], bottomless
- CRichEditCtrl class [MFC], bottomless
ms.assetid: 2877dd32-1e9a-4fd1-98c0-66dcbbeef1de
ms.openlocfilehash: 6f078680777dcf80a4349ea34e4520cb56031f44
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400741"
---
# <a name="bottomless-rich-edit-controls"></a>Controles de edição avançada sem parte inferior

Seu aplicativo pode redimensionar um controle rich edit ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) conforme necessário para que ele é sempre o mesmo tamanho que o seu conteúdo. Um controle rich edit dá suporte a essa funcionalidade chamada de "ilimitada", enviando sua janela pai um [EN_REQUESTRESIZE](/windows/desktop/Controls/en-requestresize) mensagem de notificação sempre que o tamanho de seu conteúdo é alterado.

Ao processar o **EN_REQUESTRESIZE** mensagem de notificação, um aplicativo deve redimensionar o controle para as dimensões em especificado [REQRESIZE](/windows/desktop/api/richedit/ns-richedit-_reqresize) estrutura. Um aplicativo também pode mover todas as informações próximo ao controle para acomodar a alteração do controle de altura. Para redimensionar o controle, você pode usar o `CWnd` função [SetWindowPos](../mfc/reference/cwnd-class.md#setwindowpos).

Você pode forçar um controle de edição avançada sem parte inferior para enviar uma **EN_REQUESTRESIZE** mensagem de notificação usando o [RequestResize](../mfc/reference/cricheditctrl-class.md#requestresize) função de membro. Essa mensagem pode ser útil para o [OnSize](../mfc/reference/cwnd-class.md#onsize) manipulador.

Para receber **EN_REQUESTRESIZE** mensagens de notificação, você deve habilitar a notificação usando o `SetEventMask` função de membro.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
