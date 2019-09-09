---
title: Teclas de acesso específicas de thread
ms.date: 11/04/2016
helpviewer_keywords:
- CHotKeyCtrl class [MFC], thread-specific hot keys
- keyboard shortcuts [MFC], hot keys
- threading [MFC], hot keys in CHotKeyCtrl
- access keys [MFC], hot keys
ms.assetid: b6021274-1498-483f-bcbf-ba5723547cc8
ms.openlocfilehash: 49bac6ac357924c26f131bbd8e1092cd74514167
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69511143"
---
# <a name="thread-specific-hot-keys"></a>Teclas de acesso específicas de thread

Um aplicativo define uma tecla de acesso específica ao thread ([CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)) usando a função `RegisterHotKey` do Windows. Quando o usuário pressiona uma tecla de acesso específica a um thread, o Windows posta uma mensagem [WM_HOTKEY](/windows/win32/inputdev/wm-hotkey) no início de uma fila de mensagens de um thread específico. A mensagem WM_HOTKEY contém o código de chave virtual, o estado de deslocamento e a ID definida pelo usuário da tecla de acesso específica que foi pressionada. Para obter uma lista de códigos de chave virtual padrão, consulte WinUser. h. Para obter mais informações sobre esse método, consulte [RegisterHotKey](/windows/win32/api/winuser/nf-winuser-registerhotkey).

Observe que os sinalizadores de estado de mudança usados na chamada `RegisterHotKey` para não são iguais aos retornados pela função de [membro](../mfc/reference/chotkeyctrl-class.md#gethotkey) ; você precisará converter esses sinalizadores antes de `RegisterHotKey`chamar.

## <a name="see-also"></a>Consulte também

[Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
