---
title: Como carregar um recurso da faixa de opções de um aplicativo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- ribbon resource [MFC], loading
ms.assetid: 1c76bb8f-6345-414a-9f3f-128815ceadc5
ms.openlocfilehash: 47a3b94bbcb14c6c2923524db1f6a83b687e50e8
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626407"
---
# <a name="how-to-load-a-ribbon-resource-from-an-mfc-application"></a>Como carregar um recurso da faixa de opções de um aplicativo MFC

Para usar o recurso da faixa de faixas em seu aplicativo, modifique o aplicativo para carregar o recurso da faixa de faixas.

### <a name="to-load-a-ribbon-resource"></a>Para carregar um recurso da faixa de uma

1. Declare o `Ribbon Control` objeto na `CMainFrame` classe.

```
    CMFCRibbonBar m_wndRibbonBar;
```

1. No `CMainFrame::OnCreate` , crie e inicialize o controle Ribbon.

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

[Designer de faixa de Ribbon (MFC)](ribbon-designer-mfc.md)
