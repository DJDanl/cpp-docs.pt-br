---
title: "Rótulos do Item de controle de árvore | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- tree controls [MFC], item labels
- labels, CTreeCtrl items
- CTreeCtrl class [MFC], item labels
- item labels, tree controls
- item labels
ms.assetid: fe834107-1a25-4280-aced-774c11565805
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0d9baece3986b00aa2fbcea2b4b64217618834a8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tree-control-item-labels"></a>Rótulos do item de controle de árvore
Você normalmente especifica o texto do rótulo de um item ao adicionar o item ao controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)). O `InsertItem` função de membro pode passar um [TVITEM](http://msdn.microsoft.com/library/windows/desktop/bb773456) estrutura que define as propriedades do item, incluindo uma cadeia de caracteres que contém o texto do rótulo. `InsertItem`tem várias sobrecargas que podem ser chamadas com várias combinações de parâmetros.  
  
 Um controle de árvore aloca memória para armazenar cada item; o texto dos rótulos de item ocupa uma parte significativa da memória. Se seu aplicativo mantém uma cópia das cadeias de caracteres no controle de árvore, você pode diminuir os requisitos de memória do controle, especificando o **LPSTR_TEXTCALLBACK** valor o **pszText** membro `TV_ITEM` ou `lpszItem` parâmetro em vez de passar cadeias de caracteres reais para o controle de árvore. Usando **LPSTR_TEXTCALLBACK** faz com que o controle de árvore recuperar o texto do rótulo de um item do aplicativo sempre que o item precisa ser redesenhada. Para recuperar o texto, o controle de árvore envia um [TVN_GETDISPINFO](http://msdn.microsoft.com/library/windows/desktop/bb773518) mensagem de notificação, que inclui o endereço de um [NMTVDISPINFO](http://msdn.microsoft.com/library/windows/desktop/bb773418) estrutura. Você deve responder ao definir os membros apropriados da estrutura incluído.  
  
 Um controle de árvore usa a memória alocada do heap do processo que cria o controle de árvore. O número máximo de itens em um controle de árvore é com base na quantidade de memória disponível no heap. Cada item tem 64 bytes.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

