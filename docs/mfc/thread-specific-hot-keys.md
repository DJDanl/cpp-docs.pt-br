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
ms.openlocfilehash: 14da7f0e5b0adbe72b6705700c1e9298751bc345
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36953603"
---
# <a name="thread-specific-hot-keys"></a>Teclas de acesso específicas de thread
Um aplicativo define uma tecla de acesso específicas de thread ([CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)) usando o Windows `RegisterHotKey` função. Quando o usuário pressiona uma tecla de acesso específicas de thread, o Windows envia um [WM_HOTKEY](http://msdn.microsoft.com/library/windows/desktop/ms646279) mensagem para o início da fila de mensagens de um determinado segmento. A mensagem WM_HOTKEY contém o código de tecla virtual, o estado de shift e a ID definida pelo usuário a tecla de acesso específica que foi pressionada. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. Para obter mais informações sobre esse método, consulte [RegisterHotKey](http://msdn.microsoft.com/library/windows/desktop/ms646309).  
  
 Observe que o estado de shift sinalizadores usado na chamada para `RegisterHotKey` não são iguais aos retornados pelo [GetHotKey](../mfc/reference/chotkeyctrl-class.md#gethotkey) função de membro; você precisará converter esses sinalizadores antes de chamar `RegisterHotKey`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)   
 [Controles](../mfc/controls-mfc.md)

