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
ms.openlocfilehash: 2e0484698654cd14f22a92be76a80f71c0f9adf5
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621853"
---
# <a name="detaching-a-cwnd-from-its-hwnd"></a>Desanexando um CWnd de HWND

Se você precisar burlar a relação de objeto `HWND` , o MFC fornecerá outra `CWnd` função de membro, [desanexar](reference/cwnd-class.md#detach), que desconectará o objeto de janela C++ da janela do Windows. Isso impede que o destruidor destrua a janela do Windows quando o objeto é destruído.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Criando o Windows](creating-windows.md)

- [Sequência de destruição de janela](window-destruction-sequence.md)

- [Alocando e desalocando a memória da janela](allocating-and-deallocating-window-memory.md)

## <a name="see-also"></a>Consulte também

[Objetos de janela](window-objects.md)
