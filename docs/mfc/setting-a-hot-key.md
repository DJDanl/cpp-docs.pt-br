---
title: Definindo uma tecla de acesso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- keyboard shortcuts [MFC], hot keys
- access keys [MFC], hot keys
- CHotKeyCtrl class [MFC], setting hot key
ms.assetid: 6f3bc141-e346-4dce-9ca7-3e6b2c453f3f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0c634f9eac562be2b22f79e6a71c3010e3ea3e24
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46435227"
---
# <a name="setting-a-hot-key"></a>Definindo uma tecla de acesso

Seu aplicativo pode usar as informações fornecidas por uma tecla de acesso ([CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)) controle de uma das duas maneiras:

- Configurar uma tecla de acesso global para ativar uma janela nonchild enviando uma [WM_SETHOTKEY](/windows/desktop/inputdev/wm-sethotkey) mensagem para a janela a ser ativado.

- Configurar uma tecla de acesso específicas de thread chamando a função do Windows [RegisterHotKey](https://msdn.microsoft.com/library/windows/desktop/ms646309).

## <a name="see-also"></a>Consulte também

[Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

