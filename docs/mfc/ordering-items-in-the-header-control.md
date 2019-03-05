---
title: Ordenando itens no controle de cabeçalho
ms.date: 11/04/2016
f1_keywords:
- DS_DRAGDROP
helpviewer_keywords:
- sequence [MFC]
- sequence [MFC], header control items
- OrderToIndex method [MFC]
- DS_DRAGDROP notification [MFC]
- GetOrderArray method [MFC]
- SetOrderArray method [MFC]
- header controls [MFC], ordering items
ms.assetid: 5aaef872-75b5-49c5-8fed-6f9a81fca812
ms.openlocfilehash: bae351d921c25993d6b7029f9052e1938179673b
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57282010"
---
# <a name="ordering-items-in-the-header-control"></a>Ordenando itens no controle de cabeçalho

Depois que você tiver [adicionou itens para um controle de cabeçalho](../mfc/adding-items-to-the-header-control.md), você pode manipular ou obter informações sobre seus pedidos com as seguintes funções:

- [CHeaderCtrl::GetOrderArray](../mfc/reference/cheaderctrl-class.md#getorderarray) e [CHeaderCtrl::SetOrderArray](../mfc/reference/cheaderctrl-class.md#setorderarray)

   Recupera e define a ordem da esquerda para a direita dos itens de cabeçalho.

- [CHeaderCtrl::OrderToIndex](../mfc/reference/cheaderctrl-class.md#ordertoindex).

   Recupera o valor de índice para um item de cabeçalho específico.

Além das funções de membro anterior, o estilo HDS_DRAGDROP permite ao usuário arrastar e soltar itens de cabeçalho dentro do controle de cabeçalho. Para obter mais informações, consulte [fornecendo suporte de arrastar e soltar para itens de cabeçalho](../mfc/providing-drag-and-drop-support-for-header-items.md).

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)
