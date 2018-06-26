---
title: Processando mensagens de notificação de controle de guia | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- notifications [MFC], tab controls
- CTabCtrl class [MFC], processing notifications
- notifications [MFC], processing in CTabCtrl
- processing notifications [MFC]
- tab controls [MFC], processing notifications
ms.assetid: 758ccb7a-9e73-48f8-9073-23f7cb09918c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 462d9177b1f6300eb356d052cbdfff3b85db86a1
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36928056"
---
# <a name="processing-tab-control-notification-messages"></a>Processando mensagens de notificação do controle de guia
Como os usuários clicam em guias ou botões, o controle de guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)) envia mensagens de notificação para sua janela pai. Se você quiser fazer algo em resposta, lidar com essas mensagens. Por exemplo, quando o usuário clica em uma guia, você talvez queira predefinição dados de controle na página antes de exibi-lo.  
  
 Processar mensagens WM_NOTIFY do controle guia em sua classe de exibição ou a caixa de diálogo. Use a janela de propriedades para criar um [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) função de manipulador com uma instrução switch com base em qual mensagem de notificação está sendo tratada. Para obter uma lista das notificações de um controle guia pode enviar para sua janela pai, consulte o **notificações** seção [referência de controle de guia](http://msdn.microsoft.com/library/windows/desktop/bb760548) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTabCtrl](../mfc/using-ctabctrl.md)   
 [Controles](../mfc/controls-mfc.md)

