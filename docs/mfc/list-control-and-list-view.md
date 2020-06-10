---
title: Controle e exibição de lista
ms.date: 11/04/2016
helpviewer_keywords:
- CListView class [MFC], and CListCtrl
- views [MFC], list and list control
- CListCtrl class [MFC], and CListView
- list views [MFC]
- list controls [MFC], List view
ms.assetid: 7aee1c48-b158-4399-be0b-be366993665e
ms.openlocfilehash: d308cfe83f02dcfe3687790c6638d268cc69fc24
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621437"
---
# <a name="list-control-and-list-view"></a>Controle e exibição de lista

Para sua conveniência, o MFC encapsula o controle de lista de duas maneiras. Você pode usar controles de lista:

- Diretamente, inserindo um objeto [CListCtrl](reference/clistctrl-class.md) em uma classe de caixa de diálogo.

- Indiretamente, usando a classe [CListView](reference/clistview-class.md).

`CListView`facilita a integração de um controle de lista com a arquitetura de documento/exibição do MFC, encapsulando o controle da mesma forma que o [CEditView](reference/ceditview-class.md) encapsula um controle de edição: o controle preenche toda a área da superfície de uma exibição do MFC. (A exibição *é* o controle, Cast to `CListView` .)

Um `CListView` objeto herda de [CCtrlView](reference/cctrlview-class.md) e suas classes base e adiciona uma função de membro para recuperar o controle de lista subjacente. Use exibir membros para trabalhar com a exibição como uma exibição. Use a função de membro [GetListCtrl](reference/clistview-class.md#getlistctrl) para obter acesso às funções de membro do controle de lista. Use estes membros para:

- Adicione, exclua ou manipule "itens" na lista.

- Definir ou obter atributos de controle de lista.

Para obter uma referência para o `CListCtrl` subjacente a `CListView` , chame `GetListCtrl` de sua classe de exibição de lista:

[!code-cpp[NVC_MFCListView#4](../atl/reference/codesnippet/cpp/list-control-and-list-view_1.cpp)]

Este tópico descreve as duas maneiras de usar o controle de lista.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](using-clistctrl.md)<br/>
[Controles](controls-mfc.md)
