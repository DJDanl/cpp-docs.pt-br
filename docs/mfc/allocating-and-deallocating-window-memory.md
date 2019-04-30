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
ms.openlocfilehash: 60f99c01c7a311c31602269b49efaf434d16827a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394696"
---
# <a name="allocating-and-deallocating-window-memory"></a>Alocando e desalocando a memória da janela

Não use o C++ **excluir** operador para destruir uma janela do quadro ou da exibição. Em vez disso, chame o `CWnd` função de membro `DestroyWindow`. Janelas de quadro, portanto, devem ser alocadas no heap com o operador **novo**. Tenha cuidado ao alocar janelas com moldura no quadro da pilha ou globalmente. Outras janelas devem ser alocadas no quadro da pilha sempre que possível.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Criando janelas](../mfc/creating-windows.md)

- [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)

- [Desanexando um CWnd de HWND](../mfc/detaching-a-cwnd-from-its-hwnd.md)

## <a name="see-also"></a>Consulte também

[Destruindo objetos de janela](../mfc/destroying-window-objects.md)
