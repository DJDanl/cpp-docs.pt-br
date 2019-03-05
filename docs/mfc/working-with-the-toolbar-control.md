---
title: Trabalhando com o controle da barra de ferramentas
ms.date: 11/04/2016
helpviewer_keywords:
- GetToolBarCtrl method [MFC]
- toolbars [MFC], accessing common control
- CToolBarCtrl class [MFC], accessing toolbar
- toolbar controls [MFC], accessing
ms.assetid: b19409d5-3831-42c7-80ae-195c49dc9085
ms.openlocfilehash: 88c00bf60f2ce1fccecd757d13b2f814e3a18be4
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57260498"
---
# <a name="working-with-the-toolbar-control"></a>Trabalhando com o controle da barra de ferramentas

Este artigo explica como você pode acessar o [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) objeto subjacentes uma [CToolBar](../mfc/reference/ctoolbar-class.md) para maior controle sobre suas barras de ferramentas. Este é um tópico avançado.

## <a name="procedures"></a>Procedimentos

#### <a name="to-access-the-toolbar-common-control-underlying-your-ctoolbar-object"></a>Para acessar o controle de barra de ferramentas comum subjacente de seu objeto CToolBar

1. Chame [CToolBar::GetToolBarCtrl](../mfc/reference/ctoolbar-class.md#gettoolbarctrl).

`GetToolBarCtrl` Retorna uma referência a um [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) objeto. Você pode usar a referência para chamar funções de membro de classe de controle de barra de ferramentas.

> [!CAUTION]
>  Ao chamar `CToolBarCtrl` **Obtenha** funções é seguro, tenha cuidado se você chamar o **definir** funções. Este é um tópico avançado. Normalmente não é necessário acessar o controle de barra de ferramentas subjacente.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Controles (controles comuns do Windows)](../mfc/controls-mfc.md)

- [Conceitos básicos da barra de ferramentas](../mfc/toolbar-fundamentals.md)

- [Encaixando e flutuando barras de ferramentas](../mfc/docking-and-floating-toolbars.md)

- [Redimensionar dinamicamente a barra de ferramentas](../mfc/docking-and-floating-toolbars.md)

- [Dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md)

- [Atualizações da barra de status flyby](../mfc/toolbar-tool-tips.md)

- [Manipulando notificações da dica de ferramenta](../mfc/handling-tool-tip-notifications.md)

- O [CToolBar](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) classes

- [Manipulando notificações de personalização](../mfc/handling-customization-notifications.md)

- [Várias barras de ferramentas](../mfc/toolbar-fundamentals.md)

- [Usando as barras](../mfc/using-your-old-toolbars.md)

- [Barras de controle](../mfc/control-bars.md)

Para obter informações gerais sobre o uso de controles comuns do Windows, consulte [controles comuns](/windows/desktop/Controls/common-controls-intro).

## <a name="see-also"></a>Consulte também

[Implementação da barra de ferramentas do MFC](../mfc/mfc-toolbar-implementation.md)
