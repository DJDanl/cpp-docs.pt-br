---
title: Visão geral dos estados de item de controle da árvore
ms.date: 11/04/2016
helpviewer_keywords:
- states, CTreeCtrl items
- tree controls [MFC], item states overview
- CTreeCtrl class [MFC], item states
ms.assetid: 2db11ae0-0d87-499d-8c1f-5e0dbe9e94c8
ms.openlocfilehash: bbeabf69f174fcf172808ff71f07ed05f1dc9675
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69511046"
---
# <a name="tree-control-item-states-overview"></a>Visão geral dos estados de item de controle da árvore

Cada item em um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) tem um estado atual. Por exemplo, um item pode ser selecionado, desabilitado, expandido e assim por diante. Para a maior parte, o controle de árvore define automaticamente o estado de um item para refletir as ações do usuário, como a seleção de um item. No entanto, você também pode definir o estado de um item usando a função de membro [SetItemState](../mfc/reference/ctreectrl-class.md#setitemstate) e recuperar o estado atual de um item usando a função de membro [GetItemState](../mfc/reference/ctreectrl-class.md#getitemstate) . Para obter uma lista completa de Estados de item, consulte [constantes de controle de exibição em árvore](/windows/win32/Controls/tree-view-control-item-states) no SDK do Windows.

O estado atual de um item é especificado pelo parâmetro *nState* . Um controle de árvore pode alterar o estado de um item para refletir uma ação do usuário, como selecionar o item ou definir o foco para o item. Além disso, um aplicativo pode alterar o estado de um item para desabilitar ou ocultar o item ou para especificar uma imagem de sobreposição ou imagem de estado.

Quando você especifica ou altera o estado de um item, o parâmetro *nStateMask* especifica quais bits de estado definir e o parâmetro *nState* contém os novos valores para esses bits. Por exemplo, o exemplo a seguir altera o estado atual de um item pai (especificado por *hParentItem*) em `CTreeCtrl` um objeto`m_treeCtrl`() `TVIS_EXPANDPARTIAL`para:

[!code-cpp[NVC_MFCControlLadenDialog#71](../mfc/codesnippet/cpp/tree-control-item-states-overview_1.cpp)]

Outro exemplo de alteração do estado seria definir a imagem de sobreposição de um item. Para fazer isso, *nStateMask* deve incluir o `TVIS_OVERLAYMASK` valor e *nState* deve incluir o índice baseado em um da imagem de sobreposição deslocada oito bits à esquerda usando a macro [INDEXTOOVERLAYMASK](/windows/win32/api/commctrl/nf-commctrl-indextooverlaymask) . O índice pode ser 0 para não especificar nenhuma imagem de sobreposição. A imagem de sobreposição deve ter sido adicionada à lista de imagens de sobreposição do controle de árvore por uma chamada anterior à função [CImageList:: SetOverlayImage](../mfc/reference/cimagelist-class.md#setoverlayimage) . A função especifica o índice com base em um da imagem a ser adicionada; Esse é o índice usado com a macro INDEXTOOVERLAYMASK. Um controle de árvore pode ter até quatro imagens de sobreposição.

Para definir a imagem de estado de um item, *nStateMask* deve `TVIS_STATEIMAGEMASK` incluir o valor e *nState* deve incluir o índice baseado em um da imagem de estado deslocada 12 bits à esquerda usando a macro [INDEXTOSTATEIMAGEMASK](/windows/win32/api/commctrl/nf-commctrl-indextostateimagemask) . O índice pode ser 0 para não especificar nenhuma imagem de estado. Para obter mais informações sobre sobreposição e imagens de estado, consulte lista de imagens de [controle de árvore](../mfc/tree-control-image-lists.md).

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
