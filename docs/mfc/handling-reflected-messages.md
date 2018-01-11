---
title: Manipulando mensagens refletidas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- message handling [MFC], reflected messages
- reflected messages, handling
ms.assetid: 147a4e0c-51cc-4447-a8e1-c28b4cece578
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0c3576e93ce7ce2d972e78433065feaf06f3ae15
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="handling-reflected-messages"></a>Manipulando mensagens refletidas
Mensagem de reflexão permite que você manipule as mensagens para um controle, como `WM_CTLCOLOR`, **WM_COMMAND**, e **WM_NOTIFY**, no próprio controle. Isso torna o controle mais portátil e autossuficiente. O mecanismo funciona com controles comuns do Windows, bem como com controles ActiveX (anteriormente chamado de controles OLE).  
  
 Mensagem de reflexão permite que você reutilize o `CWnd`-classes derivadas mais rapidamente. Reflexão funciona por meio de mensagem [CWnd::OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify), usando especial **ON_XXX_REFLECT** entradas do mapa de mensagem: por exemplo, **ON_CTLCOLOR_REFLECT** e **ON_CONTROL_REFLECT**. [62 de observação técnica](../mfc/tn062-message-reflection-for-windows-controls.md) explica reflexão de mensagem em mais detalhes.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer  
  
-   [Saiba mais sobre reflexão de mensagem](../mfc/tn062-message-reflection-for-windows-controls.md)  
  
-   [Implementar a reflexão de mensagem para um controle comum](../mfc/tn062-message-reflection-for-windows-controls.md)  
  
-   [Implementar a reflexão de mensagem para um controle ActiveX](../mfc/mfc-activex-controls-subclassing-a-windows-control.md)  
  
## <a name="see-also"></a>Consulte também  
 [Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)
