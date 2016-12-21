---
title: "Informa&#231;&#245;es do item de controle da &#225;rvore | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Classe CTreeCtrl, informações de item"
  - "controles em árvore, informações de item"
ms.assetid: 8dcab855-27de-49e9-95d8-f78ba963ea71
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Informa&#231;&#245;es do item de controle da &#225;rvore
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os controles de árvore \([CTreeCtrl](../mfc/reference/ctreectrl-class.md)\) têm várias funções de membro que recuperam informações sobre itens no controle.  A função de membro de [GetItem](../Topic/CTreeCtrl::GetItem.md) recupera alguns ou todos os dados associados a um item.  Esses dados podem incluir o texto do item, indicam, imagens, contagem de itens filho, e um valor de dados de 32 bits definido pelo aplicativo.  Há também uma função de [SetItem](../Topic/CTreeCtrl::SetItem.md) que pode definir alguns ou todos os dados associados a um item.  
  
 [GetItemState](../Topic/CTreeCtrl::GetItemState.md), [GetItemText](../Topic/CTreeCtrl::GetItemText.md), [GetItemData](../Topic/CTreeCtrl::GetItemData.md), e as funções de membro de [GetItemImage](../Topic/CTreeCtrl::GetItemImage.md) recuperam atributos individuais de um item.  Cada uma dessas funções tem uma função de conjunto correspondentes para definir os atributos de um item.  
  
 A função de membro de [GetNextItem](../Topic/CTreeCtrl::GetNextItem.md) recupera o item do controle de árvore que carrega a relação especificada para um item atual.  Esta função pode recuperar o pai de um item, o item visível próximo ou anterior, o primeiro item filho, e assim por diante.  Também há funções de membro para percorrer a árvore: [GetRootItem](../Topic/CTreeCtrl::GetRootItem.md), [GetFirstVisibleItem](../Topic/CTreeCtrl::GetFirstVisibleItem.md), [GetNextVisibleItem](../Topic/CTreeCtrl::GetNextVisibleItem.md), [GetPrevVisibleItem](../Topic/CTreeCtrl::GetPrevVisibleItem.md), [GetChildItem](../Topic/CTreeCtrl::GetChildItem.md), [GetNextSiblingItem](../Topic/CTreeCtrl::GetNextSiblingItem.md), [GetPrevSiblingItem](../Topic/CTreeCtrl::GetPrevSiblingItem.md), [GetParentItem](../Topic/CTreeCtrl::GetParentItem.md), [GetSelectedItem](../Topic/CTreeCtrl::GetSelectedItem.md), e [GetDropHilightItem](../Topic/CTreeCtrl::GetDropHilightItem.md).  
  
 A função de membro de [GetItemRect](../Topic/CTreeCtrl::GetItemRect.md) recupera o retângulo delimitador para um item de controle de árvore.  As funções de membro de [GetCount](../Topic/CTreeCtrl::GetCount.md) e de [GetVisibleCount](../Topic/CTreeCtrl::GetVisibleCount.md) recuperam uma contagem de itens em um controle de árvore e uma contagem de itens que estão visíveis na janela de controle de árvore, respectivamente.  Você pode garantir que um item específico é visível chamando a função de membro de [EnsureVisible](../Topic/CTreeCtrl::EnsureVisible.md) .  
  
## Consulte também  
 [Usando CTreeCtrl](../Topic/Using%20CTreeCtrl.md)   
 [Controles](../mfc/controls-mfc.md)