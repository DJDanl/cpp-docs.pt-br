---
title: Notificações enviadas por controles de animação
ms.date: 11/04/2016
helpviewer_keywords:
- notifications [MFC], animation controls
- CAnimateCtrl class [MFC], notifications
- controls [MFC], animation
- animation controls [MFC], notifications
ms.assetid: 584f5824-446b-4a1a-85f7-ef61842c8186
ms.openlocfilehash: e9e5b94736de44d5cfeef81f5b78a759df3b8aa0
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619905"
---
# <a name="notifications-sent-by-animation-controls"></a>Notificações enviadas por controles de animação

Um controle de animação ([CAnimateCtrl](reference/canimatectrl-class.md)) envia dois tipos diferentes de mensagens de notificação. As notificações são enviadas na forma de mensagens de [WM_COMMAND](/windows/win32/menurc/wm-command) .

A mensagem de [ACN_START](/windows/win32/Controls/acn-start) é enviada quando o controle de animação começa a reproduzir um clipe. A mensagem de [ACN_STOP](/windows/win32/Controls/acn-stop) é enviada quando o controle de animação termina ou parou de reproduzir um clipe.

## <a name="see-also"></a>Consulte também

[Usando CAnimateCtrl](using-canimatectrl.md)<br/>
[Controles](controls-mfc.md)
