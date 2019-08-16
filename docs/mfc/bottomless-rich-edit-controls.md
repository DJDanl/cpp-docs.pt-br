---
title: Controles de edição avançada sem parte inferior
ms.date: 11/04/2016
helpviewer_keywords:
- bottomless rich edit controls
- rich edit controls [MFC], bottomless
- CRichEditCtrl class [MFC], bottomless
ms.assetid: 2877dd32-1e9a-4fd1-98c0-66dcbbeef1de
ms.openlocfilehash: 4affdbeed723ea83beda785116dc4c45771073b2
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69509155"
---
# <a name="bottomless-rich-edit-controls"></a>Controles de edição avançada sem parte inferior

Seu aplicativo pode redimensionar um[CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)(controle de edição rico) conforme necessário para que seja sempre o mesmo tamanho que seu conteúdo. Um controle de edição rico dá suporte a essa chamada de funcionalidade "sem interrupções" enviando sua janela pai uma mensagem de notificação [EN_REQUESTRESIZE](/windows/win32/Controls/en-requestresize) sempre que o tamanho de seu conteúdo é alterado.

Ao processar a mensagem de notificação **EN_REQUESTRESIZE** , um aplicativo deve redimensionar o controle para as dimensões na estrutura [REQRESIZE](/windows/win32/api/richedit/ns-richedit-reqresize) especificada. Um aplicativo também pode mover qualquer informação perto do controle para acomodar a alteração do controle em altura. Para redimensionar o controle, você pode usar `CWnd` a função [SetWindowPos](../mfc/reference/cwnd-class.md#setwindowpos).

Você pode forçar um controle de edição mais baixo para enviar uma mensagem de notificação **EN_REQUESTRESIZE** usando a função membro [REQUESTRESIZE](../mfc/reference/cricheditctrl-class.md#requestresize) . Essa mensagem pode ser útil no manipulador [OnSize](../mfc/reference/cwnd-class.md#onsize) .

Para receber mensagens de notificação do **EN_REQUESTRESIZE** , você deve habilitar a notificação usando `SetEventMask` a função de membro.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
