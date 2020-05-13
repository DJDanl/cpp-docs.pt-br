---
title: Usando dicas de ferramenta em um objeto CStatusBarCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- tool tips [MFC], using in status bars
- status bars [MFC], tool tips
- CStatusBarCtrl class [MFC], tool tips
ms.assetid: a77597a7-43ef-4b8f-87bc-a8ea1dc63dc3
ms.openlocfilehash: 29d326c708743424686d616bbaf172ccd72481ce
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374703"
---
# <a name="using-tooltips-in-a-cstatusbarctrl-object"></a>Usando dicas de ferramenta em um objeto CStatusBarCtrl

Para habilitar dicas de ferramentas para `CStatusBarCtrl` um controle da barra de status, crie o objeto com o estilo SBT_TOOLTIPS.

> [!NOTE]
> Se você estiver `CStatusBar` usando um objeto para `CStatusBar::CreateEx` implementar sua barra de status, use a função. Ele permite especificar estilos adicionais para o objeto incorporado. `CStatusBarCtrl`

Depois `CStatusBarCtrl` de criado o objeto com sucesso, use [CStatusBarCtrl::SetTipText](../mfc/reference/cstatusbarctrl-class.md#settiptext) e [CStatusBarCtrl::GetTipText](../mfc/reference/cstatusbarctrl-class.md#gettiptext) para definir e recuperar o texto da ponta para um painel específico.

Uma vez definida a ponta da ferramenta, ela é exibida somente se a peça tiver um ícone e nenhum texto, ou se todo o texto não puder ser exibido dentro da peça. As dicas da ferramenta não são suportadas no modo simples.

## <a name="see-also"></a>Confira também

[Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
