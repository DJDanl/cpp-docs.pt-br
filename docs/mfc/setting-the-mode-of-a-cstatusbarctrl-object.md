---
title: Definindo o modo de um objeto CStatusBarCtrl
ms.date: 11/04/2016
f1_keywords:
- CStatusBarCtrl
helpviewer_keywords:
- simple mode and status bar controls
- IsSimple method, using
- SetSimple method [MFC]
- status bar controls [MFC], simple and nonsimple modes
- non-simple mode and status bar controls
- CStatusBarCtrl class [MFC], simple and nonsimple modes
ms.assetid: ca6076e5-1501-4e33-8d35-9308941e46c0
ms.openlocfilehash: a6d1a0edb356f9737aa287809dd8bca4146c1854
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57287928"
---
# <a name="setting-the-mode-of-a-cstatusbarctrl-object"></a>Definindo o modo de um objeto CStatusBarCtrl

Há dois modos para um `CStatusBarCtrl` objeto: simples e. Na maioria dos casos, o controle de barra de status terá uma ou mais partes, juntamente com o texto e talvez um ícone ou ícones. Isso é chamado de modo simples. Para obter mais informações sobre esse modo, consulte [inicializando as partes de um objeto CStatusBarCtrl](../mfc/initializing-the-parts-of-a-cstatusbarctrl-object.md).

No entanto, há casos em que você precisa exibir apenas uma única linha de texto. Nesse caso, o modo simple é suficiente para suas necessidades. Para alterar o modo dos `CStatusBarCtrl` objeto como simple, fazer uma chamada para o [SetSimple](../mfc/reference/cstatusbarctrl-class.md#setsimple) função de membro. Depois que o controle de barra de status está no modo simple, definir o texto chamando o `SetText` função de membro, passando 255 como o valor para o *nPane* parâmetro.

Você pode usar o [IsSimple](../mfc/reference/cstatusbarctrl-class.md#issimple) função para determinar qual modo o `CStatusBarCtrl` objeto está em.

> [!NOTE]
>  Se o objeto de barra de status é alterado de não simples como simples ou vice-versa, a janela imediatamente é redesenhada e, se aplicável, qualquer partes definidas são restauradas automaticamente.

## <a name="see-also"></a>Consulte também

[Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
