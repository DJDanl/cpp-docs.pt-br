---
title: Definindo uma tecla de acesso
ms.date: 11/04/2016
helpviewer_keywords:
- keyboard shortcuts [MFC], hot keys
- access keys [MFC], hot keys
- CHotKeyCtrl class [MFC], setting hot key
ms.assetid: 6f3bc141-e346-4dce-9ca7-3e6b2c453f3f
ms.openlocfilehash: 7b49f24039b130f74693e7567f5287476126f225
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69511214"
---
# <a name="setting-a-hot-key"></a>Definindo uma tecla de acesso

Seu aplicativo pode usar as informações fornecidas por um controle de tecla de acesso ([CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)) de uma das duas maneiras:

- Configure uma tecla de acesso global para ativar uma janela não-filho enviando uma mensagem [WM_SETHOTKEY](/windows/win32/inputdev/wm-sethotkey) para a janela a ser ativada.

- Configure uma tecla de acesso específica ao thread chamando a função do Windows [RegisterHotKey](/windows/win32/api/winuser/nf-winuser-registerhotkey).

## <a name="see-also"></a>Consulte também

[Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
