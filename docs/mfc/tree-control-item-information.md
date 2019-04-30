---
title: Informações do item de controle da árvore
ms.date: 11/04/2016
helpviewer_keywords:
- tree controls [MFC], item information
- CTreeCtrl class [MFC], item information
ms.assetid: 8dcab855-27de-49e9-95d8-f78ba963ea71
ms.openlocfilehash: e0eb8af4fbbb6f59c0dda75ec3705183ce916350
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62407855"
---
# <a name="tree-control-item-information"></a>Informações do item de controle da árvore

Controles de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) têm um número de funções de membro que recuperam informações sobre itens no controle. O [GetItem](../mfc/reference/ctreectrl-class.md#getitem) função de membro recupera alguns ou todos os dados associados a um item. Esses dados pode incluir o texto do item, estado, imagens, contagem de itens filhos e um valor de dados definido pelo aplicativo de 32 bits. Há também uma [SetItem](../mfc/reference/ctreectrl-class.md#setitem) função que pode definir alguns ou todos os dados associados a um item.

O [GetItemState](../mfc/reference/ctreectrl-class.md#getitemstate), [GetItemText](../mfc/reference/ctreectrl-class.md#getitemtext), [GetItemData](../mfc/reference/ctreectrl-class.md#getitemdata), e [GetItemImage](../mfc/reference/ctreectrl-class.md#getitemimage) funções de membro recuperar atributos individuais de um item. Cada uma dessas funções tem uma função de conjunto correspondente para definir os atributos de um item.

O [GetNextItem](../mfc/reference/ctreectrl-class.md#getnextitem) função de membro recupera o item de controle de árvore que tem a relação especificada para o item atual. Essa função pode recuperar o pai de um item, o item visível anterior ou seguinte, o primeiro item filho e assim por diante. Também há funções de membro para percorrer a árvore: [GetRootItem](../mfc/reference/ctreectrl-class.md#getrootitem), [GetFirstVisibleItem](../mfc/reference/ctreectrl-class.md#getfirstvisibleitem), [GetNextVisibleItem](../mfc/reference/ctreectrl-class.md#getnextvisibleitem), [GetPrevVisibleItem](../mfc/reference/ctreectrl-class.md#getprevvisibleitem), [GetChildItem](../mfc/reference/ctreectrl-class.md#getchilditem), [GetNextSiblingItem](../mfc/reference/ctreectrl-class.md#getnextsiblingitem), [GetPrevSiblingItem](../mfc/reference/ctreectrl-class.md#getprevsiblingitem), [GetParentItem](../mfc/reference/ctreectrl-class.md#getparentitem), [GetSelectedItem](../mfc/reference/ctreectrl-class.md#getselecteditem), e [ GetDropHilightItem](../mfc/reference/ctreectrl-class.md#getdrophilightitem).

O [GetItemRect](../mfc/reference/ctreectrl-class.md#getitemrect) função de membro recupera o retângulo delimitador para um item de controle de árvore. O [GetCount](../mfc/reference/ctreectrl-class.md#getcount) e [GetVisibleCount](../mfc/reference/ctreectrl-class.md#getvisiblecount) funções de membro recuperem uma contagem dos itens em um controle de árvore e uma contagem dos itens que estão atualmente visíveis na janela do controle de árvore, respectivamente. Você pode garantir que um determinado item está visível por meio da chamada a [EnsureVisible](../mfc/reference/ctreectrl-class.md#ensurevisible) função de membro.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
