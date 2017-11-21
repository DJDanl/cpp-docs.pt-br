---
title: Desanexando um CWnd de HWND | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CWnd
dev_langs: C++
helpviewer_keywords:
- HWND, detaching CWnd from
- removing HWNDs from CWnds
- CWnd objects [MFC], detaching from HWND
- detaching CWnds from HWNDs
- Detach method (CWnd class)
ms.assetid: 6efadf84-0517-4a3f-acfd-216e088f19c6
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 3d1f0635933d2cf27b824c8b0a93f66429e22ea8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="detaching-a-cwnd-from-its-hwnd"></a>Desanexando um CWnd de HWND
Se você precisar evitar object -`HWND` relação, MFC fornece outra `CWnd` função de membro, [desanexar](../mfc/reference/cwnd-class.md#detach), que desconecta o objeto de janela C++ da janela do Windows. Isso impede que o destruidor destruir a janela do Windows quando o objeto é destruído.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Criando janelas](../mfc/creating-windows.md)  
  
-   [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)  
  
-   [Alocando e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)  
  
## <a name="see-also"></a>Consulte também  
 [Objetos de janela](../mfc/window-objects.md)

