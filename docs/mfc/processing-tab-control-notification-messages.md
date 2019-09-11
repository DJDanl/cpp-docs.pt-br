---
title: Processando mensagens de notificação do controle de guia
ms.date: 11/04/2016
helpviewer_keywords:
- notifications [MFC], tab controls
- CTabCtrl class [MFC], processing notifications
- notifications [MFC], processing in CTabCtrl
- processing notifications [MFC]
- tab controls [MFC], processing notifications
ms.assetid: 758ccb7a-9e73-48f8-9073-23f7cb09918c
ms.openlocfilehash: cc322a038717d48f440df1ec571674cec80743ce
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70908070"
---
# <a name="processing-tab-control-notification-messages"></a>Processando mensagens de notificação do controle de guia

Como os usuários clicam em guias ou botões, o controle guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)) envia mensagens de notificação para sua janela pai. Manipule essas mensagens se desejar fazer algo em resposta. Por exemplo, quando o usuário clica em uma guia, talvez você queira predefinir os dados de controle na página antes de exibi-los.

Processar mensagens WM_NOTIFY do controle guia na sua exibição ou classe de caixa de diálogo. Use o [Assistente de classe](reference/mfc-class-wizard.md) para criar uma função de manipulador [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) com uma instrução switch com base na qual a mensagem de notificação está sendo manipulada. Para obter uma lista das notificações que um controle guia pode enviar para sua janela pai, consulte a seção **notificações** da [referência de controle de guia](/windows/win32/controls/tab-control-reference) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CTabCtrl](../mfc/using-ctabctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
