---
title: "Barras da caixa de di&#225;logo | Microsoft Docs"
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
  - "Classe CDialogBar, barras da caixa de diálogo"
  - "barras de controle, barras da caixa de diálogo"
  - "barras da caixa de diálogo"
  - "barras da caixa de diálogo, sobre barras de caixas de diálogo"
  - "MFC, barras de controle"
ms.assetid: 485c8055-6bb0-4051-8417-dd2971499321
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Barras da caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma barra da caixa de diálogo é uma barra de ferramentas, um tipo de [barra de controle](../Topic/Control%20Bars.md) que pode conter qualquer tipo do controle.  Porque tem características de uma caixa de diálogo modeless, um objeto de [CDialogBar](../mfc/reference/cdialogbar-class.md) fornece uma barra de ferramentas mais avançada.  
  
 Há vários principais diferenças entre uma barra de ferramentas e um objeto de `CDialogBar` .  Um objeto de `CDialogBar` for criado de um recurso de diálogo\- modelo, que você pode criar com o publicador da caixa de diálogo do Visual C\+\+ e que pode conter qualquer tipo de controle do windows.  O usuário pode alternar de controle ao controle.  Além de especificar um estilo de alinhamento para alinhar a barra da caixa de diálogo com qualquer parte da janela pai do quadro ou até mesmo para deixá\-la no lugar se o pai é redimensionado.  A seguinte figura mostra uma barra da caixa de diálogo com uma variedade de controles.  
  
 ![Barra da caixa de diálogo de VC](../mfc/media/vc378t1.png "vc378T1")  
Uma barra a caixa de diálogo  
  
 Em outros aspectos, trabalhar com um objeto de `CDialogBar` é como trabalhar com uma caixa de diálogo modeless.  Use o editor da caixa de diálogo para criar o recurso da caixa de diálogo.  
  
 Uma das virtudes de barras da caixa de diálogo é que eles podem incluir controles diferentes dos botões.  
  
 Quando é normal derivar o seu própria caixa de diálogo classificação de `CDialog`, você normalmente não deriva sua própria classe para uma barra da caixa de diálogo.  As barras da caixa de diálogo são extensões para uma janela principal e todas as mensagens de notificação controle\- de diálogo\- barra, como **BN\_CLICKED** ou **EN\_CHANGE**, serão enviadas ao pai da barra da caixa de diálogo, a janela principal.  
  
## Consulte também  
 [Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)   
 [Amostra](../top/visual-cpp-samples.md)