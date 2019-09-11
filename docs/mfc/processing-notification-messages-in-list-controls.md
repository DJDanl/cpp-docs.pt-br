---
title: Processando mensagens de notificação em controles de lista
ms.date: 11/04/2016
helpviewer_keywords:
- processing notifications [MFC]
- CListCtrl class [MFC], processing notifications
ms.assetid: 1f0e296e-d2a3-48fc-ae38-51d7fb096f51
ms.openlocfilehash: 92111e3e0a4869ca06b89d2d18d38aab9f10ab7d
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70908088"
---
# <a name="processing-notification-messages-in-list-controls"></a>Processando mensagens de notificação em controles de lista

Como os usuários clicam em cabeçalhos de coluna, arrastam ícones, editam rótulos e assim por diante, o controle de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)) envia mensagens de notificação para sua janela pai. Manipule essas mensagens se desejar fazer algo em resposta. Por exemplo, quando o usuário clica em um cabeçalho de coluna, talvez você queira classificar os itens com base no conteúdo da coluna clicada, como no Microsoft Outlook.

Processar mensagens WM_NOTIFY do controle de lista em sua classe View ou Dialog. Use o [Assistente de classe](reference/mfc-class-wizard.md) para criar uma função de manipulador [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) com uma instrução switch com base na qual a mensagem de notificação está sendo manipulada.

Para obter uma lista das notificações que um controle de lista pode enviar para sua janela pai, consulte [referência de controle de exibição de lista](/windows/win32/Controls/list-view-control-reference) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
