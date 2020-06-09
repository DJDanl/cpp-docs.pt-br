---
title: Adicionando guias a um controle de guia
ms.date: 11/04/2016
helpviewer_keywords:
- tab controls [MFC], adding tabs
- putting tabs on CTabCtrls [MFC]
- CTabCtrl class [MFC], adding tabs
- tabs [MFC], adding to CTabCtrl class [MFC]
ms.assetid: 7f3d9340-e3c7-4c71-9912-be57534ecc78
ms.openlocfilehash: 89132e94396b51bee4a111b963c67d029f3dd9df
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616528"
---
# <a name="adding-tabs-to-a-tab-control"></a>Adicionando guias a um controle de guia

Depois de criar o controle guia ([CTabCtrl](reference/ctabctrl-class.md)), adicione quantas guias forem necessárias.

### <a name="to-add-a-tab-item"></a>Para adicionar um item de guia

1. Prepare uma estrutura [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) .

1. Chame [CTabCtrl:: InsertItem](reference/ctabctrl-class.md#insertitem), passando a estrutura.

1. Repita as etapas 1 e 2 para itens de guia adicionais.

Para obter mais informações, consulte [criando um controle guia](/windows/win32/Controls/tab-controls) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CTabCtrl](using-ctabctrl.md)<br/>
[Controles](controls-mfc.md)
