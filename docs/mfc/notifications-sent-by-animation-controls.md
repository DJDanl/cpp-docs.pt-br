---
title: Notificações enviadas por controles de animação
ms.date: 11/04/2016
helpviewer_keywords:
- notifications [MFC], animation controls
- CAnimateCtrl class [MFC], notifications
- controls [MFC], animation
- animation controls [MFC], notifications
ms.assetid: 584f5824-446b-4a1a-85f7-ef61842c8186
ms.openlocfilehash: 68ede3bc55669a29eef192d38b29b8c1ab433e4b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508024"
---
# <a name="notifications-sent-by-animation-controls"></a>Notificações enviadas por controles de animação

Um controle de animação ([CAnimateCtrl](../mfc/reference/canimatectrl-class.md)) envia dois tipos diferentes de mensagens de notificação. As notificações são enviadas na forma de mensagens [WM_COMMAND](/windows/win32/menurc/wm-command) .

A mensagem [ACN_START](/windows/win32/Controls/acn-start) é enviada quando o controle de animação começa a reproduzir um clipe. A mensagem [ACN_STOP](/windows/win32/Controls/acn-stop) é enviada quando o controle de animação termina ou parou de reproduzir um clipe.

## <a name="see-also"></a>Consulte também

[Usando CAnimateCtrl](../mfc/using-canimatectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
