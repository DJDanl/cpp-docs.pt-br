---
title: Mensagens de notificação do controle deslizante
ms.date: 11/04/2016
helpviewer_keywords:
- CSliderCtrl class [MFC], notifications
- slider controls [MFC], notification messages
- messages, notification
- notifications [MFC], CSliderCtrl
ms.assetid: b9121104-3889-4a10-92bf-f3723f1af9d0
ms.openlocfilehash: bee2d602512ea1a6af39b0bb218ee7333b399c80
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57294221"
---
# <a name="slider-notification-messages"></a>Mensagens de notificação do controle deslizante

Um controle deslizante notifica sua janela pai de ações do usuário enviando mensagens WM_HSCROLL ou WM_VSCROLL mensagens, dependendo da orientação do controle deslizante para o pai. Para lidar com essas mensagens, adicione manipuladores para as mensagens de mensagens WM_HSCROLL e WM_VSCROLL para a janela pai. O [OnHScroll](../mfc/reference/cwnd-class.md#onhscroll) e [OnVScroll](../mfc/reference/cwnd-class.md#onvscroll) funções de membro serão passadas um código de notificação, a posição do controle deslizante e um ponteiro para o [CSliderCtrl](../mfc/reference/csliderctrl-class.md) objeto. Observe que o ponteiro for do tipo `CScrollBar *` mesmo que ele aponta para um `CSliderCtrl` objeto. Talvez você precise estereotipado esse ponteiro, se você precisar manipular o controle deslizante.

Em vez de usar a códigos de notificação da barra de rolagem, controles deslizantes enviam um conjunto diferente de códigos de notificação. Um controle deslizante envia os códigos de notificação TB_BOTTOM, TB_LINEDOWN, TB_LINEUP e TB_TOP somente quando o usuário interage com um controle deslizante usando o teclado. As mensagens de notificação TB_THUMBPOSITION e TB_THUMBTRACK são enviadas somente quando o usuário está usando o mouse. Os códigos de notificação TB_ENDTRACK, TB_PAGEDOWN e TB_PAGEUP são enviados em ambos os casos.

A tabela a seguir lista as mensagens de notificação do controle deslizante e eventos (códigos de tecla virtuais ou eventos de mouse) que fazem com que as notificações sejam enviadas. (Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h).

|Mensagem de notificação|Evento que causa a notificação seja enviada|
|--------------------------|-------------------------------------------|
|TB_BOTTOM|VK_END|
|TB_ENDTRACK|WM_KEYUP (o usuário soltou uma chave que é enviado um código de tecla virtual relevante)|
|TB_LINEDOWN|VK_RIGHT ou VK_DOWN|
|TB_LINEUP|VK_LEFT ou VK_UP|
|TB_PAGEDOWN|VK_NEXT (o usuário clicou no canal abaixo ou à direita do controle deslizante)|
|TB_PAGEUP|VK_PRIOR (o usuário clicou no canal acima ou à esquerda do controle deslizante)|
|TB_THUMBPOSITION|WM_LBUTTONUP seguindo uma mensagem de notificação TB_THUMBTRACK|
|TB_THUMBTRACK|Movimentação de controle deslizante (o usuário arrastar o controle deslizante)|
|TB_TOP|VK_HOME|

## <a name="see-also"></a>Consulte também

[Usando CSliderCtrl](../mfc/using-csliderctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
