---
title: Informações de controle de Item de árvore | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- tree controls [MFC], item information
- CTreeCtrl class [MFC], item information
ms.assetid: 8dcab855-27de-49e9-95d8-f78ba963ea71
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 724e9d7c4e0ee7db80f024c30e363612cb40fed1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="tree-control-item-information"></a>Informações do item de controle da árvore
Controles em árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) tem um número de funções de membro que recuperam informações sobre itens no controle. O [GetItem](../mfc/reference/ctreectrl-class.md#getitem) função membro recupera alguns ou todos os dados associados a um item. Esses dados podem incluir o texto do item, estado, imagens, contagem de itens filho e um valor de dados definido pelo aplicativo de 32 bits. Também há um [SetItem](../mfc/reference/ctreectrl-class.md#setitem) função que pode definir alguns ou todos os dados associados a um item.  
  
 O [GetItemState](../mfc/reference/ctreectrl-class.md#getitemstate), [GetItemText](../mfc/reference/ctreectrl-class.md#getitemtext), [GetItemData](../mfc/reference/ctreectrl-class.md#getitemdata), e [GetItemImage](../mfc/reference/ctreectrl-class.md#getitemimage) funções de membro recuperam atributos individuais de um item. Cada uma dessas funções tem uma função de conjunto correspondente para definir os atributos de um item.  
  
 O [GetNextItem](../mfc/reference/ctreectrl-class.md#getnextitem) função membro recupera o item de controle de árvore que tem a relação especificada para o item atual. Essa função pode recuperar o pai de um item, o item visível anterior ou seguinte, o primeiro item filho e assim por diante. Também há funções de membro para percorrer a árvore: [GetRootItem](../mfc/reference/ctreectrl-class.md#getrootitem), [GetFirstVisibleItem](../mfc/reference/ctreectrl-class.md#getfirstvisibleitem), [GetNextVisibleItem](../mfc/reference/ctreectrl-class.md#getnextvisibleitem), [GetPrevVisibleItem](../mfc/reference/ctreectrl-class.md#getprevvisibleitem), [GetChildItem](../mfc/reference/ctreectrl-class.md#getchilditem), [GetNextSiblingItem](../mfc/reference/ctreectrl-class.md#getnextsiblingitem), [GetPrevSiblingItem](../mfc/reference/ctreectrl-class.md#getprevsiblingitem), [GetParentItem](../mfc/reference/ctreectrl-class.md#getparentitem), [GetSelectedItem](../mfc/reference/ctreectrl-class.md#getselecteditem), e [GetDropHilightItem](../mfc/reference/ctreectrl-class.md#getdrophilightitem).  
  
 O [GetItemRect](../mfc/reference/ctreectrl-class.md#getitemrect) função membro recupera o retângulo delimitador para um item de controle de árvore. O [GetCount](../mfc/reference/ctreectrl-class.md#getcount) e [GetVisibleCount](../mfc/reference/ctreectrl-class.md#getvisiblecount) funções de membro recuperam uma contagem dos itens em um controle de árvore e uma contagem dos itens que estão atualmente visíveis na janela do controle de árvore, respectivamente. Você pode garantir que um determinado item está visível ao chamar o [EnsureVisible](../mfc/reference/ctreectrl-class.md#ensurevisible) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

