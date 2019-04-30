---
title: Desanexando um CWnd de HWND
ms.date: 11/04/2016
f1_keywords:
- CWnd
helpviewer_keywords:
- HWND, detaching CWnd from
- removing HWNDs from CWnds
- CWnd objects [MFC], detaching from HWND
- detaching CWnds from HWNDs
- Detach method (CWnd class)
ms.assetid: 6efadf84-0517-4a3f-acfd-216e088f19c6
ms.openlocfilehash: 259af94958f88643e9c3ce725b25c4e92cc38226
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394566"
---
# <a name="detaching-a-cwnd-from-its-hwnd"></a>Desanexando um CWnd de HWND

Se você precisar ignorar o objeto -`HWND` relação, o MFC fornece outra `CWnd` função de membro [desanexar](../mfc/reference/cwnd-class.md#detach), que desconecta o objeto de janela C++ da janela do Windows. Isso impede que o destruidor destruir a janela do Windows, quando o objeto é destruído.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Criando janelas](../mfc/creating-windows.md)

- [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)

- [Alocando e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)
