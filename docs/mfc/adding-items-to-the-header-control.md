---
title: Adicionando itens ao controle de cabeçalho
ms.date: 11/04/2016
helpviewer_keywords:
- controls [MFC], header
- CHeaderCtrl class [MFC], adding items
- header controls [MFC], adding items to
ms.assetid: 2e9a28b1-7302-4a93-8037-c5a4183e589a
ms.openlocfilehash: 897612c6d5ac96704cc0a945df65146e6a01480a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394748"
---
# <a name="adding-items-to-the-header-control"></a>Adicionando itens ao controle de cabeçalho

Depois de criar seu controle de cabeçalho ([CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)) em sua janela pai, adicione quantos "itens de cabeçalho" conforme necessário: normalmente, uma por coluna.

### <a name="to-add-a-header-item"></a>Para adicionar um item de cabeçalho

1. Preparar uma [HD_ITEM](/windows/desktop/api/commctrl/ns-commctrl-_hd_itema) estrutura.

1. Chame [CHeaderCtrl::InsertItem](../mfc/reference/cheaderctrl-class.md#insertitem), passando a estrutura.

1. Repita as etapas 1 e 2 para itens adicionais.

Para obter mais informações, consulte [adicionando um Item a um controle de cabeçalho](/windows/desktop/Controls/header-controls) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
