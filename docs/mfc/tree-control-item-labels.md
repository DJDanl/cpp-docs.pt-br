---
title: Rótulos do Item de controle de árvore | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- tree controls [MFC], item labels
- labels, CTreeCtrl items
- CTreeCtrl class [MFC], item labels
- item labels, tree controls
- item labels
ms.assetid: fe834107-1a25-4280-aced-774c11565805
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3f07032a203761e78bd44f40456093eae9a84d07
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46399869"
---
# <a name="tree-control-item-labels"></a>Rótulos do item de controle de árvore

Você normalmente especifica o texto do rótulo de um item ao adicionar o item ao controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)). O `InsertItem` função de membro pode passar uma [TVITEM](/windows/desktop/api/commctrl/ns-commctrl-tagtvitema) estrutura que define as propriedades do item, incluindo uma cadeia de caracteres que contém o texto do rótulo. `InsertItem` tem várias sobrecargas que podem ser chamadas com várias combinações de parâmetros.

Um controle de árvore aloca memória para armazenar cada item; o texto dos rótulos de item ocupa uma parte significativa da memória. Se seu aplicativo mantém uma cópia das cadeias de caracteres no controle de árvore, você pode diminuir os requisitos de memória do controle especificando o **LPSTR_TEXTCALLBACK** valor na *pszText* membro `TV_ITEM` ou o *lpszItem* parâmetro em vez de passar cadeias de caracteres reais para o controle de árvore. Usando o **LPSTR_TEXTCALLBACK** faz com que o controle de árvore recuperar o texto do rótulo de um item do aplicativo sempre que o item precisa ser redesenhado. Para recuperar o texto, o controle de árvore envia um [TVN_GETDISPINFO](/windows/desktop/Controls/tvn-getdispinfo) mensagem de notificação, que inclui o endereço de uma [NMTVDISPINFO](/windows/desktop/api/commctrl/ns-commctrl-tagtvdispinfoa) estrutura. Você deve responder ao definir os membros adequados da estrutura incluído.

Um controle de árvore usa a memória alocada do heap do processo que cria o controle de árvore. O número máximo de itens em um controle de árvore é com base na quantidade de memória disponível no heap. Cada item tem 64 bytes.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

