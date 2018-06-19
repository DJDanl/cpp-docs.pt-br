---
title: 'Como: carregar um recurso de faixa de opções de um aplicativo MFC | Microsoft Docs'
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
ms.openlocfilehash: b014e1725ae6c5043c051242a74e29338c3ef2d6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33344185"
---
# <a name="how-to-load-a-ribbon-resource-from-an-mfc-application"></a>Como carregar um recurso da faixa de opções de um aplicativo MFC
Para usar o recurso de faixa de opções em seu aplicativo, modifique o aplicativo para carregar o recurso de faixa de opções.  
  
### <a name="to-load-a-ribbon-resource"></a>Para carregar um recurso de faixa de opções  
  
1.  Declare o `Ribbon Control` objeto o `CMainFrame` classe.  
  
 ```  
    CMFCRibbonBar m_wndRibbonBar;   
 ```  
  
2.  Em `CMainFrame::OnCreate`, criar e inicializar o controle de faixa de opções.  
  
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

