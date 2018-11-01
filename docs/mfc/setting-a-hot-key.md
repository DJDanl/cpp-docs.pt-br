---
title: Definindo uma tecla de acesso
ms.date: 11/04/2016
helpviewer_keywords:
- keyboard shortcuts [MFC], hot keys
- access keys [MFC], hot keys
- CHotKeyCtrl class [MFC], setting hot key
ms.assetid: 6f3bc141-e346-4dce-9ca7-3e6b2c453f3f
ms.openlocfilehash: a5dc885767137a4e53d1ea0d066944d5f276c38c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50508791"
---
# <a name="setting-a-hot-key"></a>Definindo uma tecla de acesso

Seu aplicativo pode usar as informações fornecidas por uma tecla de acesso ([CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)) controle de uma das duas maneiras:

- Configurar uma tecla de acesso global para ativar uma janela nonchild enviando uma [WM_SETHOTKEY](/windows/desktop/inputdev/wm-sethotkey) mensagem para a janela a ser ativado.

- Configurar uma tecla de acesso específicas de thread chamando a função do Windows [RegisterHotKey](https://msdn.microsoft.com/library/windows/desktop/ms646309).

## <a name="see-also"></a>Consulte também

[Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

