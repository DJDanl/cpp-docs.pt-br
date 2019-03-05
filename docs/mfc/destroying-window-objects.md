---
title: Destruindo objetos de janela
ms.date: 11/04/2016
helpviewer_keywords:
- frame windows [MFC], destroying
- window objects [MFC], deleting
- window objects [MFC], destroying
- window objects [MFC], removing
ms.assetid: 3241fea0-c614-4a25-957d-20f21bd5fd0c
ms.openlocfilehash: f50d198f9868a70d25370f6c1399b66efaa5490b
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57289839"
---
# <a name="destroying-window-objects"></a>Destruindo objetos de janela

Deve ter cuidado com suas próprias janelas filho para destruir o objeto de janela C++ quando o usuário é concluído com a janela. Se esses objetos não são destruídos, seu aplicativo não recuperará a memória. Felizmente, a estrutura gerencia a destruição de janela, bem como a criação de janelas de quadro, exibições e caixas de diálogo. Se você criar janelas adicionais, você é responsável por destrui-los.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)

- [Alocando e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)

- [Desanexando um CWnd de HWND](../mfc/detaching-a-cwnd-from-its-hwnd.md)

- [Sequência de criação da janela geral](../mfc/general-window-creation-sequence.md)

- [Destruindo janelas com moldura](../mfc/destroying-frame-windows.md)

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)
