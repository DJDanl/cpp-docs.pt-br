---
title: Alocando e desalocando a memória da janela
ms.date: 11/04/2016
helpviewer_keywords:
- memory allocation, window objects
- memory deallocation
- storage for window objects [MFC]
- memory deallocation, window memory
- window objects [MFC], deallocating memory for
- storage for window objects [MFC], allocating
ms.assetid: 7c962539-8461-4846-b5ca-fe3b15c313dc
ms.openlocfilehash: 33d471b41c8f1fd670e25626049ecd9b06b034e1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87195194"
---
# <a name="allocating-and-deallocating-window-memory"></a>Alocando e desalocando a memória da janela

Não use o operador C++ **`delete`** para destruir uma janela ou exibição de quadro. Em vez disso, chame a `CWnd` função de membro `DestroyWindow` . Janelas de quadros, portanto, devem ser alocadas no heap com o operador **`new`** . Tenha cuidado ao alocar janelas de quadros no quadro de pilhas ou globalmente. Outras janelas devem ser alocadas no quadro de pilha sempre que possível.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Criando janelas](creating-windows.md)

- [Sequência de destruição da janela](window-destruction-sequence.md)

- [Desanexando um CWnd de HWND](detaching-a-cwnd-from-its-hwnd.md)

## <a name="see-also"></a>Confira também

[Destruindo objetos de janela](destroying-window-objects.md)
