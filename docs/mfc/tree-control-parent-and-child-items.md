---
title: Itens pai e filho do controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- parent items in CTreeCtrl [MFC]
- child items in tree control [MFC]
- CTreeCtrl class [MFC], parent and child items
- tree controls [MFC], parent and child items
ms.assetid: abcea1e4-fe9b-40d9-86dc-1db235f8f103
ms.openlocfilehash: 5a02194ccef8eca81971bb4e8ae24d859e578bcc
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513965"
---
# <a name="tree-control-parent-and-child-items"></a>Itens pai e filho do controle de árvore

Qualquer item em um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) pode ter uma lista de subitens, que são chamados de itens filho, associados a ele. Um item que tem um ou mais itens filho é chamado de item pai. Um item filho é exibido abaixo de seu item pai e é recuado para indicar que ele é subordinado ao pai. Um item que não tem pai está na parte superior da hierarquia e é chamado de item raiz.

Em um determinado momento, o estado da lista de itens filho de um item pai pode ser expandido ou recolhido. Quando o estado é expandido, os itens filho são exibidos abaixo do item pai. Quando ele é recolhido, os itens filho não são exibidos. A lista alterna automaticamente entre os Estados expandidos e recolhidos quando o usuário clica duas vezes no item pai ou, se o pai tiver o estilo **TVS_HASBUTTONS** , quando o usuário clicar no botão associado ao item pai. Um aplicativo pode expandir ou recolher os itens filho usando a função de membro [Expand](../mfc/reference/ctreectrl-class.md#expand) .

Você adiciona um item a um controle de árvore chamando a função de membro [InsertItem](../mfc/reference/ctreectrl-class.md#insertitem) . Essa função retorna um identificador do tipo **HTREEITEM** , que identifica exclusivamente o item. Ao adicionar um item, você deve especificar o identificador do item pai do novo item. Se você especificar **NULL** ou o valor **TVI_ROOT** em vez de um identificador de item pai na estrutura [TVINSERTSTRUCT](/windows/win32/api/commctrl/ns-commctrl-tvinsertstructw) ou no parâmetro *hParent* , o item será adicionado como um item raiz.

Um controle de árvore envia uma mensagem de notificação [TVN_ITEMEXPANDING](/windows/win32/Controls/tvn-itemexpanding) quando a lista de itens filho de um item pai está prestes a ser expandida ou recolhida. A notificação oferece a oportunidade de evitar a alteração ou definir qualquer atributo do item pai que dependa do estado da lista de itens filho. Depois de alterar o estado da lista, o controle de árvore envia uma mensagem de notificação [TVN_ITEMEXPANDED](/windows/win32/Controls/tvn-itemexpanded) .

Quando uma lista de itens filhos é expandida, ela é recuada em relação ao item pai. Você pode definir a quantidade de recuo usando a função de membro [SetIndent](../mfc/reference/ctreectrl-class.md#setindent) ou recuperar a quantidade atual usando a função de membro [GetIndent](../mfc/reference/ctreectrl-class.md#getindent) .

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
