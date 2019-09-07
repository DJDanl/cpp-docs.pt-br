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
ms.openlocfilehash: 16bb2bbe63eaf8ea4ce30040589d4a8a4cf4dfd3
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70741457"
---
# <a name="tree-control-item-labels"></a>Rótulos do item de controle de árvore

Normalmente, você especifica o texto do rótulo de um item ao adicionar o item ao controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)). A `InsertItem` função member pode passar uma estrutura [TVITEM](/windows/win32/api/commctrl/ns-commctrl-tvitemw) que define as propriedades do item, incluindo uma cadeia de caracteres que contém o texto do rótulo. `InsertItem`tem várias sobrecargas que podem ser chamadas com várias combinações de parâmetros.

Um controle de árvore aloca memória para armazenar cada item; o texto dos rótulos de item ocupa uma parte significativa dessa memória. Se seu aplicativo mantém uma cópia das cadeias de caracteres no controle de árvore, você pode diminuir os requisitos de memória do controle especificando o valor **LPSTR_TEXTCALLBACK** no membro *pszText* de `TV_ITEM` ou o *lpszItem* em vez de passar cadeias de caracteres reais para o controle de árvore. O uso de **LPSTR_TEXTCALLBACK** faz com que o controle de árvore recupere o texto do rótulo de um item do aplicativo sempre que o item precisar ser redesenhado. Para recuperar o texto, o controle de árvore envia uma mensagem de notificação [TVN_GETDISPINFO](/windows/win32/Controls/tvn-getdispinfo) , que inclui o endereço de uma estrutura [NMTVDISPINFO](/windows/win32/api/commctrl/ns-commctrl-nmtvdispinfow) . Você deve responder definindo os membros apropriados da estrutura incluída.

Um controle de árvore usa a memória alocada do heap do processo que cria o controle de árvore. O número máximo de itens em um controle de árvore é baseado na quantidade de memória disponível no heap. Cada item recebe 64 bytes.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
