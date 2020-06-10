---
title: Destruindo o controle List
ms.date: 11/04/2016
helpviewer_keywords:
- list controls [MFC], destroying
- CListCtrl class [MFC], destroying controls
ms.assetid: 513ec820-3a02-49d2-b073-a6a7a3fc91b3
ms.openlocfilehash: d128a613a2a4cb595f362f843a5ae2eba830e538
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621893"
---
# <a name="destroying-the-list-control"></a>Destruindo o controle List

Se você inserir o objeto [CListCtrl](reference/clistctrl-class.md) como um membro de dados de uma exibição ou classe de caixa de diálogo, ele será destruído quando seu proprietário for destruído. Se você usar um [CListView](reference/clistview-class.md), a estrutura destruirá o controle quando destruir a exibição.

Se você organizar para alguns dos seus dados de lista a serem armazenados no aplicativo, e não no controle de lista, será necessário organizar sua desalocação. Para obter mais informações, consulte [itens de retorno de chamada e a máscara de retorno de chamada](/windows/win32/Controls/using-list-view-controls) no SDK do Windows.

Além disso, você é responsável por desalocar todas as listas de imagens criadas e associadas ao objeto de controle de lista.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](using-clistctrl.md)<br/>
[Controles](controls-mfc.md)
