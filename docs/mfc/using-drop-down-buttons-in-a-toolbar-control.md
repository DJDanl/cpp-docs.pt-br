---
title: Usando botões suspensos em um controle de barra de ferramentas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- TBN_DROPDOWN
- TBSTYLE_EX_DRAWDDARROWS
dev_langs:
- C++
helpviewer_keywords:
- CToolBarCtrl class [MFC], drop-down buttons
- toolbars [MFC], drop-down buttons
- drop-down buttons in toolbars
- TBSTYLE_EX_DRAWDDARROWS
- TBN_DROPDOWN notification [MFC]
ms.assetid: b859f758-d2f6-40d9-9c26-0ff61993b9b2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1e76db0bacd7984c97fd8e2696b3543f6e9bf66b
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36953233"
---
# <a name="using-drop-down-buttons-in-a-toolbar-control"></a>Usando botões suspensos em um controle de barra de ferramentas
Além dos botões de ação padrão, uma barra de ferramentas também pode ter botões suspensos. Normalmente, um botão suspenso é indicado pela presença de uma seta anexada para baixo.  
  
> [!NOTE]
>  Seta anexada para baixo será exibida apenas se o TBSTYLE_EX_DRAWDDARROWS estilo estendido foi definido.  
  
 Quando o usuário clica na seta (ou no botão em si, se não houver nenhuma seta), uma mensagem de notificação TBN_DROPDOWN é enviada para o pai do controle da barra de ferramentas. Você pode tratar essa notificação e exibir um menu pop-up. semelhante ao comportamento do Internet Explorer.  
  
 O procedimento a seguir ilustra como implementar um botão de barra de ferramentas de lista suspensa com um menu pop-up:  
  
### <a name="to-implement-a-drop-down-button"></a>Para implementar um botão suspenso  
  
1.  Uma vez o `CToolBarCtrl` objeto foi criado, defina o estilo TBSTYLE_EX_DRAWDDARROWS, usando o seguinte código:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#36](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_1.cpp)]  
  
2.  Definir o estilo TBSTYLE_DROPDOWN para qualquer novo ([InsertButton](../mfc/reference/ctoolbarctrl-class.md#insertbutton) ou [AddButtons](../mfc/reference/ctoolbarctrl-class.md#addbuttons)) ou existentes ([SetButtonInfo](../mfc/reference/ctoolbarctrl-class.md#setbuttoninfo)) botões que serão botões suspensos. O exemplo a seguir demonstra a modificação de um botão existente em um `CToolBarCtrl` objeto:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#37](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_2.cpp)]  
  
3.  Adicione um manipulador TBN_DROPDOWN para a classe pai do objeto da barra de ferramentas.  
  
     [!code-cpp[NVC_MFCControlLadenDialog#38](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_3.cpp)]  
  
4.  No manipulador de novo, exiba o menu pop-up apropriado. O código a seguir demonstra um método:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#39](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

