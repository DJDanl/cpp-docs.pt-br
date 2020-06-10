---
title: Teclas de acesso globais
ms.date: 11/04/2016
helpviewer_keywords:
- keyboard shortcuts [MFC], hot keys
- CHotKeyCtrl class [MFC], global hot keys
- access keys [MFC], hot keys
- global hot keys [MFC]
ms.assetid: e0b95d14-c571-4c9a-9cd1-e7fc1f0e278d
ms.openlocfilehash: 5fdcfbef1db0d20126f8eac144f74f8b92410504
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618743"
---
# <a name="global-hot-keys"></a>Teclas de acesso globais

Uma tecla de acesso global é associada a uma janela não-filho específica. Ele permite que o usuário ative a janela de qualquer parte do sistema. Um aplicativo define uma tecla de acesso global para uma janela específica enviando a mensagem de [WM_SETHOTKEY](/windows/win32/inputdev/wm-sethotkey) para essa janela. Por exemplo, se `m_HotKeyCtrl` for o objeto [CHotKeyCtrl](reference/chotkeyctrl-class.md) e `pMainWnd` for um ponteiro para a janela a ser ativada quando a tecla de acesso for pressionada, você poderá usar o código a seguir para associar a tecla de atalho especificada no controle com a janela apontada por `pMainWnd` .

[!code-cpp[NVC_MFCControlLadenDialog#18](codesnippet/cpp/global-hot-keys_1.cpp)]

Sempre que o usuário pressiona uma tecla de acesso global, a janela especificada recebe uma mensagem [WM_SYSCOMMAND](/windows/win32/menurc/wm-syscommand) que especifica **SC_HOTKEY** como o tipo do comando. Essa mensagem também ativa a janela que a recebe. Como essa mensagem não inclui nenhuma informação sobre a chave exata que foi pressionada, usar esse método não permite distinguir entre diferentes teclas de acesso que podem ser anexadas à mesma janela. A tecla de acesso permanece válida até que o aplicativo que enviou **WM_SETHOTKEY** seja encerrado.

## <a name="see-also"></a>Consulte também

[Usando CHotKeyCtrl](using-chotkeyctrl.md)<br/>
[Controles](controls-mfc.md)
