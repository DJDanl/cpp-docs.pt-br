---
title: "Como carregar um recurso da faixa de op&#231;&#245;es de um aplicativo MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "recurso de faixa de opções, carregando"
ms.assetid: 1c76bb8f-6345-414a-9f3f-128815ceadc5
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como carregar um recurso da faixa de op&#231;&#245;es de um aplicativo MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para usar o recurso de fita em seu aplicativo, modifique o aplicativo carrega o recurso de fita.  
  
### Para carregar um recurso de fita  
  
1.  Declare o objeto de `Ribbon Control` na classe de `CMainFrame` .  
  
    ```  
    CMFCRibbonBar m_wndRibbonBar;   
    ```  
  
2.  Em `CMainFrame::OnCreate`, crie e inicializar o controle da Faixa De Opções.  
  
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
  
## Consulte também  
 [Designer da faixa de opções \(MFC\)](../mfc/ribbon-designer-mfc.md)