---
title: "Vis&#227;o geral dos estados de item de controle da &#225;rvore | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CTreeCtrl, estados de item"
  - "estados, Itens CTreeCtrl"
  - "controles em árvore, visão geral de estados de item"
ms.assetid: 2db11ae0-0d87-499d-8c1f-5e0dbe9e94c8
caps.latest.revision: 14
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral dos estados de item de controle da &#225;rvore
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada item em um controle de árvore \([CTreeCtrl](../mfc/reference/ctreectrl-class.md)\) tem um estado atual.  Por exemplo, um item pode ser selecionado, desabilitado, expandida, e assim por diante.  Em geral, o controle de árvore define automaticamente o estado de um item para refletir as ações do usuário, como a seleção de um item.  Porém, você também pode definir o estado de um item usando a função de membro de [SetItemState](../Topic/CTreeCtrl::SetItemState.md) e recuperar o estado atual de um item usando a função de membro de [GetItemState](../Topic/CTreeCtrl::GetItemState.md) .  Para obter uma lista completa dos estados de item, consulte [Constantes de controle de exibição de árvore](http://msdn.microsoft.com/library/windows/desktop/bb759985) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
 O estado atual de um item é especificado pelo parâmetro de `nState` .  Um controle de árvore pode alterar o estado de um item para refletir uma ação de usuário, como selecionar o item ou definir o foco para o próximo item.  Além disso, um aplicativo pode alterar o estado de um item para desativar ou ocultar o item ou para especificar uma imagem de sobreposição ou a imagem do estado.  
  
 Quando você especificar ou alterar o estado de um item, o parâmetro de `nStateMask` especifica que indicam bit para definir, e o parâmetro de `nState` contém os novos valores para os bits.  Por exemplo, o exemplo a seguir altera o estado atual de um item pai \(especificado por `hParentItem`\) em um objeto de `CTreeCtrl` \(\)`m_treeCtrl`a **TVIS\_EXPANDPARTIAL**:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#71](../mfc/codesnippet/CPP/tree-control-item-states-overview_1.cpp)]  
  
 Outro exemplo de alterar o estado seria definir a imagem da sobreposição de um item.  Para fazer isso, `nStateMask` deve incluir o valor de `TVIS_OVERLAYMASK` , e `nState` deve incluir o índice da imagem da sobreposição deslocada à esquerda oito bit usando a macro de [INDEXTOOVERLAYMASK](http://msdn.microsoft.com/library/windows/desktop/bb761408) .  O índice pode ser 0 para especificar nenhuma imagem da sobreposição.  A imagem da sobreposição deve ter sido adicionada à lista de controle de árvore de imagens de sobreposição por uma chamada anterior à função de [CImageList::SetOverlayImage](../Topic/CImageList::SetOverlayImage.md) .  A função especifica o índice da imagem para adicionar; esse é o índice usado com a macro de **INDEXTOOVERLAYMASK** .  Um controle de árvore pode ter até quatro imagens cobertas.  
  
 Para definir a imagem do estado de um item, `nStateMask` deve incluir o valor de `TVIS_STATEIMAGEMASK` , e `nState` deve incluir o índice da imagem do estado deslocada à esquerda 12 bits usando a macro de [INDEXTOSTATEIMAGEMASK](http://msdn.microsoft.com/library/windows/desktop/bb775597) .  O índice pode ser 0 para especificar nenhuma imagem do estado.  Para obter mais informações sobre as imagens de sobreposição e estado, consulte [Listas da imagem do controle de árvore](../mfc/tree-control-image-lists.md).  
  
## Consulte também  
 [Usando CTreeCtrl](../Topic/Using%20CTreeCtrl.md)   
 [Controles](../mfc/controls-mfc.md)