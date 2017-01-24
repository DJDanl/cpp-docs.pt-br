---
title: "Usando bot&#245;es suspensos em um controle de barra de ferramentas | Microsoft Docs"
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
  - "TBN_DROPDOWN"
  - "TBSTYLE_EX_DRAWDDARROWS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CToolBarCtrl, botões suspensos"
  - "botões suspensos em barras de ferramentas"
  - "TBN_DROPDOWN (notificação)"
  - "TBSTYLE_EX_DRAWDDARROWS"
  - "barras de ferramentas [C++], botões suspensos"
ms.assetid: b859f758-d2f6-40d9-9c26-0ff61993b9b2
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando bot&#245;es suspensos em um controle de barra de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Além dos botões de ação padrão, uma barra de ferramentas também pode ter os botões suspensos.  Um botão suspenso geralmente é indicado pela presença de uma seta para baixo anexado.  
  
> [!NOTE]
>  A seta para baixo anexado será exibida somente se o estilo `TBSTYLE_EX_DRAWDDARROWS` estendido foi definido.  
  
 Quando o usuário clicar nessa seta \(ou o botão próprio, se nenhuma seta estiver presente\), uma notificação de `TBN_DROPDOWN` é enviada ao pai do controle da barra de ferramentas.  Você pode controlar essa notificação e exibir um menu suspenso; semelhante ao comportamento do Internet Explorer.  
  
 O procedimento a seguir explica como implementar um botão da barra de ferramentas lista suspensa com um menu pop\-up:  
  
### Para implementar um botão suspenso  
  
1.  Uma vez que seu objeto de `CToolBarCtrl` foi criado, defina o estilo de `TBSTYLE_EX_DRAWDDARROWS` , usando o seguinte código:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#36](../mfc/codesnippet/CPP/using-drop-down-buttons-in-a-toolbar-control_1.cpp)]  
  
2.  Definir o estilo de `TBSTYLE_DROPDOWN` para todos os novos[InsertButton](../Topic/CToolBarCtrl::InsertButton.md) \(ou [AddButtons](../Topic/CToolBarCtrl::AddButtons.md)\) ou existentes \(botões de[SetButtonInfo](../Topic/CToolBarCtrl::SetButtonInfo.md)\) que sejam botões suspensos.  O exemplo a seguir demonstra a alteração de um botão existente em um objeto de `CToolBarCtrl` :  
  
     [!code-cpp[NVC_MFCControlLadenDialog#37](../mfc/codesnippet/CPP/using-drop-down-buttons-in-a-toolbar-control_2.cpp)]  
  
3.  Adicionar um manipulador de `TBN_DROPDOWN` a classe pai do objeto da barra de ferramentas.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#38](../mfc/codesnippet/CPP/using-drop-down-buttons-in-a-toolbar-control_3.cpp)]  
  
4.  No novo manipulador, exibir o menu pop\-up apropriado.  O código a seguir demonstra um método:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#39](../mfc/codesnippet/CPP/using-drop-down-buttons-in-a-toolbar-control_4.cpp)]  
  
## Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)