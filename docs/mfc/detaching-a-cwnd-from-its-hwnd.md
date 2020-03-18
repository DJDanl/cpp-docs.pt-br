---
title: Desanexando um CWnd de HWND
ms.date: 11/04/2016
helpviewer_keywords:
- HWND, detaching CWnd from
- removing HWNDs from CWnds
- CWnd objects [MFC], detaching from HWND
- detaching CWnds from HWNDs
- Detach method (CWnd class)
ms.assetid: 6efadf84-0517-4a3f-acfd-216e088f19c6
ms.openlocfilehash: f7a6f97ba9f1dd3a928a5450c1a899ce09a4ac5f
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446964"
---
# <a name="detaching-a-cwnd-from-its-hwnd"></a>Desanexando um CWnd de HWND

Se você precisar burlar a relação de`HWND` de objeto, o MFC fornecerá outra função de membro de `CWnd`, [desanexar](../mfc/reference/cwnd-class.md#detach), que desconectará o C++ objeto de janela da janela do Windows. Isso impede que o destruidor destrua a janela do Windows quando o objeto é destruído.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Criando o Windows](../mfc/creating-windows.md)

- [Sequência de destruição de janela](../mfc/window-destruction-sequence.md)

- [Alocando e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)
