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
ms.openlocfilehash: a776b4ff4799750c89a322379a063030db748eec
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33342673"
---
# <a name="detaching-a-cwnd-from-its-hwnd"></a>Desanexando um CWnd de HWND
Se você precisar evitar object -`HWND` relação, MFC fornece outra `CWnd` função de membro, [desanexar](../mfc/reference/cwnd-class.md#detach), que desconecta o objeto de janela C++ da janela do Windows. Isso impede que o destruidor destruir a janela do Windows quando o objeto é destruído.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Criando janelas](../mfc/creating-windows.md)  
  
-   [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)  
  
-   [Alocando e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)  
  
## <a name="see-also"></a>Consulte também  
 [Objetos de janela](../mfc/window-objects.md)

