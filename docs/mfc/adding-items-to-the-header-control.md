---
title: Adicionando itens ao controle de cabeçalho
ms.date: 11/04/2016
helpviewer_keywords:
- controls [MFC], header
- CHeaderCtrl class [MFC], adding items
- header controls [MFC], adding items to
ms.assetid: 2e9a28b1-7302-4a93-8037-c5a4183e589a
ms.openlocfilehash: 5749a0cae2dfe7e6c9f4c166eca487e36c2d21d2
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616461"
---
# <a name="adding-items-to-the-header-control"></a>Adicionando itens ao controle de cabeçalho

Depois de criar o controle de cabeçalho ([CHeaderCtrl](reference/cheaderctrl-class.md)) em sua janela pai, adicione quantos "itens de cabeçalho" forem necessários: geralmente um por coluna.

### <a name="to-add-a-header-item"></a>Para adicionar um item de cabeçalho

1. Prepare uma estrutura de [HD_ITEM](/windows/win32/api/commctrl/ns-commctrl-hditemw) .

1. Chame [CHeaderCtrl:: InsertItem](reference/cheaderctrl-class.md#insertitem), passando a estrutura.

1. Repita as etapas 1 e 2 para itens adicionais.

Para obter mais informações, consulte [adicionando um item a um controle de cabeçalho](/windows/win32/Controls/header-controls) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](using-cheaderctrl.md)<br/>
[Controles](controls-mfc.md)
