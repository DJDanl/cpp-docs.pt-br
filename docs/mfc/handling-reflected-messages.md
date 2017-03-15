---
title: "Manipulando mensagens refletidas | Microsoft Docs"
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
  - "lidando com erros, mensagens refletidas"
  - "mensagens refletidas, tratamento"
ms.assetid: 147a4e0c-51cc-4447-a8e1-c28b4cece578
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipulando mensagens refletidas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A reflexão de mensagem permite tratar mensagens para um controle, como `WM_CTLCOLOR`, **WM\_COMMAND**, e **WM\_NOTIFY**, dentro do próprio controle.  Isso torna o controle mais independente e portátil.  O mecanismo funciona com controles comum do windows bem como com os controles ActiveX \(chamado anteriormente controladores OLE\).  
  
 A reflexão de mensagem permite reutilizar mais prontamente seu `CWnd`\- classes derivadas.  Trabalho de reflexão de mensagem por meio de [CWnd::OnChildNotify](../Topic/CWnd::OnChildNotify.md), usando entradas especiais da mensagem de **ON\_XXX\_REFLECT** : por exemplo, **ON\_CTLCOLOR\_REFLECT** e **ON\_CONTROL\_REFLECT**.  [Observação 62 técnica](../mfc/tn062-message-reflection-for-windows-controls.md) explica a reflexão de mensagem com mais detalhes.  
  
## O que você deseja fazer?  
  
-   [Saber mais sobre a reflexão de mensagem](../mfc/tn062-message-reflection-for-windows-controls.md)  
  
-   [Implementar a reflexão de mensagem para um controle comuns](../mfc/tn062-message-reflection-for-windows-controls.md)  
  
-   [Implementar a reflexão de mensagem para um controle ActiveX](../mfc/mfc-activex-controls-subclassing-a-windows-control.md)  
  
## Consulte também  
 [Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)