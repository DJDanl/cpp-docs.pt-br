---
title: Comunicando-se com um controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- tree controls [MFC], communicating with
- CTreeCtrl class [MFC], calling member functions
- communications, tree controls
- tree controls
ms.assetid: 680ad9ee-b11f-452d-93fa-501ca7d7e069
ms.openlocfilehash: 920608724ebb362b91efdcb3eab50b80acd20474
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57289866"
---
# <a name="communicating-with-a-tree-control"></a>Comunicando-se com um controle de árvore

Usar métodos diferentes para chamar funções de membro uma [CTreeCtrl](../mfc/reference/ctreectrl-class.md) objeto dependendo de como o objeto foi criado:

- Se o controle de árvore está em uma caixa de diálogo, use uma variável de membro de tipo `CTreeCtrl` criado por você na classe de caixa de diálogo.

- Se o controle de árvore é uma janela filho, use o `CTreeCtrl` objeto (ou ponteiro) é usado para construir o objeto.

- Se você estiver usando um `CTreeView` do objeto, use a função [CTreeView::GetTreeCtrl](../mfc/reference/ctreeview-class.md#gettreectrl) para obter uma referência ao controle de árvore. Você pode inicializar outra referência com esse valor ou atribuir o endereço da referência a um `CTreeCtrl` ponteiro.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
