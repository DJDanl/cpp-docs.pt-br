---
title: "Alocando e desalocando a memória da janela | Microsoft Docs"
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
- memory allocation, window objects
- memory deallocation
- storage for window objects [MFC]
- memory deallocation, window memory
- window objects [MFC], deallocating memory for
- storage for window objects [MFC], allocating
ms.assetid: 7c962539-8461-4846-b5ca-fe3b15c313dc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 294de3c4d4ecdfcb31f6e8c227bd8a3c6764268d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="allocating-and-deallocating-window-memory"></a>Alocando e desalocando a memória da janela
Não use o C++ **excluir** operador destruir uma janela do quadro ou exibição. Em vez disso, chame o `CWnd` função de membro `DestroyWindow`. Janelas com moldura, portanto, devem ser alocadas no heap com operador **novo**. Tenha cuidado ao alocar janelas com moldura no quadro de pilha ou globalmente. Outras janelas devem ser alocadas no quadro de pilha sempre que possível.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Criando janelas](../mfc/creating-windows.md)  
  
-   [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)  
  
-   [Desanexando um CWnd de HWND](../mfc/detaching-a-cwnd-from-its-hwnd.md)  
  
## <a name="see-also"></a>Consulte também  
 [Destruindo objetos de janela](../mfc/destroying-window-objects.md)

