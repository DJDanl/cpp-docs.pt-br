---
title: Notificações enviadas por controles de animação
ms.date: 11/04/2016
helpviewer_keywords:
- notifications [MFC], animation controls
- CAnimateCtrl class [MFC], notifications
- controls [MFC], animation
- animation controls [MFC], notifications
ms.assetid: 584f5824-446b-4a1a-85f7-ef61842c8186
ms.openlocfilehash: 2a736e4315091b1b26daceb4fe0ce9672ab33ff6
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57281259"
---
# <a name="notifications-sent-by-animation-controls"></a>Notificações enviadas por controles de animação

Um controle de animação ([CAnimateCtrl](../mfc/reference/canimatectrl-class.md)) envia dois tipos diferentes de mensagens de notificação. As notificações são enviadas na forma de [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagens.

O [ACN_START](/windows/desktop/Controls/acn-start) mensagem é enviada quando o controle de animação foi iniciada, reproduzindo um clipe. O [ACN_STOP](/windows/desktop/Controls/acn-stop) mensagem é enviada quando o controle de animação tiver concluído ou interrompido reproduzindo um clipe.

## <a name="see-also"></a>Consulte também

[Usando CAnimateCtrl](../mfc/using-canimatectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
