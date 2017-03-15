---
title: "Usando CSliderCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CSliderCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CSliderCtrl, usando"
  - "controles deslizantes, usando"
ms.assetid: 242c7bcd-126e-4b9b-8f76-8082ad06fe73
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando CSliderCtrl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de [CSliderCtrl](../mfc/reference/csliderctrl-class.md) representa um controle deslizante, que também é chamado um trackbar.  Um “controle deslizante” é uma janela que contenha um controle deslizante e as marcas de escala opcionais.  Quando o usuário mover o controle deslizante, usando o mouse ou as teclas de direção, o controle deslizante envia notificações para indicar a alteração.  
  
 Os controles deslizantes são úteis quando desejar que o usuário para selecionar um valor discreto ou um conjunto de valores sucessivos em um intervalo.  Por exemplo, você pode usar um controle deslizante para permitir que o usuário defina a taxa de reprodução do teclado mover o controle deslizante para uma determinada marca de escala.  
  
 O controle deslizante em um controle deslizante passa em incrementos que você especifica quando forem criados.  Por exemplo, se você especificar que o controle deslizante deve ter um intervalo de cinco, o controle deslizante só pode ocupar seis posições: uma posição no lado esquerdo do controle deslizante e uma posição para cada incremento no intervalo.  Normalmente, cada uma dessas posições é identificada por uma marca de escala.  
  
## Que você deseja saber mais?  
  
-   [Usando controles deslizantes](../Topic/Using%20Slider%20Controls.md)  
  
-   [Estilos de controle deslizante](../Topic/Slider%20Control%20Styles.md)  
  
-   [Funções de membro do controle deslizante](../mfc/slider-control-member-functions.md)  
  
-   [Notificações de controle deslizante](../mfc/slider-notification-messages.md)  
  
## Consulte também  
 [Controles](../mfc/controls-mfc.md)