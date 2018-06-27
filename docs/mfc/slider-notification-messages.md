---
title: Mensagens de notificação do controle deslizante | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CSliderCtrl class [MFC], notifications
- slider controls [MFC], notification messages
- messages, notification
- notifications [MFC], CSliderCtrl
ms.assetid: b9121104-3889-4a10-92bf-f3723f1af9d0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c383458905d16dda935254e56a5aa9f56a153e83
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36956155"
---
# <a name="slider-notification-messages"></a>Mensagens de notificação do controle deslizante
Um controle deslizante notificará sua janela pai de ações de usuário enviando mensagens WM_HSCROLL ou WM_VSCROLL, dependendo da orientação do controle deslizante para o pai. Para lidar com essas mensagens, adicione manipuladores para mensagens de WM_HSCROLL e WM_VSCROLL para a janela pai. O [OnHScroll](../mfc/reference/cwnd-class.md#onhscroll) e [OnVScroll](../mfc/reference/cwnd-class.md#onvscroll) funções de membro serão passadas um código de notificação, a posição do controle deslizante e um ponteiro para o [CSliderCtrl](../mfc/reference/csliderctrl-class.md) objeto. Observe que o ponteiro for do tipo `CScrollBar *` mesmo que ele aponta para um `CSliderCtrl` objeto. Você precisará de conversão de tipo deste ponteiro caso você precise manipular o controle deslizante.  
  
 Em vez de usar a códigos de notificação da barra de rolagem, controles deslizantes enviar um conjunto diferente de códigos de notificação. Um controle deslizante envia os códigos de notificação TB_BOTTOM, TB_LINEDOWN, TB_LINEUP e TB_TOP somente quando o usuário interage com um controle deslizante usando o teclado. As mensagens de notificação TB_THUMBPOSITION e TB_THUMBTRACK são enviadas somente quando o usuário estiver usando o mouse. Os códigos de notificação TB_ENDTRACK, TB_PAGEDOWN e TB_PAGEUP são enviados em ambos os casos.  
  
 A tabela a seguir lista as mensagens de notificação do controle deslizante e os eventos (códigos de tecla virtuais ou eventos de mouse) que fazem as envio de notificações. (Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser.)  
  
|Mensagem de notificação|Evento que causa a notificação seja enviada|  
|--------------------------|-------------------------------------------|  
|TB_BOTTOM|VK_END|  
|TB_ENDTRACK|WM_KEYUP (o usuário lançado uma chave que é enviado um código de tecla virtual relevante)|  
|TB_LINEDOWN|VK_RIGHT ou VK_DOWN|  
|TB_LINEUP|VK_LEFT ou VK_UP|  
|TB_PAGEDOWN|VK_NEXT (o usuário clicou o canal abaixo ou à direita do controle deslizante)|  
|TB_PAGEUP|VK_PRIOR (o usuário clicou o canal acima ou à esquerda do controle deslizante)|  
|TB_THUMBPOSITION|WM_LBUTTONUP uma mensagem de notificação TB_THUMBTRACK|  
|TB_THUMBTRACK|Movimentação do controle deslizante (o usuário arrastado o controle deslizante)|  
|TB_TOP|VK_HOME|  
  
## <a name="see-also"></a>Consulte também  
 [Usando CSliderCtrl](../mfc/using-csliderctrl.md)   
 [Controles](../mfc/controls-mfc.md)

