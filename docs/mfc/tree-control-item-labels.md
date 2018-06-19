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
ms.openlocfilehash: 598dca9f0d5f394a8e742c1b886588eab3518bf4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33381505"
---
# <a name="tree-control-item-labels"></a>Rótulos do item de controle de árvore
Você normalmente especifica o texto do rótulo de um item ao adicionar o item ao controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)). O `InsertItem` função de membro pode passar um [TVITEM](http://msdn.microsoft.com/library/windows/desktop/bb773456) estrutura que define as propriedades do item, incluindo uma cadeia de caracteres que contém o texto do rótulo. `InsertItem` tem várias sobrecargas que podem ser chamadas com várias combinações de parâmetros.  
  
 Um controle de árvore aloca memória para armazenar cada item; o texto dos rótulos de item ocupa uma parte significativa da memória. Se seu aplicativo mantém uma cópia das cadeias de caracteres no controle de árvore, você pode diminuir os requisitos de memória do controle, especificando o **LPSTR_TEXTCALLBACK** valor o **pszText** membro `TV_ITEM` ou `lpszItem` parâmetro em vez de passar cadeias de caracteres reais para o controle de árvore. Usando **LPSTR_TEXTCALLBACK** faz com que o controle de árvore recuperar o texto do rótulo de um item do aplicativo sempre que o item precisa ser redesenhada. Para recuperar o texto, o controle de árvore envia um [TVN_GETDISPINFO](http://msdn.microsoft.com/library/windows/desktop/bb773518) mensagem de notificação, que inclui o endereço de um [NMTVDISPINFO](http://msdn.microsoft.com/library/windows/desktop/bb773418) estrutura. Você deve responder ao definir os membros apropriados da estrutura incluído.  
  
 Um controle de árvore usa a memória alocada do heap do processo que cria o controle de árvore. O número máximo de itens em um controle de árvore é com base na quantidade de memória disponível no heap. Cada item tem 64 bytes.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

