---
title: Definindo o modo de um objeto CStatusBarCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- simple mode and status bar controls
- IsSimple method, using
- SetSimple method [MFC]
- status bar controls [MFC], simple and nonsimple modes
- non-simple mode and status bar controls
- CStatusBarCtrl class [MFC], simple and nonsimple modes
ms.assetid: ca6076e5-1501-4e33-8d35-9308941e46c0
ms.openlocfilehash: 79b499533196447898ce62ea9dc86c1674fc0302
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446410"
---
# <a name="setting-the-mode-of-a-cstatusbarctrl-object"></a>Definindo o modo de um objeto CStatusBarCtrl

Há dois modos para um objeto de `CStatusBarCtrl`: simples e não simples. Na maioria dos casos, o controle da barra de status terá uma ou mais partes, juntamente com o texto e talvez um ícone ou ícones. Isso é chamado de modo não simples. Para obter mais informações sobre esse modo, consulte [Inicializando as partes de um objeto CStatusBarCtrl](../mfc/initializing-the-parts-of-a-cstatusbarctrl-object.md).

No entanto, há casos em que você só precisa exibir uma única linha de texto. Nesse caso, o modo simples é suficiente para suas necessidades. Para alterar o modo do objeto `CStatusBarCtrl` para simples, faça uma chamada para a função de membro [setsimples](../mfc/reference/cstatusbarctrl-class.md#setsimple) . Depois que o controle da barra de status estiver no modo simples, defina o texto chamando a função membro `SetText`, passando 255 como o valor para o parâmetro *nPane* .

Você pode usar a função [IsSimple](../mfc/reference/cstatusbarctrl-class.md#issimple) para determinar em qual modo o objeto `CStatusBarCtrl` está.

> [!NOTE]
>  Se o objeto da barra de status estiver sendo alterado de não simples para simples, ou vice-versa, a janela será redesenhada imediatamente e, se aplicável, quaisquer partes definidas serão automaticamente restauradas.

## <a name="see-also"></a>Consulte também

[Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
