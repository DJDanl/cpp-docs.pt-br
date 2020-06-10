---
title: Comunicando-se com um controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- tree controls [MFC], communicating with
- CTreeCtrl class [MFC], calling member functions
- communications, tree controls
- tree controls
ms.assetid: 680ad9ee-b11f-452d-93fa-501ca7d7e069
ms.openlocfilehash: f480cdad2fce53f830b8067083a8a4be4b4e4848
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619654"
---
# <a name="communicating-with-a-tree-control"></a>Comunicando-se com um controle de árvore

Você usa métodos diferentes para chamar funções de membro em um objeto [CTreeCtrl](reference/ctreectrl-class.md) dependendo de como o objeto foi criado:

- Se o controle de árvore estiver em uma caixa de diálogo, use uma variável de membro do tipo `CTreeCtrl` que você criar na classe da caixa de diálogo.

- Se o controle de árvore for uma janela filho, use o `CTreeCtrl` objeto (ou ponteiro) que você usou para construir o objeto.

- Se você estiver usando um `CTreeView` objeto, use a função [CTreeView:: GetTreeCtrl](reference/ctreeview-class.md#gettreectrl) para obter uma referência ao controle de árvore. Você pode inicializar outra referência com esse valor ou atribuir o endereço da referência a um `CTreeCtrl` ponteiro.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](using-ctreectrl.md)<br/>
[Controles](controls-mfc.md)
