---
title: "Mensagens | Microsoft Docs"
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
  - "mensagens"
  - "mensagens, MFC"
ms.assetid: b1476310-a135-42ca-817c-444fb3675491
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mensagens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O loop da mensagem na função de membro de **Executar** da classe `CWinApp` recupera as mensagens enfileiradas geradas por vários eventos.  Por exemplo, quando o usuário clica no mouse, o windows registra várias mensagens mouse\- relacionados, como `WM_LBUTTONDOWN` quando o botão esquerdo do mouse é pressionada e `WM_LBUTTONUP` quando o botão esquerdo do mouse será liberado.  A implementação da estrutura de loop de mensagem do aplicativo expede a mensagem à janela apropriada.  
  
 As categorias importantes de mensagens são descritas em [Categorias de mensagem](../mfc/message-categories.md).  
  
## Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)