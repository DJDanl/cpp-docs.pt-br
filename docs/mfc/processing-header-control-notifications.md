---
title: Processando notificações de controle do cabeçalho
ms.date: 11/04/2016
helpviewer_keywords:
- CHeaderCtrl class [MFC], processing notifications
- controls [MFC], header
- notifications [MFC], processing for CHeaderCtrl
- header controls [MFC], processing notifications
- header control notifications
ms.assetid: e6c6af7c-d458-4d33-85aa-48014ccde5f6
ms.openlocfilehash: bc811763fe3f4717b8baaeb4a23df1ae59bb1979
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70908130"
---
# <a name="processing-header-control-notifications"></a>Processando notificações de controle do cabeçalho

Na sua classe View ou Dialog, use o [Assistente de classe](reference/mfc-class-wizard.md) para criar uma função de manipulador [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) com uma instrução switch para qualquer mensagem de notificação de controle de cabeçalho ([CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)) que você deseja manipular (consulte [mapeando mensagens para Funções](../mfc/reference/mapping-messages-to-functions.md)). As notificações são enviadas para a janela pai quando o usuário clica ou clica duas vezes em um item de cabeçalho, arrasta um divisor entre os itens e assim por diante.

As mensagens de notificação associadas a um controle de cabeçalho são listadas na [referência de controle de cabeçalho](/windows/win32/controls/header-control-reference) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
