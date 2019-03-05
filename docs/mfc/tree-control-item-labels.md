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
ms.openlocfilehash: c945556ff9236db1ca61b15f1072efdc2f49541f
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57278880"
---
# <a name="tree-control-item-labels"></a>Rótulos do item de controle de árvore

Você normalmente especifica o texto do rótulo de um item ao adicionar o item ao controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)). O `InsertItem` função de membro pode passar uma [TVITEM](/windows/desktop/api/commctrl/ns-commctrl-tagtvitema) estrutura que define as propriedades do item, incluindo uma cadeia de caracteres que contém o texto do rótulo. `InsertItem` tem várias sobrecargas que podem ser chamadas com várias combinações de parâmetros.

Um controle de árvore aloca memória para armazenar cada item; o texto dos rótulos de item ocupa uma parte significativa da memória. Se seu aplicativo mantém uma cópia das cadeias de caracteres no controle de árvore, você pode diminuir os requisitos de memória do controle especificando o **LPSTR_TEXTCALLBACK** valor na *pszText* membro `TV_ITEM` ou o *lpszItem* parâmetro em vez de passar cadeias de caracteres reais para o controle de árvore. Usando o **LPSTR_TEXTCALLBACK** faz com que o controle de árvore recuperar o texto do rótulo de um item do aplicativo sempre que o item precisa ser redesenhado. Para recuperar o texto, o controle de árvore envia um [TVN_GETDISPINFO](/windows/desktop/Controls/tvn-getdispinfo) mensagem de notificação, que inclui o endereço de uma [NMTVDISPINFO](/windows/desktop/api/commctrl/ns-commctrl-tagtvdispinfoa) estrutura. Você deve responder ao definir os membros adequados da estrutura incluído.

Um controle de árvore usa a memória alocada do heap do processo que cria o controle de árvore. O número máximo de itens em um controle de árvore é com base na quantidade de memória disponível no heap. Cada item tem 64 bytes.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
