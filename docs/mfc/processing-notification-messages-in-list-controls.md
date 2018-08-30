---
title: Processando mensagens de notificação em controles de lista | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- processing notifications [MFC]
- CListCtrl class [MFC], processing notifications
ms.assetid: 1f0e296e-d2a3-48fc-ae38-51d7fb096f51
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3362074ce0f8d4d7a3a3463d22f9089f847e747d
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43208704"
---
# <a name="processing-notification-messages-in-list-controls"></a>Processando mensagens de notificação em controles de lista
Quando os usuários em cabeçalhos de coluna, arraste os ícones, editar rótulos e assim por diante, o controle de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)) envia mensagens de notificação à sua janela pai. Se você quiser fazer algo em resposta, lidar com essas mensagens. Por exemplo, quando o usuário clica em um cabeçalho de coluna, você talvez queira classificar os itens com base no conteúdo da coluna clicada, como no Microsoft Outlook.  
  
 Processar mensagens WM_NOTIFY do controle de lista em sua classe de exibição ou a caixa de diálogo. Use a janela Propriedades para criar uma [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) função de manipulador com uma instrução de comutação com base em qual mensagem de notificação está sendo manipulada.  
  
 Para obter uma lista das notificações de um controle de lista pode enviar para sua janela pai, consulte [referência de controle de exibição de lista](/windows/desktop/Controls/list-view-control-reference) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

