---
title: "Usando uma caixa de di&#225;logo com um controle rebar | Microsoft Docs"
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
  - "WM_EX_TRANSPARENT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "barras da caixa de diálogo, usando com bandas rebar"
  - "controles rebar, barras da caixa de diálogo"
  - "Estilo WS_EX_TRANSPARENT"
ms.assetid: e528cea0-6b81-4bdf-9643-7c03b6176590
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando uma caixa de di&#225;logo com um controle rebar
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Conforme mencionado em [Controles e faixas de Rebar](../mfc/rebar-controls-and-bands.md), cada linha distribuída pode conter apenas uma janela filho \(ou controle\).  Ela pode ser uma restrição se você quer ter mais de uma janela filho pela faixa.  Uma solução alternativa conveniente é criar um recurso da barra da caixa de diálogo com vários controles e adicione uma faixa de rebar \(que contém a barra da caixa de diálogo\) ao controle de rebar.  
  
 Normalmente, se você quisesse a faixa da barra da caixa de diálogo para exibir transparente, você definirá o estilo **WS\_EX\_TRANSPARENT** estendida do objeto da barra da caixa de diálogo.  No entanto, como **WS\_EX\_TRANSPARENT** tem alguns problemas com corretamente pintura do plano de fundo de uma barra na caixa de diálogo, você precisará fazer o trabalho em vez de adicional para obter o efeito desejado.  
  
 O procedimento a seguir detalha as etapas necessárias para obter a transparência sem usar o estilo **WS\_EX\_TRANSPARENT** estendido.  
  
### Para implementar uma barra transparente da caixa de diálogo em um rebar una  
  
1.  Usando [Caixa de diálogo adicionar classe](../mfc/reference/adding-an-mfc-class.md), adicione uma nova classe \(por exemplo, `CMyDlgBar`\) que implementa seu objeto da barra da caixa de diálogo.  
  
2.  Adicionar um manipulador para a mensagem de `WM_ERASEBKGND` .  
  
3.  No novo manipulador, modifique o código existente para corresponder ao seguinte exemplo:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#29](../mfc/codesnippet/CPP/using-a-dialog-bar-with-a-rebar-control_1.cpp)]  
  
4.  Adicionar um manipulador para a mensagem de `WM_MOVE` .  
  
5.  No novo manipulador, modifique o código existente para corresponder ao seguinte exemplo:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#30](../mfc/codesnippet/CPP/using-a-dialog-bar-with-a-rebar-control_2.cpp)]  
  
 Os novos manipuladores simulam a transparência da barra da caixa de diálogo para encaminhar a mensagem de `WM_ERASEBKGND` para a janela pai e forçar repintar cada vez que o objeto da barra da caixa de diálogo é movido.  
  
## Consulte também  
 [Usando CReBarCtrl](../Topic/Using%20CReBarCtrl.md)   
 [Controles](../mfc/controls-mfc.md)