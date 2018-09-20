---
title: Desanexando um CWnd de HWND | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CWnd
dev_langs:
- C++
helpviewer_keywords:
- HWND, detaching CWnd from
- removing HWNDs from CWnds
- CWnd objects [MFC], detaching from HWND
- detaching CWnds from HWNDs
- Detach method (CWnd class)
ms.assetid: 6efadf84-0517-4a3f-acfd-216e088f19c6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c69703d8c528d82a696fc94be76ac4a569628b4e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392639"
---
# <a name="detaching-a-cwnd-from-its-hwnd"></a>Desanexando um CWnd de HWND

Se você precisar ignorar o objeto -`HWND` relação, o MFC fornece outra `CWnd` função de membro [desanexar](../mfc/reference/cwnd-class.md#detach), que desconecta o objeto de janela C++ da janela do Windows. Isso impede que o destruidor destruir a janela do Windows, quando o objeto é destruído.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Criando janelas](../mfc/creating-windows.md)

- [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)

- [Alocando e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)

