---
title: Trabalhando com o controle da barra de ferramentas
ms.date: 11/04/2016
helpviewer_keywords:
- GetToolBarCtrl method [MFC]
- toolbars [MFC], accessing common control
- CToolBarCtrl class [MFC], accessing toolbar
- toolbar controls [MFC], accessing
ms.assetid: b19409d5-3831-42c7-80ae-195c49dc9085
ms.openlocfilehash: 371f1944fae655556bbc9f89d7ffcce7cc326e5e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365242"
---
# <a name="working-with-the-toolbar-control"></a>Trabalhando com o controle da barra de ferramentas

Este artigo explica como você pode acessar o objeto [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) subjacente a uma [Barra de Ferramentas](../mfc/reference/ctoolbar-class.md) para maior controle sobre suas barras de ferramentas. Este é um tópico avançado.

## <a name="procedures"></a>Procedimentos

#### <a name="to-access-the-toolbar-common-control-underlying-your-ctoolbar-object"></a>Para acessar o controle comum da barra de ferramentas subjacente ao objeto CToolBar

1. Chamada [CToolBar::GetToolBarCtrl](../mfc/reference/ctoolbar-class.md#gettoolbarctrl).

`GetToolBarCtrl`retorna uma referência a um objeto [CToolBarCtrl.](../mfc/reference/ctoolbarctrl-class.md) Você pode usar a referência para chamar funções de membro da classe de controle da barra de ferramentas.

> [!CAUTION]
> Ao `CToolBarCtrl` **ligar, obter** funções é seguro, tenha cuidado se você chamar as funções **definir.** Este é um tópico avançado. Normalmente você não deve precisar acessar o controle da barra de ferramentas subjacente.

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Controles (controles comuns do Windows)](../mfc/controls-mfc.md)

- [Fundamentos da barra de ferramentas](../mfc/toolbar-fundamentals.md)

- [Barras de ferramentas flutuantes e de acoplamento](../mfc/docking-and-floating-toolbars.md)

- [Redimensionamento dinâmico da barra de ferramentas](../mfc/docking-and-floating-toolbars.md)

- [Dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md)

- [Atualizações da barra de status flyby](../mfc/toolbar-tool-tips.md)

- [Notificações de ponta de ferramenta de manuseio](../mfc/handling-tool-tip-notifications.md)

- As classes [CToolBarCtrl](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)

- [Manipulação de notificações de personalização](../mfc/handling-customization-notifications.md)

- [Barras de ferramentas múltiplas](../mfc/toolbar-fundamentals.md)

- [Usando suas barras de ferramentas antigas](../mfc/using-your-old-toolbars.md)

- [Barras de controle](../mfc/control-bars.md)

Para obter informações gerais sobre o uso de controles comuns do Windows, consulte [Controles comuns](/windows/win32/Controls/common-controls-intro).

## <a name="see-also"></a>Confira também

[Implementação da barra de ferramentas MFC](../mfc/mfc-toolbar-implementation.md)
