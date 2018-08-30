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
ms.openlocfilehash: d7aff43577a4b1aa55fc0725ba4753228e334000
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43199655"
---
# <a name="notifications-sent-by-animation-controls"></a>Notificações enviadas por controles de animação
Um controle de animação ([CAnimateCtrl](../mfc/reference/canimatectrl-class.md)) envia dois tipos diferentes de mensagens de notificação. As notificações são enviadas na forma de [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagens.  
  
 O [ACN_START](/windows/desktop/Controls/acn-start) mensagem é enviada quando o controle de animação foi iniciada, reproduzindo um clipe. O [ACN_STOP](/windows/desktop/Controls/acn-stop) mensagem é enviada quando o controle de animação tiver concluído ou interrompido reproduzindo um clipe.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CAnimateCtrl](../mfc/using-canimatectrl.md)   
 [Controles](../mfc/controls-mfc.md)

