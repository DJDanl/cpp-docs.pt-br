---
title: Destruindo objetos de janela
ms.date: 11/04/2016
helpviewer_keywords:
- frame windows [MFC], destroying
- window objects [MFC], deleting
- window objects [MFC], destroying
- window objects [MFC], removing
ms.assetid: 3241fea0-c614-4a25-957d-20f21bd5fd0c
ms.openlocfilehash: 22b483c1005931b229453ae229935c0e716ab726
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621856"
---
# <a name="destroying-window-objects"></a>Destruindo objetos de janela

Deve-se ter cuidado com suas próprias janelas filhas para destruir o objeto de janela C++ quando o usuário termina com a janela. Se esses objetos não forem destruídos, seu aplicativo não recuperará sua memória. Felizmente, a estrutura gerencia a destruição de janelas, bem como a criação de janelas de quadros, exibições e caixas de diálogo. Se você criar janelas adicionais, será responsável por destruí-las.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Sequência de destruição de janela](window-destruction-sequence.md)

- [Alocando e desalocando a memória da janela](allocating-and-deallocating-window-memory.md)

- [Desanexando um CWnd de seu HWND](detaching-a-cwnd-from-its-hwnd.md)

- [Sequência de criação de janela geral](general-window-creation-sequence.md)

- [Destruindo janelas com moldura](destroying-frame-windows.md)

## <a name="see-also"></a>Consulte também

[Objetos de janela](window-objects.md)
