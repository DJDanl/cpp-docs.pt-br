---
title: Seleção do item de controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- tree controls [MFC], item selection
- controls [MFC], selecting items in
- CTreeCtrl class [MFC], item selection
- item selection in tree controls
ms.assetid: 7bcb3b16-b9c8-4c06-9350-7bc3c1c5009b
ms.openlocfilehash: 07c7b673e0f9029f8ece928b0ab17760b3863cc7
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513343"
---
# <a name="tree-control-item-selection"></a>Seleção do item de controle de árvore

Quando a seleção é alterada de um item para outro, um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) envia mensagens de notificação [TVN_SELCHANGING](/windows/win32/Controls/tvn-selchanging) e [TVN_SELCHANGED](/windows/win32/Controls/tvn-selchanged) . Ambas as notificações incluem um valor que especifica se a alteração é o resultado de um clique do mouse ou de um pressionamento de tecla. As notificações também incluem informações sobre o item que está recebendo a seleção e o item que está perdendo a seleção. Você pode usar essas informações para definir atributos de item que dependem do estado de seleção do item. Retornar **true** em resposta para `TVN_SELCHANGING` impedir que a seleção seja alterada; retornar **false** permite a alteração.

Um aplicativo pode alterar a seleção chamando a função de membro [SelectItem](../mfc/reference/ctreectrl-class.md#selectitem) .

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
