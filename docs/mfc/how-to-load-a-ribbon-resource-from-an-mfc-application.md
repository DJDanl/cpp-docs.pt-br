---
title: 'Como: Carregar um recurso de faixa de opções de um aplicativo do MFC'
ms.date: 11/04/2016
helpviewer_keywords:
- ribbon resource [MFC], loading
ms.assetid: 1c76bb8f-6345-414a-9f3f-128815ceadc5
ms.openlocfilehash: b7691d4168101209b0e2d2500012a2b4a8e47788
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57289544"
---
# <a name="how-to-load-a-ribbon-resource-from-an-mfc-application"></a>Como: Carregar um recurso de faixa de opções de um aplicativo do MFC

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
