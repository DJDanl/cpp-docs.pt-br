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
ms.openlocfilehash: b003e23a1fef2b44600b9fd15dfe4ca541df5369
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33381973"
---
# <a name="slider-notification-messages"></a>Mensagens de notificação do controle deslizante
Um controle deslizante notificará sua janela pai de ações de usuário enviando pai `WM_HSCROLL` ou `WM_VSCROLL` mensagens, dependendo da orientação do controle deslizante. Para lidar com essas mensagens, adicionar manipuladores para o `WM_HSCROLL` e `WM_VSCROLL` mensagens para a janela pai. O [OnHScroll](../mfc/reference/cwnd-class.md#onhscroll) e [OnVScroll](../mfc/reference/cwnd-class.md#onvscroll) funções de membro serão passadas um código de notificação, a posição do controle deslizante e um ponteiro para o [CSliderCtrl](../mfc/reference/csliderctrl-class.md) objeto. Observe que o ponteiro for do tipo **CScrollBar \***  mesmo que ele aponta para um `CSliderCtrl` objeto. Você precisará de conversão de tipo deste ponteiro caso você precise manipular o controle deslizante.  
  
 Em vez de usar a códigos de notificação da barra de rolagem, controles deslizantes enviar um conjunto diferente de códigos de notificação. Envia um controle deslizante de **TB_BOTTOM**, **TB_LINEDOWN**, **TB_LINEUP**, e **TB_TOP** somente quando o usuário interagisse os códigos de notificação com um controle deslizante usando o teclado. O **TB_THUMBPOSITION** e **TB_THUMBTRACK** mensagens de notificação são enviadas somente quando o usuário estiver usando o mouse. O **TB_ENDTRACK**, **TB_PAGEDOWN**, e **TB_PAGEUP** códigos de notificação são enviados em ambos os casos.  
  
 A tabela a seguir lista as mensagens de notificação do controle deslizante e os eventos (códigos de tecla virtuais ou eventos de mouse) que fazem as envio de notificações. (Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser.)  
  
|Mensagem de notificação|Evento que causa a notificação seja enviada|  
|--------------------------|-------------------------------------------|  
|**TB_BOTTOM**|**VK_END**|  
|**TB_ENDTRACK**|`WM_KEYUP` (o usuário lançado uma chave que é enviado um código de tecla virtual relevante)|  
|**TB_LINEDOWN**|**VK_RIGHT** ou **VK_DOWN**|  
|**TB_LINEUP**|**VK_LEFT** ou **VK_UP**|  
|**TB_PAGEDOWN**|**VK_NEXT** (o usuário clicou o canal abaixo ou à direita do controle deslizante)|  
|**TB_PAGEUP**|**VK_PRIOR** (o usuário clicou o canal acima ou à esquerda do controle deslizante)|  
|**TB_THUMBPOSITION**|`WM_LBUTTONUP` a seguir um **TB_THUMBTRACK** mensagem de notificação|  
|**TB_THUMBTRACK**|Movimentação do controle deslizante (o usuário arrastado o controle deslizante)|  
|**TB_TOP**|**VK_HOME**|  
  
## <a name="see-also"></a>Consulte também  
 [Usando CSliderCtrl](../mfc/using-csliderctrl.md)   
 [Controles](../mfc/controls-mfc.md)

