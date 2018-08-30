---
title: Visão geral de estados de Item de controle de árvore | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- states, CTreeCtrl items
- tree controls [MFC], item states overview
- CTreeCtrl class [MFC], item states
ms.assetid: 2db11ae0-0d87-499d-8c1f-5e0dbe9e94c8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: be5c0d3e477103edaf31bafed01265a509e48ad1
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43198335"
---
# <a name="tree-control-item-states-overview"></a>Visão geral dos estados de item de controle da árvore
Cada item em um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) tem um estado atual. Por exemplo, um item pode ser selecionado, desabilitado, expandida e assim por diante. Na maior parte, o controle de árvore define automaticamente o estado de um item para refletir as ações do usuário, como seleção de um item. No entanto, você também pode definir o estado de um item usando o [SetItemState](../mfc/reference/ctreectrl-class.md#setitemstate) função de membro e como recuperar o estado atual de um item usando o [GetItemState](../mfc/reference/ctreectrl-class.md#getitemstate) função de membro. Para obter uma lista completa dos Estados de item, consulte [constantes de controle de exibição de árvore](/windows/desktop/Controls/tree-view-control-item-states) no SDK do Windows.  
  
 Estado atual de um item for especificado o *nState* parâmetro. Um controle de árvore pode alterar o estado de um item para refletir uma ação do usuário, como selecionar o item ou definir o foco para o item. Além disso, um aplicativo pode alterar o estado de um item para desativar ou ocultar o item ou para especificar uma imagem de sobreposição ou a imagem de estado.  
  
 Quando você especificar ou alterar o estado de um item, o *nStateMask* parâmetro especifica qual estado de bits a ser definido e o *nState* parâmetro contém os novos valores para esses bits. Por exemplo, o exemplo a seguir altera o estado atual de um item pai (especificado por *hParentItem*) em um `CTreeCtrl` objeto (`m_treeCtrl`) para `TVIS_EXPANDPARTIAL`:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#71](../mfc/codesnippet/cpp/tree-control-item-states-overview_1.cpp)]  
  
 Outro exemplo de como alterar o estado seria definir a imagem de sobreposição de um item. Para fazer isso, *nStateMask* deve incluir o `TVIS_OVERLAYMASK` valor, e *nState* deve incluir o índice baseado em um de uma imagem de sobreposição deslocados para a esquerda oito bits usando o [ INDEXTOOVERLAYMASK](/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro. O índice pode ser 0 para não especificar nenhuma imagem de sobreposição. Uma imagem de sobreposição deve ter sido adicionada à lista do controle de árvore das imagens de sobreposição por uma chamada anterior para o [CImageList::SetOverlayImage](../mfc/reference/cimagelist-class.md#setoverlayimage) função. A função especifica o índice baseado em um de imagem a ser adicionada; Este é o índice usado com a macro INDEXTOOVERLAYMASK. Um controle de árvore pode ter até quatro imagens de sobreposição.  
  
 Para definir a imagem de estado de um item *nStateMask* deve incluir o `TVIS_STATEIMAGEMASK` valor, e *nState* deve incluir o índice baseado em um da imagem do estado deslocados para a esquerda de 12 bits usando o [ INDEXTOSTATEIMAGEMASK](/windows/desktop/api/commctrl/nf-commctrl-indextostateimagemask) macro. O índice pode ser 0 para não especificar nenhuma imagem de estado. Para obter mais informações sobre imagens de sobreposição e estado, consulte [listas de imagens de controle de árvore](../mfc/tree-control-image-lists.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

