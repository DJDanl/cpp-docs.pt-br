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
ms.openlocfilehash: e09a7bd274c44df2da48bbc007a95802fadd8cf0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365411"
---
# <a name="setting-the-mode-of-a-cstatusbarctrl-object"></a>Definindo o modo de um objeto CStatusBarCtrl

Existem dois modos `CStatusBarCtrl` para um objeto: simples e não simples. Na maioria dos casos, o controle da barra de status terá uma ou mais partes, juntamente com texto e talvez um ícone ou ícones. Isso é chamado de modo não simples. Para obter mais informações sobre este modo, consulte [Inicializando as partes de um objeto CStatusBarCtrl](../mfc/initializing-the-parts-of-a-cstatusbarctrl-object.md).

No entanto, há casos em que você só precisa exibir uma única linha de texto. Neste caso, o modo simples é suficiente para suas necessidades. Para alterar o `CStatusBarCtrl` modo do objeto para simples, faça uma chamada para a função [setSimple](../mfc/reference/cstatusbarctrl-class.md#setsimple) member. Uma vez que o controle da barra de `SetText` status esteja no modo simples, defina o texto chamando a função de membro, passando 255 como o valor para o parâmetro *nPane.*

Você pode usar a função [IsSimple](../mfc/reference/cstatusbarctrl-class.md#issimple) para determinar em que modo o `CStatusBarCtrl` objeto está.

> [!NOTE]
> Se o objeto da barra de status estiver sendo alterado de não simples para simples, ou vice-versa, a janela será imediatamente redesenhada e, se aplicável, quaisquer peças definidas serão automaticamente restauradas.

## <a name="see-also"></a>Confira também

[Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
