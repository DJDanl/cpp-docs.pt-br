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
ms.openlocfilehash: c1696389ce3dc40c5d02ec660ebaeb6bf3e6c3ec
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33345229"
---
# <a name="notifications-sent-by-animation-controls"></a>Notificações enviadas por controles de animação
Um controle de animação ([CAnimateCtrl](../mfc/reference/canimatectrl-class.md)) envia os dois tipos diferentes de mensagens de notificação. As notificações são enviadas na forma de [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagens.  
  
 O [ACN_START](http://msdn.microsoft.com/library/windows/desktop/bb761891) mensagem é enviada quando o controle de animação começou a ser reproduzida um clipe. O [ACN_STOP](http://msdn.microsoft.com/library/windows/desktop/bb761893) mensagem é enviada quando o controle de animação é concluída ou interrompido reproduzir um clipe.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CAnimateCtrl](../mfc/using-canimatectrl.md)   
 [Controles](../mfc/controls-mfc.md)

