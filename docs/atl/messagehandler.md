---
title: "MessageHandler | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "MessageHandler"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função de MessageHandler"
ms.assetid: 8a0acf97-1b0d-4226-91b9-75446634a03c
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# MessageHandler
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**MessageHandler** é o nome da função identificada pelo segundo parâmetro de macro de `MESSAGE_HANDLER` no mapa de mensagem.  
  
## Sintaxe  
  
```  
  
      LRESULT   
      MessageHandler  
      (  
   UINT uMsg,  
   WPARAM wParam,  
   LPARAM lParam,  
   BOOL& bHandled  
);  
```  
  
#### Parâmetros  
 `uMsg`  
 Especifica a mensagem.  
  
 `wParam`  
 Informações mensagem\- adicional específica.  
  
 `lParam`  
 Informações mensagem\- adicional específica.  
  
 `bHandled`  
 Os conjuntos `bHandled` do mapa da mensagem **Verdadeiro** antes de `MessageHandler` são chamados.  Se `MessageHandler` não trata totalmente a mensagem, deve definir `bHandled` a **Falso** para indicar a adicional das necessidades de mensagem.  
  
## Valor de retorno  
 O resultado de processamento de mensagem.  0 se com êxito.  
  
## Comentários  
 Para um exemplo de como usar este manipulador de mensagem em um mapa de mensagem, consulte [MESSAGE\_HANDLER](../Topic/MESSAGE_HANDLER.md).  
  
## Consulte também  
 [Implementando uma janela](../atl/implementing-a-window.md)   
 [Mapas de mensagem](../atl/message-maps-atl.md)   
 [WM\_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583)