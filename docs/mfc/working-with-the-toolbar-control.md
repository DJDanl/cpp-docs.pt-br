---
title: Trabalhando com o controle da barra de ferramentas
ms.date: 11/04/2016
helpviewer_keywords:
- GetToolBarCtrl method [MFC]
- toolbars [MFC], accessing common control
- CToolBarCtrl class [MFC], accessing toolbar
- toolbar controls [MFC], accessing
ms.assetid: b19409d5-3831-42c7-80ae-195c49dc9085
ms.openlocfilehash: 60cc527493e2a68751c201b998ab171c564d6c1f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69510583"
---
# <a name="working-with-the-toolbar-control"></a>Trabalhando com o controle da barra de ferramentas

Este artigo explica como você pode acessar o objeto [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) subjacente a um [CToolBar](../mfc/reference/ctoolbar-class.md) para obter maior controle sobre suas barras de ferramentas. Este é um tópico avançado.

## <a name="procedures"></a>Procedimentos

#### <a name="to-access-the-toolbar-common-control-underlying-your-ctoolbar-object"></a>Para acessar a barra de ferramentas controle comum subjacente ao objeto CToolBar

1. Chame [CToolBar:: GetToolBarCtrl](../mfc/reference/ctoolbar-class.md#gettoolbarctrl).

`GetToolBarCtrl`Retorna uma referência a um objeto [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) . Você pode usar a referência para chamar funções de membro da classe de controle ToolBar.

> [!CAUTION]
>  Ao chamar `CToolBarCtrl` **Get** Functions é seguro, tome cuidado se você chamar as funções **set** . Este é um tópico avançado. Normalmente, você não precisará acessar o controle da barra de ferramentas subjacente.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Controles (controles comuns do Windows)](../mfc/controls-mfc.md)

- [Conceitos básicos da barra de ferramentas](../mfc/toolbar-fundamentals.md)

- [Barras de ferramentas flutuantes e de encaixe](../mfc/docking-and-floating-toolbars.md)

- [Redimensionamento dinâmico da barra de ferramentas](../mfc/docking-and-floating-toolbars.md)

- [Dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md)

- [Atualizações da barra de status do flyby](../mfc/toolbar-tool-tips.md)

- [Manipulando notificações de dica de ferramenta](../mfc/handling-tool-tip-notifications.md)

- As classes [CToolBar](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)

- [Lidando com notificações de personalização](../mfc/handling-customization-notifications.md)

- [Várias barras de ferramentas](../mfc/toolbar-fundamentals.md)

- [Usando suas barras de ferramentas antigas](../mfc/using-your-old-toolbars.md)

- [Barras de controle](../mfc/control-bars.md)

Para obter informações gerais sobre como usar os controles comuns do Windows, consulte [controles comuns](/windows/win32/Controls/common-controls-intro).

## <a name="see-also"></a>Consulte também

[Implementação da barra de ferramentas do MFC](../mfc/mfc-toolbar-implementation.md)
