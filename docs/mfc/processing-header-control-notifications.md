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
ms.openlocfilehash: c313382b8be7538ba5bb465c6ba383955e414662
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619787"
---
# <a name="processing-header-control-notifications"></a>Processando notificações de controle do cabeçalho

Na sua classe View ou Dialog, use o [Assistente de classe](reference/mfc-class-wizard.md) para criar uma função de manipulador [OnChildNotify](reference/cwnd-class.md#onchildnotify) com uma instrução switch para qualquer mensagem de notificação de controle de cabeçalho ([CHeaderCtrl](reference/cheaderctrl-class.md)) que você deseja manipular (consulte [mapeando mensagens para funções](reference/mapping-messages-to-functions.md)). As notificações são enviadas para a janela pai quando o usuário clica ou clica duas vezes em um item de cabeçalho, arrasta um divisor entre os itens e assim por diante.

As mensagens de notificação associadas a um controle de cabeçalho são listadas na [referência de controle de cabeçalho](/windows/win32/controls/header-control-reference) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](using-cheaderctrl.md)<br/>
[Controles](controls-mfc.md)
