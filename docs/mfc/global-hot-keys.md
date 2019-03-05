---
title: Teclas de acesso globais
ms.date: 11/04/2016
helpviewer_keywords:
- keyboard shortcuts [MFC], hot keys
- CHotKeyCtrl class [MFC], global hot keys
- access keys [MFC], hot keys
- global hot keys [MFC]
ms.assetid: e0b95d14-c571-4c9a-9cd1-e7fc1f0e278d
ms.openlocfilehash: eedeb0547320c8b421fa72647f51b02f834af300
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57273615"
---
# <a name="global-hot-keys"></a>Teclas de acesso globais

Uma tecla de acesso global está associada uma janela nonchild específico. Ele permite que o usuário ative a janela a partir de qualquer parte do sistema. Um aplicativo define uma tecla de acesso global para uma determinada janela, enviando a [WM_SETHOTKEY](/windows/desktop/inputdev/wm-sethotkey) mensagem para essa janela. Por exemplo, se `m_HotKeyCtrl` é o [CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md) objeto e `pMainWnd` é um ponteiro para a janela a ser ativado quando é pressionada a tecla de acesso, você pode usar o código a seguir para associar a tecla de acesso especificada no controle com a janela apontado pelo `pMainWnd`.

[!code-cpp[NVC_MFCControlLadenDialog#18](../mfc/codesnippet/cpp/global-hot-keys_1.cpp)]

Sempre que o usuário pressiona uma tecla de acesso global, a janela especificada recebe um [WM_SYSCOMMAND](/windows/desktop/menurc/wm-syscommand) mensagem especifica **SC_HOTKEY** como o tipo do comando. Essa mensagem também ativa a janela que recebe a ele. Como esta mensagem não incluir todas as informações na chave exato que foi pressionada, usando esse método não permite fazer a distinção entre teclas de acesso diferentes que podem ser conectadas à mesma janela. A tecla de acesso permanece válida até o aplicativo que enviou **WM_SETHOTKEY** é encerrado.

## <a name="see-also"></a>Consulte também

[Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
