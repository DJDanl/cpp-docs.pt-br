---
title: Usando botões suspensos em um controle de barra de ferramentas
ms.date: 11/04/2016
f1_keywords:
- TBN_DROPDOWN
- TBSTYLE_EX_DRAWDDARROWS
helpviewer_keywords:
- CToolBarCtrl class [MFC], drop-down buttons
- toolbars [MFC], drop-down buttons
- drop-down buttons in toolbars
- TBSTYLE_EX_DRAWDDARROWS
- TBN_DROPDOWN notification [MFC]
ms.assetid: b859f758-d2f6-40d9-9c26-0ff61993b9b2
ms.openlocfilehash: fe314e0fdff70979dfc858bb89578170f9a9ee02
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50453490"
---
# <a name="using-drop-down-buttons-in-a-toolbar-control"></a>Usando botões suspensos em um controle de barra de ferramentas

Além dos botões de push padrão, uma barra de ferramentas também pode ter botões suspensos. Normalmente, um botão suspenso é indicado pela presença de uma seta anexada para baixo.

> [!NOTE]
>  A seta anexada para baixo será exibida apenas se o estilo estendido de TBSTYLE_EX_DRAWDDARROWS tiver sido definido.

Quando o usuário clica nessa seta (ou no próprio botão, se nenhuma seta estiver presente), uma mensagem de notificação TBN_DROPDOWN é enviada para o pai do controle de barra de ferramentas. Você pode manipular essa notificação e exibir um menu pop-up. semelhante ao comportamento do Internet Explorer.

O procedimento a seguir ilustra como implementar um botão de barra de ferramentas da lista suspensa com um menu pop-up:

### <a name="to-implement-a-drop-down-button"></a>Para implementar um botão suspenso

1. Uma vez seu `CToolBarCtrl` objeto tiver sido criado, defina o estilo TBSTYLE_EX_DRAWDDARROWS, usando o seguinte código:

   [!code-cpp[NVC_MFCControlLadenDialog#36](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_1.cpp)]

1. Definir o estilo TBSTYLE_DROPDOWN para qualquer novo ([InsertButton](../mfc/reference/ctoolbarctrl-class.md#insertbutton) ou [AddButtons](../mfc/reference/ctoolbarctrl-class.md#addbuttons)) ou existentes ([SetButtonInfo](../mfc/reference/ctoolbarctrl-class.md#setbuttoninfo)) botões que serão botões suspensos. O exemplo a seguir demonstra a modificação de um botão existente em um `CToolBarCtrl` objeto:

   [!code-cpp[NVC_MFCControlLadenDialog#37](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_2.cpp)]

1. Adicione um manipulador TBN_DROPDOWN a classe pai do objeto da barra de ferramentas.

   [!code-cpp[NVC_MFCControlLadenDialog#38](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_3.cpp)]

1. No manipulador de novo, exiba o menu pop-up apropriado. O código a seguir demonstra um método:

   [!code-cpp[NVC_MFCControlLadenDialog#39](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_4.cpp)]

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

