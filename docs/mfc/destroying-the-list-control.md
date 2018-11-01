---
title: Destruindo o controle List
ms.date: 11/04/2016
helpviewer_keywords:
- list controls [MFC], destroying
- CListCtrl class [MFC], destroying controls
ms.assetid: 513ec820-3a02-49d2-b073-a6a7a3fc91b3
ms.openlocfilehash: 85089919ccb81003dad1eab439fa8a0d127fd9ff
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50568332"
---
# <a name="destroying-the-list-control"></a>Destruindo o controle List

Se você inserir seus [CListCtrl](../mfc/reference/clistctrl-class.md) do objeto como um membro de dados de uma classe de exibição ou a caixa de diálogo, ele é destruído quando seu proprietário é destruído. Se você usar um [CListView](../mfc/reference/clistview-class.md), o framework destrói o controle quando ele destrói o modo de exibição.

Se você organizar para alguns dos seus dados de lista a ser armazenado no aplicativo, em vez do controle de lista, você precisará fazer com que seu desalocação. Para obter mais informações, consulte [itens de retorno de chamada e a máscara de retorno de chamada](/windows/desktop/Controls/using-list-view-controls) no SDK do Windows.

Além disso, você é responsável por desalocando quaisquer listas de imagens criado e associado ao objeto de controle de lista.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

