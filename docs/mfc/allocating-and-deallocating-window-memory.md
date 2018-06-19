---
title: Alocando e desalocando a memória da janela | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a1364b4d29e2ccd2c9563359716eba6880df5436
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33341453"
---
# <a name="allocating-and-deallocating-window-memory"></a>Alocando e desalocando a memória da janela
Não use o C++ **excluir** operador destruir uma janela do quadro ou exibição. Em vez disso, chame o `CWnd` função de membro `DestroyWindow`. Janelas com moldura, portanto, devem ser alocadas no heap com operador **novo**. Tenha cuidado ao alocar janelas com moldura no quadro de pilha ou globalmente. Outras janelas devem ser alocadas no quadro de pilha sempre que possível.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Criando janelas](../mfc/creating-windows.md)  
  
-   [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)  
  
-   [Desanexando um CWnd de HWND](../mfc/detaching-a-cwnd-from-its-hwnd.md)  
  
## <a name="see-also"></a>Consulte também  
 [Destruindo objetos de janela](../mfc/destroying-window-objects.md)

