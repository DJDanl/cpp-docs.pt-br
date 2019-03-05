---
title: Seleção do item de controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- tree controls [MFC], item selection
- controls [MFC], selecting items in
- CTreeCtrl class [MFC], item selection
- item selection in tree controls
ms.assetid: 7bcb3b16-b9c8-4c06-9350-7bc3c1c5009b
ms.openlocfilehash: a88a2c8ea5b935bbcb1f40b705337ff676d8b8a5
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57264112"
---
# <a name="tree-control-item-selection"></a>Seleção do item de controle de árvore

Quando a seleção é alterada de um item para outro, um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) envia [TVN_SELCHANGING](/windows/desktop/Controls/tvn-selchanging) e [TVN_SELCHANGED](/windows/desktop/Controls/tvn-selchanged) mensagens de notificação. Ambas as notificações incluem um valor que especifica se a alteração é o resultado de um clique do mouse ou um pressionamento de tecla. As notificações também incluem informações sobre o item que está ganhando a seleção e o item que está perdendo a seleção. Você pode usar essas informações para definir atributos de itens que dependem do estado de seleção do item. Retornando **verdadeira** em resposta à `TVN_SELCHANGING` impede que a seleção mudando; retornando **FALSE** permite que a alteração.

Um aplicativo pode alterar a seleção chamando o [SelectItem](../mfc/reference/ctreectrl-class.md#selectitem) função de membro.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
