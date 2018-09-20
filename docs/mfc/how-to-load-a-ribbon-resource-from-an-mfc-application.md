---
title: 'Como: carregar um recurso de faixa de opções de um aplicativo do MFC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ribbon resource [MFC], loading
ms.assetid: 1c76bb8f-6345-414a-9f3f-128815ceadc5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1643989a96a9003847fb53de624bff12cd51cd88
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46434279"
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

