---
title: Como carregar um recurso da faixa de opções de um aplicativo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- ribbon resource [MFC], loading
ms.assetid: 1c76bb8f-6345-414a-9f3f-128815ceadc5
ms.openlocfilehash: 14ba37952d6f8849c51b36901a6bc17404f938e2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50515148"
---
# <a name="how-to-load-a-ribbon-resource-from-an-mfc-application"></a>Como carregar um recurso da faixa de opções de um aplicativo MFC

Para usar o recurso de faixa de opções em seu aplicativo, modifique o aplicativo para carregar o recurso de faixa de opções.

### <a name="to-load-a-ribbon-resource"></a>Para carregar um recurso de faixa de opções

1. Declare a `Ribbon Control` do objeto no `CMainFrame` classe.

```
    CMFCRibbonBar m_wndRibbonBar;
```

1. No `CMainFrame::OnCreate`, criar e inicializar o controle de faixa de opções.

```
    if (!m_wndRibbonBar.Create (this))
{
    return -1;
}

    if (!m_wndRibbonBar.LoadFromResource(IDR_RIBBON))
{
    return -1;
}
```

## <a name="see-also"></a>Consulte também

[Designer da faixa de opções (MFC)](../mfc/ribbon-designer-mfc.md)

