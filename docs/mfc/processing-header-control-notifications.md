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
ms.openlocfilehash: 42113b43249b87a351047ab451cb1798aec1f022
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51693341"
---
# <a name="processing-header-control-notifications"></a>Processando notificações de controle do cabeçalho

Em sua classe de exibição ou a caixa de diálogo, use a janela Propriedades para criar uma [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) função de manipulador com uma instrução switch para qualquer controle de cabeçalho ([CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)) mensagens de notificação que você deseja manipular (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)). As notificações são enviadas para a janela pai quando o usuário clica ou clica duas vezes em um item de cabeçalho, arrastar um divisor entre itens e assim por diante.

As mensagens de notificação associadas com um controle de cabeçalho são listadas na [referência de controle de cabeçalho](/windows/desktop/controls/header-control-reference) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

