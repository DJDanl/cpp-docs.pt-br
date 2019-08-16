---
title: Destruindo o controle List
ms.date: 11/04/2016
helpviewer_keywords:
- list controls [MFC], destroying
- CListCtrl class [MFC], destroying controls
ms.assetid: 513ec820-3a02-49d2-b073-a6a7a3fc91b3
ms.openlocfilehash: 5004026da6bb309cc2c966384724b7b98e254e1d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508703"
---
# <a name="destroying-the-list-control"></a>Destruindo o controle List

Se você inserir o objeto [CListCtrl](../mfc/reference/clistctrl-class.md) como um membro de dados de uma exibição ou classe de caixa de diálogo, ele será destruído quando seu proprietário for destruído. Se você usar um [CListView](../mfc/reference/clistview-class.md), a estrutura destruirá o controle quando destruir a exibição.

Se você organizar para alguns dos seus dados de lista a serem armazenados no aplicativo, e não no controle de lista, será necessário organizar sua desalocação. Para obter mais informações, consulte [itens de retorno de chamada e a máscara de retorno de chamada](/windows/win32/Controls/using-list-view-controls) no SDK do Windows.

Além disso, você é responsável por desalocar todas as listas de imagens criadas e associadas ao objeto de controle de lista.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
