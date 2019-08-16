---
title: Rótulos do item de controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- tree controls [MFC], item labels
- labels, CTreeCtrl items
- CTreeCtrl class [MFC], item labels
- item labels, tree controls
- item labels
ms.assetid: fe834107-1a25-4280-aced-774c11565805
ms.openlocfilehash: d1f7fb8b558ff4726f7787cbf355a059fbcce8b5
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513384"
---
# <a name="tree-control-item-labels"></a>Rótulos do item de controle de árvore

Normalmente, você especifica o texto do rótulo de um item ao adicionar o item ao controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)). A `InsertItem` função member pode passar uma estrutura [TVITEM](/windows/win32/api/commctrl/ns-commctrl-tvitemw) que define as propriedades do item, incluindo uma cadeia de caracteres que contém o texto do rótulo. `InsertItem`tem várias sobrecargas que podem ser chamadas com várias combinações de parâmetros.

Um controle de árvore aloca memória para armazenar cada item; o texto dos rótulos de item ocupa uma parte significativa dessa memória. Se seu aplicativo mantém uma cópia das cadeias de caracteres no controle de árvore, você pode diminuir os requisitos de memória do controle especificando o valor **LPSTR_TEXTCALLBACK** no membro *pszText* de `TV_ITEM` ou o *lpszItem* em vez de passar cadeias de caracteres reais para o controle de árvore. O uso de **LPSTR_TEXTCALLBACK** faz com que o controle de árvore recupere o texto do rótulo de um item do aplicativo sempre que o item precisar ser redesenhado. Para recuperar o texto, o controle de árvore envia uma mensagem de notificação [TVN_GETDISPINFO](/windows/win32/Controls/tvn-getdispinfo) , que inclui o endereço de uma estrutura [NMTVDISPINFO](/windows/win32/api/commctrl/ns-commctrl-tvdispinfow) . Você deve responder definindo os membros apropriados da estrutura incluída.

Um controle de árvore usa a memória alocada do heap do processo que cria o controle de árvore. O número máximo de itens em um controle de árvore é baseado na quantidade de memória disponível no heap. Cada item recebe 64 bytes.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
