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
ms.openlocfilehash: 0bc4df4c07ec4b8bc5b488925cbb140609302186
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365061"
---
# <a name="using-drop-down-buttons-in-a-toolbar-control"></a>Usando botões suspensos em um controle de barra de ferramentas

Além dos botões padrão, uma barra de ferramentas também pode ter botões para baixo. Um botão suspenso é geralmente indicado pela presença de uma seta fixa para baixo.

> [!NOTE]
> A seta fixa para baixo só aparecerá se o estilo TBSTYLE_EX_DRAWDDARROWS estendido tiver sido definido.

Quando o usuário clica nesta seta (ou no próprio botão, se nenhuma seta estiver presente), uma mensagem de notificação TBN_DROPDOWN é enviada ao pai do controle da barra de ferramentas. Em seguida, você pode lidar com esta notificação e exibir um menu pop-up; semelhante ao comportamento do Internet Explorer.

O procedimento a seguir ilustra como implementar um botão de barra de ferramentas suspenso com um menu pop-up:

### <a name="to-implement-a-drop-down-button"></a>Para implementar um botão de baixa

1. Uma `CToolBarCtrl` vez que seu objeto tenha sido criado, defina o estilo TBSTYLE_EX_DRAWDDARROWS, usando o seguinte código:

   [!code-cpp[NVC_MFCControlLadenDialog#36](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_1.cpp)]

1. Defina o estilo TBSTYLE_DROPDOWN para quaisquer botões novos[(InsertButton](../mfc/reference/ctoolbarctrl-class.md#insertbutton) ou [AddButtons)](../mfc/reference/ctoolbarctrl-class.md#addbuttons)ou existentes[(SetButtonInfo)](../mfc/reference/ctoolbarctrl-class.md#setbuttoninfo)que serão botões de baixa. O exemplo a seguir demonstra a `CToolBarCtrl` modificação de um botão existente em um objeto:

   [!code-cpp[NVC_MFCControlLadenDialog#37](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_2.cpp)]

1. Adicione um manipulador de TBN_DROPDOWN à classe pai do objeto da barra de ferramentas.

   [!code-cpp[NVC_MFCControlLadenDialog#38](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_3.cpp)]

1. No novo manipulador, exiba o menu pop-up apropriado. O código a seguir demonstra um método:

   [!code-cpp[NVC_MFCControlLadenDialog#39](../mfc/codesnippet/cpp/using-drop-down-buttons-in-a-toolbar-control_4.cpp)]

## <a name="see-also"></a>Confira também

[Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
