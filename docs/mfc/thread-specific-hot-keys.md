---
title: Teclas de acesso específicas de thread | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CHotKeyCtrl class [MFC], thread-specific hot keys
- keyboard shortcuts [MFC], hot keys
- threading [MFC], hot keys in CHotKeyCtrl
- access keys [MFC], hot keys
ms.assetid: b6021274-1498-483f-bcbf-ba5723547cc8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f480b293e9c57e7fa189c6427ab39147681cfdaf
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43206854"
---
# <a name="thread-specific-hot-keys"></a>Teclas de acesso específicas de thread
Um aplicativo define uma tecla de acesso específicas de thread ([CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)) usando o Windows `RegisterHotKey` função. Quando o usuário pressiona uma tecla de acesso específicas de thread, o Windows lança um [WM_HOTKEY](/windows/desktop/inputdev/wm-hotkey) mensagem para o início da fila de mensagens do thread específico. A mensagem WM_HOTKEY contém o código de tecla virtual, o estado de deslocamento e a ID definida pelo usuário de que a tecla de acesso específica que foi pressionada. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h. Para obter mais informações sobre esse método, consulte [RegisterHotKey](https://msdn.microsoft.com/library/windows/desktop/ms646309).  
  
 Observe que o estado de deslocamento sinalizadores usado na chamada para `RegisterHotKey` não são iguais aos retornados pela [GetHotKey](../mfc/reference/chotkeyctrl-class.md#gethotkey) a função de membro; você terá que converter esses sinalizadores antes de chamar `RegisterHotKey`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)   
 [Controles](../mfc/controls-mfc.md)

