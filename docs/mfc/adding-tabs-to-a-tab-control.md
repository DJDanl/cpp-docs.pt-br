---
title: Adicionando guias a um controle de guia
ms.date: 11/04/2016
helpviewer_keywords:
- tab controls [MFC], adding tabs
- putting tabs on CTabCtrls [MFC]
- CTabCtrl class [MFC], adding tabs
- tabs [MFC], adding to CTabCtrl class [MFC]
ms.assetid: 7f3d9340-e3c7-4c71-9912-be57534ecc78
ms.openlocfilehash: f769de7bcf3e410cca717c17237d1e49ef8562c9
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57293576"
---
# <a name="adding-tabs-to-a-tab-control"></a>Adicionando guias a um controle de guia

Depois de criar o controle de guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)), adicionar tantos guias, conforme necessário.

### <a name="to-add-a-tab-item"></a>Para adicionar um item de guia

1. Preparar uma [TCITEM](/windows/desktop/api/commctrl/ns-commctrl-tagtcitema) estrutura.

1. Chame [CTabCtrl::InsertItem](../mfc/reference/ctabctrl-class.md#insertitem), passando a estrutura.

1. Repita as etapas 1 e 2 para itens de guia adicional.

Para obter mais informações, consulte [criando um controle guia](/windows/desktop/Controls/tab-controls) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CTabCtrl](../mfc/using-ctabctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
