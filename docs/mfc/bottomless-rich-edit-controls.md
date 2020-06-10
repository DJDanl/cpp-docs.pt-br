---
title: Controles de edição avançada sem parte inferior
ms.date: 11/04/2016
helpviewer_keywords:
- bottomless rich edit controls
- rich edit controls [MFC], bottomless
- CRichEditCtrl class [MFC], bottomless
ms.assetid: 2877dd32-1e9a-4fd1-98c0-66dcbbeef1de
ms.openlocfilehash: 567bb5b7f2eb2c203b40b9f1f6add82f5451d672
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616429"
---
# <a name="bottomless-rich-edit-controls"></a>Controles de edição avançada sem parte inferior

Seu aplicativo pode redimensionar um[CRichEditCtrl](reference/cricheditctrl-class.md)(controle de edição rico) conforme necessário para que seja sempre o mesmo tamanho que seu conteúdo. Um controle de edição rico dá suporte a essa chamada de funcionalidade "sem interrupções" enviando sua janela pai um [EN_REQUESTRESIZE](/windows/win32/Controls/en-requestresize) mensagem de notificação sempre que o tamanho do seu conteúdo é alterado.

Ao processar a mensagem de notificação **EN_REQUESTRESIZE** , um aplicativo deve redimensionar o controle para as dimensões na estrutura [REQRESIZE](/windows/win32/api/richedit/ns-richedit-reqresize) especificada. Um aplicativo também pode mover qualquer informação perto do controle para acomodar a alteração do controle em altura. Para redimensionar o controle, você pode usar a `CWnd` função [SetWindowPos](reference/cwnd-class.md#setwindowpos).

Você pode forçar um controle de edição mais baixo para enviar uma mensagem de notificação de **EN_REQUESTRESIZE** usando a função de membro [REQUESTRESIZE](reference/cricheditctrl-class.md#requestresize) . Essa mensagem pode ser útil no manipulador [OnSize](reference/cwnd-class.md#onsize) .

Para receber **EN_REQUESTRESIZE** mensagens de notificação, você deve habilitar a notificação usando a `SetEventMask` função de membro.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](using-cricheditctrl.md)<br/>
[Controles](controls-mfc.md)
