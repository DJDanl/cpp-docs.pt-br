---
title: "Configura&#231;&#245;es do CStatusBarCtrl | Microsoft Docs"
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
  - "CStatusBarCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CStatusBarCtrl, configurações"
  - "controles da barra de status, configurações"
ms.assetid: adeba0c3-17f3-435c-b140-a57845e9ce49
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Configura&#231;&#245;es do CStatusBarCtrl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A posição padrão de uma janela de status de [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md) é o longo da parte inferior da janela pai, mas você pode especificar o estilo de `CCS_TOP` para solicitar aparecerão na parte superior da área da janela pai do cliente.  
  
 Você pode especificar o estilo de **SBARS\_SIZEGRIP** para incluir um aperto de dimensionamento na extremidade direita da janela de status de `CStatusBarCtrl` .  Um aperto de dimensionamento é semelhante a uma borda de dimensionamento; é uma área retangular que o usuário possa clicar e arrastar para redimensionar a janela pai.  
  
> [!NOTE]
>  Se você combinar `CCS_TOP` e os estilos de **SBARS\_SIZEGRIP** , o aperto resultante de dimensionamento não funciona mesmo que o sistema desenhe o na janela de status.  
  
 O procedimento da janela para a janela de status define automaticamente o tamanho e posição inicial da janela de controle.  A largura é igual a da área da janela pai do cliente.  A altura é baseada em métricas de fonte que está selecionada atualmente no contexto do dispositivo da janela de status e a largura das bordas da janela.  
  
 O procedimento de janela automaticamente ajusta o tamanho da janela de status sempre que recebe uma mensagem de `WM_SIZE` .  Normalmente, quando o tamanho da janela pai for alterado, o pai envia uma mensagem de `WM_SIZE` à janela de status.  
  
 Você pode definir a altura mínima da área de desenho de uma janela de status chamando [SetMinHeight](../Topic/CStatusBarCtrl::SetMinHeight.md), especificando a altura mínima em pixels.  A área de desenho não inclui as bordas da janela.  
  
 Você recupera as larguras das bordas de uma janela de status chamando [GetBorders](../Topic/CStatusBarCtrl::GetBorders.md).  Essa função de membro inclui o ponteiro para uma matriz de três elemento que recebe a largura da borda horizontal, vertical da borda, e da borda entre os retângulos.  
  
## Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)