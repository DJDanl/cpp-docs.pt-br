---
title: "Processando mensagens de notificação de controle de guia | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- notifications [MFC], tab controls
- CTabCtrl class [MFC], processing notifications
- notifications [MFC], processing in CTabCtrl
- processing notifications [MFC]
- tab controls [MFC], processing notifications
ms.assetid: 758ccb7a-9e73-48f8-9073-23f7cb09918c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 840ff6fc5dd47a2059e62608b5a5d6f231f8f17c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="processing-tab-control-notification-messages"></a>Processando mensagens de notificação do controle de guia
Como os usuários clicam em guias ou botões, o controle de guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)) envia mensagens de notificação para sua janela pai. Se você quiser fazer algo em resposta, lidar com essas mensagens. Por exemplo, quando o usuário clica em uma guia, você talvez queira predefinição dados de controle na página antes de exibi-lo.  
  
 Processo **WM_NOTIFY** mensagens de controle guia em sua classe de exibição ou a caixa de diálogo. Use a janela de propriedades para criar um [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) função de manipulador com uma instrução switch com base em qual mensagem de notificação está sendo tratada. Para obter uma lista das notificações de um controle guia pode enviar para sua janela pai, consulte o **notificações** seção [referência de controle de guia](http://msdn.microsoft.com/library/windows/desktop/bb760548) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTabCtrl](../mfc/using-ctabctrl.md)   
 [Controles](../mfc/controls-mfc.md)

