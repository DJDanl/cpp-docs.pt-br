---
title: Notificações enviadas por controles de animação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- notifications [MFC], animation controls
- CAnimateCtrl class [MFC], notifications
- controls [MFC], animation
- animation controls [MFC], notifications
ms.assetid: 584f5824-446b-4a1a-85f7-ef61842c8186
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eb83fe6195c01c1e9dbcc2c00e43738af9ebc8e2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46386386"
---
# <a name="notifications-sent-by-animation-controls"></a>Notificações enviadas por controles de animação

Um controle de animação ([CAnimateCtrl](../mfc/reference/canimatectrl-class.md)) envia dois tipos diferentes de mensagens de notificação. As notificações são enviadas na forma de [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagens.

O [ACN_START](/windows/desktop/Controls/acn-start) mensagem é enviada quando o controle de animação foi iniciada, reproduzindo um clipe. O [ACN_STOP](/windows/desktop/Controls/acn-stop) mensagem é enviada quando o controle de animação tiver concluído ou interrompido reproduzindo um clipe.

## <a name="see-also"></a>Consulte também

[Usando CAnimateCtrl](../mfc/using-canimatectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

