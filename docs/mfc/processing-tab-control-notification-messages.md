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
ms.openlocfilehash: 75b19033a31d707fcc87c1b5c824acffca725c96
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50441958"
---
# <a name="processing-tab-control-notification-messages"></a>Processando mensagens de notificação do controle de guia

Como os usuários clicam guias ou botões, o controle de guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)) envia mensagens de notificação à sua janela pai. Se você quiser fazer algo em resposta, lidar com essas mensagens. Por exemplo, quando o usuário clica em uma guia, você talvez queira predefinição de dados de controle na página antes de exibi-la.

Processar mensagens WM_NOTIFY do controle guia na sua classe de exibição ou a caixa de diálogo. Use a janela Propriedades para criar uma [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) função de manipulador com uma instrução de comutação com base em qual mensagem de notificação está sendo manipulada. Para obter uma lista das notificações de um controle guia pode enviar para sua janela pai, consulte o **notificações** seção [referência de controle de guia](https://msdn.microsoft.com/library/windows/desktop/bb760548) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CTabCtrl](../mfc/using-ctabctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

