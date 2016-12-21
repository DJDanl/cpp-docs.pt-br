---
title: "Mensagens de notifica&#231;&#227;o do controle deslizante | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CSliderCtrl, notificações"
  - "mensagens,  (notificação)"
  - "notificações, CSliderCtrl"
  - "controles deslizantes, mensagens de notificação"
ms.assetid: b9121104-3889-4a10-92bf-f3723f1af9d0
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mensagens de notifica&#231;&#227;o do controle deslizante
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um controle deslizante notifica a janela pai de ações do usuário emissor `WM_HSCROLL` ou mensagens pai de `WM_VSCROLL` , dependendo da orientação de controle deslizante.  Para tratar essas mensagens, adicionar manipuladores para as mensagens de `WM_HSCROLL` e de `WM_VSCROLL` para a janela pai.  As funções de membro de [OnHScroll](../Topic/CWnd::OnHScroll.md) e de [OnVScroll](../Topic/CWnd::OnVScroll.md) serão transmitidas um código de notificação, a posição do controle deslizante, e um ponteiro para o objeto de [CSliderCtrl](../mfc/reference/csliderctrl-class.md) .  Observe que o ponteiro é do tipo **CScrollBar \*** mesmo que aponta para `CSliderCtrl` um objeto.  Você pode precisar typecast esse ponteiro se você precisa manipular o controle deslizante.  
  
 Em vez de usar os códigos de notificação da barra de rolagem, os controles deslizantes enviam um conjunto diferente de códigos de notificação.  Um controle deslizante envia **TB\_BOTTOM**, **TB\_LINEDOWN**, **TB\_LINEUP**, e a notificação de **TB\_TOP** codifica apenas quando o usuário interage com um controle deslizante usando o teclado.  As notificações de **TB\_THUMBPOSITION** e de **TB\_THUMBTRACK** são enviadas somente quando o usuário estiver usando o mouse.  Os códigos de notificação de **TB\_ENDTRACK**, de **TB\_PAGEDOWN**, e de **TB\_PAGEUP** são enviados em ambos os casos.  
  
 A tabela a seguir lista as notificações de controle deslizante e eventos \(códigos chaves ou eventos virtuais do mouse\) que faz com que as notificações ser enviado. \(Para obter uma lista de códigos chaves virtuais, consulte Winuser.h.\)  
  
|Notificação|Evento fazendo com que a notificação a ser enviada|  
|-----------------|--------------------------------------------------------|  
|**TB\_BOTTOM**|**VK\_END**|  
|**TB\_ENDTRACK**|`WM_KEYUP` \(o usuário lançou uma chave que envie um código chave relevante virtual\)|  
|**TB\_LINEDOWN**|**VK\_RIGHT** ou **VK\_DOWN**|  
|**TB\_LINEUP**|**VK\_LEFT** ou **VK\_UP**|  
|**TB\_PAGEDOWN**|**VK\_NEXT** \(o usuário clicou o canal em ou à direita do controle deslizante\)|  
|**TB\_PAGEUP**|**VK\_PRIOR** \(o usuário clicou o canal acima ou à esquerda do controle deslizante\)|  
|**TB\_THUMBPOSITION**|`WM_LBUTTONUP` depois de uma notificação de **TB\_THUMBTRACK**|  
|**TB\_THUMBTRACK**|Mover o controle deslizante \(o usuário arrastou o controle deslizante\)|  
|**TB\_TOP**|**VK\_HOME**|  
  
## Consulte também  
 [Usando CSliderCtrl](../mfc/using-csliderctrl.md)   
 [Controles](../mfc/controls-mfc.md)