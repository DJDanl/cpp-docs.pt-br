---
title: Visão geral dos Estados de Item de controle de árvore | Microsoft Docs
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
ms.openlocfilehash: 3bc62308642492aa00a139fb15cc9e6cdcfc3247
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="tree-control-item-states-overview"></a>Visão geral dos estados de item de controle da árvore
Cada item em um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) tem um estado atual. Por exemplo, um item pode ser selecionado, desabilitado, expandido e assim por diante. A maior parte do tempo, o controle de árvore define automaticamente o estado de um item para refletir as ações do usuário, como a seleção de um item. No entanto, você também pode definir o estado de um item usando o [SetItemState](../mfc/reference/ctreectrl-class.md#setitemstate) função de membro e recuperar o estado atual de um item usando o [GetItemState](../mfc/reference/ctreectrl-class.md#getitemstate) função de membro. Para obter uma lista completa dos Estados de item, consulte [constantes de controle de exibição de árvore](http://msdn.microsoft.com/library/windows/desktop/bb759985) no SDK do Windows.  
  
 Estado atual do item é especificado pelo `nState` parâmetro. Um controle de árvore pode alterar o estado de um item para refletir uma ação do usuário, como selecionar o item ou definir o foco para o item. Além disso, um aplicativo pode alterar o estado de um item para desabilitar ou ocultar o item ou para especificar uma imagem de estado ou de imagem de sobreposição.  
  
 Quando você especificar ou alterar o estado de um item, o `nStateMask` parâmetro especifica qual estado bits para definir e o `nState` parâmetro contém os novos valores para esses bits. Por exemplo, o exemplo a seguir altera o estado atual de um item pai (especificado por `hParentItem`) em um `CTreeCtrl` objeto (`m_treeCtrl`) para **TVIS_EXPANDPARTIAL**:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#71](../mfc/codesnippet/cpp/tree-control-item-states-overview_1.cpp)]  
  
 Outro exemplo de como alterar o estado seria definir a imagem de sobreposição de um item. Para fazer isso, `nStateMask` deve incluir o `TVIS_OVERLAYMASK` valor, e `nState` deve incluir o índice baseado em um da imagem de sobreposição deslocada à esquerda de oito bits usando o [INDEXTOOVERLAYMASK](http://msdn.microsoft.com/library/windows/desktop/bb761408) macro. O índice pode ser 0 para não especificar nenhuma imagem de sobreposição. A imagem de sobreposição deverá ter sido adicionada à lista de controle de árvore de imagens de sobreposição por uma chamada anterior a [CImageList::SetOverlayImage](../mfc/reference/cimagelist-class.md#setoverlayimage) função. A função especifica o índice de base um da imagem para adicionar; Esse é o índice usado com o **INDEXTOOVERLAYMASK** macro. Um controle de árvore pode ter até quatro imagens de sobreposição.  
  
 Para definir a imagem do estado de um item, `nStateMask` deve incluir o `TVIS_STATEIMAGEMASK` valor, e `nState` deve incluir o índice baseado em um da imagem do estado deslocada à esquerda de 12 bits usando o [INDEXTOSTATEIMAGEMASK](http://msdn.microsoft.com/library/windows/desktop/bb775597) macro. O índice pode ser 0 para não especificar nenhuma imagem de estado. Para obter mais informações sobre as imagens de sobreposição e estado, consulte [listas de imagens de controle de árvore](../mfc/tree-control-image-lists.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

